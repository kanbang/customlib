  #include "EPBridge.h"

Abstraction::Abstraction() {
}

Abstraction::~Abstraction() {
}

RefinedAbstraction::RefinedAbstraction(AbstractionImp* imp)
{
    _imp = imp;
}

RefinedAbstraction::~RefinedAbstraction()
{
}

void RefinedAbstraction::Operation()
{
    _imp->Operation();
}

AbstractionImp::AbstractionImp() {
}

AbstractionImp::~AbstractionImp() {
}

void AbstractionImp::Operation()
{
    cout<<"AbstractionImp....imp..."<<endl;
}

ConcreteAbstractionImpA::ConcreteAbstractionImpA() {
}

ConcreteAbstractionImpA::~ConcreteAbstractionImpA() {
}

void ConcreteAbstractionImpA::Operation()
{
    cout<<"ConcreteAbstractionImpA...."<<endl;
}

ConcreteAbstractionImpB::ConcreteAbstractionImpB() {
}

ConcreteAbstractionImpB::~ConcreteAbstractionImpB() {
}

void ConcreteAbstractionImpB::Operation()
{
    cout<<"ConcreteAbstractionImpB...."<<endl;
}
//AbstractionImp* imp = new ConcreteAbstractionImpA();
//Abstraction* abs1 = new RefinedAbstraction(imp);
//abs1->Operation();

























