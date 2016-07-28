#include "EPMainWindow.h"
#include "ui_EPMainWindow.h"
#include <QMouseEvent>
#include <QPainter>
#include <QDebug>
#include <QLayout>

EPMainWindow::EPMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::EPMainWindow)
{
    setMouseTracking(true);
    ui->setupUi(this);
//    ui->tabWidget->hide();
    m_isAddPoint = false;
    m_isLBDown = false;
    QLayout* layout = this->layout();
//    layout->removeWidget(ui->toolBar);
    int i = layout->indexOf(ui->toolBar);
    layout->takeAt(i);
    ui->toolBar->move(100,100);
//    QLayout *layout = this->layout();
    layout->addWidget(ui->toolBar);
}

EPMainWindow::~EPMainWindow()
{
    delete ui;
}

void EPMainWindow::mouseDoubleClickEvent(QMouseEvent *e)
{
    if(m_isAddPoint)
    {
       gon.append(e->pos());
       gon.append(gon.at(0));
       m_isAddPoint = false;
    }
}

void EPMainWindow::mouseMoveEvent(QMouseEvent *e)
{
    if(m_isAddPoint)
    {
        gon[gon.count()-1] = e->pos();
    }
    rect.setBottomRight(e->pos());
    repaint();
}

void EPMainWindow::mousePressEvent(QMouseEvent *e)
{
    m_isLBDown  = true;
    if(m_isAddPoint)
    {
        gon.insert(gon.count(),e->pos());
    }
    rect.setTopLeft(e->pos());
    repaint();
}

void EPMainWindow::mouseReleaseEvent(QMouseEvent *e)
{
    m_isLBDown = true;
    if(!m_isAddPoint)
    {
//        gon.clear();
        gon.append(e->pos());
        gon.append(e->pos());
        m_isAddPoint = true;
    }
    repaint();
    qDebug()<<__PRETTY_FUNCTION__;
}

void EPMainWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

//    painter.drawPolygon(gon);
    painter.drawRect(rect);
}
