#include "MuteThread.h"
#include <QtGlobal>
#include <iostream>
#include <QDebug>

MuteThread::MuteThread()
{
    stopped = false;
}

void MuteThread::setMessage(const QString &message)
{
    messageStr = message;
}

void MuteThread::run()
{
    forever{
        //如果有进程A，B，当A先start，此时这个run下面的代码会被锁住。B 就不能执行run，当A 执行到unlock后，
        // B 才能执行run。
        mutex.lock();
        if(stopped) {
            stopped = false;
            mutex.unlock();
            break;
        }
        std::cerr << qPrintable(messageStr);
        mutex.unlock();
    }
    std::cerr << std::endl;
//    while (!stopped)
//        std::cerr << qPrintable(messageStr);
//    stopped = false;
//    std::cerr << std::endl;
}

void MuteThread::stop()
{
    mutex.lock();
    stopped = true;
    mutex.unlock();
}

int number=6;
QMutex mutex;
void MyThreadA::run()
{
    //mutex.lock();
    qDebug()<<"AAAA";
    number *= 5;
    sleep(1);  //停1s后再执行下面的语句。
    number /= 4;
    //mutex.unlock();
}

void MyThreadB::run()
{
    mutex.lock();
    qDebug()<<"BBBB";
    number *= 3;
    sleep(1);
    number /= 2;
    mutex.unlock();
}
