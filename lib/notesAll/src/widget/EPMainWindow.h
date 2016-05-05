#ifndef EPMAINWINDOW_H
#define EPMAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class EPMainWindow;
}

class EPMainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit EPMainWindow(QWidget *parent = 0);
    ~EPMainWindow();
    
    void mousePressEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);
    void mouseDoubleClickEvent(QMouseEvent *e);
    void paintEvent(QPaintEvent *);

private:
    Ui::EPMainWindow *ui;
    QPolygon    gon;
    bool        m_isAddPoint;
    QRect     rect;
    bool        m_isLBDown;
};

#endif // EPMAINWINDOW_H
