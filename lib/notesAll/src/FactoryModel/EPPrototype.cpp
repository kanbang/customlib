#include "EPPrototype.h"
#include <iostream>
using namespace std;

Prototype::Prototype()
{
}

Prototype::~Prototype()
{

}

Prototype::Prototype(const Prototype &)
{

}

Prototype* Prototype::Clone() const
{
    return 0;
}

ConcretePrototype::ConcretePrototype()
{
}

ConcretePrototype::~ConcretePrototype()
{
}

ConcretePrototype::ConcretePrototype(const ConcretePrototype &/*cp*/) : Prototype()
{
    cout<<"ConcretePrototype copy ..."<<endl;
}

Prototype* ConcretePrototype::Clone() const
{
    return new ConcretePrototype(*this);
}

//Prototype* p = new ConcretePrototype();
//Prototype* p1 = p->Clone();
