#include "EPObserver.h"
#include <iostream>
using namespace std;

Subject::Subject()
{
    //****在模板的使用之前一定要new，创建
    _obvs = new list<Observer*>;
}

Subject::~Subject()
{

}

void Subject::Attach(Observer* obv)
{
    _obvs->push_front(obv);
}

void Subject::Detach(Observer* obv)
{
    if (obv != NULL) _obvs->remove(obv);
}

void Subject::Notify()
{
    list<Observer* >::iterator it;
    it = _obvs->begin();
    for ( ; it != _obvs->end(); it++)
    {
        (*it)->Update(this);
    }
}

ConcreteSubject::ConcreteSubject()
{
    _st = '\0';
}

ConcreteSubject::~ConcreteSubject()
{

}

StateOne ConcreteSubject::getStateOne()
{
    return _st;
}

void ConcreteSubject::setStateOne(const StateOne &st)
{
    _st = st;
}


Observer::Observer()
{
    _st = '\0';
}

Observer::~Observer()
{

}

ConcreteObserverA::ConcreteObserverA(Subject *sub)
{
    _sub = sub;
    _sub->Attach(this);
}

ConcreteObserverA::~ConcreteObserverA()
{
    _sub->Detach(this);
    if(_sub!= 0)
        delete _sub;
}

Subject* ConcreteObserverA::getSubject()
{
    return _sub;
}

void ConcreteObserverA::PrintInfo()
{
    cout<<"ConcreteObserverA observer.... "<<_sub->getStateOne()<<"..."<<_st<<endl;
}

void ConcreteObserverA::Update(Subject* sub)
{
    _st = sub->getStateOne();
    PrintInfo();
}

ConcreteObserverB::ConcreteObserverB(Subject* sub)
{
    _sub = sub;
    _sub->Attach(this);
}

ConcreteObserverB::~ConcreteObserverB()
{
    _sub->Detach(this);
    if (_sub != 0)
    {
        delete _sub;
    }
}

Subject* ConcreteObserverB::getSubject()
{
    return _sub;
}

void ConcreteObserverB::PrintInfo()
{
    cout<<"ConcreteObserverB observer...."<<_sub->getStateOne()<<"..."<<_st<<endl;
}

void ConcreteObserverB::Update(Subject *sub)
{
    _st = sub->getStateOne();
    PrintInfo();
}

//ConcreteSubject* sub = new ConcreteSubject();
//Observer* o1 = new ConcreteObserverA(sub);
//Observer* o2 = new ConcreteObserverB(sub);
//sub->SetState("old");
//sub->Notify();
//sub->SetState("new"); //也可以由Observer调用
//sub->Notify();
