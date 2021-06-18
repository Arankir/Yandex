#include "databasecontrol.h"

const int c_maxRestartCount = 3;

#define InitStart {
DataBaseControl::DataBaseControl(QString aAgzs, QObject *aParent): QObject(aParent), agzs_(aAgzs) {
    while(!init());
}

bool DataBaseControl::init() {
    db_ = QSqlDatabase::addDatabase("QODBC3");
    db_.setDatabaseName(QString("DRIVER={SQL Server};"
                                "SERVER=%1;"
                                "DATABASE=agzs;"
                                "Persist Security Info=true;"
                                "uid=sa;"
                                "pwd=Gfhf743Djpbr").arg(agzs_));
    return openDB();
    return false;
}

bool DataBaseControl::openDB() {
    if (db_.open()) {
        qInfo () << "DB is open";
        return true;
    } else {
        qInfo () << "DB isn't open";
        return false;
    }
}
#define InitEnd }

QString getQuery(QString aQueryName) {
    QFile qssFile(":/queries/" + aQueryName);
    qssFile.open(QFile::ReadOnly);
    return qssFile.readAll();
}

bool DataBaseControl::makeQuery(QString aQuery, QString aName, QueryType aType, std::function<void (QSqlQuery &)> func, bool isShowMessageNoData) {
#define errorInfo qWarning(logError) << aName << /*query.lastQuery() << */query.lastError().text()
    int cycles = 0;
    while (cycles < c_maxRestartCount) {
        QSqlQuery query(db_);
        query.prepare(aQuery);
        switch (aType) {
        case qSelect: {
            query.exec();
            if (query.lastError().type() == QSqlError::NoError) {
                if (query.next()) {
                    func(query);
                    return true;
                } else {
                    if (isShowMessageNoData) {
                        qWarning(logError) << aName << "no data";
                    }
                    return false;
                }
            } else {
                errorInfo << "error" << cycles;
            }
            break;
        }
        case qUpdate: {
            if (query.exec()) {
                if (query.lastError().type() == QSqlError::NoError) {
                    return true;
                } else {
                    errorInfo << "error" << cycles;
                }
            } else {
                errorInfo << "no update" << cycles;
            }
            break;
        }
        case qDelete: {
            if (query.exec()) {
                if (query.lastError().type() == QSqlError::NoError) {
                    return true;
                } else {
                    errorInfo << "error" << cycles;
                }
            } else {
                errorInfo << "no delete" << cycles;
            }
            break;
        }
        case qInsert: {
            if (query.exec()) {
                if (query.lastError().type() == QSqlError::NoError) {
                    return true;
                } else {
                    errorInfo << "error" << cycles;
                }
            } else {
                errorInfo << "no insert" << cycles;
            }
            break;
        }
        case qProcedure: {
            if (query.exec()) {
                if (query.lastError().type() == QSqlError::NoError) {
                    if (query.next()) {
                        func(query);
                        return true;
                    } else {
                        errorInfo << "no data" << cycles;
                    }
                } else {
                    errorInfo << "error" << cycles;
                }
            } else {
                errorInfo << "no exec procedure" << cycles;
            }
            break;
        }
        }
        openDB();
        ++cycles;
    }
    return false;
}

FuelNames DataBaseControl::getFuelNames(int aFuelId) {
    FuelNames fuelNames;
    makeQuery(getQuery("getFuelNames").arg(QString::number(aFuelId)), "getFuelNames", QueryType::qSelect, [&](QSqlQuery &query){
        fuelNames =   { query.value("FuelName").toString(),
                        query.value("FuelShortName").toString()
                      };
    });
    return fuelNames;

//    int cycles = 0;
//    while (cycles < c_maxRestartCount) {
//        QSqlQuery query(db_);
//        query.exec("SELECT TOP 1 [FuelName], [FuelShortName] "
//                   "FROM [agzs].[dbo].[Interface_FuelParams] "
//                   "WHERE [Fuel] = " + QString::number(aFuelId));
//        if (query.next()) {
//            FuelNames fuelNames = { query.value(0).toString(),
//                                    query.value(1).toString()
//                                  };
//            return fuelNames;
//        } else {
//            openDB();
//             qWarning(logError) << query.lastError().type() << "getFuelNames" << cycles;
//        }
//        ++cycles;
//    }
//    return FuelNames();
}

QVector<SideFuel> DataBaseControl::getFuels() {
    QVector<SideFuel> result;
    makeQuery(getQuery("getFuels"), "getFuels", QueryType::qSelect, [&](QSqlQuery &query){
         do {
            if (query.value("SideAdress").toInt() > 0) {
                SideFuel side;
                side.sideAdress = query.value("SideAdress").toInt();
                side.partnerSideAdress = query.value("Partner_TrkNum").toInt();
                QVector<int> fuels;
                if (!query.value("Nozzle1Fuel").isNull()) {
                    fuels.append(query.value("Nozzle1Fuel").toInt());
                }
                if (!query.value("Nozzle2Fuel").isNull()) {
                    fuels.append(query.value("Nozzle2Fuel").toInt());
                }
                if (!query.value("Nozzle3Fuel").isNull()) {
                    fuels.append(query.value("Nozzle3Fuel").toInt());
                }
                if (!query.value("Nozzle4Fuel").isNull()) {
                    fuels.append(query.value("Nozzle4Fuel").toInt());
                }
                if (!query.value("Nozzle5Fuel").isNull()) {
                    fuels.append(query.value("Nozzle5Fuel").toInt());
                }
                side.fuels = fuels;
                result.append(std::move(side));
            }
        } while (query.next());
    });
    return result;

//    int cycles = 0;
//    while (cycles < c_maxRestartCount) {
//        QSqlQuery query(db_);
//        query.exec("SELECT columnn.SideAdress, columnn.[Partner_TrkNum], columnn.Nozzle1Fuel, columnn.Nozzle2Fuel, columnn.Nozzle3Fuel, columnn.Nozzle4Fuel, columnn.Nozzle5Fuel "
//                    "FROM [agzs].[dbo].[PR_Columns] columnn "
//                    "INNER JOIN [agzs].[dbo].[ADAST_AdastTRK] trk ON ((columnn.SideAdress = trk.[SideA_Address]) OR (columnn.SideAdress = trk.[SideB_Address])) "
//                    "WHERE columnn.agzs = (SELECT TOP 1 AGZS "
//                                          "FROM [agzs].[dbo].[Identification]) "
//                     "AND trk.agzs = columnn.agzs "
//                     "AND columnn.visible = 1 ");
//        if (query.lastError().type() == QSqlError::NoError) {
//            QVector<SideFuel> result;
//            while (query.next()) {
//                if (query.value(0).toInt() > 0) {
//                    SideFuel side;
//                    side.sideAdress = query.value(0).toInt();
//                    side.partnerSideAdress = query.value(1).toInt();
//                    QVector<int> fuels;
//                    if (!query.value(2).isNull()) {
//                        fuels.append(query.value(2).toInt());
//                    }
//                    if (!query.value(3).isNull()) {
//                        fuels.append(query.value(3).toInt());
//                    }
//                    if (!query.value(4).isNull()) {
//                        fuels.append(query.value(4).toInt());
//                    }
//                    if (!query.value(5).isNull()) {
//                        fuels.append(query.value(5).toInt());
//                    }
//                    if (!query.value(6).isNull()) {
//                        fuels.append(query.value(6).toInt());
//                    }
//                    side.fuels = fuels;
//                    result.append(std::move(side));
//                }
//            }
//            return result;
//        } else {
//            openDB();
//             qWarning(logError) << query.lastError().type() << "getFuels" << cycles;
//        }
//        ++cycles;
//    }
//    return QVector<SideFuel>();
}

