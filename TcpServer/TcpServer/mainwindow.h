#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMap>

#include "server.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();



public slots:
    void addNewConnectionRow(int SD, QString IP, quint16 port);
    void receiveNewMessage(int SD, QByteArray data);
    void removeRow(int SD);

private slots:
    void on_forced_deletion_clicked();

signals:
    void forcedDeletion(int SD);

private:
    Ui::MainWindow *ui;

    // Переменная сервера
    Server* server;
    int clientsCount = 0;

    // переменная, которая используется для определения строчки для текущего соединения
    // SDtoRow[i] = SD;
    // где i - номер строчки, SD - дескриптов сокета
    QVector<int> SDtoRow;

    void reloadTableOnClientDeletion(int index);
};
#endif // MAINWINDOW_H
