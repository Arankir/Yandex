/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../Partners/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[80];
    char stringdata0[1125];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 15), // "FuelApiToFuelId"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 10), // "aFuelIdApi"
QT_MOC_LITERAL(4, 39, 11), // "getFuelName"
QT_MOC_LITERAL(5, 51, 10), // "aFuelVCode"
QT_MOC_LITERAL(6, 62, 15), // "FuelIdToFuelApi"
QT_MOC_LITERAL(7, 78, 9), // "moneyData"
QT_MOC_LITERAL(8, 88, 7), // "Partner"
QT_MOC_LITERAL(9, 96, 8), // "aPartner"
QT_MOC_LITERAL(10, 105, 5), // "Order"
QT_MOC_LITERAL(11, 111, 6), // "aOrder"
QT_MOC_LITERAL(12, 118, 7), // "double&"
QT_MOC_LITERAL(13, 126, 20), // "aRequestTotalPriceDB"
QT_MOC_LITERAL(14, 147, 16), // "aRequestVolumeDB"
QT_MOC_LITERAL(15, 164, 19), // "aRequestUnitPriceDB"
QT_MOC_LITERAL(16, 184, 13), // "aMoneyTakenDB"
QT_MOC_LITERAL(17, 198, 4), // "int&"
QT_MOC_LITERAL(18, 203, 11), // "aFullTankDB"
QT_MOC_LITERAL(19, 215, 17), // "getNozzleFuelCode"
QT_MOC_LITERAL(20, 233, 8), // "AdastTrk"
QT_MOC_LITERAL(21, 242, 4), // "aTrk"
QT_MOC_LITERAL(22, 247, 7), // "aFuelId"
QT_MOC_LITERAL(23, 255, 7), // "aNozzle"
QT_MOC_LITERAL(24, 263, 9), // "aFuelCode"
QT_MOC_LITERAL(25, 273, 22), // "createEmptyTransaction"
QT_MOC_LITERAL(26, 296, 11), // "Transaction"
QT_MOC_LITERAL(27, 308, 17), // "createTransaction"
QT_MOC_LITERAL(28, 326, 4), // "Agzs"
QT_MOC_LITERAL(29, 331, 11), // "currentAgzs"
QT_MOC_LITERAL(30, 343, 5), // "order"
QT_MOC_LITERAL(31, 349, 10), // "sideAdress"
QT_MOC_LITERAL(32, 360, 3), // "now"
QT_MOC_LITERAL(33, 364, 11), // "JsonToOrder"
QT_MOC_LITERAL(34, 376, 10), // "sendLiters"
QT_MOC_LITERAL(35, 387, 14), // "ApiTransaction"
QT_MOC_LITERAL(36, 402, 15), // "aApiTransaction"
QT_MOC_LITERAL(37, 418, 8), // "aOrderId"
QT_MOC_LITERAL(38, 427, 14), // "stringToStatus"
QT_MOC_LITERAL(39, 442, 11), // "OrderStatus"
QT_MOC_LITERAL(40, 454, 7), // "aStatus"
QT_MOC_LITERAL(41, 462, 18), // "processAcceptOrder"
QT_MOC_LITERAL(42, 481, 23), // "processWaitingRefueling"
QT_MOC_LITERAL(43, 505, 14), // "processFueling"
QT_MOC_LITERAL(44, 520, 13), // "processExpire"
QT_MOC_LITERAL(45, 534, 22), // "processStationCanceled"
QT_MOC_LITERAL(46, 557, 19), // "processUserCanceled"
QT_MOC_LITERAL(47, 577, 16), // "processCompleted"
QT_MOC_LITERAL(48, 594, 14), // "processUnknown"
QT_MOC_LITERAL(49, 609, 12), // "processClose"
QT_MOC_LITERAL(50, 622, 12), // "exitPassword"
QT_MOC_LITERAL(51, 635, 22), // "on_ButtonEnter_clicked"
QT_MOC_LITERAL(52, 658, 28), // "on_ButtonGetPassword_clicked"
QT_MOC_LITERAL(53, 687, 33), // "on_ButtonCancelCitymobile_cli..."
QT_MOC_LITERAL(54, 721, 29), // "on_ButtonCancelYandex_clicked"
QT_MOC_LITERAL(55, 751, 25), // "on_ButtonSettings_clicked"
QT_MOC_LITERAL(56, 777, 16), // "updateDataYandex"
QT_MOC_LITERAL(57, 794, 15), // "getOrdersYandex"
QT_MOC_LITERAL(58, 810, 20), // "updateDataCityMobile"
QT_MOC_LITERAL(59, 831, 19), // "getOrdersCityMobile"
QT_MOC_LITERAL(60, 851, 11), // "updatePrice"
QT_MOC_LITERAL(61, 863, 1), // "p"
QT_MOC_LITERAL(62, 865, 19), // "updateConfiguration"
QT_MOC_LITERAL(63, 885, 13), // "processOrders"
QT_MOC_LITERAL(64, 899, 6), // "orders"
QT_MOC_LITERAL(65, 906, 11), // "changeEvent"
QT_MOC_LITERAL(66, 918, 7), // "QEvent*"
QT_MOC_LITERAL(67, 926, 17), // "trayIconActivated"
QT_MOC_LITERAL(68, 944, 33), // "QSystemTrayIcon::ActivationRe..."
QT_MOC_LITERAL(69, 978, 6), // "reason"
QT_MOC_LITERAL(70, 985, 17), // "trayActionExecute"
QT_MOC_LITERAL(71, 1003, 18), // "setTrayIconActions"
QT_MOC_LITERAL(72, 1022, 12), // "showTrayIcon"
QT_MOC_LITERAL(73, 1035, 16), // "authYandexResult"
QT_MOC_LITERAL(74, 1052, 6), // "aToken"
QT_MOC_LITERAL(75, 1059, 8), // "needAuth"
QT_MOC_LITERAL(76, 1068, 23), // "yandexErrorNotification"
QT_MOC_LITERAL(77, 1092, 13), // "errorToString"
QT_MOC_LITERAL(78, 1106, 11), // "ErrorsOrder"
QT_MOC_LITERAL(79, 1118, 6) // "aError"

    },
    "MainWindow\0FuelApiToFuelId\0\0aFuelIdApi\0"
    "getFuelName\0aFuelVCode\0FuelIdToFuelApi\0"
    "moneyData\0Partner\0aPartner\0Order\0"
    "aOrder\0double&\0aRequestTotalPriceDB\0"
    "aRequestVolumeDB\0aRequestUnitPriceDB\0"
    "aMoneyTakenDB\0int&\0aFullTankDB\0"
    "getNozzleFuelCode\0AdastTrk\0aTrk\0aFuelId\0"
    "aNozzle\0aFuelCode\0createEmptyTransaction\0"
    "Transaction\0createTransaction\0Agzs\0"
    "currentAgzs\0order\0sideAdress\0now\0"
    "JsonToOrder\0sendLiters\0ApiTransaction\0"
    "aApiTransaction\0aOrderId\0stringToStatus\0"
    "OrderStatus\0aStatus\0processAcceptOrder\0"
    "processWaitingRefueling\0processFueling\0"
    "processExpire\0processStationCanceled\0"
    "processUserCanceled\0processCompleted\0"
    "processUnknown\0processClose\0exitPassword\0"
    "on_ButtonEnter_clicked\0"
    "on_ButtonGetPassword_clicked\0"
    "on_ButtonCancelCitymobile_clicked\0"
    "on_ButtonCancelYandex_clicked\0"
    "on_ButtonSettings_clicked\0updateDataYandex\0"
    "getOrdersYandex\0updateDataCityMobile\0"
    "getOrdersCityMobile\0updatePrice\0p\0"
    "updateConfiguration\0processOrders\0"
    "orders\0changeEvent\0QEvent*\0trayIconActivated\0"
    "QSystemTrayIcon::ActivationReason\0"
    "reason\0trayActionExecute\0setTrayIconActions\0"
    "showTrayIcon\0authYandexResult\0aToken\0"
    "needAuth\0yandexErrorNotification\0"
    "errorToString\0ErrorsOrder\0aError"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      41,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,  219,    2, 0x0a /* Public */,
       4,    1,  222,    2, 0x0a /* Public */,
       6,    1,  225,    2, 0x0a /* Public */,
       7,    7,  228,    2, 0x0a /* Public */,
      19,    4,  243,    2, 0x0a /* Public */,
      25,    0,  252,    2, 0x0a /* Public */,
      27,    5,  253,    2, 0x0a /* Public */,
      33,    2,  264,    2, 0x0a /* Public */,
      34,    3,  269,    2, 0x0a /* Public */,
      38,    1,  276,    2, 0x0a /* Public */,
      41,    2,  279,    2, 0x0a /* Public */,
      42,    2,  284,    2, 0x0a /* Public */,
      43,    2,  289,    2, 0x0a /* Public */,
      44,    2,  294,    2, 0x0a /* Public */,
      45,    2,  299,    2, 0x0a /* Public */,
      46,    2,  304,    2, 0x0a /* Public */,
      47,    2,  309,    2, 0x0a /* Public */,
      48,    2,  314,    2, 0x0a /* Public */,
      49,    1,  319,    2, 0x0a /* Public */,
      50,    0,  322,    2, 0x0a /* Public */,
      51,    0,  323,    2, 0x08 /* Private */,
      52,    0,  324,    2, 0x08 /* Private */,
      53,    0,  325,    2, 0x08 /* Private */,
      54,    0,  326,    2, 0x08 /* Private */,
      55,    0,  327,    2, 0x08 /* Private */,
      56,    0,  328,    2, 0x08 /* Private */,
      57,    0,  329,    2, 0x08 /* Private */,
      58,    0,  330,    2, 0x08 /* Private */,
      59,    0,  331,    2, 0x08 /* Private */,
      60,    1,  332,    2, 0x08 /* Private */,
      62,    1,  335,    2, 0x08 /* Private */,
      63,    2,  338,    2, 0x08 /* Private */,
      65,    1,  343,    2, 0x08 /* Private */,
      67,    1,  346,    2, 0x08 /* Private */,
      70,    0,  349,    2, 0x08 /* Private */,
      71,    0,  350,    2, 0x08 /* Private */,
      72,    0,  351,    2, 0x08 /* Private */,
      73,    1,  352,    2, 0x08 /* Private */,
      75,    0,  355,    2, 0x08 /* Private */,
      76,    0,  356,    2, 0x08 /* Private */,
      77,    1,  357,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Int, QMetaType::QString,    3,
    QMetaType::QString, QMetaType::Int,    5,
    QMetaType::QString, QMetaType::Int,    5,
    QMetaType::Void, 0x80000000 | 8, 0x80000000 | 10, 0x80000000 | 12, 0x80000000 | 12, 0x80000000 | 12, 0x80000000 | 12, 0x80000000 | 17,    9,   11,   13,   14,   15,   16,   18,
    QMetaType::Void, 0x80000000 | 20, QMetaType::QString, 0x80000000 | 17, 0x80000000 | 17,   21,   22,   23,   24,
    0x80000000 | 26,
    QMetaType::Int, 0x80000000 | 28, 0x80000000 | 10, 0x80000000 | 8, QMetaType::Int, QMetaType::QDateTime,   29,   30,    9,   31,   32,
    0x80000000 | 10, 0x80000000 | 8, QMetaType::QJsonValue,    9,   11,
    QMetaType::Void, 0x80000000 | 8, 0x80000000 | 35, QMetaType::QString,    9,   36,   37,
    0x80000000 | 39, QMetaType::QString,   40,
    QMetaType::Bool, 0x80000000 | 10, 0x80000000 | 8,   11,    9,
    QMetaType::Bool, 0x80000000 | 10, 0x80000000 | 8,   11,    9,
    QMetaType::Bool, 0x80000000 | 10, 0x80000000 | 8,   11,    9,
    QMetaType::Bool, 0x80000000 | 10, 0x80000000 | 8,   11,    9,
    QMetaType::Bool, 0x80000000 | 10, 0x80000000 | 8,   11,    9,
    QMetaType::Bool, 0x80000000 | 10, 0x80000000 | 8,   11,    9,
    QMetaType::Bool, 0x80000000 | 10, 0x80000000 | 8,   11,    9,
    QMetaType::Bool, 0x80000000 | 10, 0x80000000 | 8,   11,    9,
    QMetaType::Bool, 0x80000000 | 35,   36,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8,   61,
    QMetaType::Void, 0x80000000 | 8,   61,
    QMetaType::Void, 0x80000000 | 8, QMetaType::QJsonDocument,    9,   64,
    QMetaType::Void, 0x80000000 | 66,    2,
    QMetaType::Void, 0x80000000 | 68,   69,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   74,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::QString, 0x80000000 | 78,   79,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { int _r = _t->FuelApiToFuelId((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 1: { QString _r = _t->getFuelName((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 2: { QString _r = _t->FuelIdToFuelApi((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 3: _t->moneyData((*reinterpret_cast< Partner(*)>(_a[1])),(*reinterpret_cast< Order(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< double(*)>(_a[4])),(*reinterpret_cast< double(*)>(_a[5])),(*reinterpret_cast< double(*)>(_a[6])),(*reinterpret_cast< int(*)>(_a[7]))); break;
        case 4: _t->getNozzleFuelCode((*reinterpret_cast< AdastTrk(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 5: { Transaction _r = _t->createEmptyTransaction();
            if (_a[0]) *reinterpret_cast< Transaction*>(_a[0]) = std::move(_r); }  break;
        case 6: { int _r = _t->createTransaction((*reinterpret_cast< Agzs(*)>(_a[1])),(*reinterpret_cast< Order(*)>(_a[2])),(*reinterpret_cast< Partner(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< QDateTime(*)>(_a[5])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 7: { Order _r = _t->JsonToOrder((*reinterpret_cast< Partner(*)>(_a[1])),(*reinterpret_cast< QJsonValue(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< Order*>(_a[0]) = std::move(_r); }  break;
        case 8: _t->sendLiters((*reinterpret_cast< Partner(*)>(_a[1])),(*reinterpret_cast< ApiTransaction(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 9: { OrderStatus _r = _t->stringToStatus((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< OrderStatus*>(_a[0]) = std::move(_r); }  break;
        case 10: { bool _r = _t->processAcceptOrder((*reinterpret_cast< Order(*)>(_a[1])),(*reinterpret_cast< Partner(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 11: { bool _r = _t->processWaitingRefueling((*reinterpret_cast< Order(*)>(_a[1])),(*reinterpret_cast< Partner(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 12: { bool _r = _t->processFueling((*reinterpret_cast< Order(*)>(_a[1])),(*reinterpret_cast< Partner(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 13: { bool _r = _t->processExpire((*reinterpret_cast< Order(*)>(_a[1])),(*reinterpret_cast< Partner(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 14: { bool _r = _t->processStationCanceled((*reinterpret_cast< Order(*)>(_a[1])),(*reinterpret_cast< Partner(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 15: { bool _r = _t->processUserCanceled((*reinterpret_cast< Order(*)>(_a[1])),(*reinterpret_cast< Partner(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 16: { bool _r = _t->processCompleted((*reinterpret_cast< Order(*)>(_a[1])),(*reinterpret_cast< Partner(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 17: { bool _r = _t->processUnknown((*reinterpret_cast< Order(*)>(_a[1])),(*reinterpret_cast< Partner(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 18: { bool _r = _t->processClose((*reinterpret_cast< ApiTransaction(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 19: _t->exitPassword(); break;
        case 20: _t->on_ButtonEnter_clicked(); break;
        case 21: _t->on_ButtonGetPassword_clicked(); break;
        case 22: _t->on_ButtonCancelCitymobile_clicked(); break;
        case 23: _t->on_ButtonCancelYandex_clicked(); break;
        case 24: _t->on_ButtonSettings_clicked(); break;
        case 25: _t->updateDataYandex(); break;
        case 26: _t->getOrdersYandex(); break;
        case 27: _t->updateDataCityMobile(); break;
        case 28: _t->getOrdersCityMobile(); break;
        case 29: _t->updatePrice((*reinterpret_cast< Partner(*)>(_a[1]))); break;
        case 30: _t->updateConfiguration((*reinterpret_cast< Partner(*)>(_a[1]))); break;
        case 31: _t->processOrders((*reinterpret_cast< Partner(*)>(_a[1])),(*reinterpret_cast< QJsonDocument(*)>(_a[2]))); break;
        case 32: _t->changeEvent((*reinterpret_cast< QEvent*(*)>(_a[1]))); break;
        case 33: _t->trayIconActivated((*reinterpret_cast< QSystemTrayIcon::ActivationReason(*)>(_a[1]))); break;
        case 34: _t->trayActionExecute(); break;
        case 35: _t->setTrayIconActions(); break;
        case 36: _t->showTrayIcon(); break;
        case 37: _t->authYandexResult((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 38: _t->needAuth(); break;
        case 39: _t->yandexErrorNotification(); break;
        case 40: { QString _r = _t->errorToString((*reinterpret_cast< ErrorsOrder(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 41)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 41;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 41)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 41;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
