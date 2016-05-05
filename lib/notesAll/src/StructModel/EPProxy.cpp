#include "EPProxy.h"

Subject::Subject()
{

}

Subject::~Subject()
{

}

ConcreteSubject::ConcreteSubject() {
}

ConcreteSubject::~ConcreteSubject() {
}

void ConcreteSubject::Request()
{
    cout<<"ConcreteSubject ... request ..."<<endl;
}

Proxy::Proxy()
{
}

Proxy::Proxy(Subject *sub)
{
    _sub = sub;
}

Proxy::~Proxy()
{
    delete _sub;
}

void Proxy::Request()
{
    cout<<"Proxy request ..."<<endl;
    _sub->Request();
}

//Subject* sub = new ConcreteSubject();
//Proxy* p = new Proxy(sub);
//p->Request();
