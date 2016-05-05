#include "EPCFunction.h"
#include <string.h>
#include <QDebug>

EPCFunction::EPCFunction()
{
}

void EPCFunction::memcpyTest()
{
    int *p = new int[10];
    int *point = p;
    for(int i = 0; i< 10; i++){
        *point = i;
        qDebug()<<__PRETTY_FUNCTION__<<*point;
        point++;
    }

    p = p + 2;
    //如果想把指针p所指向的内存数据复制到指针data里面。那么data要开辟足够的内存来存储指针p的数据。
    //如果data这么定义，那么运行就会崩溃。应为没有足够的内存来存储数据。
    // int *data = 0;
    int *data = new int[5];
    memcpy(data,p,sizeof(int)*5);
    for(int i = 0; i<5; i++)
    {
        qDebug()<<*data;
        data++;
    }
}

QString getString()
{
    return QString("xingkongdao");
}

memory::memory()
{
    p = new int(10);
}

memory::~memory()
{
    if(p){
        delete p;
        p = NULL;
    }
}
