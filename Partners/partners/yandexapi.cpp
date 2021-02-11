#include "yandexapi.h"

YandexAPI::YandexAPI(QObject *aParent):
QObject(aParent),
reestr_("RegionPostavka", "Partners"),
timer_(new QTimer()),
c_baseUrl(reestr_.value("isTest").toBool() ? c_baseTest : c_baseRelease) {

}

void YandexAPI::getPassword(QString aLogin) {
    auto req = createRequest();
    req->get(QString("%1/api/auth?login=%2").arg(c_baseUrl, aLogin));
    delete req;
    //GET базовый url + /api/auth?login={login}
    //Система вышлет пароль на закрепленный за компанией Telegram канал, почту или смс
}

void YandexAPI::authorization(QString aLogin, QString aPassword) {
    auto req = createRequest();
    QNetworkRequest request = createRequest(QString("%1/api/auth").arg(c_baseUrl), "application/x-www-form-urlencoded", false);
    connect(req, &RequestData::s_finished, this, &YandexAPI::saveToken);
    req->post(request, QString("login=%1&code=%2").arg(aLogin, aPassword));
    delete req;
//    url + /api/auth
//    POST
//    login={login}&code={password}

//    АСУ АЗС должна проверять все запросы на ответ 401, если система получила ответ 401, то
//    необходимо провести Авторизацию в Яндекс.Заправки по новой
}

void YandexAPI::updatePriceList(QString aPricelist) {
    auto req = createRequest();
    QNetworkRequest request = createRequest(QString("%1/api/price").arg(c_baseUrl));
    req->post(request, aPricelist);
    delete req;
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
    auto req = createRequest();
    QNetworkRequest request = createRequest(QString("%1/api/station").arg(c_baseUrl), "application/json", true);
    req->post(request, QString(QJsonDocument(aConfiguration).toJson(QJsonDocument::Compact)));
    delete req;
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
    auto req = createRequest();
    QNetworkRequest request = createRequest(QString("%1/api/station").arg(c_baseUrl), "application/json", true);
    req->post(request, aConfiguration);
    delete req;
}

int YandexAPI::checkOrders() {
    auto req = createRequest();
    QNetworkRequest request = createRequest(QString("%1/api/orders/items").arg(c_baseUrl));
    req->get(request);
    QJsonDocument jsonRequest = QJsonDocument::fromJson(req->getAnswer());
    qDebug() << req->getCode() << req->getAnswer();
    if (req->getCode() == 200) {
        emit s_gotOrders(jsonRequest);
    }
    checkAuth(req);
    delete req;
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
    auto req = createRequest();
    QNetworkRequest request = createRequest(QString("%1/api/orders/report").arg(c_baseUrl));
    req->post(request, QString("sdate=%1&edate=%2&page=%3").arg(aStartDate.toString("dd.MM.yyyy HH:mm:ss"), aEndDate.toString("dd.MM.yyyy HH:mm:ss"), QString::number(aPage)));
    checkAuth(req);
    if ((req->getCode() != 200) && (req->getCode() != 401)) {
        qWarning(logError) << "receiveVolumeReport" << "" << req->getCode();
        emit s_error("receiveVolumeReport", "", req->getCode());
    }
    delete req;
//    Отчет возвращается в формате JSON, массив объектов Order
//    базовый url + /api/orders/report
//    Authorization: {token}
//    POST
//    sdate={sdate}&edate={edate}&page={page}
//    все параметры являются обязательными

}

void YandexAPI::getStateAGZS(QString aApikey) {
    auto req = createRequest();
    req->get(QString("%1/api/station/enable?apikey=%2").arg(c_baseUrl, aApikey));
    checkAuth(req);
    if ((req->getCode() != 200) && (req->getCode() != 401)) {
        qWarning(logError) << "getStateAGZS" << "" << req->getCode();
        emit s_error("getStateAGZS", "", req->getCode());
    }
    delete req;
//    Отчет возвращается в формате JSON, массив объектов StationStatus
//    GET базовый url + /api/station/enable?apikey={apikey}
    //    apikey – ключ сети, выписывается сервисом отдельно по запросу сети
}