int DataBaseControl::getRealSideAddress(int aAgzs, int aPartnerSideAddress) {
    int result;
    makeQuery(getQuery("getRealSideAddress").arg(QString::number(aAgzs), QString::number(aPartnerSideAddress)), "getRealSideAddress", QueryType::qSelect, [&](QSqlQuery &query){
         result = query.value("SideAdress").toInt();
    });
    return result;


//    int cycles = 0;
//    while (cycles < c_maxRestartCount) {
//        QSqlQuery query(db_);
//        query.exec("SELECT TOP 1 [SideAdress] "
//                   "FROM [agzs].[dbo].[PR_Columns] "
//                   "WHERE agzs = " + QString::number(aAgzs) + " "
//                     "AND [Partner_TrkNum] = " + QString::number(aPartnerSideAddress) + " "
//                   "ORDER BY CDate DESC");
//        if (query.next()) {
//            return query.value(0).toInt();
//        } else {
//            openDB();
//             qWarning(logError) << query.lastError().type() << "getRealSideAddress" << cycles;
//        }
//        ++cycles;
//    }
//    return 0;
}

int DataBaseControl::getSmena() {
    int result;
    makeQuery(getQuery("getSmena"), "getSmena", QueryType::qSelect, [&](QSqlQuery &query){
         result = query.value("VCode").toInt();
    });
    return result;

//    int cycles = 0;
//    while (cycles < c_maxRestartCount) {
//        QSqlQuery query(db_);
//        query.exec("SELECT TOP 1 VCode "
//                   "FROM [agzs].[dbo].[ARM_Smena] "
//                   "ORDER BY CDate DESC");
//        if (query.next()) {
//            return query.value(0).toInt();
//        } else {
//            openDB();
//             qWarning(logError) << query.lastError().type() << "getSmena" << cycles;
//        }
//        ++cycles;
//    }
//    return 0;
}

int DataBaseControl::getCashBoxIndex(QString aIPartner) {
    int result;
    makeQuery(getQuery("getCashBoxIndex").arg(aIPartner), "getCashBoxIndex", QueryType::qSelect, [&](QSqlQuery &query){
         result = query.value("CashBoxIndex").toInt();
    });
    return result;

//    int cycles = 0;
//    while (cycles < c_maxRestartCount) {
//        QSqlQuery query(db_);
//        query.exec("SELECT TOP 1 CashBoxIndex, PayIndex, PayWay, AutoCheck FROM [agzs].[dbo].[ARM_CashBoxesSemaphor] "
//                   "WHERE PayIndex = " + aIPartner + " and AutoCheck = 0 "
//                   "ORDER BY CDate DESC");
//        if (query.next()) {
//            return query.value(1).toInt();
//        } else {
//            openDB();
//             qWarning(logError) << query.lastError().type() << "getCashBoxIndex" << cycles;
//        }
//        ++cycles;
//    }
//    return 0;
}

Price DataBaseControl::getPrices(QString aIPartner) {
    Price price;
    makeQuery(getQuery("getPrices").arg(aIPartner), "getPrices", QueryType::qSelect, [&](QSqlQuery &query){
        price.agzsName          = query.value("AGZSName").toString();
        price.agzs              = query.value("AGZS").toInt();
        price.vCode             = query.value("VCode").toInt();
        price.link              = query.value("Link").toInt();
        price.cDate             = query.value("CDate").toDateTime();
        price.partner           = query.value("Partner").toString();
        price.diesel            = query.value("diesel").toFloat();
        price.diesel_premium    = query.value("diesel_premium").toFloat();
        price.a80               = query.value("a80").toFloat();
        price.a92               = query.value("a92").toFloat();
        price.a92_premium       = query.value("a92_premium").toFloat();
        price.a95               = query.value("a95").toFloat();
        price.a95_premium       = query.value("a95_premium").toFloat();
        price.a98               = query.value("a98").toFloat();
        price.a98_premium       = query.value("a98_premium").toFloat();
        price.a100              = query.value("a100").toFloat();
        price.a100_premium      = query.value("a100_premium").toFloat();
        price.propane           = query.value("propane").toFloat();
        price.metan             = query.value("metan").toFloat();
    });
    return price;
//    int cycles = 0;
//    while (cycles < c_maxRestartCount) {
//        QSqlQuery query(db_);
//        query.exec("SELECT TOP 1 [AGZSName], [AGZS], [VCode], [Link], [CDate], [Partner], "
//                    "[diesel], [diesel_premium], [a80], [a92], [a92_premium], [a95], [a95_premium], "
//                    "[a98],[a98_premium], [a100], [a100_premium], [propane], [metan] "
//                    "FROM [agzs].[dbo].PR_AGZSPrice "
//                   "WHERE Link = (SELECT VCode "
//                                 "FROM [agzs].[dbo].PR_AGZSData "
//                                 "WHERE AGZS = (SELECT TOP 1 AGZS "
//                                               "FROM [agzs].[dbo].[Identification])) "
//                   "and iPartner = " + aIPartner + " "
//                   "and DateStart < GETDATE() "
//                   "ORDER BY [CDate] desc");
//        if (query.next()) {
//            Price price;
//            price.agzsName          = query.value(0).toString();
//            price.agzs              = query.value(1).toInt();
//            price.vCode             = query.value(2).toInt();
//            price.link              = query.value(3).toInt();
//            price.cDate             = query.value(4).toDateTime();
//            price.partner           = query.value(5).toString();
//            price.diesel            = query.value(6).toFloat();
//            price.diesel_premium    = query.value(7).toFloat();
//            price.a80               = query.value(8).toFloat();
//            price.a92               = query.value(9).toFloat();
//            price.a92_premium       = query.value(10).toFloat();
//            price.a95               = query.value(11).toFloat();
//            price.a95_premium       = query.value(12).toFloat();
//            price.a98               = query.value(13).toFloat();
//            price.a98_premium       = query.value(14).toFloat();
//            price.a100              = query.value(15).toFloat();
//            price.a100_premium      = query.value(16).toFloat();
//            price.propane           = query.value(17).toFloat();
//            price.metan             = query.value(18).toFloat();
//            return price;
//        } else {
//            openDB();
//             qWarning(logError) << query.lastError().type() << "getPrices" << cycles;
//        }
//        ++cycles;
//    }
//    return Price();
}

Agzs DataBaseControl::getAgzsData() {
    Agzs agzs;
    makeQuery(getQuery("getAgzsData"), "getAgzsData", QueryType::qSelect, [&](QSqlQuery &query){
        agzs.agzsName = query.value("AGZSName").toString();
        agzs.agzs = query.value("AGZS").toInt();
        agzs.cDate = query.value("CDate").toDateTime();
        agzs.vCode = query.value("VCode").toInt();
        agzs.id = query.value("Id").toString();
        agzs.adress = query.value("Adress").toString();
        agzs.loc_x = query.value("latitude").toFloat();
        agzs.loc_y = query.value("longitude").toFloat();
        agzs.columnCount = query.value("ColumnsCount").toInt();
    });
    return agzs;
//    int cycles = 0;
//    while (cycles < c_maxRestartCount) {
//        QSqlQuery query(db_);
//        query.exec("SELECT TOP 1 [AGZSName], [AGZS], [CDate], [VCode], [Id], [Adress], "
//                    "[latitude], [longitude], [ColumnsCount] "
//                    "FROM [agzs].[dbo].[PR_AGZSData] "
//                   "WHERE AGZS = (SELECT TOP 1 AGZS "
//                                 "FROM [agzs].[dbo].[Identification]) ");
//        if (query.next()) {
//            Agzs agzs;
//            agzs.agzsName = query.value(0).toString();
//            agzs.agzs = query.value(1).toInt();
//            agzs.cDate = query.value(2).toDateTime();
//            agzs.vCode = query.value(3).toInt();
//            agzs.id = query.value(4).toString();
//            agzs.adress = query.value(5).toString();
//            agzs.loc_x = query.value(6).toFloat();
//            agzs.loc_y = query.value(7).toFloat();
//            agzs.columnCount = query.value(8).toInt();
//            return agzs;
//        } else {
//            openDB();
//             qWarning(logError) << query.lastError().type() << "getAgzsData" << cycles;
//        }
//        ++cycles;
//    }
//    return Agzs();
}

