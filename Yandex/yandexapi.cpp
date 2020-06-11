#include "yandexapi.h"

YandexAPI::YandexAPI(QString aBazeUrl, QSqlDatabase aDb, QString aAgzs, QObject *aParent): QObject(aParent), _bazeUrl(aBazeUrl), _request(new RequestData(this)),
_reestr("RegionPostavka", "Yandex api"), _db(aDb), _agzs(aAgzs), _timer(new QTimer()) {
    QObject::connect(_request,&RequestData::s_finished,this,&YandexAPI::checkAuth);
}

void YandexAPI::getPassword(QString aLogin){
    _request->get(QString("%1/api/auth?login=%2").arg(_bazeUrl,aLogin));
    //GET базовый url + /api/auth?login={login}
    //Система вышлет пароль на закрепленный за компанией Telegram канал, почту или смс
}

void YandexAPI::authorization(QString aLogin, QString aPassword) {
    QNetworkRequest request = createRequest(QString("%1/api/auth").arg(_bazeUrl), "application/x-www-form-urlencoded", false);
    _request->post(request,QString("login=%1&code=%2").arg(aLogin,aPassword));
    connect(_request,&RequestData::s_finished,this,&YandexAPI::saveToken);
//    url + /api/auth
//    POST
//    login={login}&code={password}

//    АСУ АЗС должна проверять все запросы на ответ 401, если система получила ответ 401, то
//    необходимо провести Авторизацию в Яндекс.Заправки по новой
}

void YandexAPI::updatePriceList(QString aPricelist) {
    QNetworkRequest request = createRequest(QString("%1/api/price").arg(_bazeUrl), "application/x-www-form-urlencoded", true);
    _request->post(request, aPricelist);
//    Для передачи прайс-листа в систему Яндекс.Заправки, АСУ АЗС после авторизации и в
//    момент обновления прайс-листа должна присылать HTTP запрос вида
//    базовый url + /api/price
//    Authorization: {token}
//    POST
//    key1=value1&key2=value2&.....N
//    key – идентификатор топлива
//    value – цена за единицу (double – дробный делить <.> Точка)
//    Пример запроса
//    a92=41.22&a95=43.87&a95_premium=55.78
//    Возможные идентификаторы топлива
//    ID
//    diesel    дизель
//    diesel_premium    брендированный дизель
//    a80    бензин марки А80
//    a92    бензин марки А92
//    a92_premium    брендированный бензин марки А92
//    a95    бензин марки А95
//    a95_premium    брендированный бензин марки А95
//    a98    бензин марки А98
//    a98_premium    брендированный бензин марки А98
//    a100    бензин марки А98 / 100
//    A100_premium    брендированный бензин марки А98 / 100
//    propane    пропан
//    metan    метан
}

void YandexAPI::updateConfigurationAGZS(QJsonObject aConfiguration) {
    QNetworkRequest request = createRequest(QString("%1/api/station").arg(_bazeUrl), "application/json", true);
    _request->post(request, QString(QJsonDocument(aConfiguration).toJson(QJsonDocument::Compact)));
//    Для передачи текущей конфигурации АЗС (кол-во и статус ТРК, типы топлива доступные на
//    ТРК) в систему Яндекс.Заправки, АСУ АЗС после авторизации и в момент обновления
//    конфигурации должна присылать HTTP запрос вида
//    базовый url + /api/station
//    Authorization: {token}
//    POST
//    {
//    // внешний идентификатор станции АЗС
//    string StationExtendedId
//    // словарь доступных на текущий момент колонок
//    Dictionary Columns
//    {
//    // номер колонки (int32)
//    Key: {
//    // список доступных типов топлива
//    "Fuels": [
//    "a92",
//    "a95",
//    "diesel_premium",
//    .....
//    N
//    ]
//    }
//    }
//    }
//    Пример запроса
//    {
//    "StationExtendedId": "00001",
//    "Columns": {
//    1: {
//    "Fuels": [
//    "a92",
//    "a95",
//    "diesel_premium"
//    ]
//    },
//    2: {
//    "Fuels": [
//    "a92",
//    "a95_premium",
//    "a98_premium",
//    "diesel_premium"
//    ]
//    }
//    }
    //    }
}

void YandexAPI::updateConfigurationAGZS(QString aConfiguration) {
    QNetworkRequest request = createRequest(QString("%1/api/station").arg(_bazeUrl), "application/json", true);
    _request->post(request, aConfiguration);
}

