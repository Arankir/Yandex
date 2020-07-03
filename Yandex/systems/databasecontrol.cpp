#include "databasecontrol.h"

const QString c_settingPath = "Setting.txt";
const QString c_logPath = "Log.txt";

const int c_maxRestartCount = 10;

#define InitStart {
DataBaseControl::DataBaseControl(QObject *aParent) : QObject(aParent), _reestr("RegionPostavka", "Partners") {
    if (QFile::exists(c_logPath)) {
        QFile fLog(c_logPath);
        if (fLog.open(QIODevice::WriteOnly)) {
            fLog.close();
        } else {
            qDebug()<<"Error: log file is already open";
        }
    } else {
        qDebug()<<"Error: log file not found";
    }
    while(!Init());
}

bool DataBaseControl::Init() {
    _db = QSqlDatabase::addDatabase("QODBC3");
    QStringList setting;
    if (QFile::exists(c_settingPath)) {
        QFile settings(c_settingPath);
        if (settings.open(QIODevice::ReadOnly)) {
            while(!settings.atEnd()) {
                setting << QString::fromLocal8Bit(settings.readLine()).remove("\r\n").remove("\n");
            }
            settings.close();
        } else {
            LogAppend("Error: setting file is already open");
            return false;
        }
    } else {
        LogAppend("Error: setting file not found");
        return false;
    }
    qDebug()<<setting;
    if (setting.size() > 1) {
        _reestr.setValue("CityMobile Token", setting[1]);
    }
    if (setting.size() > 0) {
        _db.setDatabaseName(QString("DRIVER={SQL Server};"
                                    "SERVER=%1;"
                                    "DATABASE=agzs;"
                                    "Persist Security Info=true;"
                                    "uid=sa;"
                                    "pwd=Gfhf743Djpbr").arg(setting[0]));
        if (_db.open()) {
            return true;
        } else {
            return false;
        }
    }
    return false;
}

bool DataBaseControl::LogAppend(QString aMessage) {
    if (QFile::exists(c_logPath)) {
        QFile fLog(c_logPath);
        if (fLog.open(QIODevice::Append)) {
            QTextStream writeStream(&fLog);
            QDateTime time;
            writeStream <<time.currentDateTime().toString("yyyy-MM-dd  HH:mm:ss") <<" "+aMessage <<"\n";
            fLog.close();
            return true;
        } else {
            qDebug()<<"Error: log file is already open";
        }
    } else {
        qDebug()<<"Error: log file not found";
    }
    return false;
}
#define InitEnd }

#define OneStart {
bool DataBaseControl::GetFuelNames(int aFuelId, QString &aFullName, QString &aShortName) {
    _cycles = 0;
    return GetFuelNamesCycle(aFuelId, aFullName, aShortName);
}

bool DataBaseControl::GetFuels(QVector<QVector<int> > &aFuels) {
    _cycles = 0;
    return GetFuelsCycle(aFuels);
}

int DataBaseControl::getSmena() {
    _cycles = 0;
    return getSmenaCycle();
}

int DataBaseControl::GetCashBoxIndex(QString aIPartner) {
    _cycles = 0;
    return GetCashBoxIndexCycle(aIPartner);
}

bool DataBaseControl::GetPrices(QString aIPartner, QString &aAgzsName, int &aAgzs, int &aVCode, int &aLink, QDateTime &aCDate, QString &aPartner,
                                double &aDiesel, double &aDiesel_premium, double &aA80, double &aA92, double &aA92_premium, double &aA95, double &aA95_premium, double &aA98,
                                double &aA98_premium, double &aA100, double &aA100_premium, double &aPropane, double &aMetan) {
    _cycles = 0;
    return GetPricesCycle(aIPartner, aAgzsName, aAgzs, aVCode, aLink, aCDate, aPartner, aDiesel, aDiesel_premium, aA80, aA92, aA92_premium, aA95, aA95_premium,
                          aA98, aA98_premium, aA100, aA100_premium, aPropane, aMetan);
}

bool DataBaseControl::GetAgzsData(QString &aAgzsName, int &aAgzs, QDateTime &aCDate, int &aVCode, QString &aId, QString &aAdress, double &aLoc_x, double &aLoc_y, int &aColumnCount) {
    _cycles = 0;
    return GetAgzsDataCycle(aAgzsName, aAgzs, aCDate, aVCode, aId, aAdress, aLoc_x, aLoc_y, aColumnCount);
}

bool DataBaseControl::GetAgzsAdastTrk(int aSideAdress, QString &aSide, QString &aDeviceName, QString &aSerial, QString &aDescription,
                                      int &aFuelCode1, int &aFuelCode2, int &aFuelCode3, int &aFuelCode4, int &aFuelCode5,
                                      int &aTrkVCode, int &aPumpPlace, int &aFuel1, int &aFuel2, int &aFuel3, int &aFuel4, int &aFuel5) {
    _cycles = 0;
    return GetAgzsAdastTrkCycle(aSideAdress, aSide, aDeviceName, aSerial, aDescription, aFuelCode1, aFuelCode2, aFuelCode3, aFuelCode4, aFuelCode5,
                                aTrkVCode, aPumpPlace, aFuel1, aFuel2, aFuel3, aFuel4, aFuel5);
}

