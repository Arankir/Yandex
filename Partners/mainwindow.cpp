#include "mainwindow.h"
#include "ui_mainwindow.h"

const double c_litersForMin = 25;
const QString c_host = "api";

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow), _reestr("RegionPostavka", "Partners") {
    ui->setupUi(this);

    if (!_reestr.value("isTest").toBool()) {
        ui->ButtonCancelYandex->setVisible(false);
        ui->ButtonCancelCitymobile->setVisible(false);
        ui->lineEdit->setVisible(false);
    }

    ui->label  ->setTextFormat(Qt::RichText);
    ui->label_2->setTextFormat(Qt::RichText);
    ui->label  ->setText("<img height=25 style=\"vertical-align: top\" src=\"://images/login.png\"> Логин</a>");
    ui->label_2->setText("<img height=25 style=\"vertical-align: top\" src=\"://images/login password.png\"> Пароль</a>");
    ui->ButtonSettings->setIcon(QIcon("://images/settings.png"));
    ui->LabelVersion->setText("v1.5");

    setTrayIconActions();
    showTrayIcon();

    _yandex = new YandexAPI(this);
    _cityMobile = new CityMobileAPI(this);

    connect(&_timerYandexAgzsData,      &QTimer::timeout,                       this, &MainWindow::updateDataYandex);
    connect(&_timerYandexOrders,        &QTimer::timeout,                       this, &MainWindow::getOrdersYandex);
    connect(&_timerCityMobileAgzsData,  &QTimer::timeout,                       this, &MainWindow::updateDataCityMobile);
    connect(&_timerCityMobileOrders,    &QTimer::timeout,                       this, &MainWindow::getOrdersCityMobile);
    connect(&_timerYandexError,         &QTimer::timeout,                       this, &MainWindow::yandexErrorNotification);
    connect(_yandex,                    &YandexAPI::s_needAuth,                 this, &MainWindow::needAuth);
    connect(_yandex,                    &YandexAPI::s_authComplete,             this, &MainWindow::authYandexResult);
    connect(_yandex,                    &YandexAPI::s_networkRequestInfo,       this, &MainWindow::requestToLog);
    connect(_cityMobile,                &CityMobileAPI::s_networkRequestInfo,   this, &MainWindow::requestToLog);
    connect(_yandex,                    &YandexAPI::s_updatePrice,              this, [=](                    ) {updatePrice(Partner::yandex);});
    connect(_yandex,                    &YandexAPI::s_gotOrders,                this, [=](QJsonDocument orders) {processOrders(Partner::yandex, orders);});
    connect(_cityMobile,                &CityMobileAPI::s_gotOrders,            this, [=](QJsonDocument orders) {processOrders(Partner::citymobile, orders);});

    _timerYandexAgzsData    .start(60000);
    _timerYandexOrders      .start(5000);
    _timerCityMobileAgzsData.start(60000);
    _timerCityMobileOrders  .start(5000);

}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::authYandexResult(QString aToken) {
    ui->labelAuthError->setVisible(true);
    if (aToken == "") {
        _errorPassword++;
        if (_errorPassword < 5) {
            ui->labelAuthError->setText(tr("Ошибка при авторизации Яндекса.\nПроверьте пароль.\nОшибок: %1").arg(_errorPassword));
        } else {
            ui->labelAuthError->setText(tr("Превышено количество ошибок.\nЗапросите пароль Яндекса заново."));
        }
    } else {
        _db.setYandexToken(aToken);
        _timerYandexError.stop();
        ui->labelAuthError->setText(tr("Успешно авторизовано!"));
        _timerYandexOrders.start(5000);
    }
}

void MainWindow::needAuth() {
    ui->labelAuthError->setVisible(true);
    ui->labelAuthError->setText(tr("Пожалуйста, авторизуйтесь\nв Яндексе заново."));
    _timerYandexOrders.stop();
    _timerYandexError.start(0);
}

void MainWindow::requestToLog(QString api, QString type, QString request, QString post, int code) {
    if ((request.indexOf("price") > 0) && (_reestr.value("agzsPriceLog") == false)) {
        return;
    }
    if ((request.indexOf("station") > 0) && (_reestr.value("agzsDataLog") == false)) {
        return;
    }
    if ((request.indexOf("items") > 0) && (_reestr.value("ordersLog") == false)) {
        return;
    }
    if (type == "GET") {
        _db.logAppend(api + " " + type + "(" + request + ") Код:" + QString::number(code));
    } else if (type == "POST") {
        _db.logAppend(api + " " + type + "(" + request + " '" + post + "') Код:" + QString::number(code));
    }
}

void MainWindow::yandexErrorNotification() {
    QMessageBox::warning(0, tr("Ошибка"), tr("Авторизуйтесь в Яндексе заново!"));
    QApplication::alert(this);
    _timerYandexError.setInterval(300000);
}