int YandexAPI::checkOrders() {
    QNetworkRequest request = createRequest(QString("%1/api/orders/items").arg(_bazeUrl), "application/x-www-form-urlencoded", true);
    _request->get(request);
    QJsonDocument jsonRequest = QJsonDocument::fromJson(_request->getAnswer());
    qDebug()<<_request->getAnswer();
    for (auto order: jsonRequest.object().value("orders").toArray()) {
        if (order.toObject().value("status").toString() == "AcceptOrder") { //заказ ожидает подтверждения от АСУ АЗС
            createTransaction(order.toObject());
            setStatusAccept(order.toObject().value("id").toString());
            if (_request->getCode() != 200) {
                setStatusCanceled(order.toObject().value("id").toString(), "Неизвестная ошибка.", QString::number(getLastAPI()), QDateTime::currentDateTime());
            }
        } else if (order.toObject().value("status").toString() == "WaitingRefueling") { //ожидаем включения налива на ТРК
            //AdditionalTransVCode = VCode другой записи - идет заправка
            //если там статус 'Выдача', iState=4, (LitersCountBeforeDB, MoneyCountBeforeDB, TransCountBefore)!=0, Transnum!='' - наливают
            //если заполнено все и статус 'Завершение выдачи' - заправили
            QSqlQuery* q_requests = new QSqlQuery(_db);
            q_requests->exec("SELECT api.AGZSName, api.AGZS, api.APIID, api.APIColumnId, api.FuelId, api.localState, api.VCode, "
                        "h.VCode, b.VCode, b.[State], b.iState, b.TrkTotalPriceDB, b.TrkVolumeDb, b.TrkUnitPriceDB, b.DateOpen, b.DateClose "
                        "FROM [agzs].[dbo].[PR_APITransaction] api "
                        "INNER JOIN [agzs].[dbo].[ADAST_TRKTransaction] h ON api.Link = h.VCode "
                        "INNER JOIN [agzs].[dbo].[ADAST_TRKTransaction] b ON h.AditionalTransVCode = b.VCode "
                        "WHERE api.APIID = " + order.toObject().value("id").toString());
            while (q_requests->next()) {
                if (q_requests->value(10).toInt() != q_requests->value(5).toInt()) {
                    QSqlQuery *q_apiUpdate = new QSqlQuery(_db);
                    switch (q_requests->value(10).toInt()) {
                    case 0: {//Формирование цен   Не сформирована

                        break;
                    }
                    case 1: {//Цена установлена
                        q_apiUpdate->prepare("UPDATE [agzs].[dbo].[PR_APITransaction] "
                                             "SET localState = :localState, DateClose = :date "
                                             "WHERE VCode = :VCode");
                        q_apiUpdate->bindValue(":localState",q_requests->value(10).toInt());
                        q_apiUpdate->bindValue(":date",q_requests->value(15).toDateTime());
                        q_apiUpdate->bindValue(":VCode",q_requests->value(6).toInt());
                        q_apiUpdate->exec();
                        break;
                    }
                    case 2: {//Запрос счетчиков
                        q_apiUpdate->prepare("UPDATE [agzs].[dbo].[PR_APITransaction] "
                                             "SET localState = :localState, DateClose = :date "
                                             "WHERE VCode = :VCode");
                        q_apiUpdate->bindValue(":localState",q_requests->value(10).toInt());
                        q_apiUpdate->bindValue(":date",q_requests->value(15).toDateTime());
                        q_apiUpdate->bindValue(":VCode",q_requests->value(6).toInt());
                        q_apiUpdate->exec();
                        break;
                    }
                    case 3: {//Запрос выдачи
                        q_apiUpdate->prepare("UPDATE [agzs].[dbo].[PR_APITransaction] "
                                             "SET localState = :localState, DateClose = :date "
                                             "WHERE VCode = :VCode");
                        q_apiUpdate->bindValue(":localState",q_requests->value(10).toInt());
                        q_apiUpdate->bindValue(":date",q_requests->value(15).toDateTime());
                        q_apiUpdate->bindValue(":VCode",q_requests->value(6).toInt());
                        q_apiUpdate->exec();
                        break;
                    }
                    case 4 ... 8: {//Выдача
                        q_apiUpdate->prepare("UPDATE [agzs].[dbo].[PR_APITransaction] "
                                             "SET localState = :localState, DateClose = :date "
                                             "WHERE VCode = :VCode");
                        q_apiUpdate->bindValue(":localState",q_requests->value(10).toInt());
                        q_apiUpdate->bindValue(":date",q_requests->value(15).toDateTime());
                        q_apiUpdate->bindValue(":VCode",q_requests->value(6).toInt());
                        q_apiUpdate->exec();
                        setStatusFueling(order.toObject().value("id").toString());
                        if (_request->getCode() != 200) {
                            QDateTime now = QDateTime::currentDateTime();
                            setStatusCanceled(order.toObject().value("id").toString(), "Неизвестная ошибка.", QString::number(getLastAPI()), now);
                        }
                        break;
                    }
                    default:{

                    }
                    }
                    delete q_apiUpdate;
                }
            }
            delete q_requests;
        } else if (order.toObject().value("status").toString() == "Fueling") { //идет налив
            //AdditionalTransVCode = VCode другой записи - идет заправка
            //если там статус 'Выдача', iState=4, (LitersCountBeforeDB, MoneyCountBeforeDB, TransCountBefore)!=0, Transnum!='' - наливают
            //если заполнено все и статус 'Завершение выдачи' - заправили
            QSqlQuery* q_requests = new QSqlQuery(_db);
            q_requests->exec("SELECT api.AGZSName, api.AGZS, api.APIID, api.APIColumnId, api.FuelId, api.localState, api.VCode, "
                        "h.VCode, b.VCode, b.[State], b.iState, b.TrkTotalPriceDB, b.TrkVolumeDb, b.TrkUnitPriceDB, b.DateOpen, b.DateClose "
                        "FROM [agzs].[dbo].[PR_APITransaction] api "
                        "INNER JOIN [agzs].[dbo].[ADAST_TRKTransaction] h ON api.Link = h.VCode "
                        "INNER JOIN [agzs].[dbo].[ADAST_TRKTransaction] b ON h.AditionalTransVCode = b.VCode "
                        "WHERE api.APIID = " + order.toObject().value("id").toString());
            while (q_requests->next()) {
                if (q_requests->value(10).toInt() != q_requests->value(5).toInt()) {
                    QSqlQuery *q_apiUpdate = new QSqlQuery(_db);
                    switch (q_requests->value(10).toInt()) {
                    case 0: {//Формирование цен   Не сформирована

                        break;
                    }
                    case 1: {//Цена установлена
                        q_apiUpdate->prepare("UPDATE [agzs].[dbo].[PR_APITransaction] "
                                             "SET localState = :localState, DateClose = :date "
                                             "WHERE VCode = :VCode");
                        q_apiUpdate->bindValue(":localState",q_requests->value(10).toInt());
                        q_apiUpdate->bindValue(":date",q_requests->value(15).toDateTime());
                        q_apiUpdate->bindValue(":VCode",q_requests->value(6).toInt());
                        q_apiUpdate->exec();
                        break;
                    }
                    case 2: {//Запрос счетчиков
                        q_apiUpdate->prepare("UPDATE [agzs].[dbo].[PR_APITransaction] "
                                             "SET localState = :localState, DateClose = :date "
                                             "WHERE VCode = :VCode");
                        q_apiUpdate->bindValue(":localState",q_requests->value(10).toInt());
                        q_apiUpdate->bindValue(":date",q_requests->value(15).toDateTime());
                        q_apiUpdate->bindValue(":VCode",q_requests->value(6).toInt());
                        q_apiUpdate->exec();
                        break;
                    }
                    case 3: {//Запрос выдачи
                        q_apiUpdate->prepare("UPDATE [agzs].[dbo].[PR_APITransaction] "
                                             "SET localState = :localState, DateClose = :date "
                                             "WHERE VCode = :VCode");
                        q_apiUpdate->bindValue(":localState",q_requests->value(10).toInt());
                        q_apiUpdate->bindValue(":date",q_requests->value(15).toDateTime());
                        q_apiUpdate->bindValue(":VCode",q_requests->value(6).toInt());
                        q_apiUpdate->exec();
                        break;
                    }
                    case 4: {//Выдача
                        q_apiUpdate->prepare("UPDATE [agzs].[dbo].[PR_APITransaction] "
                                             "SET localState = :localState, DateClose = :date "
                                             "WHERE VCode = :VCode");
                        q_apiUpdate->bindValue(":localState",q_requests->value(10).toInt());
                        q_apiUpdate->bindValue(":date",q_requests->value(15).toDateTime());
                        q_apiUpdate->bindValue(":VCode",q_requests->value(6).toInt());
                        q_apiUpdate->exec();
                        break;
                    }
                    case 5 ... 8 :{//Выдано //Подтверждение   Завершение выдачи //Обновление счетчиков //Завершение выдачи
                        QSqlQuery *q_PayOperation = new QSqlQuery(_db);
                        q_PayOperation->exec("SELECT [AmountDB], [PriceDB], [VolumeDB] "
                                             "FROM [agzs].[dbo].[ARM_PayOperation] "
                                             "WHERE Link="+q_requests->value(7).toString());
                        if(q_PayOperation->size() > 0){
                            q_apiUpdate->prepare("UPDATE [agzs].[dbo].[PR_APITransaction] set localState = :localState, [Price] = :price, ,[Litre] = :litre, [Sum] = :sum, [DateOpen] = :dateOpen, DateClose = :dateClose where VCode = :VCode");
                            q_apiUpdate->bindValue(":localState",5);
                            q_apiUpdate->bindValue(":price",q_requests->value(13).toInt());
                            q_apiUpdate->bindValue(":litre",q_requests->value(12).toInt());
                            q_apiUpdate->bindValue(":sum",q_requests->value(11).toInt());
                            q_apiUpdate->bindValue(":dateOpen",q_requests->value(14).toDateTime());
                            q_apiUpdate->bindValue(":dateClose",q_requests->value(15).toDateTime());
                            q_apiUpdate->bindValue(":VCode",q_requests->value(6).toInt());
                            q_apiUpdate->exec();
                            setStatusCompleted(order.toObject().value("id").toString(), q_requests->value(12).toDouble(), q_requests->value(6).toString(), q_requests->value(15).toDateTime());
                        }
                        delete q_PayOperation;
                        break;
                    }
                    default:{

                    }
                    }
                    delete q_apiUpdate;
                }
            }
            delete q_requests;
        } else if (order.toObject().value("status").toString()=="Expire") { //статус от АЗС не поступил в течение 30 минут
            QSqlQuery* q_requests = new QSqlQuery(_db);
            q_requests->exec("SELECT api.AGZSName, api.AGZS, api.APIID, api.APIColumnId, api.FuelId, api.localState, api.VCode, "
                        "h.VCode, b.VCode, b.[State], b.iState, b.TrkTotalPriceDB, b.TrkVolumeDb, b.TrkUnitPriceDB, b.DateOpen, b.DateClose "
                        "FROM [agzs].[dbo].[PR_APITransaction] api "
                        "INNER JOIN [agzs].[dbo].[ADAST_TRKTransaction] h ON api.Link = h.VCode "
                        "INNER JOIN [agzs].[dbo].[ADAST_TRKTransaction] b ON h.AditionalTransVCode = b.VCode "
                        "WHERE api.APIID = " + order.toObject().value("id").toString());
            QSqlQuery *q_apiUpdate = new QSqlQuery(_db);
            while(q_requests->next()) {
                q_apiUpdate->prepare("UPDATE [agzs].[dbo].[PR_APITransaction] "
                                     "SET localState = :localState, DateClose = :date "
                                     "WHERE VCode = :VCode");
                q_apiUpdate->bindValue(":localState","Ошибка: 30 минут");
                q_apiUpdate->bindValue(":date",q_requests->value(15).toDateTime());
                q_apiUpdate->exec();
            }
        }
    }
    checkAuth(_request);
    return jsonRequest.object().value("nextRetryMs").toInt();
//    АСУ АЗС должна постоянно опрашивать систему Яндекс.Заправки для проверки поступления
//    новых заказов. Для этого необходимо выполнить HTTP запрос
//    GET базовый url + /api/orders/items
//    Authorization: {token}

//    200 ОК Тело ответа будет содержать JSON вида
//    Каждый следующий HTTP запрос нужно делать через указанное в параметре nextRetryMs
//    миллисекунд
//    {
//        int nextRetryMs // Интервал в миллисекундах, спустя это время допустимо повторит запрос
//        List<Order> Orders  [
//            {
//                string Id // идентификатор заказа
//                DateTime DateCreate // дата и время создания в UTC
//                OrderType OrderType // тип заказа
//                double OrderVolume // значение заказа
//                int ColumnId // номер колонки
//                double PriceFuel // стоимость 1 литра топлива
//                double Litre // кол-во литров
//                string FuelId // идентификатор топлива
//                OrderStatus Status // текущий статус заказ
//                double Sum, // сумма заказа
//                string ContractId // идентификатор договора
//            },
//            .... N
//        ]
//    }

//    Пример ответа
//    {
//    "nextRetryMs": 3000,
//    "orders": [
//            {
//                "id": "ca067937c98844a3b0ee2cfc41493e30",--
//                "dateCreate": "2018-08-24T16:41:25.3593028Z",
//                "orderType": "Money",
//                "orderVolume": 500,
//                "columnId": 2,--
//                "litre": 12.53,--
//                "status": "AcceptOrder",--
//                "fuelId": "a92",--
//                "priceFuel": 39.88,--
//                "sum": 499.7,--
//                "ContractId": "Individual"--
//            }
//        ]
//    }
//    Параметр OrderType – тип заказа может принимать следующие значения:
//    • Money – заправка на фиксированную сумму, OrderVolume – сумма рублей
//    • Liters – заправка на литры, OrderVolume – кол-вол литров
//    • FullTank – полный бак, OrderVolume – максимальная сумма рублей
//    Параметр Status – статус заказа может принимать следующие значения
//    • AcceptOrder – заказ ожидает подтверждения от АСУ АЗС
//    • WaitingRefueling – ожидаем включения налива на ТРК
//    • Fueling – идет налив
//    • Expire – статус от АЗС не поступил в течение 30 минут
//    Параметр ContractId – тип договора по которому обрабатывается заказа
//    • Individual – договор возмездного оказания услуг (физические лица)
//    • Corporation - договор купли продажи топлива (юридические лица)
//    Система Яндекс.Заправки фиксирует, когда был отправлен последний запрос на получение
//    заказов. В случае если прошло больше 5 минут с момента последнего запроса на получение
//    списка заказов, то станция временно выключается до момента поступления запроса на
//    получение заказа
}

