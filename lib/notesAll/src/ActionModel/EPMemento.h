#ifndef EPMEMENTO_H
#define EPMEMENTO_H
#include <string>
#include <iostream>
using namespace std;

/**
 @brief The Memento class
    在不破坏封装性的前提下，捕获一个对象的内部状态，并在该对象之外保存这个状态，这样以后就可将该对象恢复到原先保存的状态。

 \brief
    Mementor模式中封装的是需要保存的状态，当需要恢复的时候才取出来进行恢复。
    原理很简单，实现的时候需要注意一个地方 ： 窄接口和宽接口。所谓的宽接口就
    是一般意义上的接口，把对外的接口作为public成员；而窄接口反之，把接口作为
    private成员，而把需要访问这些接口函数的类作为这个类的友元类，也就是说接口
    只暴露给了对这些接口感兴趣的类，而不暴露在外部。
*/
class Memento
{
private:
    friend class Originator;
    typedef string State;
    Memento();
    Memento(const State& sdt);
    ~Memento();

    void setState(const State& sdt);
    State getState();

private:
    State _sdt;
};

class Originator
{
public:
    typedef string State;
    Originator();
    Originator(const State& sdt);

    ~Originator();

    Memento* CreateMemento();
    void SetMemento(Memento* men);
    void RestoreToMemento(Memento* mt);
    State getState();
    void setState(const State& sdt);
    void PrintState();

private:
    State _sdt;
    Memento* _mt;
};


#endif // EPMEMENTO_H
