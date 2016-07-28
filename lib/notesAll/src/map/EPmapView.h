#ifndef EPMAPVIEW_H
#define EPMAPVIEW_H

#include <QAbstractScrollArea>

class EPmapView : public QAbstractScrollArea
{
    Q_OBJECT
public:
    explicit EPmapView(QWidget *parent = 0);

    void setScaleZoom();
};

#endif // EPMAPVIEW_H
