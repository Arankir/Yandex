/****************************************************************************
** Meta object code from reading C++ file 'partnerapi.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../Partners/partners/partnerapi.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'partnerapi.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_PartnerAPI_t {
    QByteArrayData data[22];
    char stringdata0[235];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PartnerAPI_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PartnerAPI_t qt_meta_stringdata_PartnerAPI = {
    {
QT_MOC_LITERAL(0, 0, 10), // "PartnerAPI"
QT_MOC_LITERAL(1, 11, 11), // "s_gotOrders"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 6), // "orders"
QT_MOC_LITERAL(4, 31, 7), // "s_error"
QT_MOC_LITERAL(5, 39, 6), // "status"
QT_MOC_LITERAL(6, 46, 5), // "order"
QT_MOC_LITERAL(7, 52, 4), // "code"
QT_MOC_LITERAL(8, 57, 11), // "checkOrders"
QT_MOC_LITERAL(9, 69, 20), // "createNetworkRequest"
QT_MOC_LITERAL(10, 90, 15), // "QNetworkRequest"
QT_MOC_LITERAL(11, 106, 3), // "url"
QT_MOC_LITERAL(12, 110, 11), // "contentType"
QT_MOC_LITERAL(13, 122, 4), // "auth"
QT_MOC_LITERAL(14, 127, 17), // "createRequestData"
QT_MOC_LITERAL(15, 145, 12), // "RequestData*"
QT_MOC_LITERAL(16, 158, 9), // "checkAuth"
QT_MOC_LITERAL(17, 168, 10), // "logNetwork"
QT_MOC_LITERAL(18, 179, 32), // "QNetworkAccessManager::Operation"
QT_MOC_LITERAL(19, 212, 9), // "operation"
QT_MOC_LITERAL(20, 222, 7), // "request"
QT_MOC_LITERAL(21, 230, 4) // "post"

    },
    "PartnerAPI\0s_gotOrders\0\0orders\0s_error\0"
    "status\0order\0code\0checkOrders\0"
    "createNetworkRequest\0QNetworkRequest\0"
    "url\0contentType\0auth\0createRequestData\0"
    "RequestData*\0checkAuth\0logNetwork\0"
    "QNetworkAccessManager::Operation\0"
    "operation\0request\0post"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PartnerAPI[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x06 /* Public */,
       4,    3,   62,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    0,   69,    2, 0x0a /* Public */,
       9,    3,   70,    2, 0x09 /* Protected */,
       9,    2,   77,    2, 0x29 /* Protected | MethodCloned */,
       9,    1,   82,    2, 0x29 /* Protected | MethodCloned */,
      14,    0,   85,    2, 0x09 /* Protected */,
      16,    1,   86,    2, 0x09 /* Protected */,
      17,    4,   89,    2, 0x09 /* Protected */,

 // signals: parameters
    QMetaType::Void, QMetaType::QJsonDocument,    3,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::Int,    5,    6,    7,

 // slots: parameters
    QMetaType::Int,
    0x80000000 | 10, QMetaType::QUrl, QMetaType::QString, QMetaType::QString,   11,   12,   13,
    0x80000000 | 10, QMetaType::QUrl, QMetaType::QString,   11,   12,
    0x80000000 | 10, QMetaType::QUrl,   11,
    0x80000000 | 15,
    QMetaType::Void, 0x80000000 | 15,    2,
    QMetaType::Void, 0x80000000 | 18, QMetaType::QString, QMetaType::QString, QMetaType::Int,   19,   20,   21,    7,

       0        // eod
};

void PartnerAPI::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<PartnerAPI *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->s_gotOrders((*reinterpret_cast< QJsonDocument(*)>(_a[1]))); break;
        case 1: _t->s_error((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 2: { int _r = _t->checkOrders();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 3: { QNetworkRequest _r = _t->createNetworkRequest((*reinterpret_cast< QUrl(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< QNetworkRequest*>(_a[0]) = std::move(_r); }  break;
        case 4: { QNetworkRequest _r = _t->createNetworkRequest((*reinterpret_cast< QUrl(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QNetworkRequest*>(_a[0]) = std::move(_r); }  break;
        case 5: { QNetworkRequest _r = _t->createNetworkRequest((*reinterpret_cast< QUrl(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QNetworkRequest*>(_a[0]) = std::move(_r); }  break;
        case 6: { RequestData* _r = _t->createRequestData();
            if (_a[0]) *reinterpret_cast< RequestData**>(_a[0]) = std::move(_r); }  break;
        case 7: _t->checkAuth((*reinterpret_cast< RequestData*(*)>(_a[1]))); break;
        case 8: _t->logNetwork((*reinterpret_cast< QNetworkAccessManager::Operation(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
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
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (PartnerAPI::*)(QJsonDocument );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PartnerAPI::s_gotOrders)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (PartnerAPI::*)(QString , QString , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PartnerAPI::s_error)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject PartnerAPI::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_PartnerAPI.data,
    qt_meta_data_PartnerAPI,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *PartnerAPI::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PartnerAPI::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_PartnerAPI.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int PartnerAPI::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void PartnerAPI::s_gotOrders(QJsonDocument _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void PartnerAPI::s_error(QString _t1, QString _t2, int _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
