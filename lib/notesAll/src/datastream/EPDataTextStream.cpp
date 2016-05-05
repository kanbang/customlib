#include "EPDataTextStream.h"

#include <QString>
#include <QFile>
#include <QPolygon>
#include <QDebug>

EPStream::EPStream()
{
    m_dsFileName = "document";
    m_tsFileName = "document";

    m_as = new InStream;
}

void EPStream::setDsFileName(QString dsFileName)
{
    m_dsFileName = dsFileName;

}

void EPStream::setTsFileName(QString tsFileName)
{
    m_tsFileName = tsFileName;
}

void EPStream::setConcreteStream(AbstractStream *as)
{
    m_as = as;
}

void EPStream::operationDs()
{
    QFile file(m_dsFileName);
    QDataStream ds(&file);
    if(file.open(QFile::WriteOnly)){
        m_as->Input(ds);
    }
    file.close();

    if(file.open(QFile::ReadOnly)){
        m_as->Output(ds);
    }
    file.close();
}

void EPStream::operationTs()
{

}

AbstractStream::AbstractStream()
{

}

AbstractStream::~AbstractStream()
{

}

void AbstractStream::Input(QDataStream &ds)
{
    this->InputDataText(ds);
}

void AbstractStream::Input(QTextStream &ts)
{
    this->InputDataText(ts);
}

void AbstractStream::Output(QDataStream &ds)
{
    this->OutputDataText(ds);
}

void AbstractStream::Output(QTextStream &ts)
{
    this->OutputDataText(ts);
}

InStream::InStream()
{

}

void InStream::InputDataText(QDataStream &ds)
{
    QPolygon gon;
    for(int i = 0; i<1000;i++)
        gon.append(QPoint(i,i));

    ds << gon;
}

void InStream::InputDataText(QTextStream &ts)
{
    QList<int> lists;
    for(int i = 0; i<1000;i++)
        lists.append(i);

  //  ts << lists;
}

void InStream::OutputDataText(QDataStream &ds)
{
    QPolygon gon;
    QIODevice* device = ds.device();
    qint64 pos = device->pos() + 1;

    qDebug()<<device->seek(pos);
    ds >> gon;
    qDebug()<<gon;
}

void InStream::OutputDataText(QTextStream &ds)
{

}