void YandexAPI::receiveVolumeReport(QDateTime aStartDate, QDateTime aEndDate, int aPage) {
    QNetworkRequest request = createRequest(QString("%1/api/orders/report").arg(_bazeUrl), "application/x-www-form-urlencoded", true);
    _request->post(request, QString("sdate=%1&edate=%2&page=%3").arg(aStartDate.toString("dd.MM.yyyy HH:mm:ss"), aEndDate.toString("dd.MM.yyyy HH:mm:ss"), QString::number(aPage)));

    //ЗДЕСЬ БУДЕТ КОД ВМЕСТО onReceiveVolumeReport


//    Отчет возвращается в формате JSON, массив объектов Order
//    базовый url + /api/orders/report
//    Authorization: {token}
//    POST
//    sdate={sdate}&edate={edate}&page={page}
//    все параметры являются обязательными

}

void YandexAPI::getStateAGZS(QString apikey) {
    _request->get(QString("%1/api/station/enable?apikey=%2").arg(_bazeUrl, apikey));
//    Отчет возвращается в формате JSON, массив объектов StationStatus
//    GET базовый url + /api/station/enable?apikey={apikey}
    //    apikey – ключ сети, выписывается сервисом отдельно по запросу сети
}

void YandexAPI::setStatusAccept(QString orderId) {
    QNetworkRequest request = createRequest(QString("%1/api/orders/accept?orderId=%2").arg(_bazeUrl, orderId), "application/x-www-form-urlencoded", true);
    _request->get(request);
//    Данный статус сообщает системе Яндекс.Заправки о том, что заказ принят и обработан
//    интегрируемой системой
//    Данный статус интегрируема система отсылает после того, как были произведены некоторые
//    действия с заказом (например, заказ сохранен в базе данных) и система готова перейти на
//    следующий шаг
//    В случае если система Яндекс.Заправки дала ответ отличный от 200 ОК, то интегрируемая
//    система отсылает статус Canceled и прекращает обработку заказ
//    GET базовый url + /api/orders/accept?orderId={ordeId}
//    Authorization: {token}
//    все параметры являются обязательными
//    После отправки статуса Accept заказ перейдёт в статус WaitingRefueling
}

