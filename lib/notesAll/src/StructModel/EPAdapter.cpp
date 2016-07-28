#include "EPAdapter.h"

Target::Target()
{

}

Target::~Target()
{

}

void Target::Request()
{
    cout<<"Target::Request"<<endl;
}

Adaptee::Adaptee()
{

}

Adaptee::~Adaptee()
{

}

void Adaptee::SpecificRequest()
{
    cout<<"Adaptee::SpecificRequest"<<endl;
}

AdapterOne::AdapterOne(Adaptee *ade)
{
    this->_ade = ade;
}

AdapterOne::~AdapterOne()
{

}

void AdapterOne::Request()
{
    _ade->SpecificRequest();
}

Adapter::Adapter()
{

}

Adapter::~Adapter()
{

}

void Adapter::Request()
{
    this->SpecificRequest();
}

//Target* adt = new Adapter();
//adt->Request();


//Adaptee* ade = new Adaptee;
//Target* adt = new AdapterOne(ade);
//adt->Request();
