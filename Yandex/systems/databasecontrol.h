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

class DataBaseControl : public QObject {
    Q_OBJECT
public:
    explicit DataBaseControl(QObject *parent = nullptr);
    bool Init();
    bool LogAppend(QString string);

public slots:
    int GetCurrentAgzs();
    bool GetFuelNames(int aFuelId, QString &fullName, QString &shortName);
    bool GetFuels(QVector<QVector<int>> &fuels);
    int GetCashBoxIndex(QString iPartner);
    bool GetPrices(QString iPartner, QString &agzsName, int &agzs, int &vCode, int &link, QDateTime &cDate, QString &partner,
                   double &diesel, double &diesel_premium, double &a80, double &a92, double &a92_premium, double &a95, double &a95_premium,
                   double &a98, double &a98_premium, double &a100, double &a100_premium, double &propane, double &metan);
    bool GetAgzsData(QString &agzsName, int &agzs, QDateTime &cDate, int &vCode, QString &id, QString &adress, double &loc_x, double &loc_y, int &columnCount);
    bool GetAgzsAdastTrk(int sideAdress, QString &side, QString &deviceName, QString &serial, QString &description, int &fuelCode1, int &fuelCode2, int &fuelCode3, int &fuelCode4, int &fuelCode5, int &trkVCode, int &pumpPlace, int &fuel1, int &fuel2, int &fuel3, int &fuel4, int &fuel5);
    bool UpdateApiTransaction(int localState, QDateTime date, int vCode);
    int GetLastVCode(QString key, bool update);
    int CheckError(QString aColumnID, QString aFuelID, int aiFuelID, QString aPriceFuel);
    bool createTrkTransaction(QString aAgzsName, int aLocalVCode, QString aTrkType, QString aDeviceName, QString aSerial, QString aFuelName, QString aFuelShortName, QString aSide, int aSideAdress, int aNozzle, int aTrkFuelCode, QString aTransNum, double aTrkTotalPrice, double aTrkVolume, double aTrkUnitPrice, double aRequestTotalPrice, double aRequestVolume, double aRequestUnitPrice, QString aRequestField, QString aState, int aIState, QString aTrkTransType, double aLitersCountBefore, double aMoneyCountBefore, int aTransCountBefore, double aLitersCountAfter, double aMoneyCountAfter, int aTransCountAfter, QString aResult, QDateTime aDateOpen, QDateTime aDateClose, double aTemperature, int aPayOperationVCode, QString aPayWay, int aPrePostPay, QString aWUser, QDateTime aWDate, QString aCUser, QDateTime aCDate, QString aCHost, QString aWHost, int aVCode, int aAddedForTransVCode, int aAditionalTransVCode, int aActive, double aMass, int aSmena, int aTrkVcode, int aCapacityVcode, int aPumpPlace, double aMoneyTaken, int aIPayWay, int aAutoCheck, int aClosed, int aFullTank, int aAgzs, int aFuelVCode, int aPropan);
    int getSmena();
    bool createApiTransaction(QString aAgzsName, int aAgzs, QDateTime aCDate, int aVCode, QString aApiId, QString aApiStationExtendedId, int aApiColumnId, QString aApiFuelId, int aFuelId, int aApiPriceFuel, int aApiLitre, int aApiSum, QString aApiStatus, QString aApiContractId, QString aAgent, QString aLocalState, double aPrice, double aLitre, double aSum, QDateTime aDateOpen, int aLink);
    bool getApiTransactionState(QString id, QString &localState, int &apiVCode, int &headVCode, int &iState, QDateTime dateOpen, QDateTime &dateClose);
    bool updateApiTransactionState(QString localState, QDateTime dateClose, int vCode);
    bool finalUpdateApiTransactionState(QString localState, double price, double volume, double amount, QDateTime dateOpen, QDateTime dateClose, int vCode);
    bool getPayOperationLiters(int link, double &amount, double &volume, double &price);
    bool setTransactionClosed(QString id, int closed);

signals:

private slots:
    bool GetFuelNamesCycle(int aFuelId, QString &fullName, QString &shortName);
    bool GetFuelsCycle(QVector<QVector<int>> &fuels);
    int GetCashBoxIndexCycle(QString iPartner);
    bool GetPricesCycle(QString iPartner, QString &agzsName, int &agzs, int &vCode, int &link, QDateTime &cDate, QString &partner,
                   double &diesel, double &diesel_premium, double &a80, double &a92, double &a92_premium, double &a95, double &a95_premium,
                   double &a98, double &a98_premium, double &a100, double &a100_premium, double &propane, double &metan);
    bool GetAgzsDataCycle(QString &agzsName, int &agzs, QDateTime &cDate, int &vCode, QString &id, QString &adress, double &loc_x, double &loc_y, int &columnCount);
    bool GetAgzsAdastTrkCycle(int sideAdress, QString &side, QString &deviceName, QString &serial, QString &description, int &fuelCode1, int &fuelCode2, int &fuelCode3, int &fuelCode4, int &fuelCode5, int &trkVCode, int &pumpPlace, int &fuel1, int &fuel2, int &fuel3, int &fuel4, int &fuel5);
    bool createTrkTransactionCycle(QString aAgzsName, int aLocalVCode, QString aTrkType, QString aDeviceName, QString aSerial, QString aFuelName, QString aFuelShortName, QString aSide, int aSideAdress, int aNozzle, int aTrkFuelCode, QString aTransNum, double aTrkTotalPrice, double aTrkVolume, double aTrkUnitPrice, double aRequestTotalPrice, double aRequestVolume, double aRequestUnitPrice, QString aRequestField, QString aState, int aIState, QString aTrkTransType, double aLitersCountBefore, double aMoneyCountBefore, int aTransCountBefore, double aLitersCountAfter, double aMoneyCountAfter, int aTransCountAfter, QString aResult, QDateTime aDateOpen, QDateTime aDateClose, double aTemperature, int aPayOperationVCode, QString aPayWay, int aPrePostPay, QString aWUser, QDateTime aWDate, QString aCUser, QDateTime aCDate, QString aCHost, QString aWHost, int aVCode, int aAddedForTransVCode, int aAditionalTransVCode, int aActive, double aMass, int aSmena, int aTrkVcode, int aCapacityVcode, int aPumpPlace, double aMoneyTaken, int aIPayWay, int aAutoCheck, int aClosed, int aFullTank, int aAgzs, int aFuelVCode, int aPropan);
    int getSmenaCycle();
    bool createApiTransactionCycle(QString aAgzsName, int aAgzs, QDateTime aCDate, int aVCode, QString aApiId, QString aApiStationExtendedId, int aApiColumnId, QString aApiFuelId, int aFuelId, int aApiPriceFuel, int aApiLitre, int aApiSum, QString aApiStatus, QString aApiContractId, QString aAgent, QString aLocalState, double aPrice, double aLitre, double aSum, QDateTime aDateOpen, int aLink);
    bool getApiTransactionStateCycle(QString id, QString &localState, int &apiVCode, int &headVCode, int &iState, QDateTime dateOpen, QDateTime &dateClose);
    bool updateApiTransactionStateCycle(QString localState, QDateTime dateClose, int vCode);
    bool finalUpdateApiTransactionStateCycle(QString localState, double price, double volume, double amount, QDateTime dateOpen, QDateTime dateClose, int vCode);
    bool getPayOperationLitersCycle(int link, double &amount, double &volume, double &price);
    bool setTransactionClosedCycle(QString id, int closed);

private:
    QSqlDatabase _db;
    QSettings _reestr;
    int _cycles;

};

#endif // DATABASECONTROL_H
