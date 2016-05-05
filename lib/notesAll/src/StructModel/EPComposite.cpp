#include "EPComposite.h"

ComponentOne::ComponentOne() {
}

ComponentOne::~ComponentOne() {
}

void ComponentOne::Add(const ComponentOne& com) {
}

ComponentOne* ComponentOne::getChild(int index)
{
    return 0;
}

void ComponentOne::Remove(const ComponentOne& com) {
}

Composite::Composite()
{
}

Composite::~Composite()
{

}

void Composite::Operation()
{
    vector<ComponentOne*>::iterator comIter = comVec.begin();
    for (;comIter != comVec.end();comIter++)
    {
        (*comIter)->Operation();
    }
}

void Composite::Add(ComponentOne *com)
{
    comVec.push_back(com);
}

void Composite::Remove(ComponentOne *com)
{
    vector<ComponentOne*>::iterator comIter = comVec.begin();
    for (;comIter != comVec.end();comIter++)
    {
        if((*comIter)==com)
            comVec.erase(comIter);
    }
}

ComponentOne* Composite::getChild(int index)
{
    return comVec[index];
}

Leaf::Leaf()
{

}

Leaf::~Leaf()
{

}

void Leaf::Operation()
{
    cout<<"Leaf Operation ..."<<endl;
}

//Leaf* l = new Leaf(); l->Operation();
//Composite* com = new Composite();
//com->Add(l);
//com->Operation();
//Component* ll = com->GetChild(0);
//ll->Operation();