void YandexAPI::setStatusAccept(QString aOrderId, int aVCode) {
    auto req = createRequest();
    QNetworkRequest request = createRequest(QString("%1/api/orders/accept?orderId=%2").arg(c_baseUrl, aOrderId));
    req->get(request);
    checkAuth(req);
    if ((req->getCode() != 200) && (req->getCode() != 401)) {
        qWarning(logError) << "setStatusAccept" << aOrderId << req->getCode();
        emit s_error("setStatusAccept", aOrderId, req->getCode());
        setStatusCanceled(aOrderId, "Неизвестная ошибка.", QString::number(aVCode), QDateTime::currentDateTime());
    }
    delete req;
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

void YandexAPI::setStatusFueling(QString aOrderId, int aVCode) {
    auto req = createRequest();
    Q_UNUSED(aVCode);
    QNetworkRequest request = createRequest(QString("%1/api/orders/fueling?orderId=%2").arg(c_baseUrl, aOrderId));
    req->get(request);
    checkAuth(req);
    if ((req->getCode() != 200) && (req->getCode() != 401)) {
        qWarning(logError) << "setStatusFueling" << aOrderId << req->getCode();
        emit s_error("setStatusFueling", aOrderId, req->getCode());
        //setStatusCanceled(orderId, "Неизвестная ошибка.", QString::number(vCode), QDateTime::currentDateTime());
    }
    delete req;
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
    auto req = createRequest();
    QNetworkRequest request = createRequest(QString("%1/api/orders/canceled?orderId=%2&reason=%3&extendedOrderId=%4&extendedDate=%5").arg(
                                            c_baseUrl, aOrderId, aReason, aExtendedOrderId, aExtendedDate.toString("dd.MM.yyyy HH:mm:ss")));
    req->get(request);
    checkAuth(req);
    if ((req->getCode() != 200) && (req->getCode() != 401)) {
        qWarning(logError) << "setStatusCanceled" << aOrderId << req->getCode();
        emit s_error("setStatusCanceled", "\"" + aOrderId + "\"", req->getCode());
    }
    delete req;
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
    auto req = createRequest();
    QNetworkRequest request = createRequest(QString("%1/api/orders/completed?orderId=%2&litre=%3&extendedOrderId=%4&extendedDate=%5").arg(
                                            c_baseUrl, aOrderId, QString::number(aLitre), aExtendedOrderId, aExtendedDate.toString("dd.MM.yyyy HH:mm:ss")));
    req->get(request);
    checkAuth(req);
    if (req->getCode() != 200) {
        timer_.start(3000);
        QEventLoop loop;
        connect(&timer_, &QTimer::timeout, &loop, &QEventLoop::quit);
        loop.exec();
        disconnect(&timer_, &QTimer::timeout, &loop, &QEventLoop::quit);
        setStatusCompleted(aOrderId, aLitre, aExtendedOrderId, aExtendedDate);
    }
    delete req;
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
    auto req = createRequest();
    QNetworkRequest request = createRequest(QString("%1/api/orders/volume").arg(c_baseUrl));
    req->post(request, QString("orderId=%1&litre=%2").arg(aOrderId, QString::number(aLitre).replace(".",",")));
    checkAuth(req);
    if ((req->getCode() != 200) && (req->getCode() != 401)) {
        qWarning(logError) << "setFuelNow" << aOrderId << req->getCode();
        emit s_error("setFuelNow", aOrderId, req->getCode());
    }
    delete req;
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

RequestData *YandexAPI::createRequest() {
    auto request = new RequestData(this);
    QObject::connect(request, &RequestData::s_finished, this, &YandexAPI::checkAuth);
    QObject::connect(request, &RequestData::s_request, this,
                     [=](QNetworkAccessManager::Operation operation, QString sRequest, QString post, int code) {
                        switch (operation) {
                        case QNetworkAccessManager::Operation::GetOperation: {
                            qInfo(logRequest) << "GET " << code << "Yandex    " << sRequest;
                            break;
                        }
                        case QNetworkAccessManager::Operation::PostOperation: {
                            qInfo(logRequest) << "POST" << code << "Yandex    " << sRequest << "(" + post + ")";
                            break;
                        }
                        default: {

                        }
                        }
                     });
    return request;
}

QNetworkRequest YandexAPI::createRequest(QString aUrl, QString aContentType, bool aAuth) {
    reestr_.sync();
    QNetworkRequest request(aUrl);
    request.setHeader(QNetworkRequest::ContentTypeHeader, aContentType.toUtf8());
    if (aAuth) {
        request.setRawHeader("Authorization", reestr_.value("Yandex Token").toString().toUtf8());
    }
    return request;
}

void YandexAPI::checkAuth(RequestData *aRequest) {
    if (aRequest->getCode() == 401) {
        emit s_needAuth(true);
    }
}

void YandexAPI::saveToken(RequestData *aRequest) {
    disconnect(aRequest, &RequestData::s_finished, this, &YandexAPI::saveToken);
    qDebug() << "Яндекс Токен:" << QString::fromUtf8(aRequest->getAuthorization());
    emit s_authComplete(QString::fromUtf8(aRequest->getAuthorization()));
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
