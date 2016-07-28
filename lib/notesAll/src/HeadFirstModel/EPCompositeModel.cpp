#include "EPCompositeModel.h"

AbstractQuackable::AbstractQuackable()
{
    m_oed = new QuackObservable(this);
}

void AbstractQuackable::registerObserver(Observer *obv)
{
    m_oed->registerObserver(obv);
}

void AbstractQuackable::notifyObservers()
{
    m_oed->notifyObservers();
}

void NewMallardDuck::quack()
{
    qDebug()<<__PRETTY_FUNCTION__<<"Quack";
    notifyObservers();
}

void NewRedheadDuck::quack()
{
    qDebug()<<__PRETTY_FUNCTION__<<"Quack";
    notifyObservers();
}

void NewDuckCall::quack()
{
    qDebug()<<__PRETTY_FUNCTION__<<"Kwak";
    notifyObservers();
}

void NewRubberDuck::quack()
{
    qDebug()<<__PRETTY_FUNCTION__<<"Squeak";
    notifyObservers();
}

void Goose::honk()
{
    qDebug()<<__PRETTY_FUNCTION__<<"Honk";
}

GooseAdapter::GooseAdapter(Goose *goose)
{
    m_goose = goose;
}

void GooseAdapter::quack()
{
    m_goose->honk();
    notifyObservers();
}

void DuckSimulator::simulate(AbstractDuckFactory* duckFactory)
{
//    AbstractQuackable* mallardDuck  = new NewMallardDuck();
//    AbstractQuackable* redheadDuck  = new NewRedheadDuck();
//    AbstractQuackable* duckCall     = new NewDuckCall();
//    AbstractQuackable* rubberDuck   = new NewRedheadDuck();
//    AbstractQuackable* gooseDuck    = new GooseAdapter(new Goose);

    AbstractQuackable* mallardDuck = duckFactory->createMallardDuck();
    AbstractQuackable* redheadDuck = duckFactory->createRedheadDuck();
    AbstractQuackable* duckCall = duckFactory->createDuckCall();
    AbstractQuackable* rubberDuck = duckFactory->createRubberDuck();
    AbstractQuackable* gooseDuck = new GooseAdapter(new Goose());

    qDebug()<<"\n Duck Simulator";

    Flock *flockOfDucks = new Flock();
    flockOfDucks->add(mallardDuck);
    flockOfDucks->add(redheadDuck);
    flockOfDucks->add(duckCall);
    flockOfDucks->add(rubberDuck);
    flockOfDucks->add(gooseDuck);

    Flock *flockOfMallards = new Flock();
    AbstractQuackable* mallardOne = duckFactory->createMallardDuck();
    AbstractQuackable* mallardTwo = duckFactory->createMallardDuck();
    AbstractQuackable* mallardThree = duckFactory->createMallardDuck();
    AbstractQuackable* mallardFour = duckFactory->createMallardDuck();

    flockOfMallards->add(mallardOne);
    flockOfMallards->add(mallardTwo);
    flockOfMallards->add(mallardThree);
    flockOfMallards->add(mallardFour);

    flockOfDucks->add(flockOfMallards);

//    qDebug()<<"\n Duck Simulator : Whole Flock Simulator";
//    simulate(flockOfDucks);

//    qDebug()<<"\n Duck Simulator : Mallard Flock Simulator";
//    simulate(flockOfMallards);

//    simulate(mallardDuck);
//    simulate(redheadDuck);
//    simulate(duckCall);
//    simulate(rubberDuck);
//    simulate(gooseDuck);

    qDebug()<<"\n Duck Simulator :With Observer";
    Quackologist* quackologist = new Quackologist();
    flockOfDucks->registerObserver(quackologist);
    simulate(flockOfDucks);
    qDebug()<<__PRETTY_FUNCTION__<<"The Quack Times "<<QuackCounter::getQuacks();
}

void DuckSimulator::simulate(AbstractQuackable *duck)
{
    duck->quack();
}

void Flock::add(AbstractQuackable* quacker)
{
    lists.append(quacker);
}

void Flock::quack()
{
    foreach(AbstractQuackable* quacker, lists)
        quacker->quack();
    notifyObservers();
}

void Quackologist::update(AbstractQuackable *duck)
{
    qDebug()<<__PRETTY_FUNCTION__;
//    duck->quack();
}

QuackObservable::QuackObservable(AbstractQuackable *duck)
{
    m_duck = duck;
}

void QuackObservable::registerObserver(Observer *obv)
{
    _obvs.append(obv);
}

void QuackObservable::notifyObservers()
{
    foreach(Observer* obv, _obvs)
        obv->update(m_duck);
}

void QuackObservable::setQuackable(AbstractQuackable *duck)
{
    m_duck = duck;
}

int QuackCounter::numberOfQuacks = 0;
QuackCounter::QuackCounter(AbstractQuackable *duck)
{
    m_duck = duck;
}

void QuackCounter::quack()
{
    m_duck->quack();
    numberOfQuacks++;
}

int QuackCounter::getQuacks()
{
    return numberOfQuacks;
}

AbstractQuackable* DuckFactory::createMallardDuck()
{
    return new NewMallardDuck();
}

AbstractQuackable* DuckFactory::createRedheadDuck()
{
    return new NewRedheadDuck();
}

AbstractQuackable* DuckFactory::createDuckCall()
{
    return new NewDuckCall();
}

AbstractQuackable* DuckFactory::createRubberDuck()
{
    return new NewRubberDuck();
}

AbstractQuackable* CountingDuckFactory::createMallardDuck()
{
    return new QuackCounter(new NewMallardDuck());
}

AbstractQuackable* CountingDuckFactory::createRedheadDuck()
{
    return new QuackCounter(new NewRedheadDuck());
}

AbstractQuackable* CountingDuckFactory::createDuckCall()
{
    return new QuackCounter(new NewDuckCall());
}

AbstractQuackable* CountingDuckFactory::createRubberDuck()
{
    return new QuackCounter(new NewRubberDuck());
}