void YandexAPI::setStatusFueling(QString orderId) {
    QNetworkRequest request = createRequest(QString("%1/api/orders/fueling?orderId=%2").arg(_bazeUrl, orderId), "application/x-www-form-urlencoded", true);
    _request->get(request);
//    Данный статус сообщает системе Яндекс.Заправки о том, что интегрируемая система готова
//    запустить колонку (начать пролив)
//    Данный статус интегрируемая система отсылает перед началом пуска колонки
//    В случае если система Яндекс.Заправки дала ответ отличный от 200 ОК, то интегрируемая
//    система отсылает статус Canceled и прекращает обработку заказ
//    GET базовый url + /api/orders/fueling?orderId={ordeId}
//    Authorization: {token}
//    все параметры являются обязательными
}

void YandexAPI::setStatusCanceled(QString aOrderId, QString aReason, QString aExtendedOrderId, QDateTime aExtendedDate) {
    QNetworkRequest request = createRequest(QString("%1/api/orders/canceled?orderId=%2&reason=%3&extendedOrderId=%4&extendedDate=%5").arg(
                                            _bazeUrl, aOrderId, aReason, aExtendedOrderId, aExtendedDate.toString("dd.MM.yyyy HH:mm:ss")), "application/x-www-form-urlencoded", true);
    _request->get(request);
//    Данный статус сообщает системе Яндекс.Заправки о том, что заказ следует отменить
//    GET базовый url +
//    /api/orders/canceled?orderId={ordeId}&reason={reason}&extendedOrderId={extendedOrderId}&
//    extendedDate={extendedDate}
//    Authorization: {token}
//    все параметры являются обязательными
//    reason – текстовая причина отмены
//    extendedOrderId – идентификатор заказа в АСУ сети
//    extendedDate – дата по которой АСУ строит отчет для сверки, формат dd.MM.yyyy HH:mm:ss
}

void YandexAPI::setStatusCompleted(QString aOrderId, double aLitre, QString aExtendedOrderId, QDateTime aExtendedDate) {
    QNetworkRequest request = createRequest(QString("%1/api/orders/completed?orderId=%2&litre=%3&extendedOrderId=%4&extendedDate=%5").arg(
                                            _bazeUrl, aOrderId, QString::number(aLitre), aExtendedOrderId, aExtendedDate.toString("dd.MM.yyyy HH:mm:ss")),
                                            "application/x-www-form-urlencoded", true);
    _request->get(request);
    if (_request->getCode() != 200) {
        _timer.start(3000);
        QEventLoop loop;
        connect(&_timer, &QTimer::timeout, &loop, &QEventLoop::quit);
        loop.exec();
        disconnect(&_timer, &QTimer::timeout, &loop, &QEventLoop::quit);
        setStatusCompleted(aOrderId, aLitre, aExtendedOrderId, aExtendedDate);
    }
//    Данный статус сообщает системе Яндекс.Заправки о том, что заказ выполнен и топливо
//    залито
//    В случае если система Яндекс.Заправки дала ответ отличный от 200 ОК, то интегрируемая
//    система отсылает запросы с некоторым отложенным кол-вом времени до момента
//    получения ответа 200 ОК
//    GET базовый url + /api/orders/completed?
//    orderId={ordeId}&litre={litre}&extendedOrderId={extendedOrderId}&
//    extendedDate={extendedDate}
//    Authorization: {token}
//    все параметры являются обязательными
//    litre – кол-во пролитых литров, указывается как double с разделителем точка
//    extendedOrderId – идентификатор заказа в АСУ сети
//    extendedDate – дата по которой АСУ строит отчет для сверки, формат dd.MM.yyyy HH:mm:ss
}

