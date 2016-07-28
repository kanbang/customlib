#ifndef EFFECTIVE_H
#define EFFECTIVE_H
#include <QPoint>

#define ASPCET_RATIO 1.653
#define ADD(x,y)  x+y

template<typename T>
inline T add(T x, T y)
{
    return (x+y);
}

const double AspectRatio = 1.653;
const char hello[] = "hello";

class effective
{
public:
    // 隐式类型转换
    explicit effective();
    effective(const effective& orig);
    const effective& operator=(const effective& orig);
    virtual ~effective();
    const effective& operator+=(const effective& other);
    friend const effective operator+(const effective& left, const effective& right);

private:
    static const int Numbers = 5;
    mutable bool lengthIsValid;
    int scores[Numbers];
};

class A
{
public:
    A(){ pos = QPoint(10,10);}
    virtual void show();
    const QPoint &getPos() const;

    static  int point ;
    int x:4;
private:
    QPoint pos;

};

class Da : public A
{
public:
    static  int point ;
    virtual void show();
};

class D
{
public:
    void dd(){}
    void ss(){}
    void sd(){}
    void ds(){}
    void asd(){}
};

#endif // EFFECTIVE_H
