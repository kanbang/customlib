#ifndef WAITCONDITIONTHREAD_H
#define WAITCONDITIONTHREAD_H

#include <QThread>

class WaitConditionProducer : public QThread
{

public:
    void run();
};

class WaitConditionConsumer : public QThread
{
public:
    void run();
};


//WaitConditionProducer producer;
//WaitConditionConsumer consumer;
//consumer.start();
//producer.start();
//producer.wait();
//consumer.wait();

#endif // WAITCONDITIONTHREAD_H
