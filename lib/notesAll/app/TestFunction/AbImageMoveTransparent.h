#ifndef ABIMAGEMOVETRANSPARENT_H
#define ABIMAGEMOVETRANSPARENT_H

#include <QWidget>
#include <EPmapImage.h>

class AbImageMoveTransparent : public QWidget
{
    Q_OBJECT
public:
    explicit AbImageMoveTransparent(QWidget *parent = 0);

    void setDrawImage();
    void paintRect(QPainter &painter,const QRect &rect);

protected:
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);
//    void mouseReleaseEvent(QMouseEvent *);
    void mouseDoubleClickEvent(QMouseEvent *);

private:
    bool m_isSelectedRect;
    int m_cursorState;
    EPmapImage *m_cImage;
};

#endif // ABIMAGEMOVETRANSPARENT_H
