#ifndef YANDEXAPI_H
#define YANDEXAPI_H

#include <QObject>
#include <requestdata.h>
#include <QSettings>

class YandexAPI : public QObject
{
    Q_OBJECT
public:
    YandexAPI(QString bazeurl, QObject *parent=nullptr);
    void GetPassword(QString login);
    void Authorization(QString login, QString password);
    void UpdatePriceList(QString pricelist);
    void UpdateConfigurationAGZS(QJsonObject configuration);
    void UpdateConfigurationAGZS(QString configuration);
    void CheckOrders(QString);//?
    void SendLoadCounter(QString orderid, QString volume);
    void ReceiveVolumeReport(QDateTime sdate, QDateTime edate, int page);

    void GetStateAGZS(QString apikey);

private:
    void SaveToken(RequestData*);
    void On_ReceiveVolumeReport(RequestData *a_request);
    void On_GetStateAGZS(RequestData *a_request);
    QString _bazeurl;
};

#endif // YANDEXAPI_H
