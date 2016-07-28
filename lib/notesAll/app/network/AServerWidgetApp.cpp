#include "AServerWidgetApp.h"
#include <QtGui>

/**
  TCP协议的程序使用的是客户端／服务器模式，在Qt中提供了QTcpSocket类来编写客户端程序
  ，使用QTcpServer类编写服务器端程序

 */
AServerWidgetApp::AServerWidgetApp(QWidget *parent) :
    QWidget(parent)
{
    /**
     QTcpServer 类用来编写服务器端程序。我们在服务器端进行端口的监听，一旦发现
     客户端的连接请求，就会发出enwConnection()信号。
    */
    tcpServer = new QTcpServer(this);
    if(!tcpServer->listen(QHostAddress::LocalHost, 6666))
    {
        qDebug()<<__PRETTY_FUNCTION__<<tcpServer->errorString();
        close();
    }
    /**
    一旦发现客户端的连接请求，就会发出newConnection()信号。
    */
    connect(tcpServer,SIGNAL(newConnection()),this,SLOT(sendMessage()));
    resize(300,100);
    m_label = new QLabel("waitConnect",this);
}
/**
 这个是数据发送函数，我们主要介绍两点：
（1）为了保证在客户端能接收到完整的文件，我们都在数据流的最开始写入完整文件的大小信息，这样客户端就可以根据大小信息来判断是否接受到了完整的文件。
    而在服务器端，我们在发送数据时就要首先发送实际文件的大小信息，但是，文件的大小一开始是无法预知的，
    所以我们先使用了out<<(quint16) 0;在block的开始添加了一个quint16大小的空间，也就是两字节的空间，
    它用于后面放置文件的大小信息。然后out<<tr(“hello Tcp!!!”);输入实际的文件，这里是字符串。
    当文件输入完成后我们在使用out.device()->seek(0);返回到block的开始，加入实际的文件大小信息，
    也就是后面的代码，它是实际文件的大小：out<<(quint16) (block.size() – sizeof(quint16));

（2）在服务器端我们可以使用tcpServer的nextPendingConnection()函数来获取已经建立的连接的Tcp套接字，使用它来完成数据的发送和其它操作。
    比如这里，我们关联了disconnected()信号和deleteLater()槽函数，然后我们发送数据 clientConnection->write(block);
    然后是clientConnection->disconnectFromHost();它表示当发送完成时就会断开连接，这时就会发出disconnected()信号，
    而最后调用deleteLater()函数保证在关闭连接后删除该套接字clientConnection。
*/
void AServerWidgetApp::sendMessage()
{
    QTcpSocket* clientConnection = tcpServer->nextPendingConnection();
    qDebug()<<__PRETTY_FUNCTION__<<clientConnection->objectName();
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_6);
    out<< (quint16) 0 ;
    out<< clientConnection->peerAddress().toString()<< QString("xkdzsh");
    out.device()->seek(0);
    out<<(quint16)(block.size() - sizeof(quint16));
    /**
      一旦有数据到来就会发出readyRead()信号。
     */
    connect(clientConnection,SIGNAL(disconnected()),clientConnection,SLOT(deleteLater()));
    clientConnection->write(block);
    clientConnection->disconnectFromHost();
    m_label->setGeometry(50,25,width()-100,40);
    m_label->setText("Send Message Successful!!!"+clientConnection->peerAddress().toString());
}
