#include "AaImagePixelColor.h"
#include <QPaintEvent>
#include <QPainter>
#include <QResizeEvent>
#include <QDebug>

AaImagePixelColor::AaImagePixelColor(QWidget *parent) :
    QWidget(parent)
{
    resize(400,400);
    buildImage(size().width(),size().height());
}

void AaImagePixelColor::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    painter.drawImage(e->rect(),*m_image);
}

/**
  QRgb 是个int 值
 */
void AaImagePixelColor::buildImage(int width, int height)
{
    m_image = new QImage(QSize(width,height),QImage::Format_ARGB32_Premultiplied);
//    QRgb rgb;
//    for(int i = 0; i<width; i++)
//        for(int j = 0; j <height; j++){
//            rgb = qRgb(qrand()%255,qrand()%255,256);
//            QColor col(rand());
//            m_image->setPixel(i,j,col.rgb());
//        }
    interpolation(width,height);

    /*******
        painter.save();
        QPainterPath path;
        path.addPolygon(m_clipRect);
        painter.setClipping(true);
        painter.setClipPath(path);
        painter.setBrushOrigin(m_clipRect.boundingRect().topLeft());
        painter.setBrush(m_clipPixmap);
        painter.drawPolygon(m_clipRect);
        painter.restore();
     */
}

void AaImagePixelColor::resizeEvent(QResizeEvent *e)
{
    buildImage(e->size().width(),e->size().height());
}

void AaImagePixelColor::interpolation(int width, int height)
{
    QRgb rgb;
    int r = 0;
    int g = 255;
    int b = 0;
    QLine line(0,0,width,height);
    for(int i = 0; i< width; i++){
        for(int j = 0; j< height; j++){
//            if((i>=100 && i<=300) && (j>=100 && j<=300)){
//                QColor col(Qt::red ||Qt::green||Qt::yellow);
//                rgb = qRgb(211,1,1);
//                m_image->setPixel(i,j,col.rgb());
//                qDebug()<<"xkd";
//            } else{
//                QColor col(Qt::blue);
//                rgb = qRgb(200,200,200);
//                m_image->setPixel(i,j,col.rgb());
//                qDebug()<<"zsh";
//            }
            if(i == j){
                QColor col(Qt::blue);
                m_image->setPixel(i,j,col.rgba());
            } else if(i>j){
                QColor col(Qt::red);
                m_image->setPixel(i,j,col.rgba());
            } else {
                QColor col(Qt::green);
                m_image->setPixel(i,j,col.rgba());
            }
        }
    }
}
