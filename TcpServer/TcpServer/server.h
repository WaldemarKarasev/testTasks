#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QTcpServer>
#include <QList>

#include "connection.h"

// класс обрабатывающий входящие соединения и создающий новые потоки для каждого клиента
class Server : public QTcpServer
{
    Q_OBJECT
public:
    explicit Server(QObject *parent = nullptr);
    void startServer();

public slots:
    void sendNewMessageToGUI(int SD, QByteArray data);
    void addnewRowToGUI(int SD, QString IP, quint16 port);
    void removeClient(int SD);
    void forcedDeletion(int SD);
signals:
    void messageToGUI(int SD, QByteArray data);
    void addRowToGUI(int SD, QString IP, quint16 port);
    void removeRowGUI(int SD);

protected:
    void incomingConnection(qintptr socketDescriptor);

private:
    // переменные для хранения клинтов и их потоков
    QList<Connection*> clients;
    QList<QThread*> clientsThreads;
};
#endif // SERVER_H
