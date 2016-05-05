#ifndef EPSINGLETON_H
#define EPSINGLETON_H

#include <iostream>
using namespace std;
/**
    1. 创建型模式
    (1) 工厂模型: 大概可以分为3种。
    a) 简单工厂模式
    优点: 只有一个工厂类，结构简单

     缺点: 不完全符合OCP开放封闭原则(扩展应开放，修改应封闭)，要增加一个新的产品类，必须相应修改工厂类的方法。
    b) 工厂方法模式
    优点: 可扩展性好，不用修改原始工厂类，增加一个工厂子类即可。
    缺点: 相比简单工厂模式，增加了多个工厂子类。
    c) 抽象工厂模式
    基于工厂方法模式，适合于解决了一系列相互依赖的对象或者有组合关系的对象的创建过程， 将一组对象的创建封装到一个工厂类，维护这个工厂类比维护多个对象的创建要简单。
 */
/**
    @def    确保一个类只有唯一的一个实例。
    @class  饿汉式和懒汉式
 */
class Singleton
{
public:
    static Singleton* Instance();

protected:
    Singleton();

private:
    static Singleton* _instance;
};

#endif // EPSINGLETON_H
