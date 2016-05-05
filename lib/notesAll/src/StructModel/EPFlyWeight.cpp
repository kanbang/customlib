#include "EPFlyWeight.h"

FlyWeight::FlyWeight(string intrinsicState)
{
    this->_intrinsicState = intrinsicState;
}

FlyWeight::~FlyWeight()
{

}

void FlyWeight::Operation(const string &/*extrinsicSate*/)
{

}

string FlyWeight::getIntrinsicState()
{
    return this->_intrinsicState;
}

ConcreteFlyWeight::ConcreteFlyWeight(string intrinsicState) : FlyWeight(intrinsicState)
{
    cout<<"ConcreteFlyWeight Build ..."<<intrinsicState<<endl;
}

ConcreteFlyWeight::~ConcreteFlyWeight()
{

}

void ConcreteFlyWeight::Operation(const string &extrinsicState)
{
    cout<<"ConcreteFlyWeight : ["<<this->getIntrinsicState() <<"]  ["<<extrinsicState <<" ]"<<endl;
}

FlyWeightFactory::FlyWeightFactory() {
}

FlyWeightFactory::~FlyWeightFactory() {
}

FlyWeight* FlyWeightFactory::getFlyWeight(const string &key)
{
    vector<FlyWeight*>::iterator it = _fly.begin();

    for(; it != _fly.end(); it++)
    {
        if((*it)->getIntrinsicState() == key )
        {
            cout<<"already created by users..."<<endl;
            return *it;
        }
    }
    FlyWeight *fn = new ConcreteFlyWeight(key);
    _fly.push_back(fn);
    return fn;
}

//FlyweightFactory* fc = new FlyweightFactory();
//Flyweight* fw1 = fc->GetFlyweight("hello");
//Flyweight* fw2 = fc->GetFlyweight("world!");
//Flyweight* fw3 = fc->GetFlyweight("hello");
