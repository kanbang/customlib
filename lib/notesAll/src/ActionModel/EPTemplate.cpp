#include "EPTemplate.h"

AbstractClass::AbstractClass()
{
}

AbstractClass::~AbstractClass()
{
}

void AbstractClass::TemplateMethod()
{
this->PrimitiveOperation1();
this->PrimitiveOperation2();
}

ConcreteClass1::ConcreteClass1()
{
}

ConcreteClass1::~ConcreteClass1()
{
}

void ConcreteClass1::PrimitiveOperation1()
{
    cout<<"ConcreteClass1...PrimitiveOperation1 "<<endl;
}

void ConcreteClass1::PrimitiveOperation2()
{
    cout<<"ConcreteClass1...PrimitiveOperation2"<<endl;
}

ConcreteClass2::ConcreteClass2()
{
}

ConcreteClass2::~ConcreteClass2()
{
}

void ConcreteClass2::PrimitiveOperation1()
{
    cout<<"ConcreteClass2...PrimitiveOperation1"<<endl;
}
void ConcreteClass2::PrimitiveOperation2()
{
    cout<<"ConcreteClass2...PrimitiveOperation2"<<endl;
}

/********************
  将算法的实现放在具体的类中，同时，在抽象类定义一个调用这些算法的借口

  **********/
//AbstractClass* p1 = new ConcreteClass1();
//AbstractClass* p2 = new ConcreteClass2();
//p1->TemplateMethod();
//p2->TemplateMethod();
