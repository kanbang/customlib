#ifndef CCONTACTDB_H
#define CCONTACTDB_H

#include <QObject>
#include <QtSql>
#include "ccontact.h"
#include "EPDatabase_global.h"

class DATABASE_EXPORT CContactDB : public QObject
{
    Q_OBJECT

public:
    QList<CContact> getContacts();
    bool deleteContacts(QList<uint> ids);
    bool saveContacts(QList<CContact*> contacts);
    bool importFromVCard(const QString& path);
    bool exportToVCard(const QString& path);
    static CContactDB *instance();

protected:
    bool deleteContact(uint id);
    bool updateContact(uint id);
    bool saveContact(CContact *contact);
    bool savePhoneNumbers(CContact* contact);
    bool readPhoneNumbers(CContact* contact);
    bool saveEmailAddresses(CContact* contact);
    bool readEmailAddresses(CContact* contact);
    bool saveUrls(CContact* contact);
    bool readUrls(CContact* contact);
    bool saveAddresses(CContact* contact);
    bool readAddresses(CContact* contact);

private:
    class ARC
    {
    public:
        ~ARC()
        {
            if(CContactDB::_instance)
            {
                delete CContactDB::_instance;
                CContactDB::_instance = NULL;
            }
        }
    };

private:
    explicit CContactDB(QObject *parent = 0);
    QSqlDatabase m_database;
    static CContactDB* _instance;
    static ARC arc;
    QList<CContact*> contacts;
};

#endif // CCONTACTDB_H
