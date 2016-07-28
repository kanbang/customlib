#ifndef EPPROTOTYPE_H
#define EPPROTOTYPE_H

class Prototype
{
public:
    virtual ~Prototype();
    Prototype(const Prototype& cp);
    virtual Prototype *Clone() const = 0;

protected:
    Prototype();
};

class ConcretePrototype:public Prototype
{
public:
    ConcretePrototype();
    ConcretePrototype(const ConcretePrototype& /*cp*/);

    ~ConcretePrototype();
    Prototype * Clone() const;
};

#endif // EPPROTOTYPE_H
