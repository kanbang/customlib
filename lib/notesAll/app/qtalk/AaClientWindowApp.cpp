#include "AaClientWindowApp.h"
#include "ui_AaClientWindowApp.h"
#include <QDebug>
#include <QPushButton>
#include <QFileDialog>
#include <QTextDocument>
#include <QTextCodec>

QString AaClientWindowApp::ipAddres = "127.0.0.1";
AaClientWindowApp::AaClientWindowApp(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AaClientWindowApp)
{
    loadSize = 1024*4;
    totalBytesRecevice = 0;
    bytesRecevice = 0;
    bytesToWriteSend = 0;
    bytesWrittenSend = 0;
    fileNameSize = 0;
    outBlock.resize(0);
    ui->setupUi(this);
    ui->m_txtOutput->setReadOnly(true);
    setFocusPolicy(Qt::ClickFocus);
    ui->menuBar->hide();

    ui->buttonBox->button(QDialogButtonBox::Ok)->setText(tr("Send"));
    ui->buttonBox->button(QDialogButtonBox::Ok)->setShortcut(Qt::ALT+Qt::Key_S);

    ui->buttonBox->button(QDialogButtonBox::Cancel)->setText(tr("Close"));
    init();
    setWindowTitle("Client");

    //connect
    connect(m_pClientServer,SIGNAL(newConnection()),this,SLOT(acceptConnection()));
    connect(ui->buttonBox,SIGNAL(clicked(QAbstractButton*)),this,SLOT(slotBtnClicked(QAbstractButton*)));
    connect(ui->action_Open,SIGNAL(triggered()),this,SLOT(slotSendFile()));
    connect(m_pClientSocket,SIGNAL(bytesWritten(qint64)),this,SLOT(slotContinueSendFile(qint64)));
}

AaClientWindowApp::~AaClientWindowApp()
{
    delete ui;
}

void AaClientWindowApp::init()
{
    m_pClientServer = new QTcpServer(this);
    if(!m_pClientServer->listen(QHostAddress::Any,19999)){
        qDebug()<<__PRETTY_FUNCTION__<<m_pClientServer->errorString();
        close();
    }

    m_pClientSocket = new QTcpSocket(this);
    m_pClientSocket->connectToHost(ipAddres,20000);
    connect(m_pClientSocket,SIGNAL(readyRead()),this,SLOT(slotReadMsg()));
}

void AaClientWindowApp::acceptConnection()
{
    m_pConnectSocket = m_pClientServer->nextPendingConnection();
    connect(m_pConnectSocket,SIGNAL(readyRead()),this,SLOT(slotReadMsg()));
}

void AaClientWindowApp::slotBtnClicked(QAbstractButton *btn)
{
    if(m_pClientSocket->state() != QAbstractSocket::ConnectedState)
        m_pClientSocket->connectToHost(ipAddres,20000);

    if(btn == (QAbstractButton*)ui->buttonBox->button(QDialogButtonBox::Ok))
    {
        processData();
    } else
    {
        close();
    }
}

//void AaClientWindowApp::slotSendMsg()
//{
//    QByteArray array;
//    QString msg = ui->m_txtInput->toPlainText();
//    QDataStream sendOut(&array,QIODevice::WriteOnly);
//    sendOut.setVersion(QDataStream::Qt_4_6);

//    sendOut<<msg;
//    m_pClientSocket->write(array);
//}

void AaClientWindowApp::slotReadMsg()
{
    QDataStream in(m_pConnectSocket);
    in.setVersion(QDataStream::Qt_4_6);
    int type;
    if(totalBytesRecevice <= 0)
        in >> totalBytesRecevice >> fileNameSize >> type;

    if((AaClientWindowApp::readType)type == AaClientWindowApp::Message)
        readMessage(in);
    if((AaClientWindowApp::readType)type == AaClientWindowApp::File)
        readFile(in);
}

