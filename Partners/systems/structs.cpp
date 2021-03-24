#include "structs.h"

OrderStatus stringToStatus(QString aStatus) {
    if (aStatus == "AcceptOrder") {
        return OrderStatus::acceptOrder;
    }
    if (aStatus == "WaitingRefueling") {
        return OrderStatus::waitingRefueling;
    }
    if (aStatus == "Fueling") {
        return OrderStatus::fueling;
    }
    if (aStatus == "Expire") {
        return OrderStatus::expire;
    }
    if (aStatus == "StationCanceled") {
        return OrderStatus::stationCanceled;
    }
    if (aStatus == "UserCanceled") {
        return OrderStatus::userCanceled;
    }
    if (aStatus == "Completed") {
        return OrderStatus::completed;
    }
    return OrderStatus::unknown;
}

Order Order::fromJson(int aiPayWay, QJsonValue aOrder) {
    Order order;
    switch (aiPayWay) {
    case c_yandexIPayWay: {
        order.id = aOrder.toObject().value("id").toString();
        order.dateCreate = QDateTime::fromString(aOrder.toObject().value("dateCreate").toString().left(23), "yyyy-MM-ddThh:mm:ss.zzz");
        order.orderType = aOrder.toObject().value("orderType").toString();
        order.orderVolume = aOrder.toObject().value("orderVolume").toDouble();
        order.columnId = aOrder.toObject().value("columnId").toInt();
        order.litre = aOrder.toObject().value("litre").toDouble();
        order.status = aOrder.toObject().value("status").toString();
        order.fuel = apiToFuel(aOrder.toObject().value("fuelId").toString());
        order.priceFuel = aOrder.toObject().value("priceFuel").toDouble();
        order.sum = aOrder.toObject().value("sum").toDouble();
        order.contractId = aOrder.toObject().value("contractId").toString();

        if (order.orderType == "Money") {
            order.moneyData.requestTotalPriceDB = order.orderVolume;
            order.moneyData.requestUnitPriceDB = order.priceFuel;
            int temp = (order.moneyData.requestTotalPriceDB / order.moneyData.requestUnitPriceDB) * 100;
            order.moneyData.requestVolumeDB = temp / 100;
            order.moneyData.moneyTakenDB = order.orderVolume;
            order.moneyData.fullTankDB = 0;
        } else if (order.orderType == "Liters") {
            order.moneyData.requestVolumeDB = order.orderVolume;
            order.moneyData.requestUnitPriceDB = order.priceFuel;
            order.moneyData.requestTotalPriceDB = order.moneyData.requestVolumeDB * order.moneyData.requestUnitPriceDB;
            order.moneyData.moneyTakenDB = order.orderVolume;
            order.moneyData.fullTankDB = 0;
        } else if (order.orderType == "FullTank") {
            order.moneyData.requestTotalPriceDB = order.orderVolume;
            order.moneyData.requestUnitPriceDB = order.priceFuel;
            int temp = (order.moneyData.requestTotalPriceDB / order.moneyData.requestUnitPriceDB) * 100;
            order.moneyData.requestVolumeDB = temp / 100;
            order.moneyData.moneyTakenDB = order.orderVolume;
            order.moneyData.fullTankDB = 1;
        }
        break;
    }
    case c_cityMobileIPayWay: {
//            {
//            "Id": "088ccc98-73e3-4b4a-aaa9-79dddd02720a",
//            "DateCreate" :  "2019-11-20T17:28:33.994Z",
//            "OrderType":  "Litre",
//            "OrderVolume": "10",
//            -"StationId":  "1234",
//            -"StationExtendedId":  "1234",
//            "ColumnId":  "1",
//            "FuelId":  "a92",
//            "PriceFuel":  "42.50",
//            "Litre":  "10",
//            "Sum":  "425.00",
//            "Status":  "OrderCreated",
//            "ContractId":  "32135"
//            }
        Order order;
        order.id = aOrder.toObject().value("id").toString();
        order.dateCreate = QDateTime::fromString(aOrder.toObject().value("dateCreate").toString().left(23), "yyyy-MM-ddThh:mm:ss.zzz");
        order.orderType = aOrder.toObject().value("orderType").toString();
        order.orderVolume = aOrder.toObject().value("orderVolume").toDouble();
        order.columnId = aOrder.toObject().value("columnId").toInt();
        order.litre = aOrder.toObject().value("litre").toDouble();
        order.status = aOrder.toObject().value("status").toString();
        order.fuel = apiToFuel(aOrder.toObject().value("fuelId").toString());
        order.priceFuel = aOrder.toObject().value("priceFuel").toDouble();
        order.sum = aOrder.toObject().value("sum").toDouble();
        order.contractId = aOrder.toObject().value("contractId").toString();

        if (order.orderType == "Money") {
            order.moneyData.requestTotalPriceDB = order.orderVolume;
            order.moneyData.requestUnitPriceDB = order.priceFuel;
            int temp = (order.moneyData.requestTotalPriceDB / order.moneyData.requestUnitPriceDB) * 100;
            order.moneyData.requestVolumeDB = temp / 100;
            order.moneyData.moneyTakenDB = order.orderVolume;
            order.moneyData.fullTankDB = 0;
        } else if (order.orderType == "Liters") {
            order.moneyData.requestVolumeDB = order.orderVolume;
            order.moneyData.requestUnitPriceDB = order.priceFuel;
            order.moneyData.requestTotalPriceDB = order.moneyData.requestVolumeDB * order.moneyData.requestUnitPriceDB;
            order.moneyData.moneyTakenDB = order.orderVolume;
            order.moneyData.fullTankDB = 0;
        } else if (order.orderType == "FullTank") {
            order.moneyData.requestTotalPriceDB = order.orderVolume;
            order.moneyData.requestUnitPriceDB = order.priceFuel;
            int temp = (order.moneyData.requestTotalPriceDB / order.moneyData.requestUnitPriceDB) * 100;
            order.moneyData.requestVolumeDB = temp / 100;
            order.moneyData.moneyTakenDB = order.orderVolume;
            order.moneyData.fullTankDB = 1;
        }
        break;
    }
    }
    return order;
}

