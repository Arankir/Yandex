#include "databasecontrol.h"

const QString c_settingPath = "Setting.txt";
const QString c_logPath = "Log.txt";

const int c_maxRestartCount = 7;

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
    while(!init());
}

bool DataBaseControl::init() {
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
            logAppend("Error: setting file is already open");
            return false;
        }
    } else {
        logAppend("Error: setting file not found");
        return false;
    }
    qDebug()<<setting;
    _reestr.setValue("ordersLog",    setting.size() > 4 ? setting[4] == "true" : false);
    _reestr.setValue("agzsPriceLog", setting.size() > 3 ? setting[3] == "true" : false);
    _reestr.setValue("agzsDataLog",  setting.size() > 2 ? setting[2] == "true" : false);
    _reestr.setValue("isTest",       setting.size() > 1 ? setting[1] == "Test" : false);
    if (setting.size() > 0) {
        _db.setDatabaseName(QString("DRIVER={SQL Server};"
                                    "SERVER=%1;"
                                    "DATABASE=agzs;"
                                    "Persist Security Info=true;"
                                    "uid=sa;"
                                    "pwd=Gfhf743Djpbr").arg(setting[0]));
        return openDB();
    }
    return false;
}

bool DataBaseControl::openDB() {
    if (_db.open()) {
        QString cityMobileToken = "";

        QSqlQuery query(_db);
        query.exec("SELECT TOP 1 [CityMobileToken] "
                "FROM [agzs].[dbo].[PR_AGZSData] "
                "WHERE AGZS = (SELECT TOP 1 AGZS "
                              "FROM [agzs].[dbo].[Identification]) ");
        if (query.next()) {
            cityMobileToken = query.value(0).toString();
        }
        _reestr.setValue("CityMobile Token", cityMobileToken);
        logAppend("DB open");
        return true;
    } else {
        logAppend("DB close");
        return false;
    }
}

