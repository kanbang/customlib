#ifndef ABSTRACTFACTORY_H
#define ABSTRACTFACTORY_H

enum factoryModel {
    EPEffective,
    EPAbstractFactory,
    EPBuilder,
    EPFactory,
    EPPrototype,
    EPSingleton
};

/****************
  AbstractProductA  是一个产品结构等级的基类， 比如是一个电视机，那么
  A1 和 A2 分别是不同品牌的电视机
  AbstractProductB  是一个产品结构等级的基类， 比如是一个电视机，那么
  B1 和 B2 分别是不同品牌的电视机

  A1和B1 是一个产品族，意思是同一个品牌的不同类型的产品

  ************/
class AbstractProductA
{
public:
    virtual ~AbstractProductA();

protected:
    AbstractProductA();
};

class AbstractProductB {
public:
    virtual ~AbstractProductB();

protected:
    AbstractProductB();
};

class ProductA1 : public AbstractProductA
{
public:
    ProductA1();
    ~ProductA1();
};

class ProductA2 : public AbstractProductA
{
public:
    ProductA2();
    ~ProductA2();
};

class ProductB1 : public AbstractProductB
{
public:
    ProductB1();
    ~ProductB1();
};

class ProductB2 : public AbstractProductB
{
public:
    ProductB2();
    ~ProductB2();
};

class AbstractFactory
{
public:
    virtual ~AbstractFactory();
    virtual AbstractProductA* CreateProductA() = 0;
    virtual AbstractProductB* CreateProductB() = 0;
protected:
    AbstractFactory();
};

class ConcreteFactory1 : public AbstractFactory
{
public:
    ConcreteFactory1();
    ~ConcreteFactory1();
    AbstractProductA* CreateProductA();
    AbstractProductB* CreateProductB();
};

class ConcreteFactory2 : public AbstractFactory
{
public:
    ConcreteFactory2();
    ~ConcreteFactory2();
    AbstractProductA* CreateProductA();
    AbstractProductB* CreateProductB();

    void create(int *&x);

};
#endif // ABSTRACTFACTORY_H