#define ButtonsStart {
void MainWindow::on_ButtonEnter_clicked() {
    _yandex->authorization(ui->LineEditLogin->text(),ui->LineEditPassword->text());
}

void MainWindow::on_ButtonGetPassword_clicked() {
    _yandex->getPassword(ui->LineEditLogin->text());
    _errorPassword = 0;
    ui->labelAuthError->setText(tr("Введите пароль."));
}

void MainWindow::on_ButtonCancelYandex_clicked() {
    _yandex->setStatusCanceled(ui->lineEdit->text(), "Ошибка 1", ui->lineEdit->text(), QDateTime::currentDateTime());
}

void MainWindow::on_ButtonCancelCitymobile_clicked() {
    _cityMobile->setStatusCanceled(ui->lineEdit->text(), "Ошибка 1", ui->lineEdit->text(), QDateTime::currentDateTime());
}

void MainWindow::on_ButtonSettings_clicked() {
    FormSettings *settings = new FormSettings();
    settings->show();
}
#define ButtonsEnd }

#define FuelStart {
int MainWindow::FuelApiToFuelId(QString aFuelIdApi) {
    if(aFuelIdApi == "diesel")
        return 32;
    if(aFuelIdApi == "diesel_premium")
        return 0;
    if(aFuelIdApi == "a80")
        return 0;
    if(aFuelIdApi == "a92")
        return 3;
    if(aFuelIdApi == "a92_premium")
        return 0;
    if(aFuelIdApi == "a95")
        return 8;
    if(aFuelIdApi == "a95_premium")
        return 0;
    if(aFuelIdApi == "a98")
        return 0;
    if(aFuelIdApi == "a98_premium")
        return 0;
    if(aFuelIdApi == "a100")
        return 0;
    if(aFuelIdApi == "a100_premium")
        return 0;
    if(aFuelIdApi == "propane")
        return 14;
    if(aFuelIdApi == "metan")
        return 0;
    return 0;
}

QString MainWindow::FuelIdToFuelApi(int aFuelVCode) {
    switch(aFuelVCode) {
    case 3: {
        return "a92";
    }
    case 14: {
        return "propane";
    }
    case 32: {
        return "diesel";
    }
    default: {
        return "";
    }
    }
}

QString MainWindow::getFuelName(int aFuelVCode) {
    switch(aFuelVCode) {
    case 3: {
        return "А-92";
    }
    case 14: {
        return "Пропан";
    }
    case 32: {
        return "Дизель";
    }
    default: {
        return "";
    }
    }
}
#define FuelEnd }

void MainWindow::updateDataYandex() {
    if (_reestr.value("Yandex Enabled", QVariant(false)).toBool()) {
        updatePrice(Partner::yandex);
        updateConfiguration(Partner::yandex);
        //_yandex->checkOrders();
    }
}

void MainWindow::getOrdersYandex() {
    if (_reestr.value("Yandex Enabled", QVariant(false)).toBool()) {
        _yandex->checkOrders();
    }
}

void MainWindow::updateDataCityMobile() {
    if (_reestr.value("CityMobile Enabled", QVariant(false)).toBool()) {
        updatePrice(Partner::citymobile);
        updateConfiguration(Partner::citymobile);
        //_cityMobile->checkOrders();
    }
}

void MainWindow::getOrdersCityMobile() {
    if (_reestr.value("CityMobile Enabled", QVariant(false)).toBool()) {
        _cityMobile->checkOrders();
    }
}

void MainWindow::moneyData(Partner aPartner, Order aOrder, double &aRequestTotalPriceDB, double &aRequestVolumeDB, double &aRequestUnitPriceDB, double &aMoneyTakenDB, int &aFullTankDB) {
    switch (aPartner) {
    case Partner::yandex: {

    }
    case Partner::citymobile: {
        if (aOrder.orderType == "Money") {
            aRequestTotalPriceDB = aOrder.orderVolume;
            aRequestUnitPriceDB = aOrder.priceFuel;
            int temp = (aRequestTotalPriceDB / aRequestUnitPriceDB) * 100;
            aRequestVolumeDB = temp / 100;
            aMoneyTakenDB = aOrder.orderVolume;
            aFullTankDB = 0;
        } else if (aOrder.orderType == "Liters") {
            aRequestVolumeDB = aOrder.orderVolume;
            aRequestUnitPriceDB = aOrder.priceFuel;
            aRequestTotalPriceDB = aRequestVolumeDB * aRequestUnitPriceDB;
            aMoneyTakenDB = aOrder.orderVolume;
            aFullTankDB = 0;
        } else if (aOrder.orderType == "FullTank") {
            aRequestTotalPriceDB = aOrder.orderVolume;
            aRequestUnitPriceDB = aOrder.priceFuel;
            int temp = (aRequestTotalPriceDB / aRequestUnitPriceDB) * 100;
            aRequestVolumeDB = temp / 100;
            aMoneyTakenDB = aOrder.orderVolume;
            aFullTankDB = 1;
        }
        break;
    }
    }
}

