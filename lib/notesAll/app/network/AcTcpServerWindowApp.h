#ifndef ACTCPSERVERWINDOWAPP_H
#define ACTCPSERVERWINDOWAPP_H

#include <QMainWindow>
#include <QtNetwork>
#include <QMessageBox>
#include <map>
using namespace std;

namespace Ui {
class AcTcpServerWindowApp;
}
/**
 * @brief
    服务端：
        QTcpServer 用来监控某端口，一旦有客户端请求链接成功，立刻发射 newConnect()信号。
        同时通过QTcpServer::nextPendingConnect()获得 一个QTcpSocket对象，这个对象的作用
        是当客户端的QTcpSocket对象调用write()函数写入数据传递到服务端的时候，可以用服务端的
        QTcpSocket接收数据。

    客户端：
        QTcpSocket::readyRead();当客户端的数据到达端口的时候，服务端的QTcpSocket会发射
        readyRead()信号。
        当客户端的通过write()这个函数传递完数据后，客户端的QTcpSocket会发射byteswritten(qint64)
        信号。

 */

class AcTcpServerWindowApp : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit AcTcpServerWindowApp(QWidget *parent = 0);
    ~AcTcpServerWindowApp();

private slots:
    void slotStartServer();
    void slotConnectServer();
    void slotSendMesg();
    void slotNewConnect();
    void slotReadMesg();

private:
    Ui::AcTcpServerWindowApp *ui;

    QTcpServer *m_pTcpServer;
    QTcpSocket *m_pTcpSocket;
    map <int,QTcpSocket*> map_TcpSocket;

    QTcpSocket *pTcpSocketServer;
    QTcpSocket *pTcpSocketClient;
    QByteArray array;
    bool isServer;
};

#endif // ACTCPSERVERWINDOWAPP_H
