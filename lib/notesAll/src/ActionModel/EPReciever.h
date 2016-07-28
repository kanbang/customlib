#ifndef EPRECIEVER_H
#define EPRECIEVER_H
#include <iostream>
using namespace std;

/**
 * @brief The Reciever class
 \brief  作用
    将一个请求封装为一个对象，从而使你可用不同的请求对客户进行参数化；对请求排队或记录请求日志，以及支持可撤销的操作

 \brief
    Command 模式的思想是把命令封装在一个类中，就是这里的Command基类，同时把接受对象也封装在一个类中就是这里的Receiver
    类中，由调用这个命令的类Invoker类来调用。其实，如果弄清楚了Command模式的原理，就会发现其实它和注册回调函数的原理是
    很相似的，而在面向过程的设计中的回调函数其实和这里的Command类的作用是一致的。
*/
class Reciever
{
public:
    Reciever();
    ~Reciever();
    void Action();
};

class Command
{
public:
    virtual ~Command();
    virtual void Excute() = 0;

protected:
    Command();
};

class ConcreteCommand : public Command
{
public:
    ConcreteCommand(Reciever *rev);
    ~ConcreteCommand();
    void Excute();

private:
    Reciever *_rev;
};

class Invoker
{
public:
    Invoker(Command *cmd);
    ~Invoker();
    void Invoke();

private:
    Command* _cmd;
};

#endif // EPRECIEVER_H