void MainWindow::getNozzleFuelCode(AdastTrk aTrk, QString aFuelId, int &aNozzle, int &aFuelCode) {
    int fuelId = FuelApiToFuelId(aFuelId);
    if (fuelId == aTrk.fuel1) {
        aNozzle = 1;
        aFuelCode = aTrk.fuelCode1;
    } else if (fuelId == aTrk.fuel2) {
        aNozzle = 2;
        aFuelCode = aTrk.fuelCode2;
    } else if (fuelId == aTrk.fuel3) {
        aNozzle = 3;
        aFuelCode = aTrk.fuelCode3;
    } else if (fuelId == aTrk.fuel4) {
        aNozzle = 4;
        aFuelCode = aTrk.fuelCode4;
    } else if (fuelId == aTrk.fuel5) {
        aNozzle = 5;
        aFuelCode = aTrk.fuelCode5;
    }
}

Transaction MainWindow::createEmptyTransaction() {
    Transaction transaction;
    transaction.trkType = "ADAST";
    transaction.transNum = "";
    transaction.trkTotalPrice = 0.0;
    transaction.trkVolume = 0.0;
    transaction.trkUnitPrice = 0.0;
    transaction.requestField = "V";
    transaction.state = "Завершение выдачи";
    transaction.iState = 8;
    transaction.trkTransType = "P";
    transaction.litersCountBefore = 0.0;
    transaction.moneyCountBefore = 0.0;
    transaction.transCountBefore = 0;
    transaction.litersCountAfter = 0.0;
    transaction.moneyCountAfter = 0.0;
    transaction.transCountAfter = 0;
    transaction.result = "Выдача завершена: 1";
    transaction.temperature = -100;
    transaction.cHost = c_host;
    transaction.wHost = c_host;
    transaction.cUser = c_host;
    transaction.wUser = c_host;
    transaction.addedForTransVCode = 0;
    transaction.aditionalTransVCode = 0;
    transaction.active = 0;
    transaction.mass = 0.0;
    return transaction;
}

int MainWindow::createTransaction(Agzs currentAgzs, Order order, Partner aPartner, int sideAdress, QDateTime now) {
    int transactionVCode = (_db.getLastVCode("ADAST_TRKTransaction", true) + 1) * 100 + currentAgzs.agzs;
    double requestTotalPriceDB = -1, requestVolumeDB = -1, requestUnitPriceDB = -1, moneyTakenDB = -1;
    int fullTankDB = -1;
    moneyData(aPartner, order, requestTotalPriceDB, requestVolumeDB, requestUnitPriceDB, moneyTakenDB, fullTankDB);
    AdastTrk currentTrk = _db.getAgzsAdastTrk(sideAdress);
    int nozzle = 0;
    int trkFuelCode = 0;
    getNozzleFuelCode(currentTrk, order.fuelId, nozzle, trkFuelCode);
    FuelNames fuelName = _db.getFuelNames(FuelApiToFuelId(order.fuelId));

    if ((requestTotalPriceDB > -1) && (requestVolumeDB > -1) && (requestUnitPriceDB > -1) && (moneyTakenDB > -1) && (fullTankDB > -1)) {
        Transaction transaction = createEmptyTransaction();
        transaction.agzsName = currentAgzs.agzsName;
        transaction.localVCode = transactionVCode;
        transaction.deviceName = currentTrk.deviceName;
        transaction.serial = currentTrk.serial;
        transaction.fuelName = fuelName.fullName;
        transaction.fuelShortName = fuelName.shortName;
        transaction.side = currentTrk.side;
        transaction.sideAdress = sideAdress;
        transaction.nozzle = nozzle;
        transaction.trkFuelCode = trkFuelCode;
        transaction.requestTotalPrice = requestTotalPriceDB;
        transaction.requestVolume = requestVolumeDB;
        transaction.requestUnitPrice = requestUnitPriceDB;
        transaction.dateOpen = now;
        transaction.dateClose = now;
        switch (aPartner) {
        case Partner::yandex: {
            transaction.payWay = "ЯНДЕКС";
            break;
        }
        case Partner::citymobile: {
            transaction.payWay = "СИТИМОБИЛ";
            break;
        }
        }
        transaction.cDate = now;
        transaction.wDate = now;
        transaction.vCode = transactionVCode;
        transaction.smena = _db.getSmena();
        transaction.trkVcode = currentTrk.trkVCode;
        transaction.capacityVcode = _db.getCashBoxIndex(QString::number(static_cast<int>(aPartner)));
        transaction.pumpPlace = currentTrk.pumpPlace;
        transaction.moneyTaken = moneyTakenDB;
        transaction.iPayWay = static_cast<int>(aPartner);
        transaction.fullTank = fullTankDB;
        transaction.agzs = currentAgzs.agzs;
        transaction.fuelVCode = FuelApiToFuelId(order.fuelId);
        transaction.propan = 0;

        if (_db.createTrkTransaction(transaction)) {
            return transactionVCode;
        }
    } else {
        return -2;
    }
    return -1;
}