QString errorToString(ErrorsOrder aError) {
    switch (aError) {
    case ErrorsOrder::noError: {
        return "0";
    }
    case ErrorsOrder::trkError: {
        return "Error: trk is not found";
    }
    case ErrorsOrder::fuelError: {
        return "Error: fuel is not found";
    }
    case ErrorsOrder::priceError: {
        return "Error: different price";
    }
    default : {
        return "";
    }
    }
}

QString fuelToApi(Fuel aFuel) {
    switch(aFuel) {
    case Fuel::diesel: {
        return "diesel";
    }
    case Fuel::diesel_premium: {
        return "diesel_premium";
    }
    case Fuel::a80: {
        return "a80";
    }
    case Fuel::a92: {
        return "a92";
    }
    case Fuel::a92_premium: {
        return "a92_premium";
    }
    case Fuel::a95: {
        return "a95";
    }
    case Fuel::a95_premium: {
        return "a95_premium";
    }
    case Fuel::a98: {
        return "a98";
    }
    case Fuel::a98_premium: {
        return "a98_premium";
    }
    case Fuel::a100: {
        return "a100";
    }
    case Fuel::a100_premium: {
        return "a100_premium";
    }
    case Fuel::propane: {
        return "propane";
    }
    case Fuel::metan: {
        return "metan";
    }
    default: {
        return "";
    }
    }
}

QString fuelToName(Fuel aFuel) {
    switch(aFuel) {
    case Fuel::diesel: {
        return "Дизель";
    }
    case Fuel::diesel_premium: {
        return "Дизель премиум";
    }
    case Fuel::a80: {
        return "А-80";
    }
    case Fuel::a92: {
        return "А-92";
    }
    case Fuel::a92_premium: {
        return "А-92 премиум";
    }
    case Fuel::a95: {
        return "А-95";
    }
    case Fuel::a95_premium: {
        return "А-95 премиум";
    }
    case Fuel::a98: {
        return "А-98";
    }
    case Fuel::a98_premium: {
        return "А-98 премиум";
    }
    case Fuel::a100: {
        return "А-100";
    }
    case Fuel::a100_premium: {
        return "А-100 премиум";
    }
    case Fuel::propane: {
        return "Пропан";
    }
    case Fuel::metan: {
        return "Метан";
    }
    default: {
        return "";
    }
    }
}

