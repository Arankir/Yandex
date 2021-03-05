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

Order JsonToOrder(Partner aPartner, QJsonValue aOrder) {
    switch (aPartner) {
    case Partner::yandex: {
        Order order;
        order.id = aOrder.toObject().value("id").toString();
        order.dateCreate = QDateTime::fromString(aOrder.toObject().value("dateCreate").toString().left(23), "yyyy-MM-ddThh:mm:ss.zzz");
        order.orderType = aOrder.toObject().value("orderType").toString();
        order.orderVolume = aOrder.toObject().value("orderVolume").toDouble();
        order.columnId = aOrder.toObject().value("columnId").toInt();
        order.litre = aOrder.toObject().value("litre").toDouble();
        order.status = aOrder.toObject().value("status").toString();
        order.fuelId = aOrder.toObject().value("fuelId").toString();
        order.priceFuel = aOrder.toObject().value("priceFuel").toDouble();
        order.sum = aOrder.toObject().value("sum").toDouble();
        order.contractId = aOrder.toObject().value("contractId").toString();
        return order;
        break;
    }
    case Partner::citymobile: {
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
        order.fuelId = aOrder.toObject().value("fuelId").toString();
        order.priceFuel = aOrder.toObject().value("priceFuel").toDouble();
        order.sum = aOrder.toObject().value("sum").toDouble();
        order.contractId = aOrder.toObject().value("contractId").toString();
        return order;
        break;
    }
    }
    return Order();
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

