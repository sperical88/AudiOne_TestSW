/****************************************************************************
** Meta object code from reading C++ file 'TC_ClientAdaptor.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "TC_ClientAdaptor.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'TC_ClientAdaptor.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TestCaseClientAdaptor_t {
    QByteArrayData data[6];
    char stringdata0[90];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TestCaseClientAdaptor_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TestCaseClientAdaptor_t qt_meta_stringdata_TestCaseClientAdaptor = {
    {
QT_MOC_LITERAL(0, 0, 21), // "TestCaseClientAdaptor"
QT_MOC_LITERAL(1, 22, 15), // "D-Bus Interface"
QT_MOC_LITERAL(2, 38, 22), // "lge.tc.QtDBus.tcClient"
QT_MOC_LITERAL(3, 61, 10), // "workFinish"
QT_MOC_LITERAL(4, 72, 0), // ""
QT_MOC_LITERAL(5, 73, 16) // "workFinishedSlot"

    },
    "TestCaseClientAdaptor\0D-Bus Interface\0"
    "lge.tc.QtDBus.tcClient\0workFinish\0\0"
    "workFinishedSlot"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TestCaseClientAdaptor[] = {

 // content:
       8,       // revision
       0,       // classname
       1,   14, // classinfo
       2,   16, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // classinfo: key, value
       1,    2,

 // signals: name, argc, parameters, tag, flags
       3,    1,   26,    4, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   29,    4, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QByteArray,    4,

 // slots: parameters
    QMetaType::Void, QMetaType::QByteArray,    4,

       0        // eod
};

void TestCaseClientAdaptor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<TestCaseClientAdaptor *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->workFinish((*reinterpret_cast< const QByteArray(*)>(_a[1]))); break;
        case 1: _t->workFinishedSlot((*reinterpret_cast< const QByteArray(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (TestCaseClientAdaptor::*)(const QByteArray & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TestCaseClientAdaptor::workFinish)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject TestCaseClientAdaptor::staticMetaObject = { {
    &QDBusAbstractAdaptor::staticMetaObject,
    qt_meta_stringdata_TestCaseClientAdaptor.data,
    qt_meta_data_TestCaseClientAdaptor,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *TestCaseClientAdaptor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TestCaseClientAdaptor::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TestCaseClientAdaptor.stringdata0))
        return static_cast<void*>(this);
    return QDBusAbstractAdaptor::qt_metacast(_clname);
}

int TestCaseClientAdaptor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDBusAbstractAdaptor::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void TestCaseClientAdaptor::workFinish(const QByteArray & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
