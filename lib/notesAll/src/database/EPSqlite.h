#ifndef EPSQLITE_H
#define EPSQLITE_H

#include <QStringList>
#include <QHash>

class EPSqlite
{
public:
    EPSqlite();

    static void operatorSqlite();

    static void readFile(QHash<int, QString> hash = QHash<int, QString>());

    static QStringList _numDBs;
};

#endif // EPSQLITE_H
