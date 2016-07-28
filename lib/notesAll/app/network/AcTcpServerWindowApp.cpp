#include "AcTcpServerWindowApp.h"
#include "ui_AcTcpServerWindowApp.h"

AcTcpServerWindowApp::AcTcpServerWindowApp(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AcTcpServerWindowApp)
{
    ui->setupUi(this);
    ui->textEdit_Info->setReadOnly(true);

    isServer= true;     //默认服务端
    connect(ui->pushButton_StartServer,SIGNAL(clicked()),this,SLOT(slotStartServer()));
    connect(ui->pushButton_ConnectServer,SIGNAL(clicked()),this,SLOT(slotConnectServer()));
    connect(ui->pushButton_Send,SIGNAL(clicked()),this,SLOT(slotSendMesg()));
}

AcTcpServerWindowApp::~AcTcpServerWindowApp()
{
    delete ui;
}

void AcTcpServerWindowApp::slotStartServer()  //启动服务器
{
    isServer = true;
    m_pTcpServer = new QTcpServer();
    m_pTcpServer->listen(QHostAddress::Any,19999);
    connect(m_pTcpServer,SIGNAL(newConnection()),this,SLOT(slotNewConnect()));
}

void AcTcpServerWindowApp::slotNewConnect()
{
//    QTcpSocket *pTcpSocket;
    pTcpSocketServer =  m_pTcpServer->nextPendingConnection();
//    pTcpSocketTemp = pTcpSocket;
//    int sockfd = pTcpSocketTemp->socketDescriptor();
//    map_TcpSocket.insert(make_pair(sockfd,pTcpSocket));
    connect(pTcpSocketServer,SIGNAL(readyRead()),this,SLOT(slotReadMesg()));
}

void AcTcpServerWindowApp::slotReadMesg() //读取信息
{
//    int sockfd = pTcpSocketTemp->socketDescriptor();
    pTcpSocketClient->waitForBytesWritten(500);
    if(pTcpSocketClient->bytesAvailable() == 0)
        return ;
    QDataStream in0(pTcpSocketClient);
    in0.setVersion(QDataStream::Qt_4_6);
    qDebug()<<__PRETTY_FUNCTION__<<isServer;
//    pTcpSocketServer->waitForBytesWritten(100);

    if(isServer == true)
    {
        QByteArray qba= pTcpSocketServer->readAll(); //读取

        QString ss=QVariant(qba).toString();
        qDebug()<<__PRETTY_FUNCTION__<<ss;
        in0 >> ss;
        QHostAddress ip = pTcpSocketServer->peerAddress();
        QString qStrSendInfo = ip.toString()+" : "+ss;
        ui->textEdit_Info->append(qStrSendInfo);

    }
    else if(isServer == false)
    {
//        QByteArray qba= pTcpSocketClient->readAll(); //读取
        QString ss;//=QVariant(qba).toString();
//        qDebug()<<__PRETTY_FUNCTION__<<ss;
        in0 >> ss;
        QHostAddress ip = pTcpSocketClient->peerAddress();
        QString qStrSendInfo = ip.toString()+" : "+ss;
        ui->textEdit_Info->append(qStrSendInfo);
    }
    pTcpSocketServer->flush();
}

void AcTcpServerWindowApp::slotConnectServer()    //连接服务器
{
    if(ui->lineEdit_IP->text().isEmpty() ||ui->lineEdit_NetPort->text().isEmpty())
    {
        QMessageBox::warning(this,tr("Warning"),tr("Please input IP OR NetPort!"));
        return;
    }

    isServer = true;
    ui->pushButton_StartServer->setEnabled(false);
    pTcpSocketClient = new QTcpSocket(this);
    pTcpSocketClient->abort();
    QString qStrIP = ui->lineEdit_IP->text();
    quint16 netport = ui->lineEdit_NetPort->text().toInt();
    pTcpSocketClient->connectToHost(qStrIP,netport);

    connect(pTcpSocketClient,SIGNAL(readyRead()),this,SLOT(slotReadMesg()));

    ui->pushButton_ConnectServer->setEnabled(false);
    ui->lineEdit_IP->setEnabled(false);
    ui->lineEdit_NetPort->setEnabled(false);
}

void AcTcpServerWindowApp::slotSendMesg() //发送消息
{
    QString strMesg= ui->lineEdit_sendmsg->text();
    ui->lineEdit_sendmsg->clear();

    QDataStream sendOut(&array,QIODevice::WriteOnly);
    sendOut.setVersion(QDataStream::Qt_4_6);
    sendOut<<strMesg;

    qDebug()<<__PRETTY_FUNCTION__<<array.data();
    if(isServer == true)
    {
        // pTcpSocketServer->write(strMesg.toStdString().c_str(),strlen(strMesg.toStdString().c_str()));
        pTcpSocketServer->write(array);
        pTcpSocketServer->waitForBytesWritten(100);
    }

    else if(isServer == false)
    {
        //pTcpSocketClient->write(strMesg.toStdString().c_str(),strlen(strMesg.toStdString().c_str()));
        pTcpSocketClient->write(array);
        pTcpSocketClient->waitForBytesWritten(100);
    }
    ui->lineEdit_sendmsg->setFocus();
}
