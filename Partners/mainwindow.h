#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QSystemTrayIcon>
#include <QMenu>
#include <QMessageBox>
#include <QInputDialog>
#include "formexitpassword.h"
#include "systems/databasecontrol.h"
#include "systems/formsettings.h"
#include "systems/structs.h"

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
    int createTransaction(Agzs currentAgzs, Order order, PartnerAPI *aPartner, int sideAdress, QDateTime now);
    double litersFromStart(ApiTransaction aApiTransaction);
    bool processAcceptOrder(Order aOrder, PartnerAPI *aPartner);
    bool processWaitingRefueling(Order aOrder, PartnerAPI *aPartner);
    bool processFueling(Order aOrder, PartnerAPI *aPartner);
    bool processExpire(Order aOrder, PartnerAPI *aPartner);
    bool processStationCanceled(Order aOrder, PartnerAPI *aPartner);
    bool processUserCanceled(Order aOrder, PartnerAPI *aPartner);
    bool processCompleted(Order aOrder, PartnerAPI *aPartner);
    bool processUnknown(Order aOrder, PartnerAPI *aPartner);
    bool processClose(ApiTransaction aApiTransaction);

    void exitPassword();

private slots:
    bool checkSettings();

    void on_ButtonEnter_clicked();
    void on_ButtonGetPassword_clicked();
    void on_ButtonCancelCitymobile_clicked();
    void on_ButtonCancelYandex_clicked();
    void on_ButtonSettings_clicked();

    void updatePrice();
    void updateConfiguration();
    void processOrders(PartnerAPI *aPartner, QJsonDocument orders);

    void changeEvent(QEvent*) override;
    void trayIconActivated(QSystemTrayIcon::ActivationReason reason);
    void trayActionExecute();
    QMenu *createTrayIconMenu();
    void showTrayIcon();

    void authYandexResult(QString aToken);
    void needAuth();
    void yandexErrorNotification();
    void soundNotification(const QString &aTitle, const QString &aMessage, const QString &aPath, const int &aVolume);

    void globalTimerCheck();

private:
    Ui::MainWindow *ui;

    const QString c_settingPath = QStringLiteral("Setting.txt");
    const QString c_version = QStringLiteral("v1.19b");

    QString agzs_;

    QSettings reestr_;
    DataBaseControl *db_;

    YandexAPI *yandex_;
    CityMobileAPI *cityMobile_;

    Price lastPriceYandex_;
    Price lastPriceCityMobile_;
    QJsonObject lastConfigurationYandex_;
    QJsonObject lastConfigurationCityMobile_;

    int errorPassword_ = 0;
    bool isNeedAuth_ = false;
    bool isNetworkError_ = false;
    bool isYandexEnabled_ = false;
    bool isCityMobileEnabled_ = false;

    QTimer timerGlobal_;
    QTimer timerYandexError_;

    QSystemTrayIcon *trayIcon_;
};
#endif // MAINWINDOW_H
