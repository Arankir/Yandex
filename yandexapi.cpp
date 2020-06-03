#include "yandexapi.h"

YandexAPI::YandexAPI(QString a_bazeurl, QObject *a_parent): QObject(a_parent), _bazeurl(a_bazeurl){}

void YandexAPI::GetPassword(QString a_login)
{
    RequestData *request = new RequestData(_bazeurl+"/api/auth?login="+a_login);
    QObject::connect(request,&RequestData::s_finished,this,&YandexAPI::deleteLater);
    //GET базовый url + /api/auth?login={login}
    //Система вышлет пароль на закрепленный за компанией Telegram канал, почту или смс
}

void YandexAPI::Authorization(QString a_login, QString a_password)
{
    RequestData *requests = new RequestData();
    QUrl url(_bazeurl+"/api/auth");
    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader,QString("application/x-www-form-urlencoded").toUtf8());
    connect(requests,&RequestData::s_finished,this,&YandexAPI::SaveToken);
    requests->Post(request,"login="+a_login+"&code="+a_password);
//    url + /api/auth
//    POST
//    login={login}&code={password}

//    АСУ АЗС должна проверять все запросы на ответ 401, если система получила ответ 401, то
//    необходимо провести Авторизацию в Яндекс.Заправки по новой
}

void YandexAPI::UpdatePriceList(QString a_pricelist)
{
    RequestData *requests = new RequestData();
    QSettings reestr("RegionPostavka","Yandex api");
    QUrl url(_bazeurl+"/api/price");
    QNetworkRequest networkRequest(url);
    networkRequest.setHeader(QNetworkRequest::ContentTypeHeader,QString("application/x-www-form-urlencoded"));
    networkRequest.setRawHeader("Authorization",reestr.value("Token").toString().toUtf8());
    requests->Post(networkRequest,a_pricelist);
    //requests->Get(networkRequest);
    QObject::connect(requests,&RequestData::s_finished,this,&YandexAPI::deleteLater);
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

void YandexAPI::UpdateConfigurationAGZS(QJsonObject a_configuration)
{
    RequestData *requests = new RequestData();
    QSettings reestr("RegionPostavka","Yandex api");
    QUrl url(_bazeurl+"/api/station");
    QNetworkRequest networkRequest(url);
    networkRequest.setRawHeader("Authorization",reestr.value("Token").toString().toUtf8());
    networkRequest.setHeader(QNetworkRequest::ContentTypeHeader,QString("application/json").toUtf8());
    requests->Post(networkRequest,QString(QJsonDocument(a_configuration).toJson(QJsonDocument::Compact)));
    QObject::connect(requests,&RequestData::s_finished,this,&YandexAPI::deleteLater);
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

void YandexAPI::UpdateConfigurationAGZS(QString a_configuration){
    RequestData *requests = new RequestData();
    QSettings reestr("RegionPostavka","Yandex api");
    QUrl url(_bazeurl+"/api/station");
    QNetworkRequest request(url);
    request.setRawHeader("Authorization",reestr.value("Token").toString().toUtf8());
    request.setHeader(QNetworkRequest::ContentTypeHeader,QString("application/json").toUtf8());
    qDebug()<<"Токен в запросе"<<reestr.value("Token").toString().toUtf8();
    requests->Post(request,a_configuration);
    QObject::connect(requests,&RequestData::s_finished,this,&YandexAPI::deleteLater);
}

void YandexAPI::CheckOrders(QString)
{
//    АСУ АЗС должна постоянно опрашивать систему Яндекс.Заправки для проверки поступления
//    новых заказов. Для этого необходимо выполнить HTTP запрос
//    GET базовый url + /api/orders/items
//    Authorization: {token}
//    200 ОК Тело ответа будет содержать JSON вида
//    Каждый следующий HTTP запрос нужно делать через указанное в параметре nextRetryMs
//    миллисекунд
//    {
//    // Интервал в миллисекундах, спустя это время допустимо повторит запрос
//    int nextRetryMs
//    // дата и время создания в UTC
//    List<Order> Orders
//    [
//    {
//    // идентификатор заказа
//    string Id
//    // дата и время создания в UTC
//    DateTime DateCreate
//    // тип заказа
//    OrderType OrderType
//    // значение заказа
//    double OrderVolume
//    // номер колонки
//    int ColumnId
//    // стоимость 1 литра топлива
//    double PriceFuel
//    // кол-во литров
//    double Litre
//    // идентификатор топлива
//    string FuelId
//    // текущий статус заказ
//    OrderStatus Status
//    // сумма заказа
//    double Sum,
//    // идентификатор договора
//    string ContractId
//    },
//    .... N
//    ]
//    }

//    Пример ответа
//    {
//    "nextRetryMs": 3000,
//    "orders": [
//    {
//    "id": "ca067937c98844a3b0ee2cfc41493e30",
//    "dateCreate": "2018-08-24T16:41:25.3593028Z",
//    "orderType": "Money",
//    "orderVolume": 500,
//    "columnId": 2,
//    "litre": 12.53,
//    "status": "AcceptOrder",
//    "fuelId": "a92",
//    "priceFuel": 39.88,
//    "sum": 499.7,
//    "ContractId": "Individual"
//    }
//    ]
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
//    •
//    Individual – договор возмездного оказания услуг (физические лица)
//    •
//    Corporation - договор купли продажи топлива (юридические лица)
//    Система Яндекс.Заправки фиксирует, когда был отправлен последний запрос на получение
//    заказов. В случае если прошло больше 5 минут с момента последнего запроса на получение
//    списка заказов, то станция временно выключается до момента поступления запроса на
//    получение заказа
}

void YandexAPI::SendLoadCounter(QString a_orderid, QString a_volume)
{
    RequestData *request = new RequestData();
    QSettings reestr("RegionPostavka","Yandex api");
    QUrlQuery query;
    query.addQueryItem("Authorization",reestr.value("Token").toString());
    query.addQueryItem("POST","orderId="+a_orderid+"&litre="+a_volume);
    request->Post(_bazeurl+"/api/orders/volume",query);
    QObject::connect(request,&RequestData::s_finished,this,&YandexAPI::deleteLater);
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

void YandexAPI::ReceiveVolumeReport(QDateTime sdate, QDateTime edate, int page)
{
    RequestData *request = new RequestData();
    QSettings reestr("RegionPostavka","Yandex api");
    QUrlQuery query;
    query.addQueryItem("Authorization",reestr.value("Token").toString());
    query.addQueryItem("POST","sdate="+sdate.toString("dd.MM.yyyy HH:mm:ss")+"&edate="+edate.toString("dd.MM.yyyy HH:mm:ss")+"&page="+QString::number(page));
    request->Post(_bazeurl+"/api/orders/report",query);
    QObject::connect(request,&RequestData::s_finished,this,&YandexAPI::On_ReceiveVolumeReport);
//    Отчет возвращается в формате JSON, массив объектов Order
//    базовый url + /api/orders/report
//    Authorization: {token}
//    POST
//    sdate={sdate}&edate={edate}&page={page}
//    все параметры являются обязательными

}

void YandexAPI::GetStateAGZS(QString apikey)
{
    RequestData *request = new RequestData(_bazeurl+"/api/station/enable?apikey="+apikey);
    QObject::connect(request,&RequestData::s_finished,this,&YandexAPI::deleteLater);
//    Отчет возвращается в формате JSON, массив объектов StationStatus
//    GET базовый url + /api/station/enable?apikey={apikey}
//    apikey – ключ сети, выписывается сервисом отдельно по запросу сети
}

void YandexAPI::On_ReceiveVolumeReport(RequestData *a_request)
{
    //sadasdasdasdasdads

    deleteLater();
    //    Тело ответа запроса содержит JSON вида
    //    // флаг наличия следующего листа отчета
    //    bool IsNextPage,
    //    // кол-во данных на листе
    //    int PageSize,
    //    // номер листа
    //    int PageIndex,
    //    // массив завершенных заказов
    //    List<OrderCompleted> Items
    //    sdate и edate – период отчета время по Московскому региону
    //    выборка идет по границам
    //    {order.DateEnd} <= sdate AND {order.DateEnd} < edate
    //    возможные форматы "dd.MM.yyyy HH:mm:ss", "dd.MM.yyyy"
    //    page – номер листа отчета по умолчанию = 0
    //    При формировании отчета за период система максимально отдает 1000 строк данных
    //    В ответе имеется параметр IsNextPage который сообщает о наличие следующего листа в
    //    отчете
    //    Отчет необходимо получать циклом до тех пор, пока IsNextPage = true
    //    JSON OrderCompleted
    //    {
    //    // идентификатор заказа
    //    string Id
    //    // дата и время создания в UTC
    //    DateTime DateCreate
    //    // тип заказа
    //    OrderType OrderType
    //    // значение заказа
    //    double OrderVolume
    //    // идентификатор станции АЗС
    //    string StationId,
    //    // внешний идентификатор станции АЗС
    //    string StationExtendedId
    //    // номер колонки
    //    int ColumnId
    //    // идентификатор топлива
    //    string FuelId
    //    // наименование марки топлива
    //    string FuelMarka
    //    // идентификатор прайса
    //    string PriceId
    //    // внешний идентификатор прайса
    //    string FuelExtendedId
    //    // стоимость 1 литра топлива
    //    double PriceFuel
    //    // сумма заказа
    //    double Sum
    //    // кол-во литров
    //    double Litre
    //    // итого оплачено
    //    double SumPaid
    //    // статус заказ
    //    OrderStatus Status
    //    // дата и время завершения заказа UTC
    //    DateTime DateEnd
    //    // идентификатор причины отмены заказа
    //    string ReasonId
    //    // причина отмены
    //    string Reason
    //    // итого сумма литров залито
    //    double LitreCompleted
    //    // итого оплачено по завершению заказа
    //    double SumPaidCompleted
    //    // идентификатор договора
    //    string ContractId
    //    }
    //    Параметр Status – статус заказа может принимать следующие значения
    //    • Completed – заказа завершен успешно
    //    • StationCanceled – заказ отменен оператором АЗС или же интегрируемой системой
    //    • UserCanceled – заказ отменен пользователем
}

void YandexAPI::On_GetStateAGZS(RequestData *a_request)
{
    //werwerwerwerwerwer

    deleteLater();

    //    Тело ответа запроса содержит JSON вида
    //    [
    //    {
    //    // идентификатор станции в системе Яндекс.Заправки
    //    string id,
    //    // идентификатор станции
    //    string ExtendedId,
    //    // наименование станции
    //    string name,
    //    // статус станции
    //    string status,
    //    // дата последнего запроса от АЗС UTC
    //    datetime lastUpdateStatus,
    //    }
    //    …. N
    //    ]
    //    Параметр Status – статус заказа может принимать следующие значения
    //    • Disable – станция
    //    • Online – станция в онлайне
    //    • Offline – станция в офлайне
    //    Параметр lastUpdateStatus – содержит дату и время в UTC по ней можно определять как давно станция не в сети
}

void YandexAPI::SaveToken(RequestData *a_request){
    QSettings reestr("RegionPostavka","Yandex api");
    qDebug()<<"Токен:"<<QString::fromUtf8(a_request->GetAuthorization());
    reestr.setValue("Token",QString::fromUtf8(a_request->GetAuthorization()));
    reestr.sync();
    deleteLater();
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
