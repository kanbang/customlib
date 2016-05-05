#ifndef DATABASEMANAGERPROXY_H
#define DATABASEMANAGERPROXY_H

#include "managerdb.h"

class DatabaseManagerProxy
{
public:
        static DatabaseManagerProxy* instance();
        ManagerDB* managerDb(const QString& urlName);

private:
        explicit DatabaseManagerProxy();

        QMap<QString, ManagerDB*> m_maps;
};

#endif // DATABASEMANAGERPROXY_H
