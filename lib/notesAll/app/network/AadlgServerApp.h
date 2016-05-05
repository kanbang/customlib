#ifndef AADLGSERVERAPP_H
#define AADLGSERVERAPP_H

#include <QDialog>
#include <QtNetwork>

namespace Ui {
class AadlgServerApp;
}

class AadlgServerApp : public QDialog
{
    Q_OBJECT
    
public:
    explicit AadlgServerApp(QWidget *parent = 0);
    ~AadlgServerApp();

private slots:
    void start();
    void acceptConnection();
    void updateServerProgress();
    void displayError(QAbstractSocket::SocketError socketError);

private:
    Ui::AadlgServerApp *ui;

    QTcpServer  *tcpServer;
    QTcpSocket  *tcpServerConnection;
    qint64      totalBytes;
    qint64      bytesReceived;
    qint64      fileNameSize;
    QString     fileName;
    QFile       *localFile;
    QByteArray  inBlock;
};

#endif // AADLGSERVERAPP_H
