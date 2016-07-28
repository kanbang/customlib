#include "AadlgClientApp.h"
#include "ui_AadlgClientApp.h"
#include <QFileDialog>

AadlgClientApp::AadlgClientApp(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AadlgClientApp)
{
    ui->setupUi(this);

    loadSize = 4*1024;
    totalBytes      = 0;
    bytesWritten    = 0;
    bytesToWrite    = 0;
    tcpClient       = new QTcpSocket(this);
    ui->openButton->setShortcut(Qt::ALT + Qt::Key_S);
    //当连接服务器成功时，发出connected()信号，开始传送文件
    connect(tcpClient, SIGNAL(connected()),this, SLOT(startTransfer()));
    //当有数据发送成功时，更新进度条,每当读完一个outBlock,就会发射bytesWritten信号
    connect(tcpClient,SIGNAL(bytesWritten(qint64)),this,SLOT(updateClientProgress(qint64)));
    //
    connect(tcpClient,SIGNAL(error(QAbstractSocket::SocketError)),this,SLOT(displayError(QAbstractSocket::SocketError)));

    connect(ui->openButton,SIGNAL(clicked()),this,SLOT(openFile()));
    connect(ui->sendButton,SIGNAL(clicked()),this,SLOT(send()));
    ui->sendButton->setEnabled(false);
}

void AadlgClientApp::openFile()
{
    fileName = QFileDialog::getOpenFileName(this);
    if(!fileName.isEmpty()){
        ui->sendButton->setEnabled(true);
        ui->clientStatusLabel->setText(tr("open file %1 successfully !").arg(fileName));
    }
}

void AadlgClientApp::send()
{
    ui->sendButton->setEnabled(false);
    bytesWritten = 0;
    ui->clientStatusLabel->setText(tr("Connecting ..."));
    tcpClient->connectToHost(ui->hostLineEdit->text(),ui->portLineEdit->text().toInt());
}

void AadlgClientApp::startTransfer()
{
    localFile = new QFile(fileName);
    if(!localFile->open(QFile::ReadOnly)){
        qDebug()<< __PRETTY_FUNCTION__<<"Open File Error";
        return;
    }
    totalBytes = localFile->size();
    //文件总大小
    QDataStream sendOut(&outBlock, QIODevice::WriteOnly);
    sendOut.setVersion(QDataStream::Qt_4_6);
    QString currentFileName = fileName.right(fileName.size() - fileName.lastIndexOf("/") -1);
    // 依次写入总大小信息空间，文件名大小信息空间，文件名
    sendOut <<qint64(0) << qint64(0) <<currentFileName;
    // 这里的总大小是文件名大小等信息和实际文件大小的总和
    totalBytes += outBlock.size();
    sendOut.device()->seek(0);
    // 返回outBlock的开始，用实际的小心信息代替两个qint64(0)空间
    sendOut<< totalBytes << qint64((outBlock.size() - sizeof(qint64)*2));
    // 发送完头数据后剩余数据的大小
    bytesToWrite = totalBytes - tcpClient->write(outBlock);
    qDebug()<<bytesToWrite << totalBytes;
    ui->clientStatusLabel->setText(tr("Connected"));
    outBlock.resize(0);
}

void AadlgClientApp::updateClientProgress(qint64 numBytes)
{
    static int num = 0;
    num += numBytes;
    qDebug()<<__PRETTY_FUNCTION__<< "num = "<<num << "step = "<<numBytes ;
    bytesWritten += (int)numBytes;
    if(bytesToWrite > 0){
        outBlock = localFile->read(qMin(bytesToWrite,loadSize));
        bytesToWrite -= (int)tcpClient->write(outBlock);
        outBlock.resize(0);
    } else{
        localFile->close();
    }
    ui->clientProgressBar->setMaximum(totalBytes);
    ui->clientProgressBar->setValue(bytesWritten);
    if(bytesWritten == totalBytes){
        ui->clientStatusLabel->setText(tr("Transfering %1 successfully").arg(fileName));
        localFile->close();
//        tcpClient->close();
    }
}

void AadlgClientApp::displayError(QAbstractSocket::SocketError)
{
    qDebug()<<__PRETTY_FUNCTION__<<tcpClient->errorString();
    tcpClient->close();
    ui->clientProgressBar->reset();
    ui->clientStatusLabel->setText(tr("Client ready"));
    ui->sendButton->setEnabled(true);
}

//void AadlgClientApp::openClick()
//{
//    openFile();
//}

//void AadlgClientApp::sendClick()
//{
//    send();
//}

AadlgClientApp::~AadlgClientApp()
{
    delete ui;
}
