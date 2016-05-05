#ifndef GLODONTESTWIDGET_H
#define GLODONTESTWIDGET_H

#include <QtWidgets/QWidget>

#include "glodontestlib_global.h"

class WIDGETSHARED_EXPORT GlodonTestWidget : public QWidget
{
    Q_OBJECT

public:
    GlodonTestWidget(QWidget* parent = 0);

};

class WIDGETSHARED_EXPORT Interface
{
public:
    ~Interface(){}

    virtual void show(int first, int second = 0) = 0;
};

class WIDGETSHARED_EXPORT UseInterface : public Interface
{
public:
    UseInterface(){}
    ~UseInterface() {}

//    void show(int first);
    virtual void show(int first, int second);
};

//class WIDGETSHARED_EXPORT SecondUse : public UseInterface
//{
//public:
//    SecondUse() {}
//    ~SecondUse() {}

//    void show(int first);
////    void show(int first, int second);
//};
#include <QComboBox>

class WIDGETSHARED_EXPORT Combobox : public QComboBox
{
    Q_OBJECT
public:
    Combobox(QWidget *parent = 0);

protected:
    void paintEvent(QPaintEvent *e);
};

#endif // GLODONTESTWIDGET_H
