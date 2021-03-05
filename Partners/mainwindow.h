#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include "partners/yandexapi.h"
#include "partners/citymobileapi.h"
#include "systems/databasecontrol.h"
#include "systems/formsettings.h"
#include "formexitpassword.h"
#include "formchangeagzs.h"
#include <QSystemTrayIcon>
#include <QMenu>
#include <QMessageBox>
#include "systems/structs.h"
#include <QInputDialog>

QT_BEGIN_NAMESPACE
namespace Ui {
    class MainWindow;
}
QT_END_NAMESPACE

class MainWindow: public QMainWindow {
    Q_OBJECT

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
    int createTransaction(Agzs currentAgzs, Order order, Partner aPartner, int sideAdress, QDateTime now);
    void sendLiters(Partner aPartner, ApiTransaction aApiTransaction, QString aOrderId);
    bool processAcceptOrder(Order aOrder, Partner aPartner);
    bool processWaitingRefueling(Order aOrder, Partner aPartner);
    bool processFueling(Order aOrder, Partner aPartner);
    bool processExpire(Order aOrder, Partner aPartner);
    bool processStationCanceled(Order aOrder, Partner aPartner);
    bool processUserCanceled(Order aOrder, Partner aPartner);
    bool processCompleted(Order aOrder, Partner aPartner);
    bool processUnknown(Order aOrder, Partner aPartner);
    bool processClose(ApiTransaction aApiTransaction);

    void exitPassword();

private slots:
    bool checkSettings();

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
    QMenu *createTrayIconMenu();
    void showTrayIcon();

    void authYandexResult(QString aToken);
    void needAuth();
    void yandexErrorNotification();

    void globalTimerCheck();

    void on_ButtonAgzs_clicked();

private:
    Ui::MainWindow *ui;

    QString agzs_;

    QSettings reestr_;
    DataBaseControl *db_;

    YandexAPI *yandex_;
    CityMobileAPI *cityMobile_;

    int errorPassword_ = 0;
    bool isNeedAuth_ = false;

    int yandexOrdersInterval_ = 5000;
    int cityMobileOrdersInterval_ = 5000;
    int yandexDataInterval_ = 60000;
    int cityMobileDataInterval_ = 60000;

    QTimer timerGlobal_;
    QTimer timerYandexAgzsData_;
    QTimer timerYandexOrders_;
    QTimer timerYandexError_;
    QTimer timerCityMobileAgzsData_;
    QTimer timerCityMobileOrders_;

    QSystemTrayIcon *trayIcon_;
};
#endif // MAINWINDOW_H
