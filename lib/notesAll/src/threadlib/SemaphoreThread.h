#ifndef SEMAPHORETHREAD_H
#define SEMAPHORETHREAD_H

#include <QThread>
#include <QSemaphore>
#include <iostream>

class SemaphoreProducer : public QThread
{
public:
    void run();
};

class SemaphoreConsumer : public QThread
{
public:
    void run();
};

#endif // SEMAPHORETHREAD_H
