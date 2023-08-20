#include "calc.h"

calc::calc()
{
    qInfo() << "Constructed" << QThread::currentThread();
}

calc::~calc()
{
    qInfo() << "Deconstructed" << QThread::currentThread();
}


void calc::consume(int value)
{
    qInfo() << this << "Consumig" << value << QThread::currentThread();
}

// Объекты данного класса запускаются в отдельном потоке
// При старте нового потока запускается функция start()
void calc::start()
{
    qInfo() << this << "Starting" << QThread::currentThread();
    m_timer = new QTimer(this);

    // соединяем сигнал таймера и слота cdlc::timeout для имитации индикации прогрессса вычисления
    connect(m_timer, &QTimer::timeout, this, &calc::timeout);
    qInfo() << this << "Starting timer" << QThread::currentThread();
    m_timer->setInterval(10);
    m_timer->start();

}

// Данная функция вызывается при окончании имитации вычисления.
// Функция quit() необходима для выдачи сигнала на завершения работы потока, в котором работал данный объект
void calc::quit()
{
    qInfo() << this << "Quitting" << QThread::currentThread();
    m_timer->stop();
    emit finished();
}

// Функция передающая индикацию о прогрессе вычисления в main поток
void calc::timeout()
{
    m_count++;
    qInfo() << this << "Producing" << m_count << QThread::currentThread();
    emit computed(m_count);
    if(m_count == 100) quit();
}
