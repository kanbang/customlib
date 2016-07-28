#ifndef EPINTERPRETER_H
#define EPINTERPRETER_H
#include <iostream>
#include <string>
using namespace std;

class Context1
{
public:
    Context1();
    ~Context1();
};

class AbstractExpression
{
public:
    virtual ~AbstractExpression();
    virtual void interpret(const Context1& c);

protected:
    AbstractExpression();
};

class TerminalExpression : public AbstractExpression
{
public:
    TerminalExpression(const string& statement);
    ~TerminalExpression();
    void interpret(const Context1 &c);

private:
    string _statement;
};

class NonterminalExpression : public AbstractExpression
{
public:
    NonterminalExpression(AbstractExpression* expression, int times);
    ~NonterminalExpression();
    void interpret(const Context1 &c);

private:
    AbstractExpression* _expression;
    int _times;
};


#endif // EPINTERPRETER_H
