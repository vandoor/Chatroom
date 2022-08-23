/****************************************************************************
** Meta object code from reading C++ file 'mainui_rightbar.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../GUI/mainui_rightbar.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainui_rightbar.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainUI_RightBar_t {
    QByteArrayData data[9];
    char stringdata0[127];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainUI_RightBar_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainUI_RightBar_t qt_meta_stringdata_MainUI_RightBar = {
    {
QT_MOC_LITERAL(0, 0, 15), // "MainUI_RightBar"
QT_MOC_LITERAL(1, 16, 20), // "flashGroupMemberList"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 11), // "resizeEvent"
QT_MOC_LITERAL(4, 50, 13), // "QResizeEvent*"
QT_MOC_LITERAL(5, 64, 8), // "sendText"
QT_MOC_LITERAL(6, 73, 19), // "openGroupMemberList"
QT_MOC_LITERAL(7, 93, 24), // "openFirstGroupMemberList"
QT_MOC_LITERAL(8, 118, 8) // "sendFile"

    },
    "MainUI_RightBar\0flashGroupMemberList\0"
    "\0resizeEvent\0QResizeEvent*\0sendText\0"
    "openGroupMemberList\0openFirstGroupMemberList\0"
    "sendFile"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainUI_RightBar[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    1,   45,    2, 0x0a /* Public */,
       5,    0,   48,    2, 0x0a /* Public */,
       6,    0,   49,    2, 0x0a /* Public */,
       7,    0,   50,    2, 0x0a /* Public */,
       8,    0,   51,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 4,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainUI_RightBar::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainUI_RightBar *_t = static_cast<MainUI_RightBar *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->flashGroupMemberList(); break;
        case 1: _t->resizeEvent((*reinterpret_cast< QResizeEvent*(*)>(_a[1]))); break;
        case 2: _t->sendText(); break;
        case 3: _t->openGroupMemberList(); break;
        case 4: _t->openFirstGroupMemberList(); break;
        case 5: _t->sendFile(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MainUI_RightBar::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainUI_RightBar::flashGroupMemberList)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject MainUI_RightBar::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_MainUI_RightBar.data,
      qt_meta_data_MainUI_RightBar,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MainUI_RightBar::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainUI_RightBar::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MainUI_RightBar.stringdata0))
        return static_cast<void*>(const_cast< MainUI_RightBar*>(this));
    return QWidget::qt_metacast(_clname);
}

int MainUI_RightBar::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void MainUI_RightBar::flashGroupMemberList()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
