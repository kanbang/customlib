#ifndef ABUDPWIDGETAPP_H
#define ABUDPWIDGETAPP_H

#include <QPushButton>
#include <QtNetwork>

class AbUdpWidgetApp : public QPushButton
{
    Q_OBJECT
public:
    explicit AbUdpWidgetApp(QWidget *parent = 0);

    double temperature() const;
    double humidity() const;
    double altitude() const;

private slots:
    void sendDatagram();

private:
    QUdpSocket udpSocket;
    QTimer timer;
};

#endif // ABUDPWIDGETAPP_H
