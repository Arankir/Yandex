/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
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
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[51];
    char stringdata0[772];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 17), // "createTransaction"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 4), // "Agzs"
QT_MOC_LITERAL(4, 35, 11), // "currentAgzs"
QT_MOC_LITERAL(5, 47, 5), // "Order"
QT_MOC_LITERAL(6, 53, 5), // "order"
QT_MOC_LITERAL(7, 59, 11), // "PartnerAPI*"
QT_MOC_LITERAL(8, 71, 8), // "aPartner"
QT_MOC_LITERAL(9, 80, 10), // "sideAdress"
QT_MOC_LITERAL(10, 91, 3), // "now"
QT_MOC_LITERAL(11, 95, 15), // "litersFromStart"
QT_MOC_LITERAL(12, 111, 14), // "ApiTransaction"
QT_MOC_LITERAL(13, 126, 15), // "aApiTransaction"
QT_MOC_LITERAL(14, 142, 18), // "processAcceptOrder"
QT_MOC_LITERAL(15, 161, 6), // "aOrder"
QT_MOC_LITERAL(16, 168, 23), // "processWaitingRefueling"
QT_MOC_LITERAL(17, 192, 14), // "processFueling"
QT_MOC_LITERAL(18, 207, 13), // "processExpire"
QT_MOC_LITERAL(19, 221, 22), // "processStationCanceled"
QT_MOC_LITERAL(20, 244, 19), // "processUserCanceled"
QT_MOC_LITERAL(21, 264, 16), // "processCompleted"
QT_MOC_LITERAL(22, 281, 14), // "processUnknown"
QT_MOC_LITERAL(23, 296, 12), // "processClose"
QT_MOC_LITERAL(24, 309, 12), // "exitPassword"
QT_MOC_LITERAL(25, 322, 13), // "checkSettings"
QT_MOC_LITERAL(26, 336, 22), // "on_ButtonEnter_clicked"
QT_MOC_LITERAL(27, 359, 28), // "on_ButtonGetPassword_clicked"
QT_MOC_LITERAL(28, 388, 33), // "on_ButtonCancelCitymobile_cli..."
QT_MOC_LITERAL(29, 422, 29), // "on_ButtonCancelYandex_clicked"
QT_MOC_LITERAL(30, 452, 25), // "on_ButtonSettings_clicked"
QT_MOC_LITERAL(31, 478, 11), // "updatePrice"
QT_MOC_LITERAL(32, 490, 19), // "updateConfiguration"
QT_MOC_LITERAL(33, 510, 13), // "processOrders"
QT_MOC_LITERAL(34, 524, 6), // "orders"
QT_MOC_LITERAL(35, 531, 11), // "changeEvent"
QT_MOC_LITERAL(36, 543, 7), // "QEvent*"
QT_MOC_LITERAL(37, 551, 17), // "trayIconActivated"
QT_MOC_LITERAL(38, 569, 33), // "QSystemTrayIcon::ActivationRe..."
QT_MOC_LITERAL(39, 603, 6), // "reason"
QT_MOC_LITERAL(40, 610, 17), // "trayActionExecute"
QT_MOC_LITERAL(41, 628, 18), // "createTrayIconMenu"
QT_MOC_LITERAL(42, 647, 6), // "QMenu*"
QT_MOC_LITERAL(43, 654, 12), // "showTrayIcon"
QT_MOC_LITERAL(44, 667, 16), // "authYandexResult"
QT_MOC_LITERAL(45, 684, 6), // "aToken"
QT_MOC_LITERAL(46, 691, 8), // "needAuth"
QT_MOC_LITERAL(47, 700, 23), // "yandexErrorNotification"
QT_MOC_LITERAL(48, 724, 16), // "globalTimerCheck"
QT_MOC_LITERAL(49, 741, 21), // "on_ButtonAgzs_clicked"
QT_MOC_LITERAL(50, 763, 8) // "formAgzs"

    },
    "MainWindow\0createTransaction\0\0Agzs\0"
    "currentAgzs\0Order\0order\0PartnerAPI*\0"
    "aPartner\0sideAdress\0now\0litersFromStart\0"
    "ApiTransaction\0aApiTransaction\0"
    "processAcceptOrder\0aOrder\0"
    "processWaitingRefueling\0processFueling\0"
    "processExpire\0processStationCanceled\0"
    "processUserCanceled\0processCompleted\0"
    "processUnknown\0processClose\0exitPassword\0"
    "checkSettings\0on_ButtonEnter_clicked\0"
    "on_ButtonGetPassword_clicked\0"
    "on_ButtonCancelCitymobile_clicked\0"
    "on_ButtonCancelYandex_clicked\0"
    "on_ButtonSettings_clicked\0updatePrice\0"
    "updateConfiguration\0processOrders\0"
    "orders\0changeEvent\0QEvent*\0trayIconActivated\0"
    "QSystemTrayIcon::ActivationReason\0"
    "reason\0trayActionExecute\0createTrayIconMenu\0"
    "QMenu*\0showTrayIcon\0authYandexResult\0"
    "aToken\0needAuth\0yandexErrorNotification\0"
    "globalTimerCheck\0on_ButtonAgzs_clicked\0"
    "formAgzs"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      32,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    5,  174,    2, 0x0a /* Public */,
      11,    1,  185,    2, 0x0a /* Public */,
      14,    2,  188,    2, 0x0a /* Public */,
      16,    2,  193,    2, 0x0a /* Public */,
      17,    2,  198,    2, 0x0a /* Public */,
      18,    2,  203,    2, 0x0a /* Public */,
      19,    2,  208,    2, 0x0a /* Public */,
      20,    2,  213,    2, 0x0a /* Public */,
      21,    2,  218,    2, 0x0a /* Public */,
      22,    2,  223,    2, 0x0a /* Public */,
      23,    1,  228,    2, 0x0a /* Public */,
      24,    0,  231,    2, 0x0a /* Public */,
      25,    0,  232,    2, 0x08 /* Private */,
      26,    0,  233,    2, 0x08 /* Private */,
      27,    0,  234,    2, 0x08 /* Private */,
      28,    0,  235,    2, 0x08 /* Private */,
      29,    0,  236,    2, 0x08 /* Private */,
      30,    0,  237,    2, 0x08 /* Private */,
      31,    0,  238,    2, 0x08 /* Private */,
      32,    0,  239,    2, 0x08 /* Private */,
      33,    2,  240,    2, 0x08 /* Private */,
      35,    1,  245,    2, 0x08 /* Private */,
      37,    1,  248,    2, 0x08 /* Private */,
      40,    0,  251,    2, 0x08 /* Private */,
      41,    0,  252,    2, 0x08 /* Private */,
      43,    0,  253,    2, 0x08 /* Private */,
      44,    1,  254,    2, 0x08 /* Private */,
      46,    0,  257,    2, 0x08 /* Private */,
      47,    0,  258,    2, 0x08 /* Private */,
      48,    0,  259,    2, 0x08 /* Private */,
      49,    0,  260,    2, 0x08 /* Private */,
      50,    0,  261,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Int, 0x80000000 | 3, 0x80000000 | 5, 0x80000000 | 7, QMetaType::Int, QMetaType::QDateTime,    4,    6,    8,    9,   10,
    QMetaType::Double, 0x80000000 | 12,   13,
    QMetaType::Bool, 0x80000000 | 5, 0x80000000 | 7,   15,    8,
    QMetaType::Bool, 0x80000000 | 5, 0x80000000 | 7,   15,    8,
    QMetaType::Bool, 0x80000000 | 5, 0x80000000 | 7,   15,    8,
    QMetaType::Bool, 0x80000000 | 5, 0x80000000 | 7,   15,    8,
    QMetaType::Bool, 0x80000000 | 5, 0x80000000 | 7,   15,    8,
    QMetaType::Bool, 0x80000000 | 5, 0x80000000 | 7,   15,    8,
    QMetaType::Bool, 0x80000000 | 5, 0x80000000 | 7,   15,    8,
    QMetaType::Bool, 0x80000000 | 5, 0x80000000 | 7,   15,    8,
    QMetaType::Bool, 0x80000000 | 12,   13,
    QMetaType::Void,
    QMetaType::Bool,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7, QMetaType::QJsonDocument,    8,   34,
    QMetaType::Void, 0x80000000 | 36,    2,
    QMetaType::Void, 0x80000000 | 38,   39,
    QMetaType::Void,
    0x80000000 | 42,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   45,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::QString,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { int _r = _t->createTransaction((*reinterpret_cast< Agzs(*)>(_a[1])),(*reinterpret_cast< Order(*)>(_a[2])),(*reinterpret_cast< PartnerAPI*(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< QDateTime(*)>(_a[5])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 1: { double _r = _t->litersFromStart((*reinterpret_cast< ApiTransaction(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = std::move(_r); }  break;
        case 2: { bool _r = _t->processAcceptOrder((*reinterpret_cast< Order(*)>(_a[1])),(*reinterpret_cast< PartnerAPI*(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 3: { bool _r = _t->processWaitingRefueling((*reinterpret_cast< Order(*)>(_a[1])),(*reinterpret_cast< PartnerAPI*(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 4: { bool _r = _t->processFueling((*reinterpret_cast< Order(*)>(_a[1])),(*reinterpret_cast< PartnerAPI*(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 5: { bool _r = _t->processExpire((*reinterpret_cast< Order(*)>(_a[1])),(*reinterpret_cast< PartnerAPI*(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 6: { bool _r = _t->processStationCanceled((*reinterpret_cast< Order(*)>(_a[1])),(*reinterpret_cast< PartnerAPI*(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 7: { bool _r = _t->processUserCanceled((*reinterpret_cast< Order(*)>(_a[1])),(*reinterpret_cast< PartnerAPI*(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 8: { bool _r = _t->processCompleted((*reinterpret_cast< Order(*)>(_a[1])),(*reinterpret_cast< PartnerAPI*(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 9: { bool _r = _t->processUnknown((*reinterpret_cast< Order(*)>(_a[1])),(*reinterpret_cast< PartnerAPI*(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 10: { bool _r = _t->processClose((*reinterpret_cast< ApiTransaction(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 11: _t->exitPassword(); break;
        case 12: { bool _r = _t->checkSettings();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 13: _t->on_ButtonEnter_clicked(); break;
        case 14: _t->on_ButtonGetPassword_clicked(); break;
        case 15: _t->on_ButtonCancelCitymobile_clicked(); break;
        case 16: _t->on_ButtonCancelYandex_clicked(); break;
        case 17: _t->on_ButtonSettings_clicked(); break;
        case 18: _t->updatePrice(); break;
        case 19: _t->updateConfiguration(); break;
        case 20: _t->processOrders((*reinterpret_cast< PartnerAPI*(*)>(_a[1])),(*reinterpret_cast< QJsonDocument(*)>(_a[2]))); break;
        case 21: _t->changeEvent((*reinterpret_cast< QEvent*(*)>(_a[1]))); break;
        case 22: _t->trayIconActivated((*reinterpret_cast< QSystemTrayIcon::ActivationReason(*)>(_a[1]))); break;
        case 23: _t->trayActionExecute(); break;
        case 24: { QMenu* _r = _t->createTrayIconMenu();
            if (_a[0]) *reinterpret_cast< QMenu**>(_a[0]) = std::move(_r); }  break;
        case 25: _t->showTrayIcon(); break;
        case 26: _t->authYandexResult((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 27: _t->needAuth(); break;
        case 28: _t->yandexErrorNotification(); break;
        case 29: _t->globalTimerCheck(); break;
        case 30: _t->on_ButtonAgzs_clicked(); break;
        case 31: { QString _r = _t->formAgzs();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 2:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< PartnerAPI* >(); break;
            }
            break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< PartnerAPI* >(); break;
            }
            break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< PartnerAPI* >(); break;
            }
            break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< PartnerAPI* >(); break;
            }
            break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< PartnerAPI* >(); break;
            }
            break;
        case 6:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< PartnerAPI* >(); break;
            }
            break;
        case 7:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< PartnerAPI* >(); break;
            }
            break;
        case 8:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< PartnerAPI* >(); break;
            }
            break;
        case 9:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< PartnerAPI* >(); break;
            }
            break;
        case 20:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< PartnerAPI* >(); break;
            }
            break;
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
        if (_id < 32)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 32;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 32)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 32;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
