#include "EPIterator.h"

Iterator::Iterator()
{
}

Iterator::~Iterator()
{

}

Aggregate::Aggregate()
{

}

Aggregate::~Aggregate()
{

}

ConcreteAggregate::ConcreteAggregate()
{
    for(int i = 0; i< SIZE ; i++)
        _objs[i] = i;
}

ConcreteAggregate::~ConcreteAggregate()
{

}

Iterator* ConcreteAggregate::createIterator()
{
    return new ConcreteIterator(this);
}

Object ConcreteAggregate::getItem(int idx)
{
    if(idx < this->getSize())
        return _objs[idx];
    else
        return -1;
}

int ConcreteAggregate::getSize()
{
    return SIZE;
}

ConcreteIterator::ConcreteIterator(Aggregate *ag, int idx)
{
    this->_ag = ag;
    this->_idx = idx;
}

ConcreteIterator::~ConcreteIterator()
{

}

Object ConcreteIterator::currentItem()
{
    return _ag->getItem(_idx);
}

void ConcreteIterator::First()
{
    _idx = 0;
}

void ConcreteIterator::Next()
{
    if(_idx < _ag->getSize())
        _idx++;
}

bool ConcreteIterator::IsDone()
{
    return (_idx == _ag->getSize());
}

//Aggregate* ag = new ConcreteAggregate();
//Iterator* it = new ConcreteIterator(ag);
//for(;!(it->IsDone());it->Next())
//{
//    cout<< it->currentItem() <<endl;
//}
