/****************************************************************************
** Meta object code from reading C++ file 'databasecontrol.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../Yandex/systems/databasecontrol.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'databasecontrol.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DataBaseControl_t {
    QByteArrayData data[180];
    char stringdata0[2107];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DataBaseControl_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DataBaseControl_t qt_meta_stringdata_DataBaseControl = {
    {
QT_MOC_LITERAL(0, 0, 15), // "DataBaseControl"
QT_MOC_LITERAL(1, 16, 14), // "getCurrentAgzs"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 12), // "getFuelNames"
QT_MOC_LITERAL(4, 45, 7), // "aFuelId"
QT_MOC_LITERAL(5, 53, 8), // "QString&"
QT_MOC_LITERAL(6, 62, 8), // "fullName"
QT_MOC_LITERAL(7, 71, 9), // "shortName"
QT_MOC_LITERAL(8, 81, 8), // "getFuels"
QT_MOC_LITERAL(9, 90, 23), // "QVector<QVector<int> >&"
QT_MOC_LITERAL(10, 114, 5), // "fuels"
QT_MOC_LITERAL(11, 120, 15), // "getCashBoxIndex"
QT_MOC_LITERAL(12, 136, 8), // "iPartner"
QT_MOC_LITERAL(13, 145, 9), // "getPrices"
QT_MOC_LITERAL(14, 155, 8), // "agzsName"
QT_MOC_LITERAL(15, 164, 4), // "int&"
QT_MOC_LITERAL(16, 169, 4), // "agzs"
QT_MOC_LITERAL(17, 174, 5), // "vCode"
QT_MOC_LITERAL(18, 180, 4), // "link"
QT_MOC_LITERAL(19, 185, 10), // "QDateTime&"
QT_MOC_LITERAL(20, 196, 5), // "cDate"
QT_MOC_LITERAL(21, 202, 7), // "partner"
QT_MOC_LITERAL(22, 210, 7), // "double&"
QT_MOC_LITERAL(23, 218, 6), // "diesel"
QT_MOC_LITERAL(24, 225, 14), // "diesel_premium"
QT_MOC_LITERAL(25, 240, 3), // "a80"
QT_MOC_LITERAL(26, 244, 3), // "a92"
QT_MOC_LITERAL(27, 248, 11), // "a92_premium"
QT_MOC_LITERAL(28, 260, 3), // "a95"
QT_MOC_LITERAL(29, 264, 11), // "a95_premium"
QT_MOC_LITERAL(30, 276, 3), // "a98"
QT_MOC_LITERAL(31, 280, 11), // "a98_premium"
QT_MOC_LITERAL(32, 292, 4), // "a100"
QT_MOC_LITERAL(33, 297, 12), // "a100_premium"
QT_MOC_LITERAL(34, 310, 7), // "propane"
QT_MOC_LITERAL(35, 318, 5), // "metan"
QT_MOC_LITERAL(36, 324, 11), // "getAgzsData"
QT_MOC_LITERAL(37, 336, 2), // "id"
QT_MOC_LITERAL(38, 339, 6), // "adress"
QT_MOC_LITERAL(39, 346, 5), // "loc_x"
QT_MOC_LITERAL(40, 352, 5), // "loc_y"
QT_MOC_LITERAL(41, 358, 11), // "columnCount"
QT_MOC_LITERAL(42, 370, 15), // "getAgzsAdastTrk"
QT_MOC_LITERAL(43, 386, 10), // "sideAdress"
QT_MOC_LITERAL(44, 397, 4), // "side"
QT_MOC_LITERAL(45, 402, 10), // "deviceName"
QT_MOC_LITERAL(46, 413, 6), // "serial"
QT_MOC_LITERAL(47, 420, 11), // "description"
QT_MOC_LITERAL(48, 432, 9), // "fuelCode1"
QT_MOC_LITERAL(49, 442, 9), // "fuelCode2"
QT_MOC_LITERAL(50, 452, 9), // "fuelCode3"
QT_MOC_LITERAL(51, 462, 9), // "fuelCode4"
QT_MOC_LITERAL(52, 472, 9), // "fuelCode5"
QT_MOC_LITERAL(53, 482, 8), // "trkVCode"
QT_MOC_LITERAL(54, 491, 9), // "pumpPlace"
QT_MOC_LITERAL(55, 501, 5), // "fuel1"
QT_MOC_LITERAL(56, 507, 5), // "fuel2"
QT_MOC_LITERAL(57, 513, 5), // "fuel3"
QT_MOC_LITERAL(58, 519, 5), // "fuel4"
QT_MOC_LITERAL(59, 525, 5), // "fuel5"
QT_MOC_LITERAL(60, 531, 20), // "updateApiTransaction"
QT_MOC_LITERAL(61, 552, 10), // "localState"
QT_MOC_LITERAL(62, 563, 4), // "date"
QT_MOC_LITERAL(63, 568, 12), // "getLastVCode"
QT_MOC_LITERAL(64, 581, 3), // "key"
QT_MOC_LITERAL(65, 585, 6), // "update"
QT_MOC_LITERAL(66, 592, 10), // "checkError"
QT_MOC_LITERAL(67, 603, 9), // "aColumnID"
QT_MOC_LITERAL(68, 613, 7), // "aFuelID"
QT_MOC_LITERAL(69, 621, 8), // "aiFuelID"
QT_MOC_LITERAL(70, 630, 10), // "aPriceFuel"
QT_MOC_LITERAL(71, 641, 9), // "aIPartner"
QT_MOC_LITERAL(72, 651, 20), // "createTrkTransaction"
QT_MOC_LITERAL(73, 672, 9), // "aAgzsName"
QT_MOC_LITERAL(74, 682, 11), // "aLocalVCode"
QT_MOC_LITERAL(75, 694, 8), // "aTrkType"
QT_MOC_LITERAL(76, 703, 11), // "aDeviceName"
QT_MOC_LITERAL(77, 715, 7), // "aSerial"
QT_MOC_LITERAL(78, 723, 9), // "aFuelName"
QT_MOC_LITERAL(79, 733, 14), // "aFuelShortName"
QT_MOC_LITERAL(80, 748, 5), // "aSide"
QT_MOC_LITERAL(81, 754, 11), // "aSideAdress"
QT_MOC_LITERAL(82, 766, 7), // "aNozzle"
QT_MOC_LITERAL(83, 774, 12), // "aTrkFuelCode"
QT_MOC_LITERAL(84, 787, 9), // "aTransNum"
QT_MOC_LITERAL(85, 797, 14), // "aTrkTotalPrice"
QT_MOC_LITERAL(86, 812, 10), // "aTrkVolume"
QT_MOC_LITERAL(87, 823, 13), // "aTrkUnitPrice"
QT_MOC_LITERAL(88, 837, 18), // "aRequestTotalPrice"
QT_MOC_LITERAL(89, 856, 14), // "aRequestVolume"
QT_MOC_LITERAL(90, 871, 17), // "aRequestUnitPrice"
QT_MOC_LITERAL(91, 889, 13), // "aRequestField"
QT_MOC_LITERAL(92, 903, 6), // "aState"
QT_MOC_LITERAL(93, 910, 7), // "aIState"
QT_MOC_LITERAL(94, 918, 13), // "aTrkTransType"
QT_MOC_LITERAL(95, 932, 18), // "aLitersCountBefore"
QT_MOC_LITERAL(96, 951, 17), // "aMoneyCountBefore"
QT_MOC_LITERAL(97, 969, 17), // "aTransCountBefore"
QT_MOC_LITERAL(98, 987, 17), // "aLitersCountAfter"
QT_MOC_LITERAL(99, 1005, 16), // "aMoneyCountAfter"
QT_MOC_LITERAL(100, 1022, 16), // "aTransCountAfter"
QT_MOC_LITERAL(101, 1039, 7), // "aResult"
QT_MOC_LITERAL(102, 1047, 9), // "aDateOpen"
QT_MOC_LITERAL(103, 1057, 10), // "aDateClose"
QT_MOC_LITERAL(104, 1068, 12), // "aTemperature"
QT_MOC_LITERAL(105, 1081, 18), // "aPayOperationVCode"
QT_MOC_LITERAL(106, 1100, 7), // "aPayWay"
QT_MOC_LITERAL(107, 1108, 11), // "aPrePostPay"
QT_MOC_LITERAL(108, 1120, 6), // "aWUser"
QT_MOC_LITERAL(109, 1127, 6), // "aWDate"
QT_MOC_LITERAL(110, 1134, 6), // "aCUser"
QT_MOC_LITERAL(111, 1141, 6), // "aCDate"
QT_MOC_LITERAL(112, 1148, 6), // "aCHost"
QT_MOC_LITERAL(113, 1155, 6), // "aWHost"
QT_MOC_LITERAL(114, 1162, 6), // "aVCode"
QT_MOC_LITERAL(115, 1169, 19), // "aAddedForTransVCode"
QT_MOC_LITERAL(116, 1189, 20), // "aAditionalTransVCode"
QT_MOC_LITERAL(117, 1210, 7), // "aActive"
QT_MOC_LITERAL(118, 1218, 5), // "aMass"
QT_MOC_LITERAL(119, 1224, 6), // "aSmena"
QT_MOC_LITERAL(120, 1231, 9), // "aTrkVcode"
QT_MOC_LITERAL(121, 1241, 14), // "aCapacityVcode"
QT_MOC_LITERAL(122, 1256, 10), // "aPumpPlace"
QT_MOC_LITERAL(123, 1267, 11), // "aMoneyTaken"
QT_MOC_LITERAL(124, 1279, 8), // "aIPayWay"
QT_MOC_LITERAL(125, 1288, 10), // "aAutoCheck"
QT_MOC_LITERAL(126, 1299, 7), // "aClosed"
QT_MOC_LITERAL(127, 1307, 9), // "aFullTank"
QT_MOC_LITERAL(128, 1317, 5), // "aAgzs"
QT_MOC_LITERAL(129, 1323, 10), // "aFuelVCode"
QT_MOC_LITERAL(130, 1334, 7), // "aPropan"
QT_MOC_LITERAL(131, 1342, 8), // "getSmena"
QT_MOC_LITERAL(132, 1351, 20), // "createApiTransaction"
QT_MOC_LITERAL(133, 1372, 6), // "aApiId"
QT_MOC_LITERAL(134, 1379, 21), // "aApiStationExtendedId"
QT_MOC_LITERAL(135, 1401, 12), // "aApiColumnId"
QT_MOC_LITERAL(136, 1414, 10), // "aApiFuelId"
QT_MOC_LITERAL(137, 1425, 13), // "aApiPriceFuel"
QT_MOC_LITERAL(138, 1439, 9), // "aApiLitre"
QT_MOC_LITERAL(139, 1449, 7), // "aApiSum"
QT_MOC_LITERAL(140, 1457, 10), // "aApiStatus"
QT_MOC_LITERAL(141, 1468, 14), // "aApiContractId"
QT_MOC_LITERAL(142, 1483, 6), // "aAgent"
QT_MOC_LITERAL(143, 1490, 11), // "aLocalState"
QT_MOC_LITERAL(144, 1502, 6), // "aPrice"
QT_MOC_LITERAL(145, 1509, 6), // "aLitre"
QT_MOC_LITERAL(146, 1516, 4), // "aSum"
QT_MOC_LITERAL(147, 1521, 5), // "aLink"
QT_MOC_LITERAL(148, 1527, 22), // "getApiTransactionState"
QT_MOC_LITERAL(149, 1550, 8), // "apiVCode"
QT_MOC_LITERAL(150, 1559, 9), // "headVCode"
QT_MOC_LITERAL(151, 1569, 6), // "iState"
QT_MOC_LITERAL(152, 1576, 8), // "dateOpen"
QT_MOC_LITERAL(153, 1585, 9), // "dateClose"
QT_MOC_LITERAL(154, 1595, 25), // "updateApiTransactionState"
QT_MOC_LITERAL(155, 1621, 30), // "finalUpdateApiTransactionState"
QT_MOC_LITERAL(156, 1652, 5), // "price"
QT_MOC_LITERAL(157, 1658, 6), // "volume"
QT_MOC_LITERAL(158, 1665, 6), // "amount"
QT_MOC_LITERAL(159, 1672, 21), // "getPayOperationLiters"
QT_MOC_LITERAL(160, 1694, 20), // "setTransactionClosed"
QT_MOC_LITERAL(161, 1715, 6), // "closed"
QT_MOC_LITERAL(162, 1722, 18), // "getTransactionData"
QT_MOC_LITERAL(163, 1741, 14), // "setYandexToken"
QT_MOC_LITERAL(164, 1756, 6), // "aToken"
QT_MOC_LITERAL(165, 1763, 17), // "getFuelNamesCycle"
QT_MOC_LITERAL(166, 1781, 13), // "getFuelsCycle"
QT_MOC_LITERAL(167, 1795, 20), // "getCashBoxIndexCycle"
QT_MOC_LITERAL(168, 1816, 14), // "getPricesCycle"
QT_MOC_LITERAL(169, 1831, 16), // "getAgzsDataCycle"
QT_MOC_LITERAL(170, 1848, 20), // "getAgzsAdastTrkCycle"
QT_MOC_LITERAL(171, 1869, 25), // "createTrkTransactionCycle"
QT_MOC_LITERAL(172, 1895, 13), // "getSmenaCycle"
QT_MOC_LITERAL(173, 1909, 25), // "createApiTransactionCycle"
QT_MOC_LITERAL(174, 1935, 27), // "getApiTransactionStateCycle"
QT_MOC_LITERAL(175, 1963, 30), // "updateApiTransactionStateCycle"
QT_MOC_LITERAL(176, 1994, 35), // "finalUpdateApiTransactionStat..."
QT_MOC_LITERAL(177, 2030, 26), // "getPayOperationLitersCycle"
QT_MOC_LITERAL(178, 2057, 25), // "setTransactionClosedCycle"
QT_MOC_LITERAL(179, 2083, 23) // "getTransactionDataCycle"

    },
    "DataBaseControl\0getCurrentAgzs\0\0"
    "getFuelNames\0aFuelId\0QString&\0fullName\0"
    "shortName\0getFuels\0QVector<QVector<int> >&\0"
    "fuels\0getCashBoxIndex\0iPartner\0getPrices\0"
    "agzsName\0int&\0agzs\0vCode\0link\0QDateTime&\0"
    "cDate\0partner\0double&\0diesel\0"
    "diesel_premium\0a80\0a92\0a92_premium\0"
    "a95\0a95_premium\0a98\0a98_premium\0a100\0"
    "a100_premium\0propane\0metan\0getAgzsData\0"
    "id\0adress\0loc_x\0loc_y\0columnCount\0"
    "getAgzsAdastTrk\0sideAdress\0side\0"
    "deviceName\0serial\0description\0fuelCode1\0"
    "fuelCode2\0fuelCode3\0fuelCode4\0fuelCode5\0"
    "trkVCode\0pumpPlace\0fuel1\0fuel2\0fuel3\0"
    "fuel4\0fuel5\0updateApiTransaction\0"
    "localState\0date\0getLastVCode\0key\0"
    "update\0checkError\0aColumnID\0aFuelID\0"
    "aiFuelID\0aPriceFuel\0aIPartner\0"
    "createTrkTransaction\0aAgzsName\0"
    "aLocalVCode\0aTrkType\0aDeviceName\0"
    "aSerial\0aFuelName\0aFuelShortName\0aSide\0"
    "aSideAdress\0aNozzle\0aTrkFuelCode\0"
    "aTransNum\0aTrkTotalPrice\0aTrkVolume\0"
    "aTrkUnitPrice\0aRequestTotalPrice\0"
    "aRequestVolume\0aRequestUnitPrice\0"
    "aRequestField\0aState\0aIState\0aTrkTransType\0"
    "aLitersCountBefore\0aMoneyCountBefore\0"
    "aTransCountBefore\0aLitersCountAfter\0"
    "aMoneyCountAfter\0aTransCountAfter\0"
    "aResult\0aDateOpen\0aDateClose\0aTemperature\0"
    "aPayOperationVCode\0aPayWay\0aPrePostPay\0"
    "aWUser\0aWDate\0aCUser\0aCDate\0aCHost\0"
    "aWHost\0aVCode\0aAddedForTransVCode\0"
    "aAditionalTransVCode\0aActive\0aMass\0"
    "aSmena\0aTrkVcode\0aCapacityVcode\0"
    "aPumpPlace\0aMoneyTaken\0aIPayWay\0"
    "aAutoCheck\0aClosed\0aFullTank\0aAgzs\0"
    "aFuelVCode\0aPropan\0getSmena\0"
    "createApiTransaction\0aApiId\0"
    "aApiStationExtendedId\0aApiColumnId\0"
    "aApiFuelId\0aApiPriceFuel\0aApiLitre\0"
    "aApiSum\0aApiStatus\0aApiContractId\0"
    "aAgent\0aLocalState\0aPrice\0aLitre\0aSum\0"
    "aLink\0getApiTransactionState\0apiVCode\0"
    "headVCode\0iState\0dateOpen\0dateClose\0"
    "updateApiTransactionState\0"
    "finalUpdateApiTransactionState\0price\0"
    "volume\0amount\0getPayOperationLiters\0"
    "setTransactionClosed\0closed\0"
    "getTransactionData\0setYandexToken\0"
    "aToken\0getFuelNamesCycle\0getFuelsCycle\0"
    "getCashBoxIndexCycle\0getPricesCycle\0"
    "getAgzsDataCycle\0getAgzsAdastTrkCycle\0"
    "createTrkTransactionCycle\0getSmenaCycle\0"
    "createApiTransactionCycle\0"
    "getApiTransactionStateCycle\0"
    "updateApiTransactionStateCycle\0"
    "finalUpdateApiTransactionStateCycle\0"
    "getPayOperationLitersCycle\0"
    "setTransactionClosedCycle\0"
    "getTransactionDataCycle"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DataBaseControl[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      35,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,  189,    2, 0x0a /* Public */,
       3,    3,  190,    2, 0x0a /* Public */,
       8,    1,  197,    2, 0x0a /* Public */,
      11,    1,  200,    2, 0x0a /* Public */,
      13,   20,  203,    2, 0x0a /* Public */,
      36,    9,  244,    2, 0x0a /* Public */,
      42,   17,  263,    2, 0x0a /* Public */,
      60,    3,  298,    2, 0x0a /* Public */,
      63,    2,  305,    2, 0x0a /* Public */,
      66,    5,  310,    2, 0x0a /* Public */,
      72,   58,  321,    2, 0x0a /* Public */,
     131,    0,  438,    2, 0x0a /* Public */,
     132,   21,  439,    2, 0x0a /* Public */,
     148,    8,  482,    2, 0x0a /* Public */,
     154,    3,  499,    2, 0x0a /* Public */,
     155,    7,  506,    2, 0x0a /* Public */,
     159,    4,  521,    2, 0x0a /* Public */,
     160,    2,  530,    2, 0x0a /* Public */,
     162,    9,  535,    2, 0x0a /* Public */,
     163,    1,  554,    2, 0x0a /* Public */,
     165,    3,  557,    2, 0x08 /* Private */,
     166,    1,  564,    2, 0x08 /* Private */,
     167,    1,  567,    2, 0x08 /* Private */,
     168,   20,  570,    2, 0x08 /* Private */,
     169,    9,  611,    2, 0x08 /* Private */,
     170,   17,  630,    2, 0x08 /* Private */,
     171,   58,  665,    2, 0x08 /* Private */,
     172,    0,  782,    2, 0x08 /* Private */,
     173,   21,  783,    2, 0x08 /* Private */,
     174,    8,  826,    2, 0x08 /* Private */,
     175,    3,  843,    2, 0x08 /* Private */,
     176,    7,  850,    2, 0x08 /* Private */,
     177,    4,  865,    2, 0x08 /* Private */,
     178,    2,  874,    2, 0x08 /* Private */,
     179,    9,  879,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Int,
    QMetaType::Bool, QMetaType::Int, 0x80000000 | 5, 0x80000000 | 5,    4,    6,    7,
    QMetaType::Bool, 0x80000000 | 9,   10,
    QMetaType::Int, QMetaType::QString,   12,
    QMetaType::Bool, QMetaType::QString, 0x80000000 | 5, 0x80000000 | 15, 0x80000000 | 15, 0x80000000 | 15, 0x80000000 | 19, 0x80000000 | 5, 0x80000000 | 22, 0x80000000 | 22, 0x80000000 | 22, 0x80000000 | 22, 0x80000000 | 22, 0x80000000 | 22, 0x80000000 | 22, 0x80000000 | 22, 0x80000000 | 22, 0x80000000 | 22, 0x80000000 | 22, 0x80000000 | 22, 0x80000000 | 22,   12,   14,   16,   17,   18,   20,   21,   23,   24,   25,   26,   27,   28,   29,   30,   31,   32,   33,   34,   35,
    QMetaType::Bool, 0x80000000 | 5, 0x80000000 | 15, 0x80000000 | 19, 0x80000000 | 15, 0x80000000 | 5, 0x80000000 | 5, 0x80000000 | 22, 0x80000000 | 22, 0x80000000 | 15,   14,   16,   20,   17,   37,   38,   39,   40,   41,
    QMetaType::Bool, QMetaType::Int, 0x80000000 | 5, 0x80000000 | 5, 0x80000000 | 5, 0x80000000 | 5, 0x80000000 | 15, 0x80000000 | 15, 0x80000000 | 15, 0x80000000 | 15, 0x80000000 | 15, 0x80000000 | 15, 0x80000000 | 15, 0x80000000 | 15, 0x80000000 | 15, 0x80000000 | 15, 0x80000000 | 15, 0x80000000 | 15,   43,   44,   45,   46,   47,   48,   49,   50,   51,   52,   53,   54,   55,   56,   57,   58,   59,
    QMetaType::Bool, QMetaType::Int, QMetaType::QDateTime, QMetaType::Int,   61,   62,   17,
    QMetaType::Int, QMetaType::QString, QMetaType::Bool,   64,   65,
    QMetaType::Int, QMetaType::QString, QMetaType::QString, QMetaType::Int, QMetaType::QString, QMetaType::Int,   67,   68,   69,   70,   71,
    QMetaType::Bool, QMetaType::QString, QMetaType::Int, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::QString, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::QString, QMetaType::QString, QMetaType::Int, QMetaType::QString, QMetaType::Double, QMetaType::Double, QMetaType::Int, QMetaType::Double, QMetaType::Double, QMetaType::Int, QMetaType::QString, QMetaType::QDateTime, QMetaType::QDateTime, QMetaType::Double, QMetaType::Int, QMetaType::QString, QMetaType::Int, QMetaType::QString, QMetaType::QDateTime, QMetaType::QString, QMetaType::QDateTime, QMetaType::QString, QMetaType::QString, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Double, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Double, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,   73,   74,   75,   76,   77,   78,   79,   80,   81,   82,   83,   84,   85,   86,   87,   88,   89,   90,   91,   92,   93,   94,   95,   96,   97,   98,   99,  100,  101,  102,  103,  104,  105,  106,  107,  108,  109,  110,  111,  112,  113,  114,  115,  116,  117,  118,  119,  120,  121,  122,  123,  124,  125,  126,  127,  128,  129,  130,
    QMetaType::Int,
    QMetaType::Bool, QMetaType::QString, QMetaType::Int, QMetaType::QDateTime, QMetaType::Int, QMetaType::QString, QMetaType::QString, QMetaType::Int, QMetaType::QString, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::QDateTime, QMetaType::Int,   73,  128,  111,  114,  133,  134,  135,  136,    4,  137,  138,  139,  140,  141,  142,  143,  144,  145,  146,  102,  147,
    QMetaType::Bool, QMetaType::QString, 0x80000000 | 5, 0x80000000 | 22, 0x80000000 | 15, 0x80000000 | 15, 0x80000000 | 15, QMetaType::QDateTime, 0x80000000 | 19,   37,   61,  138,  149,  150,  151,  152,  153,
    QMetaType::Bool, QMetaType::QString, QMetaType::QDateTime, QMetaType::Int,   61,  153,   17,
    QMetaType::Bool, QMetaType::QString, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::QDateTime, QMetaType::QDateTime, QMetaType::Int,   61,  156,  157,  158,  152,  153,   17,
    QMetaType::Bool, QMetaType::Int, 0x80000000 | 22, 0x80000000 | 22, 0x80000000 | 22,   18,  158,  157,  156,
    QMetaType::Bool, QMetaType::QString, QMetaType::Int,   37,  161,
    QMetaType::Bool, QMetaType::Int, 0x80000000 | 22, 0x80000000 | 22, 0x80000000 | 22, 0x80000000 | 22, 0x80000000 | 22, 0x80000000 | 22, 0x80000000 | 19, 0x80000000 | 19,  114,   88,   89,   90,   85,   86,   87,  102,  103,
    QMetaType::Bool, QMetaType::QString,  164,
    QMetaType::Bool, QMetaType::Int, 0x80000000 | 5, 0x80000000 | 5,    4,    6,    7,
    QMetaType::Bool, 0x80000000 | 9,   10,
    QMetaType::Int, QMetaType::QString,   12,
    QMetaType::Bool, QMetaType::QString, 0x80000000 | 5, 0x80000000 | 15, 0x80000000 | 15, 0x80000000 | 15, 0x80000000 | 19, 0x80000000 | 5, 0x80000000 | 22, 0x80000000 | 22, 0x80000000 | 22, 0x80000000 | 22, 0x80000000 | 22, 0x80000000 | 22, 0x80000000 | 22, 0x80000000 | 22, 0x80000000 | 22, 0x80000000 | 22, 0x80000000 | 22, 0x80000000 | 22, 0x80000000 | 22,   12,   14,   16,   17,   18,   20,   21,   23,   24,   25,   26,   27,   28,   29,   30,   31,   32,   33,   34,   35,
    QMetaType::Bool, 0x80000000 | 5, 0x80000000 | 15, 0x80000000 | 19, 0x80000000 | 15, 0x80000000 | 5, 0x80000000 | 5, 0x80000000 | 22, 0x80000000 | 22, 0x80000000 | 15,   14,   16,   20,   17,   37,   38,   39,   40,   41,
    QMetaType::Bool, QMetaType::Int, 0x80000000 | 5, 0x80000000 | 5, 0x80000000 | 5, 0x80000000 | 5, 0x80000000 | 15, 0x80000000 | 15, 0x80000000 | 15, 0x80000000 | 15, 0x80000000 | 15, 0x80000000 | 15, 0x80000000 | 15, 0x80000000 | 15, 0x80000000 | 15, 0x80000000 | 15, 0x80000000 | 15, 0x80000000 | 15,   43,   44,   45,   46,   47,   48,   49,   50,   51,   52,   53,   54,   55,   56,   57,   58,   59,
    QMetaType::Bool, QMetaType::QString, QMetaType::Int, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::QString, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::QString, QMetaType::QString, QMetaType::Int, QMetaType::QString, QMetaType::Double, QMetaType::Double, QMetaType::Int, QMetaType::Double, QMetaType::Double, QMetaType::Int, QMetaType::QString, QMetaType::QDateTime, QMetaType::QDateTime, QMetaType::Double, QMetaType::Int, QMetaType::QString, QMetaType::Int, QMetaType::QString, QMetaType::QDateTime, QMetaType::QString, QMetaType::QDateTime, QMetaType::QString, QMetaType::QString, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Double, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Double, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,   73,   74,   75,   76,   77,   78,   79,   80,   81,   82,   83,   84,   85,   86,   87,   88,   89,   90,   91,   92,   93,   94,   95,   96,   97,   98,   99,  100,  101,  102,  103,  104,  105,  106,  107,  108,  109,  110,  111,  112,  113,  114,  115,  116,  117,  118,  119,  120,  121,  122,  123,  124,  125,  126,  127,  128,  129,  130,
    QMetaType::Int,
    QMetaType::Bool, QMetaType::QString, QMetaType::Int, QMetaType::QDateTime, QMetaType::Int, QMetaType::QString, QMetaType::QString, QMetaType::Int, QMetaType::QString, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::QDateTime, QMetaType::Int,   73,  128,  111,  114,  133,  134,  135,  136,    4,  137,  138,  139,  140,  141,  142,  143,  144,  145,  146,  102,  147,
    QMetaType::Bool, QMetaType::QString, 0x80000000 | 5, 0x80000000 | 22, 0x80000000 | 15, 0x80000000 | 15, 0x80000000 | 15, QMetaType::QDateTime, 0x80000000 | 19,   37,   61,  138,  149,  150,  151,  152,  153,
    QMetaType::Bool, QMetaType::QString, QMetaType::QDateTime, QMetaType::Int,   61,  153,   17,
    QMetaType::Bool, QMetaType::QString, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::QDateTime, QMetaType::QDateTime, QMetaType::Int,   61,  156,  157,  158,  152,  153,   17,
    QMetaType::Bool, QMetaType::Int, 0x80000000 | 22, 0x80000000 | 22, 0x80000000 | 22,   18,  158,  157,  156,
    QMetaType::Bool, QMetaType::QString, QMetaType::Int,   37,  161,
    QMetaType::Bool, QMetaType::Int, 0x80000000 | 22, 0x80000000 | 22, 0x80000000 | 22, 0x80000000 | 22, 0x80000000 | 22, 0x80000000 | 22, 0x80000000 | 19, 0x80000000 | 19,  114,   88,   89,   90,   85,   86,   87,  102,  103,

       0        // eod
};