AdastTrk DataBaseControl::getAgzsAdastTrk(int aSideAdress) {
    AdastTrk trk;
    makeQuery(getQuery("getAgzsAdastTrk").arg(QString::number(aSideAdress)), "getAgzsAdastTrk", QueryType::qSelect, [&](QSqlQuery &query){
        trk.sideAdress = aSideAdress;
        trk.deviceName = query.value("DeviceName").toString();
        trk.serial = query.value("Serial").toString();
        trk.description = query.value("Description").toString();
        trk.trkVCode = query.value("VCode").toInt();
        trk.side = query.value("side").toString();
        trk.fuelCode1 = query.value("SideA_Nozzle1FuelCode").toInt();
        trk.fuelCode2 = query.value("SideA_Nozzle2FuelCode").toInt();
        trk.fuelCode3 = query.value("SideA_Nozzle3FuelCode").toInt();
        trk.fuelCode4 = query.value("SideA_Nozzle4FuelCode").toInt();
        trk.fuelCode5 = query.value("SideA_Nozzle5FuelCode").toInt();
        trk.pumpPlace = query.value("SideA_PumpPlace").toInt();
        trk.fuel1 = query.value("SideA_Nozzle1Fuel").toInt();
        trk.fuel2 = query.value("SideA_Nozzle2Fuel").toInt();
        trk.fuel3 = query.value("SideA_Nozzle3Fuel").toInt();
        trk.fuel4 = query.value("SideA_Nozzle4Fuel").toInt();
        trk.fuel5 = query.value("SideA_Nozzle5Fuel").toInt();
    });
    return trk;

//    int cycles = 0;
//    while (cycles < c_maxRestartCount) {
//        QSqlQuery query(db_);
//        query.exec("SELECT TOP 1 [DeviceName], [Serial], [Description], "
//                     "[SideA_Address], [SideA_Nozzle1FuelCode], [SideA_Nozzle2FuelCode], [SideA_Nozzle3FuelCode], [SideA_Nozzle4FuelCode], [SideA_Nozzle5FuelCode], "
//                     "[SideB_Address], [SideB_Nozzle1FuelCode], [SideB_Nozzle2FuelCode], [SideB_Nozzle3FuelCode], [SideB_Nozzle4FuelCode], [SideB_Nozzle5FuelCode], "
//                     "[SystemSettings], [CDate], [VCode], "
//                     "[SideA_PumpPlace], [SideA_Nozzle1Fuel], [SideA_Nozzle2Fuel], [SideA_Nozzle3Fuel], [SideA_Nozzle4Fuel], [SideA_Nozzle5Fuel], "
//                     "[SideB_PumpPlace], [SideB_Nozzle1Fuel], [SideB_Nozzle2Fuel], [SideB_Nozzle3Fuel], [SideB_Nozzle4Fuel], [SideB_Nozzle5Fuel] "
//                    "FROM [agzs].[dbo].[ADAST_AdastTRK] "
//                    "WHERE ((SideA_Address = " + QString::number(aSideAdress) + ") OR (SideB_Address = " + QString::number(aSideAdress) + ")) "
//                            "AND (AGZS = (SELECT TOP 1 AGZS "
//                                         "FROM [agzs].[dbo].[Identification]))");
//        if (query.next()) {
//            AdastTrk trk;
//            trk.sideAdress = aSideAdress;
//            trk.deviceName = query.value(0).toString();
//            trk.serial = query.value(1).toString();
//            trk.description = query.value(2).toString();
//            trk.trkVCode = query.value(17).toInt();
//            if (query.value(3).toInt() == trk.sideAdress) {
//                trk.side = "A";
//                trk.fuelCode1 = query.value(4).toInt();
//                trk.fuelCode2 = query.value(5).toInt();
//                trk.fuelCode3 = query.value(6).toInt();
//                trk.fuelCode4 = query.value(7).toInt();
//                trk.fuelCode5 = query.value(8).toInt();
//                trk.pumpPlace = query.value(18).toInt();
//                trk.fuel1 = query.value(19).toInt();
//                trk.fuel2 = query.value(20).toInt();
//                trk.fuel3 = query.value(21).toInt();
//                trk.fuel4 = query.value(22).toInt();
//                trk.fuel5 = query.value(23).toInt();
//            } else if (query.value(9).toInt() == trk.sideAdress) {
//                trk.side = "B";
//                trk.fuelCode1 = query.value(10).toInt();
//                trk.fuelCode2 = query.value(11).toInt();
//                trk.fuelCode3 = query.value(12).toInt();
//                trk.fuelCode4 = query.value(13).toInt();
//                trk.fuelCode5 = query.value(14).toInt();
//                trk.pumpPlace = query.value(24).toInt();
//                trk.fuel1 = query.value(25).toInt();
//                trk.fuel2 = query.value(26).toInt();
//                trk.fuel3 = query.value(27).toInt();
//                trk.fuel4 = query.value(28).toInt();
//                trk.fuel5 = query.value(29).toInt();
//            }
//            return trk;
//        } else {
//            openDB();
//             qWarning(logError) << query.lastError().type() << "getAgzsAdastTrk" << cycles;
//        }
//        ++cycles;
//    }
//    return AdastTrk();
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
    QString query = getQuery("createTrkTransaction").arg(aAgzsName, QString::number(aLocalVCode), aTrkType, aDeviceName, aSerial, aFuelName,
            aFuelShortName, aSide, QString::number(aSideAdress), QString::number(aNozzle), QString::number(aTrkFuelCode))
            .arg(aTransNum, QString::number(aTrkTotalPrice), QString::number(aTrkVolume), QString::number(aTrkUnitPrice),
            QString::number(aRequestTotalPrice), QString::number(aRequestVolume), QString::number(aRequestUnitPrice), aRequestField, aState)
            .arg(QString::number(aIState), aTrkTransType, QString::number(aLitersCountBefore), QString::number(aMoneyCountBefore),
            QString::number(aTransCountBefore), QString::number(aLitersCountAfter), QString::number(aMoneyCountAfter),
            QString::number(aTransCountAfter), aResult, aDateOpen.toString("yyyyMMdd hh:mm:ss.zzz"))
            .arg(aDateClose.toString("yyyyMMdd hh:mm:ss.zzz"), QString::number(aTemperature), QString::number(aPayOperationVCode), aPayWay,
            QString::number(aPrePostPay), aWUser, aWDate.toString("yyyyMMdd hh:mm:ss.zzz"), aCUser, aCDate.toString("yyyyMMdd hh:mm:ss.zzz"),
            aCHost).arg(aWHost, QString::number(aVCode), QString::number(aAddedForTransVCode), QString::number(aAditionalTransVCode),
            QString::number(aActive), QString::number(aMass), QString::number(aSmena), QString::number(aTrkVcode), QString::number(aCapacityVcode),
            QString::number(aPumpPlace)).arg(QString::number(aMoneyTaken), QString::number(aIPayWay), QString::number(aAutoCheck),
            QString::number(aClosed), QString::number(aFullTank), QString::number(aAgzs), QString::number(aFuelVCode), QString::number(aPropan));

    return makeQuery(query, "createTrkTransaction", QueryType::qInsert);

//    int cycles = 0;
//    while (cycles < c_maxRestartCount) {
//        QSqlQuery query(db_);
//        query.prepare("INSERT INTO [agzs].[dbo].[ADAST_TRKTransaction] (AGZSName, LocalVCode, TrkType, DeviceName,	Serial,	FuelName, FuelShortName, Side, SideAddress, Nozzle, "
//                       "TrkFuelCode, TransNum, TrkTotalPriceDB, TrkVolumeDB, TrkUnitPriceDB, RequestTotalPriceDB, RequestVolumeDB, RequestUnitPriceDB, RequestField, State, iState, "
//                       "TrkTransType, LitersCountBeforeDB, MoneyCountBeforeDB, TransCountBefore, LitersCountAfterDB, MoneyCountAfterDB, TransCountAfter, Result, DateOpen, DateClose, "
//                       "TemperatureDB, PayOperationVCode, PayWay, PrePostPay, WUser, WDate, CUser, CDate, CHost, WHost, VCode, AddedForTransVCode, AditionalTransVCode, ActiveDB, "
//                       "MassDB, Smena, TrkVcode, CapacityVcode, PumpPlace, MoneyTakenDB, iPayWay, AutoCheckDB, Closed, FullTankDB, AGZS, FuelVCode, rowguid, Propan) "
//                      "VALUES(:AGZSName, :LocalVCode, :TrkType, :DeviceName, :Serial, :FuelName, :FuelShortName, :Side, :SideAddress, :Nozzle, :TrkFuelCode, :TransNum, "
//                       ":TrkTotalPriceDB, :TrkVolumeDB, :TrkUnitPriceDB, :RequestTotalPriceDB, :RequestVolumeDB, :RequestUnitPriceDB, :RequestField, :State, :iState, :TrkTransType, "
//                       ":LitersCountBeforeDB, :MoneyCountBeforeDB, :TransCountBefore, :LitersCountAfterDB, :MoneyCountAfterDB, :TransCountAfter, :Result, :DateOpen, :DateClose, "
//                       ":TemperatureDB, :PayOperationVCode, :PayWay, :PrePostPay, :WUser, :WDate, :CUser, :CDate, :CHost, :WHost, :VCode, :AddedForTransVCode, :AditionalTransVCode, "
//                       ":ActiveDB, :MassDB, :Smena, :TrkVcode, :CapacityVcode, :PumpPlace, :MoneyTakenDB, :iPayWay, :AutoCheckDB, :Closed, :FullTankDB, :AGZS, :FuelVCode, DEFAULT, "
//                       ":Propan)");
//        query.bindValue(":AGZSName", aAgzsName);
//        query.bindValue(":LocalVCode", aLocalVCode);
//        query.bindValue(":TrkType", aTrkType);
//        query.bindValue(":DeviceName", aDeviceName);
//        query.bindValue(":Serial", aSerial);
//        query.bindValue(":FuelName", aFuelName);
//        query.bindValue(":FuelShortName", aFuelShortName);
//        query.bindValue(":Side", aSide);
//        query.bindValue(":SideAddress", aSideAdress);
//        query.bindValue(":Nozzle", aNozzle);
//        query.bindValue(":TrkFuelCode", aTrkFuelCode);
//        query.bindValue(":TransNum", aTransNum);
//        query.bindValue(":TrkTotalPriceDB", aTrkTotalPrice);
//        query.bindValue(":TrkVolumeDB", aTrkVolume);
//        query.bindValue(":TrkUnitPriceDB", aTrkUnitPrice);
//        query.bindValue(":RequestTotalPriceDB", aRequestTotalPrice);
//        query.bindValue(":RequestVolumeDB", aRequestVolume);
//        query.bindValue(":RequestUnitPriceDB", aRequestUnitPrice);
//        query.bindValue(":RequestField", aRequestField);
//        query.bindValue(":State", aState);
//        query.bindValue(":iState", aIState);
//        query.bindValue(":TrkTransType", aTrkTransType);
//        query.bindValue(":LitersCountBeforeDB", aLitersCountBefore);
//        query.bindValue(":MoneyCountBeforeDB", aMoneyCountBefore);
//        query.bindValue(":TransCountBefore", aTransCountBefore);
//        query.bindValue(":LitersCountAfterDB", aLitersCountAfter);
//        query.bindValue(":MoneyCountAfterDB", aMoneyCountAfter);
//        query.bindValue(":TransCountAfter", aTransCountAfter);
//        query.bindValue(":Result", aResult);
//        query.bindValue(":DateOpen", aDateOpen.toString("yyyyMMdd hh:mm:ss.zzz"));
//        query.bindValue(":DateClose", aDateClose.toString("yyyyMMdd hh:mm:ss.zzz"));
//        query.bindValue(":TemperatureDB", aTemperature);
//        query.bindValue(":PayOperationVCode", aPayOperationVCode);
//        query.bindValue(":PayWay", aPayWay);
//        query.bindValue(":PrePostPay", aPrePostPay);
//        query.bindValue(":WUser", aWUser);
//        query.bindValue(":WDate", aWDate.toString("yyyyMMdd hh:mm:ss.zzz"));
//        query.bindValue(":CUser", aCUser);
//        query.bindValue(":CDate", aCDate.toString("yyyyMMdd hh:mm:ss.zzz"));
//        query.bindValue(":CHost", aCHost);
//        query.bindValue(":WHost", aWHost);
//        query.bindValue(":VCode", aVCode);
//        query.bindValue(":AddedForTransVCode", aAddedForTransVCode);
//        query.bindValue(":AditionalTransVCode", aAditionalTransVCode);
//        query.bindValue(":ActiveDB", aActive);
//        query.bindValue(":MassDB", aMass);
//        query.bindValue(":Smena", aSmena);
//        query.bindValue(":TrkVcode", aTrkVcode);
//        query.bindValue(":CapacityVcode", aCapacityVcode);
//        query.bindValue(":PumpPlace", aPumpPlace);
//        query.bindValue(":MoneyTakenDB", aMoneyTaken);
//        query.bindValue(":iPayWay", aIPayWay);
//        query.bindValue(":AutoCheckDB", aAutoCheck);
//        query.bindValue(":Closed", aClosed);
//        query.bindValue(":FullTankDB", aFullTank);
//        query.bindValue(":AGZS", aAgzs);
//        query.bindValue(":FuelVCode", aFuelVCode);
//        query.bindValue(":Propan", aPropan);
//        query.exec();
//        if (query.lastError().type() == QSqlError::NoError) {
//            return true;
//        } else {
//            openDB();
//             qWarning(logError) << query.lastError().type() << "createTrkTransaction" << cycles;
//        }
//        ++cycles;
//    }
//    return false;
}

