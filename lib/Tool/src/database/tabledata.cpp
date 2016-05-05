#include "tabledata.h"
#include <QStringList>
#include <QDebug>

TableData::TableData(QObject *parent) :
    QObject(parent)
{
}

TableData::TableData(const TableData &tdata)
{
    QList<QByteArray> arrays = tdata.dynamicPropertyNames();
    foreach(QByteArray array, arrays)
    {
        const char* nm = array.constData();
        qDebug()<<Q_FUNC_INFO<<nm;
        setProperty(nm, tdata.property(nm));
    }
}

TableData &TableData::operator=(const TableData &tdata)
{
    QList<QByteArray> arrays = tdata.dynamicPropertyNames();
    foreach(QByteArray array, arrays)
    {
        const char* nm = array.constData();
        qDebug()<<Q_FUNC_INFO<<nm;
        setProperty(nm, tdata.property(nm));
    }
    return *this;
}

void TableData::append(RecordData *rdata)
{
    rdata->setTable(this);
    m_records.append(rdata);
}

void TableData::setTableName(const QString &name)
{
    m_name = name;
}

QString TableData::tableName() const
{
    return m_name;
}

QStringList TableData::fieldNames() const
{
    QStringList fields;
    if(m_records.count() > 0)
    {
        QList<QByteArray> arrays = m_records[0]->dynamicPropertyNames();
        foreach(QByteArray array, arrays)
        {
            fields.append(QString(array.constData()));
        }
    }
    return fields;
}

int TableData::columnCount() const
{
    if(m_records.count() > 0)
        return m_records[0]->count();
    else
        return 0;
}

int TableData::rowCount() const
{
    return m_records.count();
}

QVariant TableData::data(int row, int column) const
{
    if(m_records.count() > 0)
    {
        if(column >= m_records[0]->count() || row >= m_records.count())
        {
            return QVariant();
        }
        else
        {
            RecordData* rdate = m_records[row];
            return rdate->data(column);
        }
    }
}

bool TableData::setData(int row, int column)
{
    return false;
}

QList<RecordData *> TableData::queryTableByField(const QString &fieldName, const QVariant &value) const
{
    QList<RecordData*> records;
    QStringList fields = fieldNames();
    if(!fields.contains(fieldName))
    {
        qDebug()<<QString("There is no %1 field in the table, or there is no record in the table !").arg(fieldName);
        return records;
    }

    foreach(RecordData* record, m_records)
    {
        if(record->property(fieldName.toStdString().c_str()) == value)
        {
            records.append(record);
        }
    }

    return records;
}

void TableData::setProperty(const char *name, const QVariant &value)
{
    QObject::setProperty(name,value);
}

RecordData::RecordData(QObject *parent)
    :QObject(parent),
      m_pTable(NULL)
{
}

RecordData::RecordData(const RecordData &rdata)
{
    QList<QByteArray> arrays = rdata.dynamicPropertyNames();
    foreach(QByteArray array, arrays)
    {
        const char* nm = array.constData();
        qDebug()<<Q_FUNC_INFO<<nm;
        setProperty(nm, rdata.property(nm));
    }
}

RecordData &RecordData::operator=(const RecordData &rdata)
{
    QList<QByteArray> arrays = rdata.dynamicPropertyNames();
    foreach(QByteArray array, arrays)
    {
        const char* nm = array.constData();
        qDebug()<<Q_FUNC_INFO<<nm;
        setProperty(nm, rdata.property(nm));
    }
    return *this;
}

int RecordData::count() const
{
    return dynamicPropertyNames().count();
}

QVariant RecordData::data(int index) const
{
    QList<QByteArray> arrays = dynamicPropertyNames();
    if(arrays.count() < index)
        return QVariant();
    else
    {
        QByteArray array = arrays.at(index);
        return property(array.constData());
    }
}

QVariant RecordData::data(const QString &name) const
{
    QList<QByteArray> arrays = dynamicPropertyNames();
    QByteArray array(name.toStdString().c_str());
    if(arrays.contains(array))
    {
        return property(array.constData());
    }
    else
    {
        qDebug()<<QString("there is no field named %1").arg(name);
        return QVariant();
    }
}

QString RecordData::tableName() const
{
    return m_pTable ? m_pTable->tableName() : QString();
}

void RecordData::setTable(TableData *table)
{
    m_pTable = table;
}

TableData *RecordData::getTable()
{
    return m_pTable;
}

void RecordData::setProperty(const char *name, const QVariant &value)
{
    QObject::setProperty(name,value);
}

QDebug &operator<<(QDebug dbg, const TableData &tdata)
{
    int i = 0;
    int count = tdata.m_records.count();
    dbg.nospace()<<"TabeData( ";
    foreach (RecordData *rdata,  tdata.m_records) {
        dbg.nospace()<<" ( "<<*rdata<<((i == count -1) ? ")" : " ), ");
        dbg.nospace()<<"\n";
        i++;
    }
    dbg.nospace()<<" )";
    return dbg.maybeSpace();
}

QDebug &operator<<(QDebug dbg, const RecordData &rdata)
{
    dbg.nospace()<<"RecordData( ";
    QList<QByteArray> arrays = rdata.dynamicPropertyNames();
    int i = 0;
    int count = arrays.count();
    foreach(QByteArray array, arrays)
    {
        const char* nm = array.constData();
        dbg.nospace()<<" ( "<<nm <<" , "<<rdata.property(nm)<<((i == count -1) ? ")" : " ), ");
        i++;
    }
    dbg.nospace()<<" )";
    return dbg.maybeSpace();
}
