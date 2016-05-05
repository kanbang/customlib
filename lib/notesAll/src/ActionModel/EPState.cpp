#include "EPState.h"
#include <iostream>
using namespace std;

State::State()
{
}

State::~State()
{

}

void State::OperationInterface(ContextOne */*con*/)
{
    cout<<"State..."<<endl;
}

bool State::ChangeState(ContextOne *con, State *st)
{
    con->ChangeState(st);
    return true;
}

void State::OperationChangeState(ContextOne *)
{

}

ConcreteStateA::ConcreteStateA()
{

}

ConcreteStateA::~ConcreteStateA()
{

}

void ConcreteStateA::OperationInterface(ContextOne */*con*/)
{
    cout<< "  ConcreteStateA::OperationInterface ..."<<endl;
}

void ConcreteStateA::OperationChangeState(ContextOne *con)
{
    OperationInterface(con);
    this->ChangeState(con,new ConcreteStateB());
}

ConcreteStateB::ConcreteStateB() {
}

ConcreteStateB::~ConcreteStateB()
{

}

void ConcreteStateB::OperationInterface (ContextOne* /*con*/)
{
    cout<<"  ConcreteStateB::OperationInterface......"<<endl;
}
void ConcreteStateB::OperationChangeState (ContextOne* con)
{
    OperationInterface(con);
    this->ChangeState(con,new ConcreteStateA());
}

ContextOne::ContextOne() {
}

ContextOne::ContextOne(State* state)
{
    this->_state = state;
}

ContextOne::~ContextOne()
{
    delete _state;
}

void ContextOne::OperationInterface()
{
    _state->OperationInterface(this);
}

bool ContextOne::ChangeState(State* state)
{
    //_state->ChangeState(this,state);
    this->_state = state;
    return true;
}

void ContextOne::OperationChangeState()
{
    _state->OperationChangeState(this);
}
//AbstractState::AbstractState(GumballMachine *gm)
//{
//    m_gm = gm;
//}

//NoQuarterState::NoQuarterState(GumballMachine *gm) :AbstractState(gm)
//{
//}

//GumballMachine::GumballMachine(AbstractState *state)
//{
//    m_state = state;
//}

//State* st = new ConcreteStateA();
//ContextOne* con = new ContextOne(st);
//con->OperationChangState();
//con->OperationChangState();
//con->OperationChangState();
//if (con != NULL) delete con;
//if (st != NULL) st = NULL;

