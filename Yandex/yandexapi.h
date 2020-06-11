#ifndef YANDEXAPI_H
#define YANDEXAPI_H

#include <QObject>
#include <requestdata.h>
#include <QSettings>
#include <QtSql/QSqlDatabase>
#include <QSqlQuery>
#include <QTimer>

class YandexAPI : public QObject {
    Q_OBJECT
public:
    YandexAPI(QString bazeurl, QSqlDatabase db, QString agzs, QObject *parent=nullptr);
    void getPassword(QString login);
    void authorization(QString login, QString password);
    void updatePriceList(QString pricelist);
    void updateConfigurationAGZS(QJsonObject configuration);
    void updateConfigurationAGZS(QString configuration);
    int checkOrders();
    void receiveVolumeReport(QDateTime sdate, QDateTime edate, int page = 0);

    void getStateAGZS(QString apikey);

    void setStatusAccept(QString orderId);
    void setStatusFueling(QString orderId);
    void setStatusCanceled(QString orderId, QString reason, QString extendedOrderId, QDateTime extendedDate);
    void setStatusCompleted(QString orderId, double litre, QString extendedOrderId, QDateTime extendedDate);
    void setFuelNow(QString orderId, double litre);

signals:
    void s_setTimer(int mSec);
    void s_needAuth(bool);
    void s_authComplete(bool);
    void s_updatePrice();

private slots:
    QNetworkRequest createRequest(QString url, QString contentType, bool auth);
    void checkAuth(RequestData*);
    void saveToken(RequestData*);

    void createTransaction(QJsonObject transaction);

    int getLastAPI();
    int getFuelID(QString fuelIdAPI);
    QString getFullFuelName(int fuelID);
    int getCashBoxIndex();
    int checkError(QString columnId, QString fuelId, QString priceFuel, QString id, QString lastVCode, QDateTime now);
    void moneyData(QJsonObject data, double &requestTotalPriceDB, double &requestVolumeDB, double &requestUnitPriceDB, double &moneyTakenDB, int &fullTankDB);
    QString getSmena();

private:
    const QString _bazeUrl;
    RequestData *_request;
    QSettings _reestr;
    QSqlDatabase _db;
    QString _agzs;
    QTimer _timer;

};

#endif // YANDEXAPI_H
