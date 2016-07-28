#ifndef AAIMAGEPIXELCOLOR_H
#define AAIMAGEPIXELCOLOR_H

#include <QWidget>

class AaImagePixelColor : public QWidget
{
    Q_OBJECT
public:
    explicit AaImagePixelColor(QWidget *parent = 0);

    void buildImage(int width, int height);
    void interpolation(int width, int height);

protected:
    virtual void paintEvent(QPaintEvent *);
    virtual void resizeEvent(QResizeEvent *);

private:
    QImage *m_image;
    QList<QPoint> m_points;
    QList<QColor> m_colors;
    QList<int>    m_values;
};

#endif // AAIMAGEPIXELCOLOR_H
