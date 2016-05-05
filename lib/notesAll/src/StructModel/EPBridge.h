#ifndef EPBRIDGE_H
#define EPBRIDGE_H

#include <iostream>
using namespace std;

class AbstractionImp;
/**************************
  @ 抽象部分
  ***/
class Abstraction
{
public:
    virtual ~Abstraction();
    virtual void Operation() = 0;

protected:
    Abstraction();
};

class RefinedAbstraction : public Abstraction
{
public:
    RefinedAbstraction(AbstractionImp* imp);
    ~RefinedAbstraction();

    void Operation();

private:
    AbstractionImp* _imp;
};

/***************************
  @ 实现部分，当有新的功能要添加进来的时候，添加一个具体的类

  ****/
class AbstractionImp
{
public:
    virtual ~AbstractionImp();
    virtual void Operation() = 0;

protected:
    AbstractionImp();
};

class ConcreteAbstractionImpA : public AbstractionImp
{
public:
    ConcreteAbstractionImpA();
    ~ConcreteAbstractionImpA();

    virtual void Operation();
};

class ConcreteAbstractionImpB : public AbstractionImp
{
public:
    ConcreteAbstractionImpB();
    ~ConcreteAbstractionImpB();

    virtual void Operation();
};


#endif // EPBRIDGE_H
