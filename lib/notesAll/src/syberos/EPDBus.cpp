#include "EPDBus.h"
#include <QDebug>

#define MAX_ROOMS 100

EPDBus::EPDBus()
{
    Car *car = new Car();

    /**
    自动启动Service

    D-Bus系统提供了一种机制可以在访问某个service时，自动把该程序运行起来。
    我们需要在/usr/share/dbus-1/services下面建立com.test.hotel.service文件，文件的内容如下：

    [D-BUS Service]
    Name=com.test.hotel
    Exec=/path/to/your/hotel

    这样，我们在访问Hotel的method之前，就不必手动运行该应用程序了。

    cmos-blacklist-daemon
      */


}

/**
  不可以写在函数里面，因为一旦函数运行结束，注册在Service上的Hotel对象就会
  被销毁
  */
void EPDBus::registerService()
{
    // 用于建立到session bus 的链接
    QDBusConnection bus = QDBusConnection::sessionBus();

    // 在session bus 上注册名为 “com.test.hotel”的service
    if(!bus.registerService("com.test.hotel"))
    {
        qDebug()<<__PRETTY_FUNCTION__<< bus.lastError().message();
        exit(1);
    }

    Hotel *_hotel = new Hotel;

    // 注册名为 “/hotel/registry” 的object
    // “QDBusConnection::ExportAllSlots"
    // 表示把类Hotel的所有的Slot都导出为这个Object的method

    bus.registerObject("/hotel/registry", _hotel, QDBusConnection::ExportAllSlots);
    bus.registerObject("/hotel/unRegistry", _hotel, QDBusConnection::ExportAllSlots);
}

void EPDBus::dbusMessage(int argc, char* argv[])
{
    // 用来构造一个在D-Bus上传递的Message
    QDBusMessage msg = QDBusMessage::createMethodCall("com.test.hotel", "/hotel/registry",
                                                      "com.test.hotel.registry", "checkIn");
    if(argc == 2)
    {
        // 这是把QDBusMessage的值作为注册服务器上的Object的函数的参数
        // 比如要调用的是Service上的Hotel object的槽函数 checkIn，
        // 把这个值作为参数传递给 checkIn(msg[0]);
        msg<<QString(argv[1]).toInt();
    } else
    {
        msg << 200;
    }

    // 发送Message
    QDBusMessage response = QDBusConnection::sessionBus().call(msg);

    // 判断Method 是否被正确返回
    if(response.type() == QDBusMessage::ReplyMessage)
    {
        // QDBusMessage的arguments不仅可以用来存储发送的参数，也用来存储返回值
        // 这里取得 checkIn 的返回值
        int roomNum = response.arguments().takeFirst().toInt();
        qDebug()<<__PRETTY_FUNCTION__<<roomNum;
    }
}

void EPDBus::dbusInterface()
{
    QDBusInterface interface("com.test.hotel", "/hotel/registry",
                             "com.test.hotel.registry",
                             QDBusConnection::sessionBus());

    if(!interface.isValid())
    {
        qDebug() << qPrintable(QDBusConnection::sessionBus().lastError().message());
        exit(1);
    }

    int roomNum = -100;
    // 呼叫远程的 checkIn， 参数为 roomNum
    QDBusReply<int> reply = interface.call("checkIn",roomNum);

    if(reply.isValid())
    {
        roomNum = reply.value();
        qDebug()<<__PRETTY_FUNCTION__<<roomNum;
    }
}

void Car::show()
{
    qDebug()<<__PRETTY_FUNCTION__;
}

Hotel::Hotel()
{
    m_rooms = MAX_ROOMS;
}

Hotel::~Hotel()
{

}

int Hotel::checkIn(int roomNum)
{
    qDebug()<<__PRETTY_FUNCTION__<<roomNum;
    if(roomNum < 0)
        return 0;

    else if(roomNum >= 0 && roomNum <= MAX_ROOMS)
        return roomNum;

    else
        return MAX_ROOMS;
}

int Hotel::checkOut(int roomNum)
{
    qDebug()<<__PRETTY_FUNCTION__<<roomNum;
    if(roomNum < 0)
        return 0;

    else if(roomNum >= 0 && roomNum <= MAX_ROOMS)
        return roomNum;

    else
        return MAX_ROOMS;
}

int Hotel::query()
{
    qDebug()<<__PRETTY_FUNCTION__;
    return MAX_ROOMS;
}

Desktop::Desktop(QWidget *parent)
    :QDesktopWidget()
{

}
#include <QPainter>
void Desktop::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setBrush(Qt::black);

    painter.drawRect(100,100,500,500);
}
