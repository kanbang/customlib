#ifndef EPFLYWEIGHT_H
#define EPFLYWEIGHT_H
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class FlyWeight
{
public:
    virtual ~FlyWeight();
    virtual void Operation(const string& extrinsicSate);
    string getIntrinsicState();

protected:
    FlyWeight(string instrinsicState);

private:
    string _intrinsicState;
};

class ConcreteFlyWeight : public FlyWeight
{
public:
    ConcreteFlyWeight(string intrinsicState);
    ~ConcreteFlyWeight();

    void Operation(const string &extrinsicSate);

};

class FlyWeightFactory
{
public:
    FlyWeightFactory();
    ~FlyWeightFactory();

    FlyWeight* getFlyWeight(const string& key);

private:
    vector<FlyWeight*> _fly;
};

#endif // EPFLYWEIGHT_H
