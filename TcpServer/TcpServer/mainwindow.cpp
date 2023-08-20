#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QWidget>
#include <QPushButton>
#include <QStringList>
#include <QLabel>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QStringList headers;
    headers << "IP address" << "Port" << "message" << "Disconnect";

    ui->tableWidget->setColumnCount(4);
    ui->tableWidget->setHorizontalHeaderLabels(headers);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    qDebug() << "MainWindowcStarting..." << QThread::currentThread();
    server = new Server(this);
    server->startServer();
    QObject::connect(server, &Server::messageToGUI, this, &MainWindow::receiveNewMessage);
    QObject::connect(server, &Server::addRowToGUI, this, &MainWindow::addNewConnectionRow);
    QObject::connect(server, &Server::removeRowGUI, this, &MainWindow::removeRow);
    QObject::connect(this, &MainWindow::forcedDeletion, server, &Server::forcedDeletion);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addNewConnectionRow(int SD, QString IP, quint16 port)
{
    qDebug() << "From server to GUI addnewRow";
    clientsCount++;
    ui->tableWidget->setRowCount(clientsCount);
    ui->tableWidget->setCellWidget(ui->tableWidget->rowCount() - 1, 0, new QLabel(IP));
    ui->tableWidget->setCellWidget(ui->tableWidget->rowCount() - 1, 1, new QLabel(QString::number(port)));
    ui->tableWidget->setCellWidget(ui->tableWidget->rowCount() - 1, 2, new QLabel("no msg"));
    QWidget* pWidget = new QWidget();
    QPushButton* button = new QPushButton();
    button->setText("disconnect");
    QHBoxLayout* pLayout = new QHBoxLayout(pWidget);
    pLayout->addWidget(button);
    pLayout->setAlignment(Qt::AlignCenter);
    pLayout->setContentsMargins(0, 0, 0, 0);
    pWidget->setLayout(pLayout);
    ui->tableWidget->setCellWidget(ui->tableWidget->rowCount() - 1, 3, button);

    QObject::connect(button, &QPushButton::clicked, this, &MainWindow::on_forced_deletion_clicked);

    SDtoRow.push_back(SD);
}

void MainWindow::receiveNewMessage(int SD, QByteArray data)
{
    qDebug() << "From server to GUI receiveNewMessage";
    int pos = SDtoRow.indexOf(SD);
    QLabel* tmp = (QLabel*)ui->tableWidget->cellWidget(pos, 2);
    if(tmp == nullptr)
    {
        qDebug() << "No current label";
    }
    else
    {
        tmp->setText(QString(data));
    }
}

void MainWindow::removeRow(int SD)
{
    qDebug() << "remove Client SD:" << SD;
    int index = SDtoRow.indexOf(SD);
    ui->tableWidget->removeRow(SDtoRow.indexOf(SD));
    clientsCount--;
    reloadTableOnClientDeletion(index);
}

void MainWindow::on_forced_deletion_clicked()
{
    QPushButton* tmpButton = qobject_cast<QPushButton*>(sender());
    int tmpSD = 0;
    for(int i = 0; i < ui->tableWidget->rowCount(); ++i)
    {
        qDebug() << ui->tableWidget->cellWidget(i, 3)->childrenRect() << " " << tmpButton;
        if(ui->tableWidget->cellWidget(i, 3) == tmpButton)
        {
            tmpSD = i;
            qDebug() << "Row of the button is " << i;
        }
    }

    emit forcedDeletion(SDtoRow[tmpSD]);
}

void MainWindow::reloadTableOnClientDeletion(int index)
{
    qDebug() << "reloadTableOnClientDeletion";
    SDtoRow.remove(index);

}
