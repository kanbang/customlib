#ifndef EPCFUNCTION_H
#define EPCFUNCTION_H
#include <QString>

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

class EPCFunction
{
public:
    EPCFunction();

    static void memcpyTest();

};

#if defined(__cplusplus) || defined(c_plusplus)
extern "C" {
#endif
    QString getString();

#if defined(__cplusplus) || defined(c_plusplus)
}
#endif

//当析构的时候，只是把p指针的本身的地址删除。但是p指针指向的内存没有删除。
class memory
{
public:
    memory();
    ~memory();
    int *p;
};

#endif // EPCFUNCTION_H
