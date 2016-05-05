#ifndef EPEFFECTIVE_H
#define EPEFFECTIVE_H

#include <QObject>
#include <QDebug>
#include <iostream>
#include <QPoint>
#include <string>
using namespace std;

class EPEffective : public QObject
{
    Q_OBJECT
public:
    explicit EPEffective(QObject *parent = 0);
    const char& operator[](int position)const;
    char& operator[](int position);

    const QPoint& getPoint() const;
private:
    bool lengthIsValid;
    string text;
    QPoint pos;
};

// 决不重新定义继承而来的缺省参数值
class Shape
{
public:
    enum ShapeColor { Red,Green,Blue };
    void draw(ShapeColor color = Red) const
    {
        qDebug()<<"Shape Draw";
        doDraw(color);
    }
    virtual ~Shape() {}
private:
    virtual void doDraw(ShapeColor color) const = 0;
};

class Rectangle : public Shape {
public:
//    void draw(ShapeColor color) const
//    {
//        doDraw(color);
//    }
    virtual ~Rectangle(){}
private:
    virtual void doDraw(ShapeColor color) const;
};

class Circle : public Shape {
public:
//    void draw (ShapeColor color ) const
//    {
//        doDraw(color);
//    }
    virtual ~Circle() {}
private:
    virtual void doDraw(ShapeColor color) const;
};

////将文件间的编译依存关系降至最低
//class Person {
//public:
//    Person(const std::string &name,const QDate& birthday,const QString& addr);
//};


//确定你的public继承塑模出is－a关系

#endif // EPEFFECTIVE_H
