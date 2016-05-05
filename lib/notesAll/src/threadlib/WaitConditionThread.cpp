#include "WaitConditionThread.h"
#include <QTime>
#include <QWaitCondition>
#include <QMutex>
#include <QDebug>

const int otherDataSize = 100000;
const int otherBufferSize = 8192;
char  waitConditionBuffer[otherBufferSize];

QWaitCondition bufferNotEmpty;
QWaitCondition bufferNotFull;
QMutex myMutex;
int numUsedBytes = 0;

void WaitConditionProducer::run()
{
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    for(int i = 0;i<otherDataSize;i++)
    {
        myMutex.lock();
        if(numUsedBytes == otherBufferSize)
            bufferNotFull.wait(&myMutex);
        myMutex.unlock();

        waitConditionBuffer[i%otherBufferSize] = "ACGT"[(int)qrand()%4];
        myMutex.lock();
        ++numUsedBytes;
        qDebug()<<"produce "<<numUsedBytes;
        bufferNotEmpty.wakeAll();
        myMutex.unlock();
    }
}

void WaitConditionConsumer::run()
{
    for(int i = 0; i < otherDataSize ;++i)
    {
        myMutex.lock();
        if(numUsedBytes== 0)
            bufferNotEmpty.wait(&myMutex);
        myMutex.unlock();
        fprintf(stderr,"%c",waitConditionBuffer[i%otherBufferSize]);
        myMutex.lock();
        --numUsedBytes;
        qDebug()<<"consumer "<<numUsedBytes;
        bufferNotFull.wakeAll();
        myMutex.unlock();
    }

    fprintf(stderr,"\n");
}
