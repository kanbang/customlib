
#include <QCoreApplication>
#include "object.h"

//#define KIND

int main(int argc, char* argv[])
{
    QCoreApplication app(argc, argv);

#ifdef KIND
    registerMyTypeDataTypes();
    qDebug()<<"===================";
    object* obj = new object();
#else
    registerMyTypeDataTypes();
    qDebug()<<"=================+";
    QDBusInterface iface("com.test.dbus", "/test", "com.test.dbus");

    MyType type;
    type.key = 1;
    type.value = "xkd";
    QDBusReply<MyType> reply = iface.call("testMyType", QVariant::fromValue<MyType>(type));
    if(reply.isValid())
    {
        MyType tmp = reply.value();
        qDebug()<<Q_FUNC_INFO<<tmp.key;
    }
    else
    {
    }

    QDBusReply<QByteArray> byteReply = iface.call("testByte");
    if(byteReply.isValid())
    {
        QByteArray byte;
        byte = byteReply.value();
        MyType type;
        QDataStream ds(&byte, QIODevice::ReadOnly);
        ds>>type;
        qDebug()<<"byte==========="<<type.value;
    }
#endif

    return app.exec();
}
