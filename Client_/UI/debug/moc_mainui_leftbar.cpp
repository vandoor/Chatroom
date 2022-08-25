/****************************************************************************
** Meta object code from reading C++ file 'mainui_leftbar.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../GUI/mainui_leftbar.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainui_leftbar.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainUI_LeftBar_t {
    QByteArrayData data[5];
    char stringdata0[61];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainUI_LeftBar_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainUI_LeftBar_t qt_meta_stringdata_MainUI_LeftBar = {
    {
QT_MOC_LITERAL(0, 0, 14), // "MainUI_LeftBar"
QT_MOC_LITERAL(1, 15, 20), // "toRecentConversation"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 12), // "toFriendList"
QT_MOC_LITERAL(4, 50, 10) // "toSettings"

    },
    "MainUI_LeftBar\0toRecentConversation\0"
    "\0toFriendList\0toSettings"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainUI_LeftBar[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   29,    2, 0x06 /* Public */,
       3,    0,   30,    2, 0x06 /* Public */,
       4,    0,   31,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainUI_LeftBar::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainUI_LeftBar *_t = static_cast<MainUI_LeftBar *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->toRecentConversation(); break;
        case 1: _t->toFriendList(); break;
        case 2: _t->toSettings(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MainUI_LeftBar::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainUI_LeftBar::toRecentConversation)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (MainUI_LeftBar::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainUI_LeftBar::toFriendList)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (MainUI_LeftBar::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainUI_LeftBar::toSettings)) {
                *result = 2;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject MainUI_LeftBar::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_MainUI_LeftBar.data,
      qt_meta_data_MainUI_LeftBar,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MainUI_LeftBar::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainUI_LeftBar::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MainUI_LeftBar.stringdata0))
        return static_cast<void*>(const_cast< MainUI_LeftBar*>(this));
    return QWidget::qt_metacast(_clname);
}

int MainUI_LeftBar::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void MainUI_LeftBar::toRecentConversation()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void MainUI_LeftBar::toFriendList()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void MainUI_LeftBar::toSettings()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
