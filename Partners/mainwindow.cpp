#include "mainwindow.h"
#include "ui_mainwindow.h"

const QString c_settingPath = "Setting.txt";
const double c_litersForMin = 25;

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow), reestr_("RegionPostavka", "Partners") {
    ui->setupUi(this);
    qInfo() << "STARTED";

    checkSettings();
    agzs_ = reestr_.value("currentAgzs").toString();
    while (agzs_ == QString()) {
        agzs_ = formAgzs();
        reestr_.setValue("currentAgzs", agzs_);
    }
    qInfo() << "currentAGZS =" << agzs_;
    db_ = new DataBaseControl(agzs_);

    if (!reestr_.value("isTest").toBool()) {
        ui->ButtonCancelYandex->setVisible(false);
        ui->ButtonCancelCitymobile->setVisible(false);
        ui->lineEdit->setVisible(false);
    }

    ui->LabelVersion->setText("v1.15");
    ui->ButtonSettings->setIcon(QIcon("://images/settings.png"));
    this->setWindowFlags(Qt::Window | Qt::WindowMinimizeButtonHint);

    showTrayIcon();

    reestr_.setValue("CityMobile Token", db_->getCityMobileToken());
    isCityMobileEnabled_ = reestr_.value("CityMobile Enabled", QVariant(false)).toBool();
    isYandexEnabled_ = reestr_.value("Yandex Enabled", QVariant(false)).toBool();

    yandex_ = new YandexAPI(this);
    cityMobile_ = new CityMobileAPI(this);

    connect(&timerYandexError_,         &QTimer::timeout,                       this, &MainWindow::yandexErrorNotification);
    connect(&timerGlobal_,              &QTimer::timeout,                       this, &MainWindow::globalTimerCheck);
    connect(yandex_,                    &YandexAPI::s_needAuth,                 this, &MainWindow::needAuth);
    connect(yandex_,                    &YandexAPI::s_authComplete,             this, &MainWindow::authYandexResult);
    connect(yandex_,                    &YandexAPI::s_gotOrders,                this, [=](QJsonDocument orders) {processOrders(yandex_, orders);});
    connect(cityMobile_,                &CityMobileAPI::s_gotOrders,            this, [=](QJsonDocument orders) {processOrders(cityMobile_, orders);});

    globalTimerCheck();
    timerGlobal_            .start(300000);

}

void MainWindow::closeEvent(QCloseEvent *) {
    qInfo() << "CLOSED";
}

MainWindow::~MainWindow() {
    delete ui;
}

bool MainWindow::checkSettings() {
    QStringList setting;
    if (QFile::exists(c_settingPath)) {
        QFile settings(c_settingPath);
        if (settings.open(QIODevice::ReadOnly)) {
            while(!settings.atEnd()) {
                setting << QString::fromLocal8Bit(settings.readLine()).remove("\r\n").remove("\n");
            }
            settings.close();
        } else {
            qWarning(logError) << "setting file is already open";
            return false;
        }
    } else {
        qWarning(logError) << "setting file not found";
        return false;
    }
    qDebug() << setting;
    //_reestr.setValue("agzsPriceLog", setting.size() > 3 ? setting[3] == "true" : false);
    //_reestr.setValue("agzsDataLog",  setting.size() > 2 ? setting[2] == "true" : false);
    reestr_.setValue("ordersLog",    setting.size() > 1 ? setting[1] == "true" : false);
    reestr_.setValue("isTest",       setting.size() > 0 ? setting[0] == "test" : false);
    return true;
}

void MainWindow::globalTimerCheck() {
    qInfo() << "check y =" << isYandexEnabled_ << " nAut =" << isNeedAuth_ << " c =" << isCityMobileEnabled_;
    if (isYandexEnabled_) {
        if (isNeedAuth_) {
            yandexErrorNotification();
        }
        yandex_->start();
    } else {
        yandex_->stop();
    }
    if (isCityMobileEnabled_) {
        cityMobile_->start();
    } else {
        cityMobile_->stop();
    }
    updatePrice();
    updateConfiguration();
}

#define tray {
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

