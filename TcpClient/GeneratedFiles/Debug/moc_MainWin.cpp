/****************************************************************************
** Meta object code from reading C++ file 'MainWin.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../MainWin.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MainWin.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainWin_t {
    QByteArrayData data[13];
    char stringdata0[205];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWin_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWin_t qt_meta_stringdata_MainWin = {
    {
QT_MOC_LITERAL(0, 0, 7), // "MainWin"
QT_MOC_LITERAL(1, 8, 15), // "onNewConnection"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 19), // "onSocketStateChange"
QT_MOC_LITERAL(4, 45, 28), // "QAbstractSocket::SocketState"
QT_MOC_LITERAL(5, 74, 11), // "socketState"
QT_MOC_LITERAL(6, 86, 17), // "onClientConnected"
QT_MOC_LITERAL(7, 104, 20), // "onClientDisconnected"
QT_MOC_LITERAL(8, 125, 17), // "onSocketReadyRead"
QT_MOC_LITERAL(9, 143, 18), // "StartListen_Button"
QT_MOC_LITERAL(10, 162, 17), // "StopListen_Button"
QT_MOC_LITERAL(11, 180, 11), // "Send_Button"
QT_MOC_LITERAL(12, 192, 12) // "Clear_Button"

    },
    "MainWin\0onNewConnection\0\0onSocketStateChange\0"
    "QAbstractSocket::SocketState\0socketState\0"
    "onClientConnected\0onClientDisconnected\0"
    "onSocketReadyRead\0StartListen_Button\0"
    "StopListen_Button\0Send_Button\0"
    "Clear_Button"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWin[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x08 /* Private */,
       3,    1,   60,    2, 0x08 /* Private */,
       6,    0,   63,    2, 0x08 /* Private */,
       7,    0,   64,    2, 0x08 /* Private */,
       8,    0,   65,    2, 0x08 /* Private */,
       9,    0,   66,    2, 0x08 /* Private */,
      10,    0,   67,    2, 0x08 /* Private */,
      11,    0,   68,    2, 0x08 /* Private */,
      12,    0,   69,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWin::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWin *_t = static_cast<MainWin *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onNewConnection(); break;
        case 1: _t->onSocketStateChange((*reinterpret_cast< QAbstractSocket::SocketState(*)>(_a[1]))); break;
        case 2: _t->onClientConnected(); break;
        case 3: _t->onClientDisconnected(); break;
        case 4: _t->onSocketReadyRead(); break;
        case 5: _t->StartListen_Button(); break;
        case 6: _t->StopListen_Button(); break;
        case 7: _t->Send_Button(); break;
        case 8: _t->Clear_Button(); break;
        default: ;
        }
    }
}

const QMetaObject MainWin::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_MainWin.data,
      qt_meta_data_MainWin,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MainWin::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWin::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MainWin.stringdata0))
        return static_cast<void*>(const_cast< MainWin*>(this));
    return QWidget::qt_metacast(_clname);
}

int MainWin::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
