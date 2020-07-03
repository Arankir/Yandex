#ifndef YANDEXAPI_H
#define YANDEXAPI_H

#include <QObject>
#include "networking/requestdata.h"
#include <QSettings>
#include <QTimer>

class YandexAPI : public QObject {
    Q_OBJECT
public:
    YandexAPI(QObject *parent=nullptr);
    void getPassword(QString login);
    void authorization(QString login, QString password);
    void updatePriceList(QString pricelist);
    void updateConfigurationAGZS(QJsonObject configuration);
    void updateConfigurationAGZS(QString configuration);
    int checkOrders();
    void receiveVolumeReport(QDateTime sdate, QDateTime edate, int page = 0);

    void getStateAGZS(QString apikey);

    void setStatusAccept(QString orderId, int vCode);
    void setStatusFueling(QString orderId, int vCode);
    void setStatusCanceled(QString orderId, QString reason, QString extendedOrderId, QDateTime extendedDate);
    void setStatusCompleted(QString orderId, double litre, QString extendedOrderId, QDateTime extendedDate);
    void setFuelNow(QString orderId, double litre);

signals:
    void s_setTimer(int mSec);
    void s_needAuth(bool);
    void s_authComplete(bool);
    void s_updatePrice();
    void s_gotOrders(QJsonDocument orders);
    void s_error(QString status, QString order, int code);

private slots:
    QNetworkRequest createRequest(QString url, QString contentType, bool auth);
    void checkAuth(RequestData*);
    void saveToken(RequestData*);

private:
    const QString c_baseUrl = "http://cabinet.tst.tanker.yandex.ru"; //https://cabinet.tanker.yandex.net/api
    RequestData *_request;
    QSettings _reestr;
    QTimer _timer;

};

#endif // YANDEXAPI_H
