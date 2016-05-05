#include "AbShareMemoryWidgetApp.h"

ShareMemoryLoad::ShareMemoryLoad(QWidget *parent):QWidget(parent),sharedMem("MemoryTest")
{
    //loadIntoSharedMem();
}

ShareMemoryLoad::~ShareMemoryLoad()
{}

void ShareMemoryLoad::loadIntoSharedMem()
{
  if (sharedMem.create(5))
  {
      sharedMem.lock();
      QList<int> from;
      from.append(1);
      from.append(5);
      from.append(9);
      from.append(7);
      from.append(7);

      QList<int> *to=static_cast<QList<int>*>(sharedMem.data());
      int s=from.size();

      //从源src所指的内存地址的起始位置开始拷贝n个字节到目标dest所指的内存地址的起始位置中
      //void *memcpy(void *dest, const void *src, size_t n);
      memcpy(to,&from,s);
      sharedMem.unlock();
  }
}

ShareMemoryShow::ShareMemoryShow(QWidget *parent):QWidget(parent),sharedMem("MemoryTest")
{
    //showIntoSharedMem();
}

ShareMemoryShow::~ShareMemoryShow()
{}

void ShareMemoryShow::showIntoSharedMem()
{
  if (sharedMem.attach())
  {
      sharedMem.lock();
      int s;
      const QList<int> *list=static_cast<const QList<int>*>(sharedMem.constData());
      if(list)
          s=list->size();
      QList<int> test;
      memcpy(&test,list,s);
      sharedMem.unlock();
      foreach(int i, *list)
          qDebug()<< __PRETTY_FUNCTION__<<i;
  }
}
//QSharedMemory sharedmem("dbzhang800-shared-qt4");
//if (sharedmem.create(1024)) {
//    qDebug("shared memory created.");

//    QList<int> dataList;
//    dataList<<1<<2<<3<<4<<5;
//    QByteArray bytes;
//    QDataStream stream(&bytes, QIODevice::WriteOnly);
//    stream << dataList;

//    sharedmem.lock();
//    char * to = static_cast<char*>(sharedmem.data());
//    ::memcpy(to, bytes.data(), bytes.size());
//    sharedmem.unlock();

//} else if (sharedmem.attach()) {
//    qDebug("shared memory attached.");

//    sharedmem.lock();
//    QByteArray bytes(static_cast<char*>(sharedmem.data()), 1024);
//    sharedmem.unlock();

//    QList<int> dataList;
//    QDataStream stream(bytes);
//    stream>>dataList;
//    qDebug()<<dataList;
//}
//else {
//    qDebug("unknown error.");
//}
