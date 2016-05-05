#ifndef ACLIENTWIDGETAPP_H
#define ACLIENTWIDGETAPP_H

#include <QWidget>
#include <QtNetwork>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

class AClientWidgetApp : public QWidget
{
    Q_OBJECT

public:
    AClientWidgetApp(QWidget* parent  = 0);

private slots:
    void newConnect();
    void readMessage();
    void displayError(QAbstractSocket::SocketError);
    void onBtn();

private:
    void layoutBtn();
    QTcpSocket* tcpSocket;
    QString     message;
    quint16 blockSize;
    QLabel* m_label;
    QLabel* m_label1;
    QLabel* messageLabel;
    QLineEdit* hostLineEdit;
    QLineEdit* portLineEdit;
    QPushButton* pushButton;
};


#endif // ACLIENTWIDGETAPP_H
