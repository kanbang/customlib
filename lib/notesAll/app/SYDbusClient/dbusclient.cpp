#include "dbusclient.h"

#include <QDebug>
#include <QDBusConnection>
#include <QDBusMessage>
#include <QDBusInterface>
#include <QDBusMessage>
#include <QDBusServiceWatcher>
#include <QDBusConnectionInterface>

const QString DBUS_SERVICE_SERVICE ="cmos.testdbus.service";
const QString DBUS_SERVICE_PATH ="/testdbus";
const QString DBUS_SERVICE_INTERFACE ="cmos.testdbus.service";


DBusClient::DBusClient(QObject *parent) :
    QObject(parent)
{
    registerMyTypeDataTypes();

    QDBusConnection::sessionBus().connect(DBUS_SERVICE_SERVICE,
                                          DBUS_SERVICE_PATH,
                                          DBUS_SERVICE_INTERFACE,
                                          "notifyClientDBusChanged",
                                          this,SLOT(getNotifyClientDBusChanged(const QString &)));

    QDBusConnection::sessionBus().connect(DBUS_SERVICE_SERVICE,
                                          DBUS_SERVICE_PATH,
                                          DBUS_SERVICE_INTERFACE,
                                          "notifyDBusTypeChanged",
                                          this,SLOT(getNotifyDBusTypeChanged(const MyType &)));

    QDBusInterface manager(DBUS_SERVICE_SERVICE, "", DBUS_SERVICE_INTERFACE,QDBusConnection::sessionBus());
}

void DBusClient::callService(QString text)
{
    qDebug() << " send DBus : " << text;
    QDBusInterface manager(DBUS_SERVICE_SERVICE,
                           DBUS_SERVICE_PATH,
                           DBUS_SERVICE_INTERFACE,
                           QDBusConnection::sessionBus());

    manager.call("serviceMethod",text);
    getMapClient();
}

void DBusClient::callTypeService(const QString &key, const QString &value)
{
    MyType mytype;
    mytype.key = key;
    mytype.value = value;

    QDBusInterface manager(DBUS_SERVICE_SERVICE,
                           DBUS_SERVICE_PATH,
                           DBUS_SERVICE_INTERFACE,
                           QDBusConnection::sessionBus());

    QDBusPendingReply<MyType> reply = manager.call("serviceTypeMethod", QVariant::fromValue<MyType>(mytype));
    reply.waitForFinished();

    if(!reply.isError()) {
//        qDebug() << "--reply-:--" << reply;
        MyType tmp = reply.value();
        qDebug()<<"========"<<tmp.key;
    } else {
        qDebug() << reply.error();
    }


}

void DBusClient::getNotifyClientDBusChanged(const QString &text)
{
    qDebug() << " getNotifyClientDBusChanged : " << text;
    emit serviceDBusChanged(text);
}

void DBusClient::getNotifyDBusTypeChanged(const MyType &mytype)
{
    qDebug() << "getNotifyDBusTypeChanged : key is " << mytype.key << "  value is " << mytype.value;
}

void DBusClient::getMapClient()
{
    QDBusInterface manager(DBUS_SERVICE_SERVICE,
                           DBUS_SERVICE_PATH,
                           DBUS_SERVICE_INTERFACE,
                           QDBusConnection::sessionBus());

    QDBusPendingReply<QByteArray>reply = manager.call("getMaps");
    QByteArray ba = reply.value();
    QMap<QString,QString> maps;
    QDataStream ds(&ba, QIODevice::ReadOnly);
    ds>>maps;
    qDebug()<<maps.keys()<<"====="<<maps.values();
}
