/****************************************************************************
** Meta object code from reading C++ file 'cannonfield.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.0.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../TheGame/cannonfield.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'cannonfield.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.0.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_CannonField_t {
    QByteArrayData data[17];
    char stringdata[162];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_CannonField_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_CannonField_t qt_meta_stringdata_CannonField = {
    {
QT_MOC_LITERAL(0, 0, 11),
QT_MOC_LITERAL(1, 12, 12),
QT_MOC_LITERAL(2, 25, 0),
QT_MOC_LITERAL(3, 26, 3),
QT_MOC_LITERAL(4, 30, 12),
QT_MOC_LITERAL(5, 43, 11),
QT_MOC_LITERAL(6, 55, 9),
QT_MOC_LITERAL(7, 65, 10),
QT_MOC_LITERAL(8, 76, 12),
QT_MOC_LITERAL(9, 89, 1),
QT_MOC_LITERAL(10, 91, 13),
QT_MOC_LITERAL(11, 105, 10),
QT_MOC_LITERAL(12, 116, 8),
QT_MOC_LITERAL(13, 125, 8),
QT_MOC_LITERAL(14, 134, 9),
QT_MOC_LITERAL(15, 144, 7),
QT_MOC_LITERAL(16, 152, 8)
    },
    "CannonField\0AngleChanged\0\0val\0"
    "ForceChanged\0ShotStarted\0ShotEnded\0"
    "paintEvent\0QPaintEvent*\0e\0keyPressEvent\0"
    "QKeyEvent*\0SetAngle\0SetForce\0StartShot\0"
    "EndShot\0ChangeXY\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CannonField[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   69,    2, 0x05,
       4,    1,   72,    2, 0x05,
       5,    0,   75,    2, 0x05,
       6,    0,   76,    2, 0x05,

 // slots: name, argc, parameters, tag, flags
       7,    1,   77,    2, 0x0a,
      10,    1,   80,    2, 0x0a,
      12,    1,   83,    2, 0x0a,
      13,    1,   86,    2, 0x0a,
      14,    0,   89,    2, 0x0a,
      15,    0,   90,    2, 0x0a,
      16,    0,   91,    2, 0x0a,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, 0x80000000 | 11,    9,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void CannonField::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CannonField *_t = static_cast<CannonField *>(_o);
        switch (_id) {
        case 0: _t->AngleChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->ForceChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->ShotStarted(); break;
        case 3: _t->ShotEnded(); break;
        case 4: _t->paintEvent((*reinterpret_cast< QPaintEvent*(*)>(_a[1]))); break;
        case 5: _t->keyPressEvent((*reinterpret_cast< QKeyEvent*(*)>(_a[1]))); break;
        case 6: _t->SetAngle((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->SetForce((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->StartShot(); break;
        case 9: _t->EndShot(); break;
        case 10: _t->ChangeXY(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (CannonField::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CannonField::AngleChanged)) {
                *result = 0;
            }
        }
        {
            typedef void (CannonField::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CannonField::ForceChanged)) {
                *result = 1;
            }
        }
        {
            typedef void (CannonField::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CannonField::ShotStarted)) {
                *result = 2;
            }
        }
        {
            typedef void (CannonField::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CannonField::ShotEnded)) {
                *result = 3;
            }
        }
    }
}

const QMetaObject CannonField::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_CannonField.data,
      qt_meta_data_CannonField,  qt_static_metacall, 0, 0}
};


const QMetaObject *CannonField::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CannonField::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CannonField.stringdata))
        return static_cast<void*>(const_cast< CannonField*>(this));
    return QWidget::qt_metacast(_clname);
}

int CannonField::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void CannonField::AngleChanged(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CannonField::ForceChanged(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void CannonField::ShotStarted()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void CannonField::ShotEnded()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}
QT_END_MOC_NAMESPACE
