/****************************************************************************
** Meta object code from reading C++ file 'myqstackedwidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../MyStackedWidget/myqstackedwidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'myqstackedwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MyQStackedWidget_t {
    QByteArrayData data[11];
    char stringdata[121];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MyQStackedWidget_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MyQStackedWidget_t qt_meta_stringdata_MyQStackedWidget = {
    {
QT_MOC_LITERAL(0, 0, 16), // "MyQStackedWidget"
QT_MOC_LITERAL(1, 17, 17), // "animationFinished"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 8), // "ShowLeft"
QT_MOC_LITERAL(4, 45, 9), // "ShowRight"
QT_MOC_LITERAL(5, 55, 10), // "SlideToIdx"
QT_MOC_LITERAL(6, 66, 8), // "QWidget*"
QT_MOC_LITERAL(7, 75, 9), // "newWidget"
QT_MOC_LITERAL(8, 85, 11), // "t_direction"
QT_MOC_LITERAL(9, 97, 9), // "direction"
QT_MOC_LITERAL(10, 107, 13) // "AnimationDone"

    },
    "MyQStackedWidget\0animationFinished\0\0"
    "ShowLeft\0ShowRight\0SlideToIdx\0QWidget*\0"
    "newWidget\0t_direction\0direction\0"
    "AnimationDone"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MyQStackedWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   40,    2, 0x0a /* Public */,
       4,    0,   41,    2, 0x0a /* Public */,
       5,    2,   42,    2, 0x0a /* Public */,
      10,    0,   47,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6, 0x80000000 | 8,    7,    9,
    QMetaType::Void,

       0        // eod
};

void MyQStackedWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MyQStackedWidget *_t = static_cast<MyQStackedWidget *>(_o);
        switch (_id) {
        case 0: _t->animationFinished(); break;
        case 1: _t->ShowLeft(); break;
        case 2: _t->ShowRight(); break;
        case 3: _t->SlideToIdx((*reinterpret_cast< QWidget*(*)>(_a[1])),(*reinterpret_cast< t_direction(*)>(_a[2]))); break;
        case 4: _t->AnimationDone(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QWidget* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MyQStackedWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyQStackedWidget::animationFinished)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject MyQStackedWidget::staticMetaObject = {
    { &QStackedWidget::staticMetaObject, qt_meta_stringdata_MyQStackedWidget.data,
      qt_meta_data_MyQStackedWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MyQStackedWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MyQStackedWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MyQStackedWidget.stringdata))
        return static_cast<void*>(const_cast< MyQStackedWidget*>(this));
    return QStackedWidget::qt_metacast(_clname);
}

int MyQStackedWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QStackedWidget::qt_metacall(_c, _id, _a);
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
void MyQStackedWidget::animationFinished()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
