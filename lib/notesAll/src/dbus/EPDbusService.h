#ifndef EPDBUSINTERFACE_H
#define EPDBUSINTERFACE_H

#include <QtDBus>
#include <QObject>

class EPDbusService : public QObject
{
    Q_OBJECT
public:
    explicit EPDbusService(QObject *parent = 0);

    static void execute();
};

class EPService
{
public:
    EPService();

    static void execute();
    static void execClient();
};


class EPObject : public QObject
{
    Q_OBJECT

    Q_CLASSINFO("D-Bus Interface", "test.dbus.interface")

public:
    EPObject(QObject* parent = 0);

    Q_INVOKABLE void testDbus();
signals:
    void testChanged();

public slots:
    void receiveChanged();
};

class EPObject_One : public QObject
{
    Q_OBJECT

public:
    EPObject_One(QObject* parent = 0);

public slots:
    void oneSlot();
};

class Adaptor : public QDBusAbstractAdaptor
{
    Q_OBJECT
    Q_CLASSINFO("D-Bus Introspection", ""
                "<interface name=\"test.dbus.interface\">\n"
                "	<signal name=\"testChanged\">\n"
                "	</signal>\n"
                "</interface>\n"
                )
//    Q_CLASSINFO("D-Bus Introspect", ""
//                )
public:
    Adaptor(QObject* parent = 0);

    // Q_INVOKABLE 这个宏不可以使接口在dbus上暴露出来
public slots:
    void adaptTestDbus();
    QString adaptOutput(QString str, int value);

signals:
    void testChanged();

private:
    EPObject* _obj;
};

class anAdaptor : public QDBusAbstractAdaptor
{
    Q_OBJECT

    Q_CLASSINFO("D-Bus Interface", "test.dbus.anotherInterface")

//    Q_CLASSINFO("D-Bus Introspect", ""
//                )
public:
    anAdaptor(QObject* parent = 0);

    // Q_INVOKABLE 这个宏不可以使接口在dbus上暴露出来
public slots:
    void adaptTestDbus();
    QString adaptOutput(QString str, int value);

signals:
    void testChanged();

private:
    EPObject* _obj;
};

class SYThreadConnect : public QObject
{
    Q_OBJECT
public:
    explicit SYThreadConnect(QObject *parent = 0);
    void sendSignal();

signals:
    void emitsignal();

public slots:
    void testThread();
};

class oneThread : public QThread
{
    Q_OBJECT

public:
    oneThread(SYThreadConnect* connect);

    void run();

private:
    SYThreadConnect* _con;
};


#endif // EPDBUSINTERFACE_H
