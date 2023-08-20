/****************************************************************************
** Meta object code from reading C++ file 'server.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../TcpServer/server.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'server.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Server_t {
    QByteArrayData data[13];
    char stringdata0[125];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Server_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Server_t qt_meta_stringdata_Server = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Server"
QT_MOC_LITERAL(1, 7, 12), // "messageToGUI"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 2), // "SD"
QT_MOC_LITERAL(4, 24, 4), // "data"
QT_MOC_LITERAL(5, 29, 11), // "addRowToGUI"
QT_MOC_LITERAL(6, 41, 2), // "IP"
QT_MOC_LITERAL(7, 44, 4), // "port"
QT_MOC_LITERAL(8, 49, 12), // "removeRowGUI"
QT_MOC_LITERAL(9, 62, 19), // "sendNewMessageToGUI"
QT_MOC_LITERAL(10, 82, 14), // "addnewRowToGUI"
QT_MOC_LITERAL(11, 97, 12), // "removeClient"
QT_MOC_LITERAL(12, 110, 14) // "forcedDeletion"

    },
    "Server\0messageToGUI\0\0SD\0data\0addRowToGUI\0"
    "IP\0port\0removeRowGUI\0sendNewMessageToGUI\0"
    "addnewRowToGUI\0removeClient\0forcedDeletion"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Server[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   49,    2, 0x06 /* Public */,
       5,    3,   54,    2, 0x06 /* Public */,
       8,    1,   61,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    2,   64,    2, 0x0a /* Public */,
      10,    3,   69,    2, 0x0a /* Public */,
      11,    1,   76,    2, 0x0a /* Public */,
      12,    1,   79,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::QByteArray,    3,    4,
    QMetaType::Void, QMetaType::Int, QMetaType::QString, QMetaType::UShort,    3,    6,    7,
    QMetaType::Void, QMetaType::Int,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::QByteArray,    3,    4,
    QMetaType::Void, QMetaType::Int, QMetaType::QString, QMetaType::UShort,    3,    6,    7,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,

       0        // eod
};

void Server::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Server *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->messageToGUI((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QByteArray(*)>(_a[2]))); break;
        case 1: _t->addRowToGUI((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< quint16(*)>(_a[3]))); break;
        case 2: _t->removeRowGUI((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->sendNewMessageToGUI((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QByteArray(*)>(_a[2]))); break;
        case 4: _t->addnewRowToGUI((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< quint16(*)>(_a[3]))); break;
        case 5: _t->removeClient((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->forcedDeletion((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Server::*)(int , QByteArray );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Server::messageToGUI)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Server::*)(int , QString , quint16 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Server::addRowToGUI)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Server::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Server::removeRowGUI)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Server::staticMetaObject = { {
    QMetaObject::SuperData::link<QTcpServer::staticMetaObject>(),
    qt_meta_stringdata_Server.data,
    qt_meta_data_Server,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Server::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Server::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Server.stringdata0))
        return static_cast<void*>(this);
    return QTcpServer::qt_metacast(_clname);
}

int Server::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTcpServer::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void Server::messageToGUI(int _t1, QByteArray _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Server::addRowToGUI(int _t1, QString _t2, quint16 _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Server::removeRowGUI(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
