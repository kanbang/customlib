#ifndef EPMAPITEM_H
#define EPMAPITEM_H

#include <QObject>
#include <QMouseEvent>
#include <QWidget>

enum EPmapItemType
{
    epMapNull,
    epMapDoc,
    epMapRect,
    epMapLine,
    epMapEllipse
};

/**
    超基类对象，不能复制，因此在外面被创建，但是可以指向他的子类。
    对象的创建，并不是写个类就行了。
    考虑的问题：
    1、类的赋值  operator=(const EPmapItem &other);
    2、类的拷贝
    3、类的运算符重载
    4、类的克隆
    5、这个类要操作的数据

*/
class EPmapItem : public QObject
{
    Q_OBJECT

public:
    virtual ~EPmapItem();
    virtual EPmapItem* clone();
    virtual bool assignItem(EPmapItem* pother);

    EPmapItem& operator=(const EPmapItem& other);

    virtual EPmapItemType type() const;

public:
    virtual int     getHandleCount();
    virtual QPoint  getHandle(int handle);
    virtual QCursor getHandleCursor(int handle);
    virtual void    moveHandleTo(const QPoint& pos, int index = -1);
    virtual void    insertHandle(const QPoint& pos, int before = -1);
    virtual void    removeHandle(int handle);
    virtual void    OnLButtonDown(QWidget* widget, QMouseEvent* e);
    virtual void    OnLButtonUp(QWidget* widget, QMouseEvent* e);
    virtual void    OnButtonDoubleClk(QWidget* widget, QMouseEvent* e);
    virtual void    OnMoveMouse(QWidget* widget, QMouseEvent* e);

private:
    void assign(const EPmapItem& other);

    explicit EPmapItem(QObject *parent = 0);
    EPmapItem(const EPmapItem& orig);

private:
    QList<EPmapItem*> m_children;
    EPmapItem* m_parent;
};

#endif // EPMAPITEM_H