Order MainWindow::JsonToOrder(Partner aPartner, QJsonValue aOrder) {
    switch (aPartner) {
    case Partner::yandex: {
        Order order;
        order.id = aOrder.toObject().value("id").toString();
        order.dateCreate = QDateTime::fromString(aOrder.toObject().value("dateCreate").toString().left(23), "yyyy-MM-ddThh:mm:ss.zzz");
        order.orderType = aOrder.toObject().value("orderType").toString();
        order.orderVolume = aOrder.toObject().value("orderVolume").toDouble();
        order.columnId = aOrder.toObject().value("columnId").toInt();
        order.litre = aOrder.toObject().value("litre").toDouble();
        order.status = aOrder.toObject().value("status").toString();
        order.fuelId = aOrder.toObject().value("fuelId").toString();
        order.priceFuel = aOrder.toObject().value("priceFuel").toDouble();
        order.sum = aOrder.toObject().value("sum").toDouble();
        order.contractId = aOrder.toObject().value("contractId").toString();
        return order;
        break;
    }
    case Partner::citymobile: {
//            {
//            "Id": "088ccc98-73e3-4b4a-aaa9-79dddd02720a",
//            "DateCreate" :  "2019-11-20T17:28:33.994Z",
//            "OrderType":  "Litre",
//            "OrderVolume": "10",
//            -"StationId":  "1234",
//            -"StationExtendedId":  "1234",
//            "ColumnId":  "1",
//            "FuelId":  "a92",
//            "PriceFuel":  "42.50",
//            "Litre":  "10",
//            "Sum":  "425.00",
//            "Status":  "OrderCreated",
//            "ContractId":  "32135"
//            }
        Order order;
        order.id = aOrder.toObject().value("id").toString();
        order.dateCreate = QDateTime::fromString(aOrder.toObject().value("dateCreate").toString().left(23), "yyyy-MM-ddThh:mm:ss.zzz");
        order.orderType = aOrder.toObject().value("orderType").toString();
        order.orderVolume = aOrder.toObject().value("orderVolume").toDouble();
        order.columnId = aOrder.toObject().value("columnId").toInt();
        order.litre = aOrder.toObject().value("litre").toDouble();
        order.status = aOrder.toObject().value("status").toString();
        order.fuelId = aOrder.toObject().value("fuelId").toString();
        order.priceFuel = aOrder.toObject().value("priceFuel").toDouble();
        order.sum = aOrder.toObject().value("sum").toDouble();
        order.contractId = aOrder.toObject().value("contractId").toString();
        return order;
        break;
    }
    }
}

void MainWindow::sendLiters(Partner aPartner, ApiTransaction aApiTransaction, QString aOrderId) {
    Transaction transaction = _db.getTransactionData(aApiTransaction.headVCode);
    QDateTime now = QDateTime::currentDateTime();
    QDateTime diffTime = QDateTime::fromMSecsSinceEpoch(now.toMSecsSinceEpoch() - transaction.dateOpen.toMSecsSinceEpoch()).addSecs(-20);
    double litersNow = diffTime.toSecsSinceEpoch() * (c_litersForMin / 60);
    if ((litersNow > 0) && (litersNow < aApiTransaction.apiLitre)) {
        switch (aPartner) {
        case Partner::yandex: {
            _yandex->setFuelNow(aOrderId, litersNow);
            break;
        }
        case Partner::citymobile: {
            _cityMobile->setStatusFuelNow(aOrderId, litersNow);
            break;
        }
        }
    }
}

