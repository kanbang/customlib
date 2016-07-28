#ifndef ADSCROLLAREAVIEW_H
#define ADSCROLLAREAVIEW_H

#include <QAbstractScrollArea>

class AdScrollAreaView : public QAbstractScrollArea
{
    Q_OBJECT
public:
    explicit AdScrollAreaView(QWidget *parent = 0);
    
    void setRect(QRect rect);

protected:
    void resizeEvent(QResizeEvent *);
    void paintEvent(QPaintEvent *);

signals:
    
public slots:
    
private:
    void recalculateContentSzie();

private:
    bool m_bPixmapMustResize, m_bPixmapIsDirty;
    QRect m_bbox;
    QMatrix m_affine;
    int width,height;
    QPixmap pixmapCache;
};

#endif // ADSCROLLAREAVIEW_H
