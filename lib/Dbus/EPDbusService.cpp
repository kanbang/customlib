#include <EPDbusService.h>
#include <QDebug>

EPDbusService::EPDbusService()
{
}

void EPDbusService::execute()
{
    QDBusConnection connect = QDBusConnection::sessionBus();

    if(!connect.registerService("test.dbus.service"))
    {
        qDebug()<<"register service failure";
    }
}
