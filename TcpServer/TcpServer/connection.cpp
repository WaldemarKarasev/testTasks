#include "connection.h"

#include <QDebug>
#include <QByteArray>

Connection::Connection(int ID, QObject *parent)
    : QObject{parent}
{
    socketDescriptor = ID;
}

// при старте потока вызывается данная функция
void Connection::start()
{
    qInfo() << socketDescriptor << " Starting" << QThread::currentThread();
    socket = new QTcpSocket;
    if(!socket->setSocketDescriptor(socketDescriptor))
    {
        emit error(socket->error());
        return;
    }

    QObject::connect(socket, &QTcpSocket::readyRead, this, &Connection::readyRead);
    QObject::connect(socket, &QTcpSocket::disconnected, this, &Connection::disconnect);

    // отсылаем сигнал для добавления новой строки в таблицу в GUI
    emit addRowToGUI(socketDescriptor, socket->peerAddress().toString(), socket->peerPort());

    qInfo() << socketDescriptor << " Connected";

}

// слот обрабатывающий приходящие сообщения от сокета
void Connection::readyRead()
{
    QByteArray data = socket->readAll();

    qInfo() << socketDescriptor << " Data in:" << data;
    emit messageToGUI(socketDescriptor, data);
}

// слот для разрыва соединения с сокетом и эммитирование сигнала для прекращения работ потока
void Connection::disconnect()
{
    socket->deleteLater();
    emit finished();
    emit deleteFromGUI(socketDescriptor);
    qInfo() << socketDescriptor << " Disconnected";
}

QTcpSocket *Connection::getSocket() const
{
    return socket;
}

int Connection::getSocketDescriptor() const
{
    return socketDescriptor;
}

