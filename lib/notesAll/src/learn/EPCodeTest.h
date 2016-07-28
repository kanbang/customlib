#ifndef EPCODETEST_H
#define EPCODETEST_H
class pointerClass;

class EPCodeTest
{
public:
    EPCodeTest();

    void transform();
    void aboutList();       // 关于list.h中unique的用法
    void aboutFontWidth();  // 关于字体宽度
};

pointerClass* EPloadPointer(int *num);

class pointerClass
{
public:
    pointerClass() {}
    void    setVal(int val){ m_val = val;}
    int     getVal()    { return m_val;}

private:
    int m_val;
};

//int num;
//pointerClass *pointer = EPloadPointer(&num);

//for(int i =0; i< num;i++)
//{
//    qDebug()<< num << "..." <<pointer[i].getVal();
//}

#endif // EPCODETEST_H
