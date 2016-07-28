#ifndef EPOBJECT_H
#define EPOBJECT_H

#include <QObject>

class EPObject : public QObject
{
    Q_OBJECT

public:
    explicit EPObject(QObject *parent = 0);

    void getAction();
};

#endif // EPOBJECT_H
