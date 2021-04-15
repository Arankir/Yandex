#ifndef STRUCTS_H
#define STRUCTS_H

#include <QString>
#include <QDateTime>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include "partners/yandexapi.h"
#include "partners/citymobileapi.h"

enum class Fuel {
     diesel = 32,
     diesel_premium = -10,
     a80 = -11,
     a92 = 3,
     a92_premium = -12,
     a95 = 8,
     a95_premium = -13,
     a98 = -14,
     a98_premium = -15,
     a100 = -16,
     a100_premium = -17,
     propane = 14,
     metan = -18,
     unknown = -1
};

Fuel apiToFuel(QString aFuel);

QString fuelToApi(Fuel aFuel);

QString fuelToName(Fuel aFuel);

struct Order {
    QString id;
    QDateTime dateCreate;
    QString orderType;
    double orderVolume;
    int columnId;
    double litre;
    QString status;
    Fuel fuel;
    double priceFuel;
    double sum;
    QString contractId;

    struct MoneyData {
        double requestTotalPriceDB = -1;
        double requestVolumeDB = -1;
        double requestUnitPriceDB = -1;
        double moneyTakenDB = -1;
        int fullTankDB = -1;
    };
    MoneyData moneyData;

    static Order fromJson(int aiPayWay, QJsonValue aOrder);
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

    bool operator!=(const Price &price);
    QString toString();
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

    int getNozzle(Fuel aFuelId) {
        int fuelId = static_cast<int>(aFuelId);
        if (fuelId == fuel1) {
            return 1;
        } else if (fuelId == fuel2) {
            return 2;
        } else if (fuelId == fuel3) {
            return 3;
        } else if (fuelId == fuel4) {
            return 4;
        } else if (fuelId == fuel5) {
            return 5;
        }
        return -1;
    }

    int getFuelCode(Fuel aFuelId) {
        int fuelId = static_cast<int>(aFuelId);
        if (fuelId == fuel1) {
            return fuelCode1;
        } else if (fuelId == fuel2) {
            return fuelCode2;
        } else if (fuelId == fuel3) {
            return fuelCode3;
        } else if (fuelId == fuel4) {
            return fuelCode4;
        } else if (fuelId == fuel5) {
            return fuelCode5;
        }
        return -1;
    }

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

const QString c_host = QStringLiteral("api");

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

    static Transaction createTransaction(Agzs agzs, int transactionVCode, AdastTrk trk, FuelNames fuelName, int sideAdress,
                                         Order order, QDateTime date, QString payWay, int iPayWay, int smena, int cashBoxIndex);
};

struct SideFuel {
    int sideAdress;
    int partnerSideAdress;
    QString side;
    QVector<int> fuels;
};

#endif // STRUCTS_H
