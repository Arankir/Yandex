#ifndef YANDEXAPI_H
#define YANDEXAPI_H

#include <QObject>
#include <QTimer>
#include <chrono>
#include <thread>
#include "partners/partnerapi.h"

const int c_yandexIPayWay = 11;

class YandexAPI : public PartnerAPI {
    Q_OBJECT
public:
    int iPayWay() override {return c_yandexIPayWay;}
    QString payWay() override {return "ЯНДЕКС";}
    QString agent() override {return "Yandex";}
    QString baseUrl() override;

    YandexAPI(QObject *parent = nullptr);
    ~YandexAPI();
    void getPassword(QString login);
    void authorization(QString login, QString password);
    void receiveVolumeReport(QDateTime sdate, QDateTime edate, int page = 0);
    void getStateAGZS(QString apikey);

    void updatePriceList(QString pricelist) override;
    void updateConfigurationAGZS(QJsonObject configuration) override;
    int checkOrders() override;

    void setStatusAccept(QString orderId, int vCode) override;
    void setStatusFueling(QString orderId, int vCode) override;
    void setStatusCanceled(QString orderId, QString reason, QString extendedOrderId, QDateTime extendedDate) override;
    void setStatusCompleted(QString orderId, double litre, QString extendedOrderId, QDateTime extendedDate) override;
    void setStatusFuelNow(QString orderId, double litre) override;

signals:
    void s_needAuth(bool);
    void s_authComplete(QString token);

private slots:
    QNetworkRequest createNetworkRequest(QUrl url, QString contentType = "application/x-www-form-urlencoded", bool auth = true);
    void saveToken(RequestData*);

    void checkAuth(RequestData*) override;
//    void logNetwork(QNetworkAccessManager::Operation operation, QString request, QString post, int code) override;

private:
//    QTimer timer_;

    QString token_;
    const QString c_baseTest = "http://cabinet.tst.tanker.yandex.ru";
    const QString c_baseRelease = "https://cabinet.tanker.yandex.net";

};

#endif // YANDEXAPI_H
