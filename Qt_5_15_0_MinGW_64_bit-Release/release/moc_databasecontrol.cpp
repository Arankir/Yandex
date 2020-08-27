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
    QByteArrayData data[131];
    char stringdata0[1540];
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
QT_MOC_LITERAL(7, 72, 35), // "QVector<QPair<int,QVector<int..."
QT_MOC_LITERAL(8, 108, 5), // "fuels"
QT_MOC_LITERAL(9, 114, 15), // "getCashBoxIndex"
QT_MOC_LITERAL(10, 130, 8), // "iPartner"
QT_MOC_LITERAL(11, 139, 9), // "getPrices"
QT_MOC_LITERAL(12, 149, 5), // "Price"
QT_MOC_LITERAL(13, 155, 11), // "getAgzsData"
QT_MOC_LITERAL(14, 167, 4), // "Agzs"
QT_MOC_LITERAL(15, 172, 15), // "getAgzsAdastTrk"
QT_MOC_LITERAL(16, 188, 8), // "AdastTrk"
QT_MOC_LITERAL(17, 197, 10), // "sideAdress"
QT_MOC_LITERAL(18, 208, 20), // "updateApiTransaction"
QT_MOC_LITERAL(19, 229, 10), // "localState"
QT_MOC_LITERAL(20, 240, 4), // "date"
QT_MOC_LITERAL(21, 245, 5), // "vCode"
QT_MOC_LITERAL(22, 251, 12), // "getLastVCode"
QT_MOC_LITERAL(23, 264, 3), // "key"
QT_MOC_LITERAL(24, 268, 6), // "update"
QT_MOC_LITERAL(25, 275, 10), // "checkError"
QT_MOC_LITERAL(26, 286, 9), // "aColumnID"
QT_MOC_LITERAL(27, 296, 7), // "aFuelID"
QT_MOC_LITERAL(28, 304, 8), // "aiFuelID"
QT_MOC_LITERAL(29, 313, 10), // "aPriceFuel"
QT_MOC_LITERAL(30, 324, 9), // "aIPartner"
QT_MOC_LITERAL(31, 334, 20), // "createTrkTransaction"
QT_MOC_LITERAL(32, 355, 9), // "aAgzsName"
QT_MOC_LITERAL(33, 365, 11), // "aLocalVCode"
QT_MOC_LITERAL(34, 377, 8), // "aTrkType"
QT_MOC_LITERAL(35, 386, 11), // "aDeviceName"
QT_MOC_LITERAL(36, 398, 7), // "aSerial"
QT_MOC_LITERAL(37, 406, 9), // "aFuelName"
QT_MOC_LITERAL(38, 416, 14), // "aFuelShortName"
QT_MOC_LITERAL(39, 431, 5), // "aSide"
QT_MOC_LITERAL(40, 437, 11), // "aSideAdress"
QT_MOC_LITERAL(41, 449, 7), // "aNozzle"
QT_MOC_LITERAL(42, 457, 12), // "aTrkFuelCode"
QT_MOC_LITERAL(43, 470, 9), // "aTransNum"
QT_MOC_LITERAL(44, 480, 14), // "aTrkTotalPrice"
QT_MOC_LITERAL(45, 495, 10), // "aTrkVolume"
QT_MOC_LITERAL(46, 506, 13), // "aTrkUnitPrice"
QT_MOC_LITERAL(47, 520, 18), // "aRequestTotalPrice"
QT_MOC_LITERAL(48, 539, 14), // "aRequestVolume"
QT_MOC_LITERAL(49, 554, 17), // "aRequestUnitPrice"
QT_MOC_LITERAL(50, 572, 13), // "aRequestField"
QT_MOC_LITERAL(51, 586, 6), // "aState"
QT_MOC_LITERAL(52, 593, 7), // "aIState"
QT_MOC_LITERAL(53, 601, 13), // "aTrkTransType"
QT_MOC_LITERAL(54, 615, 18), // "aLitersCountBefore"
QT_MOC_LITERAL(55, 634, 17), // "aMoneyCountBefore"
QT_MOC_LITERAL(56, 652, 17), // "aTransCountBefore"
QT_MOC_LITERAL(57, 670, 17), // "aLitersCountAfter"
QT_MOC_LITERAL(58, 688, 16), // "aMoneyCountAfter"
QT_MOC_LITERAL(59, 705, 16), // "aTransCountAfter"
QT_MOC_LITERAL(60, 722, 7), // "aResult"
QT_MOC_LITERAL(61, 730, 9), // "aDateOpen"
QT_MOC_LITERAL(62, 740, 10), // "aDateClose"
QT_MOC_LITERAL(63, 751, 12), // "aTemperature"
QT_MOC_LITERAL(64, 764, 18), // "aPayOperationVCode"
QT_MOC_LITERAL(65, 783, 7), // "aPayWay"
QT_MOC_LITERAL(66, 791, 11), // "aPrePostPay"
QT_MOC_LITERAL(67, 803, 6), // "aWUser"
QT_MOC_LITERAL(68, 810, 6), // "aWDate"
QT_MOC_LITERAL(69, 817, 6), // "aCUser"
QT_MOC_LITERAL(70, 824, 6), // "aCDate"
QT_MOC_LITERAL(71, 831, 6), // "aCHost"
QT_MOC_LITERAL(72, 838, 6), // "aWHost"
QT_MOC_LITERAL(73, 845, 6), // "aVCode"
QT_MOC_LITERAL(74, 852, 19), // "aAddedForTransVCode"
QT_MOC_LITERAL(75, 872, 20), // "aAditionalTransVCode"
QT_MOC_LITERAL(76, 893, 7), // "aActive"
QT_MOC_LITERAL(77, 901, 5), // "aMass"
QT_MOC_LITERAL(78, 907, 6), // "aSmena"
QT_MOC_LITERAL(79, 914, 9), // "aTrkVcode"
QT_MOC_LITERAL(80, 924, 14), // "aCapacityVcode"
QT_MOC_LITERAL(81, 939, 10), // "aPumpPlace"
QT_MOC_LITERAL(82, 950, 11), // "aMoneyTaken"
QT_MOC_LITERAL(83, 962, 8), // "aIPayWay"
QT_MOC_LITERAL(84, 971, 10), // "aAutoCheck"
QT_MOC_LITERAL(85, 982, 7), // "aClosed"
QT_MOC_LITERAL(86, 990, 9), // "aFullTank"
QT_MOC_LITERAL(87, 1000, 5), // "aAgzs"
QT_MOC_LITERAL(88, 1006, 10), // "aFuelVCode"
QT_MOC_LITERAL(89, 1017, 7), // "aPropan"
QT_MOC_LITERAL(90, 1025, 11), // "Transaction"
QT_MOC_LITERAL(91, 1037, 11), // "transaction"
QT_MOC_LITERAL(92, 1049, 8), // "getSmena"
QT_MOC_LITERAL(93, 1058, 20), // "createApiTransaction"
QT_MOC_LITERAL(94, 1079, 6), // "aApiId"
QT_MOC_LITERAL(95, 1086, 21), // "aApiStationExtendedId"
QT_MOC_LITERAL(96, 1108, 12), // "aApiColumnId"
QT_MOC_LITERAL(97, 1121, 10), // "aApiFuelId"
QT_MOC_LITERAL(98, 1132, 13), // "aApiPriceFuel"
QT_MOC_LITERAL(99, 1146, 9), // "aApiLitre"
QT_MOC_LITERAL(100, 1156, 7), // "aApiSum"
QT_MOC_LITERAL(101, 1164, 10), // "aApiStatus"
QT_MOC_LITERAL(102, 1175, 14), // "aApiContractId"
QT_MOC_LITERAL(103, 1190, 6), // "aAgent"
QT_MOC_LITERAL(104, 1197, 11), // "aLocalState"
QT_MOC_LITERAL(105, 1209, 6), // "aPrice"
QT_MOC_LITERAL(106, 1216, 6), // "aLitre"
QT_MOC_LITERAL(107, 1223, 4), // "aSum"
QT_MOC_LITERAL(108, 1228, 5), // "aLink"
QT_MOC_LITERAL(109, 1234, 22), // "getApiTransactionState"
QT_MOC_LITERAL(110, 1257, 14), // "ApiTransaction"
QT_MOC_LITERAL(111, 1272, 2), // "id"
QT_MOC_LITERAL(112, 1275, 25), // "updateApiTransactionState"
QT_MOC_LITERAL(113, 1301, 9), // "dateClose"
QT_MOC_LITERAL(114, 1311, 30), // "finalUpdateApiTransactionState"
QT_MOC_LITERAL(115, 1342, 5), // "price"
QT_MOC_LITERAL(116, 1348, 6), // "volume"
QT_MOC_LITERAL(117, 1355, 6), // "amount"
QT_MOC_LITERAL(118, 1362, 8), // "dateOpen"
QT_MOC_LITERAL(119, 1371, 21), // "getPayOperationLiters"
QT_MOC_LITERAL(120, 1393, 4), // "link"
QT_MOC_LITERAL(121, 1398, 7), // "double&"
QT_MOC_LITERAL(122, 1406, 20), // "setTransactionClosed"
QT_MOC_LITERAL(123, 1427, 6), // "closed"
QT_MOC_LITERAL(124, 1434, 18), // "getTransactionData"
QT_MOC_LITERAL(125, 1453, 14), // "setYandexToken"
QT_MOC_LITERAL(126, 1468, 6), // "aToken"
QT_MOC_LITERAL(127, 1475, 18), // "isTransactionExist"
QT_MOC_LITERAL(128, 1494, 18), // "getRealSideAddress"
QT_MOC_LITERAL(129, 1513, 19), // "aPartnerSideAddress"
QT_MOC_LITERAL(130, 1533, 6) // "openDB"

    },
    "DataBaseControl\0getCurrentAgzs\0\0"
    "getFuelNames\0FuelNames\0aFuelId\0getFuels\0"
    "QVector<QPair<int,QVector<int> > >&\0"
    "fuels\0getCashBoxIndex\0iPartner\0getPrices\0"
    "Price\0getAgzsData\0Agzs\0getAgzsAdastTrk\0"
    "AdastTrk\0sideAdress\0updateApiTransaction\0"
    "localState\0date\0vCode\0getLastVCode\0"
    "key\0update\0checkError\0aColumnID\0aFuelID\0"
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
    "aFuelVCode\0aPropan\0Transaction\0"
    "transaction\0getSmena\0createApiTransaction\0"
    "aApiId\0aApiStationExtendedId\0aApiColumnId\0"
    "aApiFuelId\0aApiPriceFuel\0aApiLitre\0"
    "aApiSum\0aApiStatus\0aApiContractId\0"
    "aAgent\0aLocalState\0aPrice\0aLitre\0aSum\0"
    "aLink\0getApiTransactionState\0"
    "ApiTransaction\0id\0updateApiTransactionState\0"
    "dateClose\0finalUpdateApiTransactionState\0"
    "price\0volume\0amount\0dateOpen\0"
    "getPayOperationLiters\0link\0double&\0"
    "setTransactionClosed\0closed\0"
    "getTransactionData\0setYandexToken\0"
    "aToken\0isTransactionExist\0getRealSideAddress\0"
    "aPartnerSideAddress\0openDB"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DataBaseControl[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      24,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,  134,    2, 0x0a /* Public */,
       3,    1,  135,    2, 0x0a /* Public */,
       6,    1,  138,    2, 0x0a /* Public */,
       9,    1,  141,    2, 0x0a /* Public */,
      11,    1,  144,    2, 0x0a /* Public */,
      13,    0,  147,    2, 0x0a /* Public */,
      15,    1,  148,    2, 0x0a /* Public */,
      18,    3,  151,    2, 0x0a /* Public */,
      22,    2,  158,    2, 0x0a /* Public */,
      25,    5,  163,    2, 0x0a /* Public */,
      31,   58,  174,    2, 0x0a /* Public */,
      31,    1,  291,    2, 0x0a /* Public */,
      92,    0,  294,    2, 0x0a /* Public */,
      93,   21,  295,    2, 0x0a /* Public */,
     109,    1,  338,    2, 0x0a /* Public */,
     112,    3,  341,    2, 0x0a /* Public */,
     114,    7,  348,    2, 0x0a /* Public */,
     119,    4,  363,    2, 0x0a /* Public */,
     122,    2,  372,    2, 0x0a /* Public */,
     124,    1,  377,    2, 0x0a /* Public */,
     125,    1,  380,    2, 0x0a /* Public */,
     127,    1,  383,    2, 0x0a /* Public */,
     128,    2,  386,    2, 0x0a /* Public */,
     130,    0,  391,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Int,
    0x80000000 | 4, QMetaType::Int,    5,
    QMetaType::Bool, 0x80000000 | 7,    8,
    QMetaType::Int, QMetaType::QString,   10,
    0x80000000 | 12, QMetaType::QString,   10,
    0x80000000 | 14,
    0x80000000 | 16, QMetaType::Int,   17,
    QMetaType::Bool, QMetaType::Int, QMetaType::QDateTime, QMetaType::Int,   19,   20,   21,
    QMetaType::Int, QMetaType::QString, QMetaType::Bool,   23,   24,
    QMetaType::Int, QMetaType::QString, QMetaType::QString, QMetaType::Int, QMetaType::QString, QMetaType::Int,   26,   27,   28,   29,   30,
    QMetaType::Bool, QMetaType::QString, QMetaType::Int, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::QString, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::QString, QMetaType::QString, QMetaType::Int, QMetaType::QString, QMetaType::Double, QMetaType::Double, QMetaType::Int, QMetaType::Double, QMetaType::Double, QMetaType::Int, QMetaType::QString, QMetaType::QDateTime, QMetaType::QDateTime, QMetaType::Double, QMetaType::Int, QMetaType::QString, QMetaType::Int, QMetaType::QString, QMetaType::QDateTime, QMetaType::QString, QMetaType::QDateTime, QMetaType::QString, QMetaType::QString, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Double, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Double, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,   32,   33,   34,   35,   36,   37,   38,   39,   40,   41,   42,   43,   44,   45,   46,   47,   48,   49,   50,   51,   52,   53,   54,   55,   56,   57,   58,   59,   60,   61,   62,   63,   64,   65,   66,   67,   68,   69,   70,   71,   72,   73,   74,   75,   76,   77,   78,   79,   80,   81,   82,   83,   84,   85,   86,   87,   88,   89,
    QMetaType::Bool, 0x80000000 | 90,   91,
    QMetaType::Int,
    QMetaType::Bool, QMetaType::QString, QMetaType::Int, QMetaType::QDateTime, QMetaType::Int, QMetaType::QString, QMetaType::QString, QMetaType::Int, QMetaType::QString, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::QDateTime, QMetaType::Int,   32,   87,   70,   73,   94,   95,   96,   97,    5,   98,   99,  100,  101,  102,  103,  104,  105,  106,  107,   61,  108,
    0x80000000 | 110, QMetaType::QString,  111,
    QMetaType::Bool, QMetaType::QString, QMetaType::QDateTime, QMetaType::Int,   19,  113,   21,
    QMetaType::Bool, QMetaType::QString, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::QDateTime, QMetaType::QDateTime, QMetaType::Int,   19,  115,  116,  117,  118,  113,   21,
    QMetaType::Bool, QMetaType::Int, 0x80000000 | 121, 0x80000000 | 121, 0x80000000 | 121,  120,  117,  116,  115,
    QMetaType::Bool, QMetaType::QString, QMetaType::Int,  111,  123,
    0x80000000 | 90, QMetaType::Int,   73,
    QMetaType::Bool, QMetaType::QString,  126,
    QMetaType::Bool, QMetaType::QString,   94,
    QMetaType::Int, QMetaType::Int, QMetaType::Int,   87,  129,
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
        case 2: { bool _r = _t->getFuels((*reinterpret_cast< QVector<QPair<int,QVector<int> > >(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
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
        case 9: { int _r = _t->checkError((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 10: { bool _r = _t->createTrkTransaction((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5])),(*reinterpret_cast< QString(*)>(_a[6])),(*reinterpret_cast< QString(*)>(_a[7])),(*reinterpret_cast< QString(*)>(_a[8])),(*reinterpret_cast< int(*)>(_a[9])),(*reinterpret_cast< int(*)>(_a[10])),(*reinterpret_cast< int(*)>(_a[11])),(*reinterpret_cast< QString(*)>(_a[12])),(*reinterpret_cast< double(*)>(_a[13])),(*reinterpret_cast< double(*)>(_a[14])),(*reinterpret_cast< double(*)>(_a[15])),(*reinterpret_cast< double(*)>(_a[16])),(*reinterpret_cast< double(*)>(_a[17])),(*reinterpret_cast< double(*)>(_a[18])),(*reinterpret_cast< QString(*)>(_a[19])),(*reinterpret_cast< QString(*)>(_a[20])),(*reinterpret_cast< int(*)>(_a[21])),(*reinterpret_cast< QString(*)>(_a[22])),(*reinterpret_cast< double(*)>(_a[23])),(*reinterpret_cast< double(*)>(_a[24])),(*reinterpret_cast< int(*)>(_a[25])),(*reinterpret_cast< double(*)>(_a[26])),(*reinterpret_cast< double(*)>(_a[27])),(*reinterpret_cast< int(*)>(_a[28])),(*reinterpret_cast< QString(*)>(_a[29])),(*reinterpret_cast< QDateTime(*)>(_a[30])),(*reinterpret_cast< QDateTime(*)>(_a[31])),(*reinterpret_cast< double(*)>(_a[32])),(*reinterpret_cast< int(*)>(_a[33])),(*reinterpret_cast< QString(*)>(_a[34])),(*reinterpret_cast< int(*)>(_a[35])),(*reinterpret_cast< QString(*)>(_a[36])),(*reinterpret_cast< QDateTime(*)>(_a[37])),(*reinterpret_cast< QString(*)>(_a[38])),(*reinterpret_cast< QDateTime(*)>(_a[39])),(*reinterpret_cast< QString(*)>(_a[40])),(*reinterpret_cast< QString(*)>(_a[41])),(*reinterpret_cast< int(*)>(_a[42])),(*reinterpret_cast< int(*)>(_a[43])),(*reinterpret_cast< int(*)>(_a[44])),(*reinterpret_cast< int(*)>(_a[45])),(*reinterpret_cast< double(*)>(_a[46])),(*reinterpret_cast< int(*)>(_a[47])),(*reinterpret_cast< int(*)>(_a[48])),(*reinterpret_cast< int(*)>(_a[49])),(*reinterpret_cast< int(*)>(_a[50])),(*reinterpret_cast< double(*)>(_a[51])),(*reinterpret_cast< int(*)>(_a[52])),(*reinterpret_cast< int(*)>(_a[53])),(*reinterpret_cast< int(*)>(_a[54])),(*reinterpret_cast< int(*)>(_a[55])),(*reinterpret_cast< int(*)>(_a[56])),(*reinterpret_cast< int(*)>(_a[57])),(*reinterpret_cast< int(*)>(_a[58])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 11: { bool _r = _t->createTrkTransaction((*reinterpret_cast< Transaction(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 12: { int _r = _t->getSmena();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 13: { bool _r = _t->createApiTransaction((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< QDateTime(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5])),(*reinterpret_cast< QString(*)>(_a[6])),(*reinterpret_cast< int(*)>(_a[7])),(*reinterpret_cast< QString(*)>(_a[8])),(*reinterpret_cast< int(*)>(_a[9])),(*reinterpret_cast< int(*)>(_a[10])),(*reinterpret_cast< int(*)>(_a[11])),(*reinterpret_cast< int(*)>(_a[12])),(*reinterpret_cast< QString(*)>(_a[13])),(*reinterpret_cast< QString(*)>(_a[14])),(*reinterpret_cast< QString(*)>(_a[15])),(*reinterpret_cast< QString(*)>(_a[16])),(*reinterpret_cast< double(*)>(_a[17])),(*reinterpret_cast< double(*)>(_a[18])),(*reinterpret_cast< double(*)>(_a[19])),(*reinterpret_cast< QDateTime(*)>(_a[20])),(*reinterpret_cast< int(*)>(_a[21])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 14: { ApiTransaction _r = _t->getApiTransactionState((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< ApiTransaction*>(_a[0]) = std::move(_r); }  break;
        case 15: { bool _r = _t->updateApiTransactionState((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QDateTime(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 16: { bool _r = _t->finalUpdateApiTransactionState((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< double(*)>(_a[4])),(*reinterpret_cast< QDateTime(*)>(_a[5])),(*reinterpret_cast< QDateTime(*)>(_a[6])),(*reinterpret_cast< int(*)>(_a[7])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 17: { bool _r = _t->getPayOperationLiters((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< double(*)>(_a[4])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 18: { bool _r = _t->setTransactionClosed((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 19: { Transaction _r = _t->getTransactionData((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< Transaction*>(_a[0]) = std::move(_r); }  break;
        case 20: { bool _r = _t->setYandexToken((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 21: { bool _r = _t->isTransactionExist((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 22: { int _r = _t->getRealSideAddress((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 23: { bool _r = _t->openDB();
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
        if (_id < 24)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 24;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 24)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 24;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
