#include "EPDecorator.h"

Component::Component()
{

}

Component::~Component() {
}

void Component::Operation() {
}

ConcreteComponent::ConcreteComponent() {
}

ConcreteComponent::~ConcreteComponent() {
}

void ConcreteComponent::Operation()
{
    cout<<"ConcreteComponent operation..."<<endl;
}

Decorator::Decorator(Component *com)
{
    this->_com = com;
}

Decorator::~Decorator()
{
    delete _com;
}

void Decorator::Operation()
{

}

ConcreteDecorator::ConcreteDecorator(Component *com) : Decorator(com)
{

}

ConcreteDecorator::~ConcreteDecorator() {
}

void ConcreteDecorator::AddedBehavior()
{
    cout<<"ConcreteDecorator::AddedBehavior ..."<<endl;
}

void ConcreteDecorator::Operation()
{
    _com->Operation();
    this->AddedBehavior();
}

//Component* com = new ConcreteComponent();
//Decorator* dec = new ConcreteDecorator(com);
//dec->Operation();
//delete dec;