void AaClientWindowApp::slotSendFile()
{
    m_fileNameSend = QFileDialog::getOpenFileName(this);
    if(!m_fileNameSend.isEmpty()){
        localFile = new QFile(m_fileNameSend);
        if(!localFile->open(QFile::ReadOnly)){
            qDebug()<<__PRETTY_FUNCTION__<<"Open File Error";
            return;
        }
        totalBytesSend = localFile->size();
        QString currentFileName = m_fileNameSend.right(m_fileNameSend.size()
                                                       -m_fileNameSend.lastIndexOf("/") - 1);
        QDataStream sendOut(&outBlock,QIODevice::WriteOnly);
        sendOut.setVersion(QDataStream::Qt_4_6);
        int type = 0;
        sendOut<<qint64(0) <<qint64(0) << type << currentFileName ;
        totalBytesSend += outBlock.size();
        sendOut.device()->seek(0);
        sendOut<<totalBytesSend<<qint64((outBlock.size()-sizeof(qint64)*2));
        bytesToWriteSend = totalBytesSend - m_pClientSocket->write(outBlock);
        outBlock.resize(0);
    }
}

void AaClientWindowApp::slotContinueSendFile(qint64 numBytes)
{
    if(!m_fileNameSend.isEmpty()){
        bytesWrittenSend += numBytes;
        if(bytesToWriteSend > 0){
            outBlock = localFile->read(qMin(bytesToWriteSend,loadSize));
            bytesToWriteSend -= (int)m_pClientSocket->write(outBlock);
            outBlock.resize(0);
        } else {
            localFile->close();
        }
        if(bytesWrittenSend == totalBytesSend){
            QString msg = QString("The File has Sent Successfully!");
            appendClientText(msg);
            bytesWrittenSend = 0;
            totalBytesSend = 0;
            bytesToWriteSend = 0;
        }
    }
}

void AaClientWindowApp::processData()
{
    QByteArray array;
    QString msg = ui->m_txtInput->toPlainText();
    QDataStream sendOut(&array,QIODevice::WriteOnly);
    sendOut.setVersion(QDataStream::Qt_4_6);
    sendOut<<qint64(0)<<qint64(0)<<AaClientWindowApp::Message << msg;
    sendOut.device()->seek(0);
    //按字节来存储的。
    sendOut<<array.size() <<qint64(array.size()-sizeof(qint64)*2);
    m_pClientSocket->write(array);
    ui->m_txtInput->clear();

    appendClientText(msg);
}

void AaClientWindowApp::appendServerText(const QString &text)
{
    QString qStrSendInfo ;
    if(ui->m_txtOutput->document()->isEmpty())
        qStrSendInfo = QString("Server") + ": \n" + text;
    else
        qStrSendInfo = "\n" + QString("Server") + ": \n" + text;
    ui->m_txtOutput->append(qStrSendInfo);
}

void AaClientWindowApp::appendClientText(const QString &text)
{
    QString qStrSendInfo ;
    if(ui->m_txtOutput->document()->isEmpty())
         qStrSendInfo = QString("Client") + " :\n " + text;
    else
        qStrSendInfo ="\n" +  QString("Client") + " :\n " + text;
    ui->m_txtOutput->append(qStrSendInfo);
}

void AaClientWindowApp::readMessage(QDataStream &ds)
{
    QString msg;
//    QTextCodec::setCodecForTr(QTextCodec::codecForName("gbk")); //把中文写入文件，而不是乱码。要调用tr()函数
//    QString filename = QDir::home().absolutePath() + "/" + "xkd.cpp";
//    QFile file(filename);
//    file.open(QFile::WriteOnly);
//    QByteArray arr = m_pConnectSocket->readAll();
//    file.write(arr);
//    file.close();
    ds >> msg;
    appendServerText(msg);
    totalBytesRecevice = 0;
}

void AaClientWindowApp::readFile(QDataStream &ds)
{
    if(bytesRecevice <= sizeof(qint64)*2){
        ds >> m_fileNameRecevice;
        bytesRecevice += (fileNameSize + sizeof(qint64)*2);
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
    if(bytesRecevice == totalBytesRecevice){
        localFile->close();
        QString msg = QString("The file has receviced successfully!");
        appendClientText(msg);
        bytesRecevice = 0;
        totalBytesRecevice = 0;
    }
}
