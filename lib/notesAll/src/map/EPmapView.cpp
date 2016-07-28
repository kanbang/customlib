#include "EPmapView.h"
#include <QMatrix>
#include <QPoint>
#include <QDebug>

EPmapView::EPmapView(QWidget *parent) :
    QAbstractScrollArea(parent)
{
    setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
}

void EPmapView::setScaleZoom()
{
    int x = 10,y = 2;

    QMatrix matrix;
    matrix.scale(x,y);
    matrix.translate(-1,-1);
    QPoint pos(100,100);
    qDebug()<<matrix.map(pos) <<matrix;
}
