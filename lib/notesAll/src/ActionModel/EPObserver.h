#ifndef EPOBSERVER_H
#define EPOBSERVER_H

#include <string>
#include <list>
using namespace std;
/**
 @brief 作用
    定义对象间的一种一对多的依赖关系，当一个对象的状态发生发改变时，所有依赖于它的对象都得到通知并被自动更新

 \brief
    Observer模式定义的是一种一对多的关系，这里的一就是图中的Subject类，而多则是Observer类，当Subject类的
    状态发生改变的时候通知与之对应的Observer类们也去相应的更新状态，同时，支持动态的添加和删除Observer对象
    的功能。Observer模式的实现要点是，第一一般Subject类都是采用链表等容器来存放Observer对象，第二抽取出
    Observer对象的一些公共的属性形成Observer基类，而Subject中保存的则是Observer类对象的指针，这样就使
    Subject和具体的Observer实现解耦，也就是Subject不需要去关心到底是哪个Observer放进了自己的容器中。

 \brief
    一个班有一个班主任（Subject），他管理手下的一帮学生（Observer），当班里有一些事情发生需要通知学生的时候，
    班主任要做的不是逐个学生通知，而是把学生召集起来通知。

    @def    定义对象间的一种一对多的依赖关系，当一个对象的状态发生改变了，所以依赖于它的对象都得到通知并被自动更新。
    解决问题:   解决多个对象间相互依赖关系的相互通知
    常用地方:   一些数据有多个视图的表示。
        当一个抽象模型有两个方面，其中一个方面依赖另一个方面，将这两个封装在独立的对象中以使他们可以各自独立地改变和复用。
        当对一个对象的改变需要同时改变其他对象，而不知道具体有多少个对象有待改变。
        当一个对象必须通知其他对象，而它又不能假定其它对象是谁，换言之，你不希望这些对象是紧密耦合的。

*/
typedef string StateOne;
class Observer;

class Subject
{
public:
    virtual ~Subject();
    virtual void Attach(Observer *obv);
    virtual void Detach(Observer *obv);
    virtual void Notify();
    virtual void setStateOne(const StateOne& st) = 0;
    virtual StateOne getStateOne() = 0;

protected:
    Subject();

private:
    list<Observer *> * _obvs;
};

class ConcreteSubject : public Subject
{
public:
    ConcreteSubject();
    ~ConcreteSubject();

    StateOne getStateOne();
    void setStateOne(const StateOne& st);

private:
    StateOne _st;
};


class Observer
{
public:
    virtual ~Observer();
    virtual void Update(Subject * sub) = 0;
    virtual void PrintInfo() = 0;

protected:
    Observer();
    StateOne _st;
};

class ConcreteObserverA : public Observer
{
public:
    ConcreteObserverA (Subject * sub);
    virtual Subject* getSubject();
    virtual ~ConcreteObserverA();
    void Update(Subject *sub);
    void PrintInfo();

private:
    Subject* _sub;
};

class ConcreteObserverB : public Observer
{
public:
    ConcreteObserverB(Subject* sub);
    virtual Subject* getSubject();
    virtual ~ConcreteObserverB();
    void Update(Subject *sub);
    void PrintInfo();

private:
    Subject* _sub;
};

#endif // EPOBSERVER_H
