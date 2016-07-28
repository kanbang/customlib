#ifndef DBUSCLIENT_H
#define DBUSCLIENT_H

#include <QObject>
#include <QDBusContext>
#include "dbustypes.h"

class DBusClient : public QObject, protected QDBusContext
{
    Q_OBJECT
public:
    explicit DBusClient(QObject *parent = 0);

    Q_INVOKABLE void callService(QString text);
    Q_INVOKABLE void callTypeService(const QString &key, const QString &value);

signals:
    void serviceDBusChanged(const QString &text);

public slots:
    void getNotifyClientDBusChanged(const QString &text);
    void getNotifyDBusTypeChanged(const MyType &mytype);    
    void getMapClient();

};

#endif // DBUSCLIENT_H
