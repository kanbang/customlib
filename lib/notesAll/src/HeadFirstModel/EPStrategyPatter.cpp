#include "EPStrategyPatter.h"

Duck::Duck()
{
    _fly = 0;
    _quack = 0;
}

void Duck::quack()
{
    if(_quack){
        _quack->quack();
        qDebug()<<"quack ...";
    }
}

void Duck::fly()
{
    if(_fly){
        _fly->fly();
        qDebug()<<"fly ...";
    }
}

void Duck::setFly(FlyBehavior *fly)
{
    _fly = fly;
}

void Duck::setQuack(QuackBehavior *quack)
{
    _quack = quack;
}

void Duck::swim()
{
    qDebug()<<"Swim ...";
}

void Duck::display()
{
    qDebug()<<"No Color ...";
}

void FlyWithWings::fly()
{
    qDebug()<<__PRETTY_FUNCTION__<<"fly ...";
}

void MuteQuack::quack()
{
    qDebug()<<__PRETTY_FUNCTION__<<"quack ...";
}

MallardDuck::MallardDuck()
{

}

void MallardDuck::display()
{
    qDebug()<<"Green ...";
}

RedheadDuck::RedheadDuck()
{

}

void RedheadDuck::display()
{
    qDebug()<<"Red ...";
}
