#include "GlodonThread.h"
#include <QDebug>
GlodonThread::GlodonThread(QObject *parent) :
    QThread(parent)
{
}

void GlodonThread::run()
{
    int i = 0;
    while(i < 10000)
    {
        qDebug()<<__FUNCTION__<< i;
        i++;
    }
}