bool DataBaseControl::createTrkTransaction(Transaction aTransaction) {
    return createTrkTransaction(aTransaction.agzsName, aTransaction.localVCode, aTransaction.trkType, aTransaction.deviceName, aTransaction.serial,
                                aTransaction.fuelName, aTransaction.fuelShortName, aTransaction.side, aTransaction.sideAdress, aTransaction.nozzle,
                                aTransaction.trkFuelCode, aTransaction.transNum, aTransaction.trkTotalPrice, aTransaction.trkVolume,
                                aTransaction.trkUnitPrice, aTransaction.requestTotalPrice, aTransaction.requestVolume, aTransaction.requestUnitPrice,
                                aTransaction.requestField, aTransaction.state, aTransaction.iState, aTransaction.trkTransType, aTransaction.litersCountBefore,
                                aTransaction.moneyCountBefore, aTransaction.transCountBefore, aTransaction.litersCountAfter, aTransaction.moneyCountAfter,
                                aTransaction.transCountAfter, aTransaction.result, aTransaction.dateOpen, aTransaction.dateClose, aTransaction.temperature,
                                aTransaction.payOperationVCode, aTransaction.payWay, aTransaction.prePostPay, aTransaction.wUser, aTransaction.wDate,
                                aTransaction.cUser, aTransaction.cDate, aTransaction.cHost, aTransaction.wHost, aTransaction.vCode, aTransaction.addedForTransVCode,
                                aTransaction.aditionalTransVCode, aTransaction.active, aTransaction.mass, aTransaction.smena, aTransaction.trkVcode,
                                aTransaction.capacityVcode, aTransaction.pumpPlace, aTransaction.moneyTaken, aTransaction.iPayWay,
                                aTransaction.autoCheck, aTransaction.closed, aTransaction.fullTank, aTransaction.agzs, aTransaction.fuelVCode,
                                aTransaction.propan);
}