bool DataBaseControl::createTrkTransaction(QString aAgzsName, int aLocalVCode, QString aTrkType, QString aDeviceName, QString aSerial, QString aFuelName,
                                           QString aFuelShortName, QString aSide, int aSideAdress, int aNozzle, int aTrkFuelCode, QString aTransNum,
                                           double aTrkTotalPrice, double aTrkVolume, double aTrkUnitPrice, double aRequestTotalPrice, double aRequestVolume,
                                           double aRequestUnitPrice, QString aRequestField, QString aState, int aIState, QString aTrkTransType,
                                           double aLitersCountBefore, double aMoneyCountBefore, int aTransCountBefore, double aLitersCountAfter,
                                           double aMoneyCountAfter, int aTransCountAfter, QString aResult, QDateTime aDateOpen, QDateTime aDateClose,
                                           double aTemperature, int aPayOperationVCode, QString aPayWay, int aPrePostPay, QString aWUser, QDateTime aWDate,
                                           QString aCUser, QDateTime aCDate, QString aCHost, QString aWHost, int aVCode, int aAddedForTransVCode,
                                           int aAditionalTransVCode, int aActive, double aMass, int aSmena, int aTrkVcode, int aCapacityVcode, int aPumpPlace,
                                           double aMoneyTaken, int aIPayWay, int aAutoCheck, int aClosed, int aFullTank, int aAgzs, int aFuelVCode, int aPropan) {
    _cycles = 0;
    return createTrkTransactionCycle(aAgzsName, aLocalVCode, aTrkType, aDeviceName, aSerial, aFuelName, aFuelShortName,
                                     aSide, aSideAdress, aNozzle, aTrkFuelCode, aTransNum, aTrkTotalPrice, aTrkVolume, aTrkUnitPrice,
                                     aRequestTotalPrice, aRequestVolume, aRequestUnitPrice, aRequestField, aState, aIState, aTrkTransType,
                                     aLitersCountBefore, aMoneyCountBefore, aTransCountBefore, aLitersCountAfter, aMoneyCountAfter, aTransCountAfter,
                                     aResult, aDateOpen, aDateClose, aTemperature, aPayOperationVCode, aPayWay, aPrePostPay,
                                     aWUser, aWDate, aCUser, aCDate, aCHost, aWHost, aVCode, aAddedForTransVCode,
                                     aAditionalTransVCode, aActive, aMass, aSmena, aTrkVcode, aCapacityVcode, aPumpPlace, aMoneyTaken,
                                     aIPayWay, aAutoCheck, aClosed, aFullTank, aAgzs, aFuelVCode, aPropan);
}

bool DataBaseControl::createApiTransaction(QString aAgzsName, int aAgzs, QDateTime aCDate, int aVCode, QString aApiId, QString aApiStationExtendedId,
                                     int aApiColumnId, QString aApiFuelId, int aFuelId, int aApiPriceFuel, int aApiLitre, int aApiSum, QString aApiStatus,
                                     QString aApiContractId, QString aAgent, QString aLocalState, double aPrice, double aLitre, double aSum, QDateTime aDateOpen, int aLink) {
    _cycles = 0;
    return createApiTransactionCycle(aAgzsName, aAgzs, aCDate, aVCode, aApiId, aApiStationExtendedId,
                                     aApiColumnId, aApiFuelId, aFuelId, aApiPriceFuel, aApiLitre, aApiSum, aApiStatus,
                                     aApiContractId, aAgent, aLocalState, aPrice, aLitre, aSum, aDateOpen, aLink);
}

bool DataBaseControl::getApiTransactionState(QString aId, QString &aLocalState, int &aApiVCode, int &aHeadVCode, int &aIState, QDateTime aDateOpen, QDateTime &aDateClose) {
    _cycles = 0;
    return getApiTransactionStateCycle(aId, aLocalState, aApiVCode, aHeadVCode, aIState, aDateOpen, aDateClose);
}

bool DataBaseControl::updateApiTransactionState(QString aLocalState, QDateTime aDateClose, int aVCode) {
    _cycles = 0;
    return updateApiTransactionStateCycle(aLocalState, aDateClose, aVCode);
}

bool DataBaseControl::finalUpdateApiTransactionState(QString aLocalState, double aPrice, double aVolume, double aAmount, QDateTime aDateOpen, QDateTime aDateClose, int aVCode) {
    _cycles = 0;
    return finalUpdateApiTransactionStateCycle(aLocalState, aPrice, aVolume, aAmount, aDateOpen, aDateClose, aVCode);
}

bool DataBaseControl::getPayOperationLiters(int aLink, double &aAmount, double &aVolume, double &aPrice) {
    _cycles = 0;
    return getPayOperationLitersCycle(aLink, aAmount, aVolume, aPrice);
}

bool DataBaseControl::setTransactionClosed(QString aId, int aClosed) {
    _cycles = 0;
    return setTransactionClosedCycle(aId, aClosed);
}
#define OneEnd }

#define CycleStart {
bool DataBaseControl::GetFuelNamesCycle(int aFuelId, QString &aFullName, QString &aShortName) {
    QSqlQuery *qFuels = new QSqlQuery(_db);
    qFuels->exec("SELECT TOP 1 [FuelName], [FuelShortName] "
                  "FROM [agzs].[dbo].[Interface_FuelParams] "
                  "WHERE [Fuel] =" + QString::number(aFuelId));
    qFuels->next();
    if (qFuels->lastError().type() == QSqlError::NoError) {
        aFullName = qFuels->value(0).toString();
        aShortName = qFuels->value(1).toString();
        delete qFuels;
        return true;
    } else {
        delete qFuels;
        Init();
        if (_cycles < c_maxRestartCount) {
            LogAppend("GetFuelNamesCycle error " + QString::number(_cycles));
            _cycles++;
            return GetFuelNamesCycle(aFuelId, aFullName, aShortName);
        } else {
            return false;
        }
    }
}