QMenu *MainWindow::createTrayIconMenu() {
    // Setting actions...
    QAction *minimizeAction = new QAction("Свернуть",        this);
    QAction *restoreAction  = new QAction("Восстановить",    this);
    QAction *quitAction     = new QAction("Выход",           this);

    // Connecting actions to slots...
    connect (minimizeAction, SIGNAL(triggered()), this, SLOT(hide()));
    connect (restoreAction,  SIGNAL(triggered()), this, SLOT(showNormal()));
    connect (quitAction,     SIGNAL(triggered()), this, SLOT(exitPassword()));

    // Setting system tray's icon menu...
    QMenu *trayIconMenu = new QMenu(this);
    trayIconMenu->addAction(minimizeAction);
    trayIconMenu->addAction(restoreAction);
    trayIconMenu->addAction(quitAction);
    return trayIconMenu;
}

void MainWindow::exitPassword() {
    FormExitPassword *pass = new FormExitPassword();
    pass->show();
}

void MainWindow::showTrayIcon() {
    // Создаём экземпляр класса и задаём его свойства...
    trayIcon_ = new QSystemTrayIcon(this);
    QIcon trayImage("://images/tray.png");
    trayIcon_->setIcon(trayImage);
    trayIcon_->setContextMenu(createTrayIconMenu());

    // Подключаем обработчик клика по иконке...
    connect(trayIcon_, SIGNAL(activated(QSystemTrayIcon::ActivationReason)), this, SLOT(trayIconActivated(QSystemTrayIcon::ActivationReason)));

    // Выводим значок...
    trayIcon_->show();
}
#define trayEnd }

void MainWindow::yandexErrorNotification() {
    this->show();
    QMessageBox::warning(this, tr("Ошибка"), tr("Авторизуйтесь в Яндексе заново!"));
    QApplication::alert(this);
    //timerYandexError_.setInterval(300000);
}

void MainWindow::authYandexResult(QString aToken) {
    ui->labelAuthError->setVisible(true);
    if (aToken == "") {
        ui->labelAuthError->setText(++errorPassword_ < 5 ?
                                    tr("Ошибка при авторизации Яндекса.\nПроверьте пароль.\nОшибок: %1").arg(errorPassword_)
                                    :
                                    tr("Превышено количество ошибок.\nЗапросите пароль Яндекса заново.")
                                    );
    } else {
        db_->setYandexToken(aToken);
        reestr_.setValue("Yandex Token", aToken);
        timerYandexError_.stop();
        isNeedAuth_ = false;
        ui->labelAuthError->setText(tr("Успешно авторизовано!"));
        yandex_->updatePriceList(lastPriceYandex_.toString());
        yandex_->updateConfigurationAGZS(lastConfigurationYandex_);
        if (isYandexEnabled_) {
            yandex_->start();
        }
    }
}

void MainWindow::needAuth() {
    isNeedAuth_ = true;
    ui->labelAuthError->setVisible(true);
    ui->labelAuthError->setText(tr("Пожалуйста, авторизуйтесь в Яндексе заново."));
//    timerYandexOrders_.stop();
    //timerYandexError_.start(0);
}

#define ButtonsStart {
void MainWindow::on_ButtonEnter_clicked() {
    yandex_->authorization(ui->LineEditLogin->text(),ui->LineEditPassword->text());
}

void MainWindow::on_ButtonGetPassword_clicked() {
    yandex_->getPassword(ui->LineEditLogin->text());
    errorPassword_ = 0;
    ui->labelAuthError->setText(tr("Введите пароль."));
}

void MainWindow::on_ButtonCancelYandex_clicked() {
    yandex_->setStatusCanceled(ui->lineEdit->text(), "Ошибка 1", ui->lineEdit->text(), QDateTime::currentDateTime());
}

void MainWindow::on_ButtonCancelCitymobile_clicked() {
    cityMobile_->setStatusCanceled(ui->lineEdit->text(), "Ошибка 1", ui->lineEdit->text(), QDateTime::currentDateTime());
}

void MainWindow::on_ButtonSettings_clicked() {
    FormSettings *settings = new FormSettings();
    connect(settings, &FormSettings::s_yandexChange, this, [=](bool enabled){
        isYandexEnabled_ = enabled;
        if (isYandexEnabled_) {
            yandex_->start();
        } else {
            yandex_->stop();
        }
    });
    connect(settings, &FormSettings::s_cityMobileChange, this, [=](bool enabled){
        isCityMobileEnabled_ = enabled;
        if (isCityMobileEnabled_) {
            cityMobile_->start();
        } else {
            cityMobile_->stop();
        }
    });
    settings->show();
}

