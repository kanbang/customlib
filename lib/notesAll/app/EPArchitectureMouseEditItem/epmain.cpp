#include <QApplication>
#include <EPmapView.h>
#include <EPDBus.h>
#include <EPSqlite.h>
#include <QDebug>
#include <EPLocalCity.h>
#include <SemaphoreThread.h>

int main(int argc,char* argv[])
{
    QApplication app(argc,argv);

//    SemaphoreConsumer cunsumer;
//    SemaphoreProducer producer;

//    producer.start();
//    cunsumer.start();

    bool b = true;
    qDebug()<<(b == false || 1);
    return app.exec();
}

