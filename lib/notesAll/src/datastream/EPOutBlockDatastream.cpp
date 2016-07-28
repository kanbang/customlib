#include "EPOutBlockDatastream.h"
#include <QDataStream>
#include <QDebug>

EPOutBlockDatastream::EPOutBlockDatastream()
{
}

void EPOutBlockDatastream::showData()
{
    QDataStream ds(&outBlock,QIODevice::WriteOnly);
    ds.setVersion(QDataStream::Qt_4_6);
    ds << "xingkongdao";

    qDebug()<<outBlock.constData();
}
