#include "EPFacade.h"

void Subsystem1::Operation()
{
    cout<< "Subsystem2 operation .."<<endl;
}

void Subsystem2::Operation()
{
    cout<<"Subsystem2 operation .."<<endl;
}

void Facade::OperationWrapper()
{
    this->_subs1->Operation();
    this->_subs2->Operation();
}

//Facade* f = new Facade();
//f->OperationWrapper();
