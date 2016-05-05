#include <QApplication>
#include <EPAdapter.h>
#include <EPBridge.h>
#include <EPComposite.h>
#include <EPDecorator.h>
#include <EPFacade.h>
#include <EPFlyWeight.h>
#include <EPProxy.h>

int main(int argc,char* argv[])
{
    QApplication app(argc,argv);
    StructModel style = EPComposite;

    int *p = new int(10);
    if(p){
        cout<<"p "<<endl;
        delete p;
    }
    if(p){
        cout<<" o "<<endl;
    }
    if(style == EPAdapter)
    {
        Target* adt = new Adapter();
        adt->Request();


        Adaptee* ade = new Adaptee;
        Target* adt1 = new AdapterOne(ade);
        adt1->Request();
    } else if (style == EPBridge)
    {
        AbstractionImp* imp = new ConcreteAbstractionImpA();
        Abstraction* abs1 = new RefinedAbstraction(imp);
        abs1->Operation();
    } else if (style == EPComposite)
    {
        Leaf* l = new Leaf(); l->Operation();
        Composite* com = new Composite();
        com->Add(l);
        com->Operation();
        ComponentOne* ll = com->getChild(0);
        ll->Operation();

    } else if (style == EPDecorator)
    {
        Component* com = new ConcreteComponent();
        Decorator* dec = new ConcreteDecorator(com);
        dec->Operation();
        delete dec;

    } else if (style == EPFacade )
    {
        Facade* f = new Facade();
        f->OperationWrapper();

    } else if (style == EPFlyWeight)
    {
        FlyWeightFactory* fc = new FlyWeightFactory();
        FlyWeight* fw1 = fc->getFlyWeight("hello");
        FlyWeight* fw2 = fc->getFlyWeight("world!");
        FlyWeight* fw3 = fc->getFlyWeight("hello");

    } else if (style == EPProxy)
    {
        Subject* sub = new ConcreteSubject();
        Proxy* p = new Proxy(sub);
        p->Request();
    }
    return app.exec();
}

