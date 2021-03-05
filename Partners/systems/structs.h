#ifndef STRUCTS_H
#define STRUCTS_H

#include <QString>
#include <QDateTime>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

const QString c_host = "api";

enum class Partner {
    yandex = 11,
    citymobile = 10
};

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

Order JsonToOrder(Partner aPartner, QJsonValue aOrder);

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

OrderStatus stringToStatus(QString aStatus);

enum class ErrorsOrder {
    noError = 0,
    trkError = 1,
    fuelError = 2,
    priceError = 3
};

QString errorToString(ErrorsOrder aError);

struct FuelNames {
    QString fullName;
    QString shortName;
};

struct Price {
    QString agzsName;
    int agzs = 0;
    int vCode = 0;
    int link = 0;
    QDateTime cDate;
    QString partner;
    double diesel = 0.0;
    double diesel_premium = 0.0;
    double a80 = 0.0;
    double a92 = 0.0;
    double a92_premium = 0.0;
    double a95 = 0.0;
    double a95_premium = 0.0;
    double a98 = 0.0;
    double a98_premium = 0.0;
    double a100 = 0.0;
    double a100_premium = 0.0;
    double propane = 0.0;
    double metan = 0.0;
};

struct Agzs {
    QString agzsName;
    int agzs = 0;
    QDateTime cDate;
    int vCode = 0;
    QString id;
    QString adress;
    double loc_x = 0.0;
    double loc_y = 0.0;
    int columnCount = 0;
};

struct AdastTrk {
    int sideAdress = 0;
    QString side;
    QString deviceName;
    QString serial;
    QString description;
    int fuelCode1 = 0;
    int fuelCode2 = 0;
    int fuelCode3 = 0;
    int fuelCode4 = 0;
    int fuelCode5 = 0;
    int trkVCode = 0;
    int pumpPlace = 0;
    int fuel1 = 0;
    int fuel2 = 0;
    int fuel3 = 0;
    int fuel4 = 0;
    int fuel5 = 0;
};

struct ApiTransaction {
    QString id;
    QString localState;
    double apiLitre = 0.0;
    int apiVCode = 0;
    int headVCode = 0;
    int iState = 0;
    QDateTime dateOpen;
    QDateTime dateClose;

    bool operator==(const ApiTransaction &api) {
        return (this->id == api.id) &&
               (this->localState == api.localState) &&
               (this->apiLitre == api.apiLitre) &&
               (this->apiVCode == api.apiVCode) &&
               (this->headVCode == api.headVCode) &&
               (this->iState == api.iState) &&
               (this->dateOpen == api.dateOpen) &&
               (this->dateClose == api.dateClose);
    }
};

struct Transaction {
    QString agzsName;
    int localVCode = 0;
    QString trkType = "ADAST";
    QString deviceName;
    QString serial;
    QString fuelName;
    QString fuelShortName;
    QString side;
    int sideAdress = 0;
    int nozzle = 0;
    int trkFuelCode = 0;
    QString transNum = "";
    double trkTotalPrice = 0.0;
    double trkVolume = 0.0;
    double trkUnitPrice = 0.0;
    double requestTotalPrice = 0.0;
    double requestVolume = 0.0;
    double requestUnitPrice = 0.0;
    QString requestField = "V";
    QString state = "Завершение выдачи";
    int iState = 8;
    QString trkTransType = "P";
    double litersCountBefore = 0.0;
    double moneyCountBefore = 0.0;
    int transCountBefore = 0;
    double litersCountAfter = 0.0;
    double moneyCountAfter = 0.0;
    int transCountAfter = 0;
    QString result = "Выдача завершена: 1";
    QDateTime dateOpen;
    QDateTime dateClose;
    double temperature = -100.0;
    int payOperationVCode = 0;
    QString payWay;
    int prePostPay = 0;
    QString wUser = c_host;
    QDateTime wDate;
    QString cUser = c_host;
    QDateTime cDate;
    QString cHost = c_host;
    QString wHost = c_host;
    int vCode = 0;
    int addedForTransVCode = 0;
    int aditionalTransVCode = 0;
    int active = 0;
    double mass = 0.0;
    int smena = 0;
    int trkVcode = 0;
    int capacityVcode = 0;
    int pumpPlace = 0;
    double moneyTaken = 0.0;
    int iPayWay = 0;
    int autoCheck = 0;
    int closed = 0;
    int fullTank = 0;
    int agzs = 0;
    int fuelVCode = 0;
    int propan = 0;
};

struct SideFuel {
    int sideAdress;
    int partnerSideAdress;
    QString side;
    QVector<int> fuels;
};

#endif // STRUCTS_H
