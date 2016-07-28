#ifndef CLIENTSOCKETOBJ_H
#define CLIENTSOCKETOBJ_H

#include <QTcpSocket>

class ClientSocketObj : public QTcpSocket
{
    Q_OBJECT
public:
    explicit ClientSocketObj(QObject *parent = 0);
    
private slots:
    void readClient();

private:
    void generateRandomTrip(const QString &from, const QString &to,
                            const QDate &date, const QTime &time);

    quint16 nextBlockSize;
    
};

#endif // CLIENTSOCKETOBJ_H