#define FunctionsStart {
void MainWindow::updatePrice(Partner aPartner) {
    //    key1=value1&key2=value2&...
    QStringList prices;
    Price price = _db.getPrices(QString::number(static_cast<int>(aPartner)));
    if(price.diesel > 0.1f) {
        prices.append("diesel="         + QString::number(price.diesel));
    }
    if(price.diesel_premium > 0.1f) {
        prices.append("diesel_premium=" + QString::number(price.diesel_premium));
    }
    if(price.a80 > 0.1f) {
        prices.append("a80="            + QString::number(price.a80));
    }
    if(price.a92 > 0.1f) {
        prices.append("a92="            + QString::number(price.a92));
    }
    if(price.a92_premium > 0.1f) {
        prices.append("a92_premium="    + QString::number(price.a92_premium));
    }
    if(price.a95 > 0.1f) {
        prices.append("a95="            + QString::number(price.a95));
    }
    if(price.a95_premium > 0.1f) {
        prices.append("a95_premium="    + QString::number(price.a95_premium));
    }
    if(price.a98 > 0.1f) {
        prices.append("a98="            + QString::number(price.a98));
    }
    if(price.a98_premium > 0.1f) {
        prices.append("a98_premium="    + QString::number(price.a98_premium));
    }
    if(price.a100 > 0.1f) {
        prices.append("a100="           + QString::number(price.a100));
    }
    if(price.a100_premium > 0.1f) {
        prices.append("a100_premium="   + QString::number(price.a100_premium));
    }
    if(price.propane > 0.1f) {
        prices.append("propane="        + QString::number(price.propane));
    }
    if(price.metan > 0.1f) {
        prices.append("metan="          + QString::number(price.metan));
    }
    switch (aPartner) {
    case Partner::yandex: {
        _yandex    ->updatePriceList(prices.join("&").replace(",","."));
        break;
    }
    case Partner::citymobile: {
        _cityMobile->updatePriceList(prices.join("&").replace(",","."));
        break;
    }
    }
}

void MainWindow::updateConfiguration(Partner aPartner) {
    Agzs currentAgzs = _db.getAgzsData();

    switch (aPartner) {
    case Partner::yandex: {
        //        {
        //            "StationExtendedId": "00001",
        //            "Columns": {
        //                1: {
        //                    "Fuels": [
        //                        "a92",
        //                        "a95",
        //                        "diesel_premium"
        //                    ]
        //                },
        //                2: {
        //                    "Fuels": [
        //                        "a92",
        //                        "a95_premium",
        //                        "a98_premium",
        //                        "diesel_premium"
        //                    ]
        //                }
        //            }
        //        }

        QJsonObject AGZS;
        AGZS["StationExtendedId"] = QString::number(currentAgzs.agzs);
        //Columns
        QJsonObject columns;

        QVector<QPair<int, QVector<int>>> fuels;
        _db.getFuels(fuels);//first = Адрес, second = Топлива
        for (auto &side: fuels) {
            if (side.first > 0) {//без 0 колонки
                QJsonObject sideJ;
                QJsonArray fuelsJ;
                for (auto &fuel: side.second) {
                    if (fuel > 0) {
                        fuelsJ.push_back(FuelIdToFuelApi(fuel));
                    }
                }
                sideJ["Fuels"] = fuelsJ;
                columns[QString::number(side.first)] = sideJ;
            }
        }
        AGZS["Columns"] = columns;

        _yandex->updateConfigurationAGZS(AGZS);
        break;
    }
    case Partner::citymobile: {
        //    {
        //        "StationExtendedId": "1234",
        //        "Columns": {
        //            "1": {
        //                "Fuels": ["a92", "a95", "a95_premium", "diesel_premium"]
        //            },
        //            "2": {
        //                "Fuels": ["a92", "a95", "a95_premium", "a100_premium"]
        //            }
        //        },
        //        "Enable": true,
        //        "Name": "АЗС \"На Мандариновой\" №10",
        //        "Address": "г. Энск, ул. Мандариновая, 4",
        //        "Location": { "Lon": 43.5432, "Lat": 34.1234 },
        //        "FuelNames": [
        //        {
        //            "Fuel": "a92",
        //            "FuelName": "АИ-92"
        //        },
        //        {
        //            "Fuel": "a95",
        //            "FuelName": "АИ-95"
        //        },
        //        {
        //            "Fuel": "a95_premium",
        //            "FuelName": "G-95"
        //        },
        //        {
        //            "Fuel": "a100_premium",
        //            "FuelName": "G-100"
        //        },
        //        {
        //            "Fuel": "diesel_premium",
        //            "FuelName": "ДТ Опти"
        //        }
        //        ]
        //    }

        QJsonObject AGZS;
        AGZS["StationExtendedId"] = QString::number(currentAgzs.agzs);
        AGZS["Enable"] = true;
        AGZS["Name"] = currentAgzs.agzsName;
        AGZS["Adress"] = currentAgzs.adress;

        QJsonObject Location;
        Location["Lon"] = QString::number(currentAgzs.loc_y).replace(",",".");
        Location["Lat"] = QString::number(currentAgzs.loc_x).replace(",",".");
        AGZS["Location"] = Location;
        //Columns
        QJsonObject columns;
        QJsonArray fuelNames;

        QVector<QPair<int, QVector<int>>> fuels;
        _db.getFuels(fuels);
        for (auto &side: fuels) {
            if (side.first > 0) {
                QJsonObject sideJ;
                QJsonArray fuelsJ;
                for (auto &fuelCode: side.second) {
                    if (fuelCode > 0) {
                        fuelsJ.push_back(FuelIdToFuelApi(fuelCode));
                        bool isNeedInsert = true;
                        for (auto fuel: fuelNames) {
                            if (fuel.toObject().value("Fuel").toString() == FuelIdToFuelApi(fuelCode)) {
                                isNeedInsert = false;
                                break;
                            }
                        }
                        if (isNeedInsert) {
                            QJsonObject fuel;
                            fuel["Fuel"] = FuelIdToFuelApi(fuelCode);
                            fuel["FuelName"] = getFuelName(fuelCode);
                            fuelNames.append(fuel);
                        }
                    }
                }
                sideJ["Fuels"] = fuelsJ;
                columns[QString::number(side.first)] = sideJ;
            }
        }
        AGZS["Columns"] = columns;
        AGZS["FuelNames"] = fuelNames;
        QJsonDocument doc;
        doc.setObject(AGZS);
        _cityMobile->updateConfigurationAGZS(doc);
        break;
    }
    }
}

