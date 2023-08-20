#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // задаем количество потоков
    threadsNum = 50;
    createThreads(threadsNum);
    createGuiForThreads(threadsNum);
    linkThreadsAndGui(threadsNum);
    startThreads(threadsNum);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// создание потоков
void MainWindow::createThreads(int numOfThreads)
{
    threadVec.reserve(numOfThreads);
    calcVec.reserve(numOfThreads);

    for (int i = 0; i < numOfThreads; ++i)
    {
        QThread* tmpThread = new QThread();
        calc* tmpCalc = new calc();
        threadVec.push_back(tmpThread);
        calcVec.push_back(tmpCalc);
        calcVec[i]->moveToThread(threadVec[i]);

        threadVec[i]->setObjectName("Thread" + QString::number(i));
        calcVec[i]->setObjectName("calc" + QString::number(i));
        QObject::connect(threadVec[i], &QThread::started, calcVec[i], &calc::start);
        QObject::connect(calcVec[i], &calc::finished, threadVec[i], &QThread::quit);
    }
}

// создание в GUI индикации для каждого потока
void MainWindow::createGuiForThreads(int numOfThreads)
{

    for (int i = 0; i < numOfThreads; ++i)
    {
        QHBoxLayout* horizontalLayout = new QHBoxLayout();

        horizontal_layouts.push_back(horizontalLayout);

        QLabel* newLabel = new QLabel(threadVec[i]->objectName() + "::" + calcVec[i]->objectName(), ui->scrollAreaWidgetContents);
        labels.push_back(newLabel);
        labels[i]->setObjectName("label" + QString::number(i));
        horizontal_layouts[i]->addWidget(labels[i]);

        progress_bars.push_back(new QProgressBar(ui->scrollAreaWidgetContents));
        progress_bars[i]->setObjectName("progressBar" + QString::number(i));
        progress_bars[i]->setValue(0);
        horizontal_layouts[i]->addWidget(progress_bars[i]);

        ui->gridLayout->addLayout(horizontal_layouts[i], i, 0, 1, 1);
    }

}

// соединение объекта из потока и GUI элемента для индикации прогрессса работы потока
void MainWindow::linkThreadsAndGui(int numOfThreads)
{
    for (int i = 0; i < numOfThreads; ++i)
    {
        QObject::connect(calcVec[i], &calc::computed, this, &MainWindow::display);
        helper.insert(calcVec[i], progress_bars[i]);
    }

}

// запуск потоков в работу
void MainWindow::startThreads(int numOfThreads)
{
    for (int i = 0; i < numOfThreads;++i)
    {
        threadVec[i]->start();
    }
}


void MainWindow::display(int value)
{
    calc* senderCalc = qobject_cast<calc*>(sender());
    helper.value(senderCalc)->setValue(value);
}
