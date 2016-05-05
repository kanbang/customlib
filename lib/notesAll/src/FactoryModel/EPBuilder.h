#ifndef EPBUILDER_H
#define EPBUILDER_H
#include <iostream>
#include <string>
using namespace std;

class Product1
{
public:
    Product1();
    ~Product1();

    void ProducePart();
};

class ProductPart
{
public:
    ProductPart();
    ~ProductPart();

    ProductPart* BuildPart();
};

/***************

  **********/
class Builder
{
public:
    virtual ~Builder();

    virtual void BuildPartA(const string& buildPara)  = 0;
    virtual void BuildPartB(const string& buildPara)  = 0;
    virtual void BuildPartC(const string& buildPara)  = 0;
    virtual Product1* getProduct() = 0;

protected:
    Builder();
};

class ConcreteBuilder : public Builder
{
public:
    ConcreteBuilder();
    ~ConcreteBuilder();

    void BuildPartA(const string &buildPara);
    void BuildPartB(const string &buildPara);
    void BuildPartC(const string &buildPara);

    Product1* getProduct();
};

/****************
  Director类是一个指导类，指导复杂产品的合成步骤。
  ***********/
class Director
{
public:
    Director(Builder *bld);
    ~Director();

    void Construct();

private:
    Builder* _bld;
};

#endif // EPBUILDER_H
