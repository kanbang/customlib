#ifndef EPMAPIMAGE_H
#define EPMAPIMAGE_H

#include <QObject>
#include <QRect>
#include <QImage>

class EPmapImage : public QObject
{
    Q_OBJECT

public:
    explicit EPmapImage(QObject *parent = 0);

    void setRect(const QRect rect);
    void setImage(QImage image);
    void setImageSize();
    void setImageAlpha();

    const QRect &getRect();
    QImage& getImage();

    int     getHandleCount();
    QCursor getHandleCursor(int nHandle);
    QPoint  getHandle(int nHandle);
    void    moveHandleTo(QPoint &newPos, int index);
    virtual void paint(QPainter &painter,QWidget *view = 0);


private:
    QImage image;
    QRect rect;
};

#endif // EPMAPIMAGE_H
