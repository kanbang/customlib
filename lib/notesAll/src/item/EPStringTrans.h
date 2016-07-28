#ifndef EPSTRINGTRANS_H
#define EPSTRINGTRANS_H

#include <QString>

class EPStringTrans
{
public:
    EPStringTrans();

    static char* qstringToChar(const QString& qstr);
    static const char* qstringToConstChar(const QString& qstr);
    static QString charToQString(char* c);
};

#endif // EPSTRINGTRANS_H
