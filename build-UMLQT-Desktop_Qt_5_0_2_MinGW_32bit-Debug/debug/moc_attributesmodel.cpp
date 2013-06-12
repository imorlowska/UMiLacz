/****************************************************************************
** Meta object code from reading C++ file 'attributesmodel.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.0.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../UMLQT/attributesmodel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'attributesmodel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.0.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_AttributesModel_t {
    QByteArrayData data[3];
    char stringdata[27];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_AttributesModel_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_AttributesModel_t qt_meta_stringdata_AttributesModel = {
    {
QT_MOC_LITERAL(0, 0, 15),
QT_MOC_LITERAL(1, 16, 8),
QT_MOC_LITERAL(2, 25, 0)
    },
    "AttributesModel\0addEmpty\0\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AttributesModel[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // methods: name, argc, parameters, tag, flags
       1,    0,   19,    2, 0x02,

 // methods: parameters
    QMetaType::Void,

       0        // eod
};

void AttributesModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        AttributesModel *_t = static_cast<AttributesModel *>(_o);
        switch (_id) {
        case 0: _t->addEmpty(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject AttributesModel::staticMetaObject = {
    { &QObjectListModel::staticMetaObject, qt_meta_stringdata_AttributesModel.data,
      qt_meta_data_AttributesModel,  qt_static_metacall, 0, 0}
};


const QMetaObject *AttributesModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AttributesModel::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_AttributesModel.stringdata))
        return static_cast<void*>(const_cast< AttributesModel*>(this));
    return QObjectListModel::qt_metacast(_clname);
}

int AttributesModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObjectListModel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
