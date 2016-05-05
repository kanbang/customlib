#include "EPMemento.h"

typedef string State;

Memento::Memento()
{
}

Originator::Originator()
{
    _sdt = "";
    _mt = 0;
}

Originator::Originator(const State &sdt)
{
    _sdt = sdt;
    _mt = 0;
}

Originator::~Originator()
{

}

Memento* Originator::CreateMemento()
{
    return new Memento(_sdt);
}

State Originator::getState()
{
    return _sdt;
}

void Originator::setState(const State &sdt)
{
    _sdt = sdt;
}

void Originator::PrintState()
{
    cout<< this->_sdt << "..."<<endl;
}

void Originator::SetMemento(Memento *men)
{
}

void Originator::RestoreToMemento(Memento *mt)
{
    this->_sdt = mt->getState();
}

Memento::Memento(const State &sdt)
{
    _sdt = sdt;
}

State Memento::getState()
{
    return _sdt;
}

void Memento::setState(const State &sdt)
{
    _sdt = sdt;
}

//C++中,全局域只能声明,初始化变量,不能对变量进行赋值,运算,调用函数等操作,谨记
//Originator *o = new Originator();
//o->setState("old");
//o->PrintState();

//Memento* m = o->CreateMemento();
//o->setState("new");
//o->PrintState();
//o->RestoreToMemento(m);
//o->PrintState();
//}
