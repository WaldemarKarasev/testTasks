#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QtSql/QSqlTableModel>
#include <QDebug>
#include <QtSql>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_AddButton_clicked();

    void on_tableView_clicked(const QModelIndex &index);

    void on_DeleteButton_clicked();

    void on_comboBox_currentIndexChanged(int index);

    void on_submitButton_clicked();

    void on_revertButton_clicked();

    void on_reselectTable_clicked();

private:
    Ui::MainWindow *ui;

    // БД подгружаемая из файла cities.db3
    QSqlDatabase db;
    // Табличный виджет для отображения содержимого таблицы
    QSqlTableModel* model;
    // переменная для хранения номера(положения) выбранной строки
    int currentRow;
};
#endif // MAINWINDOW_H
