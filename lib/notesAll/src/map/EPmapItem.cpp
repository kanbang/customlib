#include "EPmapItem.h"

EPmapItem::EPmapItem(QObject *parent) :
    QObject(parent)
{
}

EPmapItem::~EPmapItem()
{
    foreach(EPmapItem* item, m_children){
        if(item)
            delete item;
    }
    m_children.clear();
}

EPmapItem* EPmapItem::clone()
{
    EPmapItem* item = new EPmapItem(*this);
    return item;
}

EPmapItem::EPmapItem(const EPmapItem &orig) : QObject(0)
{
    assign(orig);
}

EPmapItem& EPmapItem::operator =(const EPmapItem& pother)
{
    assign(pother);
    return *this;
}
/**
  @fn   对对象赋值之前进行判断
 */
bool EPmapItem::assignItem(EPmapItem *pother)
{
    if(!pother) return false;
    if(this == pother) return false;
    if(type() != pother->type()) return false;

    assign(*pother);
    return true;
}
/**
    主要是使各个类的子类能够通过重载这个函数来对自己的成员变量进行赋值
    同时，由于赋值、拷贝、克隆都需要这段代码，因此封装成一个函数比较好
 */
void EPmapItem::assign(const EPmapItem &other)
{
    EPmapItem* pItem;
    foreach(EPmapItem* item, m_children){
        pItem = item;
        if(pItem) delete pItem;
    }
    m_children.clear();
    foreach(EPmapItem* item, other.m_children){
        pItem = item;
        if(pItem){
            EPmapItem* pClone = pItem->clone();
            pClone->m_parent = this;
            m_children.append(pClone);
        }
    }
}

EPmapItemType EPmapItem::type() const
{
    return epMapNull;
}

int EPmapItem::getHandleCount()
{
    return 0;
}

QPoint EPmapItem::getHandle(int handle)
{
    return QPoint();
}

QCursor EPmapItem::getHandleCursor(int handle)
{
    return QCursor(Qt::ArrowCursor);
}

void EPmapItem::moveHandleTo(const QPoint &pos, int index)
{

}

void EPmapItem::insertHandle(const QPoint &pos, int before)
{

}

void EPmapItem::removeHandle(int handle)
{

}

void EPmapItem::OnLButtonDown(QWidget *widget, QMouseEvent *e)
{

}

void EPmapItem::OnLButtonUp(QWidget *widget, QMouseEvent *e)
{

}

void EPmapItem::OnButtonDoubleClk(QWidget *widget, QMouseEvent *e)
{

}

void EPmapItem::OnMoveMouse(QWidget *widget, QMouseEvent *e)
{

}
