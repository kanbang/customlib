#include "effective.h"
#include <QDebug>

char greeting[] = "Hello";
char* p = greeting;
const char* pChar = greeting;
char* const pConst = greeting;
const char* const pCharConst = greeting;

const int effective::Numbers;//不需要给初值
effective::effective()
{
    /**
      \brief
      初始化列表，这样就减少一次构造函数的调用
      确认变量在使用前就已经初始化了。

      */
}

effective::~effective()
{ 

}

effective::effective(const effective &orig)
{
    /**
      @a 不想使用的编译器自动生成的函数，就明确使用他
      */
}

const effective& effective::operator =(const effective& orig)
{
    if(this == &orig){

    }
}

const effective& effective::operator +=(const effective& orig)
{

}

const effective operator +(const effective& left,const effective& right)
{

}

 int A::point =5 ;
 int Da::point = 6;
void A::show()
{
    qDebug()<<__PRETTY_FUNCTION__;
    qDebug()<<pos;
}

const QPoint& A::getPos() const
{
    return pos;
}
void Da::show()
{
    static_cast<A>(*this).show();
}
