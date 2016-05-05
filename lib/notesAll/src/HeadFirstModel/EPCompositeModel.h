#ifndef EPCOMPOSITEMODEL_H
#define EPCOMPOSITEMODEL_H

#include <QDebug>
#include <QDebug>

/**
 @note  复合模式中所使用的模式
    @a  工厂类
    @b  策略模式
    @c  装饰模式
    @d  观察者模式
    @e  组合模式
    @fn 适配器模式
 */

class QuackObservable;
class Observer;

class AbstractQuackable //: public QuackObservable
{
public:
    AbstractQuackable();
    ~AbstractQuackable(){}
    virtual void quack() = 0;
    void registerObserver(Observer* obv);
    void notifyObservers();

private:
    QuackObservable* m_oed;
};

class NewMallardDuck : public AbstractQuackable
{
public:
    void quack();
};

class NewRedheadDuck : public AbstractQuackable
{
public:
    void quack();
};

class NewDuckCall : public AbstractQuackable
{
public:
    void quack();
};

class NewRubberDuck : public AbstractQuackable
{
public:
    void quack();
};

class Goose
{
public:
    void honk();
};

class GooseAdapter : public AbstractQuackable
{
public:
    GooseAdapter(Goose* goose);
    void quack();

private:
    Goose *m_goose;
};

class AbstractDuckFactory;
class DuckSimulator
{
public:
    void simulate(AbstractDuckFactory *duckFactory);
    void simulate(AbstractQuackable* duck);
};

class Flock : public AbstractQuackable
{
public:
    void quack();
    void add(AbstractQuackable *quacker);

private:
    QList<AbstractQuackable*> lists;
};

class Observer
{
public:
    virtual void  update(AbstractQuackable* duck) = 0;
};

class Quackologist : public Observer
{
public:
    void update(AbstractQuackable *duck);
};

class QuackObservable
{
public:
    QuackObservable(AbstractQuackable* duck);
    void registerObserver(Observer *obv) ;
    void notifyObservers() ;
    void setQuackable(AbstractQuackable* duck);

private:
    QList<Observer*> _obvs;
    AbstractQuackable* m_duck;
};

class QuackCounter : public AbstractQuackable
{
public:
    QuackCounter(AbstractQuackable* duck);
    void quack();
    static int getQuacks();

private:
    static int numberOfQuacks;
    AbstractQuackable* m_duck;
};

class AbstractDuckFactory
{
public:
    ~AbstractDuckFactory(){}
    virtual AbstractQuackable* createMallardDuck() = 0;
    virtual AbstractQuackable* createRedheadDuck() = 0;
    virtual AbstractQuackable* createDuckCall() = 0;
    virtual AbstractQuackable* createRubberDuck() = 0;
};

class DuckFactory : public AbstractDuckFactory
{
public:
    AbstractQuackable* createMallardDuck();
    AbstractQuackable* createRedheadDuck();
    AbstractQuackable* createDuckCall();
    AbstractQuackable* createRubberDuck();
};

class CountingDuckFactory : public AbstractDuckFactory
{
public:
    AbstractQuackable* createMallardDuck();
    AbstractQuackable* createRedheadDuck();
    AbstractQuackable* createDuckCall();
    AbstractQuackable* createRubberDuck();
};

#endif // EPCOMPOSITEMODEL_H
