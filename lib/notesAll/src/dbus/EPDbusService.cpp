#include "EPDbusService.h"
#include <QtDBus>

EPService::EPService()
{
}

void EPService::execute()
{
    QDBusConnection dbus = QDBusConnection::sessionBus();

    if(!dbus.registerService("test.dbus.service"))
    {
        qDebug()<<" ====dbus connit error ====";
    }


    EPObject *obj = new EPObject();
    obj->setObjectName("xingkongdao");


    QString str = obj->objectName();
    const char* ch = str.toStdString().c_str();
    qDebug()<<__PRETTY_FUNCTION__<<str << ch;
    dbus.registerObject("/test", obj, QDBusConnection::ExportAllContents);
//    dbus.registerObject("/test/dbus/path", obj, QDBusConnection::ExportAllContents);
}

void EPService::execClient()
{
    QDBusInterface *interface = new QDBusInterface("test.dbus.service", "/test",
                                                   "test.dbus.interface");

    EPObject_One* obj = new EPObject_One();
    QObject::connect(interface, SIGNAL(testChanged()), obj, SLOT(oneSlot()));

    if(!interface->isValid())
    {
        qDebug()<<"interface error ========";
        return ;
    }

    QDBusReply<void> reply = interface->call("adaptTestDbus");


    if(reply.isValid())
    {
        qDebug()<<"interface successfully";
    }
}


EPObject::EPObject(QObject *parent) : QObject(parent)
{
    new Adaptor(this);
//    new anAdaptor(this);
    QDBusConnection::sessionBus().registerObject("/test", this);
}

void EPObject::testDbus()
{
    qDebug()<<__PRETTY_FUNCTION__<<this;
//    emit testChanged();
}

void EPObject::receiveChanged()
{
    qDebug()<<__PRETTY_FUNCTION__<<this;
}

Adaptor::Adaptor(QObject *parent) : QDBusAbstractAdaptor(parent)
{
    _obj = (EPObject*)parent;
//    connect(_obj,SIGNAL(testChanged()), this,SIGNAL(testChanged()));
}

void Adaptor::adaptTestDbus()
{
//    emit testChanged();
    qDebug()<<__PRETTY_FUNCTION__<<this;
    if(_obj)
    {
        _obj->testDbus();
    }
}


QString Adaptor::adaptOutput(QString str, int value)
{
    qDebug()<<__PRETTY_FUNCTION__<<str <<"===value==="<<value<<this;
}


anAdaptor::anAdaptor(QObject *parent) : QDBusAbstractAdaptor(parent)
{
    _obj = (EPObject*)parent;
}

void anAdaptor::adaptTestDbus()
{
    emit testChanged();
    qDebug()<<__PRETTY_FUNCTION__<<this;
    if(_obj)
    {
        _obj->testDbus();
    }
}


QString anAdaptor::adaptOutput(QString str, int value)
{
    qDebug()<<__PRETTY_FUNCTION__<<str <<"===value==="<<value<<this;
}



SYThreadConnect::SYThreadConnect(QObject *parent) :
    QObject(parent)
{
    oneThread* thread = new oneThread(this);

    QThread *mainThread = new QThread(this);

    this->moveToThread(mainThread);

    mainThread->start();
    thread->start();
//    emit emitsignal();
}

void SYThreadConnect::sendSignal()
{
    emit emitsignal();
}


oneThread::oneThread(SYThreadConnect *connect) :QThread(connect)
{
    _con = connect;
}

void oneThread::run()
{
    connect(_con, SIGNAL(emitsignal()), _con, SLOT(testThread()), Qt::BlockingQueuedConnection);
    _con->sendSignal();

    qDebug()<<__PRETTY_FUNCTION__;
}


void SYThreadConnect::testThread()
{
    qDebug()<<__PRETTY_FUNCTION__;
}



EPObject_One::EPObject_One(QObject *parent)
    :QObject(parent)
{

}

void EPObject_One::oneSlot()
{
    qDebug()<<Q_FUNC_INFO<<"===="<<this;
}
