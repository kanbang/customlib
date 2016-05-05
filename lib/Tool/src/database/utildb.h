#ifndef UTILDB_H
#define UTILDB_H

#include "EPDatabase_global.h"
#include <QtSql>

class DATABASE_EXPORT UtilDB
{
public:
    enum Type{
        oInteger,
        oReal,
        oBool,
        oText,
        oBlob
    };

public:
    static QSqlDatabase createDatabase(const QString& path, const QString& name, bool close = true);

    static bool setDatabaseSchema(QSqlDatabase& db, const QStringList& schemas);
    static bool createTable(QSqlDatabase& db, const QStringList& schemas);
    static bool addField(QSqlDatabase& db, const QString& tableName, const QString& schema);
};

#endif // UTILDB_H