void YandexAPI::setFuelNow(QString aOrderId, double aLitre) {
    QNetworkRequest request = createRequest(QString("%1/api/orders/volume").arg(_bazeUrl), "application/x-www-form-urlencoded", true);
    _request->post(request, QString("orderId=%1&litre=%2").arg(aOrderId, QString::number(aLitre)));
//    В момент процесса налива интегрируемая система может сообщать Яндекс.Запракам статус
//    счетчика налива
//    Для этого необходимо с периодичностью от 5 – 10 секунд выполнять запрос (для
//    исключения повышенной нагрузки в АСУ АЗС следует устанавливать timeout на запрос не
//    более 1 секунды (1000 мс)
//    базовый url + /api/orders/volume
//    POST
//    orderId={ordeId}&litre={litre}
//    Authorization: {token}
//    все параметры являются обязательными
//    litre – кол-во пролитых на момент отправки запроса литров, указывается как double с
//    разделителем точка
}

QNetworkRequest YandexAPI::createRequest(QString aUrl, QString aContentType, bool aAuth) {
    _reestr.sync();
    QNetworkRequest request(aUrl);
    request.setHeader(QNetworkRequest::ContentTypeHeader, aContentType.toUtf8());
    if (aAuth) {
        request.setRawHeader("Authorization", _reestr.value("Token").toString().toUtf8());
    }
    return request;
}

void YandexAPI::checkAuth(RequestData *aRequest) {
    if (aRequest->getCode() == 401) {
        emit s_needAuth(true);
    }
}

void YandexAPI::saveToken(RequestData *aRequest){
    disconnect(_request,&RequestData::s_finished,this,&YandexAPI::saveToken);
    qDebug()<<"Токен:"<<QString::fromUtf8(aRequest->getAuthorization());
    if (aRequest->getAuthorization() != "") {
        _reestr.setValue("Token",QString::fromUtf8(aRequest->getAuthorization()));
        _reestr.sync();
        emit s_authComplete(true);
    } else {
        emit s_authComplete(false);
    }
//    В ответе 200 ОК будет прислан Head параметр Authorization
//    Авторизационный токен следует запомнить в реестре, файле системы, или конфигурации,
//    важно предусмотреть вариант при котором обновление АСУ АЗС не проводило к потери
//    токена, в случае потери токена необходимо по новой пройти процесс авторизации
//    Примет ответа:
//    > POST /api/price HTTP/1.1
//    > Host: cabinet.tst.tanker.yandex.ru
//    > Authorization: Terminal CfDJ8LvvKxbYatxLk67gs3QWA7D791g1MeYbygmCJK3nRT45v0RURmSfUEhBi2x84sLHJFnOHcAfzcPEzxHMNW3r8w_bz-
//    Ytcl4KJz5sOi5IKpfmrlonuAKLKM3xQlPldXMiKdPjomopjJe5BUztj_CBM2vRcoxFPtP7PS8je37UP2iE
//    401 – не найден Логин или же доступ для Логина заблокирован
//    404 – не верно задан пароль
//    (после запроса пароля, можно лишь 5 раз попробовать указать его не верно, далее
//    необходимо перезапрашивать пароль)
//    После успешной авторизации в каждом запросе к системе Яндекс.Заправки в Head должен
    //    передаваться параметр Authorization
}

