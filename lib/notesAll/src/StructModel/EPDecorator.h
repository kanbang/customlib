#ifndef EPDECORATOR_H
#define EPDECORATOR_H

#include <iostream>
using namespace std;
 /**************************
   @ 动态地给一个对象添加一些额外的职责，就添加功能来说，Decorator模式比生成子类更加灵活。
     有时候希望给某个对象而不是整个类添加一些功能。 使用继承机制是添加功能的一种有效途径，从其他类继承过来的特性可以被
     多个子类的实例使用，但是这种方法不灵活。
     另一种方法是将组件嵌入另一对象中，由于这个对象添加了特性，所以称这个嵌入的对象为装饰。

优点：
装饰模式与继承关系的目的都是要扩展对象的功能，但是装饰模式可以提供比继承更多的灵活性。
通过使用不同的具体装饰类以及这些装饰类的排列组合，设计师可以创造出很多不同行为的组合。
有着比继承更加灵活的特性
缺点：
    由于使用装饰模式，可以比使用继承关系需要较少数目的类。使用较少的类，当然使设计比较易于进行。
    但是，在另一方面，使用装饰模式会产生比使用继承关系更多的对象。更多的对象会使得查错变得困难，特别是这些对象看上去都很相像。
用途：
    当需要给一个类添加新的行为的时候，但基于开闭原则，就使用装饰模式。
经典例子：
    我穿衣服使用draw（）方法，在我穿好衣服后，我还打算再寄领带，而寄领带就是装饰类，
    我们可以把装饰类和对象（穿衣服类）继承于同一个接口，在装饰类的draw（）方法中调用super.draw（），
    然后再在这个方法里加上自己的特征。
   ***************/
class Component
{
public:
    virtual ~Component();

    virtual void Operation();

protected:
    Component();
};

class ConcreteComponent : public Component
{
public:
    ConcreteComponent();
    ~ConcreteComponent();

    void Operation();
};

class Decorator : public Component
{
public:
    Decorator(Component* com);
    virtual ~Decorator();
    void Operation();

protected:
    Component* _com;
};

class ConcreteDecorator : public Decorator
{
public:
    ConcreteDecorator(Component *com);
    ~ConcreteDecorator();

    void Operation();
    void AddedBehavior();
};

#endif // EPDECORATOR_H