bool DataBaseControl::createApiTransaction(QString aAgzsName, int aAgzs, QDateTime aCDate, int aVCode, QString aApiId, QString aApiStationExtendedId,
                                     int aApiColumnId, QString aApiFuelId, int aFuelId, int aApiPriceFuel, int aApiLitre, int aApiSum, QString aApiStatus,
                                     QString aApiContractId, QString aAgent, QString aLocalState, double aPrice, double aLitre, double aSum, QDateTime aDateOpen, int aLink) {

    QString query = getQuery("createApiTransaction").arg(aAgzsName, QString::number(aAgzs), aCDate.toString("yyyyMMdd hh:mm:ss.zzz"), QString::number(aVCode),
                                                    aApiId, aApiStationExtendedId, QString::number(aApiColumnId), aApiFuelId, QString::number(aFuelId),
                                                    QString::number(aApiPriceFuel)).arg(QString::number(aApiLitre), QString::number(aApiSum), aApiStatus,
                                                    aApiContractId, aAgent, aLocalState, QString::number(aPrice), QString::number(aLitre), QString::number(aSum),
                                                    aDateOpen.toString("yyyyMMdd hh:mm:ss.zzz")).arg(QString::number(aLink));

    return makeQuery(query, "createApiTransaction", QueryType::qInsert);

//    int cycles = 0;
//    while (cycles < c_maxRestartCount) {
//        QSqlQuery query(db_);
//        query.prepare("INSERT INTO [agzs].[dbo].[PR_APITransaction] ([AGZSName],[AGZS],[CDate],[VCode],[APIID],[APIStationExtendedId],[APIColumnId],[APIFuelId],[FuelId],"
//                        "[APIPriceFuel],[APILitre],[APISum],[APIStatus],[APIContractId],[agent],[localState],[Price],[Litre],[Sum],[DateOpen],[DateClose],[Link]) "
//                       "VALUES (:AGZSName, :AGZS, :CDate, :VCode, :APIID, :APIStationExtendedId, :APIColumnId, :APIFuelId, :FuelId, :APIPriceFuel, :APILitre, :APISum, "
//                        ":APIStatus, :APIContractId, :agent, :localState, :Price, :Litre, :Sum, :DateOpen, DEFAULT, :Link)");
//        query.bindValue(":AGZSName", aAgzsName);
//        query.bindValue(":AGZS", aAgzs);
//        query.bindValue(":CDate", aCDate.toString("yyyyMMdd hh:mm:ss.zzz"));
//        query.bindValue(":VCode", aVCode);
//        query.bindValue(":APIID", aApiId);
//        query.bindValue(":APIStationExtendedId", aApiStationExtendedId);
//        query.bindValue(":APIColumnId", aApiColumnId);
//        query.bindValue(":APIFuelId", aApiFuelId);
//        query.bindValue(":FuelId", aFuelId);
//        query.bindValue(":APIPriceFuel", aApiPriceFuel);
//        query.bindValue(":APILitre", aApiLitre);
//        query.bindValue(":APISum", aApiSum);
//        query.bindValue(":APIStatus", aApiStatus);
//        query.bindValue(":APIContractId", aApiContractId);
//        query.bindValue(":agent", aAgent);
//        query.bindValue(":localState", aLocalState);
//        query.bindValue(":Price", aPrice);
//        query.bindValue(":Litre", aLitre);
//        query.bindValue(":Sum", aSum);
//        query.bindValue(":DateOpen", aDateOpen.toString("yyyyMMdd hh:mm:ss.zzz"));
//        //q_APIRequests.bindValue(":DateClose", "DEFAULT");
//        query.bindValue(":Link", aLink);
//        if (query.exec()) {
//            return true;
//        } else  {
//            openDB();
//             qWarning(logError) << query.lastError().type() << "createApiTransaction" << cycles;
//        }
//        ++cycles;
//    }
//    return false;
}

bool DataBaseControl::updateApiTransactionLink(QString aApiId, int aLink) {
    return makeQuery(getQuery("updateApiTransactionLink").arg(QString::number(aLink), aApiId), "updateApiTransactionLink", QueryType::qUpdate);
}

ApiTransaction DataBaseControl::getApiTransaction(QString aId) {
    ApiTransaction trans;
    makeQuery(getQuery("getApiTransaction").arg(aId), "getApiTransaction", QueryType::qSelect, [&](QSqlQuery &query){
        trans.id = aId;
        trans.localState = query.value("localState").toString();
        trans.apiLitre = query.value("APILitre").toDouble();
        trans.transLitre = query.value("transLitre").toDouble();
        trans.apiVCode = query.value("apiVCode").toInt();
        trans.headVCode = query.value("headVCode").toInt();
        trans.iState = query.value("iState").toInt();
        trans.dateOpen = query.value("DateOpen").toDateTime();
        trans.dateClose = query.value("DateClose").toDateTime();
        trans.activeDB = query.value("ActiveDB").toInt();
    });
    return trans;

//    int cycles = 0;
//    while (cycles < c_maxRestartCount) {
//        QSqlQuery query(db_);
//        query.exec("SELECT api.localState, api.APILitre, api.VCode, h.VCode, b.iState, b.DateOpen, b.DateClose "
//                   "FROM [agzs].[dbo].[PR_APITransaction] api "
//                    "INNER JOIN [agzs].[dbo].[ADAST_TRKTransaction] h ON api.Link = h.VCode "
//                    "INNER JOIN [agzs].[dbo].[ADAST_TRKTransaction] b ON h.AditionalTransVCode = b.VCode "
//                   "WHERE api.APIID = '" + aId + "'");
//        if (query.lastError().type() == QSqlError::NoError) {
//            ApiTransaction trans;
//            while (query.next()){
//                trans.id = aId;
//                trans.localState = query.value(0).toString();
//                trans.apiLitre = query.value(1).toDouble();
//                trans.apiVCode = query.value(2).toInt();
//                trans.headVCode = query.value(3).toInt();
//                trans.iState = query.value(4).toInt();
//                trans.dateOpen = query.value(5).toDateTime();
//                trans.dateClose = query.value(6).toDateTime();
//                break;
//            }
//            return trans;
//        } else {
//            openDB();
//             qWarning(logError) << query.lastError().type() << "getApiTransactionState" << cycles;
//        }
//        ++cycles;
//    }
//    return ApiTransaction();
}

bool DataBaseControl::updateApiTransactionState(QString aLocalState, QDateTime aDateClose, int aVCode) {
    return makeQuery(getQuery("updateApiTransactionState").arg(aLocalState, aDateClose.toString("yyyyMMdd hh:mm:ss.zzz"),
                            QString::number(aVCode)), "updateApiTransactionState", QueryType::qUpdate);

//    int cycles = 0;
//    while (cycles < c_maxRestartCount) {
//        QSqlQuery query(db_);
//        query.prepare("UPDATE [agzs].[dbo].[PR_APITransaction] "
//                             "SET localState = :localState, DateClose = :date "
//                      "WHERE VCode = :VCode");
//        query.bindValue(":localState", aLocalState);
//        query.bindValue(":date",       aDateClose);
//        query.bindValue(":VCode",      aVCode);
//        query.exec();
//        if (query.lastError().type() == QSqlError::NoError) {
//            return true;
//        } else {
//            openDB();
//             qWarning(logError) << query.lastError().type() << "updateApiTransactionState" << cycles;
//        }
//        ++cycles;
//    }
//    return false;
}

bool DataBaseControl::finalUpdateApiTransactionState(QString aLocalState, double aPrice, double aVolume, double aAmount, QDateTime aDateOpen, QDateTime aDateClose, int aVCode) {
    return makeQuery(getQuery("finalUpdateApiTransactionState").arg(aLocalState, QString::number(aPrice), QString::number(aVolume),
                    QString::number(aAmount), aDateOpen.toString("yyyyMMdd hh:mm:ss.zzz"), aDateClose.toString("yyyyMMdd hh:mm:ss.zzz"),
                    QString::number(aVCode)), "finalUpdateApiTransactionState", QueryType::qUpdate);

//    int cycles = 0;
//    while (cycles < c_maxRestartCount) {
//        QSqlQuery query(db_);
//        query.prepare("UPDATE [agzs].[dbo].[PR_APITransaction] "
//                        "SET localState = :localState, "
//                           "[Price] = :price, "
//                           "[Litre] = :litre, "
//                           "[Sum] = :sum, "
//                           "[DateOpen] = :dateOpen, "
//                           "DateClose = :dateClose "
//                      "WHERE VCode = :VCode");
//        query.bindValue(":localState", aLocalState);
//        query.bindValue(":price",      aPrice);
//        query.bindValue(":litre",      aVolume);
//        query.bindValue(":sum",        aAmount);
//        query.bindValue(":dateOpen",   aDateOpen);
//        query.bindValue(":dateClose",  aDateClose);
//        query.bindValue(":VCode",      aVCode);
//        query.exec();
//        if (query.lastError().type() == QSqlError::NoError) {
//            return true;
//        } else {
//            openDB();
//             qWarning(logError) << query.lastError().type() << "finalUpdateApiTransactionState" << cycles;
//        }
//        ++cycles;
//    }
//    return false;
}

