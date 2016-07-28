#ifndef ASERVERWIDGETAPP_H
#define ASERVERWIDGETAPP_H

#include <QWidget>
#include <QtNetwork>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

class AServerWidgetApp : public QWidget
{
    Q_OBJECT

public:
    explicit AServerWidgetApp(QWidget *parent = 0);

private slots:
    void sendMessage();

private:
    QLabel*         m_label;
    QTcpServer*     tcpServer;
};

#endif // ASERVERWIDGETAPP_H
