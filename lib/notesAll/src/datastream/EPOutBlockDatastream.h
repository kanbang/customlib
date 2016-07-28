#ifndef EPOUTBLOCKDATASTREAM_H
#define EPOUTBLOCKDATASTREAM_H
#include <QByteArray>

class EPOutBlockDatastream
{
public:
    EPOutBlockDatastream();

    void showData();
private:
    QByteArray outBlock;
};

#endif // EPOUTBLOCKDATASTREAM_H