void MainWindow::on_ButtonAgzs_clicked() {
    QString password = QInputDialog::getText(this, tr("Поменять АГЗС"), tr("Пароль:"), QLineEdit::Password, "");
    if (password == "rjrjcs743") {
        QString agzs = formAgzs();
        if (agzs != "") {
            agzs_ = agzs;
            reestr_.setValue("currentAgzs", agzs_);
            qInfo() << "currentAGZS =" << agzs_;
            QMessageBox::warning(0, tr("Внимание!"), tr("АГЗС изменена, пожалуйста перезапустите приложение для применения изменений!"));
        }
    } else {
        QMessageBox::warning(0, tr("Ошибка!"), tr("Неверный пароль!"));
    }
}

QString MainWindow::formAgzs() {
    return QInputDialog::getText(this, tr("Поменять АГЗС"), tr("Введите АГЗС:"), QLineEdit::Normal, "agzs");
}
#define ButtonsEnd }

int MainWindow::createTransaction(Agzs currentAgzs, Order order, PartnerAPI *aPartner, int sideAdress, QDateTime now) {
    int transactionVCode = (db_->getLastVCode("ADAST_TRKTransaction", true) + 1) * 100 + currentAgzs.agzs;
    AdastTrk currentTrk = db_->getAgzsAdastTrk(sideAdress);
    FuelNames fuelName = db_->getFuelNames(static_cast<int>(order.fuel));

    if ((order.moneyData.requestTotalPriceDB > -1) &&
        (order.moneyData.requestVolumeDB > -1) &&
        (order.moneyData.requestUnitPriceDB > -1) &&
        (order.moneyData.moneyTakenDB > -1) &&
        (order.moneyData.fullTankDB > -1)) {
        Transaction transaction = Transaction::createTransaction(currentAgzs, transactionVCode, currentTrk,
                                                                 fuelName, sideAdress, order, now, aPartner->payWay(),
                                                                 aPartner->iPayWay(), db_->getSmena(),
                                                                 db_->getCashBoxIndex(QString::number(aPartner->iPayWay())));;

        if (db_->createTrkTransaction(transaction)) {
            return transactionVCode;
        }
    } else {
        return -2;
    }
    return -1;
}

double MainWindow::litersFromStart(ApiTransaction aApiTransaction) {
    Transaction transaction = db_->getTransaction(aApiTransaction.headVCode);
    QDateTime now = QDateTime::currentDateTime();
    QDateTime diffTime = QDateTime::fromMSecsSinceEpoch(now.toMSecsSinceEpoch() - transaction.dateOpen.toMSecsSinceEpoch()).addSecs(-20);
    double litersNow = diffTime.toSecsSinceEpoch() * (c_litersForMin / 60);
    if (litersNow < 0) {
        litersNow = 0;
    }
    if (litersNow > aApiTransaction.apiLitre) {
        litersNow = aApiTransaction.apiLitre;
    }
    return litersNow;
}

#define FunctionsStart {
void MainWindow::updatePrice() {
    Price priceYandex = db_->getPrices(QString::number(yandex_->iPayWay()));
    Price priceCityMobile = db_->getPrices(QString::number(cityMobile_->iPayWay()));
    if (priceYandex != lastPriceYandex_) {
        lastPriceYandex_ = priceYandex;
        yandex_->priceNeedUpdate();
    }
    if (priceCityMobile != lastPriceCityMobile_) {
        lastPriceCityMobile_ = priceCityMobile;
        cityMobile_->priceNeedUpdate();
    }

    if (!yandex_->isLastPriceUpdated()) {
        yandex_->updatePriceList(lastPriceYandex_.toString());
    }
    if (!cityMobile_->isLastPriceUpdated()) {
        cityMobile_->updatePriceList(lastPriceCityMobile_.toString());
    }
}

