#include "dbuswatcher.h"
#include <QDebug>

const QString DBUS_SERVICE_SERVICE ="cmos.testdbus.service";
const QString DBUS_SERVICE_PATH ="/testdbus";
const QString DBUS_SERVICE_INTERFACE ="cmos.testdbus.service";

DBusWatcher::DBusWatcher(QObject *parent) :
    QObject(parent)
{
    QDBusConnection bus = QDBusConnection::sessionBus();
    qDebug() << bus.interface()->isServiceRegistered(DBUS_SERVICE_SERVICE);

    watcher = new QDBusServiceWatcher(DBUS_SERVICE_SERVICE,QDBusConnection::sessionBus(),
            QDBusServiceWatcher::WatchForRegistration |
            QDBusServiceWatcher::WatchForUnregistration, this);
    connect(watcher, SIGNAL(serviceRegistered(const QString &)),
            this, SLOT(dbusRegistration(const QString &)));
    connect(watcher, SIGNAL(serviceUnregistered(const QString &)),
            this, SLOT(dbusUnregistered(const QString &)));
}

void DBusWatcher::dbusRegistration(const QString &service)
{
    qDebug() << "dbus registration, service is " << service;
}

void DBusWatcher::dbusUnregistered(const QString &service)
{
    qDebug() << "dbus unregistration, service is " << service;

}
