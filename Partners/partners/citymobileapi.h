#ifndef CITYMOBILEAPI_H
#define CITYMOBILEAPI_H

#include <QObject>
#include "networking/requestdata.h"
#include "partners/partnerapi.h"
#include <QSettings>

const int c_cityMobileIPayWay = 10;

class CityMobileAPI : public PartnerAPI {
    Q_OBJECT
public:
    int iPayWay() override {return c_cityMobileIPayWay;}
    QString payWay() override {return "СИТИМОБИЛ";}
    QString agent() override {return "CityMobile";}
    QString baseUrl() override;

    explicit CityMobileAPI(QObject *parent = nullptr);
    ~CityMobileAPI();
    void setStatusMessage(QString orderId, QString msg);

    void updatePriceList(QString pricelist) override;
    void updateConfigurationAGZS(QJsonObject configuration) override;
    int checkOrders() override;

    void setStatusAccept(QString orderId, int vCode) override;
    void setStatusFueling(QString orderId, int vCode) override;
    void setStatusCanceled(QString orderId, QString reason, QString extendedOrderId, QDateTime extendedDate) override;
    void setStatusCompleted(QString orderId, double litre, QString extendedOrderId, QDateTime extendedDate) override;
    void setStatusFuelNow(QString orderId, double litre) override;

signals:
    void s_finished(RequestData *request);
    void s_gotOrders(QJsonDocument orders);
    void s_error(QString status, QString order, int code);

private slots:
    QNetworkRequest createNetworkRequest(QUrl url, QString contentType = "application/x-www-form-urlencoded", bool auth = true);

    void checkAuth(RequestData*) override {};
//    void logNetwork(QNetworkAccessManager::Operation operation, QString request, QString post, int code) override;

private:
    QString apiKey_;
    QString currentPrice_;
    QString currentConfiguration_;
    const QString c_baseTest = "https://terminal.api.test.fuelup.ru/";
    const QString c_baseRelease = "https://terminal.api.fuelup.ru/";

};

#endif // CITYMOBILEAPI_H
