#include "AdScrollAreaView.h"
#include <QScrollBar>
//#include <QResizeEvent>
#include <QDebug>
#include <QPainter>
#include <QMatrix>

AdScrollAreaView::AdScrollAreaView(QWidget *parent) :
    QAbstractScrollArea(parent)
{
    m_bPixmapMustResize = true;
    m_bPixmapIsDirty = false;
}

void AdScrollAreaView::setRect(QRect rect)
{
    m_bbox = rect;
    recalculateContentSzie();
}

void AdScrollAreaView::resizeEvent(QResizeEvent *e)
{
    qDebug()<< viewport()->geometry();
    QAbstractScrollArea::resizeEvent(e);
    recalculateContentSzie();
}

void AdScrollAreaView::paintEvent(QPaintEvent *e)
{
    if(m_bbox.isNull())
        QAbstractScrollArea::paintEvent(e);

    QPainter painter;
    if(m_bPixmapMustResize){
        pixmapCache = QPixmap(viewport()->size());
        QColor bgColor = QColor(Qt::darkGray);
        pixmapCache.fill(bgColor);
        m_bPixmapIsDirty = true;
    }
    if(m_bPixmapIsDirty){
        painter.begin(&pixmapCache);

    }
}

void AdScrollAreaView::recalculateContentSzie()
{
    if(!m_bbox.isNull()){
        width = viewport()->width();
        height = viewport()->height();
        if(m_bbox.width() > width){
            horizontalScrollBar()->setRange(0,m_bbox.width()-width);
            qDebug()<<__PRETTY_FUNCTION__<<horizontalScrollBar()->minimum() <<horizontalScrollBar()->maximum();
        } else
            horizontalScrollBar()->setRange(0,0);

        if(m_bbox.height() > height){
            verticalScrollBar()->setRange(0,m_bbox.height() - height);
            qDebug()<<verticalScrollBar()->minimum() <<verticalScrollBar()->maximum();
        } else
            verticalScrollBar()->setRange(0,0);
    }
}
