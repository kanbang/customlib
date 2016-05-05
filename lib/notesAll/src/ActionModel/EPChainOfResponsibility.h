#ifndef EPCHAINOFRESPONSIBILITY_H
#define EPCHAINOFRESPONSIBILITY_H
#include <iostream>
using namespace std;

/**
 @brief The Handle class
    使多个对象都有机会处理请求，从而避免请求的发送者和接受者之间的解耦关系。
    将这些对象连成一条链，并沿着这条链传递该请求，直到有一个对象处理它为止。

 \brief
    就好比Qt中，事件的传递一样，当前子窗口发生一个鼠标按下事件，如果当前子窗口
    不想处理该事件，那么就会传递给父窗口，一直到有人接受处理。

    事情如果能在我这里处理，我就处理，否则我就丢出去，让别人处理。
*/
class Handle
{
public:
    virtual ~Handle();
    virtual void HandleRequest() = 0;
    void setSuccessor(Handle* succ);
    Handle* getSuccessor();

protected:
    Handle();
    Handle(Handle* succ);

private:
    Handle* _succ;
};

class ConcreteHandleA : public Handle
{
public:
    ConcreteHandleA();
    ~ConcreteHandleA();
    ConcreteHandleA(Handle* succ);
    void HandleRequest();
};

class ConcreteHandleB : public Handle
{
public:
    ConcreteHandleB();
    ~ConcreteHandleB();
    ConcreteHandleB(Handle* succ);
    void HandleRequest();
};

#endif // EPCHAINOFRESPONSIBILITY_H
