#include "EPBuilder.h"

/**************
  将一个复杂对象的构建与它的表示分离， 使得同样的构建过程可以创建不同的表示

  对象的构建在 ConcreteBuilder::getProduct()这个类里。
  对象的表示在 ConcreteBuilder::buildPartA() 、buildPartB()、 buildPartC()之中。

  适用条件：
  1、 当创建复杂对象的算法应该独立于该对象的组成部分以及他们的装配方式
      理解： 复杂的算法应该在Builder这个类中实现，当需要不同的算法的时候，重新实现一个Builder。

  2、 当构造过程必须允许构造的对象有不同的表示
      理解： 不同的Builder算法，最终得到的结果就会不同。

      导向器(Director)是调用BuildPart()方法，来将部件(part)组合到目标Product中的，如果只是组合不同数量的现有部件，
      则不用定义新的ConcreteBuilder.

  *************/
Product1::Product1()
{
    ProducePart();
    cout<<"return a product "<<endl;
}

Product1::~Product1()
{

}

void Product1::ProducePart()
{
    cout<<"build part of product .."<<endl;
}

ProductPart::ProductPart()
{

}

ProductPart::~ProductPart()
{

}

ProductPart* ProductPart::BuildPart()
{
    return new ProductPart;
}

Builder::Builder()
{
}

Builder::~Builder()
{

}

ConcreteBuilder::ConcreteBuilder()
{

}

ConcreteBuilder::~ConcreteBuilder()
{

}

void ConcreteBuilder::BuildPartA(const string &buildPara)
{
    cout<<"Step1 : Build PartA .."<<buildPara<<endl;
}

void ConcreteBuilder::BuildPartB(const string& buildPara)
{
    cout<<"Step1:Build PartB..."<<buildPara<<endl;
}

void ConcreteBuilder::BuildPartC(const string& buildPara)
{
    cout<<"Step1:Build PartC..."<<buildPara<<endl;
}

Product1* ConcreteBuilder::getProduct()
{
    BuildPartA("pre-defined");
    BuildPartB("pre-defined");
    BuildPartC("pre-defined");
    return new Product1();
}

Director::Director(Builder *bld)
{
    _bld = bld;
}

Director::~Director()
{

}

void Director::Construct()
{
    _bld->BuildPartA("user-defined");
    _bld->BuildPartB("user-defined");
    _bld->BuildPartC("user-defined");
}


































