#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::on_ButtonEnter_clicked(){
    YandexAPI *request = new YandexAPI(_baseUrl);
    request->Authorization(ui->LineEditLogin->text(),ui->LineEditPassword->text());
}

void MainWindow::on_ButtonGetPassword_clicked(){
    YandexAPI *request = new YandexAPI(_baseUrl);
    request->GetPassword(ui->LineEditLogin->text());
}

void MainWindow::on_pushButton_clicked(){
    YandexAPI *request = new YandexAPI(_baseUrl);
    request->UpdatePriceList("a92=22.221&a95=44.22&a95_premium=22.44&diesel_premium=24.42");
}

void MainWindow::on_pushButton_2_clicked()
{
    YandexAPI *request = new YandexAPI(_baseUrl);
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
    QString configuration = "{\"Columns\":"
                                "{1:"
                                    "{\"Fuels\":"
                                        "[\"a92\","
                                        "\"a95\"]"
                                    "},"
                                "2:"
                                    "{\"Fuels\":"
                                        "[\"a92\","
                                        "\"a95_premium\","
                                        "\"diesel_premium\"]"
                                    "},"
                                "3:"
                                    "{\"Fuels\":"
                                        "[\"a92\","
                                        "\"diesel_premium\"]"
                                    "}"
                                "},"
                            "\"StationExtendedId\":\"00001\"}";
    request->UpdateConfigurationAGZS(configuration);
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

void MainWindow::on_pushButton_3_clicked()
{
    QTimer *timer = new QTimer();
    connect(timer,&QTimer::timeout, this, [=]{QApplication::alert(this);});
    timer->start(5000);
}
