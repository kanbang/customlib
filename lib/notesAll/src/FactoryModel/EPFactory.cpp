#include "EPFactory.h"
#include <iostream>
using namespace std;

Product::Product()
{

}

Product::~Product()
{

}

ConcreteProduct::ConcreteProduct()
{
    cout<<"ConcreteProduct "<<endl;
}

ConcreteProduct::~ConcreteProduct()
{

}

Factory::Factory()
{
}

Factory::~Factory()
{

}

ConcreteFactory::ConcreteFactory()
{
    cout<<"ConcreteFactory ..."<<endl;
}

ConcreteFactory::~ConcreteFactory()
{

}

Product* ConcreteFactory::CreateProduct()
{
    return new ConcreteProduct();
}
