#include "server.h"
#include <algorithm>

Server::Server(QObject *parent)
{

}

void Server::startServer()
{
    if(!listen(QHostAddress::Any, 1234))
    {
        qDebug() << "Could not start server";
    }
    else
    {
        qDebug() << "Listerning" << QThread::currentThread();
    }
}

void Server::incomingConnection(qintptr socketDescriptor)
{
    qDebug() << socketDescriptor << " Connecting...";

//    QThread* newThread = new QThread();
//    Connection* newConnection = new Connection(socketDescriptor);
//    newConnection->moveToThread(newThread);
//    QObject::connect(newThread, &QThread::started, clients.last(), &Connection::start);
//    QObject::connect(newConnection, &Connection::finished, newThread, &QThread::quit);

//    QObject::connect(newConnection, &Connection::addRowToGUI, this, &Server::addnewRowToGUI);
//    QObject::connect(newConnection, &Connection::messageToGUI, this, &Server::sendNewMessageToGUI);

//    clients.push_back(new Connection(socketDescriptor));
//    clients.last()->moveToThread(newThread);
//    QObject::connect(newThread, &QThread::started, clients.last(), &Connection::start);
//    QObject::connect(clients.last(), &Connection::finished, newThread, &QThread::quit);

//    QObject::connect(clients.last(), &Connection::addRowToGUI, this, &Server::addnewRowToGUI);
//    QObject::connect(clients.last(), &Connection::messageToGUI, this, &Server::sendNewMessageToGUI);

//    newThread->start();

    clientsThreads.push_back(new QThread());
    clients.push_back(new Connection(socketDescriptor));
    clients.last()->moveToThread(clientsThreads.last());
    QObject::connect(clientsThreads.last(), &QThread::started, clients.last(), &Connection::start);
    QObject::connect(clients.last(), &Connection::finished, clientsThreads.last(), &QThread::quit);

    QObject::connect(clients.last(), &Connection::addRowToGUI, this, &Server::addnewRowToGUI);
    QObject::connect(clients.last(), &Connection::messageToGUI, this, &Server::sendNewMessageToGUI);
    QObject::connect(clients.last(), &Connection::deleteFromGUI, this, &Server::removeClient);

    clientsThreads.last()->start();
}


void Server::sendNewMessageToGUI(int SD, QByteArray data)
{
    qDebug() << "From Connection to Server sendMessage";
    emit messageToGUI(SD, data);
    qDebug() << "Stop";
}

void Server::addnewRowToGUI(int SD, QString IP, quint16 port)
{
    qDebug() << "From Connection to Server addnewRow " << QThread::currentThread();
    emit addRowToGUI(SD, IP, port);
    qDebug() << "Stop emitting signal";
}

void Server::removeClient(int SD)
{
    Connection* removableClient = qobject_cast<Connection*>(sender());

    int pos = clients.indexOf(removableClient);
    if(pos == -1)
    {
        qDebug() << "Cannot delet client:" << removableClient->objectName();
    }

    clients.removeAt(pos);
    removableClient->deleteLater();
    emit removeRowGUI(SD);
}

void Server::forcedDeletion(int SD)
{
    auto itr = std::find_if(clients.begin(), clients.end(), [SD](Connection* client)
    {
       return client->getSocketDescriptor() == SD;
    });
    qDebug() << "Forced deletion on server. SD:" << SD << "clients::disconnect is called";
    (*itr)->getSocket()->deleteLater();
}



