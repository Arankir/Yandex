#ifndef PARTNERAPI_H
#define PARTNERAPI_H

#include <QObject>
#include <QSettings>
#include <QTimer>
#include "networking/requestdata.h"

class PartnerAPI : public QObject {
    Q_OBJECT
public:
    explicit PartnerAPI(QObject *parent = nullptr);
    ~PartnerAPI();

    virtual int iPayWay() = 0;
    virtual QString payWay() = 0;
    virtual QString agent() = 0;
    virtual QString baseUrl() = 0;

    void start(int interval = 5000);
    void stop();
    bool isStart() {return timerOrders_.isActive();}

    bool isLastPriceUpdated() {return isLastPriceUpdated_;}
    bool isLastConfigurationUpdated() {return isLastConfigurationUpdated_;}

    void priceNeedUpdate() {isLastPriceUpdated_ = false;}
    void configurationNeedUpdate() {isLastConfigurationUpdated_ = false;}

    virtual void updatePriceList(QString pricelist) = 0;
    virtual void updateConfigurationAGZS(QJsonObject configuration) = 0;
    virtual void setStatusAccept(QString orderId, int vCode) = 0;
    virtual void setStatusFueling(QString orderId, int vCode) = 0;
    virtual void setStatusCanceled(QString orderId, QString reason, QString extendedOrderId, QDateTime extendedDate) = 0;
    virtual void setStatusCompleted(QString orderId, double litre, QString extendedOrderId, QDateTime extendedDate) = 0;
    virtual void setStatusFuelNow(QString orderId, double litre) = 0;

public slots:
    virtual int checkOrders() = 0;

signals:
    void s_gotOrders(QJsonDocument orders);
    void s_error(const QString &status, const QString &order, int code);

protected slots:
    virtual QNetworkRequest createNetworkRequest(QUrl url, QString contentType = "application/x-www-form-urlencoded", QString auth = "");
    virtual RequestData *createRequestData();
    virtual void checkAuth(RequestData*) = 0;
    virtual void logNetwork(QNetworkAccessManager::Operation operation, QString request, QString post, int code);

protected:
    QSettings reestr_;
    RequestData *request_ = nullptr;
    QTimer timerOrders_;
    int timerInterval_ = 5000;
    bool isLastPriceUpdated_ = false;
    bool isLastConfigurationUpdated_ = false;

    int &fixInterval(int &interval);
private:

};

#endif // PARTNERAPI_H
