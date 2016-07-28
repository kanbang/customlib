#include "AaServerWindowApp.h"
#include "ui_AaServerWindowApp.h"
#include <QPushButton>
#include <QDebug>
#include <QFileDialog>

QString AaServerWindowApp::ipAddres = "127.0.0.1";
AaServerWindowApp::AaServerWindowApp(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AaServerWindowApp)
{
    localSize = 2048;
    totalBytesRecevice = 0;
    bytesRecevice = 0;
    bytesToWriteSend = 0;
    bytesWrittenSend = 0;
    fileNameSize = 0;
    ui->setupUi(this);
    ui->m_txtOutput->setReadOnly(true);
    setFocusPolicy(Qt::ClickFocus);
    ui->menuBar->hide();

    ui->buttonBox->button(QDialogButtonBox::Ok)->setText(tr("Send"));
    ui->buttonBox->button(QDialogButtonBox::Ok)->setShortcut(Qt::ALT+Qt::Key_S);

    ui->buttonBox->button(QDialogButtonBox::Cancel)->setText(tr("Close"));
    setWindowTitle(tr("Server"));
    init();

    //connect
    connect(m_pServerServer,SIGNAL(newConnection()),this,SLOT(acceptConnection()));
    connect(ui->buttonBox,SIGNAL(clicked(QAbstractButton*)),this,SLOT(slotBtnClicked(QAbstractButton*)));
    connect(ui->actionSend_File,SIGNAL(triggered()),this,SLOT(slotSendFile()));
    connect(m_pServerSocket,SIGNAL(bytesWritten(qint64)),this,SLOT(slotContinueSendFile(qint64)));
}

AaServerWindowApp::~AaServerWindowApp()
{
    delete ui;
}


void AaServerWindowApp::init()
{
    m_pServerServer = new QTcpServer(this);
    if(!m_pServerServer->listen(QHostAddress::Any,20000)){
        qDebug()<<__PRETTY_FUNCTION__<<m_pServerServer->errorString();
        close();
    }

    m_pServerSocket = new QTcpSocket(this);
    m_pServerSocket->connectToHost(ipAddres,19999);
    connect(m_pServerSocket,SIGNAL(readyRead()),this,SLOT(slotReadMsg()));
}

void AaServerWindowApp::focusInEvent(QFocusEvent *)
{
}

void AaServerWindowApp::acceptConnection()
{
    m_pConnectSocket = m_pServerServer->nextPendingConnection();
    connect(m_pConnectSocket,SIGNAL(readyRead()),this,SLOT(slotReadMsg()));
}

void AaServerWindowApp::slotBtnClicked(QAbstractButton *btn)
{
    if(m_pServerSocket->state() != QAbstractSocket::ConnectedState)
        m_pServerSocket->connectToHost(ipAddres,19999);

    if(btn == (QAbstractButton*)ui->buttonBox->button(QDialogButtonBox::Ok))
    {
        processData();
    } else
    {
        close();
    }
}

//void AaServerWindowApp::slotSendMsg()
//{
//    QByteArray array;
//    QString msg = ui->m_txtInput->toPlainText();
//    QDataStream sendOut(&array,QIODevice::WriteOnly);
//    sendOut.setVersion(QDataStream::Qt_4_6);

//    sendOut<<msg;
//    m_pServerSocket->write(array);
//}

void AaServerWindowApp::slotReadMsg()
{
    QDataStream in(m_pConnectSocket);
    in.setVersion(QDataStream::Qt_4_6);
    // 加了这句后，就不能从客户端传递数据到服务端了。
//    qDebug()<<"read "<<m_pConnectSocket->readAll();

    int type = 0;
    if(totalBytesRecevice <=0)
        in >> totalBytesRecevice >> fileNameSize >> type;
    if ((AaServerWindowApp::readType)type == AaServerWindowApp::File)
        readFile(in);
    if ((AaServerWindowApp::readType)type == AaServerWindowApp::Message)
        readMessage(in);
}

