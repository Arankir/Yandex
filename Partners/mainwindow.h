#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <partners/yandexapi.h>
#include <partners/citymobileapi.h>
#include <systems/databasecontrol.h>
#include <systems/formsettings.h>

QT_BEGIN_NAMESPACE
namespace Ui {
    class MainWindow;
}
QT_END_NAMESPACE

class MainWindow: public QMainWindow {
    Q_OBJECT

    enum class Partner {
        yandex,
        citymobile
    };

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    int getFuelID(QString aFuelIdApi);
    QString getFuelName(int aFuelVCode);
    QString getFuelAPIName(int aFuelVCode);
    void moneyData(Partner aPartner, QJsonObject aRequest, double &aRequestTotalPriceDB, double &aRequestVolumeDB, double &aRequestUnitPriceDB, double &aMoneyTakenDB, int &aFullTankDB);

private slots:
    void on_ButtonEnter_clicked();
    void on_ButtonGetPassword_clicked();
    void on_pushButton_5_clicked();
    void on_ButtonSettings_clicked();

    void mainFunctionYandex();
    void updateDataCityMobile();
    void getOrdersCityMobile();

    void updatePrice(Partner p);
    void updateConfiguration(Partner p);
    void processOrders(Partner aPartner, QJsonDocument orders);

private:
    Ui::MainWindow *ui;
    YandexAPI *_yandex;
    CityMobileAPI *_cityMobile;
    int _errorPassword = 0;
    DataBaseControl _db;
    QSettings _reestr;

    QTimer _timerYandex;
    QTimer _timerCityMobileAgzsData;
    QTimer _timerCityMobileOrders;
};
#endif // MAINWINDOW_H
