#include "SemaphoreThread.h"
#include <QDebug>
// 这些全局变量不能放在EPFourthSemaphoresApp.h头文件中
// 否则报错
// 在linux下可以直接在头文件中定义类中静态变量的值，
// 但如果在win下的qt中直接定义全局变量的值则会提示错误。

const int DataSize = 10;
const int BufferSize = 2;
char buffer[BufferSize];

QSemaphore freeSpace(BufferSize);
QSemaphore usedSpace(0);

void SemaphoreProducer::run()
{
    qDebug()<<Q_FUNC_INFO;
    for (int i = 0; i < DataSize; ++i) {
        qDebug()<<"producer-------"<<i;
        //freeSpace可以同时被最多BufferSize次访问
        //有这两个语句，就是当buffer写入BufferSize个字符时，就会被读掉(因为freeSpace可以同时被最多BufferSize次访问).
        // 当freeSpace写满(写了BufferSize个字节)后，如果uesdSpace还没有读取，那么acquire就开始堵塞。写不了。
        //要等usedSpace开始读数据后才能写。
        freeSpace.acquire(); // acquire(int n=1)视图获得n资源，如果没有这些资源，他将堵塞
        buffer[i % BufferSize] = "AC"[i % 2];
        qDebug()<<"free "<< buffer[i % BufferSize];
        usedSpace.release(); // release(int n=1)释放n资源,

//        QThread::sleep(1);
    }
}

void SemaphoreConsumer::run()
{
    qDebug()<<Q_FUNC_INFO;
    for (int i = 0; i < DataSize; ++i) {
        // 当freeSpace没有可读数据了，usedSpace就会堵塞。等到freeSpace写入数据了才能读。
        qDebug()<<"consumer-------"<<i;
        usedSpace.acquire();
//        QThread::sleep(1);
        qDebug()<< "use "<<buffer[i % BufferSize];
        freeSpace.release();
    }
}
