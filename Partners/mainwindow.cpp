#include "mainwindow.h"
#include "ui_mainwindow.h"

const double c_litersForMin = 25;

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow), _reestr("RegionPostavka", "Partners") {
    ui->setupUi(this);

    if (!_reestr.value("isTest").toBool()) {
        ui->pushButton_5->setVisible(false);
        ui->lineEdit->setVisible(false);
    }

    ui->label->setTextFormat(Qt::RichText);
    ui->label->setText("<img height=25 style=\"vertical-align: top\" src=\"://images/login.png\"> Логин</a>");
    ui->label_2->setTextFormat(Qt::RichText);
    ui->label_2->setText("<img height=25 style=\"vertical-align: top\" src=\"://images/login password.png\"> Пароль</a>");
    ui->ButtonSettings->setIcon(QIcon("://images/settings.png"));

    #define yandexStart {
    connect(&_timerYandex, &QTimer::timeout, this, &MainWindow::mainFunctionYandex);
    _timerYandex.start(5000);

    _yandex = new YandexAPI(this);
    connect(_yandex, &YandexAPI::s_authComplete, this, [=](QString aToken) {
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
            ui->labelAuthError->setText(tr("Успешно авторизовано!"));
            _timerYandex.start(5000);
        }
    });

    connect(_yandex, &YandexAPI::s_needAuth, this, [=](bool) {
        ui->labelAuthError->setVisible(true);
        ui->labelAuthError->setText(tr("Пожалуйста, авторизуйтесь\nв Яндексе заново."));
        _timerYandex.stop();
        QApplication::alert(this);
    });

    connect(_yandex, &YandexAPI::s_updatePrice, this, [=]() {
        updatePrice(Partner::yandex);
    });

    connect(_yandex, &YandexAPI::s_gotOrders, this, [=](QJsonDocument orders) {
        processOrders(Partner::yandex, orders);
    });

    connect(_yandex, &YandexAPI::s_request, this, [=](QString request) {
        if (request.indexOf("price") > 0) {
            if (_reestr.value("agzsPriceLog") != false) {
                _db.logAppend(request);
            }
        } else if(request.indexOf("station") > 0) {
            if (_reestr.value("agzsDataLog") != false) {
                _db.logAppend(request);
            }
        } else if (request.indexOf("items") > 0) {
            if (_reestr.value("ordersLog") != false) {
                _db.logAppend(request);
            }
        } else {
            _db.logAppend(request);
        }
    });
    #define yandexEnd }
    #define cityMobileStart {
    connect(&_timerCityMobileAgzsData, &QTimer::timeout, this, &MainWindow::updateDataCityMobile);
    _timerCityMobileAgzsData.start(60000);

    connect(&_timerCityMobileOrders, &QTimer::timeout, this, &MainWindow::getOrdersCityMobile);
    _timerCityMobileOrders.start(5000);

    _cityMobile = new CityMobileAPI(this);

    connect(_cityMobile, &CityMobileAPI::s_gotOrders, this, [=](QJsonDocument orders) {
        processOrders(Partner::citymobile, orders);
    });
    #define cityMobileEnd }

}

