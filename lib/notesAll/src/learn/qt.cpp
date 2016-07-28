#include "qt.h"
#include <QDebug>

qt::qt()
{
}
void qt::memcpyTest()
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

void qt::qwidget_setWindowFlags()
{
    /**
    去掉最小化最大化：

    this->setWindowFlags(Qt::WindowSystemMenuHint);//这个是只剩下关闭按钮
    this->setWindowFlags(Qt::FramelessWindowHint);//这个是什么按钮都没有了
     */
}

void qt::qwidget_keyPressEvent()
{
    /**
    键盘时间以及字符判定：
    if(event->key() == Qt::Key_Down)
    {
        QString str=label_2->text();
        if(str=="<View Config>"){
        label_1->setText ("View Config");
        label_2->setText ("<View Delay>");
        label_3->setText ("View id Parameters");
    }
    */
}

void qt::qtimer()
{
    /**
    //定时器
    QTimer *timer=new QTimer();
    timer->start(3000);

    注意缺省时QTimer将会不停的生成超时信号，直至你主动停止。
    如果要QTimer超时仅为一次，你可以调用setSingleShot()函数设置true值处理。

    timer->setSingleShot( false ); <-true只循环一次(只发射一次timeout信号)，false无限循环
    connect(timer,SIGNAL(timeout()) ,this, SLOT(firmdisconnectSLot()));
    兄弟的定时器
    但当true的时候timeout是不会停的！
    组合键的运用：
    if(event->modifiers() == Qt::ShiftModifier && event->key() == Qt::Key_Up){
         this->hide();
      }
     */
}

void qt::signalslot()
{
    /**
      信号槽机制和观察者模式的比较类似，connect相当于register的功能，
      但是信号槽机制比观察者模式更好一些，如果删除了观察对象，程序不需要管理内存，
      但是观察者需要把观察者列表里相应的观察对象删除，否则后期运行可能会出错，
      导致程序崩溃
      */
}

void qt::cast()
{
    /**
    class A
    {
    public:
        int x,y;
    };
    int arr[] = { 3,4};
    int *pArr = arr;
    A *a = reinterpret_cast<A*>(pArr);
    qDebug()<<a->x <<"change "<<a->y;
      */
}
