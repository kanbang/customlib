#ifndef EPMEDIATOR_H
#define EPMEDIATOR_H

#include <string>
#include <iostream>
using namespace std;

class Mediator
{
public:
    virtual ~Mediator();
    virtual void DoActionFromAtoB() = 0;
    virtual void DoActionFromBtoA() = 0;

protected:
    Mediator();
};

class Colleage
{
public:
    virtual ~Colleage();
    virtual void Action() = 0;
    virtual void setState(const string &sdt) = 0;
    virtual string getState() = 0;

protected:
    Colleage();
    Colleage(Mediator *mdt);
    Mediator* _mdt;
};

class ConcreteColleageA : public Colleage
{
public:
    ConcreteColleageA();
    ConcreteColleageA(Mediator *mdt);
    ~ConcreteColleageA();

    void Action();
    void setState(const string &sdt);
    string getState();

private:
    string _sdt;
};

class ConcreteColleageB : public Colleage
{
public:
    ConcreteColleageB();
    ConcreteColleageB(Mediator *mdt);
    ~ConcreteColleageB();
    void Action();
    void setState(const string &sdt);
    string getState();

private:
    string _sdt;
};


class ConcreteMediator : public Mediator
{
public:
    ConcreteMediator();
    ConcreteMediator(Colleage *clgA,Colleage *clgB);
    ~ConcreteMediator();
    void setConcreteColleageA(Colleage* clgA);
    void setConcreteColleageB(Colleage* clgB);
    Colleage* getConcreteColleageA();
    Colleage* getConcreteColleageB();

    void IntroColleage(Colleage* clgA, Colleage* clgB);
    void DoActionFromAtoB();
    void DoActionFromBtoA();

private:
    Colleage* _clgA;
    Colleage* _clgB;
};


#endif // EPMEDIATOR_H
