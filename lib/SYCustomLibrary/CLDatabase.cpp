#include "CLDatabase.h"


CLDatabase::CLDatabase()
{
    QString dbName = "/harassment.db";
    m_db = QSqlDatabase::addDatabase(QLatin1String("QSQLITE"));
    m_db.setDatabaseName(QDir::currentPath() + dbName);

    m_maps.clear();
    if( !m_db.open() )
    {
        qDebug()<<"Failed to open the database";
    }

    QSqlQuery query(m_db);
    QString sql = QString("SELECT * FROM harass");
    if(query.exec(sql))
    {
        int i = 0;
        while(query.next())
        {
            QStringList tmps;
            for(int j = 0; j<query.record().count(); j++)
            {
                tmps<<query.value(j).toString();
            }
            m_maps[i]=tmps;
            i++;
        }
    }

    qDebug()<<__PRETTY_FUNCTION__<<m_db.driverName();
    m_db.close();
}

QMap<int, QStringList> &CLDatabase::getTable()
{
    return m_maps;
}

QSqlDatabase CLDatabase::createDb(const QString &path)
{
    QFile file("blacklist.txt");

    if(!file.open(QFile::ReadOnly))
    {
        qDebug()<<__PRETTY_FUNCTION__<<file.errorString();
    }

    QTextStream ts(&file);
    QStringList _numDBs;

    _numDBs.clear();

    while(!ts.atEnd())
    {
        QString line = ts.readLine();
        if(line.left(6) == "INSERT")
        {
            QStringList lists = line.split("(");
            for(int i = 1; i<lists.count(); i++)
            {
                QString number = lists.at(i).split(",").at(1);
                number.replace("'","");
                _numDBs.append(number);
            }
        }
    }

    qDebug()<<__PRETTY_FUNCTION__<<_numDBs.at(117743);

    QString dbName = "/harassment.db";
    QSqlDatabase database = QSqlDatabase::addDatabase(QLatin1String("QSQLITE"), dbName);
    database.setDatabaseName(QDir::currentPath() + dbName);
    database.setHostName("xingkongdao");
    database.setPort(10000);
    database.setUserName("xkd");
    database.setPassword("xkd123");
    qDebug()<<QDir::currentPath()+dbName;
    if(!database.open())
    {
        qDebug()<<__PRETTY_FUNCTION__<<"Failed to open blacklist database";
    }
    QSqlQuery query(database);

    query.exec("create table harass(id int not null primary key, number varchar(20) not null, count int ,description varchar(20))");
    // 不加事物处理，插入数据非常慢
    database.transaction();
    for(int i = 0; i< _numDBs.count(); i++)
    {
        QString stmt = "INSERT INTO harass(id, number, count, description) VALUES(%1, '%2', 1, 'the %3 harassment phone')";

        if(!query.exec(stmt.arg(i).arg(_numDBs.at(i)).arg(i)))
        {
            qWarning()<<" error "<< query.lastError();
        }

    }
    database.commit();
    database.close();

    return database;
}

