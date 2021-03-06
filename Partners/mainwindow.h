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

enum class OrderStatus {
    unknown,
    acceptOrder,
    waitingRefueling,
    fueling,
    expire,
    stationCanceled,
    userCanceled,
    completed
};

class MainWindow: public QMainWindow {
    Q_OBJECT

    enum class Partner {
        yandex = 11,
        citymobile = 10
    };

public:
    MainWindow(QWidget *parent = nullptr);
    void closeEvent(QCloseEvent*) override;
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
    OrderStatus stringToStatus(QString aStatus);
    bool processAcceptOrder(Order aOrder, Partner aPartner);
    bool processWaitingRefueling(Order aOrder, Partner aPartner);
    bool processFueling(Order aOrder, Partner aPartner);
    bool processExpire(Order aOrder, Partner aPartner);
    bool processStationCanceled(Order aOrder, Partner aPartner);
    bool processUserCanceled(Order aOrder, Partner aPartner);
    bool processCompleted(Order aOrder, Partner aPartner);
    bool processUnknown(Order aOrder, Partner aPartner);
private slots:
    void InitTray();
    void InitTimers();
    void InitPartners();
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

    void changeEvent(QEvent*) override;
    void trayIconActivated(QSystemTrayIcon::ActivationReason reason);

    void authYandexResult(QString aToken);
    void needAuth();
    //void requestToLog(QString api, QString type, QString request, QString post, int code);
    void yandexErrorNotification();

    QString errorToString(ErrorsOrder aError);
private:
    Ui::MainWindow *ui;
    YandexAPI *yandex_;
    CityMobileAPI *cityMobile_;
    DataBaseControl db_;
    QSettings reestr_;

    QTimer timerYandexAgzsData_;
    QTimer timerYandexOrders_;
    QTimer timerYandexError_;
    QTimer timerCityMobileAgzsData_;
    QTimer timerCityMobileOrders_;
};
#endif // MAINWINDOW_H