void YandexAPI::createTransaction(QJsonObject aTransaction) {
//        {
//            "id": "ca067937c98844a3b0ee2cfc41493e30",--
//            "dateCreate": "2018-08-24T16:41:25.3593028Z",
//            "orderType": "Money",
//            "orderVolume": 500,
//            "columnId": 2,--
//            "litre": 12.53,--
//            "status": "AcceptOrder",--
//            "fuelId": "a92",--
//            "priceFuel": 39.88,--
//            "sum": 499.7,--
//            "ContractId": "Individual"--
//        }
        QDateTime now = QDateTime::currentDateTime();
        int lastAPIVCode = getLastAPI();
        int error = checkError(aTransaction.value("columnId").toString(),
                               aTransaction.value("fuelId").toString(),
                               QString::number(aTransaction.value("priceFuel").toInt()),
                               aTransaction.value("id").toString(),
                               QString::number(lastAPIVCode+1),
                               now);
        QSqlQuery *q_AGZSColumn = new QSqlQuery(_db);
        q_AGZSColumn->exec("SELECT c.AGZSName, c.AGZS, d.VCode, d.Id,  c.TrkType, c.[DeviceName], c.[Serial], c.[FuelName], c.[FuelShortName], "
                            "c.[Side], c.[SideAdress], c.[Nozzle], c.[TrkFuelCode], c.[TrkVCode] "
                           "FROM [agzs].[dbo].PR_AGZSData d "
                                "INNER JOIN [agzs].[dbo].PR_AGZSColumnsData c "
                                "ON d.VCode = c.Link "
                                "INNER JOIN [agzs].[dbo].pr_agzsPrice p "
                                "ON d.VCode = p.Link "
                           "WHERE d.AGZS=" + _agzs + " and c.SideAdress=" + QString::number(aTransaction.value("columnId").toInt()) +
                            " and c.FuelVCode=" + QString::number(getFuelID(aTransaction.value("fuelId").toString())) +
                            " and p.[" + aTransaction.value("fuelId").toString() + "]=" + QString::number(aTransaction.value("priceFuel").toInt()) + " "
                           "ORDER BY d.CDate DESC");
        q_AGZSColumn->next();
        int transactionVCode = -1;
        if (error == 0) {
            double requestTotalPriceDB=-1,	requestVolumeDB=-1,	requestUnitPriceDB=-1, moneyTakenDB=-1;
            int fullTankDB=-1;
            moneyData(aTransaction, requestTotalPriceDB, requestVolumeDB, requestUnitPriceDB, moneyTakenDB, fullTankDB);
            QSqlQuery *q_Transaction = new QSqlQuery(_db);
            q_Transaction->exec("SELECT TOP 1 Value "
                                "FROM [agzs].[dbo].[LxKeysOfCodes] "
                                "WHERE [Key]='ADAST_TRKTransaction'");
            q_Transaction->next();
            transactionVCode=q_Transaction->value(0).toInt()+1;
            q_Transaction->exec("UPDATE [agzs].[dbo].[LxKeysOfCodes] "
                                "SET Value="+QString::number(transactionVCode)+" "
                                "WHERE [Key]='ADAST_TRKTransaction'");
            q_Transaction->prepare("INSERT INTO [agzs].[dbo].[ADAST_TRKTransaction] (AGZSName, LocalVCode, TrkType, DeviceName,	Serial,	FuelName, FuelShortName, Side, SideAddress, Nozzle, "
                           "TrkFuelCode, TransNum, TrkTotalPriceDB, TrkVolumeDB, TrkUnitPriceDB, RequestTotalPriceDB, RequestVolumeDB, RequestUnitPriceDB, RequestField, State, iState, "
                           "TrkTransType, LitersCountBeforeDB, MoneyCountBeforeDB, TransCountBefore, LitersCountAfterDB, MoneyCountAfterDB, TransCountAfter, Result, DateOpen, DateClose, "
                           "TemperatureDB, PayOperationVCode, PayWay, PrePostPay, WUser, WDate, CUser, CDate, CHost, WHost, VCode, AddedForTransVCode, AditionalTransVCode, ActiveDB, "
                           "MassDB, Smena, TrkVcode, CapacityVcode, PumpPlace, MoneyTakenDB, iPayWay, AutoCheckDB, Closed, FullTankDB, AGZS, FuelVCode, rowguid, Propan) "
                           "VALUES(:AGZSName, :LocalVCode, :TrkType, :DeviceName, :Serial, :FuelName, :FuelShortName, :Side, :SideAddress, :Nozzle, :TrkFuelCode, :TransNum, "
                           ":TrkTotalPriceDB, :TrkVolumeDB, :TrkUnitPriceDB, :RequestTotalPriceDB, :RequestVolumeDB, :RequestUnitPriceDB, :RequestField, :State, :iState, :TrkTransType, "
                           ":LitersCountBeforeDB, :MoneyCountBeforeDB, :TransCountBefore, :LitersCountAfterDB, :MoneyCountAfterDB, :TransCountAfter, :Result, :DateOpen, :DateClose, "
                           ":TemperatureDB, :PayOperationVCode, :PayWay, :PrePostPay, :WUser, :WDate, :CUser, :CDate, :CHost, :WHost, :VCode, :AddedForTransVCode, :AditionalTransVCode, "
                           ":ActiveDB, :MassDB, :Smena, :TrkVcode, :CapacityVcode, :PumpPlace, :MoneyTakenDB, :iPayWay, :AutoCheckDB, :Closed, :FullTankDB, :AGZS, :FuelVCode, DEFAULT, "
                           ":Propan)");
            q_Transaction->bindValue(":AGZSName",q_AGZSColumn->value(0).toString());
            q_Transaction->bindValue(":LocalVCode",QString::number(transactionVCode));
            q_Transaction->bindValue(":TrkType",q_AGZSColumn->value(4).toString());
            q_Transaction->bindValue(":DeviceName",q_AGZSColumn->value(5).toString());
            q_Transaction->bindValue(":Serial",q_AGZSColumn->value(6).toString());
            q_Transaction->bindValue(":FuelName",q_AGZSColumn->value(7).toString());
            q_Transaction->bindValue(":FuelShortName",q_AGZSColumn->value(8).toString());
            q_Transaction->bindValue(":Side",q_AGZSColumn->value(9).toString());
            q_Transaction->bindValue(":SideAddress",q_AGZSColumn->value(10).toString());
            q_Transaction->bindValue(":Nozzle",q_AGZSColumn->value(11).toString());
            q_Transaction->bindValue(":TrkFuelCode",q_AGZSColumn->value(12).toString());
            q_Transaction->bindValue(":TransNum","");
            q_Transaction->bindValue(":TrkTotalPriceDB",0);
            q_Transaction->bindValue(":TrkVolumeDB",0);
            q_Transaction->bindValue(":TrkUnitPriceDB",0);
            q_Transaction->bindValue(":RequestTotalPriceDB",requestTotalPriceDB);
            q_Transaction->bindValue(":RequestVolumeDB",requestVolumeDB);
            q_Transaction->bindValue(":RequestUnitPriceDB",requestUnitPriceDB);
            q_Transaction->bindValue(":RequestField","V");
            q_Transaction->bindValue(":State","Завершение выдачи");
            q_Transaction->bindValue(":iState",8);
            q_Transaction->bindValue(":TrkTransType","P");
            q_Transaction->bindValue(":LitersCountBeforeDB",0);
            q_Transaction->bindValue(":MoneyCountBeforeDB",0);
            q_Transaction->bindValue(":TransCountBefore",0);
            q_Transaction->bindValue(":LitersCountAfterDB",0);
            q_Transaction->bindValue(":MoneyCountAfterDB",0);
            q_Transaction->bindValue(":TransCountAfter",0);
            q_Transaction->bindValue(":Result","Выдача завершена: 1");
            q_Transaction->bindValue(":DateOpen",now.toString("yyyyMMdd hh:mm:ss.zzz"));
            q_Transaction->bindValue(":DateClose",now.toString("yyyyMMdd hh:mm:ss.zzz"));
            q_Transaction->bindValue(":TemperatureDB",-100);
            q_Transaction->bindValue(":PayOperationVCode",0);
            q_Transaction->bindValue(":PayWay","ЯНДЕКС");
            q_Transaction->bindValue(":PrePostPay",0);
            q_Transaction->bindValue(":WUser","SERVER");
            q_Transaction->bindValue(":WDate",now.toString("yyyyMMdd hh:mm:ss.zzz"));
            q_Transaction->bindValue(":CUser","SERVER");
            q_Transaction->bindValue(":CDate",now.toString("yyyyMMdd hh:mm:ss.zzz"));
            q_Transaction->bindValue(":CHost","SERVER");
            q_Transaction->bindValue(":WHost","SERVER");
            q_Transaction->bindValue(":VCode",transactionVCode);
            q_Transaction->bindValue(":AddedForTransVCode",0);
            q_Transaction->bindValue(":AditionalTransVCode",0);
            q_Transaction->bindValue(":ActiveDB",0);
            q_Transaction->bindValue(":MassDB",0);
            q_Transaction->bindValue(":Smena",getSmena());
            q_Transaction->bindValue(":TrkVcode",q_AGZSColumn->value(13).toString());
            q_Transaction->bindValue(":CapacityVcode",getCashBoxIndex());
            q_Transaction->bindValue(":PumpPlace",q_AGZSColumn->value(10).toString());
            q_Transaction->bindValue(":MoneyTakenDB",moneyTakenDB);
            q_Transaction->bindValue(":iPayWay",11);
            q_Transaction->bindValue(":AutoCheckDB",0);
            q_Transaction->bindValue(":Closed",0);
            q_Transaction->bindValue(":FullTankDB",fullTankDB);
            q_Transaction->bindValue(":AGZS",q_AGZSColumn->value(1).toString());
            q_Transaction->bindValue(":FuelVCode",getFuelID(aTransaction.value("fuelId").toString()));
            q_Transaction->bindValue(":Propan",0);
            q_Transaction->exec();
            if(q_Transaction->next()) {
                setStatusAccept(aTransaction.value("id").toString());
            }
            delete q_Transaction;
        }
        QSqlQuery *q_APIRequests = new QSqlQuery(_db);
        q_APIRequests->prepare("INSERT INTO [agzs].[dbo].[PR_APITransaction] ([AGZSName],[AGZS],[CDate],[VCode],[APIID],[APIStationExtendedId],[APIColumnId],[APIFuelId],[FuelId],"
                    "[APIPriceFuel],[APILitre],[APISum],[APIStatus],[APIContractId],[agent],[localState],[Price],[Litre],[Sum],[DateOpen],[DateClose],[Link]) "
                    "VALUES (:AGZSName, :AGZS, :CDate, :VCode, :APIID, :APIStationExtendedId, :APIColumnId, :APIFuelId, :FuelId, :APIPriceFuel, :APILitre, :APISum, "
                    ":APIStatus, :APIContractId, :agent, :localState, :Price, :Litre, :Sum, :DateOpen, DEFAULT, :Link)");
        q_APIRequests->bindValue(":AGZSName", q_AGZSColumn->value(0).toString());
        q_APIRequests->bindValue(":AGZS", q_AGZSColumn->value(1).toString());
        q_APIRequests->bindValue(":CDate", QDateTime::fromString(aTransaction.value("dateCreate").toString().left(23), "yyyy-MM-ddThh:mm:ss.zzz").toString("yyyyMMdd hh:mm:ss.zzz"));
        q_APIRequests->bindValue(":VCode", lastAPIVCode + 1);
        q_APIRequests->bindValue(":APIID", aTransaction.value("id").toString());
        q_APIRequests->bindValue(":APIStationExtendedId", "");
        q_APIRequests->bindValue(":APIColumnId", aTransaction.value("columnId").toInt());
        q_APIRequests->bindValue(":APIFuelId", aTransaction.value("fuelId").toString());
        q_APIRequests->bindValue(":FuelId", getFuelID(aTransaction.value("fuelId").toString()));
        q_APIRequests->bindValue(":APIPriceFuel", aTransaction.value("priceFuel").toDouble());
        q_APIRequests->bindValue(":APILitre", aTransaction.value("litre").toDouble());
        q_APIRequests->bindValue(":APISum", aTransaction.value("sum").toDouble());
        q_APIRequests->bindValue(":APIStatus", aTransaction.value("status").toString());
        q_APIRequests->bindValue(":APIContractId", aTransaction.value("contractId").toString());
        q_APIRequests->bindValue(":agent", "Yandex");
        q_APIRequests->bindValue(":localState", error != 0 ? "Error: " + QString::number(error) : "0");
        q_APIRequests->bindValue(":Price", 0);
        q_APIRequests->bindValue(":Litre", 0);
        q_APIRequests->bindValue(":Sum", 0);
        q_APIRequests->bindValue(":DateOpen", now.toString("yyyyMMdd hh:mm:ss.zzz"));
        //q_APIRequests->bindValue(":DateClose", "DEFAULT");
        q_APIRequests->bindValue(":Link", QString::number(transactionVCode));
        q_APIRequests->exec();
        delete q_APIRequests;
        delete q_AGZSColumn;
}

