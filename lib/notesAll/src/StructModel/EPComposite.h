#ifndef EPCOMPOSITE_H
#define EPCOMPOSITE_H

#include <iostream>
#include <vector>
using namespace std;

class ComponentOne
{
public:
    ComponentOne();
    virtual ~ComponentOne();
public:
    virtual void Operation() = 0;
    virtual void Add(const ComponentOne &);
    virtual void Remove(const ComponentOne&);
    virtual ComponentOne* getChild(int);
};

class Composite : public ComponentOne
{
public:
    Composite();
    ~Composite();

public:
    void Operation();
    void Add(ComponentOne *com);
    void Remove(ComponentOne *com);
    ComponentOne* getChild(int);

private:
    vector<ComponentOne* > comVec;
};

class Leaf : public ComponentOne
{
public:
    Leaf();
    ~Leaf();

    void Operation();

};

#endif // EPCOMPOSITE_H
