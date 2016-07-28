#ifndef AASERVERWINDOWAPP_H
#define AASERVERWINDOWAPP_H

#include <QMainWindow>
#include <QTcpServer>
#include <QTcpSocket>
#include <QDialogButtonBox>
#include <QFile>
//#include <DefineType.h>

namespace Ui {
class AaServerWindowApp;
}

class AaServerWindowApp : public QMainWindow
{
    Q_OBJECT

public:
    enum readType{
        File,
        Message
    };

    explicit AaServerWindowApp(QWidget *parent = 0);
    ~AaServerWindowApp();

    void init();

protected:
    void focusInEvent(QFocusEvent *);

private slots:
    void acceptConnection();
    //void slotSendMsg();
    void slotReadMsg();
    void slotBtnClicked(QAbstractButton* btn);
    void slotSendFile();
    void slotContinueSendFile(qint64 number);

private:
    void appendServerText(const QString & text);
    void appendClientText(const QString & text);
    void readFile(QDataStream &ds);
    void readMessage(QDataStream &ds);
    virtual void processData();

private:
    Ui::AaServerWindowApp *ui;
    QTcpServer* m_pServerServer;
    QTcpSocket* m_pConnectSocket;
    QTcpSocket* m_pServerSocket;
    QString     m_fileNameSend, m_fileNameRecevice;
    QFile*      localFile;
    QByteArray  outBlock;
    qint64      totalBytesRecevice;
    qint64      bytesRecevice;
    qint64      fileNameSize;
    qint64      totalBytesSend;
    qint64      bytesWrittenSend;
    qint64      bytesToWriteSend;
    qint64      localSize;

    static QString ipAddres;
};

#endif // AASERVERWINDOWAPP_H
