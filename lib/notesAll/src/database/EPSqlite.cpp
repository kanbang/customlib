#include "EPSqlite.h"
#include <sqlite3.h>
#include <QFile>
#include <QTextStream>
#include <iostream>
#include <QDir>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>

#include <QDebug>
using namespace std;

QStringList EPSqlite::_numDBs;

EPSqlite::EPSqlite()
{
    /**
      ubuntu 默认安装了 sqlite3，但是没有开发环境，安装 libsqlite3-dev 就好

      */
}

/**
  编译程序的时候，由于sqlite3_open()这个函数在 sqlite3 库里，
  因此需要在platform-app.mk 里添加  -lsqlite3
  否则会报错

  当前路径是 bin里面，也就是执行文件的文件夹里面

  select * from sqlite_master
  .dump person;

  CREATE TABLE blacklist ( id INTEGER PRIMARY KEY AUTOINCREMENT,number TEXT UNIQUE)
  */
void EPSqlite::operatorSqlite()
{
    sqlite3 *db = NULL;

       char* zErrMsg = 0;

       int rc = 1;
       rc = sqlite3_open("test.db", &db);

       if(!rc)
       {
          cout<<"rc = "<<rc<<endl;

       }
       char* sql = "CREATE TABLE Person(name char(20) not null, age int not null);";

       sqlite3_exec(db, sql, 0, 0, &zErrMsg);

       qDebug()<<"Msg0"<<zErrMsg<<QDir::currentPath()<<endl;

       sql = "INSERT INTO \"Person\" VALUES('dashabi',45);";

       sqlite3_exec(db, sql, 0, 0, &zErrMsg);

       int nRow = 0, nColumn = 0;
       char** azResult;

       sql = "SELECT * FROM Person";

       sqlite3_get_table(db, sql, &azResult, &nRow, &nColumn, &zErrMsg);
       qDebug()<<"Row "<< nRow << " Column "<< nColumn;

       for(int i = 0; i < (nRow + 1)*nColumn; i++)
       {
           qDebug()<<" result "<<*(azResult+i);
       }

       sqlite3_close(db);

       //       cout<<"Msg" << zErrMsg<<endl;
}

void EPSqlite::readFile(QHash<int, QString> hash)
{
    QFile file("blacklist.txt");

    if(!file.open(QFile::ReadOnly))
    {
        qDebug()<<__PRETTY_FUNCTION__<<file.errorString();
    }

    QTextStream ts(&file);

//    QStringList numDB;
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

    qDebug()<<QDir::currentPath()+dbName;
    if(!database.open())
    {
        qDebug()<<__PRETTY_FUNCTION__<<"Failed to open blacklist database";
    }/*
    QSqlQuery query(database);

    query.exec("create table phone(number varchar(20) not null primary key, count int, type int, remark text)");

    // 不加事物处理，插入数据非常慢
    database.transaction();
    for(int i = 0; i< _numDBs.count(); i++)
    {
        QString stmt = "INSERT INTO phone('number', 'count') VALUES('%1','1')";

        if(!query.exec(stmt.arg(_numDBs.at(i))))
        {
            qWarning()<<" error "<< query.lastError();
        }
        qDebug()<<i;
    }
//    database.record("phone").
    database.commit();*/
    QString sql = QString("SELECT NUMBER FROM phone");
//    QString sql = QString("Delete NUMBER FROM phone where NUMBER=%1");
    QSqlQuery query1(database);
    if(!query1.exec(sql))
    {
        return ;
    }
    while(query1.next())
    {
        QString str = query1.value(0).toString();
        if(str.right(5) == "10086" && str.length() <= 9)
        {
            qDebug()<<"---------------------";
//            query1.exec(
            qDebug()<<query1.value(0).toString();
        }
    }

    database.close();
    qDebug()<<"db.close";
}
