#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
: QMainWindow(parent)
, ui(new Ui::MainWindow) {
    ui->setupUi(this);

    ui->pushButton->setVisible(false);
    ui->pushButton_2->setVisible(false);
    ui->pushButton_3->setVisible(false);
    ui->pushButton_4->setVisible(false);
    ui->pushButton_5->setVisible(false);
    ui->lineEdit->setVisible(false);

    _db = QSqlDatabase::addDatabase("QODBC3");
    QStringList setting;
    if(QFile::exists("Setting.txt")){
        QFile settings("Setting.txt");
        if (settings.open(QIODevice::ReadOnly)){
            while(!settings.atEnd()){
                setting << QString::fromLocal8Bit(settings.readLine()).remove("\r\n").remove("\n");
            }
            settings.close();
        } else {
            qDebug()<<"Error: setting file is already open";
            setting << "agzs2" << "2";
        }
    } else {
        qDebug()<<"Error: setting file not found";
        setting << "agzs2" << "2";
    }
    qDebug()<<setting;
    _db.setDatabaseName(QString("DRIVER={SQL Server};"
                                "SERVER=%1;"
                                "DATABASE=agzs;"
                                "Persist Security Info=true;"
                                "uid=sa;"
                                "pwd=Gfhf743Djpbr").arg(setting[0]));
    if(_db.open()){
        qDebug()<<"db open";
        connect(&_timer, &QTimer::timeout, this, &MainWindow::mainFunction);
        _timer.start(5000);
        _yandex = new YandexAPI(_baseUrl,_db,setting[1],this);
        connect(_yandex, &YandexAPI::s_authComplete, this, [=](bool auth){
            ui->labelAuthError->setVisible(true);
            if (!auth) {
                _errorPassword++;
                if (_errorPassword < 5) {
                    ui->labelAuthError->setText(tr("Ошибка при авторизации.\nПроверьте пароль.\nОшибок: %1").arg(_errorPassword));
                } else {
                    ui->labelAuthError->setText(tr("Превышено количество ошибок.\nЗапросите пароль заново."));
                }
            } else {
                ui->labelAuthError->setText(tr("Успешно авторизовано!"));
                _timer.start(5000);
            }
        });
        connect(_yandex, &YandexAPI::s_needAuth, this, [=](bool){
            ui->labelAuthError->setVisible(true);
            ui->labelAuthError->setText(tr("Пожалуйста, \nавторизуйтесь заново."));
            _timer.stop();
            QApplication::alert(this);
        });
        connect(_yandex, &YandexAPI::s_updatePrice, this, [=](){
            updatePrice();
        });
        //ui->labelAuthError->setVisible(false);
    }
    else {
        qDebug() << "db close";
    }

}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_ButtonEnter_clicked() {
    _yandex->authorization(ui->LineEditLogin->text(),ui->LineEditPassword->text());
}

void MainWindow::on_ButtonGetPassword_clicked() {
    _yandex->getPassword(ui->LineEditLogin->text());
    _errorPassword = 0;
}

void MainWindow::on_pushButton_clicked() {
    //_yandex->updatePriceList("a92=33.33&a95=33.33&a95_premium=11.11&diesel_premium=11.11&propane=14.00");
    updatePrice();
}

void MainWindow::on_pushButton_2_clicked() {
    updateConfiguration();
//    QJsonObject configuration;
//    configuration["StationExtendedId"]="00001";

//    QJsonObject columns;

//    QJsonArray Fuels1;
//    Fuels1.append("a92");
//    Fuels1.append("a95");
//    Fuels1.append("diesel_premium");
//    QJsonObject column1;
//    column1["Fuels"]=Fuels1;
//    columns["1"]=column1;
//    QJsonArray Fuels2;
//    Fuels2.append("a92");
//    Fuels2.append("a95_premium");
//    Fuels2.append("diesel_premium");
//    QJsonObject column2;
//    column2["Fuels"]=Fuels2;
//    columns["2"]=column2;
//    QJsonArray Fuels3;
//    Fuels3.append("a92");
//    Fuels3.append("a95_premium");
//    Fuels3.append("diesel_premium");
//    QJsonObject column3;
//    column3["Fuels"]=Fuels3;
//    columns["3"]=column3;
//    configuration["Columns"]=columns;
    //_yandex->updateConfigurationAGZS(configuration);
}

void MainWindow::on_pushButton_3_clicked() {
    QTimer *timer = new QTimer();
    connect(timer, &QTimer::timeout, this, [=](){
        QApplication::alert(this);
    });
    timer->start(5000);
}

void MainWindow::mainFunction() {
    updatePrice();
    updateConfiguration();
    _yandex->checkOrders();
}

QString MainWindow::GetFullFuelName(int aFuelId) {
    QSqlQuery *q_Fuels = new QSqlQuery(_db);
    q_Fuels->exec("SELECT TOP 1 [DBVCode], [DBName] "
                  "FROM [agzs].[dbo].[FuelMassLink] "
                  "WHERE [DBVCode]="+QString::number(aFuelId));
    q_Fuels->next();
    QString fullName=q_Fuels->value(1).toString();
    delete q_Fuels;
    return fullName;
}

