#ifndef TABLEDATA_H
#define TABLEDATA_H

#include <QObject>
#include "EPDatabase_global.h"
#include "managerdb.h"

class RecordData;
class DATABASE_EXPORT TableData : public QObject
{
    Q_OBJECT
public:
    explicit TableData(QObject *parent = 0);
    TableData(const TableData& tdata);
    TableData& operator=(const TableData& tdata);

    void append(RecordData* rdata);
    void setTableName(const QString& name);
    QString tableName() const;
    QStringList fieldNames() const;
    int columnCount() const;
    int rowCount() const;
    QVariant data(int row, int column) const;
    bool setData(int row, int column);
    QList<RecordData*> queryTableByField(const QString& fieldName, const QVariant& value) const;
protected:
    void setProperty(const char *name, const QVariant &value);

private:
    friend QDebug& operator<<(QDebug dbg, const TableData& tdata);
    friend class ManagerDB;
    QList<RecordData*> m_records;
    QString m_name;
};

class DATABASE_EXPORT RecordData : public QObject
{
    Q_OBJECT
public:
    explicit RecordData(QObject* parent = 0);
    RecordData(const RecordData& rdata);
    RecordData& operator=(const RecordData& rdata);

    int count() const;
    QVariant data(int index) const;
    QVariant data(const QString& name) const;

    QString tableName() const;

    void setTable(TableData* table);
    TableData* getTable();
protected:
    void setProperty(const char *name, const QVariant &value);

private:
    TableData* m_pTable;
    QString m_tableName;
    friend QDebug& operator<<(QDebug dbg, const RecordData& rdata);
    friend class ManagerDB;
};

QDebug& operator<<(QDebug dbg, const TableData& tdata);
QDebug& operator<<(QDebug dbg, const RecordData& rdata);

#endif // TABLEDATA_H
