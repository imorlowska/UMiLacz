/****************************************************************************
** Meta object code from reading C++ file 'qconnection.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.0.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../UMLQT/qconnection.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qconnection.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.0.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_QConnection_t {
    QByteArrayData data[12];
    char stringdata[107];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_QConnection_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_QConnection_t qt_meta_stringdata_QConnection = {
    {
QT_MOC_LITERAL(0, 0, 11),
QT_MOC_LITERAL(1, 12, 11),
QT_MOC_LITERAL(2, 24, 0),
QT_MOC_LITERAL(3, 25, 13),
QT_MOC_LITERAL(4, 39, 13),
QT_MOC_LITERAL(5, 53, 13),
QT_MOC_LITERAL(6, 67, 9),
QT_MOC_LITERAL(7, 77, 4),
QT_MOC_LITERAL(8, 82, 6),
QT_MOC_LITERAL(9, 89, 6),
QT_MOC_LITERAL(10, 96, 6),
QT_MOC_LITERAL(11, 103, 2)
    },
    "QConnection\0typeChanged\0\0numberChanged\0"
    "class1Changed\0class2Changed\0idChanged\0"
    "type\0number\0class1\0class2\0id\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QConnection[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       5,   44, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x05,
       3,    0,   40,    2, 0x05,
       4,    0,   41,    2, 0x05,
       5,    0,   42,    2, 0x05,
       6,    0,   43,    2, 0x05,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // properties: name, type, flags
       7, QMetaType::Int, 0x00495103,
       8, QMetaType::Int, 0x00495103,
       9, QMetaType::QVariant, 0x00495103,
      10, QMetaType::QVariant, 0x00495103,
      11, QMetaType::Int, 0x00495001,

 // properties: notify_signal_id
       0,
       1,
       2,
       3,
       4,

       0        // eod
};

void QConnection::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QConnection *_t = static_cast<QConnection *>(_o);
        switch (_id) {
        case 0: _t->typeChanged(); break;
        case 1: _t->numberChanged(); break;
        case 2: _t->class1Changed(); break;
        case 3: _t->class2Changed(); break;
        case 4: _t->idChanged(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (QConnection::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QConnection::typeChanged)) {
                *result = 0;
            }
        }
        {
            typedef void (QConnection::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QConnection::numberChanged)) {
                *result = 1;
            }
        }
        {
            typedef void (QConnection::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QConnection::class1Changed)) {
                *result = 2;
            }
        }
        {
            typedef void (QConnection::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QConnection::class2Changed)) {
                *result = 3;
            }
        }
        {
            typedef void (QConnection::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QConnection::idChanged)) {
                *result = 4;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject QConnection::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_QConnection.data,
      qt_meta_data_QConnection,  qt_static_metacall, 0, 0}
};


const QMetaObject *QConnection::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QConnection::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QConnection.stringdata))
        return static_cast<void*>(const_cast< QConnection*>(this));
    return QObject::qt_metacast(_clname);
}

int QConnection::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< int*>(_v) = getType(); break;
        case 1: *reinterpret_cast< int*>(_v) = getNumber(); break;
        case 2: *reinterpret_cast< QVariant*>(_v) = getClass1(); break;
        case 3: *reinterpret_cast< QVariant*>(_v) = getClass2(); break;
        case 4: *reinterpret_cast< int*>(_v) = getId(); break;
        }
        _id -= 5;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: setType(*reinterpret_cast< int*>(_v)); break;
        case 1: setNumber(*reinterpret_cast< int*>(_v)); break;
        case 2: setClass1(*reinterpret_cast< QVariant*>(_v)); break;
        case 3: setClass2(*reinterpret_cast< QVariant*>(_v)); break;
        }
        _id -= 5;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 5;
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void QConnection::typeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void QConnection::numberChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void QConnection::class1Changed()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void QConnection::class2Changed()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}

// SIGNAL 4
void QConnection::idChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, 0);
}
QT_END_MOC_NAMESPACE
