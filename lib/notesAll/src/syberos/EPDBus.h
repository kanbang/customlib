#ifndef EPDBUS_H
#define EPDBUS_H

#include <QtDBus>

#include <QObject>
#include <QDesktopWidget>

class Car
{
public:
    void show();
};

// http://blog.chinaunix.net/uid-23023613-id-219094.html
// http://dbus.freedesktop.org/releases/dbus/
class EPDBus
{
public:
    EPDBus();

    static void registerService();
    static void dbusMessage(int argc, char *argv[]);

    static void dbusInterface();
};

/**
    D-Bus 通过Signal/Method来发送和接收Message。
    Signal/Method可以理解为QT4中的Signal/Slot这个概念。
    一个 Object可以提供多个Method/Signal，这些Method/Signal的集合又组成了Interface。

    因此，D-Bus的这些概念从大到小可以表示为：
    Message Bus->Service->Object->[Interface]->Method/Signal。
    其中，Interface是可选的。

  */
class Hotel : public QObject
{
    Q_OBJECT

    // 定义 Interface 名称为 “com.test.hotel.registry"
    Q_CLASSINFO("D-Bus Interface", "com.test.hotel.registry")

public:
    Hotel();
    ~Hotel();

public slots:
    int checkIn(int roomNum);
    int checkOut(int roomNum);

    int query();

private:
    int m_rooms;
    QReadWriteLock m_lock;
};

class Desktop : public QDesktopWidget
{
    Q_OBJECT

public:
    Desktop(QWidget *parent = 0);

protected:
    void paintEvent(QPaintEvent *);

};

#endif // EPDBUS_H