bool DataBaseControl::GetFuelsCycle(QVector<QVector<int> > &aFuels) {
    QSqlQuery *qFuels = new QSqlQuery(_db);
    qFuels->exec("SELECT [DeviceName], [Serial], [Description], "
                 "[SideA_Address], [SideA_Nozzle1FuelCode], [SideA_Nozzle2FuelCode], [SideA_Nozzle3FuelCode], [SideA_Nozzle4FuelCode], [SideA_Nozzle5FuelCode], "
                 "[SideB_Address], [SideB_Nozzle1FuelCode], [SideB_Nozzle2FuelCode], [SideB_Nozzle3FuelCode], [SideB_Nozzle4FuelCode], [SideB_Nozzle5FuelCode], "
                 "[SystemSettings], [CDate], [VCode], "
                 "[SideA_PumpPlace], [SideA_Nozzle1Fuel], [SideA_Nozzle2Fuel], [SideA_Nozzle3Fuel], [SideA_Nozzle4Fuel], [SideA_Nozzle5Fuel], "
                 "[SideB_PumpPlace], [SideB_Nozzle1Fuel], [SideB_Nozzle2Fuel], [SideB_Nozzle3Fuel], [SideB_Nozzle4Fuel], [SideB_Nozzle5Fuel] "
                 "FROM [agzs].[dbo].[ADAST_AdastTRK] ");
    if (qFuels->lastError().type() == QSqlError::NoError) {
        while (qFuels->next()) {
            if (!qFuels->value(3).isNull()) {
                QVector<int> fuelsLocalA;
                fuelsLocalA.append(qFuels->value(3).toInt());
                if (!qFuels->value(19).isNull()) {
                    fuelsLocalA.append(qFuels->value(19).toInt());
                }
                if (!qFuels->value(20).isNull()) {
                    fuelsLocalA.append(qFuels->value(20).toInt());
                }
                if (!qFuels->value(21).isNull()) {
                    fuelsLocalA.append(qFuels->value(21).toInt());
                }
                if (!qFuels->value(22).isNull()) {
                    fuelsLocalA.append(qFuels->value(22).toInt());
                }
                if (!qFuels->value(23).isNull()) {
                    fuelsLocalA.append(qFuels->value(23).toInt());
                }
                aFuels.append(fuelsLocalA);
            }
            if (!qFuels->value(9).isNull()) {
                QVector<int> fuelsLocalB;
                fuelsLocalB.append(qFuels->value(9).toInt());
                if (!qFuels->value(25).isNull()) {
                    fuelsLocalB.append(qFuels->value(25).toInt());
                }
                if (!qFuels->value(26).isNull()) {
                    fuelsLocalB.append(qFuels->value(26).toInt());
                }
                if (!qFuels->value(27).isNull()) {
                    fuelsLocalB.append(qFuels->value(27).toInt());
                }
                if (!qFuels->value(28).isNull()) {
                    fuelsLocalB.append(qFuels->value(28).toInt());
                }
                if (!qFuels->value(29).isNull()) {
                    fuelsLocalB.append(qFuels->value(29).toInt());
                }
                aFuels.append(fuelsLocalB);
            }
        }
        delete qFuels;
        return true;
    } else {
        delete qFuels;
        Init();
        if (_cycles < c_maxRestartCount) {
            LogAppend("GetFuelsCycle error " + QString::number(_cycles));
            _cycles++;
            return GetFuelsCycle(aFuels);
        } else {
            return false;
        }
    }
}

int DataBaseControl::getSmenaCycle() {
    QSqlQuery *qSmena = new QSqlQuery(_db);
    qSmena->exec("SELECT TOP 1 VCode "
                  "FROM [agzs].[dbo].[ARM_Smena] "
                  "ORDER BY CDate DESC");
    qSmena->next();
    int index = 0;
    if (qSmena->lastError().type() == QSqlError::NoError) {
        index = qSmena->value(0).toInt();
        delete qSmena;
    } else if (_cycles < c_maxRestartCount) {
        _cycles++;
        LogAppend("GetSmenaCycle error " + QString::number(_cycles));
        delete qSmena;
        Init();
        index = getSmenaCycle();
    }
    return index;
}

int DataBaseControl::GetCashBoxIndexCycle(QString aIPartner) {
    QSqlQuery *qCashBox = new QSqlQuery(_db);
    qCashBox->exec("SELECT TOP 1 CashBoxIndex, PayIndex, PayWay, AutoCheck FROM [agzs].[dbo].[ARM_CashBoxesSemaphor] "
                    "WHERE PayIndex = " + aIPartner + " and AutoCheck = 0 "
                    "ORDER BY CDate DESC");
    qCashBox->next();
    int index = 0;
    if (qCashBox->lastError().type() == QSqlError::NoError) {
        index = qCashBox->value(1).toInt();
        delete qCashBox;
    } else if (_cycles < c_maxRestartCount) {
        _cycles++;
        LogAppend("GetCashBoxIndexCycle error " + QString::number(_cycles));
        delete qCashBox;
        Init();
        index = GetCashBoxIndexCycle(aIPartner);
    }
    return index;
}

bool DataBaseControl::GetPricesCycle(QString aIPartner, QString &aAgzsName, int &aAgzs, int &aVCode, int &aLink, QDateTime &aCDate, QString &aPartner, double &aDiesel, double &aDiesel_premium,
                                     double &aA80, double &aA92, double &aA92_premium, double &aA95, double &aA95_premium, double &aA98, double &aA98_premium, double &aA100, double &aA100_premium,
                                     double &aPropane, double &aMetan) {
    QSqlQuery* qPrice = new QSqlQuery(_db);
    qPrice->exec("SELECT TOP 1 [AGZSName], [AGZS], [VCode], [Link], [CDate], [Partner], "
            "[diesel], [diesel_premium], [a80], [a92], [a92_premium], [a95], [a95_premium], "
            "[a98],[a98_premium], [a100], [a100_premium], [propane], [metan] "
            "FROM [agzs].[dbo].PR_AGZSPrice "
            "WHERE Link = (SELECT VCode "
                          "FROM [agzs].[dbo].PR_AGZSData "
                          "WHERE AGZS = (SELECT TOP 1 AGZS "
                                        "FROM [agzs].[dbo].[Identification])) "
            "and iPartner = "+aIPartner);
    qPrice->next();
    if (qPrice->lastError().type() == QSqlError::NoError) {
        aAgzsName = qPrice->value(0).toString();
        aAgzs = qPrice->value(1).toInt();
        aVCode = qPrice->value(2).toInt();
        aLink = qPrice->value(3).toInt();
        aCDate = qPrice->value(4).toDateTime();
        aPartner = qPrice->value(5).toString();
        aDiesel = qPrice->value(6).toFloat();
        aDiesel_premium = qPrice->value(7).toFloat();
        aA80 = qPrice->value(8).toFloat();
        aA92 = qPrice->value(9).toFloat();
        aA92_premium = qPrice->value(10).toFloat();
        aA95 = qPrice->value(11).toFloat();
        aA95_premium = qPrice->value(12).toFloat();
        aA98 = qPrice->value(13).toFloat();
        aA98_premium = qPrice->value(14).toFloat();
        aA100 = qPrice->value(15).toFloat();
        aA100_premium = qPrice->value(16).toFloat();
        aPropane = qPrice->value(17).toFloat();
        aMetan = qPrice->value(18).toFloat();
        delete qPrice;
        return true;
    } else {
        delete qPrice;
        Init();
        if (_cycles < c_maxRestartCount) {
            LogAppend("GetPricesCycle error " + QString::number(_cycles));
            _cycles++;
            return GetPricesCycle(aIPartner, aAgzsName, aAgzs, aVCode, aLink, aCDate, aPartner, aDiesel, aDiesel_premium, aA80, aA92, aA92_premium, aA95, aA95_premium, aA98, aA98_premium,
                                  aA100, aA100_premium, aPropane, aMetan);
        } else {
            return false;
        }
    }
}

