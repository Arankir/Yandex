/****************************************************************************
** Meta object code from reading C++ file 'yandexapi.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../Partners/partners/yandexapi.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'yandexapi.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_YandexAPI_t {
    QByteArrayData data[22];
    char stringdata0[202];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_YandexAPI_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_YandexAPI_t qt_meta_stringdata_YandexAPI = {
    {
QT_MOC_LITERAL(0, 0, 9), // "YandexAPI"
QT_MOC_LITERAL(1, 10, 10), // "s_setTimer"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 4), // "mSec"
QT_MOC_LITERAL(4, 27, 10), // "s_needAuth"
QT_MOC_LITERAL(5, 38, 14), // "s_authComplete"
QT_MOC_LITERAL(6, 53, 5), // "token"
QT_MOC_LITERAL(7, 59, 13), // "s_updatePrice"
QT_MOC_LITERAL(8, 73, 11), // "s_gotOrders"
QT_MOC_LITERAL(9, 85, 6), // "orders"
QT_MOC_LITERAL(10, 92, 7), // "s_error"
QT_MOC_LITERAL(11, 100, 6), // "status"
QT_MOC_LITERAL(12, 107, 5), // "order"
QT_MOC_LITERAL(13, 113, 4), // "code"
QT_MOC_LITERAL(14, 118, 13), // "createRequest"
QT_MOC_LITERAL(15, 132, 15), // "QNetworkRequest"
QT_MOC_LITERAL(16, 148, 3), // "url"
QT_MOC_LITERAL(17, 152, 11), // "contentType"
QT_MOC_LITERAL(18, 164, 4), // "auth"
QT_MOC_LITERAL(19, 169, 9), // "checkAuth"
QT_MOC_LITERAL(20, 179, 12), // "RequestData*"
QT_MOC_LITERAL(21, 192, 9) // "saveToken"

    },
    "YandexAPI\0s_setTimer\0\0mSec\0s_needAuth\0"
    "s_authComplete\0token\0s_updatePrice\0"
    "s_gotOrders\0orders\0s_error\0status\0"
    "order\0code\0createRequest\0QNetworkRequest\0"
    "url\0contentType\0auth\0checkAuth\0"
    "RequestData*\0saveToken"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_YandexAPI[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x06 /* Public */,
       4,    1,   62,    2, 0x06 /* Public */,
       5,    1,   65,    2, 0x06 /* Public */,
       7,    0,   68,    2, 0x06 /* Public */,
       8,    1,   69,    2, 0x06 /* Public */,
      10,    3,   72,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      14,    3,   79,    2, 0x08 /* Private */,
      19,    1,   86,    2, 0x08 /* Private */,
      21,    1,   89,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QJsonDocument,    9,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::Int,   11,   12,   13,

 // slots: parameters
    0x80000000 | 15, QMetaType::QString, QMetaType::QString, QMetaType::Bool,   16,   17,   18,
    QMetaType::Void, 0x80000000 | 20,    2,
    QMetaType::Void, 0x80000000 | 20,    2,

       0        // eod
};

void YandexAPI::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<YandexAPI *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->s_setTimer((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->s_needAuth((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->s_authComplete((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->s_updatePrice(); break;
        case 4: _t->s_gotOrders((*reinterpret_cast< QJsonDocument(*)>(_a[1]))); break;
        case 5: _t->s_error((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 6: { QNetworkRequest _r = _t->createRequest((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< QNetworkRequest*>(_a[0]) = std::move(_r); }  break;
        case 7: _t->checkAuth((*reinterpret_cast< RequestData*(*)>(_a[1]))); break;
        case 8: _t->saveToken((*reinterpret_cast< RequestData*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 7:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< RequestData* >(); break;
            }
            break;
        case 8:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< RequestData* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (YandexAPI::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&YandexAPI::s_setTimer)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (YandexAPI::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&YandexAPI::s_needAuth)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (YandexAPI::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&YandexAPI::s_authComplete)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (YandexAPI::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&YandexAPI::s_updatePrice)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (YandexAPI::*)(QJsonDocument );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&YandexAPI::s_gotOrders)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (YandexAPI::*)(QString , QString , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&YandexAPI::s_error)) {
                *result = 5;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject YandexAPI::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_YandexAPI.data,
    qt_meta_data_YandexAPI,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *YandexAPI::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *YandexAPI::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_YandexAPI.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int YandexAPI::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void YandexAPI::s_setTimer(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void YandexAPI::s_needAuth(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void YandexAPI::s_authComplete(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void YandexAPI::s_updatePrice()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void YandexAPI::s_gotOrders(QJsonDocument _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void YandexAPI::s_error(QString _t1, QString _t2, int _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
