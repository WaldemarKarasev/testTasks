#ifndef CALC_H
#define CALC_H

#include <QDebug>
#include <QObject>
#include <QThread>
#include <QTimer>
#include <QRandomGenerator>

// класс, имитирующий вычисление в отдельном потоке
class calc : public QObject
{
    Q_OBJECT

public:
    calc();
    ~calc();


signals:
    void computed(int value);
    void finished();

public slots:
    void consume(int value);
    void start();
    void quit();

private:

    // переменные, используемые для имитации вычисления затратное по времени
    QTimer* m_timer;
    int m_count = 0;
    //

    void timeout();
};

#endif // CALC_H
