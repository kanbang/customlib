#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QMouseEvent>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setMouseTracking(true);
    m_bLBDown = false;
    m_pTable = new EPlogTable();
    m_cachePixmap = QPixmap(size());
    m_cachePixmap.fill(Qt::white);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter painter;
    painter.begin(&m_cachePixmap);
    m_cachePixmap.fill(Qt::white);
    m_pTable->drawForeground(&painter,this);
    m_pTable->paint(&painter,this);
    painter.end();

    painter.begin(this);
    painter.drawPixmap(0,0,m_cachePixmap);
    painter.end();
}

void MainWindow::mouseMoveEvent(QMouseEvent *e)
{
    if(m_bLBDown)
    {
        m_rect.setBottomRight(e->pos());
        m_pTable->setFocusRect(m_rect);
    }
    update();
}

void MainWindow::mousePressEvent(QMouseEvent *e)
{
    m_bLBDown = true;
    m_rect.setTopLeft(e->pos());
    m_rect.setBottomRight(e->pos());
    m_pTable->setFocusRect(m_rect);
    update();
}

void MainWindow::mouseDoubleClickEvent(QMouseEvent *e)
{

}

void MainWindow::mouseReleaseEvent(QMouseEvent *e)
{
    m_bLBDown = false;
    m_pTable->setRect(m_rect);
//    m_pTable->setFocusRect(QRect(0,0,0,0));
    m_pTable->calPos();
    m_pTable->removeColumn(1);
    m_pTable->insertRow(2,"xkd");
    m_pTable->calPos();
    update();
}

void MainWindow::resizeEvent(QResizeEvent *)
{
    m_cachePixmap = m_cachePixmap.scaled(size());
}
