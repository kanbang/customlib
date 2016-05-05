#ifndef EPVISITOR_H
#define EPVISITOR_H
#include <iostream>
using namespace std;

class ConcreteElementA;
class ConcreteElementB;
class Element;

/**
表示一个作用于某对象结构中的各元素的操作，它使你可以在不改变各元素的类的前提下定义作用于这些元素的新操作。

Visitor 模式把对节点的访问封装成一个抽象基类，通过派生出不同的类生成新的访问方式。在实现的时候，在visitor
抽象基类中声明了对所有不同节点（ElementA、 ElementB）进行访问的接口函数。如例子中的VisitConcreteElementA函数等，
这样就造成了Visitor模式的一个缺陷：

\brief
    新加入一个节点的时候都要添加Visitor中的对其进行访问接口函数，这使得所有的Visitor及其派生类都要重新编译了。
    也就是说Visitor模式的一个缺点就是添加新的节点十分困难。

\brief
    Visitor采用了所谓的‘双重分派’的技术，要对一个节点进行访问，首先需要产生一个Element的派生类对象，其次要传入
    一个Visitor类派生类对象来调用对应的Accept函数，也就是说，到底对哪种Element采用哪种Visitor访问，需要两次动态
    绑定才可以确定下来。
*/

class Visitor
{
public:
    virtual ~Visitor();
    virtual void VisitConcreteElementA(Element* elm) = 0;
    virtual void VisitConcreteElementB(Element* elm) = 0;

protected:
    Visitor();
};

class ConcreteVisitorA : public Visitor
{
public:
    ConcreteVisitorA();
    virtual ~ConcreteVisitorA();
    virtual void VisitConcreteElementA(Element *elm);
    virtual void VisitConcreteElementB(Element *elm);

};

class ConcreteVisitorB : public Visitor
{
public:
    ConcreteVisitorB();
    virtual ~ConcreteVisitorB();
    virtual void VisitConcreteElementA(Element *elm);
    virtual void VisitConcreteElementB(Element *elm);
};

class Element
{
public:
    virtual ~Element();
    virtual void Accept(Visitor *vis) = 0;

protected:
    Element();
};

class ConcreteElementA : public Element
{
public:
    ConcreteElementA();
    ~ConcreteElementA();
    void Accept(Visitor *vis);
};

class ConcreteElementB : public Element
{
public:
    ConcreteElementB();
    ~ConcreteElementB();
    void Accept(Visitor *vis);
};

class A
{
public:
    A();
    virtual ~A()
    {

    }
    int x;
private:
    virtual void move();
};

class AA : public A
{
public:
    AA();
    ~AA()
    {

    }
    virtual void move();
};

#endif // EPVISITOR_H
