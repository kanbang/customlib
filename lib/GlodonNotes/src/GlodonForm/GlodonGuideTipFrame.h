#ifndef GLODONGUIDETIPFRAME_H
#define GLODONGUIDETIPFRAME_H

#include "glodonform_global.h"

#include <QWidget>
#include <QDialog>

class GLODONFORMSHARED_EXPORT GlodonGuideTipFrame : public QWidget
{
public:
    GlodonGuideTipFrame(const QString &fileName, QPoint &p, QWidget *parent = 0, Qt::Corner corner = Qt::TopLeftCorner);
    ~GlodonGuideTipFrame();

public:
    void moveByCorner(QPoint &p, Qt::Corner corner);

    void setPixmap(const QString &fileName);

protected:
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *);

private:
    QPixmap m_tipImage;

};

class QTimer;
class GLODONFORMSHARED_EXPORT GlodonDialog : public QDialog
{
    Q_OBJECT

public:
    GlodonDialog(QWidget *parent = 0);

public slots:
    void onFocusOutClose();

protected:
    void paintEvent(QPaintEvent *);
    void focusOutEvent(QFocusEvent * event);
    void mousePressEvent(QMouseEvent *);
private:
    QPixmap m_tipImage;
    QTimer *timer;
};

#endif // GLODONGUIDETIPFRAME_H