bool DataBaseControl::GetAgzsDataCycle(QString &aAgzsName, int &aAgzs, QDateTime &aCDate, int &aVCode, QString &aId, QString &aAdress, double &aLoc_x, double &aLoc_y, int &aColumnCount) {
    QSqlQuery* qData = new QSqlQuery(_db);
    qData->exec("SELECT TOP 1 [AGZSName], [AGZS], [CDate], [VCode], [Id], [Adress], "
            "[Location_x], [Location_y], [ColumnsCount] "
            "FROM [agzs].[dbo].[PR_AGZSData] "
            "WHERE AGZS = (SELECT TOP 1 AGZS "
                          "FROM [agzs].[dbo].[Identification]) ");
    qData->next();
    if (qData->lastError().type() == QSqlError::NoError) {
        aAgzsName = qData->value(0).toString();
        aAgzs = qData->value(1).toInt();
        aCDate = qData->value(2).toDateTime();
        aVCode = qData->value(3).toInt();
        aId = qData->value(4).toString();
        aAdress = qData->value(5).toString();
        aLoc_x = qData->value(6).toFloat();
        aLoc_y = qData->value(7).toFloat();
        aColumnCount = qData->value(8).toInt();
        delete qData;
        return true;
    } else {
        delete qData;
        Init();
        if (_cycles < c_maxRestartCount) {
            LogAppend("GetAgzsDataCycle error " + QString::number(_cycles));
            _cycles++;
            return GetAgzsDataCycle(aAgzsName, aAgzs, aCDate, aVCode, aId, aAdress, aLoc_x, aLoc_y, aColumnCount);
        } else {
            return false;
        }
    }
}

bool DataBaseControl::GetAgzsAdastTrkCycle(int aSideAdress, QString &aSide, QString &aDeviceName, QString &aSerial, QString &aDescription,
                                           int &aFuelCode1, int &aFuelCode2, int &aFuelCode3, int &aFuelCode4, int &aFuelCode5,
                                           int &aTrkVCode, int &aPumpPlace, int &aFuel1, int &aFuel2, int &aFuel3, int &aFuel4, int &aFuel5) {
    QSqlQuery *qFuels = new QSqlQuery(_db);
    qFuels->exec("SELECT TOP 1 [DeviceName], [Serial], [Description], "
                 "[SideA_Address], [SideA_Nozzle1FuelCode], [SideA_Nozzle2FuelCode], [SideA_Nozzle3FuelCode], [SideA_Nozzle4FuelCode], [SideA_Nozzle5FuelCode], "
                 "[SideB_Address], [SideB_Nozzle1FuelCode], [SideB_Nozzle2FuelCode], [SideB_Nozzle3FuelCode], [SideB_Nozzle4FuelCode], [SideB_Nozzle5FuelCode], "
                 "[SystemSettings], [CDate], [VCode], "
                 "[SideA_PumpPlace], [SideA_Nozzle1Fuel], [SideA_Nozzle2Fuel], [SideA_Nozzle3Fuel], [SideA_Nozzle4Fuel], [SideA_Nozzle5Fuel], "
                 "[SideB_PumpPlace], [SideB_Nozzle1Fuel], [SideB_Nozzle2Fuel], [SideB_Nozzle3Fuel], [SideB_Nozzle4Fuel], [SideB_Nozzle5Fuel] "
                 "FROM [agzs].[dbo].[ADAST_AdastTRK] "
                 "WHERE ((SideA_Address = " + QString::number(aSideAdress) + ") OR (SideB_Address = " + QString::number(aSideAdress) + ")) "
                        "AND (AGZS = (SELECT TOP 1 AGZS "
                                     "FROM [agzs].[dbo].[Identification]))");
    if (qFuels->lastError().type() == QSqlError::NoError) {
        qFuels->next();
        aDeviceName = qFuels->value(0).toString();
        aSerial = qFuels->value(1).toString();
        aDescription = qFuels->value(2).toString();
        aTrkVCode = qFuels->value(17).toInt();
        if (qFuels->value(3).toInt() == aSideAdress) {
            aSide="A";
            aFuelCode1 = qFuels->value(4).toInt();
            aFuelCode2 = qFuels->value(5).toInt();
            aFuelCode3 = qFuels->value(6).toInt();
            aFuelCode4 = qFuels->value(7).toInt();
            aFuelCode5 = qFuels->value(8).toInt();
            aPumpPlace = qFuels->value(18).toInt();
            aFuel1 = qFuels->value(19).toInt();
            aFuel2 = qFuels->value(20).toInt();
            aFuel3 = qFuels->value(21).toInt();
            aFuel4 = qFuels->value(22).toInt();
            aFuel5 = qFuels->value(23).toInt();
        } else if (qFuels->value(9).toInt() == aSideAdress) {
            aSide="B";
            aFuelCode1 = qFuels->value(10).toInt();
            aFuelCode2 = qFuels->value(11).toInt();
            aFuelCode3 = qFuels->value(12).toInt();
            aFuelCode4 = qFuels->value(13).toInt();
            aFuelCode5 = qFuels->value(14).toInt();
            aPumpPlace = qFuels->value(24).toInt();
            aFuel1 = qFuels->value(25).toInt();
            aFuel2 = qFuels->value(26).toInt();
            aFuel3 = qFuels->value(27).toInt();
            aFuel4 = qFuels->value(28).toInt();
            aFuel5 = qFuels->value(29).toInt();
        }
        delete qFuels;
        return true;
    } else {
        delete qFuels;
        Init();
        if (_cycles < c_maxRestartCount) {
            LogAppend("GetAgzsAdastTrkCycle error " + QString::number(_cycles));
            _cycles++;
            return GetAgzsAdastTrkCycle(aSideAdress, aSide, aDeviceName, aSerial, aDescription, aFuelCode1, aFuelCode2, aFuelCode3, aFuelCode4, aFuelCode5,
                                 aTrkVCode, aPumpPlace, aFuel1, aFuel2, aFuel3, aFuel4, aFuel5);
        } else {
            return false;
        }
    }
}

