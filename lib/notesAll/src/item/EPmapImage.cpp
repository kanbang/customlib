#include "EPmapImage.h"
#include <QPainter>
#include <QCursor>
#include <QDebug>

EPmapImage::EPmapImage(QObject *parent) :
    QObject(parent)
{

}

void EPmapImage::setRect(const QRect rect)
{
    this->rect = rect;
}

const QRect& EPmapImage::getRect()
{
    return rect;
}

void EPmapImage::setImage(QImage image)
{
    this->image = image;
}

void EPmapImage::setImageSize()
{
    image = image.scaled(rect.width(),rect.height());
    setImageAlpha();
}

void EPmapImage::setImageAlpha()
{
    QRgb rgb;
    for(int i = 0;i<rect.width();i++)
        for(int j = 0; j<rect.height(); j++)
        {
        QRgb rgb1 = image.pixel(i,j);
        rgb = qRgba(qRed(rgb1),qGreen(rgb1),qBlue(rgb1),200);
        image.setPixel(i,j,rgb);
    }
}

QImage& EPmapImage::getImage()
{
    return image;
}

int EPmapImage::getHandleCount()
{
    return 8;
}

QCursor EPmapImage::getHandleCursor(int nHandle)
{
    Qt::CursorShape id = Qt::ArrowCursor;
    switch (nHandle)
    {
    case 0:
        id = Qt::SizeAllCursor;
        break;
    case 1:
    case 5:
        id = Qt::SizeBDiagCursor;
        break;
    case 2:
    case 6:
        id = Qt::SizeVerCursor;
        break;
    case 3:
    case 7:
        id = Qt::SizeFDiagCursor;
        break;
    case 4:
    case 8:
        id = Qt::SizeHorCursor;
        break;
    }

    return QCursor(id);
}

QPoint EPmapImage::getHandle(int nHandle)
{
    int x = 0, y = 0, xCenter,yCenter;
    xCenter = rect.center().x();
    yCenter = rect.center().y();

    switch (nHandle)
    {
    case 0:
        x = xCenter;
        y = yCenter;
        break;

    case 1:
        x = rect.right();
        y = rect.top();
        break;

    case 2:
        x = xCenter;
        y = rect.top();
        break;

    case 3:
        x = rect.left();
        y = rect.top();
        break;

    case 4:
        x = rect.left();
        y = yCenter;
        break;

    case 5:
        x = rect.left();
        y = rect.bottom();
        break;

    case 6:
        x = xCenter;
        y = rect.bottom();
        break;

    case 7:
        x = rect.right();
        y = rect.bottom();
        break;

    case 8:
        x = rect.right();
        y = yCenter;
        break;
    }

    return QPoint(x,y);
}

void EPmapImage::moveHandleTo(QPoint &newPos, int index)
{
    switch (index)
    {
        case 0:
            rect.moveCenter(newPos);
            break;
        case 1:
            rect.setTopRight(newPos);
            break;

        case 2:
            rect.setTop(newPos.y());
            break;

        case 3:
            rect.setTopLeft(newPos);
            break;

        case 4:
            rect.setLeft(newPos.x());
            break;

        case 5:
            rect.setBottomLeft(newPos);
            break;

        case 6:
            rect.setBottom(newPos.y());
            break;

        case 7:
            rect.setBottomRight(newPos);
            break;

        case 8:
            rect.setRight(newPos.x());
            break;
        default:
            break;
    }
    rect = rect.normalized();
}

void EPmapImage::paint(QPainter &painter, QWidget *view)
{
    setImageSize();
    painter.drawLine(rect.topLeft() + QPoint(-20,-20),rect.bottomRight() + QPoint(20,20));
    painter.drawPixmap(rect.topLeft(),QPixmap::fromImage(image));
    //painter.drawRect(rect);

}