void AaServerWindowApp::slotSendFile()
{
    m_fileNameSend = QFileDialog::getOpenFileName(this);
    if(!m_fileNameSend.isEmpty()){
        localFile = new QFile(m_fileNameSend);
        if (!localFile->open(QFile::ReadOnly)){
            qDebug()<<__PRETTY_FUNCTION__<<"Error";
            return;
        }
        totalBytesSend = localFile->size();
        QDataStream sendOut(&outBlock,QIODevice::WriteOnly);
        sendOut.setVersion(QDataStream::Qt_4_6);
        QString currentFileName = m_fileNameSend.right(m_fileNameSend.size()
                                                       -m_fileNameSend.lastIndexOf("/") -1);
        sendOut << qint64(0) <<qint64(0) <<AaServerWindowApp::File << currentFileName;
        totalBytesSend += outBlock.size();
        sendOut.device()->seek(0);
        sendOut << totalBytesSend << qint64(outBlock.size() - sizeof(qint64)*2);
        bytesToWriteSend = totalBytesSend - m_pServerSocket->write(outBlock);
        outBlock.resize(0);
    }
}

void AaServerWindowApp::slotContinueSendFile(qint64 number)
{
    if(!m_fileNameSend.isEmpty()){
        bytesWrittenSend += number;
        if(bytesToWriteSend > 0){
            outBlock = localFile->read(qMin(bytesToWriteSend,localSize));
            //往套接字缓存中写入数据，并发送
            bytesToWriteSend -= m_pServerSocket->write(outBlock);
            outBlock.resize(0);
        } else
            localFile->close();
        if(bytesWrittenSend == totalBytesSend){
            QString msg = QString("The file has sent successfully!");
            appendServerText(msg);
            bytesWrittenSend = 0;
            totalBytesSend = 0;
            bytesToWriteSend = 0;
        }
    }
}

void AaServerWindowApp::processData()
{
    QByteArray array;
    QString msg = ui->m_txtInput->toPlainText();
    QDataStream sendOut(&array,QIODevice::WriteOnly);
    sendOut.setVersion(QDataStream::Qt_4_6);

    sendOut<<qint64(0) << qint64(0) << AaServerWindowApp::Message << msg;
    sendOut.device()->seek(0);
    sendOut<<array.size() <<qint64(array.size() - sizeof(qint64)*2);

    m_pServerSocket->write(array);
    ui->m_txtInput->clear();
    appendServerText(msg);
}

void AaServerWindowApp::readFile(QDataStream &ds)
{
    if(bytesRecevice <= sizeof(qint64)*2){
        ds >> m_fileNameRecevice;
        bytesRecevice += (fileNameSize + sizeof(qint64)*2) ;
        m_fileNameRecevice = QDir::home().absolutePath() + "/" + m_fileNameRecevice;
        localFile = new QFile(m_fileNameRecevice);
        if(!localFile->open(QFile::WriteOnly)){
            qDebug()<<__PRETTY_FUNCTION__<<"Error";
            return ;
        }
    }
    if(bytesRecevice < totalBytesRecevice){
        bytesRecevice += m_pConnectSocket->bytesAvailable();
        outBlock = m_pConnectSocket->readAll();
        localFile->write(outBlock);
        outBlock.resize(0);
    }

    if(bytesRecevice == totalBytesRecevice ){
        localFile->close();
        QString msg = QString("The file has receviced successfully!");
        appendServerText(msg);
        bytesRecevice = 0;
        totalBytesRecevice = 0;
    }
}

void AaServerWindowApp::readMessage(QDataStream &ds)
{
    QString msg;
    ds >> msg;
    appendServerText(msg);
    totalBytesRecevice = 0;
}


void AaServerWindowApp::appendServerText(const QString &text)
{
    QString qStrSendInfo ;
    if(ui->m_txtOutput->document()->isEmpty())
        qStrSendInfo = QString("Server") + ": \n" + text;
    else
        qStrSendInfo = "\n" + QString("Server") + ": \n" + text;
    ui->m_txtOutput->append(qStrSendInfo);
}

void AaServerWindowApp::appendClientText(const QString &text)
{
    QString qStrSendInfo ;
    if(ui->m_txtOutput->document()->isEmpty())
         qStrSendInfo = QString("Client") + " :\n " + text;
    else
        qStrSendInfo ="\n" +  QString("Client") + " :\n " + text;
    ui->m_txtOutput->append(qStrSendInfo);
}
