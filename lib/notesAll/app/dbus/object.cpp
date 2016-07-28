#include "object.h"



QDBusArgument &operator<<(QDBusArgument &argument, const MyType &mytype)
{
    argument.beginStructure();
    argument << mytype.key << mytype.value ;
    argument.endStructure();
    return argument;
}

const QDBusArgument &operator>>(const QDBusArgument &argument, MyType &mytype)
{
    argument.beginStructure();
    argument >> mytype.key >> mytype.value ;
    argument.endStructure();
    return argument;
}

QDataStream &operator<<(QDataStream &ds, const MyType& type)
{
    ds << type.key;
    ds << type.value;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, MyType& type)
{
    ds>>type.key;
    ds>>type.value;
    return ds;
}

object::object(QObject *parent) :
    QObject(parent)
{
    QDBusConnection bus = QDBusConnection::sessionBus();
    if(!bus.registerService("com.test.dbus"))
    {
        qDebug()<<__PRETTY_FUNCTION__<< bus.lastError().message();
        exit(1);
    }
    bus.registerObject("/test", this, QDBusConnection::ExportAllSlots);
}


MyType object::testMyType(MyType type)
{
    qDebug()<<Q_FUNC_INFO;
    type.key = 100;
    type.value = "xingkongdao";
    return type;
}

QByteArray object::testByte()
{
    QByteArray array;
    QDataStream ds(&array, QIODevice::WriteOnly);
    MyType type;
    type.key=1314;
    type.value = "testByte";
    ds<<type;

    return array;
}
