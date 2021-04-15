/****************************************************************************
** Meta object code from reading C++ file 'citymobileapi.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../Partners/partners/citymobileapi.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'citymobileapi.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CityMobileAPI_t {
    QByteArrayData data[11];
    char stringdata0[115];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CityMobileAPI_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CityMobileAPI_t qt_meta_stringdata_CityMobileAPI = {
    {
QT_MOC_LITERAL(0, 0, 13), // "CityMobileAPI"
QT_MOC_LITERAL(1, 14, 10), // "s_finished"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 12), // "RequestData*"
QT_MOC_LITERAL(4, 39, 7), // "request"
QT_MOC_LITERAL(5, 47, 20), // "createNetworkRequest"
QT_MOC_LITERAL(6, 68, 15), // "QNetworkRequest"
QT_MOC_LITERAL(7, 84, 3), // "url"
QT_MOC_LITERAL(8, 88, 11), // "contentType"
QT_MOC_LITERAL(9, 100, 4), // "auth"
QT_MOC_LITERAL(10, 105, 9) // "checkAuth"

    },
    "CityMobileAPI\0s_finished\0\0RequestData*\0"
    "request\0createNetworkRequest\0"
    "QNetworkRequest\0url\0contentType\0auth\0"
    "checkAuth"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CityMobileAPI[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    3,   42,    2, 0x08 /* Private */,
       5,    2,   49,    2, 0x28 /* Private | MethodCloned */,
       5,    1,   54,    2, 0x28 /* Private | MethodCloned */,
      10,    1,   57,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    0x80000000 | 6, QMetaType::QUrl, QMetaType::QString, QMetaType::Bool,    7,    8,    9,
    0x80000000 | 6, QMetaType::QUrl, QMetaType::QString,    7,    8,
    0x80000000 | 6, QMetaType::QUrl,    7,
    QMetaType::Void, 0x80000000 | 3,    2,

       0        // eod
};

void CityMobileAPI::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CityMobileAPI *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->s_finished((*reinterpret_cast< RequestData*(*)>(_a[1]))); break;
        case 1: { QNetworkRequest _r = _t->createNetworkRequest((*reinterpret_cast< QUrl(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< QNetworkRequest*>(_a[0]) = std::move(_r); }  break;
        case 2: { QNetworkRequest _r = _t->createNetworkRequest((*reinterpret_cast< QUrl(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QNetworkRequest*>(_a[0]) = std::move(_r); }  break;
        case 3: { QNetworkRequest _r = _t->createNetworkRequest((*reinterpret_cast< QUrl(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QNetworkRequest*>(_a[0]) = std::move(_r); }  break;
        case 4: _t->checkAuth((*reinterpret_cast< RequestData*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< RequestData* >(); break;
            }
            break;
        case 4:
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
            using _t = void (CityMobileAPI::*)(RequestData * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CityMobileAPI::s_finished)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject CityMobileAPI::staticMetaObject = { {
    QMetaObject::SuperData::link<PartnerAPI::staticMetaObject>(),
    qt_meta_stringdata_CityMobileAPI.data,
    qt_meta_data_CityMobileAPI,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *CityMobileAPI::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CityMobileAPI::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CityMobileAPI.stringdata0))
        return static_cast<void*>(this);
    return PartnerAPI::qt_metacast(_clname);
}

int CityMobileAPI::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = PartnerAPI::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void CityMobileAPI::s_finished(RequestData * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
