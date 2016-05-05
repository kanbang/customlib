#ifndef EPLOCALCITY_H
#define EPLOCALCITY_H

#include <QtSql>

class EPLocalCity
{
public:
    EPLocalCity();

    void initCityAndOperatorData();
    QString attribution( QString number );
    QString locateOperator( QString number );

private:
    QSqlDatabase m_database;
    //归属地 归属地区号
    QMap<QString, QString> m_attriAreas;
    //归属地 归属地id
    QMap<QString,QString> m_attriAreaIds;
    //号码 归属地id
    QMap<QString, QString> m_numAreasIds;
};

#endif // EPLOCALCITY_H
