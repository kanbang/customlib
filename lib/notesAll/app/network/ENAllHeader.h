#ifndef ENALLHEADER_H
#define ENALLHEADER_H
/**
 http://jesserei.blog.163.com/blog/static/12141168920101934728424/
 QIODevice是所有Qt I/O设备的基类，它提供了对支持块读写设备(例如：QFile,QButter,QTcpSocket)
 的通用实现和抽象接口。QIODevice是一种抽象，不能被实例化，但是，利用其提供的通用接口可以实现
 设备无关的 I/O 特性

 在访问设备前，必须首先使用open()函数打开并设定正确的访问模式 OpenMode(例如 ReadOnly/ReadWrite)。
 然后，可用write()或者putChar()写设备，或者利用read(), readLine(), readAll() 读设备。完事之后用
 close() 关闭设备。QIODevice具有一下信号：

 readyRead()  当data有新数据准备好时发出信号。例如，新数据通过network到达或者有数据附加到了你正在
 读取的文件之后

 bytesAvaiable() 确定当前可读数据的字节数，当对非同步设备例如QTcpSocket(此类设备的数据到达的时间
 是随机的)编程时，常与readyRead() 信号联用。

 bytesWritten() 每当负载数据被写入设备时触发该信号，使用bytesToWrite()信号确定当前等待被写入的
 数据量

 某些QIODevice类，例如QTcpSocket 和QProcess，是非同步的。如write()或者 read()之类的函数总是
 立即返回，而此时设备可能在函数返回事件循环(eventloop)期间通信。QIODevice提供了可以强制操作立即
 被执行，阻塞回调线程，不用进入事件循环的函数：
 waitForReadyRead();
 waitForBytesWritten();
 waitFor...
 从主函数，GUI线程调用这些函数可能导致界面冻结：

waitForConnected() 等待链接的建立
waitForReadyRead() 等待新数据的到来
waitForBytesWritten() 等待数据写入socket
waitForDisconnected() 等待链接断开

 */
#include <QApplication>
#include <QWidget>
#include <QtNetwork>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QObject>
#include <iostream>

#include <AClientWidgetApp.h>
#include <AServerWidgetApp.h>
#include <AadlgClientApp.h>
#include <AadlgServerApp.h>
#include <AbdlgUdpApp.h>
#include <AbHttpApp.h>
#include <AbdlgUdpApp.h>
#include <AbUdpWidgetApp.h>
#include <AcTcpServerWindowApp.h>
#include <networkWindowApp.h>
#include <networkFactory.h>

#endif // ENALLHEADER_H