bool DataBaseControl::createTrkTransactionCycle(QString aAgzsName, int aLocalVCode, QString aTrkType, QString aDeviceName, QString aSerial, QString aFuelName, QString aFuelShortName,
                                     QString aSide, int aSideAdress, int aNozzle, int aTrkFuelCode, QString aTransNum, double aTrkTotalPrice, double aTrkVolume, double aTrkUnitPrice,
                                     double aRequestTotalPrice, double aRequestVolume, double aRequestUnitPrice, QString aRequestField, QString aState, int aIState, QString aTrkTransType,
                                     double aLitersCountBefore, double aMoneyCountBefore, int aTransCountBefore, double aLitersCountAfter, double aMoneyCountAfter, int aTransCountAfter,
                                     QString aResult, QDateTime aDateOpen, QDateTime aDateClose, double aTemperature, int aPayOperationVCode, QString aPayWay, int aPrePostPay,
                                     QString aWUser, QDateTime aWDate, QString aCUser, QDateTime aCDate, QString aCHost, QString aWHost, int aVCode, int aAddedForTransVCode,
                                     int aAditionalTransVCode, int aActive, double aMass, int aSmena, int aTrkVcode, int aCapacityVcode, int aPumpPlace, double aMoneyTaken,
                                     int aIPayWay, int aAutoCheck, int aClosed, int aFullTank, int aAgzs, int aFuelVCode, int aPropan) {
    QSqlQuery *qTransaction = new QSqlQuery(_db);
    qTransaction->prepare("INSERT INTO [agzs].[dbo].[ADAST_TRKTransaction] (AGZSName, LocalVCode, TrkType, DeviceName,	Serial,	FuelName, FuelShortName, Side, SideAddress, Nozzle, "
                   "TrkFuelCode, TransNum, TrkTotalPriceDB, TrkVolumeDB, TrkUnitPriceDB, RequestTotalPriceDB, RequestVolumeDB, RequestUnitPriceDB, RequestField, State, iState, "
                   "TrkTransType, LitersCountBeforeDB, MoneyCountBeforeDB, TransCountBefore, LitersCountAfterDB, MoneyCountAfterDB, TransCountAfter, Result, DateOpen, DateClose, "
                   "TemperatureDB, PayOperationVCode, PayWay, PrePostPay, WUser, WDate, CUser, CDate, CHost, WHost, VCode, AddedForTransVCode, AditionalTransVCode, ActiveDB, "
                   "MassDB, Smena, TrkVcode, CapacityVcode, PumpPlace, MoneyTakenDB, iPayWay, AutoCheckDB, Closed, FullTankDB, AGZS, FuelVCode, rowguid, Propan) "
                   "VALUES(:AGZSName, :LocalVCode, :TrkType, :DeviceName, :Serial, :FuelName, :FuelShortName, :Side, :SideAddress, :Nozzle, :TrkFuelCode, :TransNum, "
                   ":TrkTotalPriceDB, :TrkVolumeDB, :TrkUnitPriceDB, :RequestTotalPriceDB, :RequestVolumeDB, :RequestUnitPriceDB, :RequestField, :State, :iState, :TrkTransType, "
                   ":LitersCountBeforeDB, :MoneyCountBeforeDB, :TransCountBefore, :LitersCountAfterDB, :MoneyCountAfterDB, :TransCountAfter, :Result, :DateOpen, :DateClose, "
                   ":TemperatureDB, :PayOperationVCode, :PayWay, :PrePostPay, :WUser, :WDate, :CUser, :CDate, :CHost, :WHost, :VCode, :AddedForTransVCode, :AditionalTransVCode, "
                   ":ActiveDB, :MassDB, :Smena, :TrkVcode, :CapacityVcode, :PumpPlace, :MoneyTakenDB, :iPayWay, :AutoCheckDB, :Closed, :FullTankDB, :AGZS, :FuelVCode, DEFAULT, "
                   ":Propan)");
    qTransaction->bindValue(":AGZSName", aAgzsName);
    qTransaction->bindValue(":LocalVCode", aLocalVCode);
    qTransaction->bindValue(":TrkType", aTrkType);
    qTransaction->bindValue(":DeviceName", aDeviceName);
    qTransaction->bindValue(":Serial", aSerial);
    qTransaction->bindValue(":FuelName", aFuelName);
    qTransaction->bindValue(":FuelShortName", aFuelShortName);
    qTransaction->bindValue(":Side", aSide);
    qTransaction->bindValue(":SideAddress", aSideAdress);
    qTransaction->bindValue(":Nozzle", aNozzle);
    qTransaction->bindValue(":TrkFuelCode", aTrkFuelCode);
    qTransaction->bindValue(":TransNum", aTransNum);
    qTransaction->bindValue(":TrkTotalPriceDB", aTrkTotalPrice);
    qTransaction->bindValue(":TrkVolumeDB", aTrkVolume);
    qTransaction->bindValue(":TrkUnitPriceDB", aTrkUnitPrice);
    qTransaction->bindValue(":RequestTotalPriceDB", aRequestTotalPrice);
    qTransaction->bindValue(":RequestVolumeDB", aRequestVolume);
    qTransaction->bindValue(":RequestUnitPriceDB", aRequestUnitPrice);
    qTransaction->bindValue(":RequestField", aRequestField);
    qTransaction->bindValue(":State", aState);
    qTransaction->bindValue(":iState", aIState);
    qTransaction->bindValue(":TrkTransType", aTrkTransType);
    qTransaction->bindValue(":LitersCountBeforeDB", aLitersCountBefore);
    qTransaction->bindValue(":MoneyCountBeforeDB", aMoneyCountBefore);
    qTransaction->bindValue(":TransCountBefore", aTransCountBefore);
    qTransaction->bindValue(":LitersCountAfterDB", aLitersCountAfter);
    qTransaction->bindValue(":MoneyCountAfterDB", aMoneyCountAfter);
    qTransaction->bindValue(":TransCountAfter", aTransCountAfter);
    qTransaction->bindValue(":Result", aResult);
    qTransaction->bindValue(":DateOpen", aDateOpen.toString("yyyyMMdd hh:mm:ss.zzz"));
    qTransaction->bindValue(":DateClose", aDateClose.toString("yyyyMMdd hh:mm:ss.zzz"));
    qTransaction->bindValue(":TemperatureDB", aTemperature);
    qTransaction->bindValue(":PayOperationVCode", aPayOperationVCode);
    qTransaction->bindValue(":PayWay", aPayWay);
    qTransaction->bindValue(":PrePostPay", aPrePostPay);
    qTransaction->bindValue(":WUser", aWUser);
    qTransaction->bindValue(":WDate", aWDate.toString("yyyyMMdd hh:mm:ss.zzz"));
    qTransaction->bindValue(":CUser", aCUser);
    qTransaction->bindValue(":CDate", aCDate.toString("yyyyMMdd hh:mm:ss.zzz"));
    qTransaction->bindValue(":CHost", aCHost);
    qTransaction->bindValue(":WHost", aWHost);
    qTransaction->bindValue(":VCode", aVCode);
    qTransaction->bindValue(":AddedForTransVCode", aAddedForTransVCode);
    qTransaction->bindValue(":AditionalTransVCode", aAditionalTransVCode);
    qTransaction->bindValue(":ActiveDB", aActive);
    qTransaction->bindValue(":MassDB", aMass);
    qTransaction->bindValue(":Smena", aSmena);
    qTransaction->bindValue(":TrkVcode", aTrkVcode);
    qTransaction->bindValue(":CapacityVcode", aCapacityVcode);
    qTransaction->bindValue(":PumpPlace", aPumpPlace);
    qTransaction->bindValue(":MoneyTakenDB", aMoneyTaken);
    qTransaction->bindValue(":iPayWay", aIPayWay);
    qTransaction->bindValue(":AutoCheckDB", aAutoCheck);
    qTransaction->bindValue(":Closed", aClosed);
    qTransaction->bindValue(":FullTankDB", aFullTank);
    qTransaction->bindValue(":AGZS", aAgzs);
    qTransaction->bindValue(":FuelVCode", aFuelVCode);
    qTransaction->bindValue(":Propan", aPropan);
    qTransaction->exec();
    if (qTransaction->lastError().type() == QSqlError::NoError) {
        delete qTransaction;
        return true;
    } else {
        delete qTransaction;
        Init();
        if (_cycles < c_maxRestartCount) {
            LogAppend("createTrkTransactionCycle error " + QString::number(_cycles));
            _cycles++;
            return createTrkTransactionCycle(aAgzsName, aLocalVCode, aTrkType, aDeviceName, aSerial, aFuelName, aFuelShortName,
                                             aSide, aSideAdress, aNozzle, aTrkFuelCode, aTransNum, aTrkTotalPrice, aTrkVolume, aTrkUnitPrice,
                                             aRequestTotalPrice, aRequestVolume, aRequestUnitPrice, aRequestField, aState, aIState, aTrkTransType,
                                             aLitersCountBefore, aMoneyCountBefore, aTransCountBefore, aLitersCountAfter, aMoneyCountAfter, aTransCountAfter,
                                             aResult, aDateOpen, aDateClose, aTemperature, aPayOperationVCode, aPayWay, aPrePostPay,
                                             aWUser, aWDate, aCUser, aCDate, aCHost, aWHost, aVCode, aAddedForTransVCode,
                                             aAditionalTransVCode, aActive, aMass, aSmena, aTrkVcode, aCapacityVcode, aPumpPlace, aMoneyTaken,
                                             aIPayWay, aAutoCheck, aClosed, aFullTank, aAgzs, aFuelVCode, aPropan);
        } else {
            return false;
        }
    }
}

