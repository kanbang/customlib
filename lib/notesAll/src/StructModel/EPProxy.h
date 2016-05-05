#ifndef EPPROXY_H
#define EPPROXY_H

#include <iostream>
using namespace std;

/**
优点：
　　向客户端隐藏了访问某个对象的细节及复杂性；可以动态地调用一个对象中的方法，且无需实现固定的接口。

缺点：（
    个人见解切勿当真）总觉得代理者不够可靠，不能得到有效的保证，要是对象代理者在维护的时候，
    或者其他的做出了变动，对被代理的人来说可能带来损失。

使用场景：
    远程代理，可以隐藏一个对象存在于不同地址空间的事实
    虚拟代理，比如html页面刷新的图片，图片一张嘴下载后才能看就是通过虚拟代理来替代了真实的图片，此时代理存储了真实图片的路径和尺寸
    安全代理，用来控制真实对象的访问权限。一般用于对象应该有不同的访问权限的时候
    智能指引，当调用真实的对象时，代理处理另外一些事。

经典例子：
    我玩wow，但又没有时间精力投入到里面，于是我请了个人来代练，代练的人和我都继承于玩家类。
    而代练者是认识我的，当代练的人开始刷副本的时候，调用代练者.刷副本（）方法,此时他在这个方法中实际调用的是我.刷副本（）。
 */

class Subject
{
public:
    virtual ~Subject();
    virtual void Request() = 0;

protected:
    Subject();

};

class ConcreteSubject : public Subject
{
public:
    ConcreteSubject();
    ~ConcreteSubject();

    void Request();
};

class Proxy
{
public:
    Proxy();
    Proxy(Subject* sub);
    ~Proxy();

    void Request();

private:
    Subject *_sub;
};

#endif // EPPROXY_H