void DataBaseControl::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DataBaseControl *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { int _r = _t->getCurrentAgzs();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 1: { bool _r = _t->getFuelNames((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 2: { bool _r = _t->getFuels((*reinterpret_cast< QVector<QVector<int> >(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 3: { int _r = _t->getCashBoxIndex((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 4: { bool _r = _t->getPrices((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5])),(*reinterpret_cast< QDateTime(*)>(_a[6])),(*reinterpret_cast< QString(*)>(_a[7])),(*reinterpret_cast< double(*)>(_a[8])),(*reinterpret_cast< double(*)>(_a[9])),(*reinterpret_cast< double(*)>(_a[10])),(*reinterpret_cast< double(*)>(_a[11])),(*reinterpret_cast< double(*)>(_a[12])),(*reinterpret_cast< double(*)>(_a[13])),(*reinterpret_cast< double(*)>(_a[14])),(*reinterpret_cast< double(*)>(_a[15])),(*reinterpret_cast< double(*)>(_a[16])),(*reinterpret_cast< double(*)>(_a[17])),(*reinterpret_cast< double(*)>(_a[18])),(*reinterpret_cast< double(*)>(_a[19])),(*reinterpret_cast< double(*)>(_a[20])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 5: { bool _r = _t->getAgzsData((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< QDateTime(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5])),(*reinterpret_cast< QString(*)>(_a[6])),(*reinterpret_cast< double(*)>(_a[7])),(*reinterpret_cast< double(*)>(_a[8])),(*reinterpret_cast< int(*)>(_a[9])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 6: { bool _r = _t->getAgzsAdastTrk((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5])),(*reinterpret_cast< int(*)>(_a[6])),(*reinterpret_cast< int(*)>(_a[7])),(*reinterpret_cast< int(*)>(_a[8])),(*reinterpret_cast< int(*)>(_a[9])),(*reinterpret_cast< int(*)>(_a[10])),(*reinterpret_cast< int(*)>(_a[11])),(*reinterpret_cast< int(*)>(_a[12])),(*reinterpret_cast< int(*)>(_a[13])),(*reinterpret_cast< int(*)>(_a[14])),(*reinterpret_cast< int(*)>(_a[15])),(*reinterpret_cast< int(*)>(_a[16])),(*reinterpret_cast< int(*)>(_a[17])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 7: { bool _r = _t->updateApiTransaction((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QDateTime(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 8: { int _r = _t->getLastVCode((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 9: { int _r = _t->checkError((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 10: { bool _r = _t->createTrkTransaction((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5])),(*reinterpret_cast< QString(*)>(_a[6])),(*reinterpret_cast< QString(*)>(_a[7])),(*reinterpret_cast< QString(*)>(_a[8])),(*reinterpret_cast< int(*)>(_a[9])),(*reinterpret_cast< int(*)>(_a[10])),(*reinterpret_cast< int(*)>(_a[11])),(*reinterpret_cast< QString(*)>(_a[12])),(*reinterpret_cast< double(*)>(_a[13])),(*reinterpret_cast< double(*)>(_a[14])),(*reinterpret_cast< double(*)>(_a[15])),(*reinterpret_cast< double(*)>(_a[16])),(*reinterpret_cast< double(*)>(_a[17])),(*reinterpret_cast< double(*)>(_a[18])),(*reinterpret_cast< QString(*)>(_a[19])),(*reinterpret_cast< QString(*)>(_a[20])),(*reinterpret_cast< int(*)>(_a[21])),(*reinterpret_cast< QString(*)>(_a[22])),(*reinterpret_cast< double(*)>(_a[23])),(*reinterpret_cast< double(*)>(_a[24])),(*reinterpret_cast< int(*)>(_a[25])),(*reinterpret_cast< double(*)>(_a[26])),(*reinterpret_cast< double(*)>(_a[27])),(*reinterpret_cast< int(*)>(_a[28])),(*reinterpret_cast< QString(*)>(_a[29])),(*reinterpret_cast< QDateTime(*)>(_a[30])),(*reinterpret_cast< QDateTime(*)>(_a[31])),(*reinterpret_cast< double(*)>(_a[32])),(*reinterpret_cast< int(*)>(_a[33])),(*reinterpret_cast< QString(*)>(_a[34])),(*reinterpret_cast< int(*)>(_a[35])),(*reinterpret_cast< QString(*)>(_a[36])),(*reinterpret_cast< QDateTime(*)>(_a[37])),(*reinterpret_cast< QString(*)>(_a[38])),(*reinterpret_cast< QDateTime(*)>(_a[39])),(*reinterpret_cast< QString(*)>(_a[40])),(*reinterpret_cast< QString(*)>(_a[41])),(*reinterpret_cast< int(*)>(_a[42])),(*reinterpret_cast< int(*)>(_a[43])),(*reinterpret_cast< int(*)>(_a[44])),(*reinterpret_cast< int(*)>(_a[45])),(*reinterpret_cast< double(*)>(_a[46])),(*reinterpret_cast< int(*)>(_a[47])),(*reinterpret_cast< int(*)>(_a[48])),(*reinterpret_cast< int(*)>(_a[49])),(*reinterpret_cast< int(*)>(_a[50])),(*reinterpret_cast< double(*)>(_a[51])),(*reinterpret_cast< int(*)>(_a[52])),(*reinterpret_cast< int(*)>(_a[53])),(*reinterpret_cast< int(*)>(_a[54])),(*reinterpret_cast< int(*)>(_a[55])),(*reinterpret_cast< int(*)>(_a[56])),(*reinterpret_cast< int(*)>(_a[57])),(*reinterpret_cast< int(*)>(_a[58])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 11: { int _r = _t->getSmena();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 12: { bool _r = _t->createApiTransaction((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< QDateTime(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5])),(*reinterpret_cast< QString(*)>(_a[6])),(*reinterpret_cast< int(*)>(_a[7])),(*reinterpret_cast< QString(*)>(_a[8])),(*reinterpret_cast< int(*)>(_a[9])),(*reinterpret_cast< int(*)>(_a[10])),(*reinterpret_cast< int(*)>(_a[11])),(*reinterpret_cast< int(*)>(_a[12])),(*reinterpret_cast< QString(*)>(_a[13])),(*reinterpret_cast< QString(*)>(_a[14])),(*reinterpret_cast< QString(*)>(_a[15])),(*reinterpret_cast< QString(*)>(_a[16])),(*reinterpret_cast< double(*)>(_a[17])),(*reinterpret_cast< double(*)>(_a[18])),(*reinterpret_cast< double(*)>(_a[19])),(*reinterpret_cast< QDateTime(*)>(_a[20])),(*reinterpret_cast< int(*)>(_a[21])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 13: { bool _r = _t->getApiTransactionState((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5])),(*reinterpret_cast< int(*)>(_a[6])),(*reinterpret_cast< QDateTime(*)>(_a[7])),(*reinterpret_cast< QDateTime(*)>(_a[8])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 14: { bool _r = _t->updateApiTransactionState((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QDateTime(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 15: { bool _r = _t->finalUpdateApiTransactionState((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< double(*)>(_a[4])),(*reinterpret_cast< QDateTime(*)>(_a[5])),(*reinterpret_cast< QDateTime(*)>(_a[6])),(*reinterpret_cast< int(*)>(_a[7])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 16: { bool _r = _t->getPayOperationLiters((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< double(*)>(_a[4])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 17: { bool _r = _t->setTransactionClosed((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 18: { bool _r = _t->getTransactionData((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< double(*)>(_a[4])),(*reinterpret_cast< double(*)>(_a[5])),(*reinterpret_cast< double(*)>(_a[6])),(*reinterpret_cast< double(*)>(_a[7])),(*reinterpret_cast< QDateTime(*)>(_a[8])),(*reinterpret_cast< QDateTime(*)>(_a[9])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 19: { bool _r = _t->setYandexToken((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 20: { bool _r = _t->getFuelNamesCycle((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 21: { bool _r = _t->getFuelsCycle((*reinterpret_cast< QVector<QVector<int> >(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 22: { int _r = _t->getCashBoxIndexCycle((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 23: { bool _r = _t->getPricesCycle((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5])),(*reinterpret_cast< QDateTime(*)>(_a[6])),(*reinterpret_cast< QString(*)>(_a[7])),(*reinterpret_cast< double(*)>(_a[8])),(*reinterpret_cast< double(*)>(_a[9])),(*reinterpret_cast< double(*)>(_a[10])),(*reinterpret_cast< double(*)>(_a[11])),(*reinterpret_cast< double(*)>(_a[12])),(*reinterpret_cast< double(*)>(_a[13])),(*reinterpret_cast< double(*)>(_a[14])),(*reinterpret_cast< double(*)>(_a[15])),(*reinterpret_cast< double(*)>(_a[16])),(*reinterpret_cast< double(*)>(_a[17])),(*reinterpret_cast< double(*)>(_a[18])),(*reinterpret_cast< double(*)>(_a[19])),(*reinterpret_cast< double(*)>(_a[20])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 24: { bool _r = _t->getAgzsDataCycle((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< QDateTime(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5])),(*reinterpret_cast< QString(*)>(_a[6])),(*reinterpret_cast< double(*)>(_a[7])),(*reinterpret_cast< double(*)>(_a[8])),(*reinterpret_cast< int(*)>(_a[9])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 25: { bool _r = _t->getAgzsAdastTrkCycle((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5])),(*reinterpret_cast< int(*)>(_a[6])),(*reinterpret_cast< int(*)>(_a[7])),(*reinterpret_cast< int(*)>(_a[8])),(*reinterpret_cast< int(*)>(_a[9])),(*reinterpret_cast< int(*)>(_a[10])),(*reinterpret_cast< int(*)>(_a[11])),(*reinterpret_cast< int(*)>(_a[12])),(*reinterpret_cast< int(*)>(_a[13])),(*reinterpret_cast< int(*)>(_a[14])),(*reinterpret_cast< int(*)>(_a[15])),(*reinterpret_cast< int(*)>(_a[16])),(*reinterpret_cast< int(*)>(_a[17])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 26: { bool _r = _t->createTrkTransactionCycle((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5])),(*reinterpret_cast< QString(*)>(_a[6])),(*reinterpret_cast< QString(*)>(_a[7])),(*reinterpret_cast< QString(*)>(_a[8])),(*reinterpret_cast< int(*)>(_a[9])),(*reinterpret_cast< int(*)>(_a[10])),(*reinterpret_cast< int(*)>(_a[11])),(*reinterpret_cast< QString(*)>(_a[12])),(*reinterpret_cast< double(*)>(_a[13])),(*reinterpret_cast< double(*)>(_a[14])),(*reinterpret_cast< double(*)>(_a[15])),(*reinterpret_cast< double(*)>(_a[16])),(*reinterpret_cast< double(*)>(_a[17])),(*reinterpret_cast< double(*)>(_a[18])),(*reinterpret_cast< QString(*)>(_a[19])),(*reinterpret_cast< QString(*)>(_a[20])),(*reinterpret_cast< int(*)>(_a[21])),(*reinterpret_cast< QString(*)>(_a[22])),(*reinterpret_cast< double(*)>(_a[23])),(*reinterpret_cast< double(*)>(_a[24])),(*reinterpret_cast< int(*)>(_a[25])),(*reinterpret_cast< double(*)>(_a[26])),(*reinterpret_cast< double(*)>(_a[27])),(*reinterpret_cast< int(*)>(_a[28])),(*reinterpret_cast< QString(*)>(_a[29])),(*reinterpret_cast< QDateTime(*)>(_a[30])),(*reinterpret_cast< QDateTime(*)>(_a[31])),(*reinterpret_cast< double(*)>(_a[32])),(*reinterpret_cast< int(*)>(_a[33])),(*reinterpret_cast< QString(*)>(_a[34])),(*reinterpret_cast< int(*)>(_a[35])),(*reinterpret_cast< QString(*)>(_a[36])),(*reinterpret_cast< QDateTime(*)>(_a[37])),(*reinterpret_cast< QString(*)>(_a[38])),(*reinterpret_cast< QDateTime(*)>(_a[39])),(*reinterpret_cast< QString(*)>(_a[40])),(*reinterpret_cast< QString(*)>(_a[41])),(*reinterpret_cast< int(*)>(_a[42])),(*reinterpret_cast< int(*)>(_a[43])),(*reinterpret_cast< int(*)>(_a[44])),(*reinterpret_cast< int(*)>(_a[45])),(*reinterpret_cast< double(*)>(_a[46])),(*reinterpret_cast< int(*)>(_a[47])),(*reinterpret_cast< int(*)>(_a[48])),(*reinterpret_cast< int(*)>(_a[49])),(*reinterpret_cast< int(*)>(_a[50])),(*reinterpret_cast< double(*)>(_a[51])),(*reinterpret_cast< int(*)>(_a[52])),(*reinterpret_cast< int(*)>(_a[53])),(*reinterpret_cast< int(*)>(_a[54])),(*reinterpret_cast< int(*)>(_a[55])),(*reinterpret_cast< int(*)>(_a[56])),(*reinterpret_cast< int(*)>(_a[57])),(*reinterpret_cast< int(*)>(_a[58])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 27: { int _r = _t->getSmenaCycle();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 28: { bool _r = _t->createApiTransactionCycle((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< QDateTime(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5])),(*reinterpret_cast< QString(*)>(_a[6])),(*reinterpret_cast< int(*)>(_a[7])),(*reinterpret_cast< QString(*)>(_a[8])),(*reinterpret_cast< int(*)>(_a[9])),(*reinterpret_cast< int(*)>(_a[10])),(*reinterpret_cast< int(*)>(_a[11])),(*reinterpret_cast< int(*)>(_a[12])),(*reinterpret_cast< QString(*)>(_a[13])),(*reinterpret_cast< QString(*)>(_a[14])),(*reinterpret_cast< QString(*)>(_a[15])),(*reinterpret_cast< QString(*)>(_a[16])),(*reinterpret_cast< double(*)>(_a[17])),(*reinterpret_cast< double(*)>(_a[18])),(*reinterpret_cast< double(*)>(_a[19])),(*reinterpret_cast< QDateTime(*)>(_a[20])),(*reinterpret_cast< int(*)>(_a[21])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 29: { bool _r = _t->getApiTransactionStateCycle((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5])),(*reinterpret_cast< int(*)>(_a[6])),(*reinterpret_cast< QDateTime(*)>(_a[7])),(*reinterpret_cast< QDateTime(*)>(_a[8])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 30: { bool _r = _t->updateApiTransactionStateCycle((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QDateTime(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 31: { bool _r = _t->finalUpdateApiTransactionStateCycle((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< double(*)>(_a[4])),(*reinterpret_cast< QDateTime(*)>(_a[5])),(*reinterpret_cast< QDateTime(*)>(_a[6])),(*reinterpret_cast< int(*)>(_a[7])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 32: { bool _r = _t->getPayOperationLitersCycle((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< double(*)>(_a[4])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 33: { bool _r = _t->setTransactionClosedCycle((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 34: { bool _r = _t->getTransactionDataCycle((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< double(*)>(_a[4])),(*reinterpret_cast< double(*)>(_a[5])),(*reinterpret_cast< double(*)>(_a[6])),(*reinterpret_cast< double(*)>(_a[7])),(*reinterpret_cast< QDateTime(*)>(_a[8])),(*reinterpret_cast< QDateTime(*)>(_a[9])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject DataBaseControl::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_DataBaseControl.data,
    qt_meta_data_DataBaseControl,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *DataBaseControl::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DataBaseControl::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DataBaseControl.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int DataBaseControl::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 35)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 35;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 35)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 35;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
