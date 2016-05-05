#include "AbUdpWidgetApp.h"
#include <cstdlib>

AbUdpWidgetApp::AbUdpWidgetApp(QWidget *parent) :
    QPushButton(parent)
{
    connect(this, SIGNAL(clicked()), this, SLOT(close()));
    connect(&timer, SIGNAL(timeout()), this, SLOT(sendDatagram()));

    timer.start(2 * 1000);

    setWindowTitle(tr("Weather Balloon"));
}

double AbUdpWidgetApp::temperature() const
{
    return -20.0 + (2.0 * std::rand() / (RAND_MAX + 1.0));
}

double AbUdpWidgetApp::humidity() const
{
    return 20.0 + (2.0 * std::rand() / (RAND_MAX + 1.0));
}

double AbUdpWidgetApp::altitude() const
{
    return 7000 + (100.0 * std::rand() / (RAND_MAX + 1.0));
}

void AbUdpWidgetApp::sendDatagram()
{
    QByteArray datagram;
    QDataStream out(&datagram, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_3);
    out << QDateTime::currentDateTime() << temperature() << humidity()
        << altitude();

    udpSocket.writeDatagram(datagram, QHostAddress::LocalHost, 5824);
}