void MainWindow::processOrders(Partner aPartner, QJsonDocument aOrders) {
    switch (aPartner) {
    case Partner::yandex: {
        for (auto order: aOrders.object().value("orders").toArray()) {
            Order currentOrder = JsonToOrder(aPartner, order);
            if (currentOrder.status == "AcceptOrder") { //заказ ожидает подтверждения от АСУ АЗС
                if (!_db.isTransactionExist(currentOrder.id)) {
                    QDateTime now           = QDateTime::currentDateTime();
                    int lastAPIVCode        = (_db.getLastVCode("PR_APITransaction", true) + 1) * 100 + _db.getCurrentAgzs();
                    Agzs currentAgzs        = _db.getAgzsData();
                    int sideAdress          = _db.getRealSideAddress(currentAgzs.agzs, currentOrder.columnId);
                    int error               = _db.checkError(QString::number(sideAdress),
                                                currentOrder.fuelId,
                                                FuelApiToFuelId(currentOrder.fuelId),
                                                QString::number(currentOrder.priceFuel),
                                                static_cast<int>(aPartner));
                    int transactionVCode    = -1;

                    switch (error) {
                    case 0: {
                        transactionVCode = createTransaction(currentAgzs, currentOrder, aPartner, sideAdress, now);
                        break;
                    }
                    case 1: {
                        _db.logAppend("Error Указанная колонка не найдена " + currentOrder.id);
                        _yandex->setStatusCanceled(currentOrder.id, "Указанная колонка не найдена.", QString::number(lastAPIVCode), now);
                        break;
                    }
                    case 2: {
                        _db.logAppend("Error Не обнаружено указанное топливо " + currentOrder.id);
                        _yandex->setStatusCanceled(currentOrder.id, "Не обнаружено указанное топливо.", QString::number(lastAPIVCode), now);
                        break;
                    }
                    case 3: {
                        _db.logAppend("Error Цена на выбранный вид топлива отличается от фактической цены " + currentOrder.id);
                        _yandex->setStatusCanceled(currentOrder.id, "Цена на выбранный вид топлива отличается от фактической цены.", QString::number(lastAPIVCode), now);
                        break;
                    }
                    }

                    _db.createApiTransaction(currentAgzs.agzsName, currentAgzs.agzs, currentOrder.dateCreate,
                                         lastAPIVCode, currentOrder.id, "", currentOrder.columnId, currentOrder.fuelId,
                                         FuelApiToFuelId(currentOrder.fuelId), currentOrder.priceFuel, currentOrder.litre,
                                         currentOrder.sum, currentOrder.status, currentOrder.contractId, "Yandex",
                                         error != 0 ? "Error: " + QString::number(error) : "0", 0, 0, 0, now, transactionVCode);
                    if (error == 0) {
                        _yandex->setStatusAccept(currentOrder.id, lastAPIVCode);
                    }
                }
            } else {
                ApiTransaction apiTransaction = _db.getApiTransactionState(currentOrder.id);
                if (currentOrder.status == "WaitingRefueling") { //ожидаем включения налива на ТРК
                    if (QString::number(apiTransaction.iState) != apiTransaction.localState) {
                        if (apiTransaction.iState > 0) {
                            _db.updateApiTransactionState(apiTransaction.localState, apiTransaction.dateClose, apiTransaction.apiVCode);
                        }
                        _yandex->setStatusFueling(currentOrder.id, apiTransaction.apiVCode);
                    }
                } else if (currentOrder.status == "Fueling") { //идет налив
                    sendLiters(aPartner, apiTransaction, currentOrder.id);

                    if (QString::number(apiTransaction.iState) != apiTransaction.localState) {
                        switch (apiTransaction.iState) {
                        case 1 ... 4: {//Цена установлена
                            _db.updateApiTransactionState(apiTransaction.localState, apiTransaction.dateClose, apiTransaction.apiVCode);
                            break;
                        }
                        case 5 ... 8 :{//Выдано //Подтверждение   Завершение выдачи //Обновление счетчиков //Завершение выдачи
                            if (apiTransaction.localState != 5) {
                                double amount = 0.0f, volume = 0.0f, price = 0.0f;
                                _db.getPayOperationLiters(apiTransaction.headVCode, amount, volume, price);

                                if((amount > 0.1) && (volume > 0.1) && (price > 0.1)) {
                                    _db.finalUpdateApiTransactionState("5", price, volume, amount, apiTransaction.dateOpen, apiTransaction.dateClose, apiTransaction.apiVCode);
                                    _yandex->setStatusCompleted(currentOrder.id, volume, QString::number(apiTransaction.apiVCode), apiTransaction.dateClose);
                                }
                            }
                            break;
                        }
                        default: {

                        }
                        }
                    }
                } else if (currentOrder.status == "Expire") { //статус от АЗС не поступил в течение 30 минут
                    _db.updateApiTransactionState("Ошибка: 30 минут", apiTransaction.dateClose, apiTransaction.apiVCode);
                    _db.setTransactionClosed(currentOrder.id, 1);

                    _yandex->setStatusCanceled(currentOrder.id, "Истекло время ожидания", QString::number(apiTransaction.apiVCode), apiTransaction.dateOpen);
                }
            }
        }
        if (aOrders.object().value("nextRetryMs").isDouble()) {
            _timerYandexOrders.setInterval(aOrders.object().value("nextRetryMs").toInt());
        }
        break;
    }
    case Partner::citymobile: {
        //AcceptOrder, Expire, Completed, StationCanceled, UserCanceled, WaitingRefueling, Fueling
        for(auto order: aOrders.object().value("orders").toArray()) {
            Order currentOrder = JsonToOrder(aPartner, order);
            if (currentOrder.status == "AcceptOrder") { //заказ создан, полностью оплачен и ожидает подтверждения от АСУ АЗС
                if (!_db.isTransactionExist(currentOrder.id)) {
                    QDateTime now = QDateTime::currentDateTime();
                    int lastAPIVCode = (_db.getLastVCode("PR_APITransaction", true) + 1) * 100 + _db.getCurrentAgzs();
                    Agzs currentAgzs = _db.getAgzsData();
                    int sideAdress = _db.getRealSideAddress(currentAgzs.agzs, currentOrder.columnId);
                    int error = _db.checkError(QString::number(sideAdress),
                                            currentOrder.fuelId,
                                            FuelApiToFuelId(currentOrder.fuelId),
                                            QString::number(currentOrder.priceFuel),
                                            static_cast<int>(aPartner));
                    int transactionVCode = 0;

                    switch (error) {
                    case 0: {
                        transactionVCode = createTransaction(currentAgzs, currentOrder, aPartner, sideAdress, now);
                        if (transactionVCode == -2) {
                            _cityMobile->setStatusCanceled(currentOrder.id, "Указанная колонка не найдена.", QString::number(lastAPIVCode), now);
                        }
                        break;
                    }
                    case 1: {
                        _db.logAppend("Error Неизвестная ошибка " + currentOrder.id);
                        _cityMobile->setStatusCanceled(currentOrder.id, "Неизвестная ошибка.", QString::number(lastAPIVCode), now);
                        break;
                    }
                    case 2: {
                        _db.logAppend("Error Не обнаружено указанное топливо " + currentOrder.id);
                        _cityMobile->setStatusCanceled(currentOrder.id, "Не обнаружено указанное топливо.", QString::number(lastAPIVCode), now);
                        break;
                    }
                    case 3: {
                        _db.logAppend("Error Цена на выбранный вид топлива отличается от фактической цены " + currentOrder.id);
                        _cityMobile->setStatusCanceled(currentOrder.id, "Цена на выбранный вид топлива отличается от фактической цены.", QString::number(lastAPIVCode), now);
                        break;
                    }
                    }
                    _db.createApiTransaction(currentAgzs.agzsName, currentAgzs.agzs, currentOrder.dateCreate,
                                         lastAPIVCode, currentOrder.id, "", currentOrder.columnId, currentOrder.fuelId,
                                         FuelApiToFuelId(currentOrder.fuelId), currentOrder.priceFuel, currentOrder.litre,
                                         currentOrder.sum, currentOrder.status, currentOrder.contractId, "CityMobile",
                                         error != 0 ? "Error: " + QString::number(error) : "0", 0, 0, 0, now, transactionVCode);
                    if (error == 0) {
                        _cityMobile->setStatusAccept(currentOrder.id, lastAPIVCode);
                    }
                }
            } else {
                ApiTransaction apiTransaction = _db.getApiTransactionState(currentOrder.id);
                if (currentOrder.status == "WaitingRefueling") { //ожидание включения налива на ТРК
                    if (QString::number(apiTransaction.iState) != apiTransaction.localState) {
                        if (apiTransaction.iState > 0) {
                            _db.updateApiTransactionState(apiTransaction.localState, apiTransaction.dateClose, apiTransaction.apiVCode);
                        }
                        _cityMobile->setStatusFueling(currentOrder.id, apiTransaction.apiVCode);
                    }
                } else if (currentOrder.status == "Fueling") { //идет налив
                    sendLiters(aPartner, apiTransaction, currentOrder.id);

                    if (QString::number(apiTransaction.iState) != apiTransaction.localState) {
                        switch (apiTransaction.iState) {
                        case 1 ... 4: {//Цена установлена
                            _db.updateApiTransactionState(apiTransaction.localState, apiTransaction.dateClose, apiTransaction.apiVCode);
                            break;
                        }
                        case 5 ... 8 : {//Выдано //Подтверждение   Завершение выдачи //Обновление счетчиков //Завершение выдачи
                            if (apiTransaction.localState != 5) {
                                double amount = 0.0f, volume = 0.0f, price = 0.0f;
                                _db.getPayOperationLiters(apiTransaction.headVCode, amount, volume, price);

                                if((amount > 0.1) && (volume > 0.1) && (price > 0.1)){
                                    _db.finalUpdateApiTransactionState("5", price, volume, amount, apiTransaction.dateOpen, apiTransaction.dateClose, apiTransaction.apiVCode);
                                    _cityMobile->setStatusCompleted(currentOrder.id, volume, QString::number(apiTransaction.apiVCode), apiTransaction.dateClose);
                                }
                            }
                            break;
                        }
                        default: {

                        }
                        }
                    }
                } else if (currentOrder.status == "Expire") { //статус от АЗС не поступил в течение 30 минут
                    _db.updateApiTransactionState("Ошибка: 30 минут", apiTransaction.dateClose, apiTransaction.apiVCode);
                    _db.setTransactionClosed(currentOrder.id, 1);

                    _cityMobile->setStatusCanceled(currentOrder.id, "Истекло время ожидания", QString::number(apiTransaction.apiVCode), apiTransaction.dateOpen);
                } else if (currentOrder.status == "StationCanceled") { //заказ отменен оператором АЗС или же интегрируемой системой

                } else if (currentOrder.status == "UserCanceled") { //заказ отменен пользователем
                    //_db.updateApiTransactionState("Ошибка: отменен пользователем", apiTransaction.dateClose, apiTransaction.apiVCode);
                    //_db.setTransactionClosed(currentOrder.id, 1);

                    //_cityMobile->setStatusCanceled(currentOrder.id, "Заказ отменен пользователем", QString::number(apiTransaction.apiVCode), apiTransaction.dateOpen);
                } else if (currentOrder.status == "Completed") { //заказа завершен успешно

                }
            }
        }
        if (aOrders.object().value("nextRetryMs").isDouble()) {
            _timerCityMobileOrders.setInterval(aOrders.object().value("nextRetryMs").toInt());
        }
    }
    }
}