#define getData {
QJsonObject yandexData (Agzs agzs, QVector<SideFuel> fuels) {
    QJsonObject AgzsYandex;
    /*  {
        "StationExtendedId": "00001",
        "Columns": {
            1: {
                "Fuels": [
                    "a92",
                    "a95",
                    "diesel_premium"
                ]
            },
            2: {
                "Fuels": [
                    "a92",
                    "a95_premium",
                    "a98_premium",
                    "diesel_premium"
                ]
            }
        }
    }*/

    AgzsYandex["StationExtendedId"] = QString::number(agzs.agzs);
    //Columns
    QJsonObject columns;

    for (auto &side: fuels) {
        if ((side.partnerSideAdress <= 0) || (side.sideAdress <= 0)) {//без 0 колонки
            continue;
        }
        QJsonObject sideJ;
        QJsonArray fuelsJ;
        for (auto &fuel: side.fuels) {
            if (fuel > 0) {
                fuelsJ.push_back(fuelToApi(static_cast<Fuel>(fuel)));
            }
        }
        sideJ["Fuels"] = fuelsJ;
        columns[QString::number(side.partnerSideAdress)] = sideJ;
    }
    AgzsYandex["Columns"] = columns;
    return AgzsYandex;
}

QJsonObject cityMobileData (Agzs agzs, QVector<SideFuel> fuels) {
    QJsonObject AgzsCityMobile;
    /*  {
        "StationExtendedId": "1234",
        "Columns": {
            "1": {
                "Fuels": ["a92", "a95", "a95_premium", "diesel_premium"]
            },
            "2": {
                "Fuels": ["a92", "a95", "a95_premium", "a100_premium"]
            }
        },
        "Enable": true,
        "Name": "АЗС \"На Мандариновой\" №10",
        "Address": "г. Энск, ул. Мандариновая, 4",
        "Location": { "Lon": 43.5432, "Lat": 34.1234 },
        "FuelNames": [
        {
            "Fuel": "a92",
            "FuelName": "АИ-92"
        },
        {
            "Fuel": "a95",
            "FuelName": "АИ-95"
        },
        {
            "Fuel": "a95_premium",
            "FuelName": "G-95"
        },
        {
            "Fuel": "a100_premium",
            "FuelName": "G-100"
        },
        {
            "Fuel": "diesel_premium",
            "FuelName": "ДТ Опти"
        }
        ]
    }*/

    AgzsCityMobile["StationExtendedId"] = QString::number(agzs.agzs);
    AgzsCityMobile["Enable"] = true;
    AgzsCityMobile["Name"] = agzs.agzsName;
    AgzsCityMobile["Adress"] = agzs.adress;

    QJsonObject Location;
    Location["Lon"] = QString::number(agzs.loc_y).replace(",",".");
    Location["Lat"] = QString::number(agzs.loc_x).replace(",",".");
    AgzsCityMobile["Location"] = Location;
    //Columns
    QJsonObject columns;
    QJsonArray fuelNames;

    for (auto &side: fuels) {
        if ((side.partnerSideAdress <= 0) || (side.sideAdress <= 0)) {
            continue;
        }
        QJsonObject sideJ;
        QJsonArray fuelsJ;
        for (auto &fuelCode: side.fuels) {
            if (fuelCode <= 0) {
                continue;
            }
            QString fuelApi = fuelToApi(static_cast<Fuel>(fuelCode));
            fuelsJ.push_back(fuelApi);
            bool isExist = std::any_of(fuelNames.cbegin(), fuelNames.cend(),
                                             [=](const QJsonValue fuel) {return fuel.toObject().value("Fuel").toString() == fuelApi;});
            if (!isExist) {
                QJsonObject fuel;
                fuel["Fuel"] = fuelApi;
                fuel["FuelName"] = fuelToName(static_cast<Fuel>(fuelCode));
                fuelNames.append(fuel);
            }
        }
        sideJ["Fuels"] = fuelsJ;
        columns[QString::number(side.partnerSideAdress)] = sideJ;
    }
    AgzsCityMobile["Columns"] = columns;
    AgzsCityMobile["FuelNames"] = fuelNames;
    return AgzsCityMobile;
}
#define getDataEnd }

