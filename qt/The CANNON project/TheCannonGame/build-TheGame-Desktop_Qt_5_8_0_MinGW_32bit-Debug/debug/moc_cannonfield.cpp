/****************************************************************************
** Meta object code from reading C++ file 'cannonfield.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../TheGame/cannonfield.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'cannonfield.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CannonField_t {
    QByteArrayData data[23];
    char stringdata0[223];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CannonField_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CannonField_t qt_meta_stringdata_CannonField = {
    {
QT_MOC_LITERAL(0, 0, 11), // "CannonField"
QT_MOC_LITERAL(1, 12, 12), // "AngleChanged"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 3), // "val"
QT_MOC_LITERAL(4, 30, 12), // "ForceChanged"
QT_MOC_LITERAL(5, 43, 11), // "ShotStarted"
QT_MOC_LITERAL(6, 55, 9), // "ShotEnded"
QT_MOC_LITERAL(7, 65, 12), // "TargetWasHit"
QT_MOC_LITERAL(8, 78, 11), // "ModeChanged"
QT_MOC_LITERAL(9, 90, 10), // "paintEvent"
QT_MOC_LITERAL(10, 101, 12), // "QPaintEvent*"
QT_MOC_LITERAL(11, 114, 1), // "e"
QT_MOC_LITERAL(12, 116, 13), // "keyPressEvent"
QT_MOC_LITERAL(13, 130, 10), // "QKeyEvent*"
QT_MOC_LITERAL(14, 141, 8), // "SetAngle"
QT_MOC_LITERAL(15, 150, 8), // "SetForce"
QT_MOC_LITERAL(16, 159, 9), // "StartShot"
QT_MOC_LITERAL(17, 169, 7), // "EndShot"
QT_MOC_LITERAL(18, 177, 8), // "ChangeXY"
QT_MOC_LITERAL(19, 186, 12), // "ChangeTarget"
QT_MOC_LITERAL(20, 199, 10), // "DrawTarget"
QT_MOC_LITERAL(21, 210, 9), // "QPainter*"
QT_MOC_LITERAL(22, 220, 2) // "xp"

    },
    "CannonField\0AngleChanged\0\0val\0"
    "ForceChanged\0ShotStarted\0ShotEnded\0"
    "TargetWasHit\0ModeChanged\0paintEvent\0"
    "QPaintEvent*\0e\0keyPressEvent\0QKeyEvent*\0"
    "SetAngle\0SetForce\0StartShot\0EndShot\0"
    "ChangeXY\0ChangeTarget\0DrawTarget\0"
    "QPainter*\0xp"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CannonField[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   89,    2, 0x06 /* Public */,
       4,    1,   92,    2, 0x06 /* Public */,
       5,    0,   95,    2, 0x06 /* Public */,
       6,    0,   96,    2, 0x06 /* Public */,
       7,    0,   97,    2, 0x06 /* Public */,
       8,    1,   98,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    1,  101,    2, 0x0a /* Public */,
      12,    1,  104,    2, 0x0a /* Public */,
      14,    1,  107,    2, 0x0a /* Public */,
      15,    1,  110,    2, 0x0a /* Public */,
      16,    0,  113,    2, 0x0a /* Public */,
      17,    0,  114,    2, 0x0a /* Public */,
      18,    0,  115,    2, 0x0a /* Public */,
      19,    0,  116,    2, 0x0a /* Public */,
      20,    1,  117,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    3,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 10,   11,
    QMetaType::Void, 0x80000000 | 13,   11,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 21,   22,

       0        // eod
};

void CannonField::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CannonField *_t = static_cast<CannonField *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->AngleChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->ForceChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->ShotStarted(); break;
        case 3: _t->ShotEnded(); break;
        case 4: _t->TargetWasHit(); break;
        case 5: _t->ModeChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->paintEvent((*reinterpret_cast< QPaintEvent*(*)>(_a[1]))); break;
        case 7: _t->keyPressEvent((*reinterpret_cast< QKeyEvent*(*)>(_a[1]))); break;
        case 8: _t->SetAngle((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->SetForce((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->StartShot(); break;
        case 11: _t->EndShot(); break;
        case 12: _t->ChangeXY(); break;
        case 13: _t->ChangeTarget(); break;
        case 14: _t->DrawTarget((*reinterpret_cast< QPainter*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (CannonField::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CannonField::AngleChanged)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (CannonField::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CannonField::ForceChanged)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (CannonField::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CannonField::ShotStarted)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (CannonField::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CannonField::ShotEnded)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (CannonField::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CannonField::TargetWasHit)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (CannonField::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CannonField::ModeChanged)) {
                *result = 5;
                return;
            }
        }
    }
}

const QMetaObject CannonField::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_CannonField.data,
      qt_meta_data_CannonField,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *CannonField::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CannonField::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_CannonField.stringdata0))
        return static_cast<void*>(const_cast< CannonField*>(this));
    return QWidget::qt_metacast(_clname);
}

int CannonField::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 15;
    }
    return _id;
}

// SIGNAL 0
void CannonField::AngleChanged(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CannonField::ForceChanged(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void CannonField::ShotStarted()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void CannonField::ShotEnded()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}

// SIGNAL 4
void CannonField::TargetWasHit()
{
    QMetaObject::activate(this, &staticMetaObject, 4, Q_NULLPTR);
}

// SIGNAL 5
void CannonField::ModeChanged(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
