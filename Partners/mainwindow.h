#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <partners/yandexapi.h>
#include <partners/citymobileapi.h>
#include <systems/databasecontrol.h>
#include <systems/formsettings.h>
#include <QSystemTrayIcon>
#include <QMenu>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui {
    class MainWindow;
}
QT_END_NAMESPACE

struct Order {
    QString id;
    QDateTime dateCreate;
    QString orderType;
    double orderVolume;
    int columnId;
    double litre;
    QString status;
    QString fuelId;
    double priceFuel;
    double sum;
    QString contractId;
};

class MainWindow: public QMainWindow {
    Q_OBJECT

    enum class Partner {
        yandex = 11,
        citymobile = 10
    };

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    int FuelApiToFuelId(QString aFuelIdApi);
    QString getFuelName(int aFuelVCode);
    QString FuelIdToFuelApi(int aFuelVCode);
    void moneyData(Partner aPartner, Order aOrder, double &aRequestTotalPriceDB, double &aRequestVolumeDB, double &aRequestUnitPriceDB, double &aMoneyTakenDB, int &aFullTankDB);

    void getNozzleFuelCode(AdastTrk aTrk, QString aFuelId, int &aNozzle, int &aFuelCode);
    Transaction createEmptyTransaction();
    int createTransaction(Agzs currentAgzs, Order order, Partner aPartner, int sideAdress, QDateTime now);
    Order JsonToOrder(Partner aPartner, QJsonValue aOrder);
    void sendLiters(Partner aPartner, ApiTransaction aApiTransaction, QString aOrderId);
private slots:
    void on_ButtonEnter_clicked();
    void on_ButtonGetPassword_clicked();
    void on_ButtonCancelCitymobile_clicked();
    void on_ButtonCancelYandex_clicked();
    void on_ButtonSettings_clicked();

    void updateDataYandex();
    void getOrdersYandex();
    void updateDataCityMobile();
    void getOrdersCityMobile();

    void updatePrice(Partner p);
    void updateConfiguration(Partner p);
    void processOrders(Partner aPartner, QJsonDocument orders);

    void changeEvent(QEvent*);
    void trayIconActivated(QSystemTrayIcon::ActivationReason reason);
    void trayActionExecute();
    void setTrayIconActions();
    void showTrayIcon();

    void authYandexResult(QString aToken);
    void needAuth();
    void requestToLog(QString api, QString type, QString request, QString post, int code);
    void yandexErrorNotification();

private:
    Ui::MainWindow *ui;
    YandexAPI *_yandex;
    CityMobileAPI *_cityMobile;
    int _errorPassword = 0;
    DataBaseControl _db;
    QSettings _reestr;

    QTimer _timerYandexAgzsData;
    QTimer _timerYandexOrders;
    QTimer _timerYandexError;
    QTimer _timerCityMobileAgzsData;
    QTimer _timerCityMobileOrders;

    QMenu *trayIconMenu;
    QAction *minimizeAction;
    QAction *restoreAction;
    QAction *quitAction;
    QSystemTrayIcon *trayIcon;
};
#endif // MAINWINDOW_H
