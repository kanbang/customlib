#include "AbImageMoveTransparent.h"
#include <ETestHeader.h>

AbImageMoveTransparent::AbImageMoveTransparent(QWidget *parent) :
    QWidget(parent)
{
    setDrawImage();
    resize(400,400);
    QImage& mage = m_cImage->getImage();
    QPainter painter(&mage);
    painter.initFrom(this);
    //painter.drawLine(mage.rect().bottomLeft(),mage.rect().topRight());
}

void AbImageMoveTransparent::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    m_cImage->paint(painter,this);
    if(m_isSelectedRect)
    {
        QRect rect = m_cImage->getRect();
        paintRect(painter,rect);
    }
}

void AbImageMoveTransparent::mousePressEvent(QMouseEvent *e)
{
    if (m_cImage->getRect().contains(e->pos()))
        m_isSelectedRect = true;
    else
        m_isSelectedRect = false;

    repaint();
}

void AbImageMoveTransparent::mouseMoveEvent(QMouseEvent *e)
{
    if(e->buttons() & Qt::LeftButton )
    {
        QPoint pos = e->pos();
        m_cImage->moveHandleTo(pos,m_cursorState);
        repaint();
    }
    else
        for(int i = 0;i<=m_cImage->getHandleCount();i++)
        {
            QRect rect(m_cImage->getHandle(i)- QPoint(3,3),m_cImage->getHandle(i) + QPoint(3,3));
            if(i == 0){
                if(m_cImage->getRect().contains(e->pos()) && m_isSelectedRect){
                    setCursor(m_cImage->getHandleCursor(i));
                    m_cursorState = i;
                }
                else
                    setCursor(QCursor(Qt::ArrowCursor));
            } else {
                if(rect.contains(e->pos()) && m_isSelectedRect){
                    setCursor(m_cImage->getHandleCursor(i));
                    m_cursorState = i;
                }
            }
        }
}

void AbImageMoveTransparent::mouseDoubleClickEvent(QMouseEvent *)
{
    m_isSelectedRect = false;
    m_cursorState = 100;
    repaint();
}

void AbImageMoveTransparent::setDrawImage()
{
    setMouseTracking(true);
    m_cursorState = 100;
    QRegion region;
    setMask(region);
    m_cImage = new EPmapImage;
    QImage image(QSize(100,100),QImage::Format_ARGB32_Premultiplied);
    QString str = ":/back.png";
    image.load(str);
    qDebug()<<__PRETTY_FUNCTION__<<image.format();
    m_cImage->setImage(image.convertToFormat(QImage::Format_ARGB32_Premultiplied));
    QRect rect(100,100,200,200);
    m_cImage->setRect(rect);
    m_cImage->setImageSize();
    m_isSelectedRect = false;
}

void AbImageMoveTransparent::paintRect(QPainter &painter, const QRect &rect)
{
    QPen pen;
    pen.setColor(Qt::red);
    pen.setWidth(2);
    painter.setPen(pen);
    painter.setRenderHints(QPainter::Antialiasing);
    for(int i = 1;i<=m_cImage->getHandleCount();i++)
    {
        painter.drawRect(QRect(m_cImage->getHandle(i)-QPoint(3,3),m_cImage->getHandle(i)+QPoint(3,3)));
    }
}
