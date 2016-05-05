#include "EPInterpreter.h"

Context1::Context1()
{

}

Context1::~Context1()
{

}

AbstractExpression::AbstractExpression() {
}

AbstractExpression::~AbstractExpression() {
}

void AbstractExpression::interpret(const Context1& /*c*/) {
}

TerminalExpression::TerminalExpression(const string &statement)
{
    this->_statement = statement;
}

TerminalExpression::~TerminalExpression()
{

}

void TerminalExpression::interpret(const Context1 &/*c*/)
{
    cout<<this->_statement <<"  TerminalExpression "<<endl;
}

NonterminalExpression::NonterminalExpression(AbstractExpression *expression, int times)
{
    this->_expression = expression;
    this->_times = times;
}

NonterminalExpression::~NonterminalExpression()
{
}

void NonterminalExpression::interpret(const Context1 &c)
{
    for (int i = 0; i< _times; i++)
    {
        this->_expression->interpret(c);
    }
}

//Context1 *c = new Context1();
//AbstractExpression* te = new TerminaExpression("hello");
//AbstractExpression* nte = new NoterminalExpression(te,2);
//nte->interpret(*c);
