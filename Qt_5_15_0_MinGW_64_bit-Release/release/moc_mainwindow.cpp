/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../Yandex/mainwindow.h"
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
    QByteArrayData data[30];
    char stringdata0[421];
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
QT_MOC_LITERAL(20, 256, 23), // "on_pushButton_5_clicked"
QT_MOC_LITERAL(21, 280, 25), // "on_ButtonSettings_clicked"
QT_MOC_LITERAL(22, 306, 18), // "mainFunctionYandex"
QT_MOC_LITERAL(23, 325, 20), // "updateDataCityMobile"
QT_MOC_LITERAL(24, 346, 19), // "getOrdersCityMobile"
QT_MOC_LITERAL(25, 366, 11), // "updatePrice"
QT_MOC_LITERAL(26, 378, 1), // "p"
QT_MOC_LITERAL(27, 380, 19), // "updateConfiguration"
QT_MOC_LITERAL(28, 400, 13), // "processOrders"
QT_MOC_LITERAL(29, 414, 6) // "orders"

    },
    "MainWindow\0getFuelID\0\0aFuelIdApi\0"
    "getFuelName\0aFuelVCode\0getFuelAPIName\0"
    "moneyData\0Partner\0aPartner\0aRequest\0"
    "double&\0aRequestTotalPriceDB\0"
    "aRequestVolumeDB\0aRequestUnitPriceDB\0"
    "aMoneyTakenDB\0int&\0aFullTankDB\0"
    "on_ButtonEnter_clicked\0"
    "on_ButtonGetPassword_clicked\0"
    "on_pushButton_5_clicked\0"
    "on_ButtonSettings_clicked\0mainFunctionYandex\0"
    "updateDataCityMobile\0getOrdersCityMobile\0"
    "updatePrice\0p\0updateConfiguration\0"
    "processOrders\0orders"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   84,    2, 0x0a /* Public */,
       4,    1,   87,    2, 0x0a /* Public */,
       6,    1,   90,    2, 0x0a /* Public */,
       7,    7,   93,    2, 0x0a /* Public */,
      18,    0,  108,    2, 0x08 /* Private */,
      19,    0,  109,    2, 0x08 /* Private */,
      20,    0,  110,    2, 0x08 /* Private */,
      21,    0,  111,    2, 0x08 /* Private */,
      22,    0,  112,    2, 0x08 /* Private */,
      23,    0,  113,    2, 0x08 /* Private */,
      24,    0,  114,    2, 0x08 /* Private */,
      25,    1,  115,    2, 0x08 /* Private */,
      27,    1,  118,    2, 0x08 /* Private */,
      28,    2,  121,    2, 0x08 /* Private */,

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
    QMetaType::Void, 0x80000000 | 8,   26,
    QMetaType::Void, 0x80000000 | 8,   26,
    QMetaType::Void, 0x80000000 | 8, QMetaType::QJsonDocument,    9,   29,

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
        case 6: _t->on_pushButton_5_clicked(); break;
        case 7: _t->on_ButtonSettings_clicked(); break;
        case 8: _t->mainFunctionYandex(); break;
        case 9: _t->updateDataCityMobile(); break;
        case 10: _t->getOrdersCityMobile(); break;
        case 11: _t->updatePrice((*reinterpret_cast< Partner(*)>(_a[1]))); break;
        case 12: _t->updateConfiguration((*reinterpret_cast< Partner(*)>(_a[1]))); break;
        case 13: _t->processOrders((*reinterpret_cast< Partner(*)>(_a[1])),(*reinterpret_cast< QJsonDocument(*)>(_a[2]))); break;
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
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
