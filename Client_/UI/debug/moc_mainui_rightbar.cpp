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
    QByteArrayData data[16];
    char stringdata0[196];
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
QT_MOC_LITERAL(8, 118, 8), // "sendFile"
QT_MOC_LITERAL(9, 127, 9), // "sendEmoji"
QT_MOC_LITERAL(10, 137, 5), // "index"
QT_MOC_LITERAL(11, 143, 8), // "sendDaku"
QT_MOC_LITERAL(12, 152, 10), // "sendHaixiu"
QT_MOC_LITERAL(13, 163, 11), // "sendWeixiao"
QT_MOC_LITERAL(14, 175, 6), // "sendQi"
QT_MOC_LITERAL(15, 182, 13) // "sendZhuangsha"

    },
    "MainUI_RightBar\0flashGroupMemberList\0"
    "\0resizeEvent\0QResizeEvent*\0sendText\0"
    "openGroupMemberList\0openFirstGroupMemberList\0"
    "sendFile\0sendEmoji\0index\0sendDaku\0"
    "sendHaixiu\0sendWeixiao\0sendQi\0"
    "sendZhuangsha"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainUI_RightBar[] = {

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
       1,    0,   74,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    1,   75,    2, 0x0a /* Public */,
       5,    0,   78,    2, 0x0a /* Public */,
       6,    0,   79,    2, 0x0a /* Public */,
       7,    0,   80,    2, 0x0a /* Public */,
       8,    0,   81,    2, 0x0a /* Public */,
       9,    1,   82,    2, 0x0a /* Public */,
      11,    0,   85,    2, 0x0a /* Public */,
      12,    0,   86,    2, 0x0a /* Public */,
      13,    0,   87,    2, 0x0a /* Public */,
      14,    0,   88,    2, 0x0a /* Public */,
      15,    0,   89,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 4,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void,
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
        case 6: _t->sendEmoji((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: _t->sendDaku(); break;
        case 8: _t->sendHaixiu(); break;
        case 9: _t->sendWeixiao(); break;
        case 10: _t->sendQi(); break;
        case 11: _t->sendZhuangsha(); break;
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
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
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
