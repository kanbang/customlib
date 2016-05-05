#include <QSqlDatabase>

#include "managerdb.h"
#include "utildb.h"
#include "tabledata.h"

ManagerDB::ManagerDB(QObject *parent)
    :QObject(parent)
{
}

ManagerDB::ManagerDB(const QString &path, const QString &name, QObject *parent)
{
    m_path = path;
    m_name = name;
//    bool exists = QFile::exists(m_path + "/" + m_name);
    if(m_db.isOpen())
        m_db.close();
    m_db = UtilDB::createDatabase(path, name);
    if (!m_db.open())
    {
        qWarning() << QString("Failed to open %1 database").arg(m_db.databaseName());
        qWarning() << m_db.isOpenError();
    }
    else
    {
        qWarning() <<QString( "Opened %1 database:").arg(m_db.databaseName());
    }

    loadData();
}

void ManagerDB::setPathAndName(const QString &path, const QString &name)
{
    if(m_path == path && m_name == name)
        return;

    m_path = path;
    m_name = name;
//    bool exists = QFile::exists(m_path + "/" + m_name);
    if(m_db.isOpen())
        m_db.close();
    m_db = UtilDB::createDatabase(path, name);
    if (!m_db.open())
    {
        qWarning() << QString("Failed to open %1 database").arg(m_db.databaseName());
        qWarning() << m_db.isOpenError();
    }
    else
    {
        qWarning() <<QString( "Opened %1 database:").arg(m_db.databaseName());
    }
    loadData();
}

QString ManagerDB::getDbPath() const
{
    return m_path;
}

TableData *ManagerDB::tableData(const QString &name)
{
    foreach (TableData* tdata, m_tableDatas) {
        if(tdata->tableName() == name)
        {
            return tdata;
        }
    }

    return NULL;
}

QList<TableData *> ManagerDB::tableDatas()
{
    return m_tableDatas;
}

QStringList ManagerDB::tableNames() const
{
    return m_db.tables();
}

/**
当一张表包含了用 "AUTOINCREMENT" 修饰的列时, sqlite 将自动创建表 "SQLITE_SEQUENCE"。
表SQLITE_SEQUENCE中只有两个字段： name, seq 。
建表语句为： CREATE TABLE sqlite_sequence(name,seq);
注3：可以向 sqlite_sequence 中添加重复的记录
seq值是可以手工修改的。
 */
void ManagerDB::getTableSchemaInfo()
{
    QStringList tableNames = m_db.tables();

    QSqlQuery query(m_db);
    for(int i = 0; i<tableNames.count(); i++)
    {
        QString cmd = QString("SELECT * FROM %1").arg(tableNames[i]);
        if(!query.exec(cmd))
        {
            qDebug()<<query.lastError();
            continue;
        }
        // 先是schema，然后是record。
        QSqlRecord record = query.record();
        QStringList schemas;
        for(int index = 0; index < record.count(); index++)
        {
            schemas.append(record.fieldName(index));
        }
        continue;
    }
}

bool ManagerDB::loadData()
{
    QStringList tableNames = m_db.tables(QSql::Tables);
    qDebug()<<Q_FUNC_INFO<< tableNames;
    QSqlQuery query(m_db);

    m_tableDatas.clear();
    foreach(QString name, tableNames)
    {
        QString cmd = QString("SELECT * FROM %1").arg(name);
        if(!query.exec(cmd))
        {
            qDebug()<<Q_FUNC_INFO<<query.lastError();
            return false;
        }
        TableData* tdata = new TableData();
        while(query.next())
        {
            RecordData *rdata = new RecordData();
            QSqlRecord record = query.record();
            for(int i = 0; i< record.count(); i++)
            {
                QSqlField field = record.field(i);
                rdata->setProperty(field.name().toStdString().c_str(), field.value());
            }
            tdata->append(rdata);
        }
        tdata->setTableName(name);
//        qDebug()<<Q_FUNC_INFO<< *tdata;
        m_tableDatas.append(tdata);
    }
    return true;
}
