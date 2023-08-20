#ifndef CONNECTION_H
#define CONNECTION_H

#include <QObject>
#include <QThread>
#include <QTcpSocket>
#include <QHostAddress>

// класс для обработки соединения в отдельном потоке
class Connection : public QObject
{
    Q_OBJECT
public:
    explicit Connection(int ID, QObject *parent = nullptr);

    int getSocketDescriptor() const;

    QTcpSocket *getSocket() const;

signals:
    void error(QTcpSocket::SocketError socketerror);
    void messageToGUI(int SD, QByteArray data);
    void addRowToGUI(int SD, QString IP, quint16 port);
    void finished();
    void deleteFromGUI(int SD);

public slots:
    void start();
    void readyRead();
    void disconnect();

private:
    // переменные сокета и его дескриптора
    QTcpSocket* socket;
    int socketDescriptor;
};

#endif // CONNECTION_H