bool DataBaseControl::createApiTransactionCycle(QString aAgzsName, int aAgzs, QDateTime aCDate, int aVCode, QString aApiId, QString aApiStationExtendedId,
                                     int aApiColumnId, QString aApiFuelId, int aFuelId, int aApiPriceFuel, int aApiLitre, int aApiSum, QString aApiStatus,
                                     QString aApiContractId, QString aAgent, QString aLocalState, double aPrice, double aLitre, double aSum, QDateTime aDateOpen, int aLink) {
    QSqlQuery *qApiRequests = new QSqlQuery(_db);
    qApiRequests->prepare("INSERT INTO [agzs].[dbo].[PR_APITransaction] ([AGZSName],[AGZS],[CDate],[VCode],[APIID],[APIStationExtendedId],[APIColumnId],[APIFuelId],[FuelId],"
                "[APIPriceFuel],[APILitre],[APISum],[APIStatus],[APIContractId],[agent],[localState],[Price],[Litre],[Sum],[DateOpen],[DateClose],[Link]) "
                "VALUES (:AGZSName, :AGZS, :CDate, :VCode, :APIID, :APIStationExtendedId, :APIColumnId, :APIFuelId, :FuelId, :APIPriceFuel, :APILitre, :APISum, "
                ":APIStatus, :APIContractId, :agent, :localState, :Price, :Litre, :Sum, :DateOpen, DEFAULT, :Link)");
    qApiRequests->bindValue(":AGZSName", aAgzsName);
    qApiRequests->bindValue(":AGZS", aAgzs);
    qApiRequests->bindValue(":CDate", aCDate.toString("yyyyMMdd hh:mm:ss.zzz"));
    qApiRequests->bindValue(":VCode", aVCode);
    qApiRequests->bindValue(":APIID", aApiId);
    qApiRequests->bindValue(":APIStationExtendedId", aApiStationExtendedId);
    qApiRequests->bindValue(":APIColumnId", aApiColumnId);
    qApiRequests->bindValue(":APIFuelId", aApiFuelId);
    qApiRequests->bindValue(":FuelId", aFuelId);
    qApiRequests->bindValue(":APIPriceFuel", aApiPriceFuel);
    qApiRequests->bindValue(":APILitre", aApiLitre);
    qApiRequests->bindValue(":APISum", aApiSum);
    qApiRequests->bindValue(":APIStatus", aApiStatus);
    qApiRequests->bindValue(":APIContractId", aApiContractId);
    qApiRequests->bindValue(":agent", aAgent);
    qApiRequests->bindValue(":localState", aLocalState);
    qApiRequests->bindValue(":Price", aPrice);
    qApiRequests->bindValue(":Litre", aLitre);
    qApiRequests->bindValue(":Sum", aSum);
    qApiRequests->bindValue(":DateOpen", aDateOpen.toString("yyyyMMdd hh:mm:ss.zzz"));
    //q_APIRequests->bindValue(":DateClose", "DEFAULT");
    qApiRequests->bindValue(":Link", aLink);
    qApiRequests->exec();
    if (qApiRequests->lastError().type() == QSqlError::NoError) {
        delete qApiRequests;
        return true;
    } else if (_cycles < c_maxRestartCount) {
        LogAppend("createApiTransactionCycle error " + QString::number(_cycles));
        _cycles++;
        delete qApiRequests;
        Init();
        return createApiTransactionCycle(aAgzsName, aAgzs, aCDate, aVCode, aApiId, aApiStationExtendedId,
                                         aApiColumnId, aApiFuelId, aFuelId, aApiPriceFuel, aApiLitre, aApiSum, aApiStatus,
                                         aApiContractId, aAgent, aLocalState, aPrice, aLitre, aSum, aDateOpen, aLink);
    } else {
        delete qApiRequests;
        Init();
        return false;
    }
}

