/****************************************************************************
** Meta object code from reading C++ file 'TC_Server.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "TC_Server.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'TC_Server.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TestCaseServer_t {
    QByteArrayData data[26];
    char stringdata0[298];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TestCaseServer_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TestCaseServer_t qt_meta_stringdata_TestCaseServer = {
    {
QT_MOC_LITERAL(0, 0, 14), // "TestCaseServer"
QT_MOC_LITERAL(1, 15, 15), // "D-Bus Interface"
QT_MOC_LITERAL(2, 31, 22), // "lge.tc.QtDBus.tcServer"
QT_MOC_LITERAL(3, 54, 8), // "finished"
QT_MOC_LITERAL(4, 63, 0), // ""
QT_MOC_LITERAL(5, 64, 24), // "QDBusPendingCallWatcher*"
QT_MOC_LITERAL(6, 89, 4), // "self"
QT_MOC_LITERAL(7, 94, 12), // "workFinished"
QT_MOC_LITERAL(8, 107, 11), // "aboutToQuit"
QT_MOC_LITERAL(9, 119, 17), // "reqTestFromClient"
QT_MOC_LITERAL(10, 137, 3), // "msg"
QT_MOC_LITERAL(11, 141, 23), // "on_completeSimpleThread"
QT_MOC_LITERAL(12, 165, 4), // "quit"
QT_MOC_LITERAL(13, 170, 9), // "Q_NOREPLY"
QT_MOC_LITERAL(14, 180, 13), // "audioTestMain"
QT_MOC_LITERAL(15, 194, 10), // "testCaseID"
QT_MOC_LITERAL(16, 205, 4), // "tcID"
QT_MOC_LITERAL(17, 210, 10), // "audioTest1"
QT_MOC_LITERAL(18, 221, 3), // "arg"
QT_MOC_LITERAL(19, 225, 10), // "audioTest2"
QT_MOC_LITERAL(20, 236, 10), // "audioTest3"
QT_MOC_LITERAL(21, 247, 11), // "bspTestMain"
QT_MOC_LITERAL(22, 259, 8), // "bspTest1"
QT_MOC_LITERAL(23, 268, 8), // "bspTest2"
QT_MOC_LITERAL(24, 277, 8), // "bspTest3"
QT_MOC_LITERAL(25, 286, 11) // "allAutoTest"

    },
    "TestCaseServer\0D-Bus Interface\0"
    "lge.tc.QtDBus.tcServer\0finished\0\0"
    "QDBusPendingCallWatcher*\0self\0"
    "workFinished\0aboutToQuit\0reqTestFromClient\0"
    "msg\0on_completeSimpleThread\0quit\0"
    "Q_NOREPLY\0audioTestMain\0testCaseID\0"
    "tcID\0audioTest1\0arg\0audioTest2\0"
    "audioTest3\0bspTestMain\0bspTest1\0"
    "bspTest2\0bspTest3\0allAutoTest"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TestCaseServer[] = {

 // content:
       8,       // revision
       0,       // classname
       1,   14, // classinfo
      15,   16, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // classinfo: key, value
       1,    2,

 // signals: name, argc, parameters, tag, flags
       3,    1,   91,    4, 0x06 /* Public */,
       7,    1,   94,    4, 0x06 /* Public */,
       8,    0,   97,    4, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    1,   98,    4, 0x4a /* Public | isScriptable */,
      11,    1,  101,    4, 0x0a /* Public */,
      12,    0,  104,   13, 0x0a /* Public */,

 // methods: name, argc, parameters, tag, flags
      14,    1,  105,    4, 0x42 /* Public | isScriptable */,
      17,    1,  108,    4, 0x42 /* Public | isScriptable */,
      19,    1,  111,    4, 0x42 /* Public | isScriptable */,
      20,    1,  114,    4, 0x42 /* Public | isScriptable */,
      21,    1,  117,    4, 0x42 /* Public | isScriptable */,
      22,    1,  120,    4, 0x42 /* Public | isScriptable */,
      23,    1,  123,    4, 0x42 /* Public | isScriptable */,
      24,    1,  126,    4, 0x42 /* Public | isScriptable */,
      25,    0,  129,    4, 0x42 /* Public | isScriptable */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, QMetaType::QByteArray,    4,
    QMetaType::Void,

 // slots: parameters
    QMetaType::QString, QMetaType::QByteArray,   10,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void,

 // methods: parameters
    QMetaType::QString, 0x80000000 | 15,   16,
    QMetaType::QString, QMetaType::QString,   18,
    QMetaType::QString, QMetaType::QString,   18,
    QMetaType::QString, QMetaType::QString,   18,
    QMetaType::QString, 0x80000000 | 15,   16,
    QMetaType::QString, QMetaType::QString,   18,
    QMetaType::QString, QMetaType::QString,   18,
    QMetaType::QString, QMetaType::QString,   18,
    QMetaType::QString,

       0        // eod
};

void TestCaseServer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<TestCaseServer *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->finished((*reinterpret_cast< QDBusPendingCallWatcher*(*)>(_a[1]))); break;
        case 1: _t->workFinished((*reinterpret_cast< const QByteArray(*)>(_a[1]))); break;
        case 2: _t->aboutToQuit(); break;
        case 3: { QString _r = _t->reqTestFromClient((*reinterpret_cast< const QByteArray(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 4: _t->on_completeSimpleThread((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->quit(); break;
        case 6: { QString _r = _t->audioTestMain((*reinterpret_cast< testCaseID(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 7: { QString _r = _t->audioTest1((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 8: { QString _r = _t->audioTest2((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 9: { QString _r = _t->audioTest3((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 10: { QString _r = _t->bspTestMain((*reinterpret_cast< testCaseID(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 11: { QString _r = _t->bspTest1((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 12: { QString _r = _t->bspTest2((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 13: { QString _r = _t->bspTest3((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 14: { QString _r = _t->allAutoTest();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
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
            using _t = void (TestCaseServer::*)(QDBusPendingCallWatcher * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TestCaseServer::finished)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (TestCaseServer::*)(const QByteArray & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TestCaseServer::workFinished)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (TestCaseServer::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TestCaseServer::aboutToQuit)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject TestCaseServer::staticMetaObject = { {
    &QDBusAbstractAdaptor::staticMetaObject,
    qt_meta_stringdata_TestCaseServer.data,
    qt_meta_data_TestCaseServer,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *TestCaseServer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TestCaseServer::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TestCaseServer.stringdata0))
        return static_cast<void*>(this);
    return QDBusAbstractAdaptor::qt_metacast(_clname);
}

int TestCaseServer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDBusAbstractAdaptor::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    }
    return _id;
}

// SIGNAL 0
void TestCaseServer::finished(QDBusPendingCallWatcher * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void TestCaseServer::workFinished(const QByteArray & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void TestCaseServer::aboutToQuit()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