bool DataBaseControl::logAppend(QString aMessage) {
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

bool DataBaseControl::getFuelNames(int aFuelId, QString &aFullName, QString &aShortName) {
    int cycles = 0;
    while (cycles < c_maxRestartCount) {
        QSqlQuery query(_db);
        query.exec("SELECT TOP 1 [FuelName], [FuelShortName] "
                   "FROM [agzs].[dbo].[Interface_FuelParams] "
                   "WHERE [Fuel] = " + QString::number(aFuelId));
        if (query.next()) {
            aFullName = query.value(0).toString();
            aShortName = query.value(1).toString();
            return true;
        } else {
            openDB();
            logAppend("GetFuelNames error " + QString::number(cycles));
        }
        cycles++;
    }
    return false;
}

bool DataBaseControl::getFuels(QVector<QPair<int, QVector<int>>> &aFuels) {
    int cycles = 0;
    while (cycles < c_maxRestartCount) {
        QSqlQuery qFuels(_db);
        qFuels.exec("SELECT columnn.SideAdress, columnn.[Partner_TrkNum], columnn.Nozzle1Fuel, columnn.Nozzle2Fuel, columnn.Nozzle3Fuel, columnn.Nozzle4Fuel, columnn.Nozzle5Fuel "
                    "FROM [agzs].[dbo].[PR_Columns] columnn "
                    "INNER JOIN [agzs].[dbo].[ADAST_AdastTRK] trk ON ((columnn.SideAdress = trk.[SideA_Address]) OR (columnn.SideAdress = trk.[SideB_Address])) "
                    "WHERE columnn.agzs = (SELECT TOP 1 AGZS "
                                          "FROM [agzs].[dbo].[Identification]) "
                     "AND trk.agzs = columnn.agzs "
                     "AND columnn.visible = 1 ");
        if (qFuels.lastError().type() == QSqlError::NoError) {
            while (qFuels.next()) {
                if (qFuels.value(0).toInt() > 0) {
                    QVector<int> fuelsLocalA;
                    if (!qFuels.value(2).isNull()) {
                        fuelsLocalA.append(qFuels.value(2).toInt());
                    }
                    if (!qFuels.value(3).isNull()) {
                        fuelsLocalA.append(qFuels.value(3).toInt());
                    }
                    if (!qFuels.value(4).isNull()) {
                        fuelsLocalA.append(qFuels.value(4).toInt());
                    }
                    if (!qFuels.value(5).isNull()) {
                        fuelsLocalA.append(qFuels.value(5).toInt());
                    }
                    if (!qFuels.value(6).isNull()) {
                        fuelsLocalA.append(qFuels.value(6).toInt());
                    }
                    aFuels.append(QPair<int, QVector<int>>(qFuels.value(1).toInt(), fuelsLocalA));
                }
            }
            return true;
        } else {
            openDB();
            logAppend("GetFuels error " + QString::number(cycles));
        }
        cycles++;
    }
    return false;
}

int DataBaseControl::getRealSideAddress(int aAgzs, int aPartnerSideAddress) {
    int cycles = 0;
    while (cycles < c_maxRestartCount) {
        QSqlQuery query(_db);
        query.exec("SELECT TOP 1 [SideAdress] "
                   "FROM [agzs].[dbo].[PR_Columns] "
                   "WHERE agzs = " + QString::number(aAgzs) + " "
                     "AND [Partner_TrkNum] = " + QString::number(aPartnerSideAddress) + " "
                   "ORDER BY CDate DESC");
        if (query.next()) {
            return query.value(0).toInt();
        } else {
            openDB();
            logAppend("getRealSideAddress error " + QString::number(cycles));
        }
        cycles++;
    }
    return 0;
}

int DataBaseControl::getSmena() {
    int cycles = 0;
    while (cycles < c_maxRestartCount) {
        QSqlQuery query(_db);
        query.exec("SELECT TOP 1 VCode "
                   "FROM [agzs].[dbo].[ARM_Smena] "
                   "ORDER BY CDate DESC");
        if (query.next()) {
            return query.value(0).toInt();
        } else {
            openDB();
            logAppend("GetSmena error " + QString::number(cycles));
        }
        cycles++;
    }
    return 0;
}

int DataBaseControl::getCashBoxIndex(QString aIPartner) {
    int cycles = 0;
    while (cycles < c_maxRestartCount) {
        QSqlQuery query(_db);
        query.exec("SELECT TOP 1 CashBoxIndex, PayIndex, PayWay, AutoCheck FROM [agzs].[dbo].[ARM_CashBoxesSemaphor] "
                   "WHERE PayIndex = " + aIPartner + " and AutoCheck = 0 "
                   "ORDER BY CDate DESC");
        if (query.next()) {
            return query.value(1).toInt();
        } else {
            openDB();
            logAppend("GetCashBoxIndex error " + QString::number(cycles));
        }
        cycles++;
    }
    return 0;
}

bool DataBaseControl::getPrices(QString aIPartner, QString &aAgzsName, int &aAgzs, int &aVCode, int &aLink, QDateTime &aCDate, QString &aPartner,
                                double &aDiesel, double &aDiesel_premium, double &aA80, double &aA92, double &aA92_premium, double &aA95, double &aA95_premium, double &aA98,
                                double &aA98_premium, double &aA100, double &aA100_premium, double &aPropane, double &aMetan) {
    int cycles = 0;
    while (cycles < c_maxRestartCount) {
        QSqlQuery query(_db);
        query.exec("SELECT TOP 1 [AGZSName], [AGZS], [VCode], [Link], [CDate], [Partner], "
                    "[diesel], [diesel_premium], [a80], [a92], [a92_premium], [a95], [a95_premium], "
                    "[a98],[a98_premium], [a100], [a100_premium], [propane], [metan] "
                    "FROM [agzs].[dbo].PR_AGZSPrice "
                   "WHERE Link = (SELECT VCode "
                                 "FROM [agzs].[dbo].PR_AGZSData "
                                 "WHERE AGZS = (SELECT TOP 1 AGZS "
                                               "FROM [agzs].[dbo].[Identification])) "
                   "and iPartner = " + aIPartner);
        if (query.next()) {
            aAgzsName = query.value(0).toString();
            aAgzs = query.value(1).toInt();
            aVCode = query.value(2).toInt();
            aLink = query.value(3).toInt();
            aCDate = query.value(4).toDateTime();
            aPartner = query.value(5).toString();
            aDiesel = query.value(6).toFloat();
            aDiesel_premium = query.value(7).toFloat();
            aA80 = query.value(8).toFloat();
            aA92 = query.value(9).toFloat();
            aA92_premium = query.value(10).toFloat();
            aA95 = query.value(11).toFloat();
            aA95_premium = query.value(12).toFloat();
            aA98 = query.value(13).toFloat();
            aA98_premium = query.value(14).toFloat();
            aA100 = query.value(15).toFloat();
            aA100_premium = query.value(16).toFloat();
            aPropane = query.value(17).toFloat();
            aMetan = query.value(18).toFloat();
            return true;
        } else {
            openDB();
            logAppend("GetPrices error " + QString::number(cycles));
        }
        cycles++;
    }
    return false;
}

bool DataBaseControl::getAgzsData(QString &aAgzsName, int &aAgzs, QDateTime &aCDate, int &aVCode, QString &aId, QString &aAdress, double &aLat, double &aLon, int &aColumnCount) {
    int cycles = 0;
    while (cycles < c_maxRestartCount) {
        QSqlQuery query(_db);
        query.exec("SELECT TOP 1 [AGZSName], [AGZS], [CDate], [VCode], [Id], [Adress], "
                    "[latitude], [longitude], [ColumnsCount] "
                    "FROM [agzs].[dbo].[PR_AGZSData] "
                   "WHERE AGZS = (SELECT TOP 1 AGZS "
                                 "FROM [agzs].[dbo].[Identification]) ");
        if (query.next()) {
            aAgzsName = query.value(0).toString();
            aAgzs = query.value(1).toInt();
            aCDate = query.value(2).toDateTime();
            aVCode = query.value(3).toInt();
            aId = query.value(4).toString();
            aAdress = query.value(5).toString();
            aLat = query.value(6).toFloat();
            aLon = query.value(7).toFloat();
            aColumnCount = query.value(8).toInt();
            return true;
        } else {
            openDB();
            logAppend("GetAgzsData error " + QString::number(cycles));
        }
        cycles++;
    }
    return false;
}

bool DataBaseControl::getAgzsAdastTrk(int aSideAdress, QString &aSide, QString &aDeviceName, QString &aSerial, QString &aDescription,
                                      int &aFuelCode1, int &aFuelCode2, int &aFuelCode3, int &aFuelCode4, int &aFuelCode5,
                                      int &aTrkVCode, int &aPumpPlace, int &aFuel1, int &aFuel2, int &aFuel3, int &aFuel4, int &aFuel5) {
    int cycles = 0;
    while (cycles < c_maxRestartCount) {
        QSqlQuery query(_db);
        query.exec("SELECT TOP 1 [DeviceName], [Serial], [Description], "
                     "[SideA_Address], [SideA_Nozzle1FuelCode], [SideA_Nozzle2FuelCode], [SideA_Nozzle3FuelCode], [SideA_Nozzle4FuelCode], [SideA_Nozzle5FuelCode], "
                     "[SideB_Address], [SideB_Nozzle1FuelCode], [SideB_Nozzle2FuelCode], [SideB_Nozzle3FuelCode], [SideB_Nozzle4FuelCode], [SideB_Nozzle5FuelCode], "
                     "[SystemSettings], [CDate], [VCode], "
                     "[SideA_PumpPlace], [SideA_Nozzle1Fuel], [SideA_Nozzle2Fuel], [SideA_Nozzle3Fuel], [SideA_Nozzle4Fuel], [SideA_Nozzle5Fuel], "
                     "[SideB_PumpPlace], [SideB_Nozzle1Fuel], [SideB_Nozzle2Fuel], [SideB_Nozzle3Fuel], [SideB_Nozzle4Fuel], [SideB_Nozzle5Fuel] "
                    "FROM [agzs].[dbo].[ADAST_AdastTRK] "
                    "WHERE ((SideA_Address = " + QString::number(aSideAdress) + ") OR (SideB_Address = " + QString::number(aSideAdress) + ")) "
                            "AND (AGZS = (SELECT TOP 1 AGZS "
                                         "FROM [agzs].[dbo].[Identification]))");
        if (query.next()) {
            aDeviceName = query.value(0).toString();
            aSerial = query.value(1).toString();
            aDescription = query.value(2).toString();
            aTrkVCode = query.value(17).toInt();
            if (query.value(3).toInt() == aSideAdress) {
                aSide="A";
                aFuelCode1 = query.value(4).toInt();
                aFuelCode2 = query.value(5).toInt();
                aFuelCode3 = query.value(6).toInt();
                aFuelCode4 = query.value(7).toInt();
                aFuelCode5 = query.value(8).toInt();
                aPumpPlace = query.value(18).toInt();
                aFuel1 = query.value(19).toInt();
                aFuel2 = query.value(20).toInt();
                aFuel3 = query.value(21).toInt();
                aFuel4 = query.value(22).toInt();
                aFuel5 = query.value(23).toInt();
            } else if (query.value(9).toInt() == aSideAdress) {
                aSide="B";
                aFuelCode1 = query.value(10).toInt();
                aFuelCode2 = query.value(11).toInt();
                aFuelCode3 = query.value(12).toInt();
                aFuelCode4 = query.value(13).toInt();
                aFuelCode5 = query.value(14).toInt();
                aPumpPlace = query.value(24).toInt();
                aFuel1 = query.value(25).toInt();
                aFuel2 = query.value(26).toInt();
                aFuel3 = query.value(27).toInt();
                aFuel4 = query.value(28).toInt();
                aFuel5 = query.value(29).toInt();
            }
            return true;
        } else {
            openDB();
            logAppend("GetAgzsAdastTrk error " + QString::number(cycles));
        }
        cycles++;
    }
    return false;
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
    int cycles = 0;
    while (cycles < c_maxRestartCount) {
        QSqlQuery query(_db);
        query.prepare("INSERT INTO [agzs].[dbo].[ADAST_TRKTransaction] (AGZSName, LocalVCode, TrkType, DeviceName,	Serial,	FuelName, FuelShortName, Side, SideAddress, Nozzle, "
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
        query.bindValue(":AGZSName", aAgzsName);
        query.bindValue(":LocalVCode", aLocalVCode);
        query.bindValue(":TrkType", aTrkType);
        query.bindValue(":DeviceName", aDeviceName);
        query.bindValue(":Serial", aSerial);
        query.bindValue(":FuelName", aFuelName);
        query.bindValue(":FuelShortName", aFuelShortName);
        query.bindValue(":Side", aSide);
        query.bindValue(":SideAddress", aSideAdress);
        query.bindValue(":Nozzle", aNozzle);
        query.bindValue(":TrkFuelCode", aTrkFuelCode);
        query.bindValue(":TransNum", aTransNum);
        query.bindValue(":TrkTotalPriceDB", aTrkTotalPrice);
        query.bindValue(":TrkVolumeDB", aTrkVolume);
        query.bindValue(":TrkUnitPriceDB", aTrkUnitPrice);
        query.bindValue(":RequestTotalPriceDB", aRequestTotalPrice);
        query.bindValue(":RequestVolumeDB", aRequestVolume);
        query.bindValue(":RequestUnitPriceDB", aRequestUnitPrice);
        query.bindValue(":RequestField", aRequestField);
        query.bindValue(":State", aState);
        query.bindValue(":iState", aIState);
        query.bindValue(":TrkTransType", aTrkTransType);
        query.bindValue(":LitersCountBeforeDB", aLitersCountBefore);
        query.bindValue(":MoneyCountBeforeDB", aMoneyCountBefore);
        query.bindValue(":TransCountBefore", aTransCountBefore);
        query.bindValue(":LitersCountAfterDB", aLitersCountAfter);
        query.bindValue(":MoneyCountAfterDB", aMoneyCountAfter);
        query.bindValue(":TransCountAfter", aTransCountAfter);
        query.bindValue(":Result", aResult);
        query.bindValue(":DateOpen", aDateOpen.toString("yyyyMMdd hh:mm:ss.zzz"));
        query.bindValue(":DateClose", aDateClose.toString("yyyyMMdd hh:mm:ss.zzz"));
        query.bindValue(":TemperatureDB", aTemperature);
        query.bindValue(":PayOperationVCode", aPayOperationVCode);
        query.bindValue(":PayWay", aPayWay);
        query.bindValue(":PrePostPay", aPrePostPay);
        query.bindValue(":WUser", aWUser);
        query.bindValue(":WDate", aWDate.toString("yyyyMMdd hh:mm:ss.zzz"));
        query.bindValue(":CUser", aCUser);
        query.bindValue(":CDate", aCDate.toString("yyyyMMdd hh:mm:ss.zzz"));
        query.bindValue(":CHost", aCHost);
        query.bindValue(":WHost", aWHost);
        query.bindValue(":VCode", aVCode);
        query.bindValue(":AddedForTransVCode", aAddedForTransVCode);
        query.bindValue(":AditionalTransVCode", aAditionalTransVCode);
        query.bindValue(":ActiveDB", aActive);
        query.bindValue(":MassDB", aMass);
        query.bindValue(":Smena", aSmena);
        query.bindValue(":TrkVcode", aTrkVcode);
        query.bindValue(":CapacityVcode", aCapacityVcode);
        query.bindValue(":PumpPlace", aPumpPlace);
        query.bindValue(":MoneyTakenDB", aMoneyTaken);
        query.bindValue(":iPayWay", aIPayWay);
        query.bindValue(":AutoCheckDB", aAutoCheck);
        query.bindValue(":Closed", aClosed);
        query.bindValue(":FullTankDB", aFullTank);
        query.bindValue(":AGZS", aAgzs);
        query.bindValue(":FuelVCode", aFuelVCode);
        query.bindValue(":Propan", aPropan);
        query.exec();
        if (query.lastError().type() == QSqlError::NoError) {
            return true;
        } else {
            openDB();
            logAppend("createTrkTransaction error " + QString::number(cycles));
        }
        cycles++;
    }
    return false;
}

bool DataBaseControl::createApiTransaction(QString aAgzsName, int aAgzs, QDateTime aCDate, int aVCode, QString aApiId, QString aApiStationExtendedId,
                                     int aApiColumnId, QString aApiFuelId, int aFuelId, int aApiPriceFuel, int aApiLitre, int aApiSum, QString aApiStatus,
                                     QString aApiContractId, QString aAgent, QString aLocalState, double aPrice, double aLitre, double aSum, QDateTime aDateOpen, int aLink) {
    int cycles = 0;
    while (cycles < c_maxRestartCount) {
        QSqlQuery query(_db);
        query.prepare("INSERT INTO [agzs].[dbo].[PR_APITransaction] ([AGZSName],[AGZS],[CDate],[VCode],[APIID],[APIStationExtendedId],[APIColumnId],[APIFuelId],[FuelId],"
                        "[APIPriceFuel],[APILitre],[APISum],[APIStatus],[APIContractId],[agent],[localState],[Price],[Litre],[Sum],[DateOpen],[DateClose],[Link]) "
                       "VALUES (:AGZSName, :AGZS, :CDate, :VCode, :APIID, :APIStationExtendedId, :APIColumnId, :APIFuelId, :FuelId, :APIPriceFuel, :APILitre, :APISum, "
                        ":APIStatus, :APIContractId, :agent, :localState, :Price, :Litre, :Sum, :DateOpen, DEFAULT, :Link)");
        query.bindValue(":AGZSName", aAgzsName);
        query.bindValue(":AGZS", aAgzs);
        query.bindValue(":CDate", aCDate.toString("yyyyMMdd hh:mm:ss.zzz"));
        query.bindValue(":VCode", aVCode);
        query.bindValue(":APIID", aApiId);
        query.bindValue(":APIStationExtendedId", aApiStationExtendedId);
        query.bindValue(":APIColumnId", aApiColumnId);
        query.bindValue(":APIFuelId", aApiFuelId);
        query.bindValue(":FuelId", aFuelId);
        query.bindValue(":APIPriceFuel", aApiPriceFuel);
        query.bindValue(":APILitre", aApiLitre);
        query.bindValue(":APISum", aApiSum);
        query.bindValue(":APIStatus", aApiStatus);
        query.bindValue(":APIContractId", aApiContractId);
        query.bindValue(":agent", aAgent);
        query.bindValue(":localState", aLocalState);
        query.bindValue(":Price", aPrice);
        query.bindValue(":Litre", aLitre);
        query.bindValue(":Sum", aSum);
        query.bindValue(":DateOpen", aDateOpen.toString("yyyyMMdd hh:mm:ss.zzz"));
        //q_APIRequests.bindValue(":DateClose", "DEFAULT");
        query.bindValue(":Link", aLink);
        query.exec();
        if (query.lastError().type() == QSqlError::NoError) {
            return true;
        } else  {
            openDB();
            logAppend("createApiTransaction error " + QString::number(cycles) + " " + query.lastError().text());
//            logAppend(aAgzsName + " " + QString::number(aAgzs) + " " + aCDate.toString() + " " + QString::number(aVCode) + " " + aApiId + " " + aApiStationExtendedId + " " +
//                      QString::number(aApiColumnId) + " " + aApiFuelId + " " + QString::number(aFuelId) + " " + QString::number(aApiPriceFuel) + " " + QString::number(aApiLitre) + " " +
//                      QString::number(aApiSum) + " " + aApiStatus + " " + aApiContractId + " " + aAgent + " " + aLocalState + " " + QString::number(aPrice) + " " + QString::number(aLitre) + " " +
//                      QString::number(aSum) + " " + aDateOpen.toString() + " " + QString::number(aLink) + " " + query.lastError().text());
        }
        cycles++;
    }
    return false;
}

bool DataBaseControl::getApiTransactionState(QString aId, QString &aLocalState, double &aApiLitre, int &aApiVCode, int &aHeadVCode, int &aIState, QDateTime aDateOpen, QDateTime &aDateClose) {
    int cycles = 0;
    while (cycles < c_maxRestartCount) {
        QSqlQuery query(_db);
        query.exec("SELECT api.localState, api.APILitre, api.VCode, h.VCode, b.iState, b.DateOpen, b.DateClose "
                   "FROM [agzs].[dbo].[PR_APITransaction] api "
                    "INNER JOIN [agzs].[dbo].[ADAST_TRKTransaction] h ON api.Link = h.VCode "
                    "INNER JOIN [agzs].[dbo].[ADAST_TRKTransaction] b ON h.AditionalTransVCode = b.VCode "
                   "WHERE api.APIID = '" + aId + "'");
        if (query.lastError().type() == QSqlError::NoError) {
            while (query.next()){
                aLocalState = query.value(0).toString();
                aApiLitre = query.value(1).toDouble();
                aApiVCode = query.value(2).toInt();
                aHeadVCode = query.value(3).toInt();
                aIState = query.value(4).toInt();
                aDateOpen = query.value(5).toDateTime();
                aDateClose = query.value(6).toDateTime();
                break;
            }
            return true;
        } else {
            openDB();
            logAppend("getApiTransactionState error " + QString::number(cycles));
        }
        cycles++;
    }
    return false;
}

bool DataBaseControl::updateApiTransactionState(QString aLocalState, QDateTime aDateClose, int aVCode) {
    int cycles = 0;
    while (cycles < c_maxRestartCount) {
        QSqlQuery query(_db);
        query.prepare("UPDATE [agzs].[dbo].[PR_APITransaction] "
                             "SET localState = :localState, DateClose = :date "
                      "WHERE VCode = :VCode");
        query.bindValue(":localState", aLocalState);
        query.bindValue(":date",       aDateClose);
        query.bindValue(":VCode",      aVCode);
        query.exec();
        if (query.lastError().type() == QSqlError::NoError) {
            return true;
        } else {
            openDB();
            logAppend("updateApiTransactionState error " + QString::number(cycles));
        }
        cycles++;
    }
    return false;
}

bool DataBaseControl::finalUpdateApiTransactionState(QString aLocalState, double aPrice, double aVolume, double aAmount, QDateTime aDateOpen, QDateTime aDateClose, int aVCode) {
    int cycles = 0;
    while (cycles < c_maxRestartCount) {
        QSqlQuery query(_db);
        query.prepare("UPDATE [agzs].[dbo].[PR_APITransaction] "
                        "SET localState = :localState, "
                           "[Price] = :price, "
                           "[Litre] = :litre, "
                           "[Sum] = :sum, "
                           "[DateOpen] = :dateOpen, "
                           "DateClose = :dateClose "
                      "WHERE VCode = :VCode");
        query.bindValue(":localState", aLocalState);
        query.bindValue(":price",      aPrice);
        query.bindValue(":litre",      aVolume);
        query.bindValue(":sum",        aAmount);
        query.bindValue(":dateOpen",   aDateOpen);
        query.bindValue(":dateClose",  aDateClose);
        query.bindValue(":VCode",      aVCode);
        query.exec();
        if (query.lastError().type() == QSqlError::NoError) {
            return true;
        } else {
            openDB();
            logAppend("finalUpdateApiTransactionState error " + QString::number(cycles));
        }
        cycles++;
    }
    return false;
}

bool DataBaseControl::getPayOperationLiters(int aLink, double &aAmount, double &aVolume, double &aPrice) {
    int cycles = 0;
    while (cycles < c_maxRestartCount) {
        QSqlQuery query(_db);
        query.exec("SELECT [AmountDB], [PriceDB], [VolumeDB] "
                   "FROM [agzs].[dbo].[ARM_PayOperation] "
                   "WHERE Link = " + QString::number(aLink));
        if (query.next()) {
            aAmount = query.value(0).toDouble();
            aVolume = query.value(2).toDouble();
            aPrice = query.value(1).toDouble();
            return true;
        } else {
            openDB();
            logAppend("getPayOperationLiters error " + QString::number(cycles));
        }
        cycles++;
    }
    return false;
}

bool DataBaseControl::setTransactionClosed(QString aId, int aClosed) {
    int cycles = 0;
    while (cycles < c_maxRestartCount) {
        QSqlQuery query(_db);
        query.prepare("UPDATE [agzs].[dbo].[ADAST_TRKTransaction] "
                             "SET Closed = :closed "
                      "WHERE VCode = (SELECT Link "
                                     "FROM [agzs].[dbo].[PR_APITransaction] "
                                     "WHERE ApiId = :id)");
        query.bindValue(":closed", aClosed);
        query.bindValue(":id",     aId);
        query.exec();
        if (query.lastError().type() == QSqlError::NoError) {
            return true;
        } else {
            openDB();
            logAppend("setTransactionClosed error " + QString::number(cycles));
        }
        cycles++;
    }
    return false;
}

bool DataBaseControl::getTransactionData(int aVCode, double &aRequestTotalPrice, double &aRequestVolume, double &aRequestUnitPrice, double &aTrkTotalPrice, double &aTrkVolume, double &aTrkUnitPrice, QDateTime &aDateOpen, QDateTime &aDateClose) {
    int cycles = 0;
    while (cycles < c_maxRestartCount) {
        QSqlQuery query(_db);
            query.prepare("SELECT [TrkTotalPriceDB] "
                                  ",[TrkVolumeDB] "
                                  ",[TrkUnitPriceDB] "
                                  ",[RequestTotalPriceDB] "
                                  ",[RequestVolumeDB] "
                                  ",[RequestUnitPriceDB] "
                                  ",DateOpen"
                                  ",DateClose "
                          "FROM [agzs].[dbo].[ADAST_TRKTransaction] "
                          "WHERE VCode = :VCode");
            query.bindValue(":VCode", aVCode);
            query.exec();
        if (query.lastError().type() == QSqlError::NoError) {
            if (query.next()) {
                aTrkTotalPrice = query.value(0).toDouble();
                aTrkVolume = query.value(1).toDouble();
                aTrkUnitPrice = query.value(2).toDouble();
                aRequestTotalPrice = query.value(3).toDouble();
                aRequestVolume = query.value(4).toDouble();
                aRequestUnitPrice = query.value(5).toDouble();
                aDateOpen = query.value(6).toDateTime();
                aDateClose = query.value(7).toDateTime();
            }
            return true;
        } else {
            openDB();
            logAppend("getTransactionData error " + QString::number(cycles));
        }
        cycles++;
    }
    return false;
}

int DataBaseControl::getCurrentAgzs() {
    QSqlQuery query(_db);
    query.exec("SELECT TOP 1 AGZS "
                "FROM [agzs].[dbo].[Identification] ");
    if (query.next()) {
        return query.value(0).toInt();
    }
    return 0;
}

bool DataBaseControl::updateApiTransaction(int aLocalState, QDateTime aDate, int aVCode) {
    int cycles = 0;
    while (cycles < c_maxRestartCount) {
        QSqlQuery query(_db);
        query.prepare("UPDATE [agzs].[dbo].[PR_APITransaction] "
                             "SET localState = :localState, DateClose = :date "
                      "WHERE VCode = :VCode");
        query.bindValue(":localState", aLocalState);
        query.bindValue(":date",       aDate);
        query.bindValue(":VCode",      aVCode);
        query.exec();
        if (query.lastError().type() == QSqlError::NoError) {
            return true;
        } else {
            openDB();
            logAppend("updateApiTransaction error " + QString::number(cycles));
        }
        cycles++;
    }
    return false;
}

int DataBaseControl::getLastVCode(QString aKey, bool aUpdate) {
    QSqlQuery query(_db);
        query.exec("SELECT TOP 1 Value "
                   "FROM [agzs].[dbo].[LxKeysOfCodes] "
                   "WHERE [Key] = '" + aKey + "'");
    if (query.next()) {
        int vcode = query.value(0).toInt();
        if (aUpdate) {
            query.exec("UPDATE [agzs].[dbo].[LxKeysOfCodes] "
                             "SET Value = Value + 1 "
                       "WHERE [Key] = '" + aKey + "'");
        }
        return vcode;
    } else {
        openDB();
        return 0;
    }
}

int DataBaseControl::checkError(QString aColumnID, QString aFuelID, int aiFuelID, QString aPriceFuel, int aIPartner) {
    QSqlQuery query(_db);
    query.exec("SELECT d.AGZS, d.VCode, d.Id "
               "FROM [agzs].[dbo].PR_AGZSData d "
                     "INNER JOIN [agzs].[dbo].[ADAST_AdastTRK] t ON d.AGZS = t.AGZS "
               "WHERE d.AGZS = (SELECT TOP 1 AGZS "
                               "FROM [agzs].[dbo].[Identification]) "
                    "AND ((t.[SideA_Address] = " + aColumnID + ") OR (t.[SideB_Address] = " + aColumnID + ")) "
               "ORDER BY d.CDate DESC");
    if (query.next()) {
        query.exec("SELECT d.AGZS, d.VCode, d.Id "
                     "FROM [agzs].[dbo].PR_AGZSData d "
                         "INNER JOIN [agzs].[dbo].[ADAST_AdastTRK] t "
                         "ON d.AGZS = t.AGZS "
                     "WHERE d.AGZS = (SELECT TOP 1 AGZS "
                                    "FROM [agzs].[dbo].[Identification]) "
                        "AND (((t.[SideA_Address] = " + aColumnID + ") AND (([SideA_Nozzle1Fuel] = " + QString::number(aiFuelID) + ") "
                                                                        "OR ([SideA_Nozzle2Fuel] = " + QString::number(aiFuelID) + ") "
                                                                        "OR ([SideA_Nozzle3Fuel] = " + QString::number(aiFuelID) + ") "
                                                                        "OR ([SideA_Nozzle4Fuel] = " + QString::number(aiFuelID) + ") "
                                                                        "OR ([SideA_Nozzle5Fuel] = " + QString::number(aiFuelID) + "))) "
                           "OR (t.[SideB_Address] = " + aColumnID + ") AND (([SideB_Nozzle1Fuel] = " + QString::number(aiFuelID) + ") "
                                                                        "OR ([SideB_Nozzle2Fuel] = " + QString::number(aiFuelID) + ") "
                                                                        "OR ([SideB_Nozzle3Fuel] = " + QString::number(aiFuelID) + ") "
                                                                        "OR ([SideB_Nozzle4Fuel] = " + QString::number(aiFuelID) + ") "
                                                                        "OR ([SideB_Nozzle5Fuel] = " + QString::number(aiFuelID) + "))) "
                     "ORDER BY d.CDate DESC");
        if (query.next()) {
            query.exec("SELECT d.AGZS, d.VCode, d.Id, p.[" + aFuelID + "] "
                        "FROM [agzs].[dbo].PR_AGZSData d "
                             "INNER JOIN [agzs].[dbo].[ADAST_AdastTRK] t "
                             "ON d.AGZS = t.AGZS "
                             "INNER JOIN [agzs].[dbo].PR_AGZSPrice p "
                             "ON d.VCode = p.Link "
                        "WHERE d.AGZS = (SELECT TOP 1 AGZS "
                                        "FROM [agzs].[dbo].[Identification]) "
                            "AND (((t.[SideA_Address] = " + aColumnID + ") AND (([SideA_Nozzle1Fuel] = " + QString::number(aiFuelID) + ") "
                                                                            "OR ([SideA_Nozzle2Fuel] = " + QString::number(aiFuelID) + ") "
                                                                            "OR ([SideA_Nozzle3Fuel] = " + QString::number(aiFuelID) + ") "
                                                                            "OR ([SideA_Nozzle4Fuel] = " + QString::number(aiFuelID) + ") "
                                                                            "OR ([SideA_Nozzle5Fuel] = " + QString::number(aiFuelID) + "))) "
                               "OR (t.[SideB_Address] = " + aColumnID + ") AND (([SideB_Nozzle1Fuel] = " + QString::number(aiFuelID) + ") "
                                                                            "OR ([SideB_Nozzle2Fuel] = " + QString::number(aiFuelID) + ") "
                                                                            "OR ([SideB_Nozzle3Fuel] = " + QString::number(aiFuelID) + ") "
                                                                            "OR ([SideB_Nozzle4Fuel] = " + QString::number(aiFuelID) + ") "
                                                                            "OR ([SideB_Nozzle5Fuel] = " + QString::number(aiFuelID) + "))) "
                            "and p.[" + aFuelID + "] = " + aPriceFuel + " "
                            "and p.iPartner = " + QString::number(aIPartner) +
                        "ORDER BY d.CDate DESC");
            if (query.next()) {
                return 0;
            } else {
                return 3;
            }
        } else {
            return 2;
        }
    } else {
        return 1;
    }
}

bool DataBaseControl::setYandexToken(QString aToken) {
    QSqlQuery query(_db);
    query.prepare("UPDATE [agzs].[dbo].[PR_AGZSData] "
                         "SET YandexToken = :token "
                  "WHERE AGZS = (SELECT TOP 1 AGZS "
                                "FROM [agzs].[dbo].[Identification]) ");
    query.bindValue(":token", aToken);
    query.exec();
    _reestr.setValue("Yandex Token", aToken);
    return true;
}

bool DataBaseControl::isTransactionExist(QString aApiId) {
    QSqlQuery query(_db);
    query.prepare("SELECT id "
                  "FROM [agzs].[dbo].[PR_AGZSData] "
                  "WHERE id = :id ");
    query.bindValue(":id", aApiId);
    query.exec();
    if (query.next() || query.lastError().type() != QSqlError::NoError) {
        return true;
    } else {
        return false;
    }
}
