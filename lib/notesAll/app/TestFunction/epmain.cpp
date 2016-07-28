#include <ETestHeader.h>
#include <TreeWidget.h>
static const uint qt_meta_data_AadlgClientApp[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      16,   15,   15,   15, 0x08,
      23,   15,   15,   15, 0x08,
      39,   15,   15,   15, 0x08,
      68,   15,   15,   15, 0x08,
     111,   15,   15,   15, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_AadlgClientApp[] = {
    "AadlgClientApp\0\0send()\0startTransfer()\0"
    "updateClientProgress(qint64)\0"
    "displayError(QAbstractSocket::SocketError)\0"
    "openFile()\0"
};

int main(int argc, char* argv[])
{
    QApplication app(argc,argv);
    TestWindowApp w;

    w.show();

//    qDebug()<<sizeof(qt_meta_data_AadlgClientApp)/sizeof(uint);
//    qDebug()<<sizeof(qt_meta_stringdata_AadlgClientApp)/sizeof(char);

//    const char* p = qt_meta_stringdata_AadlgClientApp;
//    for(int i = 0; i<123; i++){
//        if(p[i] == '\0')
//            qDebug()<<"i = "<<i;
//        qDebug()<<p[i];
//    }
//    qDebug()<<qt_meta_stringdata_AadlgClientApp;
    return app.exec();
}
