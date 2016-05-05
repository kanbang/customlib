#ifndef EPITERATOR_H
#define EPITERATOR_H

typedef int Object;

#include <iostream>
using namespace std;

/**
 \brief 作用
    提供一种方法顺序访问一个聚合对象中各个元素，而又不需要暴露该对象的内部表示。

 \brief
    Iterator 提供一种方式，使得算法和容器可以独立的变化，而且在访问容器对象的时候，不必暴露容器的内部细节，具体是怎么做
    到这一点呢？在STL的实现中，所有的迭代器（Iterator）都必须遵照一套规范，这套规范里面定义了几种类型的名称，比如对象的名称，
    指向对象的指针的名称，指向对象的引用的名称...等等。

  \brief
    当新生成一个容器的时候与之对应的Iterator都要遵守这个规范里面所定义的名称，这样在外部看来虽然里面的实现细节不一样，
    但是作用（也就是对外的表象）都是一样的，通过某个名称可以得到容器包含的对象，通过某个名称可以得到容器包含的对象的指针
    等等。而且，采用这个模式把访问容器对象的算法不需要知道需要处理的是什么容器，只需要遵守事先约定好的Iterator的规范就可以了；
    而对于各个容器而言，不管内部的事先如何，是树还是链表还是数组，只需要对外的接口也遵守Iterator的标准，这样算法（Iterator
    的使用者）和容器（Iterator的提供者）就能很好的进行合作，而且不必关心对方是如何事先的，简而言之，Iterator就是算法和容器之间的一座
    桥梁。
 */
class Aggregate;

class Iterator
{
public:
    virtual ~Iterator();
    virtual void First() = 0;
    virtual void Next() = 0;
    virtual bool IsDone() = 0;
    virtual Object currentItem() = 0;

protected:
    Iterator();
};


class Aggregate
{
public:
    virtual ~Aggregate();
    virtual Iterator* createIterator() = 0;
    virtual Object getItem(int idx) = 0;
    virtual int getSize() = 0;

protected:
    Aggregate();
};

class ConcreteAggregate : public Aggregate
{
public:
    enum {SIZE = 3};
    ConcreteAggregate();
    ~ConcreteAggregate();
    Iterator* createIterator();
    Object getItem(int idx);
    int getSize();

private:
    Object _objs[SIZE];
};

class ConcreteIterator : public Iterator
{
public:
    ConcreteIterator(Aggregate* ag ,int idx = 0);
    ~ConcreteIterator();
    void First();
    void Next();
    bool IsDone();
    Object currentItem();

private:
    Aggregate* _ag;
    int _idx;
};

#endif // EPITERATOR_H
