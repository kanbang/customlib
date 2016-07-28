#ifndef MUTETHREAD_H
#define MUTETHREAD_H
#include <QThread>
#include <QMutex>

/*****************
  @ 和线程有关的类QMutex ，QReadWriteLock， QSemaphore(信号，信号量)， QWaitCondition

  *********************/
class MuteThread : public QThread
{
    Q_OBJECT
public:
    explicit MuteThread();

    void setMessage(const QString &message);
    void stop();

protected:
    void run();

private:
    QString messageStr;
    volatile bool stopped;
    QMutex mutex;
    
};

class MyThreadA : public QThread
{
public:
    void run();
};
class MyThreadB: public QThread
{
public:
    void run();
};

#endif // MUTETHREAD_H
