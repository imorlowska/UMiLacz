/****************************************************************************
** Meta object code from reading C++ file 'connectionsmodel.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.0.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../UMLQT/connectionsmodel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'connectionsmodel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.0.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ConnectionsModel_t {
    QByteArrayData data[9];
    char stringdata[73];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_ConnectionsModel_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_ConnectionsModel_t qt_meta_stringdata_ConnectionsModel = {
    {
QT_MOC_LITERAL(0, 0, 16),
QT_MOC_LITERAL(1, 17, 13),
QT_MOC_LITERAL(2, 31, 0),
QT_MOC_LITERAL(3, 32, 2),
QT_MOC_LITERAL(4, 35, 2),
QT_MOC_LITERAL(5, 38, 4),
QT_MOC_LITERAL(6, 43, 6),
QT_MOC_LITERAL(7, 50, 16),
QT_MOC_LITERAL(8, 67, 4)
    },
    "ConnectionsModel\0addConnection\0\0c1\0"
    "c2\0type\0number\0deleteConnection\0conn\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ConnectionsModel[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // methods: name, argc, parameters, tag, flags
       1,    4,   24,    2, 0x02,
       7,    1,   33,    2, 0x02,

 // methods: parameters
    QMetaType::QString, QMetaType::QVariant, QMetaType::QVariant, QMetaType::Int, QMetaType::Int,    3,    4,    5,    6,
    QMetaType::Void, QMetaType::QVariant,    8,

       0        // eod
};

void ConnectionsModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ConnectionsModel *_t = static_cast<ConnectionsModel *>(_o);
        switch (_id) {
        case 0: { QString _r = _t->addConnection((*reinterpret_cast< const QVariant(*)>(_a[1])),(*reinterpret_cast< const QVariant(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 1: _t->deleteConnection((*reinterpret_cast< const QVariant(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject ConnectionsModel::staticMetaObject = {
    { &QObjectListModel::staticMetaObject, qt_meta_stringdata_ConnectionsModel.data,
      qt_meta_data_ConnectionsModel,  qt_static_metacall, 0, 0}
};


const QMetaObject *ConnectionsModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ConnectionsModel::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ConnectionsModel.stringdata))
        return static_cast<void*>(const_cast< ConnectionsModel*>(this));
    return QObjectListModel::qt_metacast(_clname);
}

int ConnectionsModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObjectListModel::qt_metacall(_c, _id, _a);
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
QT_END_MOC_NAMESPACE