int YandexAPI::getLastAPI() {
    QSqlQuery *q_APIRequestsLast = new QSqlQuery(_db);
    q_APIRequestsLast->exec("SELECT TOP 1 VCode "
                            "FROM [agzs].[dbo].[PR_APITransaction] "
                            "ORDER BY CDate DESC");
    int last=0;
    if (q_APIRequestsLast->next()) {
        last = q_APIRequestsLast->value(0).toInt();
    }
    delete q_APIRequestsLast;
    return last;
}

int YandexAPI::getFuelID(QString aFuelIdApi) {
    if(aFuelIdApi=="diesel")
        return 32;
    if(aFuelIdApi=="diesel_premium")
        return 0;
    if(aFuelIdApi=="a80")
        return 0;
    if(aFuelIdApi=="a92")
        return 3;
    if(aFuelIdApi=="a92_premium")
        return 0;
    if(aFuelIdApi=="a95")
        return 8;
    if(aFuelIdApi=="a95_premium")
        return 0;
    if(aFuelIdApi=="a98")
        return 0;
    if(aFuelIdApi=="a98_premium")
        return 0;
    if(aFuelIdApi=="a100")
        return 0;
    if(aFuelIdApi=="a100_premium")
        return 0;
    if(aFuelIdApi=="propane")
        return 14;
    if(aFuelIdApi=="metan")
        return 0;
    return 0;
}

