#ifndef EPADAPTER_H
#define EPADAPTER_H

#include <iostream>
using namespace std;
/**
 @brief
 将一个类的接口转换成客户希望的另外一个接口，解决两个已有接口之间不匹配的问题。

 */
enum StructModel {
    EPAdapter,
    EPBridge,
    EPComposite,
    EPDecorator,
    EPFacade,
    EPFlyWeight,
    EPProxy
};

class Target
{
public:
    Target();
    virtual ~Target();
    virtual void Request();
};

class Adaptee
{
public:
    Adaptee();
    ~Adaptee();

    void SpecificRequest();

};

class AdapterOne : public Target
{
public:
    AdapterOne(Adaptee *ade);
    ~AdapterOne();

    void Request();

private:
    Adaptee* _ade;
};

class Adapter : public Target, private Adaptee
{
public:
    Adapter();
    ~Adapter();
    void Request();
};

#endif // EPADAPTER_H
