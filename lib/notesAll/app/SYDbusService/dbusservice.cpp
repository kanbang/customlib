#include "dbusservice.h"
#include <QDebug>

#include <QDBusConnection>
#include <QDBusMessage>
#include <QDBusServiceWatcher>
#include <QDBusConnectionInterface>

const QString DBUS_SERVICE_SERVICE ="cmos.testdbus.service";
const QString DBUS_SERVICE_PATH ="/testdbus";
const QString DBUS_SERVICE_INTERFACE ="cmos.testdbus.service";

DBusService::DBusService(QObject *parent) :
    QObject(parent)
{
    registerMyTypeDataTypes();

    QDBusConnection bus = QDBusConnection::sessionBus();
    if (!bus.registerService(DBUS_SERVICE_SERVICE)) {
        qWarning() << "bus is error" << bus.lastError().message();
    }

    bus.registerObject(DBUS_SERVICE_PATH, this,
                       QDBusConnection::ExportAllContents);
}

void DBusService::sendDBus(const QString & text)
{
    emit notifyClientDBusChanged(text);
}

void DBusService::sendTypeDBus(const QString &key, const QString &value)
{
    MyType mytype;
    mytype.key = key;
    mytype.value = value;

    emit notifyDBusTypeChanged(mytype);
}

QByteArray DBusService::getMaps()
{
    QMap<QString, QString> maps;
    maps["xingkongdao"] = "zhengsihua";
    QByteArray ba;
    QDataStream ds(&ba, QIODevice::WriteOnly);
    ds<<maps;
    return ba;
}

void DBusService::serviceMethod(const QString & text)
{
    qDebug() << "=============PID====================";
    qDebug() << "PID is: " << connection().interface()->servicePid(message().service());
    qDebug() << "UID is: " << connection().interface()->serviceUid(message().service());
    qDebug() << "=============UID====================";
    emit notifyQMLDBusChanged(text);
}

MyType DBusService::serviceTypeMethod(const MyType &mytype)
{
    qDebug() << "=============PID====================";
    qDebug() << "PID is: " << connection().interface()->servicePid(message().service());
    qDebug() << "UID is: " << connection().interface()->serviceUid(message().service());
    qDebug() << "=============UID====================";

    qDebug() << "serviceTypeMethod : key is " << mytype.key << "  value is " << mytype.value;
    return mytype;
}