QString YandexAPI::getFullFuelName(int aFuelID) {
    QSqlQuery *q_Fuels = new QSqlQuery(_db);
    q_Fuels->exec("SELECT TOP 1 [DBVCode], [DBName] "
                  "FROM [agzs].[dbo].[FuelMassLink] "
                  "WHERE [DBVCode]="+QString::number(aFuelID));
    q_Fuels->next();
    QString fullName = q_Fuels->value(1).toString();
    delete q_Fuels;
    return fullName;
}

int YandexAPI::getCashBoxIndex() {
    QSqlQuery *q_CashBox = new QSqlQuery(_db);
    q_CashBox->exec("SELECT TOP 1 CashBoxIndex, PayIndex, PayWay, AutoCheck FROM [agzs].[dbo].[ARM_CashBoxesSemaphor] "
                    "WHERE PayIndex = 11 and PayWay = 'ЯНДЕКС' and AutoCheck = 0 "
                    "ORDER BY CDate DESC");
    int last = 0;
    if (q_CashBox->next()) {
        last = q_CashBox->value(0).toInt();
    }
    delete q_CashBox;
    return last;
}

int YandexAPI::checkError(QString aColumnID, QString aFuelID, QString aPriceFuel, QString aOrderId, QString aLastVCode, QDateTime aNow) {
    QSqlQuery *q_Check = new QSqlQuery(_db);
    q_Check->exec("SELECT c.AGZSName, c.AGZS, d.VCode, d.Id, c.[FuelName], c.[FuelShortName], c.[Side], c.[SideAdress], c.[Nozzle], "
                    "c.[TrkFuelCode], c.[TrkVCode] "
                  "FROM [agzs].[dbo].PR_AGZSData d "
                    "INNER JOIN [agzs].[dbo].PR_AGZSColumnsData c "
                    "ON d.VCode = c.Link "
                  "WHERE d.AGZS = "+_agzs+" and c.SideAdress = "+aColumnID+" "
                  "ORDER BY d.CDate DESC");
    if (q_Check->size() == 0) {
        setStatusCanceled(aOrderId, "Указанная колонка не найдена.", aLastVCode, aNow);
        delete q_Check;
        qDebug()<<"Error1";
        return 1;
    }
    q_Check->exec("SELECT c.AGZSName, c.AGZS, d.VCode, d.Id, c.[FuelName], c.[FuelShortName], c.[Side], c.[SideAdress], c.[Nozzle], "
                    "c.[TrkFuelCode], c.[TrkVCode] "
                  "FROM [agzs].[dbo].PR_AGZSData d "
                    "INNER JOIN [agzs].[dbo].PR_AGZSColumnsData c "
                    "ON d.VCode = c.Link "
                  "WHERE d.Id='"+_agzs+"' and c.SideAdress = "+aColumnID+" and c.FuelVCode = "+QString::number(getFuelID(aFuelID))+" "
                  "ORDER BY d.CDate DESC");
    if (q_Check->size() == 0) {
        setStatusCanceled(aOrderId, "Не обнаружено указанное топливо.", aLastVCode, aNow);
        delete q_Check;
        qDebug()<<"Error2";
        return 2;
    }
    q_Check->exec("SELECT c.AGZSName, c.AGZS, d.VCode, d.Id, c.[FuelName], c.[FuelShortName], c.[Side], c.[SideAdress], c.[Nozzle], "
                    "c.[TrkFuelCode], c.[TrkVCode], p.["+aFuelID+"] "
                "FROM [agzs].[dbo].PR_AGZSData d "
                     "INNER JOIN [agzs].[dbo].PR_AGZSColumnsData c "
                     "ON d.VCode = c.Link "
                     "INNER JOIN [agzs].[dbo].PR_AGZSPrice p "
                     "ON d.VCode = p.Link "
                "WHERE d.Id='"+_agzs+"' and c.SideAdress = "+aColumnID+" and c.FuelVCode = "+QString::number(getFuelID(aFuelID))+
                    " and p.["+aFuelID+"]="+aPriceFuel+" "
                "ORDER BY d.CDate DESC");
    if (q_Check->size() == 0) {
        setStatusCanceled(aOrderId, "Цена на выбранный вид топлива отличается от фактической цены.", aLastVCode, aNow);
        delete q_Check;
        emit s_updatePrice();
        qDebug()<<"Error3";
        return 3;
    }
    delete q_Check;
    return 0;
}

void YandexAPI::moneyData(QJsonObject aRequest, double &aRequestTotalPriceDB, double &aRequestVolumeDB, double &aRequestUnitPriceDB, double &aMoneyTakenDB, int &aFullTankDB) {
    if (aRequest.value("orderType").toString() == "Money") {
        aRequestTotalPriceDB = aRequest.value("orderVolume").toDouble();
        aRequestUnitPriceDB = aRequest.value("priceFuel").toDouble();
        aRequestVolumeDB = aRequestTotalPriceDB / aRequestUnitPriceDB;
        aMoneyTakenDB = aRequest.value("orderVolume").toDouble();
        aFullTankDB = 0;
    } else if (aRequest.value("orderType").toString() == "Liters") {
        aRequestVolumeDB = aRequest.value("orderVolume").toDouble();
        aRequestUnitPriceDB = aRequest.value("priceFuel").toDouble();
        aRequestTotalPriceDB = aRequestVolumeDB * aRequestUnitPriceDB;
        aMoneyTakenDB = aRequest.value("orderVolume").toDouble();
        aFullTankDB = 0;
    } else if (aRequest.value("orderType").toString() == "FullTank") {
        aRequestTotalPriceDB = aRequest.value("orderVolume").toDouble();
        aRequestUnitPriceDB = aRequest.value("priceFuel").toDouble();
        aRequestVolumeDB = aRequestTotalPriceDB / aRequestUnitPriceDB;
        aMoneyTakenDB = aRequest.value("OrderVolume").toDouble();
        aFullTankDB = 1;
    }
}

QString YandexAPI::getSmena() {
    QSqlQuery *q_Smena = new QSqlQuery(_db);
    q_Smena->exec("SELECT TOP 1 VCode "
                  "FROM [agzs].[dbo].[ARM_Smena] "
                  "ORDER BY CDate DESC");
    q_Smena->next();
    return q_Smena->value(0).toString();
}
