#ifndef DATABASECONTROL_H
#define DATABASECONTROL_H

#include <QObject>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QSqlQuery>
#include <QFile>
#include <QDebug>
#include <QDateTime>
#include <QSettings>
#include "partners/networking/requestdata.h"

#define Structs {
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
};

struct Transaction {
    QString agzsName;
    int localVCode = 0;
    QString trkType;
    QString deviceName;
    QString serial;
    QString fuelName;
    QString fuelShortName;
    QString side;
    int sideAdress = 0;
    int nozzle = 0;
    int trkFuelCode = 0;
    QString transNum;
    double trkTotalPrice = 0.0;
    double trkVolume = 0.0;
    double trkUnitPrice = 0.0;
    double requestTotalPrice = 0.0;
    double requestVolume = 0.0;
    double requestUnitPrice = 0.0;
    QString requestField;
    QString state;
    int iState = 0;
    QString trkTransType;
    double litersCountBefore = 0.0;
    double moneyCountBefore = 0.0;
    int transCountBefore = 0;
    double litersCountAfter = 0.0;
    double moneyCountAfter = 0.0;
    int transCountAfter = 0;
    QString result;
    QDateTime dateOpen;
    QDateTime dateClose;
    double temperature = 0.0;
    int payOperationVCode = 0;
    QString payWay;
    int prePostPay = 0;
    QString wUser;
    QDateTime wDate;
    QString cUser;
    QDateTime cDate;
    QString cHost;
    QString wHost;
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

enum class ErrorsOrder {
    noError = 0,
    trkError = 1,
    fuelError = 2,
    priceError = 3
};

#define StructsEnd }

class DataBaseControl : public QObject {
    Q_OBJECT
public:
    explicit DataBaseControl(QObject *parent = nullptr);
    bool init();

public slots:
    int getCurrentAgzs();
    FuelNames getFuelNames(int aFuelId);
    QVector<SideFuel> getFuels();
    int getCashBoxIndex(QString iPartner);
    Price getPrices(QString iPartner);
    Agzs getAgzsData();
    AdastTrk getAgzsAdastTrk(int sideAdress);
    bool updateApiTransaction(int localState, QDateTime date, int vCode);
    int getLastVCode(QString key, bool update);
    ErrorsOrder checkError(QString aColumnID, QString aFuelID, int aiFuelID, QString aPriceFuel, int aIPartner);
    bool createTrkTransaction(QString aAgzsName, int aLocalVCode, QString aTrkType, QString aDeviceName, QString aSerial, QString aFuelName, QString aFuelShortName, QString aSide, int aSideAdress, int aNozzle, int aTrkFuelCode, QString aTransNum, double aTrkTotalPrice, double aTrkVolume, double aTrkUnitPrice, double aRequestTotalPrice, double aRequestVolume, double aRequestUnitPrice, QString aRequestField, QString aState, int aIState, QString aTrkTransType, double aLitersCountBefore, double aMoneyCountBefore, int aTransCountBefore, double aLitersCountAfter, double aMoneyCountAfter, int aTransCountAfter, QString aResult, QDateTime aDateOpen, QDateTime aDateClose, double aTemperature, int aPayOperationVCode, QString aPayWay, int aPrePostPay, QString aWUser, QDateTime aWDate, QString aCUser, QDateTime aCDate, QString aCHost, QString aWHost, int aVCode, int aAddedForTransVCode, int aAditionalTransVCode, int aActive, double aMass, int aSmena, int aTrkVcode, int aCapacityVcode, int aPumpPlace, double aMoneyTaken, int aIPayWay, int aAutoCheck, int aClosed, int aFullTank, int aAgzs, int aFuelVCode, int aPropan);
    bool createTrkTransaction(Transaction transaction);
    int getSmena();
    bool createApiTransaction(QString aAgzsName, int aAgzs, QDateTime aCDate, int aVCode, QString aApiId, QString aApiStationExtendedId, int aApiColumnId, QString aApiFuelId, int aFuelId, int aApiPriceFuel, int aApiLitre, int aApiSum, QString aApiStatus, QString aApiContractId, QString aAgent, QString aLocalState, double aPrice, double aLitre, double aSum, QDateTime aDateOpen, int aLink);
    ApiTransaction getApiTransaction(QString id);
    bool updateApiTransactionState(QString localState, QDateTime dateClose, int vCode);
    bool finalUpdateApiTransactionState(QString localState, double price, double volume, double amount, QDateTime dateOpen, QDateTime dateClose, int vCode);
    bool getPayOperationLiters(int link, double &amount, double &volume, double &price);
    bool setTransactionClosed(QString id, int closed);
    Transaction getTransaction(int aVCode);
    bool setYandexToken(QString aToken);
    bool isTransactionExist(QString aApiId);

    int getRealSideAddress(int aAgzs, int aPartnerSideAddress);
signals:

private slots:
    bool openDB();

private:
    QSqlDatabase _db;
    QSettings _reestr;

};

#endif // DATABASECONTROL_H
