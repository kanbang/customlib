#include "AcThreadWindowApp.h"
#include <QDebug>

AcThread::AcThread(QWidget *pW,QMutex *mu)
{
    m_pW = pW;
    mutex = mu;
    qDebug()<<__PRETTY_FUNCTION__<<QThread::currentThreadId();
    moveToThread(this);  //把槽函数的运行放到当前线程来运行。窗口还有响应。对AcThread::show有用，可以把这个函数放在QAcThread这个进程
                         // 调用，但是对m_pW中的showData就没有用，因为showData是主线程的。他是在主线程上被调用的。
    AcThreadWindowApp* window = dynamic_cast<AcThreadWindowApp*>(m_pW);
    if(window)
        connect(window,SIGNAL(valueChanged()),this,SLOT(show()));
    connect(m_pW,SIGNAL(valueChanged()),m_pW,SLOT(showData()));
}
void AcThread::run()
{
    AcThreadWindowApp* window = dynamic_cast<AcThreadWindowApp*>(m_pW);
    emit showValue();
    if(window)
        emit window->emitSignal();
    show();
    qDebug()<<__PRETTY_FUNCTION__<<QThread::currentThreadId();
    QWidget *w = new QWidget(0);
    w->show();
    w->moveToThread(this);
}

void AcThread::show()
{
    mutex->lock();
    int i=0;
//    while(i < 1000)
    {
        qDebug()<<objectName() <<" = "<<i;
    }

    mutex->unlock();
}

AcLineEdit::AcLineEdit(QWidget *parent) : QLineEdit(parent)
{

}

bool AcLineEdit::event(QEvent *e)
{
    if(e->type() == QEvent::MouseButtonPress){
        qDebug()<<"xkd";
        e->ignore();
    }
    QLineEdit::event(e);
}

AcThreadWindowApp::AcThreadWindowApp(QWidget *parent) :
    QWidget(parent)
{
    str = QString();
    QMutex *mu = new QMutex;   //互斥量只能是一个。要不然你创建两个进程，那就是两个互斥量。
    threadA = new AcThread(this,mu);
    threadB = new AcThread(this,mu);
    threadA->setObjectName("threadA");
    threadB->setObjectName("threadB");
    btnA = new QPushButton("ThreadA",this);
    btnB = new QPushButton("ThreadB",this);
    AcLineEdit * lineEdit = new AcLineEdit(this);
    btnA->setGeometry(20,30,60,30);
    btnB->setGeometry(120,30,60,30);
    lineEdit->setGeometry(70,70,80,40);
    connect(btnA,SIGNAL(clicked()),this,SLOT(slotThreadA()));
    connect(btnB,SIGNAL(clicked()),this,SLOT(slotThreadB()));
    ab = false;
    _val = 0;
    qDebug()<<__PRETTY_FUNCTION__<<QThread::currentThreadId();
    QWidget *w = new QWidget(0);
//    setWindowFlags(windowFlags() & ~Qt::WindowMaximizeButtonHint);
//    setWindowFlags(windowFlags() & ~Qt::WindowStaysOnTopHint);
}

bool AcThreadWindowApp::event(QEvent *event)
{
    if(event->type() == QEvent::MouseButtonPress)
        qDebug()<<"AcThreadWindowApp::event";
    QWidget::event(event);
}

void AcThreadWindowApp::slotThreadA()
{
    ab = true;
    threadA->start();
}

void AcThreadWindowApp::slotThreadB()
{
    ab = false;
    threadB->start();
}

void AcThreadWindowApp::showData()
{
    int i = 1;
//    while(i)
    {
        qDebug()<<"i = "<<i;
    }
}

void AcThreadWindowApp::emitSignal()
{
    emit valueChanged();
}
