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
    QByteArrayData data[144];
    char stringdata0[1732];
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
QT_MOC_LITERAL(17, 184, 13), // "generateVCode"
QT_MOC_LITERAL(18, 198, 3), // "key"
QT_MOC_LITERAL(19, 202, 10), // "checkError"
QT_MOC_LITERAL(20, 213, 11), // "ErrorsOrder"
QT_MOC_LITERAL(21, 225, 9), // "aColumnID"
QT_MOC_LITERAL(22, 235, 7), // "aFuelID"
QT_MOC_LITERAL(23, 243, 8), // "aiFuelID"
QT_MOC_LITERAL(24, 252, 10), // "aPriceFuel"
QT_MOC_LITERAL(25, 263, 9), // "aIPartner"
QT_MOC_LITERAL(26, 273, 20), // "createTrkTransaction"
QT_MOC_LITERAL(27, 294, 9), // "aAgzsName"
QT_MOC_LITERAL(28, 304, 11), // "aLocalVCode"
QT_MOC_LITERAL(29, 316, 8), // "aTrkType"
QT_MOC_LITERAL(30, 325, 11), // "aDeviceName"
QT_MOC_LITERAL(31, 337, 7), // "aSerial"
QT_MOC_LITERAL(32, 345, 9), // "aFuelName"
QT_MOC_LITERAL(33, 355, 14), // "aFuelShortName"
QT_MOC_LITERAL(34, 370, 5), // "aSide"
QT_MOC_LITERAL(35, 376, 11), // "aSideAdress"
QT_MOC_LITERAL(36, 388, 7), // "aNozzle"
QT_MOC_LITERAL(37, 396, 12), // "aTrkFuelCode"
QT_MOC_LITERAL(38, 409, 9), // "aTransNum"
QT_MOC_LITERAL(39, 419, 14), // "aTrkTotalPrice"
QT_MOC_LITERAL(40, 434, 10), // "aTrkVolume"
QT_MOC_LITERAL(41, 445, 13), // "aTrkUnitPrice"
QT_MOC_LITERAL(42, 459, 18), // "aRequestTotalPrice"
QT_MOC_LITERAL(43, 478, 14), // "aRequestVolume"
QT_MOC_LITERAL(44, 493, 17), // "aRequestUnitPrice"
QT_MOC_LITERAL(45, 511, 13), // "aRequestField"
QT_MOC_LITERAL(46, 525, 6), // "aState"
QT_MOC_LITERAL(47, 532, 7), // "aIState"
QT_MOC_LITERAL(48, 540, 13), // "aTrkTransType"
QT_MOC_LITERAL(49, 554, 18), // "aLitersCountBefore"
QT_MOC_LITERAL(50, 573, 17), // "aMoneyCountBefore"
QT_MOC_LITERAL(51, 591, 17), // "aTransCountBefore"
QT_MOC_LITERAL(52, 609, 17), // "aLitersCountAfter"
QT_MOC_LITERAL(53, 627, 16), // "aMoneyCountAfter"
QT_MOC_LITERAL(54, 644, 16), // "aTransCountAfter"
QT_MOC_LITERAL(55, 661, 7), // "aResult"
QT_MOC_LITERAL(56, 669, 9), // "aDateOpen"
QT_MOC_LITERAL(57, 679, 10), // "aDateClose"
QT_MOC_LITERAL(58, 690, 12), // "aTemperature"
QT_MOC_LITERAL(59, 703, 18), // "aPayOperationVCode"
QT_MOC_LITERAL(60, 722, 7), // "aPayWay"
QT_MOC_LITERAL(61, 730, 11), // "aPrePostPay"
QT_MOC_LITERAL(62, 742, 6), // "aWUser"
QT_MOC_LITERAL(63, 749, 6), // "aWDate"
QT_MOC_LITERAL(64, 756, 6), // "aCUser"
QT_MOC_LITERAL(65, 763, 6), // "aCDate"
QT_MOC_LITERAL(66, 770, 6), // "aCHost"
QT_MOC_LITERAL(67, 777, 6), // "aWHost"
QT_MOC_LITERAL(68, 784, 6), // "aVCode"
QT_MOC_LITERAL(69, 791, 19), // "aAddedForTransVCode"
QT_MOC_LITERAL(70, 811, 20), // "aAditionalTransVCode"
QT_MOC_LITERAL(71, 832, 7), // "aActive"
QT_MOC_LITERAL(72, 840, 5), // "aMass"
QT_MOC_LITERAL(73, 846, 6), // "aSmena"
QT_MOC_LITERAL(74, 853, 9), // "aTrkVcode"
QT_MOC_LITERAL(75, 863, 14), // "aCapacityVcode"
QT_MOC_LITERAL(76, 878, 10), // "aPumpPlace"
QT_MOC_LITERAL(77, 889, 11), // "aMoneyTaken"
QT_MOC_LITERAL(78, 901, 8), // "aIPayWay"
QT_MOC_LITERAL(79, 910, 10), // "aAutoCheck"
QT_MOC_LITERAL(80, 921, 7), // "aClosed"
QT_MOC_LITERAL(81, 929, 9), // "aFullTank"
QT_MOC_LITERAL(82, 939, 5), // "aAgzs"
QT_MOC_LITERAL(83, 945, 10), // "aFuelVCode"
QT_MOC_LITERAL(84, 956, 7), // "aPropan"
QT_MOC_LITERAL(85, 964, 11), // "Transaction"
QT_MOC_LITERAL(86, 976, 11), // "transaction"
QT_MOC_LITERAL(87, 988, 8), // "getSmena"
QT_MOC_LITERAL(88, 997, 20), // "createApiTransaction"
QT_MOC_LITERAL(89, 1018, 6), // "aApiId"
QT_MOC_LITERAL(90, 1025, 21), // "aApiStationExtendedId"
QT_MOC_LITERAL(91, 1047, 12), // "aApiColumnId"
QT_MOC_LITERAL(92, 1060, 10), // "aApiFuelId"
QT_MOC_LITERAL(93, 1071, 13), // "aApiPriceFuel"
QT_MOC_LITERAL(94, 1085, 9), // "aApiLitre"
QT_MOC_LITERAL(95, 1095, 7), // "aApiSum"
QT_MOC_LITERAL(96, 1103, 10), // "aApiStatus"
QT_MOC_LITERAL(97, 1114, 14), // "aApiContractId"
QT_MOC_LITERAL(98, 1129, 6), // "aAgent"
QT_MOC_LITERAL(99, 1136, 11), // "aLocalState"
QT_MOC_LITERAL(100, 1148, 6), // "aPrice"
QT_MOC_LITERAL(101, 1155, 6), // "aLitre"
QT_MOC_LITERAL(102, 1162, 4), // "aSum"
QT_MOC_LITERAL(103, 1167, 5), // "aLink"
QT_MOC_LITERAL(104, 1173, 24), // "updateApiTransactionLink"
QT_MOC_LITERAL(105, 1198, 17), // "getApiTransaction"
QT_MOC_LITERAL(106, 1216, 14), // "ApiTransaction"
QT_MOC_LITERAL(107, 1231, 2), // "id"
QT_MOC_LITERAL(108, 1234, 25), // "updateApiTransactionState"
QT_MOC_LITERAL(109, 1260, 10), // "localState"
QT_MOC_LITERAL(110, 1271, 9), // "dateClose"
QT_MOC_LITERAL(111, 1281, 5), // "vCode"
QT_MOC_LITERAL(112, 1287, 30), // "finalUpdateApiTransactionState"
QT_MOC_LITERAL(113, 1318, 5), // "price"
QT_MOC_LITERAL(114, 1324, 6), // "volume"
QT_MOC_LITERAL(115, 1331, 6), // "amount"
QT_MOC_LITERAL(116, 1338, 8), // "dateOpen"
QT_MOC_LITERAL(117, 1347, 19), // "getPayOperationData"
QT_MOC_LITERAL(118, 1367, 4), // "link"
QT_MOC_LITERAL(119, 1372, 7), // "double&"
QT_MOC_LITERAL(120, 1380, 10), // "QDateTime&"
QT_MOC_LITERAL(121, 1391, 10), // "aDateStart"
QT_MOC_LITERAL(122, 1402, 8), // "aDateEnd"
QT_MOC_LITERAL(123, 1411, 20), // "setTransactionClosed"
QT_MOC_LITERAL(124, 1432, 6), // "closed"
QT_MOC_LITERAL(125, 1439, 14), // "getTransaction"
QT_MOC_LITERAL(126, 1454, 24), // "getOpenedApiTransactions"
QT_MOC_LITERAL(127, 1479, 21), // "QList<ApiTransaction>"
QT_MOC_LITERAL(128, 1501, 8), // "aPartner"
QT_MOC_LITERAL(129, 1510, 17), // "updateYandexToken"
QT_MOC_LITERAL(130, 1528, 6), // "aToken"
QT_MOC_LITERAL(131, 1535, 18), // "getCityMobileToken"
QT_MOC_LITERAL(132, 1554, 21), // "isApiTransactionExist"
QT_MOC_LITERAL(133, 1576, 18), // "getRealSideAddress"
QT_MOC_LITERAL(134, 1595, 19), // "aPartnerSideAddress"
QT_MOC_LITERAL(135, 1615, 6), // "openDB"
QT_MOC_LITERAL(136, 1622, 9), // "makeQuery"
QT_MOC_LITERAL(137, 1632, 5), // "query"
QT_MOC_LITERAL(138, 1638, 4), // "name"
QT_MOC_LITERAL(139, 1643, 26), // "DataBaseControl::QueryType"
QT_MOC_LITERAL(140, 1670, 4), // "type"
QT_MOC_LITERAL(141, 1675, 31), // "std::function<void(QSqlQuery&)>"
QT_MOC_LITERAL(142, 1707, 4), // "func"
QT_MOC_LITERAL(143, 1712, 19) // "isShowMessageNoData"

    },
    "DataBaseControl\0getCurrentAgzs\0\0"
    "getFuelNames\0FuelNames\0aFuelId\0getFuels\0"
    "QVector<SideFuel>\0getCashBoxIndex\0"
    "iPartner\0getPrices\0Price\0getAgzsData\0"
    "Agzs\0getAgzsAdastTrk\0AdastTrk\0sideAdress\0"
    "generateVCode\0key\0checkError\0ErrorsOrder\0"
    "aColumnID\0aFuelID\0aiFuelID\0aPriceFuel\0"
    "aIPartner\0createTrkTransaction\0aAgzsName\0"
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
    "aFuelVCode\0aPropan\0Transaction\0"
    "transaction\0getSmena\0createApiTransaction\0"
    "aApiId\0aApiStationExtendedId\0aApiColumnId\0"
    "aApiFuelId\0aApiPriceFuel\0aApiLitre\0"
    "aApiSum\0aApiStatus\0aApiContractId\0"
    "aAgent\0aLocalState\0aPrice\0aLitre\0aSum\0"
    "aLink\0updateApiTransactionLink\0"
    "getApiTransaction\0ApiTransaction\0id\0"
    "updateApiTransactionState\0localState\0"
    "dateClose\0vCode\0finalUpdateApiTransactionState\0"
    "price\0volume\0amount\0dateOpen\0"
    "getPayOperationData\0link\0double&\0"
    "QDateTime&\0aDateStart\0aDateEnd\0"
    "setTransactionClosed\0closed\0getTransaction\0"
    "getOpenedApiTransactions\0QList<ApiTransaction>\0"
    "aPartner\0updateYandexToken\0aToken\0"
    "getCityMobileToken\0isApiTransactionExist\0"
    "getRealSideAddress\0aPartnerSideAddress\0"
    "openDB\0makeQuery\0query\0name\0"
    "DataBaseControl::QueryType\0type\0"
    "std::function<void(QSqlQuery&)>\0func\0"
    "isShowMessageNoData"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DataBaseControl[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      30,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,  164,    2, 0x0a /* Public */,
       3,    1,  165,    2, 0x0a /* Public */,
       6,    0,  168,    2, 0x0a /* Public */,
       8,    1,  169,    2, 0x0a /* Public */,
      10,    1,  172,    2, 0x0a /* Public */,
      12,    0,  175,    2, 0x0a /* Public */,
      14,    1,  176,    2, 0x0a /* Public */,
      17,    1,  179,    2, 0x0a /* Public */,
      19,    5,  182,    2, 0x0a /* Public */,
      26,   58,  193,    2, 0x0a /* Public */,
      26,    1,  310,    2, 0x0a /* Public */,
      87,    0,  313,    2, 0x0a /* Public */,
      88,   21,  314,    2, 0x0a /* Public */,
     104,    2,  357,    2, 0x0a /* Public */,
     105,    1,  362,    2, 0x0a /* Public */,
     108,    3,  365,    2, 0x0a /* Public */,
     112,    7,  372,    2, 0x0a /* Public */,
     117,    6,  387,    2, 0x0a /* Public */,
     123,    2,  400,    2, 0x0a /* Public */,
     125,    1,  405,    2, 0x0a /* Public */,
     126,    1,  408,    2, 0x0a /* Public */,
     129,    1,  411,    2, 0x0a /* Public */,
     131,    0,  414,    2, 0x0a /* Public */,
     132,    1,  415,    2, 0x0a /* Public */,
     132,    1,  418,    2, 0x0a /* Public */,
     133,    2,  421,    2, 0x0a /* Public */,
     135,    0,  426,    2, 0x08 /* Private */,
     136,    5,  427,    2, 0x08 /* Private */,
     136,    4,  438,    2, 0x28 /* Private | MethodCloned */,
     136,    3,  447,    2, 0x28 /* Private | MethodCloned */,

 // slots: parameters
    QMetaType::Int,
    0x80000000 | 4, QMetaType::Int,    5,
    0x80000000 | 7,
    QMetaType::Int, QMetaType::QString,    9,
    0x80000000 | 11, QMetaType::QString,    9,
    0x80000000 | 13,
    0x80000000 | 15, QMetaType::Int,   16,
    QMetaType::Int, QMetaType::QString,   18,
    0x80000000 | 20, QMetaType::QString, QMetaType::QString, QMetaType::Int, QMetaType::QString, QMetaType::Int,   21,   22,   23,   24,   25,
    QMetaType::Bool, QMetaType::QString, QMetaType::Int, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::QString, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::QString, QMetaType::QString, QMetaType::Int, QMetaType::QString, QMetaType::Double, QMetaType::Double, QMetaType::Int, QMetaType::Double, QMetaType::Double, QMetaType::Int, QMetaType::QString, QMetaType::QDateTime, QMetaType::QDateTime, QMetaType::Double, QMetaType::Int, QMetaType::QString, QMetaType::Int, QMetaType::QString, QMetaType::QDateTime, QMetaType::QString, QMetaType::QDateTime, QMetaType::QString, QMetaType::QString, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Double, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Double, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,   27,   28,   29,   30,   31,   32,   33,   34,   35,   36,   37,   38,   39,   40,   41,   42,   43,   44,   45,   46,   47,   48,   49,   50,   51,   52,   53,   54,   55,   56,   57,   58,   59,   60,   61,   62,   63,   64,   65,   66,   67,   68,   69,   70,   71,   72,   73,   74,   75,   76,   77,   78,   79,   80,   81,   82,   83,   84,
    QMetaType::Bool, 0x80000000 | 85,   86,
    QMetaType::Int,
    QMetaType::Bool, QMetaType::QString, QMetaType::Int, QMetaType::QDateTime, QMetaType::Int, QMetaType::QString, QMetaType::QString, QMetaType::Int, QMetaType::QString, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::QDateTime, QMetaType::Int,   27,   82,   65,   68,   89,   90,   91,   92,    5,   93,   94,   95,   96,   97,   98,   99,  100,  101,  102,   56,  103,
    QMetaType::Bool, QMetaType::QString, QMetaType::Int,   89,  103,
    0x80000000 | 106, QMetaType::QString,  107,
    QMetaType::Bool, QMetaType::QString, QMetaType::QDateTime, QMetaType::Int,  109,  110,  111,
    QMetaType::Bool, QMetaType::QString, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::QDateTime, QMetaType::QDateTime, QMetaType::Int,  109,  113,  114,  115,  116,  110,  111,
    QMetaType::Bool, QMetaType::Int, 0x80000000 | 119, 0x80000000 | 119, 0x80000000 | 119, 0x80000000 | 120, 0x80000000 | 120,  118,  115,  114,  113,  121,  122,
    QMetaType::Bool, QMetaType::QString, QMetaType::Int,  107,  124,
    0x80000000 | 85, QMetaType::Int,   68,
    0x80000000 | 127, QMetaType::Int,  128,
    QMetaType::Bool, QMetaType::QString,  130,
    QMetaType::QString,
    QMetaType::Bool, QMetaType::QString,   89,
    QMetaType::Bool, QMetaType::Int,   68,
    QMetaType::Int, QMetaType::Int, QMetaType::Int,   82,  134,
    QMetaType::Bool,
    QMetaType::Bool, QMetaType::QString, QMetaType::QString, 0x80000000 | 139, 0x80000000 | 141, QMetaType::Bool,  137,  138,  140,  142,  143,
    QMetaType::Bool, QMetaType::QString, QMetaType::QString, 0x80000000 | 139, 0x80000000 | 141,  137,  138,  140,  142,
    QMetaType::Bool, QMetaType::QString, QMetaType::QString, 0x80000000 | 139,  137,  138,  140,

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
        case 7: { int _r = _t->generateVCode((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 8: { ErrorsOrder _r = _t->checkError((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5])));
            if (_a[0]) *reinterpret_cast< ErrorsOrder*>(_a[0]) = std::move(_r); }  break;
        case 9: { bool _r = _t->createTrkTransaction((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5])),(*reinterpret_cast< QString(*)>(_a[6])),(*reinterpret_cast< QString(*)>(_a[7])),(*reinterpret_cast< QString(*)>(_a[8])),(*reinterpret_cast< int(*)>(_a[9])),(*reinterpret_cast< int(*)>(_a[10])),(*reinterpret_cast< int(*)>(_a[11])),(*reinterpret_cast< QString(*)>(_a[12])),(*reinterpret_cast< double(*)>(_a[13])),(*reinterpret_cast< double(*)>(_a[14])),(*reinterpret_cast< double(*)>(_a[15])),(*reinterpret_cast< double(*)>(_a[16])),(*reinterpret_cast< double(*)>(_a[17])),(*reinterpret_cast< double(*)>(_a[18])),(*reinterpret_cast< QString(*)>(_a[19])),(*reinterpret_cast< QString(*)>(_a[20])),(*reinterpret_cast< int(*)>(_a[21])),(*reinterpret_cast< QString(*)>(_a[22])),(*reinterpret_cast< double(*)>(_a[23])),(*reinterpret_cast< double(*)>(_a[24])),(*reinterpret_cast< int(*)>(_a[25])),(*reinterpret_cast< double(*)>(_a[26])),(*reinterpret_cast< double(*)>(_a[27])),(*reinterpret_cast< int(*)>(_a[28])),(*reinterpret_cast< QString(*)>(_a[29])),(*reinterpret_cast< QDateTime(*)>(_a[30])),(*reinterpret_cast< QDateTime(*)>(_a[31])),(*reinterpret_cast< double(*)>(_a[32])),(*reinterpret_cast< int(*)>(_a[33])),(*reinterpret_cast< QString(*)>(_a[34])),(*reinterpret_cast< int(*)>(_a[35])),(*reinterpret_cast< QString(*)>(_a[36])),(*reinterpret_cast< QDateTime(*)>(_a[37])),(*reinterpret_cast< QString(*)>(_a[38])),(*reinterpret_cast< QDateTime(*)>(_a[39])),(*reinterpret_cast< QString(*)>(_a[40])),(*reinterpret_cast< QString(*)>(_a[41])),(*reinterpret_cast< int(*)>(_a[42])),(*reinterpret_cast< int(*)>(_a[43])),(*reinterpret_cast< int(*)>(_a[44])),(*reinterpret_cast< int(*)>(_a[45])),(*reinterpret_cast< double(*)>(_a[46])),(*reinterpret_cast< int(*)>(_a[47])),(*reinterpret_cast< int(*)>(_a[48])),(*reinterpret_cast< int(*)>(_a[49])),(*reinterpret_cast< int(*)>(_a[50])),(*reinterpret_cast< double(*)>(_a[51])),(*reinterpret_cast< int(*)>(_a[52])),(*reinterpret_cast< int(*)>(_a[53])),(*reinterpret_cast< int(*)>(_a[54])),(*reinterpret_cast< int(*)>(_a[55])),(*reinterpret_cast< int(*)>(_a[56])),(*reinterpret_cast< int(*)>(_a[57])),(*reinterpret_cast< int(*)>(_a[58])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 10: { bool _r = _t->createTrkTransaction((*reinterpret_cast< Transaction(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 11: { int _r = _t->getSmena();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 12: { bool _r = _t->createApiTransaction((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< QDateTime(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5])),(*reinterpret_cast< QString(*)>(_a[6])),(*reinterpret_cast< int(*)>(_a[7])),(*reinterpret_cast< QString(*)>(_a[8])),(*reinterpret_cast< int(*)>(_a[9])),(*reinterpret_cast< int(*)>(_a[10])),(*reinterpret_cast< int(*)>(_a[11])),(*reinterpret_cast< int(*)>(_a[12])),(*reinterpret_cast< QString(*)>(_a[13])),(*reinterpret_cast< QString(*)>(_a[14])),(*reinterpret_cast< QString(*)>(_a[15])),(*reinterpret_cast< QString(*)>(_a[16])),(*reinterpret_cast< double(*)>(_a[17])),(*reinterpret_cast< double(*)>(_a[18])),(*reinterpret_cast< double(*)>(_a[19])),(*reinterpret_cast< QDateTime(*)>(_a[20])),(*reinterpret_cast< int(*)>(_a[21])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 13: { bool _r = _t->updateApiTransactionLink((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 14: { ApiTransaction _r = _t->getApiTransaction((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< ApiTransaction*>(_a[0]) = std::move(_r); }  break;
        case 15: { bool _r = _t->updateApiTransactionState((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QDateTime(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 16: { bool _r = _t->finalUpdateApiTransactionState((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< double(*)>(_a[4])),(*reinterpret_cast< QDateTime(*)>(_a[5])),(*reinterpret_cast< QDateTime(*)>(_a[6])),(*reinterpret_cast< int(*)>(_a[7])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 17: { bool _r = _t->getPayOperationData((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< double(*)>(_a[4])),(*reinterpret_cast< QDateTime(*)>(_a[5])),(*reinterpret_cast< QDateTime(*)>(_a[6])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 18: { bool _r = _t->setTransactionClosed((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 19: { Transaction _r = _t->getTransaction((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< Transaction*>(_a[0]) = std::move(_r); }  break;
        case 20: { QList<ApiTransaction> _r = _t->getOpenedApiTransactions((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QList<ApiTransaction>*>(_a[0]) = std::move(_r); }  break;
        case 21: { bool _r = _t->updateYandexToken((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 22: { QString _r = _t->getCityMobileToken();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 23: { bool _r = _t->isApiTransactionExist((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 24: { bool _r = _t->isApiTransactionExist((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 25: { int _r = _t->getRealSideAddress((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 26: { bool _r = _t->openDB();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 27: { bool _r = _t->makeQuery((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< DataBaseControl::QueryType(*)>(_a[3])),(*reinterpret_cast< std::function<void(QSqlQuery&)>(*)>(_a[4])),(*reinterpret_cast< bool(*)>(_a[5])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 28: { bool _r = _t->makeQuery((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< DataBaseControl::QueryType(*)>(_a[3])),(*reinterpret_cast< std::function<void(QSqlQuery&)>(*)>(_a[4])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 29: { bool _r = _t->makeQuery((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< DataBaseControl::QueryType(*)>(_a[3])));
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
        if (_id < 30)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 30;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 30)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 30;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