bool DataBaseControl::getPayOperationData(int aLink, double &aAmount, double &aVolume, double &aPrice, QDateTime &aDateStart, QDateTime &aDateEnd) {
    bool isExist = false;
    isExist = makeQuery(getQuery("getPayOperationData").arg(QString::number(aLink)), "getPayOperationData", QueryType::qSelect, [&](QSqlQuery &query){
        aAmount = query.value("AmountDB").toDouble();
        aPrice = query.value("PriceDB").toDouble();
        aVolume = query.value("VolumeDB").toDouble();
        aDateStart = query.value("DateOpen").toDateTime();
        aDateEnd = query.value("DateClose").toDateTime();
    });
    return isExist;

//    int cycles = 0;
//    while (cycles < 2) {
//        QSqlQuery query(db_);
//        query.exec( "SELECT [AmountDB], [PriceDB], [VolumeDB], [DateOpen], [DateClose] "
//                    "FROM [agzs].[dbo].[ARM_PayOperation] p "
//                        "INNER JOIN "
//                    "agzs.dbo.ADAST_TRKTransaction t "
//                        "on (p.Link = t.VCode) "
//                    "WHERE t.VCode = " + QString::number(aLink));
//        if (query.lastError().type() == QSqlError::NoError) {
//            if (query.next()) {
//                aAmount = query.value(0).toDouble();
//                aPrice = query.value(1).toDouble();
//                aVolume = query.value(2).toDouble();
//                aDateStart = query.value(3).toDateTime();
//                aDateEnd = query.value(4).toDateTime();
//                return true;
//            } else {
//                 qWarning(logError) << query.lastError().type() << "getPayOperationLiters" << aLink << cycles;
//                 qWarning(logError) << query.lastError().type() << query.lastQuery();
//                openDB();
//            }
//        }
//        ++cycles;
//    }
//    return false;
}

bool DataBaseControl::setTransactionClosed(QString aId, int aClosed) {
    return makeQuery(getQuery("setTransactionClosed").arg(aId, QString::number(aClosed)), "setTransactionClosed", QueryType::qUpdate);

//    int cycles = 0;
//    while (cycles < c_maxRestartCount) {
//        QSqlQuery query(db_);
//        query.prepare("UPDATE [agzs].[dbo].[ADAST_TRKTransaction] "
//                             "SET Closed = :closed "
//                      "WHERE VCode in (SELECT Link "
//                                     "FROM [agzs].[dbo].[PR_APITransaction] "
//                                     "WHERE ApiId = :id)");
//        query.bindValue(":closed", aClosed);
//        query.bindValue(":id",     aId);
//        query.exec();
//        if (query.lastError().type() == QSqlError::NoError) {
//            return true;
//        } else {
//            openDB();
//             qWarning(logError) << query.lastError().type() << "setTransactionClosed" << cycles;
//        }
//        ++cycles;
//    }
//    return false;
}

