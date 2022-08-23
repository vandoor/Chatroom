/****************************************************************************
** Meta object code from reading C++ file 'mainui_midbar.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../GUI/mainui_midbar.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainui_midbar.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainUI_MidBar_t {
    QByteArrayData data[17];
    char stringdata0[218];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainUI_MidBar_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainUI_MidBar_t qt_meta_stringdata_MainUI_MidBar = {
    {
QT_MOC_LITERAL(0, 0, 13), // "MainUI_MidBar"
QT_MOC_LITERAL(1, 14, 14), // "openChatWindow"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 13), // "MyToolButton*"
QT_MOC_LITERAL(4, 44, 11), // "addNewGroup"
QT_MOC_LITERAL(5, 56, 7), // "groupID"
QT_MOC_LITERAL(6, 64, 9), // "groupName"
QT_MOC_LITERAL(7, 74, 20), // "toRecentConversation"
QT_MOC_LITERAL(8, 95, 12), // "toFriendList"
QT_MOC_LITERAL(9, 108, 11), // "toGroupList"
QT_MOC_LITERAL(10, 120, 10), // "toSettings"
QT_MOC_LITERAL(11, 131, 10), // "showNotice"
QT_MOC_LITERAL(12, 142, 22), // "initRecentConversation"
QT_MOC_LITERAL(13, 165, 14), // "initFriendList"
QT_MOC_LITERAL(14, 180, 13), // "initGroupList"
QT_MOC_LITERAL(15, 194, 6), // "search"
QT_MOC_LITERAL(16, 201, 16) // "openConversation"

    },
    "MainUI_MidBar\0openChatWindow\0\0"
    "MyToolButton*\0addNewGroup\0groupID\0"
    "groupName\0toRecentConversation\0"
    "toFriendList\0toGroupList\0toSettings\0"
    "showNotice\0initRecentConversation\0"
    "initFriendList\0initGroupList\0search\0"
    "openConversation"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainUI_MidBar[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   74,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    2,   77,    2, 0x0a /* Public */,
       7,    0,   82,    2, 0x0a /* Public */,
       8,    0,   83,    2, 0x0a /* Public */,
       9,    0,   84,    2, 0x0a /* Public */,
      10,    0,   85,    2, 0x0a /* Public */,
      11,    0,   86,    2, 0x0a /* Public */,
      12,    0,   87,    2, 0x0a /* Public */,
      13,    0,   88,    2, 0x0a /* Public */,
      14,    0,   89,    2, 0x0a /* Public */,
      15,    0,   90,    2, 0x0a /* Public */,
      16,    0,   91,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    5,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainUI_MidBar::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainUI_MidBar *_t = static_cast<MainUI_MidBar *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->openChatWindow((*reinterpret_cast< MyToolButton*(*)>(_a[1]))); break;
        case 1: _t->addNewGroup((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 2: _t->toRecentConversation(); break;
        case 3: _t->toFriendList(); break;
        case 4: _t->toGroupList(); break;
        case 5: _t->toSettings(); break;
        case 6: _t->showNotice(); break;
        case 7: _t->initRecentConversation(); break;
        case 8: _t->initFriendList(); break;
        case 9: _t->initGroupList(); break;
        case 10: _t->search(); break;
        case 11: _t->openConversation(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< MyToolButton* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MainUI_MidBar::*_t)(MyToolButton * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainUI_MidBar::openChatWindow)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject MainUI_MidBar::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_MainUI_MidBar.data,
      qt_meta_data_MainUI_MidBar,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MainUI_MidBar::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainUI_MidBar::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MainUI_MidBar.stringdata0))
        return static_cast<void*>(const_cast< MainUI_MidBar*>(this));
    return QWidget::qt_metacast(_clname);
}

int MainUI_MidBar::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void MainUI_MidBar::openChatWindow(MyToolButton * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
