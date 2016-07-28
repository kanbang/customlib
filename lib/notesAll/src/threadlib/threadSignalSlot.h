#ifndef THREADSIGNALSLOT_H
#define THREADSIGNALSLOT_H
#include <QThread>
#include <QWidget>

class EPObject;
class threadSignalSlot : public QThread
{
    Q_OBJECT

public:
    threadSignalSlot(EPObject *parent = 0);

    void sendSignal();

protected:
    void run();

signals:
    void emitSignal();

private:
    EPObject *obj;
};

class EPObject : public QObject
{
    Q_OBJECT

public:
    EPObject(QObject *parent = 0);
    void show();

public slots:
    void receiverSignal();
};

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    void sendSignal();

signals:
    void emitSignal();

public slots:
    void slotBtn();

private:
    EPObject obj;
    threadSignalSlot thread;
};

#endif // THREADSIGNALSLOT_H
