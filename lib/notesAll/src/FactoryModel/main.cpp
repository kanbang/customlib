#include <QApplication>
#include <EPEffective.h>
#include <QDebug>
#include <iostream>
#include <QUrl>
#include <QDir>
#include <QFileInfo>
//#include <QUrlInfo>
#include <EPBuilder.h>
#include <EPFactory.h>
#include <EPPrototype.h>
#include <EPSingleton.h>
#include <AbstractFactory.h>

const int gv = 20;
int main(int argc,char* argv[])
{
    QApplication app(argc,argv);
    factoryModel style = EPAbstractFactory;

    if (style == EPEffective)
    {
        Shape *pr = new Rectangle;
        pr->draw();
        pr->draw(Shape::Green);

        Shape *pc = new Circle;
        pc->draw(Shape::Blue);
    } else if (style == EPFactory)
    {
        Factory *fac = new ConcreteFactory();
        Product *p = fac->CreateProduct();
        delete p;
    } else if (style == EPBuilder )
    {
        Director* d = new Director(new ConcreteBuilder());
        d->Construct();
    } else if (style == EPAbstractFactory)
    {
        AbstractFactory *cf1 = new ConcreteFactory1();
        cf1->CreateProductA();
        cf1->CreateProductB();

        AbstractFactory *cf2 = new ConcreteFactory2();
        cf2->CreateProductA();
        cf2->CreateProductB();
        int *p = NULL;
        int x = 10;
        p = &x;
        ConcreteFactory2 *cf3 = (ConcreteFactory2*)cf2;
        cf3->create(p);
    }

    return app.exec();
}
