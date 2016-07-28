#ifndef AADLGCLIENTAPP_H
#define AADLGCLIENTAPP_H

#include <QDialog>
#include <QtNetwork>

namespace Ui {
class AadlgClientApp;
}

class AadlgClientApp : public QDialog
{
    Q_OBJECT
    
public:
    explicit AadlgClientApp(QWidget *parent = 0);
    ~AadlgClientApp();

signals:
    void sendSignal();

private slots:
    void send();
    void startTransfer();
    void updateClientProgress(qint64);
    void displayError(QAbstractSocket::SocketError );
    void openFile();

private:
    Ui::AadlgClientApp *ui;

    QTcpSocket  *tcpClient;
    QFile       *localFile;
    qint64      totalBytes;
    qint64      bytesWritten;   //send
    qint64      bytesToWrite;   //rest
    qint64      loadSize;       //everytime
    QString     fileName;
    QByteArray  outBlock;
};

#endif // AADLGCLIENTAPP_H
