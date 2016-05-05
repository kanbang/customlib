#ifndef EPSTATE_H
#define EPSTATE_H

/**
 \brief
    允许一个对象在其内部状态改变时改变它的行为。

 \brief
    State模式主要解决的是在开发中时常遇到的根据不同的状态需要不同的处理操作的问题，而这样的问题，大部分人是采用switch-case语句进行处理的，
    这样会造成一个问题： 分支过多，而且如果加入一个新的状态就需要对原来的代码进行编译。

 \brief
    State模式采用了对这些不同的状态进行封装的方式处理这类问题，当状态改变的时候进行处理然后再切换到另一种状态，也就是说把状态的切换责任
    交给了具体的状态类去负责。同时，State模式和Strategy模式在图示上有很多相似的地方，需要说明的是两者的思想都是一致的，只不过封装的东西
    不同：
    State模式封装的是不同的状态，而Strategy模式封装的是不同的算法。
 */
class ContextOne;

class State
{
public:
    State();
    virtual ~State();

    virtual void OperationInterface(ContextOne *) = 0;
    virtual void OperationChangeState(ContextOne *) = 0;

protected:
    bool ChangeState(ContextOne *con, State *st);

};

class ConcreteStateA : public State
{
public:
    ConcreteStateA();
    virtual ~ConcreteStateA();
    virtual void OperationInterface(ContextOne *);
    virtual void OperationChangeState(ContextOne *);

};

class ConcreteStateB : public State
{
public:
    ConcreteStateB();
    virtual ~ConcreteStateB();
    virtual void OperationInterface(ContextOne* );
    virtual void OperationChangeState(ContextOne*);

};

class ContextOne
{
public:
    ContextOne();
    ContextOne(State *state);
    ~ContextOne();

    void OperationInterface();
    void OperationChangeState();

private:
    friend class State;//表明在State类中可以访问Context类的private字段，重要是访问ChangeState(State* state),
                        // 在bool State::ChangeState(ContextOne* con, State *st)中要访问。
    bool ChangeState(State *state);

    State *_state;
};

//class GumballMachine;
//class AbstractState
//{
//public:
//    AbstractState(GumballMachine* gm);
//    virtual void insertQuarter() = 0;
//    virtual void ejectQuarter() = 0;
//    virtual void turnCrank() = 0;
//    virtual void dispense() = 0;

//private:
//    GumballMachine* m_gm;
//};

//class SoldState :public AbstractState
//{
//public:
//    virtual void insertQuarter();
//    virtual void ejectQuarter();
//    virtual void turnCrank();
//    virtual void dispense();
//};

//class SoldOutState :public AbstractState
//{
//public:
//    virtual void insertQuarter();
//    virtual void ejectQuarter();
//    virtual void turnCrank();
//    virtual void dispense();
//};

//class NoQuarterState :public AbstractState
//{
//public:
//    NoQuarterState(GumballMachine* gm);
//    virtual void insertQuarter();
//    virtual void ejectQuarter();
//    virtual void turnCrank();
//    virtual void dispense();
//};

//class HasQuarterState :public AbstractState
//{
//public:
//    virtual void insertQuarter();
//    virtual void ejectQuarter();
//    virtual void turnCrank();
//    virtual void dispense();
//};

//class WinnerState :public AbstractState
//{
//public:
//    virtual void insertQuarter();
//    virtual void ejectQuarter();
//    virtual void turnCrank();
//    virtual void dispense();
//};

//class GumballMachine
//{
//public:
//    GumballMachine(AbstractState * state);

//private:
//    AbstractState *m_state;
//};

#endif // EPSTATE_H
