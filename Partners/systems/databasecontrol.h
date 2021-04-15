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
#include <systems/structs.h>
#include "partners/networking/requestdata.h"

class DataBaseControl: public QObject {
    Q_OBJECT

enum QueryType {
    qSelect,
    qUpdate,
    qDelete,
    qInsert,
    qProcedure
};

public:
    explicit DataBaseControl(QString Agzs, QObject *parent = nullptr);
    bool init();

public slots:
    int getCurrentAgzs();
    FuelNames getFuelNames(int aFuelId);
    QVector<SideFuel> getFuels();
    int getCashBoxIndex(QString iPartner);
    Price getPrices(QString iPartner);
    Agzs getAgzsData();
    AdastTrk getAgzsAdastTrk(int sideAdress);
    int generateVCode(QString key);
    ErrorsOrder checkError(QString aColumnID, QString aFuelID, int aiFuelID, QString aPriceFuel, int aIPartner);
    bool createTrkTransaction(QString aAgzsName, int aLocalVCode, QString aTrkType, QString aDeviceName, QString aSerial, QString aFuelName, QString aFuelShortName, QString aSide, int aSideAdress, int aNozzle, int aTrkFuelCode, QString aTransNum, double aTrkTotalPrice, double aTrkVolume, double aTrkUnitPrice, double aRequestTotalPrice, double aRequestVolume, double aRequestUnitPrice, QString aRequestField, QString aState, int aIState, QString aTrkTransType, double aLitersCountBefore, double aMoneyCountBefore, int aTransCountBefore, double aLitersCountAfter, double aMoneyCountAfter, int aTransCountAfter, QString aResult, QDateTime aDateOpen, QDateTime aDateClose, double aTemperature, int aPayOperationVCode, QString aPayWay, int aPrePostPay, QString aWUser, QDateTime aWDate, QString aCUser, QDateTime aCDate, QString aCHost, QString aWHost, int aVCode, int aAddedForTransVCode, int aAditionalTransVCode, int aActive, double aMass, int aSmena, int aTrkVcode, int aCapacityVcode, int aPumpPlace, double aMoneyTaken, int aIPayWay, int aAutoCheck, int aClosed, int aFullTank, int aAgzs, int aFuelVCode, int aPropan);
    bool createTrkTransaction(Transaction transaction);
    int getSmena();
    bool createApiTransaction(QString aAgzsName, int aAgzs, QDateTime aCDate, int aVCode, QString aApiId, QString aApiStationExtendedId, int aApiColumnId, QString aApiFuelId, int aFuelId, int aApiPriceFuel, int aApiLitre, int aApiSum, QString aApiStatus, QString aApiContractId, QString aAgent, QString aLocalState, double aPrice, double aLitre, double aSum, QDateTime aDateOpen, int aLink);
    bool updateApiTransactionLink(QString aApiId, int aLink);
    ApiTransaction getApiTransaction(QString id);
    bool updateApiTransactionState(QString localState, QDateTime dateClose, int vCode);
    bool finalUpdateApiTransactionState(QString localState, double price, double volume, double amount, QDateTime dateOpen, QDateTime dateClose, int vCode);
    bool getPayOperationData(int link, double &amount, double &volume, double &price, QDateTime &aDateStart, QDateTime &aDateEnd);
    bool setTransactionClosed(QString id, int closed);
    Transaction getTransaction(int aVCode);
    QList<ApiTransaction> getOpenedApiTransactions(int aPartner);
    bool updateYandexToken(QString aToken);
    QString getCityMobileToken();
    bool isApiTransactionExist(QString aApiId);
    bool isApiTransactionExist(int aVCode);

    int getRealSideAddress(int aAgzs, int aPartnerSideAddress);
signals:

private slots:
    bool openDB();
    bool makeQuery(QString query, QString name, DataBaseControl::QueryType type, std::function<void (QSqlQuery &)> func = std::function<void (QSqlQuery &)>(), bool isShowMessageNoData = true);

private:
    QString agzs_;
    QSqlDatabase db_;

};

#endif // DATABASECONTROL_H
