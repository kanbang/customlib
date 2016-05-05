#ifndef EPFACADE_H
#define EPFACADE_H
#include <iostream>
using namespace std;
/**
    2. 结构型模式
    (1). 桥接模式(Bridge)
    优点: 通过组合的方式将抽象与实现分离，降低了耦合性
    (2). 适配器模式(Adapter)
    用于以下情形：

    (i)提供的接口与使用环境要求不一致；

    (ii)客户端和接口双方都不容易修改；
    (3). 装饰模式(Decorator)
    给一类对象添加一些新的职责，优点：

    (i).避免修改父类(增加接口)，而且增加的接口其他子类也许并不需要。

    (II).不论增加多少个Component子类，只需要一个Decorator类，可以对其所有进行修饰.
 */
/**
 @brief  利用迪米特原则
 */
class Subsystem1
{
public:
    Subsystem1()
    {

    }

    ~Subsystem1()
    {

    }

    void Operation();
};

class Subsystem2
{
public:
    Subsystem2()
    {

    }
    ~Subsystem2()
    {

    }

    void Operation();
};

class Facade
{
public:
    Facade()
    {
        this->_subs1 = new Subsystem1();
        this->_subs2 = new Subsystem2();
    }
    ~Facade()
    {
        delete _subs1;
        delete _subs2;
    }
    void OperationWrapper();

private:
    Subsystem1* _subs1;
    Subsystem2* _subs2;
};

#endif // EPFACADE_H
