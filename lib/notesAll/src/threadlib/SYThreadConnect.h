#ifndef SYTHREADCONNECT_H
#define SYTHREADCONNECT_H

#include <QObject>
#include <QThread>

class SYThreadConnect : public QObject
{
    Q_OBJECT
public:
    explicit SYThreadConnect(QObject *parent = 0);
    
signals:
    
public slots:
    
};

class oneThread : public QThread
{
    Q_OBJECT

public:
    oneThread(QObject *parent = 0);

};

#endif // SYTHREADCONNECT_H
