#ifndef EPFACTORY_H
#define EPFACTORY_H

/**
  为了提高内聚和松耦合，经常抽象出一些类的公共接口以形成抽象基类或者借口。通过声明一个指向基类的指针来指向实际的子类实现
  ，达到多态的目的。
    **/
class Product
{
public:
    virtual ~Product() = 0;

protected:
    Product();

private:
};

class ConcreteProduct : public Product
{
public:
    ~ConcreteProduct();
    ConcreteProduct();

protected:
private:
};

/**
 @brief 简单工厂
    @def    用一个方法去代替构造器或者是 new 关键字，把创建的对象隐藏起来。
    优点 :
        1、 隐藏了new关键字和构造器
        2、 降低了这个对象与别的类之间的藕合度，提供了程序的可扩展性
            原因：当子类被别的类替换，或者构造器的参数发生改变的时候，只需改动工厂方法内的new即可，改动量降到了最低。
                 如果不用工厂模式，而是直接用new关键字的话，要改动的地方很多。
        3、 把对象的设计和实现分割开来，从而代码扩展性强，灵活性更高


 */
class Factory
{
public:
    virtual ~Factory() = 0;
    virtual Product * CreateProduct() = 0;

protected:
    Factory();
};

class ConcreteFactory : public Factory
{
public:
    ~ConcreteFactory();
    ConcreteFactory();

    Product * CreateProduct();

};

/**************************
  工厂模型是有一个抽象的工厂类，当要生产某一具体的产品时，就继承抽象工厂，获得具体的工厂类。
  缺点: 如果有很多产品，那么就有很多相应的工厂类。
  优点: 符合开闭原则，易于扩展
  ***************/
#endif // EPFACTORY_H
