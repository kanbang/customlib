#ifndef DEFINETYPE_H
#define DEFINETYPE_H

class TestClass
{
public:
    TestClass()
    {
        m_class.m_x = 100;
    }

    int getValue()
    {
        return m_class.m_x;
    }

    int getTest()
    {
        return m_val;
    }

    class ChildClass
    {
    public:
        ChildClass()
        {
//            m_val = 200;
        }

        int m_x;
    };


private:
    int m_val;
    ChildClass m_class;
};

#endif // DEFINETYPE_H
