/****************************************************************************
** Meta object code from reading C++ file 'databasecontrol.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../Partners/systems/databasecontrol.h"
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
    QByteArrayData data[167];
    char stringdata0[1801];
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
QT_MOC_LITERAL(9, 90, 35), // "QVector<QPair<int,QVector<int..."
QT_MOC_LITERAL(10, 126, 5), // "fuels"
QT_MOC_LITERAL(11, 132, 15), // "getCashBoxIndex"
QT_MOC_LITERAL(12, 148, 8), // "iPartner"
QT_MOC_LITERAL(13, 157, 9), // "getPrices"
QT_MOC_LITERAL(14, 167, 8), // "agzsName"
QT_MOC_LITERAL(15, 176, 4), // "int&"
QT_MOC_LITERAL(16, 181, 4), // "agzs"
QT_MOC_LITERAL(17, 186, 5), // "vCode"
QT_MOC_LITERAL(18, 192, 4), // "link"
QT_MOC_LITERAL(19, 197, 10), // "QDateTime&"
QT_MOC_LITERAL(20, 208, 5), // "cDate"
QT_MOC_LITERAL(21, 214, 7), // "partner"
QT_MOC_LITERAL(22, 222, 7), // "double&"
QT_MOC_LITERAL(23, 230, 6), // "diesel"
QT_MOC_LITERAL(24, 237, 14), // "diesel_premium"
QT_MOC_LITERAL(25, 252, 3), // "a80"
QT_MOC_LITERAL(26, 256, 3), // "a92"
QT_MOC_LITERAL(27, 260, 11), // "a92_premium"
QT_MOC_LITERAL(28, 272, 3), // "a95"
QT_MOC_LITERAL(29, 276, 11), // "a95_premium"
QT_MOC_LITERAL(30, 288, 3), // "a98"
QT_MOC_LITERAL(31, 292, 11), // "a98_premium"
QT_MOC_LITERAL(32, 304, 4), // "a100"
QT_MOC_LITERAL(33, 309, 12), // "a100_premium"
QT_MOC_LITERAL(34, 322, 7), // "propane"
QT_MOC_LITERAL(35, 330, 5), // "metan"
QT_MOC_LITERAL(36, 336, 11), // "getAgzsData"
QT_MOC_LITERAL(37, 348, 2), // "id"
QT_MOC_LITERAL(38, 351, 6), // "adress"
QT_MOC_LITERAL(39, 358, 5), // "loc_x"
QT_MOC_LITERAL(40, 364, 5), // "loc_y"
QT_MOC_LITERAL(41, 370, 11), // "columnCount"
QT_MOC_LITERAL(42, 382, 15), // "getAgzsAdastTrk"
QT_MOC_LITERAL(43, 398, 10), // "sideAdress"
QT_MOC_LITERAL(44, 409, 4), // "side"
QT_MOC_LITERAL(45, 414, 10), // "deviceName"
QT_MOC_LITERAL(46, 425, 6), // "serial"
QT_MOC_LITERAL(47, 432, 11), // "description"
QT_MOC_LITERAL(48, 444, 9), // "fuelCode1"
QT_MOC_LITERAL(49, 454, 9), // "fuelCode2"
QT_MOC_LITERAL(50, 464, 9), // "fuelCode3"
QT_MOC_LITERAL(51, 474, 9), // "fuelCode4"
QT_MOC_LITERAL(52, 484, 9), // "fuelCode5"
QT_MOC_LITERAL(53, 494, 8), // "trkVCode"
QT_MOC_LITERAL(54, 503, 9), // "pumpPlace"
QT_MOC_LITERAL(55, 513, 5), // "fuel1"
QT_MOC_LITERAL(56, 519, 5), // "fuel2"
QT_MOC_LITERAL(57, 525, 5), // "fuel3"
QT_MOC_LITERAL(58, 531, 5), // "fuel4"
QT_MOC_LITERAL(59, 537, 5), // "fuel5"
QT_MOC_LITERAL(60, 543, 20), // "updateApiTransaction"
QT_MOC_LITERAL(61, 564, 10), // "localState"
QT_MOC_LITERAL(62, 575, 4), // "date"
QT_MOC_LITERAL(63, 580, 12), // "getLastVCode"
QT_MOC_LITERAL(64, 593, 3), // "key"
QT_MOC_LITERAL(65, 597, 6), // "update"
QT_MOC_LITERAL(66, 604, 10), // "checkError"
QT_MOC_LITERAL(67, 615, 9), // "aColumnID"
QT_MOC_LITERAL(68, 625, 7), // "aFuelID"
QT_MOC_LITERAL(69, 633, 8), // "aiFuelID"
QT_MOC_LITERAL(70, 642, 10), // "aPriceFuel"
QT_MOC_LITERAL(71, 653, 9), // "aIPartner"
QT_MOC_LITERAL(72, 663, 20), // "createTrkTransaction"
QT_MOC_LITERAL(73, 684, 9), // "aAgzsName"
QT_MOC_LITERAL(74, 694, 11), // "aLocalVCode"
QT_MOC_LITERAL(75, 706, 8), // "aTrkType"
QT_MOC_LITERAL(76, 715, 11), // "aDeviceName"
QT_MOC_LITERAL(77, 727, 7), // "aSerial"
QT_MOC_LITERAL(78, 735, 9), // "aFuelName"
QT_MOC_LITERAL(79, 745, 14), // "aFuelShortName"
QT_MOC_LITERAL(80, 760, 5), // "aSide"
QT_MOC_LITERAL(81, 766, 11), // "aSideAdress"
QT_MOC_LITERAL(82, 778, 7), // "aNozzle"
QT_MOC_LITERAL(83, 786, 12), // "aTrkFuelCode"
QT_MOC_LITERAL(84, 799, 9), // "aTransNum"
QT_MOC_LITERAL(85, 809, 14), // "aTrkTotalPrice"
QT_MOC_LITERAL(86, 824, 10), // "aTrkVolume"
QT_MOC_LITERAL(87, 835, 13), // "aTrkUnitPrice"
QT_MOC_LITERAL(88, 849, 18), // "aRequestTotalPrice"
QT_MOC_LITERAL(89, 868, 14), // "aRequestVolume"
QT_MOC_LITERAL(90, 883, 17), // "aRequestUnitPrice"
QT_MOC_LITERAL(91, 901, 13), // "aRequestField"
QT_MOC_LITERAL(92, 915, 6), // "aState"
QT_MOC_LITERAL(93, 922, 7), // "aIState"
QT_MOC_LITERAL(94, 930, 13), // "aTrkTransType"
QT_MOC_LITERAL(95, 944, 18), // "aLitersCountBefore"
QT_MOC_LITERAL(96, 963, 17), // "aMoneyCountBefore"
QT_MOC_LITERAL(97, 981, 17), // "aTransCountBefore"
QT_MOC_LITERAL(98, 999, 17), // "aLitersCountAfter"
QT_MOC_LITERAL(99, 1017, 16), // "aMoneyCountAfter"
QT_MOC_LITERAL(100, 1034, 16), // "aTransCountAfter"
QT_MOC_LITERAL(101, 1051, 7), // "aResult"
QT_MOC_LITERAL(102, 1059, 9), // "aDateOpen"
QT_MOC_LITERAL(103, 1069, 10), // "aDateClose"
QT_MOC_LITERAL(104, 1080, 12), // "aTemperature"
QT_MOC_LITERAL(105, 1093, 18), // "aPayOperationVCode"
QT_MOC_LITERAL(106, 1112, 7), // "aPayWay"
QT_MOC_LITERAL(107, 1120, 11), // "aPrePostPay"
QT_MOC_LITERAL(108, 1132, 6), // "aWUser"
QT_MOC_LITERAL(109, 1139, 6), // "aWDate"
QT_MOC_LITERAL(110, 1146, 6), // "aCUser"
QT_MOC_LITERAL(111, 1153, 6), // "aCDate"
QT_MOC_LITERAL(112, 1160, 6), // "aCHost"
QT_MOC_LITERAL(113, 1167, 6), // "aWHost"
QT_MOC_LITERAL(114, 1174, 6), // "aVCode"
QT_MOC_LITERAL(115, 1181, 19), // "aAddedForTransVCode"
QT_MOC_LITERAL(116, 1201, 20), // "aAditionalTransVCode"
QT_MOC_LITERAL(117, 1222, 7), // "aActive"
QT_MOC_LITERAL(118, 1230, 5), // "aMass"
QT_MOC_LITERAL(119, 1236, 6), // "aSmena"
QT_MOC_LITERAL(120, 1243, 9), // "aTrkVcode"
QT_MOC_LITERAL(121, 1253, 14), // "aCapacityVcode"
QT_MOC_LITERAL(122, 1268, 10), // "aPumpPlace"
QT_MOC_LITERAL(123, 1279, 11), // "aMoneyTaken"
QT_MOC_LITERAL(124, 1291, 8), // "aIPayWay"
QT_MOC_LITERAL(125, 1300, 10), // "aAutoCheck"
QT_MOC_LITERAL(126, 1311, 7), // "aClosed"
QT_MOC_LITERAL(127, 1319, 9), // "aFullTank"
QT_MOC_LITERAL(128, 1329, 5), // "aAgzs"
QT_MOC_LITERAL(129, 1335, 10), // "aFuelVCode"
QT_MOC_LITERAL(130, 1346, 7), // "aPropan"
QT_MOC_LITERAL(131, 1354, 8), // "getSmena"
QT_MOC_LITERAL(132, 1363, 20), // "createApiTransaction"
QT_MOC_LITERAL(133, 1384, 6), // "aApiId"
QT_MOC_LITERAL(134, 1391, 21), // "aApiStationExtendedId"
QT_MOC_LITERAL(135, 1413, 12), // "aApiColumnId"
QT_MOC_LITERAL(136, 1426, 10), // "aApiFuelId"
QT_MOC_LITERAL(137, 1437, 13), // "aApiPriceFuel"
QT_MOC_LITERAL(138, 1451, 9), // "aApiLitre"
QT_MOC_LITERAL(139, 1461, 7), // "aApiSum"
QT_MOC_LITERAL(140, 1469, 10), // "aApiStatus"
QT_MOC_LITERAL(141, 1480, 14), // "aApiContractId"
QT_MOC_LITERAL(142, 1495, 6), // "aAgent"
QT_MOC_LITERAL(143, 1502, 11), // "aLocalState"
QT_MOC_LITERAL(144, 1514, 6), // "aPrice"
QT_MOC_LITERAL(145, 1521, 6), // "aLitre"
QT_MOC_LITERAL(146, 1528, 4), // "aSum"
QT_MOC_LITERAL(147, 1533, 5), // "aLink"
QT_MOC_LITERAL(148, 1539, 22), // "getApiTransactionState"
QT_MOC_LITERAL(149, 1562, 8), // "apiVCode"
QT_MOC_LITERAL(150, 1571, 9), // "headVCode"
QT_MOC_LITERAL(151, 1581, 6), // "iState"
QT_MOC_LITERAL(152, 1588, 8), // "dateOpen"
QT_MOC_LITERAL(153, 1597, 9), // "dateClose"
QT_MOC_LITERAL(154, 1607, 25), // "updateApiTransactionState"
QT_MOC_LITERAL(155, 1633, 30), // "finalUpdateApiTransactionState"
QT_MOC_LITERAL(156, 1664, 5), // "price"
QT_MOC_LITERAL(157, 1670, 6), // "volume"
QT_MOC_LITERAL(158, 1677, 6), // "amount"
QT_MOC_LITERAL(159, 1684, 21), // "getPayOperationLiters"
QT_MOC_LITERAL(160, 1706, 20), // "setTransactionClosed"
QT_MOC_LITERAL(161, 1727, 6), // "closed"
QT_MOC_LITERAL(162, 1734, 18), // "getTransactionData"
QT_MOC_LITERAL(163, 1753, 14), // "setYandexToken"
QT_MOC_LITERAL(164, 1768, 6), // "aToken"
QT_MOC_LITERAL(165, 1775, 18), // "isTransactionExist"
QT_MOC_LITERAL(166, 1794, 6) // "openDB"

    },
    "DataBaseControl\0getCurrentAgzs\0\0"
    "getFuelNames\0aFuelId\0QString&\0fullName\0"
    "shortName\0getFuels\0"
    "QVector<QPair<int,QVector<int> > >&\0"
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
    "aToken\0isTransactionExist\0openDB"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DataBaseControl[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      22,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,  124,    2, 0x0a /* Public */,
       3,    3,  125,    2, 0x0a /* Public */,
       8,    1,  132,    2, 0x0a /* Public */,
      11,    1,  135,    2, 0x0a /* Public */,
      13,   20,  138,    2, 0x0a /* Public */,
      36,    9,  179,    2, 0x0a /* Public */,
      42,   17,  198,    2, 0x0a /* Public */,
      60,    3,  233,    2, 0x0a /* Public */,
      63,    2,  240,    2, 0x0a /* Public */,
      66,    5,  245,    2, 0x0a /* Public */,
      72,   58,  256,    2, 0x0a /* Public */,
     131,    0,  373,    2, 0x0a /* Public */,
     132,   21,  374,    2, 0x0a /* Public */,
     148,    8,  417,    2, 0x0a /* Public */,
     154,    3,  434,    2, 0x0a /* Public */,
     155,    7,  441,    2, 0x0a /* Public */,
     159,    4,  456,    2, 0x0a /* Public */,
     160,    2,  465,    2, 0x0a /* Public */,
     162,    9,  470,    2, 0x0a /* Public */,
     163,    1,  489,    2, 0x0a /* Public */,
     165,    1,  492,    2, 0x0a /* Public */,
     166,    0,  495,    2, 0x08 /* Private */,

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
    QMetaType::Bool, QMetaType::QString,  133,
    QMetaType::Bool,

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
        case 2: { bool _r = _t->getFuels((*reinterpret_cast< QVector<QPair<int,QVector<int> > >(*)>(_a[1])));
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
        case 20: { bool _r = _t->isTransactionExist((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 21: { bool _r = _t->openDB();
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
        if (_id < 22)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 22;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 22)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 22;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
