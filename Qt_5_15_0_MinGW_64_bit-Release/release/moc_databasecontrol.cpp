/****************************************************************************
** Meta object code from reading C++ file 'databasecontrol.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../Partners/systems/databasecontrol.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'databasecontrol.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DataBaseControl_t {
    QByteArrayData data[135];
    char stringdata0[1591];
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
QT_MOC_LITERAL(4, 45, 9), // "FuelNames"
QT_MOC_LITERAL(5, 55, 7), // "aFuelId"
QT_MOC_LITERAL(6, 63, 8), // "getFuels"
QT_MOC_LITERAL(7, 72, 17), // "QVector<SideFuel>"
QT_MOC_LITERAL(8, 90, 15), // "getCashBoxIndex"
QT_MOC_LITERAL(9, 106, 8), // "iPartner"
QT_MOC_LITERAL(10, 115, 9), // "getPrices"
QT_MOC_LITERAL(11, 125, 5), // "Price"
QT_MOC_LITERAL(12, 131, 11), // "getAgzsData"
QT_MOC_LITERAL(13, 143, 4), // "Agzs"
QT_MOC_LITERAL(14, 148, 15), // "getAgzsAdastTrk"
QT_MOC_LITERAL(15, 164, 8), // "AdastTrk"
QT_MOC_LITERAL(16, 173, 10), // "sideAdress"
QT_MOC_LITERAL(17, 184, 20), // "updateApiTransaction"
QT_MOC_LITERAL(18, 205, 10), // "localState"
QT_MOC_LITERAL(19, 216, 4), // "date"
QT_MOC_LITERAL(20, 221, 5), // "vCode"
QT_MOC_LITERAL(21, 227, 12), // "getLastVCode"
QT_MOC_LITERAL(22, 240, 3), // "key"
QT_MOC_LITERAL(23, 244, 6), // "update"
QT_MOC_LITERAL(24, 251, 10), // "checkError"
QT_MOC_LITERAL(25, 262, 11), // "ErrorsOrder"
QT_MOC_LITERAL(26, 274, 9), // "aColumnID"
QT_MOC_LITERAL(27, 284, 7), // "aFuelID"
QT_MOC_LITERAL(28, 292, 8), // "aiFuelID"
QT_MOC_LITERAL(29, 301, 10), // "aPriceFuel"
QT_MOC_LITERAL(30, 312, 9), // "aIPartner"
QT_MOC_LITERAL(31, 322, 20), // "createTrkTransaction"
QT_MOC_LITERAL(32, 343, 9), // "aAgzsName"
QT_MOC_LITERAL(33, 353, 11), // "aLocalVCode"
QT_MOC_LITERAL(34, 365, 8), // "aTrkType"
QT_MOC_LITERAL(35, 374, 11), // "aDeviceName"
QT_MOC_LITERAL(36, 386, 7), // "aSerial"
QT_MOC_LITERAL(37, 394, 9), // "aFuelName"
QT_MOC_LITERAL(38, 404, 14), // "aFuelShortName"
QT_MOC_LITERAL(39, 419, 5), // "aSide"
QT_MOC_LITERAL(40, 425, 11), // "aSideAdress"
QT_MOC_LITERAL(41, 437, 7), // "aNozzle"
QT_MOC_LITERAL(42, 445, 12), // "aTrkFuelCode"
QT_MOC_LITERAL(43, 458, 9), // "aTransNum"
QT_MOC_LITERAL(44, 468, 14), // "aTrkTotalPrice"
QT_MOC_LITERAL(45, 483, 10), // "aTrkVolume"
QT_MOC_LITERAL(46, 494, 13), // "aTrkUnitPrice"
QT_MOC_LITERAL(47, 508, 18), // "aRequestTotalPrice"
QT_MOC_LITERAL(48, 527, 14), // "aRequestVolume"
QT_MOC_LITERAL(49, 542, 17), // "aRequestUnitPrice"
QT_MOC_LITERAL(50, 560, 13), // "aRequestField"
QT_MOC_LITERAL(51, 574, 6), // "aState"
QT_MOC_LITERAL(52, 581, 7), // "aIState"
QT_MOC_LITERAL(53, 589, 13), // "aTrkTransType"
QT_MOC_LITERAL(54, 603, 18), // "aLitersCountBefore"
QT_MOC_LITERAL(55, 622, 17), // "aMoneyCountBefore"
QT_MOC_LITERAL(56, 640, 17), // "aTransCountBefore"
QT_MOC_LITERAL(57, 658, 17), // "aLitersCountAfter"
QT_MOC_LITERAL(58, 676, 16), // "aMoneyCountAfter"
QT_MOC_LITERAL(59, 693, 16), // "aTransCountAfter"
QT_MOC_LITERAL(60, 710, 7), // "aResult"
QT_MOC_LITERAL(61, 718, 9), // "aDateOpen"
QT_MOC_LITERAL(62, 728, 10), // "aDateClose"
QT_MOC_LITERAL(63, 739, 12), // "aTemperature"
QT_MOC_LITERAL(64, 752, 18), // "aPayOperationVCode"
QT_MOC_LITERAL(65, 771, 7), // "aPayWay"
QT_MOC_LITERAL(66, 779, 11), // "aPrePostPay"
QT_MOC_LITERAL(67, 791, 6), // "aWUser"
QT_MOC_LITERAL(68, 798, 6), // "aWDate"
QT_MOC_LITERAL(69, 805, 6), // "aCUser"
QT_MOC_LITERAL(70, 812, 6), // "aCDate"
QT_MOC_LITERAL(71, 819, 6), // "aCHost"
QT_MOC_LITERAL(72, 826, 6), // "aWHost"
QT_MOC_LITERAL(73, 833, 6), // "aVCode"
QT_MOC_LITERAL(74, 840, 19), // "aAddedForTransVCode"
QT_MOC_LITERAL(75, 860, 20), // "aAditionalTransVCode"
QT_MOC_LITERAL(76, 881, 7), // "aActive"
QT_MOC_LITERAL(77, 889, 5), // "aMass"
QT_MOC_LITERAL(78, 895, 6), // "aSmena"
QT_MOC_LITERAL(79, 902, 9), // "aTrkVcode"
QT_MOC_LITERAL(80, 912, 14), // "aCapacityVcode"
QT_MOC_LITERAL(81, 927, 10), // "aPumpPlace"
QT_MOC_LITERAL(82, 938, 11), // "aMoneyTaken"
QT_MOC_LITERAL(83, 950, 8), // "aIPayWay"
QT_MOC_LITERAL(84, 959, 10), // "aAutoCheck"
QT_MOC_LITERAL(85, 970, 7), // "aClosed"
QT_MOC_LITERAL(86, 978, 9), // "aFullTank"
QT_MOC_LITERAL(87, 988, 5), // "aAgzs"
QT_MOC_LITERAL(88, 994, 10), // "aFuelVCode"
QT_MOC_LITERAL(89, 1005, 7), // "aPropan"
QT_MOC_LITERAL(90, 1013, 11), // "Transaction"
QT_MOC_LITERAL(91, 1025, 11), // "transaction"
QT_MOC_LITERAL(92, 1037, 8), // "getSmena"
QT_MOC_LITERAL(93, 1046, 20), // "createApiTransaction"
QT_MOC_LITERAL(94, 1067, 6), // "aApiId"
QT_MOC_LITERAL(95, 1074, 21), // "aApiStationExtendedId"
QT_MOC_LITERAL(96, 1096, 12), // "aApiColumnId"
QT_MOC_LITERAL(97, 1109, 10), // "aApiFuelId"
QT_MOC_LITERAL(98, 1120, 13), // "aApiPriceFuel"
QT_MOC_LITERAL(99, 1134, 9), // "aApiLitre"
QT_MOC_LITERAL(100, 1144, 7), // "aApiSum"
QT_MOC_LITERAL(101, 1152, 10), // "aApiStatus"
QT_MOC_LITERAL(102, 1163, 14), // "aApiContractId"
QT_MOC_LITERAL(103, 1178, 6), // "aAgent"
QT_MOC_LITERAL(104, 1185, 11), // "aLocalState"
QT_MOC_LITERAL(105, 1197, 6), // "aPrice"
QT_MOC_LITERAL(106, 1204, 6), // "aLitre"
QT_MOC_LITERAL(107, 1211, 4), // "aSum"
QT_MOC_LITERAL(108, 1216, 5), // "aLink"
QT_MOC_LITERAL(109, 1222, 17), // "getApiTransaction"
QT_MOC_LITERAL(110, 1240, 14), // "ApiTransaction"
QT_MOC_LITERAL(111, 1255, 2), // "id"
QT_MOC_LITERAL(112, 1258, 25), // "updateApiTransactionState"
QT_MOC_LITERAL(113, 1284, 9), // "dateClose"
QT_MOC_LITERAL(114, 1294, 30), // "finalUpdateApiTransactionState"
QT_MOC_LITERAL(115, 1325, 5), // "price"
QT_MOC_LITERAL(116, 1331, 6), // "volume"
QT_MOC_LITERAL(117, 1338, 6), // "amount"
QT_MOC_LITERAL(118, 1345, 8), // "dateOpen"
QT_MOC_LITERAL(119, 1354, 21), // "getPayOperationLiters"
QT_MOC_LITERAL(120, 1376, 4), // "link"
QT_MOC_LITERAL(121, 1381, 7), // "double&"
QT_MOC_LITERAL(122, 1389, 20), // "setTransactionClosed"
QT_MOC_LITERAL(123, 1410, 6), // "closed"
QT_MOC_LITERAL(124, 1417, 14), // "getTransaction"
QT_MOC_LITERAL(125, 1432, 21), // "getOpenedTransactions"
QT_MOC_LITERAL(126, 1454, 21), // "QList<ApiTransaction>"
QT_MOC_LITERAL(127, 1476, 8), // "aPartner"
QT_MOC_LITERAL(128, 1485, 14), // "setYandexToken"
QT_MOC_LITERAL(129, 1500, 6), // "aToken"
QT_MOC_LITERAL(130, 1507, 18), // "getCityMobileToken"
QT_MOC_LITERAL(131, 1526, 18), // "isTransactionExist"
QT_MOC_LITERAL(132, 1545, 18), // "getRealSideAddress"
QT_MOC_LITERAL(133, 1564, 19), // "aPartnerSideAddress"
QT_MOC_LITERAL(134, 1584, 6) // "openDB"

    },
    "DataBaseControl\0getCurrentAgzs\0\0"
    "getFuelNames\0FuelNames\0aFuelId\0getFuels\0"
    "QVector<SideFuel>\0getCashBoxIndex\0"
    "iPartner\0getPrices\0Price\0getAgzsData\0"
    "Agzs\0getAgzsAdastTrk\0AdastTrk\0sideAdress\0"
    "updateApiTransaction\0localState\0date\0"
    "vCode\0getLastVCode\0key\0update\0checkError\0"
    "ErrorsOrder\0aColumnID\0aFuelID\0aiFuelID\0"
    "aPriceFuel\0aIPartner\0createTrkTransaction\0"
    "aAgzsName\0aLocalVCode\0aTrkType\0"
    "aDeviceName\0aSerial\0aFuelName\0"
    "aFuelShortName\0aSide\0aSideAdress\0"
    "aNozzle\0aTrkFuelCode\0aTransNum\0"
    "aTrkTotalPrice\0aTrkVolume\0aTrkUnitPrice\0"
    "aRequestTotalPrice\0aRequestVolume\0"
    "aRequestUnitPrice\0aRequestField\0aState\0"
    "aIState\0aTrkTransType\0aLitersCountBefore\0"
    "aMoneyCountBefore\0aTransCountBefore\0"
    "aLitersCountAfter\0aMoneyCountAfter\0"
    "aTransCountAfter\0aResult\0aDateOpen\0"
    "aDateClose\0aTemperature\0aPayOperationVCode\0"
    "aPayWay\0aPrePostPay\0aWUser\0aWDate\0"
    "aCUser\0aCDate\0aCHost\0aWHost\0aVCode\0"
    "aAddedForTransVCode\0aAditionalTransVCode\0"
    "aActive\0aMass\0aSmena\0aTrkVcode\0"
    "aCapacityVcode\0aPumpPlace\0aMoneyTaken\0"
    "aIPayWay\0aAutoCheck\0aClosed\0aFullTank\0"
    "aAgzs\0aFuelVCode\0aPropan\0Transaction\0"
    "transaction\0getSmena\0createApiTransaction\0"
    "aApiId\0aApiStationExtendedId\0aApiColumnId\0"
    "aApiFuelId\0aApiPriceFuel\0aApiLitre\0"
    "aApiSum\0aApiStatus\0aApiContractId\0"
    "aAgent\0aLocalState\0aPrice\0aLitre\0aSum\0"
    "aLink\0getApiTransaction\0ApiTransaction\0"
    "id\0updateApiTransactionState\0dateClose\0"
    "finalUpdateApiTransactionState\0price\0"
    "volume\0amount\0dateOpen\0getPayOperationLiters\0"
    "link\0double&\0setTransactionClosed\0"
    "closed\0getTransaction\0getOpenedTransactions\0"
    "QList<ApiTransaction>\0aPartner\0"
    "setYandexToken\0aToken\0getCityMobileToken\0"
    "isTransactionExist\0getRealSideAddress\0"
    "aPartnerSideAddress\0openDB"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DataBaseControl[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      26,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,  144,    2, 0x0a /* Public */,
       3,    1,  145,    2, 0x0a /* Public */,
       6,    0,  148,    2, 0x0a /* Public */,
       8,    1,  149,    2, 0x0a /* Public */,
      10,    1,  152,    2, 0x0a /* Public */,
      12,    0,  155,    2, 0x0a /* Public */,
      14,    1,  156,    2, 0x0a /* Public */,
      17,    3,  159,    2, 0x0a /* Public */,
      21,    2,  166,    2, 0x0a /* Public */,
      24,    5,  171,    2, 0x0a /* Public */,
      31,   58,  182,    2, 0x0a /* Public */,
      31,    1,  299,    2, 0x0a /* Public */,
      92,    0,  302,    2, 0x0a /* Public */,
      93,   21,  303,    2, 0x0a /* Public */,
     109,    1,  346,    2, 0x0a /* Public */,
     112,    3,  349,    2, 0x0a /* Public */,
     114,    7,  356,    2, 0x0a /* Public */,
     119,    4,  371,    2, 0x0a /* Public */,
     122,    2,  380,    2, 0x0a /* Public */,
     124,    1,  385,    2, 0x0a /* Public */,
     125,    1,  388,    2, 0x0a /* Public */,
     128,    1,  391,    2, 0x0a /* Public */,
     130,    0,  394,    2, 0x0a /* Public */,
     131,    1,  395,    2, 0x0a /* Public */,
     132,    2,  398,    2, 0x0a /* Public */,
     134,    0,  403,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Int,
    0x80000000 | 4, QMetaType::Int,    5,
    0x80000000 | 7,
    QMetaType::Int, QMetaType::QString,    9,
    0x80000000 | 11, QMetaType::QString,    9,
    0x80000000 | 13,
    0x80000000 | 15, QMetaType::Int,   16,
    QMetaType::Bool, QMetaType::Int, QMetaType::QDateTime, QMetaType::Int,   18,   19,   20,
    QMetaType::Int, QMetaType::QString, QMetaType::Bool,   22,   23,
    0x80000000 | 25, QMetaType::QString, QMetaType::QString, QMetaType::Int, QMetaType::QString, QMetaType::Int,   26,   27,   28,   29,   30,
    QMetaType::Bool, QMetaType::QString, QMetaType::Int, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::QString, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::QString, QMetaType::QString, QMetaType::Int, QMetaType::QString, QMetaType::Double, QMetaType::Double, QMetaType::Int, QMetaType::Double, QMetaType::Double, QMetaType::Int, QMetaType::QString, QMetaType::QDateTime, QMetaType::QDateTime, QMetaType::Double, QMetaType::Int, QMetaType::QString, QMetaType::Int, QMetaType::QString, QMetaType::QDateTime, QMetaType::QString, QMetaType::QDateTime, QMetaType::QString, QMetaType::QString, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Double, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Double, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,   32,   33,   34,   35,   36,   37,   38,   39,   40,   41,   42,   43,   44,   45,   46,   47,   48,   49,   50,   51,   52,   53,   54,   55,   56,   57,   58,   59,   60,   61,   62,   63,   64,   65,   66,   67,   68,   69,   70,   71,   72,   73,   74,   75,   76,   77,   78,   79,   80,   81,   82,   83,   84,   85,   86,   87,   88,   89,
    QMetaType::Bool, 0x80000000 | 90,   91,
    QMetaType::Int,
    QMetaType::Bool, QMetaType::QString, QMetaType::Int, QMetaType::QDateTime, QMetaType::Int, QMetaType::QString, QMetaType::QString, QMetaType::Int, QMetaType::QString, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::QDateTime, QMetaType::Int,   32,   87,   70,   73,   94,   95,   96,   97,    5,   98,   99,  100,  101,  102,  103,  104,  105,  106,  107,   61,  108,
    0x80000000 | 110, QMetaType::QString,  111,
    QMetaType::Bool, QMetaType::QString, QMetaType::QDateTime, QMetaType::Int,   18,  113,   20,
    QMetaType::Bool, QMetaType::QString, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::QDateTime, QMetaType::QDateTime, QMetaType::Int,   18,  115,  116,  117,  118,  113,   20,
    QMetaType::Bool, QMetaType::Int, 0x80000000 | 121, 0x80000000 | 121, 0x80000000 | 121,  120,  117,  116,  115,
    QMetaType::Bool, QMetaType::QString, QMetaType::Int,  111,  123,
    0x80000000 | 90, QMetaType::Int,   73,
    0x80000000 | 126, QMetaType::Int,  127,
    QMetaType::Bool, QMetaType::QString,  129,
    QMetaType::QString,
    QMetaType::Bool, QMetaType::QString,   94,
    QMetaType::Int, QMetaType::Int, QMetaType::Int,   87,  133,
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
        case 1: { FuelNames _r = _t->getFuelNames((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< FuelNames*>(_a[0]) = std::move(_r); }  break;
        case 2: { QVector<SideFuel> _r = _t->getFuels();
            if (_a[0]) *reinterpret_cast< QVector<SideFuel>*>(_a[0]) = std::move(_r); }  break;
        case 3: { int _r = _t->getCashBoxIndex((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 4: { Price _r = _t->getPrices((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< Price*>(_a[0]) = std::move(_r); }  break;
        case 5: { Agzs _r = _t->getAgzsData();
            if (_a[0]) *reinterpret_cast< Agzs*>(_a[0]) = std::move(_r); }  break;
        case 6: { AdastTrk _r = _t->getAgzsAdastTrk((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< AdastTrk*>(_a[0]) = std::move(_r); }  break;
        case 7: { bool _r = _t->updateApiTransaction((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QDateTime(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 8: { int _r = _t->getLastVCode((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 9: { ErrorsOrder _r = _t->checkError((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5])));
            if (_a[0]) *reinterpret_cast< ErrorsOrder*>(_a[0]) = std::move(_r); }  break;
        case 10: { bool _r = _t->createTrkTransaction((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5])),(*reinterpret_cast< QString(*)>(_a[6])),(*reinterpret_cast< QString(*)>(_a[7])),(*reinterpret_cast< QString(*)>(_a[8])),(*reinterpret_cast< int(*)>(_a[9])),(*reinterpret_cast< int(*)>(_a[10])),(*reinterpret_cast< int(*)>(_a[11])),(*reinterpret_cast< QString(*)>(_a[12])),(*reinterpret_cast< double(*)>(_a[13])),(*reinterpret_cast< double(*)>(_a[14])),(*reinterpret_cast< double(*)>(_a[15])),(*reinterpret_cast< double(*)>(_a[16])),(*reinterpret_cast< double(*)>(_a[17])),(*reinterpret_cast< double(*)>(_a[18])),(*reinterpret_cast< QString(*)>(_a[19])),(*reinterpret_cast< QString(*)>(_a[20])),(*reinterpret_cast< int(*)>(_a[21])),(*reinterpret_cast< QString(*)>(_a[22])),(*reinterpret_cast< double(*)>(_a[23])),(*reinterpret_cast< double(*)>(_a[24])),(*reinterpret_cast< int(*)>(_a[25])),(*reinterpret_cast< double(*)>(_a[26])),(*reinterpret_cast< double(*)>(_a[27])),(*reinterpret_cast< int(*)>(_a[28])),(*reinterpret_cast< QString(*)>(_a[29])),(*reinterpret_cast< QDateTime(*)>(_a[30])),(*reinterpret_cast< QDateTime(*)>(_a[31])),(*reinterpret_cast< double(*)>(_a[32])),(*reinterpret_cast< int(*)>(_a[33])),(*reinterpret_cast< QString(*)>(_a[34])),(*reinterpret_cast< int(*)>(_a[35])),(*reinterpret_cast< QString(*)>(_a[36])),(*reinterpret_cast< QDateTime(*)>(_a[37])),(*reinterpret_cast< QString(*)>(_a[38])),(*reinterpret_cast< QDateTime(*)>(_a[39])),(*reinterpret_cast< QString(*)>(_a[40])),(*reinterpret_cast< QString(*)>(_a[41])),(*reinterpret_cast< int(*)>(_a[42])),(*reinterpret_cast< int(*)>(_a[43])),(*reinterpret_cast< int(*)>(_a[44])),(*reinterpret_cast< int(*)>(_a[45])),(*reinterpret_cast< double(*)>(_a[46])),(*reinterpret_cast< int(*)>(_a[47])),(*reinterpret_cast< int(*)>(_a[48])),(*reinterpret_cast< int(*)>(_a[49])),(*reinterpret_cast< int(*)>(_a[50])),(*reinterpret_cast< double(*)>(_a[51])),(*reinterpret_cast< int(*)>(_a[52])),(*reinterpret_cast< int(*)>(_a[53])),(*reinterpret_cast< int(*)>(_a[54])),(*reinterpret_cast< int(*)>(_a[55])),(*reinterpret_cast< int(*)>(_a[56])),(*reinterpret_cast< int(*)>(_a[57])),(*reinterpret_cast< int(*)>(_a[58])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 11: { bool _r = _t->createTrkTransaction((*reinterpret_cast< Transaction(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 12: { int _r = _t->getSmena();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 13: { bool _r = _t->createApiTransaction((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< QDateTime(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5])),(*reinterpret_cast< QString(*)>(_a[6])),(*reinterpret_cast< int(*)>(_a[7])),(*reinterpret_cast< QString(*)>(_a[8])),(*reinterpret_cast< int(*)>(_a[9])),(*reinterpret_cast< int(*)>(_a[10])),(*reinterpret_cast< int(*)>(_a[11])),(*reinterpret_cast< int(*)>(_a[12])),(*reinterpret_cast< QString(*)>(_a[13])),(*reinterpret_cast< QString(*)>(_a[14])),(*reinterpret_cast< QString(*)>(_a[15])),(*reinterpret_cast< QString(*)>(_a[16])),(*reinterpret_cast< double(*)>(_a[17])),(*reinterpret_cast< double(*)>(_a[18])),(*reinterpret_cast< double(*)>(_a[19])),(*reinterpret_cast< QDateTime(*)>(_a[20])),(*reinterpret_cast< int(*)>(_a[21])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 14: { ApiTransaction _r = _t->getApiTransaction((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< ApiTransaction*>(_a[0]) = std::move(_r); }  break;
        case 15: { bool _r = _t->updateApiTransactionState((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QDateTime(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 16: { bool _r = _t->finalUpdateApiTransactionState((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< double(*)>(_a[4])),(*reinterpret_cast< QDateTime(*)>(_a[5])),(*reinterpret_cast< QDateTime(*)>(_a[6])),(*reinterpret_cast< int(*)>(_a[7])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 17: { bool _r = _t->getPayOperationLiters((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< double(*)>(_a[4])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 18: { bool _r = _t->setTransactionClosed((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 19: { Transaction _r = _t->getTransaction((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< Transaction*>(_a[0]) = std::move(_r); }  break;
        case 20: { QList<ApiTransaction> _r = _t->getOpenedTransactions((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QList<ApiTransaction>*>(_a[0]) = std::move(_r); }  break;
        case 21: { bool _r = _t->setYandexToken((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 22: { QString _r = _t->getCityMobileToken();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 23: { bool _r = _t->isTransactionExist((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 24: { int _r = _t->getRealSideAddress((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 25: { bool _r = _t->openDB();
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
        if (_id < 26)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 26;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 26)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 26;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
