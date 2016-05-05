#ifndef DBUSSERVICE_H
#define DBUSSERVICE_H

#include <QObject>
#include <QDBusContext>
#include "dbustypes.h"

class DBusService : public QObject, protected QDBusContext
{
    Q_OBJECT
    Q_CLASSINFO("D-Bus Interface", "cmos.testdbus.service")

public:
    explicit DBusService(QObject *parent = 0);

    Q_INVOKABLE void sendDBus(const QString &text);
    Q_INVOKABLE void sendTypeDBus(const QString &key, const QString &value);
    Q_INVOKABLE QByteArray getMaps();

signals:
    void notifyClientDBusChanged(const QString &text);
    void notifyQMLDBusChanged(const QString &text);
    void notifyDBusTypeChanged(const MyType &mytype);

public slots:
    void serviceMethod(const QString &text);
    MyType serviceTypeMethod(const MyType &mytype);
};

#endif // DBUSSERVICE_H
