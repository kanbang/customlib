#include "EPMateObject.h"
#include <QDebug>
#include <QWidget>

EPMateObject::EPMateObject(QObject *parent) :
    QObject(parent)
{
    _id = "zhengsihua";
    m_widget = new QWidget();
    connect(this, SIGNAL(valueChanged(const QString&)), this, SLOT(slotValueChange(const QString&)));
}

void EPMateObject::setId(const QString &newId)
{
    qDebug()<<__PRETTY_FUNCTION__<<newId <<"   "<<_id;
    _id = newId;
    qDebug()<<__PRETTY_FUNCTION__<<newId <<"   "<<_id;
    emit valueChanged(newId);
}

const QString &EPMateObject::getId() const
{
    return _id;
}

void EPMateObject::setWidget(QWidget *widget)
{
    m_widget = widget;
}

QWidget *EPMateObject::getWidget()
{
    return m_widget;
}

void EPMateObject::execute()
{
    qRegisterMetaType<QWidget*>("QWidget*");

    EPMateObject* obj = new EPMateObject();
    obj->setProperty("id","xingkongdao");

//    QVariant v =  new QWidget();
//    obj->setProperty("widget",v);
}

void EPMateObject::slotValueChange(const QString& id)
{
    qDebug()<<"slotValueChange "<<__PRETTY_FUNCTION__<<id;
}
