#include "link.h"

class Dog
{
public:
    int m_age;
    Dog* next;
};


int main()
{
    Link<Dog*> lists;
    Dog* dog1 = new Dog;
    dog1->m_age = 10;

    Dog* dog2 = new Dog;
    dog2->m_age = 20;

    Dog* dog3 = new Dog;
    dog3->m_age = 30;

    lists.append(dog1);
    lists.append(dog2);
    lists.append(dog3);
    qDebug()<<lists.count()<<lists.at(2)->m_age;


    Link<int> ints;
    ints.append(12);
    ints.append(13);
    ints.append(14);

    for(int i = 0; i<ints.count(); i++)
    {
        qDebug()<<"value = "<<ints.at(i);
    }
    qDebug()<<"==================================";
    ints.Delete(2);
    for(int i = 0; i<ints.count(); i++)
    {
        qDebug()<<"value = "<<ints.at(i);
    }


    return 0;
}