Fuel apiToFuel(QString aFuel) {
    if (aFuel == "diesel") {
        return Fuel::diesel;
    }
    if (aFuel == "diesel_premium") {
        return Fuel::diesel_premium;
    }
    if (aFuel == "a80") {
        return Fuel::a80;
    }
    if (aFuel == "a92") {
        return Fuel::a92;
    }
    if (aFuel == "a92_premium") {
        return Fuel::a92_premium;
    }
    if (aFuel == "a95") {
        return Fuel::a95;
    }
    if (aFuel == "a95_premium") {
        return Fuel::a95_premium;
    }
    if (aFuel == "a98") {
        return Fuel::a98;
    }
    if (aFuel == "a98_premium") {
        return Fuel::a98_premium;
    }
    if (aFuel == "a100") {
        return Fuel::a100;
    }
    if (aFuel == "a100_premium") {
        return Fuel::a100_premium;
    }
    if (aFuel == "propane") {
        return Fuel::propane;
    }
    if (aFuel == "metan") {
        return Fuel::metan;
    }
    return Fuel::unknown;
}

Transaction Transaction::createTransaction(Agzs agzs, int transactionVCode, AdastTrk trk, FuelNames fuelName,
                                           int sideAdress, Order order, QDateTime date, QString payWay,
                                           int iPayWay, int smena, int cashBoxIndex) {
    Transaction transaction;
    transaction.agzsName = agzs.agzsName;
    transaction.localVCode = transactionVCode;
    transaction.deviceName = trk.deviceName;
    transaction.serial = trk.serial;
    transaction.fuelName = fuelName.fullName;
    transaction.fuelShortName = fuelName.shortName;
    transaction.side = trk.side;
    transaction.sideAdress = sideAdress;
    transaction.nozzle = trk.getNozzle(order.fuel);
    transaction.trkFuelCode = trk.getFuelCode(order.fuel);
    transaction.requestTotalPrice = order.moneyData.requestTotalPriceDB;
    transaction.requestVolume = order.moneyData.requestVolumeDB;
    transaction.requestUnitPrice = order.moneyData.requestUnitPriceDB;
    transaction.dateOpen = date;
    transaction.dateClose = date;
    transaction.payWay = payWay;
    transaction.cDate = date;
    transaction.wDate = date;
    transaction.vCode = transactionVCode;
    transaction.smena = smena;
    transaction.trkVcode = trk.trkVCode;
    transaction.capacityVcode = cashBoxIndex;
    transaction.pumpPlace = trk.pumpPlace;
    transaction.moneyTaken = order.moneyData.moneyTakenDB;
    transaction.iPayWay = iPayWay;
    transaction.fullTank = order.moneyData.fullTankDB;
    transaction.agzs = agzs.agzs;
    transaction.fuelVCode = static_cast<int>(order.fuel);
    transaction.propan = 0;
    return transaction;
}

bool Price::operator!=(const Price &price) {
    return (diesel != price.diesel) || (diesel_premium != price.diesel_premium) || (a80 != price.a80) ||
            (a92 != price.a92) || (a92_premium != price.a92_premium) ||
            (a95 != price.a95) || (a95_premium != price.a95_premium) ||
            (a98 != price.a98) || (a98_premium != price.a98_premium) ||
            (a100 != price.a100) || (a100_premium != price.a100_premium) ||
            (propane != price.propane) || (metan != price.metan);
}

QString Price::toString() {
    QStringList prices;
    if(diesel > 0.1) {
        prices.append("diesel="         + QString::number(diesel));
    }
    if(diesel_premium > 0.1) {
        prices.append("diesel_premium=" + QString::number(diesel_premium));
    }
    if(a80 > 0.1) {
        prices.append("a80="            + QString::number(a80));
    }
    if(a92 > 0.1) {
        prices.append("a92="            + QString::number(a92));
    }
    if(a92_premium > 0.1) {
        prices.append("a92_premium="    + QString::number(a92_premium));
    }
    if(a95 > 0.1) {
        prices.append("a95="            + QString::number(a95));
    }
    if(a95_premium > 0.1) {
        prices.append("a95_premium="    + QString::number(a95_premium));
    }
    if(a98 > 0.1) {
        prices.append("a98="            + QString::number(a98));
    }
    if(a98_premium > 0.1) {
        prices.append("a98_premium="    + QString::number(a98_premium));
    }
    if(a100 > 0.1) {
        prices.append("a100="           + QString::number(a100));
    }
    if(a100_premium > 0.1) {
        prices.append("a100_premium="   + QString::number(a100_premium));
    }
    if(propane > 0.1) {
        prices.append("propane="        + QString::number(propane));
    }
    if(metan > 0.1) {
        prices.append("metan="          + QString::number(metan));
    }
    return prices.join("&").replace(",",".");
}