bool DataBaseControl::getApiTransactionStateCycle(QString aId, QString &aLocalState, int &aApiVCode, int &aHeadVCode, int &aIState, QDateTime aDateOpen, QDateTime &aDateClose) {
    QSqlQuery* qRequests = new QSqlQuery(_db);
    qRequests->exec("SELECT api.localState, api.VCode, h.VCode, b.iState, b.DateOpen, b.DateClose "
                "FROM [agzs].[dbo].[PR_APITransaction] api "
                "INNER JOIN [agzs].[dbo].[ADAST_TRKTransaction] h ON api.Link = h.VCode "
                "INNER JOIN [agzs].[dbo].[ADAST_TRKTransaction] b ON h.AditionalTransVCode = b.VCode "
                "WHERE api.APIID = '" + aId + "'");
    if (qRequests->lastError().type() == QSqlError::NoError) {
        while (qRequests->next()){
            aLocalState = qRequests->value(0).toString();
            aApiVCode = qRequests->value(1).toInt();
            aHeadVCode = qRequests->value(2).toInt();
            aIState = qRequests->value(3).toInt();
            aDateOpen = qRequests->value(4).toDateTime();
            aDateClose = qRequests->value(5).toDateTime();
            break;
        }
        delete qRequests;
        return true;
    } else {
        delete qRequests;
        Init();
        if (_cycles < c_maxRestartCount) {
            LogAppend("getApiTransactionStateCycle error " + QString::number(_cycles));
            _cycles++;
            return getApiTransactionStateCycle(aId, aLocalState, aApiVCode, aHeadVCode, aIState, aDateOpen, aDateClose);
        } else {
            return false;
        }
    }
}

bool DataBaseControl::updateApiTransactionStateCycle(QString aLocalState, QDateTime aDateClose, int aVCode) {
    QSqlQuery* qApiUpdate = new QSqlQuery(_db);
    qApiUpdate->prepare("UPDATE [agzs].[dbo].[PR_APITransaction] "
                         "SET localState = :localState, DateClose = :date "
                         "WHERE VCode = :VCode");
    qApiUpdate->bindValue(":localState",aLocalState);
    qApiUpdate->bindValue(":date",aDateClose);
    qApiUpdate->bindValue(":VCode",aVCode);
    qApiUpdate->exec();
    if (qApiUpdate->lastError().type() == QSqlError::NoError) {
        delete qApiUpdate;
        return true;
    } else {
        delete qApiUpdate;
        Init();
        if (_cycles < c_maxRestartCount) {
            LogAppend("updateApiTransactionStateCycle error " + QString::number(_cycles));
            _cycles++;
            return updateApiTransactionStateCycle(aLocalState, aDateClose, aVCode);
        } else {
            return false;
        }
    }
}

bool DataBaseControl::finalUpdateApiTransactionStateCycle(QString aLocalState, double aPrice, double aVolume, double aAmount, QDateTime aDateOpen, QDateTime aDateClose, int aVCode) {
    QSqlQuery* qApiUpdate = new QSqlQuery(_db);
    qApiUpdate->prepare("UPDATE [agzs].[dbo].[PR_APITransaction] "
                        "SET localState = :localState, "
                           "[Price] = :price, "
                           "[Litre] = :litre, "
                           "[Sum] = :sum, "
                           "[DateOpen] = :dateOpen, "
                           "DateClose = :dateClose "
                        "WHERE VCode = :VCode");
    qApiUpdate->bindValue(":localState", aLocalState);
    qApiUpdate->bindValue(":price", aPrice);
    qApiUpdate->bindValue(":litre", aVolume);
    qApiUpdate->bindValue(":sum", aAmount);
    qApiUpdate->bindValue(":dateOpen", aDateOpen);
    qApiUpdate->bindValue(":dateClose", aDateClose);
    qApiUpdate->bindValue(":VCode", aVCode);
    qApiUpdate->exec();
    if (qApiUpdate->lastError().type() == QSqlError::NoError) {
        delete qApiUpdate;
        return true;
    } else {
        delete qApiUpdate;
        Init();
        if (_cycles < c_maxRestartCount) {
            LogAppend("finalUpdateApiTransactionStateCycle error " + QString::number(_cycles));
            _cycles++;
            return finalUpdateApiTransactionStateCycle(aLocalState, aPrice, aVolume, aAmount, aDateOpen, aDateClose, aVCode);
        } else {
            return false;
        }
    }
}

bool DataBaseControl::getPayOperationLitersCycle(int aLink, double &aAmount, double &aVolume, double &aPrice) {
    QSqlQuery *qPayOperation = new QSqlQuery(_db);
    qPayOperation->exec("SELECT [AmountDB], [PriceDB], [VolumeDB] "
                         "FROM [agzs].[dbo].[ARM_PayOperation] "
                         "WHERE Link = " + QString::number(aLink));
    if (qPayOperation->lastError().type() == QSqlError::NoError) {
        qPayOperation->next();
        aAmount = qPayOperation->value(0).toFloat();
        aVolume = qPayOperation->value(2).toFloat();
        aPrice = qPayOperation->value(1).toFloat();
        delete qPayOperation;
        return true;
    } else {
        delete qPayOperation;
        Init();
        if (_cycles < c_maxRestartCount) {
            LogAppend("getPayOperationLitersCycle error " + QString::number(_cycles));
            _cycles++;
            return getPayOperationLitersCycle(aLink, aAmount, aVolume, aPrice);
        } else {
            return false;
        }
    }
}

