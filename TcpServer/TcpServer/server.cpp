#include "server.h"
#include <algorithm>

Server::Server(QObject *parent)
{

}

// старт сервера, ставим на прослушивание серверный сокет
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

// обработка нового соединения и создания для него отдельного потока
void Server::incomingConnection(qintptr socketDescriptor)
{
    qDebug() << socketDescriptor << " Connecting...";

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


// обработка сигнала о новом сообщении от клиента и передача в GUI для его отображения
void Server::sendNewMessageToGUI(int SD, QByteArray data)
{
    qDebug() << "From Connection to Server sendMessage";
    emit messageToGUI(SD, data);
    qDebug() << "Stop";
}

// обработка сигнала о новом соединении и запрос на добавление новой строки в табдицу GUI
void Server::addnewRowToGUI(int SD, QString IP, quint16 port)
{
    qDebug() << "From Connection to Server addnewRow " << QThread::currentThread();
    emit addRowToGUI(SD, IP, port);
    qDebug() << "Stop emitting signal";
}

// удаление клиента. Данная функция вызывается при эммитирования сигнала от клиента о закрытии соединения
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

// принудительное удаление клиента. Данная функция вызывается при нажатии кнопки discnnect в GUI, что вызывает принудительное закрытие соединения
void Server::forcedDeletion(int SD)
{
    auto itr = std::find_if(clients.begin(), clients.end(), [SD](Connection* client)
    {
       return client->getSocketDescriptor() == SD;
    });
    qDebug() << "Forced deletion on server. SD:" << SD << "clients::disconnect is called";
    (*itr)->getSocket()->deleteLater();
}