void MainWindow::updateConfiguration() {
    Agzs currentAgzs = db_->getAgzsData();
    QVector<SideFuel> fuels = db_->getFuels();
    QJsonObject agzsYandex = yandexData(currentAgzs, fuels);
    QJsonObject agzsCityMobile = cityMobileData(currentAgzs, fuels);

    if (agzsYandex != lastConfigurationYandex_) {
        lastConfigurationYandex_ = agzsYandex;
        yandex_->configurationNeedUpdate();
    }

    if (agzsCityMobile != lastConfigurationCityMobile_) {
        lastConfigurationCityMobile_ = agzsCityMobile;
        cityMobile_->configurationNeedUpdate();
    }

    if (!yandex_->isLastConfigurationUpdated()) {
        yandex_->updateConfigurationAGZS(lastConfigurationYandex_);
    }

    if (!cityMobile_->isLastConfigurationUpdated()) {
        cityMobile_->updateConfigurationAGZS(lastConfigurationCityMobile_);
    }
}

void MainWindow::processOrders(PartnerAPI *aPartner, QJsonDocument aOrders) {
    auto openedTransactions = db_->getOpenedTransactions(aPartner->iPayWay());
    for(auto order: aOrders.object().value("orders").toArray()) {
        Order currentOrder = Order::fromJson(aPartner->iPayWay(), order);
        qInfo() << "itemOrder" << currentOrder.status << currentOrder.id;
        //Найти и исключить из листа эту транзакцию
        auto iterator = std::find_if(openedTransactions.begin(),
                                     openedTransactions.end(),
                                     [=](ApiTransaction &api) {
                                         return api.id == currentOrder.id;
                                     });
        if (iterator != openedTransactions.end()) {
            openedTransactions.removeOne(*iterator);
        }

        switch (stringToStatus(currentOrder.status)) {
        case OrderStatus::acceptOrder: {
            processAcceptOrder(currentOrder, aPartner);
            break;
        }
        case OrderStatus::waitingRefueling: {
            processWaitingRefueling(currentOrder, aPartner);
            break;
        }
        case OrderStatus::fueling: {
            processFueling(currentOrder, aPartner);
            break;
        }
        case OrderStatus::expire: {
            processExpire(currentOrder, aPartner);
            break;
        }
        case OrderStatus::stationCanceled: {
            processStationCanceled(currentOrder, aPartner);
            break;
        }
        case OrderStatus::userCanceled: {
            processUserCanceled(currentOrder, aPartner);
            break;
        }
        case OrderStatus::completed: {
            processCompleted(currentOrder, aPartner);
            break;
        }
        case OrderStatus::unknown: {
            processUnknown(currentOrder, aPartner);
            break;
        }
        }
    }
    //Все оставшиеся транзакции в листе закрыть и записать в лог
    for(auto &openedTransaction: openedTransactions) {
        processClose(openedTransaction);
    }
}

#define ProcessOrders {

bool MainWindow::processAcceptOrder(Order aOrder, PartnerAPI *aPartner) {
    if (db_->isTransactionExist(aOrder.id)) {
        return false;
    }
    qInfo() << aOrder.id << "AcceptOrder";
    QDateTime now           = QDateTime::currentDateTime();
    int lastAPIVCode        = (db_->getLastVCode("PR_APITransaction", true) + 1) * 100 + db_->getCurrentAgzs();
    Agzs currentAgzs        = db_->getAgzsData();
    int sideAdress          = db_->getRealSideAddress(currentAgzs.agzs, aOrder.columnId);
    ErrorsOrder error       = db_->checkError(QString::number(sideAdress),
                                fuelToApi(aOrder.fuel),
                                static_cast<int>(aOrder.fuel),
                                QString::number(aOrder.priceFuel),
                                aPartner->iPayWay());
    int transactionVCode    = -1;

    if (error == ErrorsOrder::noError) {
        transactionVCode = createTransaction(currentAgzs, aOrder, aPartner, sideAdress, now);
    }
    while (!db_->createApiTransaction(currentAgzs.agzsName, currentAgzs.agzs, aOrder.dateCreate.addSecs(7200),
                         lastAPIVCode, aOrder.id, "", aOrder.columnId, fuelToApi(aOrder.fuel),
                         static_cast<int>(aOrder.fuel), aOrder.priceFuel, aOrder.litre,
                         aOrder.sum, aOrder.status, aOrder.contractId, aPartner->agent(),
                         errorToString(error), 0, 0, 0, now, transactionVCode));
    switch (error) {
    case ErrorsOrder::noError: {
        aPartner->setStatusAccept(aOrder.id, lastAPIVCode);
        return true;
        break;
    }
    case ErrorsOrder::trkError: {
        qWarning(logError) << "Указанная колонка не найдена" << aOrder.id;
        aPartner->setStatusCanceled(aOrder.id, "Указанная колонка не найдена.", QString::number(lastAPIVCode), now);
        return false;
        break;
    }
    case ErrorsOrder::fuelError: {
        qWarning(logError) << "Не обнаружено указанное топливо" << aOrder.id;
        aPartner->setStatusCanceled(aOrder.id, "Не обнаружено указанное топливо.", QString::number(lastAPIVCode), now);
        return false;
        break;
    }
    case ErrorsOrder::priceError: {
        qWarning(logError) << "Цена на выбранный вид топлива отличается от фактической цены" << aOrder.id;
        aPartner->setStatusCanceled(aOrder.id, "Цена на выбранный вид топлива отличается от фактической цены.", QString::number(lastAPIVCode), now);
        updatePrice();
        return false;
        break;
    }
    }
    return false;
}