bool DataBaseControl::setTransactionClosedCycle(QString aId, int aClosed) {
    QSqlQuery *qUpdate = new QSqlQuery(_db);
    qUpdate->prepare("UPDATE [agzs].[dbo].[ADAST_TRKTransaction] "
                         "SET Closed = :closed "
                         "WHERE VCode = (SELECT Link "
                                        "FROM [agzs].[dbo].[PR_APITransaction] "
                                        "WHERE ApiId = :id)");
    qUpdate->bindValue(":closed", aClosed);
    qUpdate->bindValue(":id", aId);
    qUpdate->exec();
    if (qUpdate->lastError().type() == QSqlError::NoError) {
        delete qUpdate;
        return true;
    } else {
        delete qUpdate;
        Init();
        if (_cycles < c_maxRestartCount) {
            LogAppend("setTransactionClosedCycle error " + QString::number(_cycles));
            _cycles++;
            return setTransactionClosedCycle(aId, aClosed);
        } else {
            return false;
        }
    }
}
#define CycleEnd }

int DataBaseControl::GetCurrentAgzs() {
    QSqlQuery* qData = new QSqlQuery(_db);
    qData->exec("SELECT TOP 1 AGZS "
                "FROM [agzs].[dbo].[Identification] ");
    qData->next();
    int agzs = qData->value(0).toInt();
    delete qData;
    return agzs;
}

bool DataBaseControl::UpdateApiTransaction(int aLocalState, QDateTime aDate, int aVCode) {
    QSqlQuery *qApiUpdate = new QSqlQuery(_db);
        qApiUpdate->prepare("UPDATE [agzs].[dbo].[PR_APITransaction] "
                             "SET localState = :localState, DateClose = :date "
                             "WHERE VCode = :VCode");
        qApiUpdate->bindValue(":localState",aLocalState);
        qApiUpdate->bindValue(":date",aDate);
        qApiUpdate->bindValue(":VCode",aVCode);
        qApiUpdate->exec();
    if (qApiUpdate->lastError().type() == QSqlError::NoError) {
        delete qApiUpdate;
        return true;
    } else {
        delete qApiUpdate;
        Init();
        return false;
    }
}

int DataBaseControl::GetLastVCode(QString aKey, bool aUpdate) {
    QSqlQuery *qLastVCode = new QSqlQuery(_db);
        qLastVCode->exec("SELECT TOP 1 Value "
                            "FROM [agzs].[dbo].[LxKeysOfCodes] "
                            "WHERE [Key] = '" + aKey + "'");
        qLastVCode->next();
    if (qLastVCode->lastError().type() == QSqlError::NoError) {
        int vcode = qLastVCode->value(0).toInt();
        if (aUpdate) {
            qLastVCode->exec("UPDATE [agzs].[dbo].[LxKeysOfCodes] "
                             "SET Value = Value + 1"
                             "WHERE [Key] = '" + aKey + "'");
        }
        delete qLastVCode;
        return vcode;
    } else {
        delete qLastVCode;
        Init();
        return 0;
    }
}

int DataBaseControl::CheckError(QString aColumnID, QString aFuelID, int aiFuelID, QString aPriceFuel) {
    QSqlQuery *qCheck = new QSqlQuery(_db);
    qCheck->exec("SELECT c.AGZSName, c.AGZS, d.VCode, d.Id, c.[FuelName], c.[FuelShortName], c.[Side], c.[SideAdress], c.[Nozzle], "
                    "c.[TrkFuelCode], c.[TrkVCode] "
                  "FROM [agzs].[dbo].PR_AGZSData d "
                    "INNER JOIN [agzs].[dbo].PR_AGZSColumns c "
                    "ON d.VCode = c.Link "
                  "WHERE d.AGZS = (SELECT TOP 1 AGZS "
                                  "FROM [agzs].[dbo].[Identification]) "
                    "and c.SideAdress = " + aColumnID + " "
                  "ORDER BY d.CDate DESC");
    if (qCheck->size() == 0) {
        delete qCheck;
        return 1;
    }
    qCheck->exec("SELECT c.AGZSName, c.AGZS, d.VCode, d.Id, c.[FuelName], c.[FuelShortName], c.[Side], c.[SideAdress], c.[Nozzle], "
                    "c.[TrkFuelCode], c.[TrkVCode] "
                  "FROM [agzs].[dbo].PR_AGZSData d "
                    "INNER JOIN [agzs].[dbo].PR_AGZSColumns c "
                    "ON d.VCode = c.Link "
                  "WHERE d.AGZS = (SELECT TOP 1 AGZS "
                                  "FROM [agzs].[dbo].[Identification]) "
                    "and c.SideAdress = " + aColumnID + " "
                    "and c.FuelVCode = " + QString::number(aiFuelID) + " "
                  "ORDER BY d.CDate DESC");
    if (qCheck->size() == 0) {
        delete qCheck;
        return 2;
    }
    qCheck->exec("SELECT c.AGZSName, c.AGZS, d.VCode, d.Id, c.[FuelName], c.[FuelShortName], c.[Side], c.[SideAdress], c.[Nozzle], "
                    "c.[TrkFuelCode], c.[TrkVCode], p.[" + aFuelID + "] "
                "FROM [agzs].[dbo].PR_AGZSData d "
                     "INNER JOIN [agzs].[dbo].PR_AGZSColumns c "
                     "ON d.VCode = c.Link "
                     "INNER JOIN [agzs].[dbo].PR_AGZSPrice p "
                     "ON d.VCode = p.Link "
                "WHERE d.AGZS = (SELECT TOP 1 AGZS "
                                "FROM [agzs].[dbo].[Identification]) "
                    "and c.SideAdress = " + aColumnID + " "
                    "and c.FuelVCode = " + QString::number(aiFuelID) + " "
                    "and p.[" + aFuelID + "]=" + aPriceFuel + " "
                "ORDER BY d.CDate DESC");
    if (qCheck->size() == 0) {
        delete qCheck;
        return 3;
    }
    delete qCheck;
    return 0;
}
