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
    QByteArrayData data[50];
    char stringdata0[701];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 9), // "getFuelID"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 10), // "aFuelIdApi"
QT_MOC_LITERAL(4, 33, 11), // "getFuelName"
QT_MOC_LITERAL(5, 45, 10), // "aFuelVCode"
QT_MOC_LITERAL(6, 56, 14), // "getFuelAPIName"
QT_MOC_LITERAL(7, 71, 9), // "moneyData"
QT_MOC_LITERAL(8, 81, 7), // "Partner"
QT_MOC_LITERAL(9, 89, 8), // "aPartner"
QT_MOC_LITERAL(10, 98, 8), // "aRequest"
QT_MOC_LITERAL(11, 107, 7), // "double&"
QT_MOC_LITERAL(12, 115, 20), // "aRequestTotalPriceDB"
QT_MOC_LITERAL(13, 136, 16), // "aRequestVolumeDB"
QT_MOC_LITERAL(14, 153, 19), // "aRequestUnitPriceDB"
QT_MOC_LITERAL(15, 173, 13), // "aMoneyTakenDB"
QT_MOC_LITERAL(16, 187, 4), // "int&"
QT_MOC_LITERAL(17, 192, 11), // "aFullTankDB"
QT_MOC_LITERAL(18, 204, 22), // "on_ButtonEnter_clicked"
QT_MOC_LITERAL(19, 227, 28), // "on_ButtonGetPassword_clicked"
QT_MOC_LITERAL(20, 256, 33), // "on_ButtonCancelCitymobile_cli..."
QT_MOC_LITERAL(21, 290, 29), // "on_ButtonCancelYandex_clicked"
QT_MOC_LITERAL(22, 320, 25), // "on_ButtonSettings_clicked"
QT_MOC_LITERAL(23, 346, 16), // "updateDataYandex"
QT_MOC_LITERAL(24, 363, 15), // "getOrdersYandex"
QT_MOC_LITERAL(25, 379, 20), // "updateDataCityMobile"
QT_MOC_LITERAL(26, 400, 19), // "getOrdersCityMobile"
QT_MOC_LITERAL(27, 420, 11), // "updatePrice"
QT_MOC_LITERAL(28, 432, 1), // "p"
QT_MOC_LITERAL(29, 434, 19), // "updateConfiguration"
QT_MOC_LITERAL(30, 454, 13), // "processOrders"
QT_MOC_LITERAL(31, 468, 6), // "orders"
QT_MOC_LITERAL(32, 475, 11), // "changeEvent"
QT_MOC_LITERAL(33, 487, 7), // "QEvent*"
QT_MOC_LITERAL(34, 495, 17), // "trayIconActivated"
QT_MOC_LITERAL(35, 513, 33), // "QSystemTrayIcon::ActivationRe..."
QT_MOC_LITERAL(36, 547, 6), // "reason"
QT_MOC_LITERAL(37, 554, 17), // "trayActionExecute"
QT_MOC_LITERAL(38, 572, 18), // "setTrayIconActions"
QT_MOC_LITERAL(39, 591, 12), // "showTrayIcon"
QT_MOC_LITERAL(40, 604, 16), // "authYandexResult"
QT_MOC_LITERAL(41, 621, 6), // "aToken"
QT_MOC_LITERAL(42, 628, 8), // "needAuth"
QT_MOC_LITERAL(43, 637, 12), // "requestToLog"
QT_MOC_LITERAL(44, 650, 3), // "api"
QT_MOC_LITERAL(45, 654, 4), // "type"
QT_MOC_LITERAL(46, 659, 7), // "request"
QT_MOC_LITERAL(47, 667, 4), // "post"
QT_MOC_LITERAL(48, 672, 4), // "code"
QT_MOC_LITERAL(49, 677, 23) // "yandexErrorNotification"

    },
    "MainWindow\0getFuelID\0\0aFuelIdApi\0"
    "getFuelName\0aFuelVCode\0getFuelAPIName\0"
    "moneyData\0Partner\0aPartner\0aRequest\0"
    "double&\0aRequestTotalPriceDB\0"
    "aRequestVolumeDB\0aRequestUnitPriceDB\0"
    "aMoneyTakenDB\0int&\0aFullTankDB\0"
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
    "needAuth\0requestToLog\0api\0type\0request\0"
    "post\0code\0yandexErrorNotification"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      25,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,  139,    2, 0x0a /* Public */,
       4,    1,  142,    2, 0x0a /* Public */,
       6,    1,  145,    2, 0x0a /* Public */,
       7,    7,  148,    2, 0x0a /* Public */,
      18,    0,  163,    2, 0x08 /* Private */,
      19,    0,  164,    2, 0x08 /* Private */,
      20,    0,  165,    2, 0x08 /* Private */,
      21,    0,  166,    2, 0x08 /* Private */,
      22,    0,  167,    2, 0x08 /* Private */,
      23,    0,  168,    2, 0x08 /* Private */,
      24,    0,  169,    2, 0x08 /* Private */,
      25,    0,  170,    2, 0x08 /* Private */,
      26,    0,  171,    2, 0x08 /* Private */,
      27,    1,  172,    2, 0x08 /* Private */,
      29,    1,  175,    2, 0x08 /* Private */,
      30,    2,  178,    2, 0x08 /* Private */,
      32,    1,  183,    2, 0x08 /* Private */,
      34,    1,  186,    2, 0x08 /* Private */,
      37,    0,  189,    2, 0x08 /* Private */,
      38,    0,  190,    2, 0x08 /* Private */,
      39,    0,  191,    2, 0x08 /* Private */,
      40,    1,  192,    2, 0x08 /* Private */,
      42,    0,  195,    2, 0x08 /* Private */,
      43,    5,  196,    2, 0x08 /* Private */,
      49,    0,  207,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Int, QMetaType::QString,    3,
    QMetaType::QString, QMetaType::Int,    5,
    QMetaType::QString, QMetaType::Int,    5,
    QMetaType::Void, 0x80000000 | 8, QMetaType::QJsonObject, 0x80000000 | 11, 0x80000000 | 11, 0x80000000 | 11, 0x80000000 | 11, 0x80000000 | 16,    9,   10,   12,   13,   14,   15,   17,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8,   28,
    QMetaType::Void, 0x80000000 | 8,   28,
    QMetaType::Void, 0x80000000 | 8, QMetaType::QJsonDocument,    9,   31,
    QMetaType::Void, 0x80000000 | 33,    2,
    QMetaType::Void, 0x80000000 | 35,   36,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   41,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::Int,   44,   45,   46,   47,   48,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { int _r = _t->getFuelID((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 1: { QString _r = _t->getFuelName((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 2: { QString _r = _t->getFuelAPIName((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 3: _t->moneyData((*reinterpret_cast< Partner(*)>(_a[1])),(*reinterpret_cast< QJsonObject(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< double(*)>(_a[4])),(*reinterpret_cast< double(*)>(_a[5])),(*reinterpret_cast< double(*)>(_a[6])),(*reinterpret_cast< int(*)>(_a[7]))); break;
        case 4: _t->on_ButtonEnter_clicked(); break;
        case 5: _t->on_ButtonGetPassword_clicked(); break;
        case 6: _t->on_ButtonCancelCitymobile_clicked(); break;
        case 7: _t->on_ButtonCancelYandex_clicked(); break;
        case 8: _t->on_ButtonSettings_clicked(); break;
        case 9: _t->updateDataYandex(); break;
        case 10: _t->getOrdersYandex(); break;
        case 11: _t->updateDataCityMobile(); break;
        case 12: _t->getOrdersCityMobile(); break;
        case 13: _t->updatePrice((*reinterpret_cast< Partner(*)>(_a[1]))); break;
        case 14: _t->updateConfiguration((*reinterpret_cast< Partner(*)>(_a[1]))); break;
        case 15: _t->processOrders((*reinterpret_cast< Partner(*)>(_a[1])),(*reinterpret_cast< QJsonDocument(*)>(_a[2]))); break;
        case 16: _t->changeEvent((*reinterpret_cast< QEvent*(*)>(_a[1]))); break;
        case 17: _t->trayIconActivated((*reinterpret_cast< QSystemTrayIcon::ActivationReason(*)>(_a[1]))); break;
        case 18: _t->trayActionExecute(); break;
        case 19: _t->setTrayIconActions(); break;
        case 20: _t->showTrayIcon(); break;
        case 21: _t->authYandexResult((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 22: _t->needAuth(); break;
        case 23: _t->requestToLog((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5]))); break;
        case 24: _t->yandexErrorNotification(); break;
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
        if (_id < 25)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 25;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 25)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 25;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
