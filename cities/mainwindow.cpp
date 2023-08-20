#include "mainwindow.h"
#include "./ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // подгружаем таблицу из файла в переменную db
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setHostName("127.0.0.1");
    db.setDatabaseName("../../db/cities.db3");

    // открываем БД
    if (db.open())
    {
        // если открытие успешно, то отображаем содержимое в model
        ui->statusbar->showMessage("Successful database connection: " + db.databaseName());
        model = new QSqlTableModel(this, db);
        model->setTable("cities");

        // сохранение изменений в таблице только при вызове метода model->submitAll()
        model->setEditStrategy(QSqlTableModel::OnManualSubmit);

        // читаем данные из БД в model
        model->select();

        // отображаем данные в tableView
        ui->tableView->setModel(model);
        ui->tableView->setColumnHidden(0, true);
        ui->tableView->setColumnHidden(1, true);
        ui->tableView->setColumnHidden(2, true);

        // выделение построчно
        ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
        // включение сортировки по столбцам
        ui->tableView->setSortingEnabled(true);
    }
    else
    {
        // при ошибке выводим в statusbar сообщение ошибки
        ui->statusbar->showMessage("Connection error: " + db.lastError().databaseText());
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

// слот для определения текущей строки
void MainWindow::on_tableView_clicked(const QModelIndex &index)
{
    currentRow = index.row();
}

// слот фильтрации данных из БД по населению
void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    qDebug() << index;
    switch (index)
    {
    case 0:
        model->setFilter("population > 0");
        break;
    case 1:
        model->setFilter("population > 1000");
        break;
    case 2:
        model->setFilter("population > 10000");
        break;
    case 3:
        model->setFilter("population > 25000");
        break;
    case 4:
        model->setFilter("population > 50000");
        break;
    case 5:
        model->setFilter("population > 100000");
        break;
    case 6:
        model->setFilter("population > 250000");
        break;
    case 7:
        model->setFilter("population > 500000");
        break;
    case 8:
        model->setFilter("population > 1000000");
        break;
    case 9:
        model->setFilter("population > 2000000");
        break;
    case 10:
        model->setFilter("population > 20000000");
    default: // nop
        break;
    }
    model->select();
}

// слот для вставки новой строки в БД
void MainWindow::on_AddButton_clicked()
{
    qDebug() << "inserting row:" << model->insertRow(model->rowCount());
}

// удаление строки из БД
void MainWindow::on_DeleteButton_clicked()
{
    qDebug() << "deleting row:" << model->removeRow(currentRow);
    model->select();
}

// подтверждение изменений в базе даных
void MainWindow::on_submitButton_clicked()
{
    model->submitAll();
}

// отмена изменений, которые совершены до вызова метода model->submitAll()
void MainWindow::on_revertButton_clicked()
{
    model->revertAll();
}

// перезаполнение model данными из БД
void MainWindow::on_reselectTable_clicked()
{
    model->select();
}



