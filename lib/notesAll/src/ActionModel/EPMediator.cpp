#include "EPMediator.h"

Colleage::Colleage()
{

}

Colleage::Colleage(Mediator *mdt)
{
    this->_mdt = mdt;
}

Colleage::~Colleage()
{ }

ConcreteColleageA::ConcreteColleageA()
{ }

ConcreteColleageA::~ConcreteColleageA()
{ }

ConcreteColleageA::ConcreteColleageA(Mediator *mdt) : Colleage(mdt)
{

}

void ConcreteColleageA::setState(const string &sdt)
{
    _sdt = sdt;
}

string ConcreteColleageA::getState()
{
    return _sdt;
}

void ConcreteColleageA::Action()
{
    _mdt->DoActionFromAtoB();
    cout<<" State of ConcreteColleageA : "<< " "<< this->getState() <<endl;
}

ConcreteColleageB::ConcreteColleageB()
{

}

ConcreteColleageB::~ConcreteColleageB()
{

}

ConcreteColleageB::ConcreteColleageB(Mediator *mdt) : Colleage(mdt)
{

}

void ConcreteColleageB::Action()
{
    _mdt->DoActionFromBtoA();
    cout<< "State of ConcreteColleageB "<< " " <<this->getState() <<endl;
}

string ConcreteColleageB::getState()
{
    return _sdt;
}

void ConcreteColleageB::setState(const string &sdt)
{
    _sdt = sdt;
}



Mediator::Mediator()
{
}

Mediator::~Mediator()
{

}

ConcreteMediator::ConcreteMediator()
{

}

ConcreteMediator::~ConcreteMediator()
{

}

ConcreteMediator::ConcreteMediator(Colleage *clgA, Colleage *clgB)
{
    this->_clgA = clgA;
    this->_clgB = clgB;
}

void ConcreteMediator::DoActionFromAtoB()
{
    _clgB->setState(_clgA->getState());
}

void ConcreteMediator::DoActionFromBtoA()
{
    _clgA->setState(_clgB->getState());
}

void ConcreteMediator::setConcreteColleageA(Colleage *clgA)
{
    this->_clgA = clgA;
}

void ConcreteMediator::setConcreteColleageB(Colleage *clgB)
{
    this->_clgB = clgB;
}

Colleage* ConcreteMediator::getConcreteColleageA()
{
    return _clgA;
}

Colleage* ConcreteMediator::getConcreteColleageB()
{
    return _clgB;
}

void ConcreteMediator::IntroColleage(Colleage *clgA, Colleage *clgB)
{
    this->_clgA = clgA;
    this->_clgB = clgB;
}

//ConcreteMediator* m = new ConcreteMediator();
//ConcreteColleageA* c1 = new ConcreteColleageA(m);
//ConcreteColleageB* c2 = new ConcreteColleageB(m);

//这里的信息交互是通过每个具体的Colleage类中的Mediator对象来交互的，当然，前提条件是要让Mediator知道要和哪两个
//Colleage信息交互

/* m->IntroColleage(c1,c2); 指定c1，c2这两个Colleage交换信息。
   这样的好处是，当c1，c2之间的信息交换方式发生改变的时候，可以通过继承Mediator，得到另一个中交换方式。这样又不用修改
   原来的代码。
*/
//c1->setState("old"); c2->SetState("old"); c1->Action(); c2->Action(); cout<<endl;
//c1->setState("new"); c1->Action(); c2->Action(); cout<<endl;
//c2->setState("old"); c2->Action(); c1->Action();













