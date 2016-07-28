#include "AClientWidgetApp.h"
#include <QtGui>
#include <QHBoxLayout>
AClientWidgetApp::AClientWidgetApp(QWidget *parent):
    QWidget(parent)
{
    layoutBtn();
    tcpSocket = new QTcpSocket(this);
    connect(tcpSocket,SIGNAL(readyRead()),this,SLOT(readMessage()));
    connect(tcpSocket,SIGNAL(error(QAbstractSocket::SocketError)),this,SLOT(displayError(QAbstractSocket::SocketError)));
    connect(pushButton,SIGNAL(clicked()),this,SLOT(onBtn()));
}

void AClientWidgetApp::layoutBtn()
{
    m_label = new QLabel("Host");
    m_label1 = new QLabel("Port");
    messageLabel = new QLabel("reciver message");
    pushButton = new QPushButton("Connect");
    hostLineEdit = new QLineEdit();
    hostLineEdit->setText(QString("localhost"));
    portLineEdit = new QLineEdit();
    portLineEdit->setText(QString("6666"));

    QHBoxLayout *hLayout = new QHBoxLayout;
    hLayout->addWidget(m_label);
    hLayout->addWidget(hostLineEdit);

    QHBoxLayout *hLayout1 = new QHBoxLayout;
    hLayout1->addWidget(m_label1);
    hLayout1->addWidget(portLineEdit);

    QHBoxLayout* hLayout2 = new QHBoxLayout;
    hLayout2->addWidget(messageLabel);
    hLayout2->addWidget(pushButton);

    QVBoxLayout* mainLayout = new QVBoxLayout;
    mainLayout->addLayout(hLayout);
    mainLayout->addLayout(hLayout1);
    mainLayout->addLayout(hLayout2);

    setLayout(mainLayout);

}

void AClientWidgetApp::newConnect()
{
    blockSize = 0;
    tcpSocket->abort(); //
    tcpSocket->connectToHost(hostLineEdit->text(),portLineEdit->text().toInt());
}
/**
 * @brief AClientWidgetApp::readMessage
    这个函数实现了数据的接收，它与服务器端的发送函数相对应。首先我们要获取文件的大小信息，然后根据文件的大小来判断是否接收到了完整的文件。
*/
void AClientWidgetApp::readMessage()
{
    QDataStream in(tcpSocket);
     //设置数据流版本，这里要和服务器端相同
    in.setVersion(QDataStream::Qt_4_6);
    if(blockSize == 0)  //如果是刚开始接收数据
    {
        //判断接收的数据是否有两字节，也就是文件的大小信息
        //如果有则保存到blockSize变量中，没有则返回，继续接收数据
        if(tcpSocket->bytesAvailable() < (int)sizeof(quint16))
            return;
        in >> blockSize;
    }
    if(tcpSocket->bytesAvailable() < blockSize)
        //如果没有得到全部的数据，则返回，继续接收数据
        return;
    //将接收到的数据存放到变量中
    in >> message;
    messageLabel->setText(message);
}

void AClientWidgetApp::displayError(QAbstractSocket::SocketError)
{
    qDebug()<<__PRETTY_FUNCTION__<<tcpSocket->errorString();
}

void AClientWidgetApp::onBtn()
{
    newConnect();
}
