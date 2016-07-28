#include "AadlgServerApp.h"
#include "ui_AadlgServerApp.h"

AadlgServerApp::AadlgServerApp(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AadlgServerApp)
{
    ui->setupUi(this);
    totalBytes      = 0;
    bytesReceived   = 0;
    fileNameSize    = 0;
    tcpServer = new QTcpServer(this);
    connect(tcpServer,SIGNAL(newConnection()),this,SLOT(acceptConnection()));
    connect(ui->startButton,SIGNAL(clicked()),this,SLOT(start()));
}

void AadlgServerApp::start()
{
    ui->startButton->setEnabled(false);
    bytesReceived = 0;
    if(!tcpServer->listen(QHostAddress::LocalHost, 16666)){
        qDebug()<<__PRETTY_FUNCTION__<<tcpServer->errorString();
        close();
        return;
    }
    ui->serverStatusLabel->setText(tr("Monitor"));
}

void AadlgServerApp::acceptConnection()
{
    tcpServerConnection = tcpServer->nextPendingConnection();
    // QTcpSocket一开始write，就发射readyRead() 信号
    connect(tcpServerConnection,SIGNAL(readyRead()),this,SLOT(updateServerProgress()));
    connect(tcpServerConnection,SIGNAL(error(QAbstractSocket::SocketError)),this,SLOT(displayError(QAbstractSocket::SocketError)));
    ui->serverStatusLabel->setText(tr("accept connection"));
    tcpServer->close();
}

void AadlgServerApp::updateServerProgress()
{
    qDebug()<<__PRETTY_FUNCTION__<<totalBytes;
    QDataStream in(tcpServerConnection);
    in.setVersion(QDataStream::Qt_4_6);
    if(bytesReceived <= sizeof(qint64)*2){
        if((tcpServerConnection->bytesAvailable() >= sizeof(qint64)*2) && (fileNameSize == 0)){
            in >> totalBytes >> fileNameSize;
            bytesReceived += sizeof(qint64)*2;
        }
        if((tcpServerConnection->bytesAvailable() >= fileNameSize) && (fileNameSize != 0)){
            in >> fileName;
            fileName=QString("/home/xkd/")+fileName;
            ui->serverStatusLabel->setText(tr("Receive File %1 ...").arg(fileName));
            bytesReceived += fileNameSize;
            localFile = new QFile(fileName);
            if(!localFile->open(QFile::WriteOnly)){
                qDebug()<<__PRETTY_FUNCTION__<<"open file error";
                return ;
            }
        } else
            return;
    }

    if(bytesReceived < totalBytes ){
        bytesReceived += tcpServerConnection->bytesAvailable();
        inBlock = tcpServerConnection->readAll();
        localFile->write(inBlock);
        qDebug()<<__PRETTY_FUNCTION__<<inBlock.constData();
        inBlock.resize(0);
    }
    ui->serverProgressBar->setMaximum(totalBytes);
    ui->serverProgressBar->setValue(bytesReceived);

    if(bytesReceived == totalBytes){
//        tcpServerConnection->close();
        localFile->close();
        ui->startButton->setEnabled(true);
        ui->serverStatusLabel->setText(tr("Receive File %1 Successfully").arg(fileName));
    }
}

void AadlgServerApp::displayError(QAbstractSocket::SocketError socketError)
{
    qDebug()<<__PRETTY_FUNCTION__<< tcpServerConnection->errorString();
    tcpServerConnection->close();
    ui->serverProgressBar->reset();
    ui->serverStatusLabel->setText(tr("Server Ready"));
    ui->startButton->setEnabled(true);
}

AadlgServerApp::~AadlgServerApp()
{
    delete ui;
}
