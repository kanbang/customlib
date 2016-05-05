#ifndef DBUSWATCHER_H
#define DBUSWATCHER_H

#include <QObject>
#include <QDBusServiceWatcher>
#include <QDBusConnection>
#include <QDBusConnectionInterface>

class DBusWatcher : public QObject
{
    Q_OBJECT
public:
    explicit DBusWatcher(QObject *parent = 0);

signals:

public slots:
    void dbusRegistration(const QString &service);
    void dbusUnregistered(const QString &service);

private:
    QDBusServiceWatcher *watcher;
};

#endif // DBUSWATCHER_H
