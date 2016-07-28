#include "EPEffective.h"
#include <QDebug>

EPEffective::EPEffective(QObject *parent) :
    QObject(parent)
{
    pos = QPoint(2,3);
    text = "xingkongdao";

}

const char& EPEffective::operator [](int position)const
{
    return text[position];
}

char& EPEffective::operator [](int position)
{
    return const_cast<char&>(static_cast<const EPEffective&>(*this)[position]);
}

const QPoint& EPEffective::getPoint() const
{
    return pos;
}


// 决不重新定义继承而来的缺省参数值
void Shape::doDraw(ShapeColor color) const
{
    qDebug()<<" Shape :: "<<color;
}

void Rectangle::doDraw(ShapeColor color) const
{
    qDebug()<<" Rectangle :: "<< color;
}

void Circle::doDraw(ShapeColor color) const
{
    qDebug()<<" Circle :: "<< color;
}
