#include "GlodonGuideTipFrame.h"

#include <QBitmap>
#include <QPainter>

GlodonGuideTipFrame::GlodonGuideTipFrame(const QString &fileName, QPoint &p, QWidget *parent, Qt::Corner corner)
    : QWidget(parent), m_tipImage(QPixmap(fileName))
{
    resize(m_tipImage.size());
    setMask(m_tipImage.mask());

    moveByCorner(p, corner);
}

GlodonGuideTipFrame::~GlodonGuideTipFrame()
{

}

void GlodonGuideTipFrame::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.drawPixmap(0, 0, m_tipImage);
}

void GlodonGuideTipFrame::mousePressEvent(QMouseEvent *)
{
    this->hide();
}

void GlodonGuideTipFrame::moveByCorner(QPoint &p, Qt::Corner corner)
{
    QPoint movePoint = p;
    switch (corner)
    {
    case Qt::TopLeftCorner:
    {
        break;
    }
    case Qt::TopRightCorner:
    {
        movePoint.setX(p.x() - m_tipImage.width());
        break;
    }
    case Qt::BottomLeftCorner:
    {
        movePoint.setY(p.y() - m_tipImage.height());
        break;
    }
    case Qt::BottomRightCorner:
    {
        movePoint.setX(p.x() - m_tipImage.width());
        movePoint.setY(p.y() - m_tipImage.height());
        break;
    }
    default:
    {
        return;
    }
    }
    move(movePoint);
}

void GlodonGuideTipFrame::setPixmap(const QString &fileName)
{
    m_tipImage = QPixmap(fileName);
}


#include <QTimer>
GlodonDialog::GlodonDialog(QWidget *parent)
    : QDialog(parent), m_tipImage(QPixmap(":Forms.png"))
{
//    setWindowFlags();
    this->setWindowFlags(Qt::FramelessWindowHint);//去掉标题栏
//    this->setGeometry(QRect(950, 55, 350, 250));//可设置窗口显示的方位与大小

//    this->setWindowOpacity(0.7);//设置透明1-全体透明
    this->setAttribute(Qt::WA_TranslucentBackground, true);//设置透明2-窗体标题栏不透明,背景透明
    resize(m_tipImage.size());
//    setMask(m_tipImage.mask());
//    setAttribute(Qt::WA_PaintOnScreen,true);
//    setWindowFlags();
//    QTimer::singleShot(200,this, SLOT(onFocusOutClose()));
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(onFocusOutClose()));
    timer->start(1000);
//    QTimer::singleShot(100, this, SLOT(onFocusOutClose()));

}

void GlodonDialog::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setOpacity(0.8);
    painter.drawPixmap(0,0,m_tipImage);

}
#include <QDebug>

void GlodonDialog::focusOutEvent(QFocusEvent *event)
{
    qDebug()<<__FUNCTION__;
}

void GlodonDialog::mousePressEvent(QMouseEvent *)
{
    close();
    accept();
    delete timer;
    delete this;

}

void GlodonDialog::onFocusOutClose()
{
    if(!isActiveWindow())
    {
        close();
        delete timer;
        delete this;
    }
}
