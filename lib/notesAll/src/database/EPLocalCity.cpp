#include "EPLocalCity.h"
#include <QString>

#define DATABASE_PATH "/home/xkd/"
#define DATABASE_NAME "locatedcity.db"

EPLocalCity::EPLocalCity()
{
    initCityAndOperatorData();
}


void EPLocalCity::initCityAndOperatorData()
{
    QDir databaseDir( QLatin1String(DATABASE_PATH) );

    if (!databaseDir.exists())
    {
        qDebug()<<"DB DIR NOT EXIST";
        databaseDir.mkpath(QLatin1String("."));
    }

    const QString databaseFile = databaseDir.absoluteFilePath(QLatin1String(DATABASE_NAME));

    m_database = QSqlDatabase::addDatabase(QLatin1String("QSQLITE"), "locatedcity.db");
    m_database.setDatabaseName(databaseFile);
    if(!m_database.open())
    {
        qDebug()<<"ERROR: open file";
    }
    else
    {
            QString queryexp("SELECT * FROM city");
            QSqlQuery query(m_database);
            int cityCount = 0;
            int numberCount = 0;
            if(query.exec(queryexp))
            {
                while(query.next())
                {
                    QSqlRecord record = query.record();
                    QString id = record.field(0).value().toString();
                    QString city = record.field(1).value().toString();
                    QString areacode = record.field(2).value().toString();
                    m_attriAreas[areacode] = city;
                    m_attriAreaIds[id] = city;
                    cityCount++;
                }
                qDebug()<<"cityCount==============112=============="<<cityCount;
            }

            QString numexp("SELECT * FROM phonenumbers");
            QSqlQuery queryNum(m_database);

            if(queryNum.exec(numexp))
            {
                while(queryNum.next())
                {
                    QSqlRecord record = queryNum.record();
                    QString phonenumber = record.field(0).value().toString();
                    QString areaid= record.field(1).value().toString();
                    m_numAreasIds[phonenumber] = areaid;
                    numberCount++;
                }
                qDebug()<<"numberCount=============123==============="<<numberCount;
            }
    }
}


QString EPLocalCity::attribution(QString number)
{
    QString attribution;
    qDebug()<<Q_FUNC_INFO<<"====1====="<<number;
    // trip the country code.
    if( number.startsWith(QStringLiteral("+86")) ){
        number = number.right( number.length()-3);
    }

    if( number.startsWith(QStringLiteral("1")) ){
        qDebug()<<Q_FUNC_INFO<<"====cellphone====="<<number;
        // cell phone number
        if( number.length() >= 7 ){
            QString left =number.left(7);
            qDebug()<<Q_FUNC_INFO<<"====cellphone===left=="<<left;
            qDebug()<<Q_FUNC_INFO<<"====cellphone===id=="<<m_attriAreaIds[m_numAreasIds[left]]<<"===="<< m_numAreasIds[left];

            attribution = m_attriAreaIds[m_numAreasIds[left]];
        }
    }
    else if( number.startsWith("0") )
    {
        qDebug()<<Q_FUNC_INFO<<"====telephone====="<<number;
        QString  prefix = number.left(2);
        if( prefix == QStringLiteral("01") || prefix == QStringLiteral("02") )
        {
            prefix = number.left(3);
        }
        else
        {
            prefix = number.left(4);
        }
        attribution = m_attriAreas[prefix];
    }

    return attribution;
}

QString EPLocalCity::locateOperator(QString number )
{
    if( number.startsWith(QStringLiteral("+86")) )
    {
        number = number.right( number.length()-3);
    }

    QString result;
    if(number.startsWith(QStringLiteral("1")))
    {
        if(number.length() >= 7)
        {
            QString mobile("中国移动");
            QString telecom("中国电信");
            QString unicome("中国联通");

            if( number.length() >= 3 ){

                int prifix = number.left(3).toInt();
                switch ( prifix ) {
                case 135:
                case 136:
                case 137:
                case 138:
                case 139:
                case 147:
                case 150:
                case 151:
                case 152:
                case 157:
                case 158:
                case 159:
                case 183:
                case 187:
                case 188:
                   {
                       result = mobile;
                       break;
                   }
                case 130:
                case 131:
                case 132:
                case 145:
                case 155:
                case 156:
                case 185:
                case 186:
                {
                    result = unicome;
                    break;
                }
                case 133:
                case 153:
                case 180:
                case 181:
                case 189:
                {
                    result = telecom;
                    break;
                }
                case 134:
                {
                    if( number.at(3) == QChar('9'))  result = telecom;
                    else result = mobile;
                }

                default:
                    break;
                }
            }
        }
    }
    return result;
}