MainWindow::~MainWindow() {
    delete ui;
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

void MainWindow::on_pushButton_5_clicked(){
    //_yandex->setStatusCanceled(ui->lineEdit->text(),"1",ui->lineEdit->text(), QDateTime::currentDateTime());
    _cityMobile->setStatusCanceled(ui->lineEdit->text(),"Ошибка 3",ui->lineEdit->text(), QDateTime::currentDateTime());
}

void MainWindow::on_ButtonSettings_clicked() {
    FormSettings *settings = new FormSettings();
    settings->show();
}
#define ButtonsEnd }

#define FuelStart {
int MainWindow::getFuelID(QString aFuelIdApi) {
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

QString MainWindow::getFuelAPIName(int aFuelVCode) {
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

void MainWindow::mainFunctionYandex() {
    if (_reestr.value("Yandex Enabled", QVariant(false)).toBool()) {
        updatePrice(Partner::yandex);
        updateConfiguration(Partner::yandex);
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

void MainWindow::moneyData(Partner aPartner, QJsonObject aRequest, double &aRequestTotalPriceDB, double &aRequestVolumeDB, double &aRequestUnitPriceDB, double &aMoneyTakenDB, int &aFullTankDB) {
    switch (aPartner) {
    case Partner::yandex: {
        if (aRequest.value("orderType").toString() == "Money") {
            aRequestTotalPriceDB = aRequest.value("orderVolume").toDouble();
            aRequestUnitPriceDB = aRequest.value("priceFuel").toDouble();
            int temp = (aRequestTotalPriceDB / aRequestUnitPriceDB) * 100;
            aRequestVolumeDB = temp / 100;
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
            int temp = (aRequestTotalPriceDB / aRequestUnitPriceDB) * 100;
            aRequestVolumeDB = temp / 100;
            aMoneyTakenDB = aRequest.value("orderVolume").toDouble();
            aFullTankDB = 1;
        }
        break;
    }
    case Partner::citymobile: {
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
            aMoneyTakenDB = aRequest.value("orderVolume").toDouble();
            aFullTankDB = 1;
        }
        break;
    }
    }
}

#define FunctionsStart {
void MainWindow::updatePrice(Partner aPartner) {
    switch (aPartner) {
    case Partner::yandex: {
        //    key1=value1&key2=value2&...
        QStringList prices;
        QString agzsName, partner;
        int agzs, vCode, link;
        QDateTime cDate;
        double diesel = 0, diesel_premium = 0, a80 = 0, a92 = 0, a92_premium = 0, a95 = 0, a95_premium = 0, a98 = 0, a98_premium = 0, a100 = 0, a100_premium = 0, propane = 0, metan = 0;
        _db.getPrices("11", agzsName, agzs, vCode, link, cDate, partner, diesel, diesel_premium, a80, a92, a92_premium, a95, a95_premium, a98,a98_premium, a100, a100_premium, propane, metan);
        if(diesel>0.1f){
            prices.append("diesel="+QString::number(diesel));
        }
        if(diesel_premium>0.1f){
            prices.append("diesel_premium="+QString::number(diesel_premium));
        }
        if(a80>0.1f){
            prices.append("a80="+QString::number(a80));
        }
        if(a92>0.1f){
            prices.append("a92="+QString::number(a92));
        }
        if(a92_premium>0.1f){
            prices.append("a92_premium="+QString::number(a92_premium));
        }
        if(a95>0.1f){
            prices.append("a95="+QString::number(a95));
        }
        if(a95_premium>0.1f){
            prices.append("a95_premium="+QString::number(a95_premium));
        }
        if(a98>0.1f){
            prices.append("a98="+QString::number(a98));
        }
        if(a98_premium>0.1f){
            prices.append("a98_premium="+QString::number(a98_premium));
        }
        if(a100>0.1f){
            prices.append("a100="+QString::number(a100));
        }
        if(a100_premium>0.1f){
            prices.append("a100_premium="+QString::number(a100_premium));
        }
        if(propane>0.1f){
            prices.append("propane="+QString::number(propane));
        }
        if(metan>0.1f){
            prices.append("metan="+QString::number(metan));
        }
        _yandex->updatePriceList(prices.join("&").replace(",","."));
        break;
    }
    case Partner::citymobile: {
        //    key1=value1&key2=value2&...
        QStringList prices;
        QString agzsName, partner;
        int agzs, vCode, link;
        QDateTime cDate;
        double diesel = 0, diesel_premium = 0, a80 = 0, a92 = 0, a92_premium = 0, a95 = 0, a95_premium = 0, a98 = 0, a98_premium = 0, a100 = 0, a100_premium = 0, propane = 0, metan = 0;
        _db.getPrices("10", agzsName, agzs, vCode, link, cDate, partner, diesel, diesel_premium, a80, a92, a92_premium, a95, a95_premium, a98,a98_premium, a100, a100_premium, propane, metan);
        if(diesel>0.1f){
            prices.append("diesel="+QString::number(diesel));
        }
        if(diesel_premium>0.1f){
            prices.append("diesel_premium="+QString::number(diesel_premium));
        }
        if(a80>0.1f){
            prices.append("a80="+QString::number(a80));
        }
        if(a92>0.1f){
            prices.append("a92="+QString::number(a92));
        }
        if(a92_premium>0.1f){
            prices.append("a92_premium="+QString::number(a92_premium));
        }
        if(a95>0.1f){
            prices.append("a95="+QString::number(a95));
        }
        if(a95_premium>0.1f){
            prices.append("a95_premium="+QString::number(a95_premium));
        }
        if(a98>0.1f){
            prices.append("a98="+QString::number(a98));
        }
        if(a98_premium>0.1f){
            prices.append("a98_premium="+QString::number(a98_premium));
        }
        if(a100>0.1f){
            prices.append("a100="+QString::number(a100));
        }
        if(a100_premium>0.1f){
            prices.append("a100_premium="+QString::number(a100_premium));
        }
        if(propane>0.1f){
            prices.append("propane="+QString::number(propane));
        }
        if(metan>0.1f){
                prices.append("metan="+QString::number(metan));
            }
        _cityMobile->updatePriceList(prices.join("&").replace(",","."));
        break;
    }
    }
}

void MainWindow::updateConfiguration(Partner aPartner) {
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
        QString agzsNameD, idD, adress;
        int agzsD, vCodeD, columnCount;
        QDateTime cDateD;
        double loc_x, loc_y;
        _db.getAgzsData(agzsNameD, agzsD, cDateD, vCodeD, idD, adress, loc_x, loc_y, columnCount);

        QJsonObject AGZS;
        AGZS["StationExtendedId"] = QString::number(agzsD);
        //Columns
        QJsonObject columns;

        QVector<QVector<int>> fuels;
        _db.getFuels(fuels);
        for (auto &side: fuels) {
            QJsonObject sideJ;
            QJsonArray fuelsJ;
            for (int i = 1; i < side.size(); i++) {
                if (side[i] > 0) {
                    fuelsJ.push_back(getFuelAPIName(side[i]));
                }
            }
            sideJ["Fuels"] = fuelsJ;
            columns[QString::number(side[0])] = sideJ;
        }
        AGZS["Columns"]=columns;

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
        QString agzsNameD, idD, adress;
        int agzsD, vCodeD, columnCount;
        QDateTime cDateD;
        double lat, lon;
        _db.getAgzsData(agzsNameD, agzsD, cDateD, vCodeD, idD, adress, lat, lon, columnCount);

        QJsonObject AGZS;
        AGZS["StationExtendedId"] = QString::number(agzsD);
        AGZS["Enable"] = true;
        AGZS["Name"] = agzsNameD;
        AGZS["Adress"] = adress;

        QJsonObject Location;
        Location["Lon"] = QString::number(lon).replace(",",".");
        Location["Lat"] = QString::number(lat).replace(",",".");
        AGZS["Location"] = Location;
        //Columns
        QJsonObject columns;
        QJsonArray fuelNames;

        QVector<QVector<int>> fuels;
        _db.getFuels(fuels);
        for (auto &side: fuels) {
            QJsonObject sideJ;
            QJsonArray fuelsJ;
            for (int i = 1; i < side.size(); i++) {
                if (side[i] > 0) {
                    fuelsJ.push_back(getFuelAPIName(side[i]));

                    bool insert = true;
                    for (auto fuel: fuelNames) {
                        if (fuel.toObject().value("Fuel") == getFuelAPIName(side[i])) {
                            insert = false;
                            break;
                        }
                    }
                    if (insert) {
                        QJsonObject fuel;
                        fuel["Fuel"] = getFuelAPIName(side[i]);
                        fuel["FuelName"] = getFuelName(side[i]);
                        fuelNames.append(std::move(fuel));
                    }
                }
            }
            sideJ["Fuels"] = fuelsJ;
            columns[QString::number(side[0])] = sideJ;
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
            if (order.toObject().value("status").toString() == "AcceptOrder") { //заказ ожидает подтверждения от АСУ АЗС
                QDateTime now = QDateTime::currentDateTime();
                int lastAPIVCode = (_db.getLastVCode("PR_APITransaction", true) + 1) * 100 + _db.getCurrentAgzs();
                int error = _db.checkError(QString::number(order.toObject().value("columnId").toInt()),
                                       order.toObject().value("fuelId").toString(),
                                       getFuelID(order.toObject().value("fuelId").toString()),
                                       QString::number(order.toObject().value("priceFuel").toDouble()),
                                       11);

                QString agzsName, id, adress;
                int agzs, vCode, columnCount;
                QDateTime cDate;
                double loc_x, loc_y;
                _db.getAgzsData(agzsName, agzs, cDate, vCode, id, adress, loc_x, loc_y, columnCount);

                int transactionVCode = 0;
                switch (error) {
                case 0: {
                    transactionVCode = (_db.getLastVCode("ADAST_TRKTransaction", true) + 1) * 100 + agzs;

                    double requestTotalPriceDB = -1, requestVolumeDB = -1, requestUnitPriceDB = -1, moneyTakenDB = -1;
                    int fullTankDB = -1;
                    moneyData(Partner::yandex, order.toObject(), requestTotalPriceDB, requestVolumeDB, requestUnitPriceDB, moneyTakenDB, fullTankDB);

                    int fuelCode1 = 0, fuelCode2 = 0, fuelCode3 = 0, fuelCode4 = 0, fuelCode5 = 0, trkVCode = 0, pumpPlace = 0, fuel1 = 0, fuel2 = 0, fuel3 = 0, fuel4 = 0, fuel5 = 0;
                    QString deviceName, serial, description, side;
                    _db.getAgzsAdastTrk(order.toObject().value("columnId").toInt(), side, deviceName, serial, description, fuelCode1, fuelCode2, fuelCode3, fuelCode4, fuelCode5, trkVCode,
                                        pumpPlace, fuel1, fuel2, fuel3, fuel4, fuel5);

                    QString fuelName, fuelShortName;
                    _db.getFuelNames(getFuelID(order.toObject().value("fuelId").toString()), fuelName, fuelShortName);

                    int nozzle = 0;
                    int trkFuelCode = 0;
                    if (getFuelID(order.toObject().value("fuelId").toString()) == fuel1) {
                        nozzle = 1;
                        trkFuelCode = std::move(fuelCode1);
                    } else if (getFuelID(order.toObject().value("fuelId").toString()) == fuel2) {
                        nozzle = 2;
                        trkFuelCode = std::move(fuelCode2);
                    } else if (getFuelID(order.toObject().value("fuelId").toString()) == fuel3) {
                        nozzle = 3;
                        trkFuelCode = std::move(fuelCode3);
                    } else if (getFuelID(order.toObject().value("fuelId").toString()) == fuel4) {
                        nozzle = 4;
                        trkFuelCode = std::move(fuelCode4);
                    } else if (getFuelID(order.toObject().value("fuelId").toString()) == fuel5) {
                        nozzle = 5;
                        trkFuelCode = std::move(fuelCode5);
                    }

                    _db.createTrkTransaction(agzsName, transactionVCode, "ADAST", deviceName, serial, fuelName, fuelShortName, side,
                                      order.toObject().value("columnId").toInt(), nozzle, trkFuelCode, "", 0, 0, 0, requestTotalPriceDB,
                                      requestVolumeDB, requestUnitPriceDB, "V", "Завершение выдачи", 8, "P", 0, 0, 0, 0, 0, 0, "Выдача завершена: 1", now, now,
                                      -100, 0, "ЯНДЕКС", 0, "SERVER", now, "SERVER", now, "SERVER", "SERVER", transactionVCode, 0, 0, 0, 0, _db.getSmena(), trkVCode,
                                      _db.getCashBoxIndex("11"), pumpPlace, moneyTakenDB, 11, 0, 0, fullTankDB, agzs,
                                      getFuelID(order.toObject().value("fuelId").toString()), 0);
                    break;
                }
                case 1: {
                    _db.logAppend("Error 1");
                    _yandex->setStatusCanceled(order.toObject().value("id").toString(), "Указанная колонка не найдена.", QString::number(lastAPIVCode), now);
                    break;
                }
                case 2: {
                    _db.logAppend("Error 2");
                    _yandex->setStatusCanceled(order.toObject().value("id").toString(), "Не обнаружено указанное топливо.", QString::number(lastAPIVCode), now);
                    break;
                }
                case 3: {
                    _db.logAppend("Error 3");
                    _yandex->setStatusCanceled(order.toObject().value("id").toString(), "Цена на выбранный вид топлива отличается от фактической цены.", QString::number(lastAPIVCode), now);
                    break;
                }
                }
                _db.createApiTransaction(agzsName, agzs, QDateTime::fromString(order.toObject().value("dateCreate").toString().left(23), "yyyy-MM-ddThh:mm:ss.zzz"),
                                     lastAPIVCode, order.toObject().value("id").toString(), "", order.toObject().value("columnId").toInt(), order.toObject().value("fuelId").toString(),
                                     getFuelID(order.toObject().value("fuelId").toString()), order.toObject().value("priceFuel").toDouble(), order.toObject().value("litre").toDouble(),
                                     order.toObject().value("sum").toDouble(), order.toObject().value("status").toString(), order.toObject().value("contractId").toString(), "Yandex",
                                     error != 0 ? "Error: " + QString::number(error) : "0", 0, 0, 0, now, transactionVCode);
                _yandex->setStatusAccept(order.toObject().value("id").toString(), lastAPIVCode);
            } else if (order.toObject().value("status").toString() == "WaitingRefueling") { //ожидаем включения налива на ТРК
                QString localState = "0";
                int apiVCode = 0, headVCode = 0, iState = 0;
                QDateTime dateOpen, dateClose;
                double apiLitre = 0.0f;
                _db.getApiTransactionState(order.toObject().value("id").toString(), localState, apiLitre, apiVCode, headVCode, iState, dateOpen, dateClose);
                if (QString::number(iState) != localState) {
                    if (iState > 0) {
                        _db.updateApiTransactionState(localState, dateClose, apiVCode);
                    }
                    _yandex->setStatusFueling(order.toObject().value("id").toString(), apiVCode);
                }
            } else if (order.toObject().value("status").toString() == "Fueling") { //идет налив
                QString localState;
                int apiVCode = 0, headVCode = 0, iState = 0;
                QDateTime dateOpen, dateClose;
                double apiLitre = 0.0f;
                _db.getApiTransactionState(order.toObject().value("id").toString(), localState, apiLitre, apiVCode, headVCode, iState, dateOpen, dateClose);

                double requestTotalPrice = 0.0f, requestVolume = 0.0f, requestUnitPrice = 0.0f, trkTotalPrice = 0.0f, trkVolume = 0.0f, trkUnitPrice = 0.0f;
                QDateTime transactionDateOpen, transactionDateClose;
                _db.getTransactionData(headVCode, requestTotalPrice, requestVolume, requestUnitPrice, trkTotalPrice, trkVolume, trkUnitPrice, transactionDateOpen, transactionDateClose);

                QDateTime now = QDateTime::currentDateTime();
                QDateTime diffTime = QDateTime::fromMSecsSinceEpoch(now.toMSecsSinceEpoch() - transactionDateOpen.toMSecsSinceEpoch());
                diffTime = diffTime.addSecs(-20);

                double litersNow = diffTime.toSecsSinceEpoch() * (c_litersForMin / 60);
                if ((litersNow > 0) && (litersNow < apiLitre)) {
                    _yandex->setFuelNow(order.toObject().value("id").toString(), litersNow);
                }

                if (QString::number(iState) != localState) {
                    switch (iState) {
                    case 1 ... 4: {//Цена установлена
                        _db.updateApiTransactionState(localState, dateClose, apiVCode);
                        break;
                    }
                    case 5 ... 8 :{//Выдано //Подтверждение   Завершение выдачи //Обновление счетчиков //Завершение выдачи
                        if (localState != 5) {
                            double amount = 0.0f, volume = 0.0f, price = 0.0f;
                            _db.getPayOperationLiters(headVCode, amount, volume, price);

                            if((amount > 0.1) && (volume > 0.1) && (price > 0.1)){
                                _db.finalUpdateApiTransactionState("5", price, volume, amount, dateOpen, dateClose, apiVCode);
                                _yandex->setStatusCompleted(order.toObject().value("id").toString(), volume, QString::number(apiVCode), dateClose);
                            }
                        }
                        break;
                    }
                    default:{

                    }
                    }
                }
            } else if (order.toObject().value("status").toString()=="Expire") { //статус от АЗС не поступил в течение 30 минут
                QString localState;
                int apiVCode = 0, headVCode = 0, iState = 0;
                QDateTime dateOpen, dateClose;
                double apiLitre = 0.0f;
                _db.getApiTransactionState(order.toObject().value("id").toString(), localState, apiLitre, apiVCode, headVCode, iState, dateOpen, dateClose);

                _db.updateApiTransactionState("Ошибка: 30 минут", dateClose, apiVCode);

                _db.setTransactionClosed(order.toObject().value("id").toString(), 1);

                _yandex->setStatusCanceled(order.toObject().value("id").toString(), "Истекло время ожидания", QString::number(apiVCode), dateOpen);
            }
        }
        if (aOrders.object().value("nextRetryMs").isDouble()) {
            _timerYandex.setInterval(aOrders.object().value("nextRetryMs").toInt());
        }
        break;
    }
    case Partner::citymobile: {
        //AcceptOrder, Expire, Completed, StationCanceled, UserCanceled, WaitingRefueling, Fueling
        for(auto order: aOrders.object().value("orders").toArray()) {
            if (order.toObject().value("status").toString() == "AcceptOrder") { //заказ создан, полностью оплачен и ожидает подтверждения от АСУ АЗС
                //            {
                //            "Id": "088ccc98-73e3-4b4a-aaa9-79dddd02720a",
                //            "DateCreate" :  "2019-11-20T17:28:33.994Z",
                //            "OrderType":  "Litre",
                //            "OrderVolume": "10",
                //            "StationId":  "1234",
                //            "StationExtendedId":  "1234",
                //            "ColumnId":  "1",
                //            "FuelId":  "a92",
                //            "PriceFuel":  "42.50",
                //            "Litre":  "10",
                //            "Sum":  "425.00",
                //            "Status":  "OrderCreated",
                //            "ContractId":  "32135"
                //            }
                QDateTime now = QDateTime::currentDateTime();
                int lastAPIVCode = (_db.getLastVCode("PR_APITransaction", true) + 1) * 100 + _db.getCurrentAgzs();
                int error = _db.checkError(QString::number(order.toObject().value("columnId").toInt()),
                                       order.toObject().value("fuelId").toString(),
                                       getFuelID(order.toObject().value("fuelId").toString()),
                                       QString::number(order.toObject().value("priceFuel").toDouble()),
                                       10);

                QString agzsName, id, adress;
                int agzs, vCode, columnCount;
                QDateTime cDate;
                double loc_x, loc_y;
                _db.getAgzsData(agzsName, agzs, cDate, vCode, id, adress, loc_x, loc_y, columnCount);

                int transactionVCode = 0;
                switch (error) {
                case 0: {
                    double requestTotalPriceDB = -1, requestVolumeDB = -1, requestUnitPriceDB = -1, moneyTakenDB = -1;
                    int fullTankDB = -1;
                    moneyData(Partner::citymobile, order.toObject(), requestTotalPriceDB, requestVolumeDB, requestUnitPriceDB, moneyTakenDB, fullTankDB);

                    int fuelCode1 = 0, fuelCode2 = 0, fuelCode3 = 0, fuelCode4 = 0, fuelCode5 = 0, trkVCode = 0, pumpPlace = 0, fuel1 = 0, fuel2 = 0, fuel3 = 0, fuel4 = 0, fuel5 = 0;
                    QString deviceName, serial, description, side;
                    _db.getAgzsAdastTrk(order.toObject().value("columnId").toInt(), side, deviceName, serial, description, fuelCode1, fuelCode2, fuelCode3, fuelCode4, fuelCode5, trkVCode,
                                        pumpPlace, fuel1, fuel2, fuel3, fuel4, fuel5);

                    QString fuelName, fuelShortName;
                    _db.getFuelNames(getFuelID(order.toObject().value("fuelId").toString()), fuelName, fuelShortName);

                    int nozzle = 0;
                    int trkFuelCode = 0;
                    if (getFuelID(order.toObject().value("fuelId").toString()) == fuel1) {
                        nozzle = 1;
                        trkFuelCode = std::move(fuelCode1);
                    } else if (getFuelID(order.toObject().value("fuelId").toString()) == fuel2) {
                        nozzle = 2;
                        trkFuelCode = std::move(fuelCode2);
                    } else if (getFuelID(order.toObject().value("fuelId").toString()) == fuel3) {
                        nozzle = 3;
                        trkFuelCode = std::move(fuelCode3);
                    } else if (getFuelID(order.toObject().value("fuelId").toString()) == fuel4) {
                        nozzle = 4;
                        trkFuelCode = std::move(fuelCode4);
                    } else if (getFuelID(order.toObject().value("fuelId").toString()) == fuel5) {
                        nozzle = 5;
                        trkFuelCode = std::move(fuelCode5);
                    }
                    if ((requestTotalPriceDB > -1) && (requestVolumeDB > -1) && (requestUnitPriceDB > -1) && (moneyTakenDB > -1) && (fullTankDB > -1)) {
                        transactionVCode = (_db.getLastVCode("ADAST_TRKTransaction", true) + 1) * 100 + agzs;

                        _db.createTrkTransaction(agzsName, transactionVCode, "ADAST", deviceName, serial, fuelName, fuelShortName, side,
                                          order.toObject().value("columnId").toInt(), nozzle, trkFuelCode, "", 0, 0, 0, requestTotalPriceDB,
                                          requestVolumeDB, requestUnitPriceDB, "V", "Завершение выдачи", 8, "P", 0, 0, 0, 0, 0, 0, "Выдача завершена: 1", now, now,
                                          -100, 0, "СИТИМОБИЛ", 0, "SERVER", now, "SERVER", now, "SERVER", "SERVER", transactionVCode, 0, 0, 0, 0, _db.getSmena(), trkVCode,
                                          _db.getCashBoxIndex("10"), pumpPlace, moneyTakenDB, 10, 0, 0, fullTankDB, agzs,
                                          getFuelID(order.toObject().value("fuelId").toString()), 0);
                    } else {
                        _cityMobile->setStatusCanceled(order.toObject().value("id").toString(), "Указанная колонка не найдена.", QString::number(lastAPIVCode), now);
                    }
                    break;
                }
                case 1: {
                    _cityMobile->setStatusCanceled(order.toObject().value("id").toString(), "Неизвестная ошибка.", QString::number(lastAPIVCode), now);
                    break;
                }
                case 2: {
                    _cityMobile->setStatusCanceled(order.toObject().value("id").toString(), "Не обнаружено указанное топливо.", QString::number(lastAPIVCode), now);
                    break;
                }
                case 3: {
                    _cityMobile->setStatusCanceled(order.toObject().value("id").toString(), "Цена на выбранный вид топлива отличается от фактической цены.", QString::number(lastAPIVCode), now);
                    break;
                }
                }
                _db.createApiTransaction(agzsName, agzs, QDateTime::fromString(order.toObject().value("dateCreate").toString().left(23), "yyyy-MM-ddThh:mm:ss.zzz"),
                                     lastAPIVCode, order.toObject().value("id").toString(), "", order.toObject().value("columnId").toInt(), order.toObject().value("fuelId").toString(),
                                     getFuelID(order.toObject().value("fuelId").toString()), order.toObject().value("priceFuel").toDouble(), order.toObject().value("litre").toDouble(),
                                     order.toObject().value("sum").toDouble(), order.toObject().value("status").toString(), order.toObject().value("contractId").toString(), "CityMobile",
                                     error != 0 ? "Error: " + QString::number(error) : "0", 0, 0, 0, now, transactionVCode);
                _cityMobile->setStatusAccept(order.toObject().value("id").toString(), lastAPIVCode);
            } else if (order.toObject().value("status").toString() == "WaitingRefueling") { //ожидание включения налива на ТРК
                QString localState = "0";
                int apiVCode = 0, headVCode = 0, iState = 0;
                QDateTime dateOpen, dateClose;
                double apiLitre = 0.0f;
                _db.getApiTransactionState(order.toObject().value("id").toString(), localState, apiLitre, apiVCode, headVCode, iState, dateOpen, dateClose);

    //TODO поздно срабатывает
                if (QString::number(iState) != localState) {
                    if (iState > 0) {
                        _db.updateApiTransactionState(localState, dateClose, apiVCode);
                    }
                    _cityMobile->setStatusFueling(order.toObject().value("id").toString(), apiVCode);
                }
            } else if (order.toObject().value("status").toString() == "Fueling") { //идет налив
                QString localState;
                int apiVCode = 0, headVCode = 0, iState = 0;
                QDateTime dateOpen, dateClose;
                double apiLitre = 0.0f;
                _db.getApiTransactionState(order.toObject().value("id").toString(), localState, apiLitre, apiVCode, headVCode, iState, dateOpen, dateClose);

                double requestTotalPrice = 0.0f, requestVolume = 0.0f, requestUnitPrice = 0.0f, trkTotalPrice = 0.0f, trkVolume = 0.0f, trkUnitPrice = 0.0f;
                QDateTime transactionDateOpen, transactionDateClose;
                _db.getTransactionData(headVCode, requestTotalPrice, requestVolume, requestUnitPrice, trkTotalPrice, trkVolume, trkUnitPrice, transactionDateOpen, transactionDateClose);

                QDateTime now = QDateTime::currentDateTime();
                QDateTime diffTime = QDateTime::fromMSecsSinceEpoch(now.toMSecsSinceEpoch() - transactionDateOpen.toMSecsSinceEpoch());
                diffTime = diffTime.addSecs(-20);

                double litersNow = diffTime.toSecsSinceEpoch() * (c_litersForMin / 60);
                if ((litersNow > 0) && (litersNow < apiLitre)) {
                    _cityMobile->setStatusFuelNow(order.toObject().value("id").toString(), litersNow);
                }

                if (QString::number(iState) != localState) {
                    switch (iState) {
                    case 1 ... 4: {//Цена установлена
                        _db.updateApiTransactionState(localState, dateClose, apiVCode);
                        break;
                    }
                    case 5 ... 8 :{//Выдано //Подтверждение   Завершение выдачи //Обновление счетчиков //Завершение выдачи
                        if (localState != 5) {
                            double amount = 0.0f, volume = 0.0f, price = 0.0f;
                            _db.getPayOperationLiters(headVCode, amount, volume, price);

                            if((amount > 0.1) && (volume > 0.1) && (price > 0.1)){
                                _db.finalUpdateApiTransactionState("5", price, volume, amount, dateOpen, dateClose, apiVCode);
                                _cityMobile->setStatusCompleted(order.toObject().value("id").toString(), volume, QString::number(apiVCode), dateClose);
                            }
                        }
                        break;
                    }
                    default:{

                    }
                    }
                }
            } else if (order.toObject().value("status").toString() == "Expire") { //статус от АЗС не поступил в течение 30 минут
                QString localState;
                int apiVCode = 0, headVCode = 0, iState = 0;
                QDateTime dateOpen, dateClose;
                double apiLitre = 0.0f;
                _db.getApiTransactionState(order.toObject().value("id").toString(), localState, apiLitre, apiVCode, headVCode, iState, dateOpen, dateClose);

                _db.updateApiTransactionState("Ошибка: 30 минут", dateClose, apiVCode);

                _db.setTransactionClosed(order.toObject().value("id").toString(), 1);

                _cityMobile->setStatusCanceled(order.toObject().value("id").toString(), "Истекло время ожидания", QString::number(apiVCode), dateOpen);
            } else if (order.toObject().value("status").toString() == "StationCanceled") { //заказ отменен оператором АЗС или же интегрируемой системой

            } else if (order.toObject().value("status").toString() == "UserCanceled") { //заказ отменен пользователем
                QString localState;
                int apiVCode = 0, headVCode = 0, iState = 0;
                QDateTime dateOpen, dateClose;
                double apiLitre = 0.0f;
                _db.getApiTransactionState(order.toObject().value("id").toString(), localState, apiLitre, apiVCode, headVCode, iState, dateOpen, dateClose);

                _db.updateApiTransactionState("Ошибка: отменен пользователем", dateClose, apiVCode);

                _db.setTransactionClosed(order.toObject().value("id").toString(), 1);

                _cityMobile->setStatusCanceled(order.toObject().value("id").toString(), "Заказ отменен пользователем", QString::number(apiVCode), dateOpen);
            } else if (order.toObject().value("status").toString() == "Completed") { //заказа завершен успешно

            }
        }
        if (aOrders.object().value("nextRetryMs").isDouble())
            _timerCityMobileOrders.setInterval(aOrders.object().value("nextRetryMs").toInt());
    }
    }
}
#define FunctionsEnd }