Transaction DataBaseControl::getTransaction(int aVCode) {
    Transaction transaction;
    makeQuery(getQuery("getTransaction").arg(QString::number(aVCode)), "getTransaction", QueryType::qSelect, [&](QSqlQuery &query) {
        transaction.agzsName = query.value("AGZSName").toString();
        transaction.localVCode = query.value("LocalVCode").toInt();
        transaction.trkType = query.value("TrkType").toString();
        transaction.deviceName = query.value("DeviceName").toString();
        transaction.serial = query.value("Serial").toString();
        transaction.fuelName = query.value("FuelName").toString();
        transaction.fuelShortName = query.value("FuelShortName").toString();
        transaction.side = query.value("Side").toString();
        transaction.sideAdress = query.value("SideAddress").toInt();
        transaction.nozzle = query.value("Nozzle").toInt();
        transaction.trkFuelCode = query.value("TrkFuelCode").toInt();
        transaction.transNum = query.value("TransNum").toString();
        transaction.trkTotalPrice = query.value("TrkTotalPriceDB").toDouble();
        transaction.trkVolume = query.value("TrkVolumeDB").toDouble();
        transaction.trkUnitPrice = query.value("TrkUnitPriceDB").toDouble();
        transaction.requestTotalPrice = query.value("RequestTotalPriceDB").toDouble();
        transaction.requestVolume = query.value("RequestVolumeDB").toDouble();
        transaction.requestUnitPrice = query.value("RequestUnitPriceDB").toDouble();
        transaction.requestField = query.value("RequestField").toString();
        transaction.state = query.value("State").toString();
        transaction.iState = query.value("iState").toInt();
        transaction.trkTransType = query.value("TrkTransType").toString();
        transaction.litersCountBefore = query.value("LitersCountBeforeDB").toDouble();
        transaction.moneyCountBefore = query.value("MoneyCountBeforeDB").toDouble();
        transaction.transCountBefore = query.value("TransCountBefore").toInt();
        transaction.litersCountAfter = query.value("LitersCountAfterDB").toDouble();
        transaction.moneyCountAfter = query.value("MoneyCountAfterDB").toDouble();
        transaction.transCountAfter = query.value("TransCountAfter").toInt();
        transaction.result = query.value("Result").toString();
        transaction.dateOpen = query.value("DateOpen").toDateTime();
        transaction.dateClose = query.value("DateClose").toDateTime();
        transaction.temperature = query.value("TemperatureDB").toDouble();
        transaction.payOperationVCode = query.value("PayOperationVCode").toInt();
        transaction.payWay = query.value("PayWay").toString();
        transaction.prePostPay = query.value("PrePostPay").toInt();
        transaction.wUser = query.value("WUser").toString();
        transaction.wDate = query.value("WDate").toDateTime();
        transaction.cUser = query.value("CUser").toString();
        transaction.cDate = query.value("CDate").toDateTime();
        transaction.cHost = query.value("CHost").toString();
        transaction.wHost = query.value("WHost").toString();
        transaction.vCode = query.value("VCode").toInt();
        transaction.addedForTransVCode = query.value("AddedForTransVCode").toInt();
        transaction.aditionalTransVCode = query.value("AditionalTransVCode").toInt();
        transaction.active = query.value("ActiveDB").toInt();
        transaction.mass = query.value("MassDB").toDouble();
        transaction.smena = query.value("Smena").toInt();
        transaction.trkVcode = query.value("TrkVcode").toInt();
        transaction.capacityVcode = query.value("CapacityVcode").toInt();
        transaction.pumpPlace = query.value("PumpPlace").toInt();
        transaction.moneyTaken = query.value("MoneyTakenDB").toDouble();
        transaction.iPayWay = query.value("iPayWay").toInt();
        transaction.autoCheck = query.value("AutoCheckDB").toInt();
        transaction.closed = query.value("Closed").toInt();
        transaction.fullTank = query.value("FullTankDB").toInt();
        transaction.agzs = query.value("AGZS").toInt();
        transaction.fuelVCode = query.value("FuelVCode").toInt();
        transaction.propan = query.value("Propan").toInt();
    });
    return transaction;

//    int cycles = 0;
//    while (cycles < c_maxRestartCount) {
//        QSqlQuery query(db_);
//            query.prepare("SELECT AGZSName, LocalVCode, TrkType, DeviceName,	Serial,	FuelName, FuelShortName, Side, SideAddress, Nozzle, "
//                          "TrkFuelCode, TransNum, TrkTotalPriceDB, TrkVolumeDB, TrkUnitPriceDB, RequestTotalPriceDB, RequestVolumeDB, RequestUnitPriceDB, RequestField, State, iState, "
//                          "TrkTransType, LitersCountBeforeDB, MoneyCountBeforeDB, TransCountBefore, LitersCountAfterDB, MoneyCountAfterDB, TransCountAfter, Result, DateOpen, DateClose, "
//                          "TemperatureDB, PayOperationVCode, PayWay, PrePostPay, WUser, WDate, CUser, CDate, CHost, WHost, VCode, AddedForTransVCode, AditionalTransVCode, ActiveDB, "
//                          "MassDB, Smena, TrkVcode, CapacityVcode, PumpPlace, MoneyTakenDB, iPayWay, AutoCheckDB, Closed, FullTankDB, AGZS, FuelVCode, Propan"
//                          "[TrkTotalPriceDB] "
//                          "FROM [agzs].[dbo].[ADAST_TRKTransaction] "
//                          "WHERE VCode = :VCode");
//            query.bindValue(":VCode", aVCode);
//            query.exec();
//        if (query.lastError().type() == QSqlError::NoError) {
//            Transaction transaction;
//            if (query.next()) {
//                transaction.agzsName = query.value(0).toString();
//                transaction.localVCode = query.value(1).toInt();
//                transaction.trkType = query.value(2).toString();
//                transaction.deviceName = query.value(3).toString();
//                transaction.serial = query.value(4).toString();
//                transaction.fuelName = query.value(5).toString();
//                transaction.fuelShortName = query.value(6).toString();
//                transaction.side = query.value(7).toString();
//                transaction.sideAdress = query.value(8).toInt();
//                transaction.nozzle = query.value(9).toInt();
//                transaction.trkFuelCode = query.value(10).toInt();
//                transaction.transNum = query.value(11).toString();
//                transaction.trkTotalPrice = query.value(12).toDouble();
//                transaction.trkVolume = query.value(13).toDouble();
//                transaction.trkUnitPrice = query.value(14).toDouble();
//                transaction.requestTotalPrice = query.value(15).toDouble();
//                transaction.requestVolume = query.value(16).toDouble();
//                transaction.requestUnitPrice = query.value(17).toDouble();
//                transaction.requestField = query.value(18).toString();
//                transaction.state = query.value(19).toString();
//                transaction.iState = query.value(20).toInt();
//                transaction.trkTransType = query.value(21).toString();
//                transaction.litersCountBefore = query.value(22).toDouble();
//                transaction.moneyCountBefore = query.value(23).toDouble();
//                transaction.transCountBefore = query.value(24).toInt();
//                transaction.litersCountAfter = query.value(25).toDouble();
//                transaction.moneyCountAfter = query.value(26).toDouble();
//                transaction.transCountAfter = query.value(27).toInt();
//                transaction.result = query.value(28).toString();
//                transaction.dateOpen = query.value(29).toDateTime();
//                transaction.dateClose = query.value(30).toDateTime();
//                transaction.temperature = query.value(31).toDouble();
//                transaction.payOperationVCode = query.value(32).toInt();
//                transaction.payWay = query.value(33).toString();
//                transaction.prePostPay = query.value(34).toInt();
//                transaction.wUser = query.value(35).toString();
//                transaction.wDate = query.value(36).toDateTime();
//                transaction.cUser = query.value(37).toString();
//                transaction.cDate = query.value(38).toDateTime();
//                transaction.cHost = query.value(39).toString();
//                transaction.wHost = query.value(40).toString();
//                transaction.vCode = query.value(41).toInt();
//                transaction.addedForTransVCode = query.value(42).toInt();
//                transaction.aditionalTransVCode = query.value(43).toInt();
//                transaction.active = query.value(44).toInt();
//                transaction.mass = query.value(45).toDouble();
//                transaction.smena = query.value(46).toInt();
//                transaction.trkVcode = query.value(47).toInt();
//                transaction.capacityVcode = query.value(48).toInt();
//                transaction.pumpPlace = query.value(49).toInt();
//                transaction.moneyTaken = query.value(50).toDouble();
//                transaction.iPayWay = query.value(51).toInt();
//                transaction.autoCheck = query.value(52).toInt();
//                transaction.closed = query.value(53).toInt();
//                transaction.fullTank = query.value(54).toInt();
//                transaction.agzs = query.value(55).toInt();
//                transaction.fuelVCode = query.value(56).toInt();
//                transaction.propan = query.value(57).toInt();
//            }
//            return transaction;
//        } else {
//            openDB();
//             qWarning(logError) << query.lastError().type() << "getTransactionData" << cycles;
//        }
//        ++cycles;
//    }
//    return Transaction();
}

QList<ApiTransaction> DataBaseControl::getOpenedApiTransactions(int aPartner) {
    QList<ApiTransaction> list;
    makeQuery(getQuery("getOpenedApiTransactions").arg(QString::number(aPartner)), "getOpenedApiTransactions", QueryType::qSelect, [&](QSqlQuery &query) {
        do {
            ApiTransaction trans;
            trans.id = query.value("APIID").toString();
            trans.localState = query.value("localState").toString();
            trans.apiLitre = query.value("APILitre").toDouble();
            trans.apiVCode = query.value("apiVCode").toInt();
            trans.headVCode = query.value("transVCode").toInt();
            trans.dateOpen = query.value("DateOpen").toDateTime();
            trans.dateClose = query.value("DateClose").toDateTime();
            list.append(trans);
        } while (query.next());
    }, false);
    return list;

//    QList<ApiTransaction> list;
//    QSqlQuery query(db_);
//    query.exec("SELECT [APIID] "
//                   ",[localState] "
//                   ",[APILitre] "
//                   ",a.[VCode] "
//                   ",t.VCode "
//                   ",a.[DateOpen] "
//                   ",a.[DateClose] "
//               "FROM [agzs].[dbo].[PR_APITransaction] a "
//               "INNER JOIN [agzs].[dbo].[ADAST_TRKTransaction] t "
//                 "ON (a.Link = t.vcode) "
//               "WHERE ((SELECT count(*) FROM agzs.dbo.ARM_PayOperation p WHERE p.Link = t.VCode) = 0) "
//                 "and t.iPayWay = " + QString::number(aPartner) + " "
//                 "and localState <> 'Ошибка: 30 минут' "
//                 "and localState <> 'Отменена' "
//                 "and t.agzs = (SELECT TOP 1 AGZS "
//                             "FROM [agzs].[dbo].[Identification]) "
//               "ORDER BY DateOpen desc ");
//    while (query.next()) {
//        ApiTransaction trans;
//        trans.id = query.value(0).toString();
//        trans.localState = query.value(1).toString();
//        trans.apiLitre = query.value(2).toDouble();
//        trans.apiVCode = query.value(3).toInt();
//        trans.headVCode = query.value(4).toInt();
//        trans.dateOpen = query.value(5).toDateTime();
//        trans.dateClose = query.value(6).toDateTime();
//        list.append(trans);
//    }
//    return list;
}

int DataBaseControl::getCurrentAgzs() {
    int agzs = -1;
    makeQuery(getQuery("getCurrentAgzs"), "getCurrentAgzs", QueryType::qSelect, [&](QSqlQuery &query) {
        agzs = query.value("AGZS").toInt();
    });
    return agzs;

//    QSqlQuery query(db_);
//    query.exec("SELECT TOP 1 AGZS "
//                "FROM [agzs].[dbo].[Identification] ");
//    if (query.next()) {
//        return query.value(0).toInt();
//    }
//    return 0;
}

