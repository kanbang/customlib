#include "GlodonTestWidget.h"
#include <QDebug>

GlodonTestWidget::GlodonTestWidget(QWidget *parent) :
    QWidget(parent)
{

}

//void UseInterface::show(int first)
//{
//    qDebug()<<"void UseInterface::show(int first)";
//}

void UseInterface::show(int first, int second)
{
    qDebug()<<"void UseInterface::show(int first, int second)";
}

//void SecondUse::show(int first)
//{
//    qDebug()<<"void SecondUse::show(int first)";
//}

//void SecondUse::show(int first, int second)
//{
//    qDebug()<<"void SecondUse::show(int first, int second)";
//}


Combobox::Combobox(QWidget *parent) : QComboBox(parent)
{

}

void Combobox::paintEvent(QPaintEvent *e)
{
    QComboBox::paintEvent(e);
}
