#ifndef EPHOTEL_H
#define EPHOTEL_H

#include <QObject>
#include <QtDBus>
// dbus-adaptor
//https://pythonhosted.org/txdbus/dbus_overview.html

class EPDbusAdaptor : public QDBusAbstractAdaptor
{
    Q_OBJECT

};

class EPHotel : public QObject
{
    Q_OBJECT
public:
    explicit EPHotel(QObject *parent = 0);
    
signals:
    
public slots:
    
};

#endif // EPHOTEL_H
