#include "threadSignalSlot.h"
#include <QDebug>
#include <QPushButton>

threadSignalSlot::threadSignalSlot(EPObject *parent) : QThread(parent)
{
//    obj = parent;
    qDebug()<<__PRETTY_FUNCTION__<<QThread::currentThreadId();
}

void threadSignalSlot::run()
{
//    obj->show();
    qDebug()<<__PRETTY_FUNCTION__<<QThread::currentThreadId();

    // 没有这个函数，这个线程执行完了就被销毁。 这个函数可以是线程一直存在，处理循环。
    exec();
//    sendSignal();
}

void threadSignalSlot::sendSignal()
{
    emit emitSignal();
}

EPObject::EPObject(QObject *parent) :
    QObject(parent)
{
    qDebug()<<__PRETTY_FUNCTION__<<QThread::currentThreadId();
}

void EPObject::show()
{
    qDebug()<<__PRETTY_FUNCTION__<<QThread::currentThreadId();
}

void EPObject::receiverSignal()
{
    qDebug()<<__PRETTY_FUNCTION__<<QThread::currentThreadId();
}
/**
    EPObject *obj = new EPObject;
    threadSignalSlot *thread = new threadSignalSlot(obj);
//    thread->start();
    obj->moveToThread(thread);
//    QObject::connect(thread,SIGNAL(emitSignal()),obj,SLOT(receiverSignal()));
    QObject::connect(thread,SIGNAL(emitSignal()),obj,SLOT(receiverSignal()),Qt::QueuedConnection);
//    obj->show();
    thread->sendSignal();
 */

Widget::Widget(QWidget *parent) :QWidget(parent)
{
//    obj = new EPObject(0);
    QPushButton* btn = new QPushButton("xkd",this);
    connect(btn,SIGNAL(clicked()),this,SLOT(slotBtn()));
    connect(this,SIGNAL(emitSignal()),&obj,SLOT(receiverSignal()),Qt::QueuedConnection);

    obj.moveToThread(&thread);

}

void Widget::slotBtn()
{
    thread.start();
    sendSignal();
}

void Widget::sendSignal()
{
    emit emitSignal();
}
