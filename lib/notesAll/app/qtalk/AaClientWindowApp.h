#ifndef AACLIENTWINDOWAPP_H
#define AACLIENTWINDOWAPP_H

#include <QMainWindow>
#include <QTcpServer>
#include <QTcpSocket>
#include <QDialogButtonBox>
#include <QFile>
#include <DefineType.h>

namespace Ui {
class AaClientWindowApp;
}

class AaClientWindowApp : public QMainWindow
{
    Q_OBJECT

public:
    enum readType{
        File,
        Message
    };

    explicit AaClientWindowApp(QWidget *parent = 0);
    ~AaClientWindowApp();
    
    void init();

private slots:
    void acceptConnection();
    //void slotSendMsg();
    void slotReadMsg();
    void slotBtnClicked(QAbstractButton* btn);
    void slotSendFile();
    void slotContinueSendFile(qint64);

private:
    void appendServerText(const QString & text);
    void appendClientText(const QString & text);
    void readFile(QDataStream &ds);
    void readMessage(QDataStream &ds);
    virtual void processData();

private:
    Ui::AaClientWindowApp *ui;
    QTcpSocket* m_pClientSocket;
    QTcpSocket* m_pConnectSocket;
    QTcpServer* m_pClientServer;
    QString     m_fileNameSend, m_fileNameRecevice;
    QFile*      localFile;
    qint64      totalBytesRecevice;
    qint64      bytesRecevice;
    qint64      fileNameSize;
    qint64      totalBytesSend;
    qint64      bytesWrittenSend;
    qint64      bytesToWriteSend;
    qint64      loadSize;
    QByteArray  outBlock;

    static QString ipAddres;
};

#endif // AACLIENTWINDOWAPP_H
