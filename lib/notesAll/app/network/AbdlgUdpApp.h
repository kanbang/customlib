#ifndef ABDLGUDPAPP_H
#define ABDLGUDPAPP_H

#include <QDialog>
#include <QtNetwork>
#include <QLabel>
#include <QLineEdit>

class AbdlgUdpApp : public QDialog
{
    Q_OBJECT
public:
    explicit AbdlgUdpApp(QWidget *parent = 0);

private slots:
    void processPendingDatagrams();

private:
    QUdpSocket udpSocket;

    QLabel *dateLabel;
    QLabel *timeLabel;
    QLabel *temperatureLabel;
    QLabel *humidityLabel;
    QLabel *altitudeLabel;
    QLineEdit *dateLineEdit;
    QLineEdit *timeLineEdit;
    QLineEdit *temperatureLineEdit;
    QLineEdit *humidityLineEdit;
    QLineEdit *altitudeLineEdit;
};

#endif // ABDLGUDPAPP_H
