#include <QApplication>
#include <EPState.h>
#include <EPStrategy.h>
#include <EPTemplate.h>
#include <EPObserver.h>
#include <EPMediator.h>
#include <EPMemento.h>
#include <EPReciever.h>
#include <EPVisitor.h>
#include <EPChainOfResponsibility.h>
#include <EPIterator.h>
#include <EPInterpreter.h>
#include <QDebug>

int main(int argc,char* argv[])
{
    QApplication app(argc,argv);

    ActionModel style = EPState;

    AA a;
    a.move();
    if(style == EPState)
    {
        State* st = new ConcreteStateA();
        ContextOne* con = new ContextOne(st);
        con->OperationChangeState();
        con->OperationChangeState();
        con->OperationChangeState();
        if (con != NULL) delete con;
        if (st != NULL) st = NULL;
    } else if (style == EPObserver)
    {
        ConcreteSubject* sub = new ConcreteSubject();
        Observer* o1 = new ConcreteObserverA(sub);
        Observer* o2 = new ConcreteObserverB(sub);
        sub->setStateOne("old");
        sub->Notify();
        sub->setStateOne("new"); //也可以由Observer调用
        sub->Notify();
        delete o1;
        delete o2;
    } else if ( style == EPStrategy)
    {
        Strategy* ps = new ConcreteStrategyA();
        Context* pc = new Context(ps);
        pc->DoAction();
        if (NULL != pc)
            delete pc;
    } else if ( style == EPTemplate )
    {
        AbstractClass* p1 = new ConcreteClass1();
        AbstractClass* p2 = new ConcreteClass2();
        p1->TemplateMethod();
        p2->TemplateMethod();
    } else if (style == EPMediator )
    {
        ConcreteMediator* m = new ConcreteMediator();
        ConcreteColleageA* c1 = new ConcreteColleageA(m);
        ConcreteColleageB* c2 = new ConcreteColleageB(m);
        m->IntroColleage(c1,c2);
        c1->setState("old");
        //c2->setState("old");
        c1->Action();
        c2->Action();
        cout<<endl;

        c2->setState("new");
        c1->Action();
        c2->Action();
        cout<<endl;

        c2->setState("old");
        c2->Action();
        c1->Action();
    } else if (style == EPMemento)
    {
        Originator *o = new Originator();
        o->setState("old");
        o->PrintState();

        Memento* m = o->CreateMemento();
        o->setState("new");
        o->PrintState();
        o->RestoreToMemento(m);
        o->PrintState();
    } else if (style == EPCommand)
    {
        Reciever *rev = new Reciever();
        Command *cmd = new ConcreteCommand(rev);
        Invoker *inv = new Invoker(cmd);
        inv->Invoke();
    } else if (style == EPVisitor)
    {
        Visitor* vis = new ConcreteVisitorA();
        Element* elm = new ConcreteElementA();
        elm->Accept(vis);
    } else if (style == EPChainOfResponsibility)
    {
        Handle *h1 = new ConcreteHandleA();
        Handle *h2 = new ConcreteHandleB();
        h1->setSuccessor(h2);
        h1->HandleRequest();
    } else if (style == EPIterator)
    {
        Aggregate* ag = new ConcreteAggregate();
        Iterator* it = new ConcreteIterator(ag);
        for(;!(it->IsDone());it->Next())
        {
            cout<< it->currentItem() <<endl;
        }
    } else if (style == EPInterpreter)
    {
        Context1 *c = new Context1();
        AbstractExpression* te = new TerminalExpression("hello");
        AbstractExpression* nte = new NonterminalExpression(te,2);
        //te->interpret(*c);
        nte->interpret(*c);
    }
    return app.exec();
}