void MainWindow::changeEvent(QEvent *aEvent) {
    QMainWindow::changeEvent(aEvent);
    if (aEvent -> type() == QEvent::WindowStateChange) {
        if (isMinimized()) {
            this->hide();
        }
    }
}

void MainWindow::trayIconActivated(QSystemTrayIcon::ActivationReason aReason) {
    switch (aReason) {
        case QSystemTrayIcon::Trigger:
        case QSystemTrayIcon::DoubleClick:
            this->trayActionExecute();
            break;
        default:
            break;
    }
}

void MainWindow::trayActionExecute() {
    this->show();
    this->showNormal();
}

void MainWindow::setTrayIconActions() {
    // Setting actions...
    minimizeAction = new QAction("Свернуть", this);
    restoreAction =  new QAction("Восстановить", this);
    quitAction =     new QAction("Выход", this);

    // Connecting actions to slots...
    connect (minimizeAction, SIGNAL(triggered()), this, SLOT(hide()));
    connect (restoreAction,  SIGNAL(triggered()), this, SLOT(showNormal()));
    connect (quitAction,     SIGNAL(triggered()), qApp, SLOT(quit()));

    // Setting system tray's icon menu...
    trayIconMenu = new QMenu(this);
    trayIconMenu->addAction(minimizeAction);
    trayIconMenu->addAction(restoreAction);
    trayIconMenu->addAction(quitAction);
}

void MainWindow::showTrayIcon() {
    // Создаём экземпляр класса и задаём его свойства...
    trayIcon = new QSystemTrayIcon(this);
    QIcon trayImage("://images/tray.png");
    trayIcon->setIcon(trayImage);
    trayIcon->setContextMenu(trayIconMenu);

    // Подключаем обработчик клика по иконке...
    connect(trayIcon, SIGNAL(activated(QSystemTrayIcon::ActivationReason)), this, SLOT(trayIconActivated(QSystemTrayIcon::ActivationReason)));

    // Выводим значок...
    trayIcon->show();
}
#define FunctionsEnd }
