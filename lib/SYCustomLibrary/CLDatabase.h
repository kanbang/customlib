#include <QSqlDatabase>
#include <QtSql>

class CLDatabase
{

public:
    CLDatabase();
    QMap<int, QStringList>& getTable();

    static QSqlDatabase createDb(const QString& path);

private:
    QSqlDatabase m_db;
    QMap<int, QStringList> m_maps;
};
