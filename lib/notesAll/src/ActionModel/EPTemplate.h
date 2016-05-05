#ifndef EPTEMPLATE_H
#define EPTEMPLATE_H
#include <iostream>
using namespace std;

/**
 @brief The ActionModel enum
    TemplateMethod 的关键在于在基类中定义了一个算法的轮廓,但是算法每一
    步具体的实现留给了派生类.但是这样也会造成设计的灵活性不高的缺点,因为
    轮廓已经定下来了要想改变就比较难了,这也是为什么优先采用聚合而不是继承
    的原因.
 */
enum ActionModel {
    EPState,
    EPStrategy,
    EPTemplate,
    EPObserver,
    EPMediator,
    EPMemento,
    EPCommand,
    EPVisitor,
    EPChainOfResponsibility,
    EPIterator,
    EPInterpreter
};

class AbstractClass
{
public:
    virtual ~AbstractClass();
    void TemplateMethod();

protected:
    virtual void PrimitiveOperation1() = 0;
    virtual void PrimitiveOperation2() = 0;
    AbstractClass();
};

class ConcreteClass1 : public AbstractClass
{
public:
    ConcreteClass1();
    ~ConcreteClass1();

protected:
    void PrimitiveOperation1();
    void PrimitiveOperation2();

};

class ConcreteClass2 : public AbstractClass
{
public:
    ConcreteClass2();
    ~ConcreteClass2();

protected:
    void PrimitiveOperation1();
    void PrimitiveOperation2();

};

class base
{
public:
    base(int val) : _val(val){}

    int _val;
};

class base1 : virtual public base
{
public:
    base1(int val) : base(val){}

};

class base2 : virtual public base
{
public:
    base2(int val) : base(val){}

};

class Derived : public base1 ,public base2
{
public:
    Derived(int val,int val1,int val2)  : base(val),base1(val1), base2(val2) {}
    void show() { cout<< "val "<<_val<<endl;}
};

//AbstractClass* p1 = new ConcreteClass1();
//AbstractClass* p2 = new ConcreteClass2();
//p1->TemplateMethod();
//p2->TemplateMethod();
#endif // EPTEMPLATE_H