bool MainWindow::processWaitingRefueling(Order aOrder, PartnerAPI *aPartner) {
    if (!db_->isTransactionExist(aOrder.id)) {
        qWarning() << "APITransaction not created";
        processAcceptOrder(aOrder, aPartner);
    }
    ApiTransaction apiTransaction = db_->getApiTransaction(aOrder.id);
    if (apiTransaction.id == "") {
        return false;
    }
    qInfo() << aOrder.id << "WaitingRefueling";
    if (apiTransaction.iState > 0) {
        db_->updateApiTransactionState(apiTransaction.localState, apiTransaction.dateClose, apiTransaction.apiVCode);
    }
    aPartner->setStatusFueling(aOrder.id, apiTransaction.apiVCode);
    return true;
}

bool MainWindow::processFueling(Order aOrder, PartnerAPI *aPartner) {
    qInfo() << aOrder.id << "Fueling";
    ApiTransaction apiTransaction = db_->getApiTransaction(aOrder.id);
    aPartner->setStatusFuelNow(aOrder.id, litersFromStart(apiTransaction));

    double amount = 0.0, volume = 0.0, price = 0.0;
    QDateTime dateOpen, dateClose;
    db_->getPayOperationData(apiTransaction.headVCode, amount, volume, price, dateOpen, dateClose);

    if((amount > 0.1) && (volume > 0.1) && (price > 0.1) && (apiTransaction.localState.toInt() < 5)) {
        db_->finalUpdateApiTransactionState("5", price, volume, amount, dateOpen, dateClose, apiTransaction.apiVCode);
        aPartner->setStatusCompleted(aOrder.id, volume, QString::number(apiTransaction.apiVCode), dateClose);
    }
    return false;
}

bool MainWindow::processExpire(Order aOrder, PartnerAPI *aPartner) {
    qInfo() << aOrder.id << "Expire";
    ApiTransaction apiTransaction = db_->getApiTransaction(aOrder.id);
    db_->updateApiTransactionState("Ошибка: 30 минут", apiTransaction.dateClose, apiTransaction.apiVCode);
    db_->setTransactionClosed(aOrder.id, 1);
    aPartner->setStatusCanceled(aOrder.id, "Истекло время ожидания", QString::number(apiTransaction.apiVCode), apiTransaction.dateOpen);
    return true;
}

bool MainWindow::processStationCanceled(Order aOrder, PartnerAPI *aPartner) {
    Q_UNUSED(aOrder);
    Q_UNUSED(aPartner);
    return false;
}

bool MainWindow::processUserCanceled(Order aOrder, PartnerAPI *aPartner) {
    Q_UNUSED(aOrder);
    Q_UNUSED(aPartner);
    return false;
}

bool MainWindow::processCompleted(Order aOrder, PartnerAPI *aPartner) {
    Q_UNUSED(aOrder);
    Q_UNUSED(aPartner);
    return false;
}

bool MainWindow::processUnknown(Order aOrder, PartnerAPI *aPartner) {
    Q_UNUSED(aOrder);
    Q_UNUSED(aPartner);
    return false;
}

bool MainWindow::processClose(ApiTransaction aApiTransaction) {
    qInfo() << aApiTransaction.id << "Closed";
    db_->updateApiTransactionState("Отменена", aApiTransaction.dateClose, aApiTransaction.apiVCode);
    return db_->setTransactionClosed(aApiTransaction.id, 1);
}

#define ProcessOrdersEnd }

#define FunctionsEnd }
