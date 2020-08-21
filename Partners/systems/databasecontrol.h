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
    bool init();
    bool logAppend(QString string);

public slots:
    int getCurrentAgzs();
    bool getFuelNames(int aFuelId, QString &fullName, QString &shortName);
    bool getFuels(QVector<QPair<int, QVector<int> > > &fuels);
    int getCashBoxIndex(QString iPartner);
    bool getPrices(QString iPartner, QString &agzsName, int &agzs, int &vCode, int &link, QDateTime &cDate, QString &partner,
                   double &diesel, double &diesel_premium, double &a80, double &a92, double &a92_premium, double &a95, double &a95_premium,
                   double &a98, double &a98_premium, double &a100, double &a100_premium, double &propane, double &metan);
    bool getAgzsData(QString &agzsName, int &agzs, QDateTime &cDate, int &vCode, QString &id, QString &adress, double &loc_x, double &loc_y, int &columnCount);
    bool getAgzsAdastTrk(int sideAdress, QString &side, QString &deviceName, QString &serial, QString &description, int &fuelCode1, int &fuelCode2, int &fuelCode3, int &fuelCode4, int &fuelCode5, int &trkVCode, int &pumpPlace, int &fuel1, int &fuel2, int &fuel3, int &fuel4, int &fuel5);
    bool updateApiTransaction(int localState, QDateTime date, int vCode);
    int getLastVCode(QString key, bool update);
    int checkError(QString aColumnID, QString aFuelID, int aiFuelID, QString aPriceFuel, int aIPartner);
    bool createTrkTransaction(QString aAgzsName, int aLocalVCode, QString aTrkType, QString aDeviceName, QString aSerial, QString aFuelName, QString aFuelShortName, QString aSide, int aSideAdress, int aNozzle, int aTrkFuelCode, QString aTransNum, double aTrkTotalPrice, double aTrkVolume, double aTrkUnitPrice, double aRequestTotalPrice, double aRequestVolume, double aRequestUnitPrice, QString aRequestField, QString aState, int aIState, QString aTrkTransType, double aLitersCountBefore, double aMoneyCountBefore, int aTransCountBefore, double aLitersCountAfter, double aMoneyCountAfter, int aTransCountAfter, QString aResult, QDateTime aDateOpen, QDateTime aDateClose, double aTemperature, int aPayOperationVCode, QString aPayWay, int aPrePostPay, QString aWUser, QDateTime aWDate, QString aCUser, QDateTime aCDate, QString aCHost, QString aWHost, int aVCode, int aAddedForTransVCode, int aAditionalTransVCode, int aActive, double aMass, int aSmena, int aTrkVcode, int aCapacityVcode, int aPumpPlace, double aMoneyTaken, int aIPayWay, int aAutoCheck, int aClosed, int aFullTank, int aAgzs, int aFuelVCode, int aPropan);
    int getSmena();
    bool createApiTransaction(QString aAgzsName, int aAgzs, QDateTime aCDate, int aVCode, QString aApiId, QString aApiStationExtendedId, int aApiColumnId, QString aApiFuelId, int aFuelId, int aApiPriceFuel, int aApiLitre, int aApiSum, QString aApiStatus, QString aApiContractId, QString aAgent, QString aLocalState, double aPrice, double aLitre, double aSum, QDateTime aDateOpen, int aLink);
    bool getApiTransactionState(QString id, QString &localState, double &aApiLitre, int &apiVCode, int &headVCode, int &iState, QDateTime dateOpen, QDateTime &dateClose);
    bool updateApiTransactionState(QString localState, QDateTime dateClose, int vCode);
    bool finalUpdateApiTransactionState(QString localState, double price, double volume, double amount, QDateTime dateOpen, QDateTime dateClose, int vCode);
    bool getPayOperationLiters(int link, double &amount, double &volume, double &price);
    bool setTransactionClosed(QString id, int closed);
    bool getTransactionData(int aVCode, double &aRequestTotalPrice, double &aRequestVolume, double &aRequestUnitPrice, double &aTrkTotalPrice, double &aTrkVolume, double &aTrkUnitPrice, QDateTime &aDateOpen, QDateTime &aDateClose);
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
