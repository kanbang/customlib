#include "EPObject.h"
#include <QDebug>

EPObject::EPObject(QObject *parent) :
    QObject(parent)
{
}

void EPObject::getAction()
{
    qDebug()<<__PRETTY_FUNCTION__;
}