QString MainWindow::GetFuelAPIName(int aFuelVCode) {
    switch(aFuelVCode) {
    case 3: {
        return "a92";
        break;
    }
    case 14: {
        return "propane";
        break;
    }
    case 32: {
        return "diesel";
        break;
    }
    default: {
        return "";
    }
    }
}

void MainWindow::on_pushButton_4_clicked() {
    qDebug()<<_yandex->checkOrders();
}

void MainWindow::updatePrice() {
    //    key1=value1&key2=value2&...
        QStringList prices;
        QSqlQuery* q = new QSqlQuery(_db);
        q->exec("SELECT TOP 1 [AGZSName], [AGZS], [VCode], [Link], [CDate], [Partner], [iPartner], "
                "[diesel], [diesel_premium], [a80], [a92], [a92_premium], [a95], [a95_premium], "
                "[a98],[a98_premium], [a100], [a100_premium], [propane], [metan] "
                "FROM [agzs].[dbo].PR_AGZSPrice "
                "WHERE Link = (SELECT VCode "
                              "FROM [agzs].[dbo].PR_AGZSData "
                              "WHERE AGZS = (SELECT TOP 1 AGZS "
                                            "FROM [agzs].[dbo].[Identification])) "
                "and iPartner = 11");
        while (q->next()) {
            if(q->value(7).toInt()>0){
                prices.append("diesel="+QString::number(q->value(7).toDouble()));
            }
            if(q->value(8).toInt()>0){
                prices.append("diesel_premium="+QString::number(q->value(8).toDouble()));
            }
            if(q->value(9).toInt()>0){
                prices.append("a80="+QString::number(q->value(9).toDouble()));
            }
            if(q->value(10).toInt()>0){
                prices.append("a92="+QString::number(q->value(10).toDouble()));
            }
            if(q->value(11).toInt()>0){
                prices.append("a92_premium="+QString::number(q->value(11).toDouble()));
            }
            if(q->value(12).toInt()>0){
                prices.append("a95="+QString::number(q->value(12).toDouble()));
            }
            if(q->value(13).toInt()>0){
                prices.append("a95_premium="+QString::number(q->value(13).toDouble()));
            }
            if(q->value(14).toInt()>0){
                prices.append("a98="+QString::number(q->value(14).toDouble()));
            }
            if(q->value(15).toInt()>0){
                prices.append("a98_premium="+QString::number(q->value(15).toDouble()));
            }
            if(q->value(16).toInt()>0){
                prices.append("a100="+QString::number(q->value(16).toDouble()));
            }
            if(q->value(17).toInt()>0){
                prices.append("a100_premium="+QString::number(q->value(17).toDouble()));
            }
            if(q->value(18).toInt()>0){
                prices.append("propane="+QString::number(q->value(18).toDouble()));
            }
            if(q->value(19).toInt()>0){
                prices.append("metan="+QString::number(q->value(19).toDouble()));
            }
        }
        delete q;
        _yandex->updatePriceList(prices.join("&").replace(",","."));
}

void MainWindow::updateConfiguration() {
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
    QSqlQuery* q = new QSqlQuery(_db);
    if (q->exec("SELECT AGZSName, AGZS, VCode, Id "
                "FROM [agzs].[dbo].PR_AGZSData "
                "WHERE AGZS = (SELECT TOP 1 AGZS FROM [agzs].[dbo].[Identification])")) {
        while (q->next()) {
            QJsonObject AGZS;
            AGZS["StationExtendedId"] = q->value(3).toString();
            //Columns
            QJsonObject columns;
            QSqlQuery* q2 = new QSqlQuery(_db);
            q2->exec("SELECT DISTINCT [AGZSName], [AGZS], [VCode], [Link], [FuelVCode], [TrkVCode], [SideAdress] "
                     "FROM [agzs].[dbo].PR_AGZSColumnsData  "
                     "WHERE Link = "+QString::number(q->value(2).toInt())+
                     "ORDER BY TrkVCode, SideAdress ASC");
            int sideAdress = 0;
            int index = 1;
            QJsonArray fuels;
            q2->next();
            fuels.push_back(GetFuelAPIName(q2->value(4).toInt()));
            while (q2->next()) {
                if (sideAdress != q2->value(6).toInt()) {
                    sideAdress = q2->value(6).toInt();
                    QJsonObject fu;
                    fu["Fuels"]=fuels;
                    columns[QString::number(sideAdress)] = fu;
                    fuels = QJsonArray();
                }
                fuels.push_back(GetFuelAPIName(q2->value(4).toInt()));
            }
            QJsonObject fuel;
            fuel["Fuels"]=fuels;
            columns[QString::number(index++)] = fuel;

            delete q2;
            AGZS["Columns"]=columns;
            _yandex->updateConfigurationAGZS(AGZS);
        }
    }
    delete q;
}

void MainWindow::on_pushButton_5_clicked(){
    _yandex->setStatusCanceled(ui->lineEdit->text(),"1",ui->lineEdit->text(), QDateTime::currentDateTime());
}