int DataBaseControl::generateVCode(QString aKey) {
    int vcode = -1;
    makeQuery(getQuery("generateVCode").arg(aKey), "generateVCode", QueryType::qProcedure, [&](QSqlQuery &query) {
        vcode = query.value(0).toInt();
    });
    return vcode;

//    int vcode = -1;
//    makeQuery(getQuery("getLastVCode").arg(aKey), "getLastVCode", QueryType::qSelect, [&](QSqlQuery &query) {
//        vcode = query.value(0).toInt();
//    });
//    if ((vcode > -1) && aUpdate) {
//        makeQuery(getQuery("updateLastVCode").arg(aKey), "updateLastVCode", QueryType::qUpdate);
//    }
//    return vcode;

//    QSqlQuery query(db_);
//        query.exec("SELECT TOP 1 Value "
//                   "FROM [agzs].[dbo].[LxKeysOfCodes] "
//                   "WHERE [Key] = '" + aKey + "'");
//    if (query.next()) {
//        int vcode = query.value(0).toInt();
//        if (aUpdate) {
//            query.exec("UPDATE [agzs].[dbo].[LxKeysOfCodes] "
//                             "SET Value = Value + 1 "
//                       "WHERE [Key] = '" + aKey + "'");
//        }
//        return vcode;
//    } else {
//        openDB();
//        return 0;
//    }
}

ErrorsOrder DataBaseControl::checkError(QString aColumnID, QString aFuelID, int aiFuelID, QString aPriceFuel, int aIPartner) {
    QSqlQuery query(db_);
    query.exec(QString("SELECT d.AGZS, d.VCode, d.Id "
               "FROM [agzs].[dbo].PR_AGZSData d "
                     "INNER JOIN [agzs].[dbo].[ADAST_AdastTRK] t ON d.AGZS = t.AGZS "
               "WHERE d.AGZS = (SELECT TOP 1 AGZS "
                               "FROM [agzs].[dbo].[Identification]) "
                    "AND ((t.[SideA_Address] = %1) OR (t.[SideB_Address] = %1)) "
               "ORDER BY d.CDate DESC").arg(aColumnID));
    if (query.next()) {
        query.exec(QString("SELECT d.AGZS, d.VCode, d.Id "
                     "FROM [agzs].[dbo].PR_AGZSData d "
                         "INNER JOIN [agzs].[dbo].[ADAST_AdastTRK] t "
                         "ON d.AGZS = t.AGZS "
                     "WHERE d.AGZS = (SELECT TOP 1 AGZS "
                                    "FROM [agzs].[dbo].[Identification]) "
                        "AND (((t.[SideA_Address] = %1) AND (([SideA_Nozzle1Fuel] = %2) "
                                                        "OR ([SideA_Nozzle2Fuel] = %2) "
                                                        "OR ([SideA_Nozzle3Fuel] = %2) "
                                                        "OR ([SideA_Nozzle4Fuel] = %2) "
                                                        "OR ([SideA_Nozzle5Fuel] = %2))) "
                           "OR (t.[SideB_Address] = %1) AND (([SideB_Nozzle1Fuel] = %2) "
                                                        "OR ([SideB_Nozzle2Fuel] = %2) "
                                                        "OR ([SideB_Nozzle3Fuel] = %2) "
                                                        "OR ([SideB_Nozzle4Fuel] = %2) "
                                                        "OR ([SideB_Nozzle5Fuel] = %2))) "
                     "ORDER BY d.CDate DESC").arg(aColumnID, QString::number(aiFuelID)));
        if (query.next()) {
            query.exec(QString("SELECT d.AGZS, d.VCode, d.Id, p.[" + aFuelID + "] "
                        "FROM [agzs].[dbo].PR_AGZSData d "
                             "INNER JOIN [agzs].[dbo].[ADAST_AdastTRK] t "
                             "ON d.AGZS = t.AGZS "
                             "INNER JOIN [agzs].[dbo].PR_AGZSPrice p "
                             "ON d.VCode = p.Link "
                        "WHERE d.AGZS = (SELECT TOP 1 AGZS "
                                        "FROM [agzs].[dbo].[Identification]) "
                            "AND (((t.[SideA_Address] = %1) AND (([SideA_Nozzle1Fuel] = %2) "
                                                            "OR ([SideA_Nozzle2Fuel] = %2) "
                                                            "OR ([SideA_Nozzle3Fuel] = %2) "
                                                            "OR ([SideA_Nozzle4Fuel] = %2) "
                                                            "OR ([SideA_Nozzle5Fuel] = %2))) "
                               "OR (t.[SideB_Address] = %1) AND (([SideB_Nozzle1Fuel] = %2) "
                                                            "OR ([SideB_Nozzle2Fuel] = %2) "
                                                            "OR ([SideB_Nozzle3Fuel] = %2) "
                                                            "OR ([SideB_Nozzle4Fuel] = %2) "
                                                            "OR ([SideB_Nozzle5Fuel] = %2))) "
                            "and p.[%3] = %4 "
                            "and p.iPartner = %5 "
                        "ORDER BY d.CDate DESC").arg(aColumnID, QString::number(aiFuelID), aFuelID, aPriceFuel, QString::number(aIPartner)));
            if (query.next()) {
                return ErrorsOrder::noError;
            } else {
                return ErrorsOrder::priceError;
            }
        } else {
            return ErrorsOrder::fuelError;
        }
    } else {
        return ErrorsOrder::trkError;
    }
}

bool DataBaseControl::updateYandexToken(QString aToken) {
    return makeQuery(getQuery("updateYandexToken").arg(aToken), "updateYandexToken", QueryType::qUpdate);

//    QSqlQuery query(db_);
//    query.prepare("UPDATE [grimnir].[agzs].[dbo].[PR_AGZSData] "
//                         "SET [YandexToken] = :token "
//                  "WHERE AGZS = (SELECT TOP 1 AGZS "
//                                "FROM [agzs].[dbo].[Identification]) ");
//    query.bindValue(":token", aToken);
//    query.exec();
//    if (query.lastError().type() == QSqlError::NoError) {
//        return true;
//    } else {
//         qWarning(logError) << query.lastError().type() << "setYandexToken" << aToken;
//        return false;
//    }
}

QString DataBaseControl::getCityMobileToken() {
    QString token;
    makeQuery(getQuery("getCityMobileToken"), "getCityMobileToken", QueryType::qSelect, [&](QSqlQuery &query) {
        token = query.value("CityMobileToken").toString();
    });
    return token;

//    QSqlQuery query(db_);
//    query.exec("SELECT TOP 1 [CityMobileToken] "
//            "FROM [agzs].[dbo].[PR_AGZSData] "
//            "WHERE AGZS = (SELECT TOP 1 AGZS "
//                          "FROM [agzs].[dbo].[Identification]) ");
//    if (query.next()) {
//        return query.value(0).toString();
//    } else {
//         qWarning(logError) << query.lastError().type() << "getCityMobileToken";
//        return "";
//    }
}

bool DataBaseControl::isApiTransactionExist(QString aApiId) {
    return makeQuery(getQuery("isApiTransactionExistId").arg(aApiId), "isApiTransactionExistId", QueryType::qSelect, [&](QSqlQuery &query) {
        if (query.isNull(0)) {
            return true;
        } else {
            return false;
        }
    });

//    QSqlQuery query(db_);
//    query.prepare("SELECT [APIID] "
//                  "FROM [agzs].[dbo].[PR_APITransaction] "
//                  "WHERE APIID = :id ");
//    query.bindValue(":id", aApiId);
//    query.exec();
//    if (query.next()) {
//        return true;
//    } else {
//        return false;
//    }
}

bool DataBaseControl::isApiTransactionExist(int aVCode) {
    return makeQuery(getQuery("isApiTransactionExistVCode").arg(QString::number(aVCode)), "isApiTransactionExistVCode", QueryType::qSelect, [&](QSqlQuery &query) {
        if (query.isNull(0)) {
            return true;
        } else {
            return false;
        }
    });

//    QSqlQuery query(db_);
//    query.prepare("SELECT [APIID] "
//                  "FROM [agzs].[dbo].[PR_APITransaction] "
//                  "WHERE VCode = :vcode ");
//    query.bindValue(":vcode", aVCode);
//    query.exec();
//    if (query.next()) {
//        return true;
//    } else {
//        return false;
//    }
}
