/****************************************************************************
** Meta object code from reading C++ file 'TC_Client.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "TC_Client.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'TC_Client.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TestCaseClient_t {
    QByteArrayData data[9];
    char stringdata0[116];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TestCaseClient_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TestCaseClient_t qt_meta_stringdata_TestCaseClient = {
    {
QT_MOC_LITERAL(0, 0, 14), // "TestCaseClient"
QT_MOC_LITERAL(1, 15, 11), // "responseMsg"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 16), // "callFinishedSlot"
QT_MOC_LITERAL(4, 45, 24), // "QDBusPendingCallWatcher*"
QT_MOC_LITERAL(5, 70, 16), // "workFinishedSlot"
QT_MOC_LITERAL(6, 87, 4), // "quit"
QT_MOC_LITERAL(7, 92, 9), // "Q_NOREPLY"
QT_MOC_LITERAL(8, 102, 13) // "on_requestMsg"

    },
    "TestCaseClient\0responseMsg\0\0"
    "callFinishedSlot\0QDBusPendingCallWatcher*\0"
    "workFinishedSlot\0quit\0Q_NOREPLY\0"
    "on_requestMsg"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TestCaseClient[] = {

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
       3,    1,   42,    2, 0x0a /* Public */,
       5,    1,   45,    2, 0x0a /* Public */,
       6,    0,   48,    7, 0x0a /* Public */,
       8,    1,   49,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 4,    2,
    QMetaType::Void, QMetaType::QByteArray,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray,    2,

       0        // eod
};

void TestCaseClient::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<TestCaseClient *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->responseMsg((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->callFinishedSlot((*reinterpret_cast< QDBusPendingCallWatcher*(*)>(_a[1]))); break;
        case 2: _t->workFinishedSlot((*reinterpret_cast< const QByteArray(*)>(_a[1]))); break;
        case 3: _t->quit(); break;
        case 4: _t->on_requestMsg((*reinterpret_cast< const QByteArray(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QDBusPendingCallWatcher* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (TestCaseClient::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TestCaseClient::responseMsg)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject TestCaseClient::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_TestCaseClient.data,
    qt_meta_data_TestCaseClient,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *TestCaseClient::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TestCaseClient::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TestCaseClient.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int TestCaseClient::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
void TestCaseClient::responseMsg(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
