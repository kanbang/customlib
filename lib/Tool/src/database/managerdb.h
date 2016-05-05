#ifndef MANAGERDB_H
#define MANAGERDB_H

#include <QObject>
#include <QSqlDatabase>
#include <QMap>
#include <QStringList>
#include <QVariant>
#include "EPDatabase_global.h"

class TableData;
class DATABASE_EXPORT ManagerDB : public QObject
{
    Q_OBJECT

public:
    ManagerDB(QObject *parent = 0);
    ManagerDB(const QString& path, const QString& name, QObject* parent = 0);
    void setPathAndName(const QString& path, const QString& name);
    QString getDbPath() const;
    TableData* tableData(const QString& name);
    QList<TableData*> tableDatas();

    QStringList tableNames() const;
    void getTableSchemaInfo();

protected:
    bool loadData();

private:
    QSqlDatabase m_db;
    QString m_path;
    QString m_name;
    QList<TableData*> m_tableDatas;
};

#endif // MANAGERDB_H
