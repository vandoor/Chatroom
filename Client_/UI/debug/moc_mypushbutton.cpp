/****************************************************************************
** Meta object code from reading C++ file 'mypushbutton.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../GUI/mypushbutton.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mypushbutton.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MyPushButton_t {
    QByteArrayData data[19];
    char stringdata0[185];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MyPushButton_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MyPushButton_t qt_meta_stringdata_MyPushButton = {
    {
QT_MOC_LITERAL(0, 0, 12), // "MyPushButton"
QT_MOC_LITERAL(1, 13, 10), // "enterEvent"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 7), // "QEvent*"
QT_MOC_LITERAL(4, 33, 10), // "leaveEvent"
QT_MOC_LITERAL(5, 44, 14), // "mouseMoveEvent"
QT_MOC_LITERAL(6, 59, 12), // "QMouseEvent*"
QT_MOC_LITERAL(7, 72, 5), // "event"
QT_MOC_LITERAL(8, 78, 15), // "mousePressEvent"
QT_MOC_LITERAL(9, 94, 17), // "mouseReleaseEvent"
QT_MOC_LITERAL(10, 112, 8), // "setImage"
QT_MOC_LITERAL(11, 121, 4), // "icon"
QT_MOC_LITERAL(12, 126, 7), // "setType"
QT_MOC_LITERAL(13, 134, 4), // "type"
QT_MOC_LITERAL(14, 139, 9), // "setMysize"
QT_MOC_LITERAL(15, 149, 4), // "size"
QT_MOC_LITERAL(16, 154, 9), // "addFriend"
QT_MOC_LITERAL(17, 164, 10), // "buildGroup"
QT_MOC_LITERAL(18, 175, 9) // "joinGroup"

    },
    "MyPushButton\0enterEvent\0\0QEvent*\0"
    "leaveEvent\0mouseMoveEvent\0QMouseEvent*\0"
    "event\0mousePressEvent\0mouseReleaseEvent\0"
    "setImage\0icon\0setType\0type\0setMysize\0"
    "size\0addFriend\0buildGroup\0joinGroup"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MyPushButton[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   69,    2, 0x0a /* Public */,
       4,    1,   72,    2, 0x0a /* Public */,
       5,    1,   75,    2, 0x0a /* Public */,
       8,    1,   78,    2, 0x0a /* Public */,
       9,    1,   81,    2, 0x0a /* Public */,
      10,    1,   84,    2, 0x0a /* Public */,
      12,    1,   87,    2, 0x0a /* Public */,
      14,    1,   90,    2, 0x0a /* Public */,
      16,    0,   93,    2, 0x0a /* Public */,
      17,    0,   94,    2, 0x0a /* Public */,
      18,    0,   95,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void, QMetaType::QString,   13,
    QMetaType::Void, QMetaType::QSize,   15,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MyPushButton::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MyPushButton *_t = static_cast<MyPushButton *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->enterEvent((*reinterpret_cast< QEvent*(*)>(_a[1]))); break;
        case 1: _t->leaveEvent((*reinterpret_cast< QEvent*(*)>(_a[1]))); break;
        case 2: _t->mouseMoveEvent((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 3: _t->mousePressEvent((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 4: _t->mouseReleaseEvent((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 5: _t->setImage((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->setType((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: _t->setMysize((*reinterpret_cast< QSize(*)>(_a[1]))); break;
        case 8: _t->addFriend(); break;
        case 9: _t->buildGroup(); break;
        case 10: _t->joinGroup(); break;
        default: ;
        }
    }
}

const QMetaObject MyPushButton::staticMetaObject = {
    { &QPushButton::staticMetaObject, qt_meta_stringdata_MyPushButton.data,
      qt_meta_data_MyPushButton,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MyPushButton::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MyPushButton::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MyPushButton.stringdata0))
        return static_cast<void*>(const_cast< MyPushButton*>(this));
    return QPushButton::qt_metacast(_clname);
}

int MyPushButton::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QPushButton::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
