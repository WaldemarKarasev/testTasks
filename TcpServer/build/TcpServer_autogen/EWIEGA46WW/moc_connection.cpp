/****************************************************************************
** Meta object code from reading C++ file 'connection.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../TcpServer/connection.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'connection.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Connection_t {
    QByteArrayData data[16];
    char stringdata0[145];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Connection_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Connection_t qt_meta_stringdata_Connection = {
    {
QT_MOC_LITERAL(0, 0, 10), // "Connection"
QT_MOC_LITERAL(1, 11, 5), // "error"
QT_MOC_LITERAL(2, 17, 0), // ""
QT_MOC_LITERAL(3, 18, 23), // "QTcpSocket::SocketError"
QT_MOC_LITERAL(4, 42, 11), // "socketerror"
QT_MOC_LITERAL(5, 54, 12), // "messageToGUI"
QT_MOC_LITERAL(6, 67, 2), // "SD"
QT_MOC_LITERAL(7, 70, 4), // "data"
QT_MOC_LITERAL(8, 75, 11), // "addRowToGUI"
QT_MOC_LITERAL(9, 87, 2), // "IP"
QT_MOC_LITERAL(10, 90, 4), // "port"
QT_MOC_LITERAL(11, 95, 8), // "finished"
QT_MOC_LITERAL(12, 104, 13), // "deleteFromGUI"
QT_MOC_LITERAL(13, 118, 5), // "start"
QT_MOC_LITERAL(14, 124, 9), // "readyRead"
QT_MOC_LITERAL(15, 134, 10) // "disconnect"

    },
    "Connection\0error\0\0QTcpSocket::SocketError\0"
    "socketerror\0messageToGUI\0SD\0data\0"
    "addRowToGUI\0IP\0port\0finished\0deleteFromGUI\0"
    "start\0readyRead\0disconnect"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Connection[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x06 /* Public */,
       5,    2,   57,    2, 0x06 /* Public */,
       8,    3,   62,    2, 0x06 /* Public */,
      11,    0,   69,    2, 0x06 /* Public */,
      12,    1,   70,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      13,    0,   73,    2, 0x0a /* Public */,
      14,    0,   74,    2, 0x0a /* Public */,
      15,    0,   75,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::Int, QMetaType::QByteArray,    6,    7,
    QMetaType::Void, QMetaType::Int, QMetaType::QString, QMetaType::UShort,    6,    9,   10,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    6,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Connection::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Connection *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->error((*reinterpret_cast< QTcpSocket::SocketError(*)>(_a[1]))); break;
        case 1: _t->messageToGUI((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QByteArray(*)>(_a[2]))); break;
        case 2: _t->addRowToGUI((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< quint16(*)>(_a[3]))); break;
        case 3: _t->finished(); break;
        case 4: _t->deleteFromGUI((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->start(); break;
        case 6: _t->readyRead(); break;
        case 7: _t->disconnect(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Connection::*)(QTcpSocket::SocketError );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Connection::error)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Connection::*)(int , QByteArray );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Connection::messageToGUI)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Connection::*)(int , QString , quint16 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Connection::addRowToGUI)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Connection::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Connection::finished)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (Connection::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Connection::deleteFromGUI)) {
                *result = 4;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Connection::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_Connection.data,
    qt_meta_data_Connection,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Connection::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Connection::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Connection.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Connection::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void Connection::error(QTcpSocket::SocketError _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Connection::messageToGUI(int _t1, QByteArray _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Connection::addRowToGUI(int _t1, QString _t2, quint16 _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Connection::finished()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void Connection::deleteFromGUI(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
