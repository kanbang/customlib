#ifndef GLODONCOMMAND_H
#define GLODONCOMMAND_H

#include "glodonpattern_global.h"

class GLODONPATTERNSHARED_EXPORT Command
{
public:
    virtual ~Command();
    virtual void execute() = 0;

protected:
    Command();
};

class Receivce;

class ConcreteCommand : public Command
{
public:
    ConcreteCommand(Receivce* rec);
    ~ConcreteCommand();

    void execute();

private:
    Receivce* m_pRec;
};

class Invoker
{
public:
    Invoker(Command* com);
    ~Invoker();

    void invoke();

private:
    Command* m_pCom;
};

class Receivce
{
public:
    Receivce();
    ~Receivce();

    void action();

};

#endif // GLODONCOMMAND_H
