#ifndef EPDBUSCLIENT_H
#define EPDBUSCLIENT_H

#include <QObject>

class EPDbusClient : public QObject
{
    Q_OBJECT
public:
    explicit EPDbusClient(QObject *parent = 0);
    
signals:
    
public slots:
    
};

#endif // EPDBUSCLIENT_H
