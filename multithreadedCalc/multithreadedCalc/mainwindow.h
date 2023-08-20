#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QThread>
#include <QVector>

#include <QHBoxLayout>
#include <QLabel>
#include <QProgressBar>
#include <QMap>

#include "calc.h"


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
    void display(int value);

private:
    Ui::MainWindow *ui;

    // переменные для хранения созданных потоков и объектов
    QVector<QThread*>       threadVec;
    QVector<calc*>          calcVec;
    QMap<calc*, QProgressBar*> helper;
    int threadsNum;

    // переменные для отображения процесса вычисления GUI
    QVector<QHBoxLayout*>   horizontal_layouts;
    QVector<QLabel*>        labels;
    QVector<QProgressBar*>  progress_bars;
    QWidget*                scrollAreaWidgetContents;
    QGridLayout*            gridLayout;

    // приватные функции для создания и запуска потоков вычислений
    void createThreads(int numOfThreads);
    void createGuiForThreads(int numOfThreads);
    void linkThreadsAndGui(int numOfThreads);
    void startThreads(int numOfThreads);

};
#endif // MAINWINDOW_H
