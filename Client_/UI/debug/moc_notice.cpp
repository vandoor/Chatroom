/****************************************************************************
** Meta object code from reading C++ file 'notice.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../GUI/notice.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'notice.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Notice_t {
    QByteArrayData data[7];
    char stringdata0[74];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Notice_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Notice_t qt_meta_stringdata_Notice = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Notice"
QT_MOC_LITERAL(1, 7, 14), // "agreeNewFriend"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 8), // "friendID"
QT_MOC_LITERAL(4, 32, 10), // "friendName"
QT_MOC_LITERAL(5, 43, 15), // "flashFriendList"
QT_MOC_LITERAL(6, 59, 14) // "flashGroupList"

    },
    "Notice\0agreeNewFriend\0\0friendID\0"
    "friendName\0flashFriendList\0flashGroupList"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Notice[] = {

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
       1,    2,   29,    2, 0x06 /* Public */,
       5,    0,   34,    2, 0x06 /* Public */,
       6,    0,   35,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    3,    4,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Notice::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Notice *_t = static_cast<Notice *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->agreeNewFriend((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 1: _t->flashFriendList(); break;
        case 2: _t->flashGroupList(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Notice::*_t)(QString , QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Notice::agreeNewFriend)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (Notice::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Notice::flashFriendList)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (Notice::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Notice::flashGroupList)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject Notice::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Notice.data,
      qt_meta_data_Notice,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Notice::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Notice::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Notice.stringdata0))
        return static_cast<void*>(const_cast< Notice*>(this));
    return QWidget::qt_metacast(_clname);
}

int Notice::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void Notice::agreeNewFriend(QString _t1, QString _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Notice::flashFriendList()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void Notice::flashGroupList()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
