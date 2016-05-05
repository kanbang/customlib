#include "ccontactdb.h"
#include "utildb.h"

#define CONTACT_DATABASE_DIR "/home/xkd/tmp"
#define CONTACT_DATABASE_NAME "contacts.db"

static const char *db_setup[] =
{
    "PRAGMA temp_store = MEMORY",
    "PRAGMA journal_mode = WAL",
    "PRAGMA foreign_keys = ON"
};

static int db_setup_count = sizeof(db_setup) / sizeof(*db_setup);

static const char *contacts_schema[] =
{
    "PRAGMA encoding = \"UTF-8\"",
    "CREATE TABLE Contacts ( "
    "contactId INTEGER PRIMARY KEY ASC AUTOINCREMENT,"
    "displayLabel TEXT,"
    "firstName TEXT,"
    "lowerFirstName TEXT,"
    "lastName TEXT,"
    "lowerLastName TEXT,"
    "middleName TEXT,"
    "organization TEXT,"
    "gender TEXT,"
    "avatar TEXT,"
    "ringtone TEXT,"
    "syncTarget TEXT NOT NULL,"
    "note TEXT,"
    "pingyinName TEXT,"
    "lowerPingyinName TEXT,"
    "t9Index TEXT,"
    "birthday DATETIME,"
    "created DATETIME,"
    "modified DATETIME,"
    "mdmId INTEGER,"
    "calendarId INTEGER,"
    "isFavorite BOOL,"
    "hasPhoneNumber BOOL,"
    "hasEmailAddresses BOOL,"
    "hasUrls BOOL,"
    "hasAddresses BOOL"
    ")"
};

static const char *phonenumbers_schema[] =
{
    "PRAGMA encoding = \"UTF-8\"",
    "CREATE TABLE PhoneNumbers ( "
    "detailId INTEGER PRIMARY KEY ASC AUTOINCREMENT,"
    "contactId INTEGER KEY,"
    "phoneNumber TEXT,"
    "type TEXT,"
    "normalizedNumber TEXT"
    ")"
};

static const char *urls_schema[] =
{
    "PRAGMA encoding = \"UTF-8\"",
    "CREATE TABLE Urls ( "
    "detailId INTEGER PRIMARY KEY ASC AUTOINCREMENT,"
    "contactId INTEGER KEY,"
    "url TEXT,"
    "type TEXT"
    ")"
};

static const char *emailAddresses_schema[] =
{
    "PRAGMA encoding = \"UTF-8\"",
    "CREATE TABLE EmailAddresses ( "
    "detailId INTEGER PRIMARY KEY ASC AUTOINCREMENT,"
    "contactId INTEGER KEY,"
    "emailAddress TEXT,"
    "lowerEmailAddress TEXT,"
    "type TEXT,"
    "customText TEXT"
    ")"
};

static const char *addresses_schema[] =
{
    "PRAGMA encoding = \"UTF-8\"",
    "CREATE TABLE Addresses ( "
    "detailId INTEGER PRIMARY KEY ASC AUTOINCREMENT,"
    "contactId INTEGER KEY,"
    "street TEXT,"
    "postOfficeBox TEXT,"
    "region TEXT,"
    "locality TEXT,"
    "postCode TEXT,"
    "type  TEXT,"
    "country TEXT,"
    "customTypeText TEXT"
    ")"
};

CContactDB* CContactDB::_instance = NULL;
CContactDB::ARC  CContactDB::arc;

QList<CContact> CContactDB::getContacts()
{
    QList<CContact> contacts;
    QSqlQuery query(m_database);
    QString cmd = "SELECT * FROM Contacts";
    if(!query.exec(cmd))
    {
        qDebug()<<Q_FUNC_INFO<<query.lastError();
        qDebug()<<Q_FUNC_INFO<<cmd;
    }
    else
    {
        while(query.next())
        {
            QSqlRecord record = query.record();
            CContact contact;
            for(int i = 0; i<record.count(); i++)
            {
                QSqlField field = record.field(i);
                if(field.name() == "contactId")
                {
                    contact.setid(field.value().toUInt());                    
                }
                else if( field.name() == "displayLabel")
                {
                    contact.setDisplayLabel(field.value().toString());
                }
                else if (field.name() == "firstName")
                {
                    contact.setFirstName(field.value().toString());
                }
                else if (field.name() == "lowerFirstName")
                {
                    contact.setLowerFirstName(field.value().toString());
                }
                else if(field.name() == "lastName")
                {
                    contact.setLastName(field.value().toString());
                }
                else if (field.name() == "lowerLastName")
                {
                    contact.setLowerLastName(field.value().toString());
                }
                else if (field.name() == "middleName")
                {
                    contact.setMiddleName(field.value().toString());
                }
                else if (field.name() == "organization")
                {
                    contact.setOrganization(field.value().toString());
                }
                else if (field.name() == "gender")
                {
                    contact.setGender(field.value().toString());
                }
                else if (field.name() == "avatar")
                {
                    contact.setAvatar(field.value().toString());
                }
                else if (field.name() == "ringtone")
                {
                    contact.setRingtone(field.value().toString());
                }
                else if (field.name() == "syncTarget")
                {
                    contact.setSyncTarget(field.value().toString());
                }
                else if (field.name() == "note")
                {
                    contact.setNote(field.value().toString());
                }
                else if (field.name() == "pingyinName")
                {
                    contact.setPingyinName(field.value().toString());
                }
                else if (field.name() == "lowerPingyinName")
                {
                    contact.setLowerPingyinName(field.value().toString());
                }
                else if (field.name() == "t9Index")
                {
                    contact.setT9Index(field.value().toString());
                }
                else if (field.name() == "birthday")
                {
                    contact.setBirthday(field.value().toDateTime());
                }
                else if(field.name() == "created")
                {
                    contact.setCreated(field.value().toDateTime());
                }
                else if (field.name() == "modified")
                {
                    contact.setModified(field.value().toDateTime());
                }
                else if (field.name() == "mdmId")
                {
                    contact.setMdmId(field.value().toUInt());
                }
                else if (field.name() == "calendarId")
                {
                    contact.setCalendarId(field.value().toUInt());
                }
                else if (field.name() == "isFavorite")
                {
                    contact.setIsFavorite(field.value().toBool());
                }
            }
            readPhoneNumbers(&contact);
            readAddresses(&contact);
            readEmailAddresses(&contact);
            readUrls(&contact);
            contacts.append(contact);
            qDebug()<<Q_FUNC_INFO<<"="<<contact;
        }
    }

    return contacts;
}

bool CContactDB::deleteContact(uint id)
{
    if(id == 0)
    {
        qDebug()<<"The Contact ID = 0";
        return false;
    }
    QStringList tables = m_database.tables();
    QSqlQuery query(m_database);
    foreach(QString tableName, tables)
    {
        if(tableName == "sqlite_sequence")
            continue;
        QString cmd = QString("delete from %1 where contactId = %2").arg(tableName).arg(id);
        if(!query.exec(cmd))
        {
            qDebug()<<Q_FUNC_INFO<<query.lastError();
            qDebug()<<Q_FUNC_INFO<<tableName;
            return false;
        }
    }
    return true;
}

bool CContactDB::deleteContacts(QList<uint> ids)
{
    if(!m_database.transaction())
    {
        qDebug()<<Q_FUNC_INFO<<"fail to begin a transaction";
        return false;
    }
    bool error = false;
    foreach(uint id, ids)
    {
        error = deleteContact(id);
        if(!error)
        {
            m_database.rollback();
            return false;
        }
    }
    return m_database.commit();
}

bool CContactDB::saveContact(CContact *contact)
{
    if(contact->id() != 0)
    {
        qDebug()<<"the contact has exists";
        return false;
    }
    QSqlQuery query(m_database);
    QString schema = QString("insert into Contacts(displayLabel, firstName, lowerFirstName,"
                          "lastName, lowerLastName, middleName, organization, gender, avatar,"
                          "ringtone, syncTarget, note, pingyinName, lowerPingyinName, t9Index,"
                          "birthday, created, modified, mdmId, calendarId, isFavorite,"
                          "hasPhoneNumber, hasEmailAddresses,hasUrls, hasAddresses)"
                          " values('%1','%2','%3','%4','%5','%6','%7','%8','%9',"
                          "'%10','%11','%12','%13','%14','%15','%16','%17','%18','%19','%20',"
                          "'%21','%22','%23','%24','%25')").arg(contact->displayLabel()).arg(contact->firstName())
            .arg(contact->lowerFirstName()).arg(contact->lastName()).arg(contact->lowerLastName())
            .arg(contact->middleName()).arg(contact->organization()).arg(contact->gender())
            .arg(contact->avatar()).arg(contact->ringtone()).arg(contact->syncTarget()).arg(contact->note())
            .arg(contact->pingyinName()).arg(contact->lowerPingyinName()).arg(contact->t9Index())
            .arg(contact->birthday().toString("yyyy-MM-dd")).arg(contact->created().toString("yyyy-MM-dd"))
            .arg(contact->modified().toString("yyyy-MM-dd")).arg(contact->mdmId())
            .arg(contact->calendarId()).arg(contact->isFavorite()).arg(contact->hasPhoneNumber())
            .arg(contact->hasEmailAddresses()).arg(contact->hasUrls()).arg(contact->hasAddresses());

    if(!query.exec(schema))
    {
        qDebug()<<Q_FUNC_INFO<<query.lastError();
        return false;
    }
    contact->setid(query.lastInsertId().toUInt());
    qDebug()<<Q_FUNC_INFO<<contact->id();
    if(!savePhoneNumbers(contact))
        return false;
    if(!saveEmailAddresses(contact))
        return false;
    if(!saveAddresses(contact))
        return false;
//    if(!saveUrls(contact))
//        return false;

    return true;
}

bool CContactDB::saveContacts(QList<CContact *> contacts)
{
    if(!m_database.transaction())
    {
        qDebug()<<Q_FUNC_INFO<<"fail to begin a transaction";
        return false;
    }
    bool error = false;
    foreach(CContact* contact, contacts)
    {
        error = saveContact(contact);
        if(!error)
        {
            m_database.rollback();
            return false;
        }
    }
    return m_database.commit();
}

bool CContactDB::updateContact(uint id)
{
    return true;
}

CContactDB *CContactDB::instance()
{
    if(!_instance)
    {
        _instance = new CContactDB();
    }
    return _instance;
}

bool CContactDB::savePhoneNumbers(CContact *contact)
{
    QSqlQuery query(m_database);

    QList<QString> keys = contact->phoneNumbers().keys();
    QList<QString>::const_iterator it = keys.begin();
    bool error = false;
    for(; it != keys.end(); it++)
    {

        QString cmd = QString("INSERT INTO PhoneNumbers(contactId, phoneNumber, type)"
                              " VALUES('%1','%2','%3')").arg(contact->id()).arg(contact->phoneNumbers().value(*it))
                .arg(*it);
        if(!query.exec(cmd))
        {
            qDebug()<<Q_FUNC_INFO<<query.lastError();
            qDebug()<<Q_FUNC_INFO<<cmd;
            error = true;
        }
    }
    return !error;
}

bool CContactDB::saveEmailAddresses(CContact *contact)
{
    QSqlQuery query(m_database);

    QList<QString> keys = contact->emailAddresses().keys();
    QList<QString>::const_iterator it = keys.begin();
    bool error = false;
    for(; it != keys.end(); it++)
    {

        QString cmd = QString("INSERT INTO EmailAddresses(contactId, emailAddress, type)"
                              " VALUES('%1','%2','%3')").arg(contact->id()).arg(contact->emailAddresses().value(*it))
                .arg(*it);
        if(!query.exec(cmd))
        {
            qDebug()<<Q_FUNC_INFO<<query.lastError();
            qDebug()<<Q_FUNC_INFO<<cmd;
            error = true;
        }
    }
    return !error;
}

bool CContactDB::saveUrls(CContact *contact)
{
    QSqlQuery query(m_database);

    QList<QString> keys = contact->urls().keys();
    QList<QString>::const_iterator it = keys.begin();
    bool error = false;
    for(; it != keys.end(); it++)
    {

        QString cmd = QString("INSERT INTO Urls(contactId, url, type)"
                              " VALUES('%1','%2','%3')").arg(contact->id()).arg(contact->urls().value(*it))
                .arg(*it);
        if(!query.exec(cmd))
        {
            qDebug()<<Q_FUNC_INFO<<query.lastError();
            qDebug()<<Q_FUNC_INFO<<cmd;
            error = true;
        }
    }
    return !error;
}

bool CContactDB::saveAddresses(CContact *contact)
{

    QSqlQuery query(m_database);

    QList<QString> keys = contact->addresses().keys();
    QList<QString>::const_iterator it = keys.begin();
    bool error = false;
    for(; it != keys.end(); it++)
    {

        QString cmd = QString("INSERT INTO Addresses(contactId, street, type)"
                              " VALUES('%1','%2','%3')").arg(contact->id()).arg(contact->addresses().value(*it))
                .arg(*it);
        if(!query.exec(cmd))
        {
            qDebug()<<Q_FUNC_INFO<<query.lastError();
            qDebug()<<Q_FUNC_INFO<<cmd;
            error = true;
        }
    }
    return !error;
}

CContactDB::CContactDB(QObject *parent) :
    QObject(parent)
{
    QString path = QString(CONTACT_DATABASE_DIR) + "/" + QString(CONTACT_DATABASE_NAME);
    bool exists = QFile::exists(path);
    m_database = UtilDB::createDatabase(CONTACT_DATABASE_DIR, CONTACT_DATABASE_NAME);

    if (!m_database.open())
    {
        qWarning() << QString("Failed to open %1 database").arg(m_database.databaseName());
        qWarning() << m_database.lastError();
    }
    else
    {
        qWarning() <<QString( "Opened %1 database:").arg(m_database.databaseName());
    }
    if(!exists)
    {
        QStringList schemas;
        schemas<<QString(contacts_schema[0])<<QString(contacts_schema[1])<<QString(phonenumbers_schema[1])<<QString(urls_schema[1])
                <<QString(emailAddresses_schema[1])<<QString(addresses_schema[1]);
        UtilDB::createTable(m_database, schemas);
    }
}

bool CContactDB::readPhoneNumbers(CContact *contact)
{
    QSqlQuery query(m_database);
    QString cmd = QString("SELECT * FROM PhoneNumbers WHERE contactId = %1").arg(contact->id());
    if(!query.exec(cmd))
    {
        qDebug()<<Q_FUNC_INFO<<query.lastError();
        qDebug()<<Q_FUNC_INFO<<cmd;
    }
    else
    {
        QMap<QString, QString> maps;
        maps.clear();
        while(query.next())
        {
            QSqlRecord record = query.record();
            QString type;
            QString value;
            for(int i = 0; i<record.count(); i++)
            {
                QSqlField field = record.field(i);
                if(field.name() == "phoneNumber")
                {
                    value = field.value().toString();
                }
                else if (field.name() == "type")
                {
                    type = field.value().toString();
                }
            }
            if(!type.isEmpty() && !value.isEmpty())
            {
                maps[type] = value;
            }
            contact->setPhoneNumbers(maps);
        }
    }
}

bool CContactDB::readEmailAddresses(CContact *contact)
{

    QSqlQuery query(m_database);
    QString cmd = QString("SELECT * FROM EmailAddresses WHERE contactId = %1").arg(contact->id());
    if(!query.exec(cmd))
    {
        qDebug()<<Q_FUNC_INFO<<query.lastError();
        qDebug()<<Q_FUNC_INFO<<cmd;
    }
    else
    {
        QMap<QString, QString> maps;
        maps.clear();
        while(query.next())
        {
            QSqlRecord record = query.record();
            QString type;
            QString value;
            for(int i = 0; i<record.count(); i++)
            {
                QSqlField field = record.field(i);
                if(field.name() == "emailAddress")
                {
                    value = field.value().toString();
                }
                else if (field.name() == "type")
                {
                    type = field.value().toString();
                }
            }
            if(!type.isEmpty() && !value.isEmpty())
            {
                maps[type] = value;
            }
            contact->setEmailAddresses(maps);
        }
    }
}

bool CContactDB::readUrls(CContact *contact)
{
    QSqlQuery query(m_database);
    QString cmd = QString("SELECT * FROM Urls WHERE contactId = %1").arg(contact->id());
    if(!query.exec(cmd))
    {
        qDebug()<<Q_FUNC_INFO<<query.lastError();
        qDebug()<<Q_FUNC_INFO<<cmd;
    }
    else
    {
        QMap<QString, QString> maps;
        maps.clear();
        while(query.next())
        {
            QSqlRecord record = query.record();
            QString type;
            QString value;
            for(int i = 0; i<record.count(); i++)
            {
                QSqlField field = record.field(i);
                if(field.name() == "url")
                {
                    value = field.value().toString();
                }
                else if (field.name() == "type")
                {
                    type = field.value().toString();
                }
            }
            if(!type.isEmpty() && !value.isEmpty())
            {
                maps[type] = value;
            }
            contact->setUrls(maps);
        }
    }
}

bool CContactDB::readAddresses(CContact *contact)
{

    QSqlQuery query(m_database);
    QString cmd = QString("SELECT * FROM Addresses WHERE contactId = %1").arg(contact->id());
    if(!query.exec(cmd))
    {
        qDebug()<<Q_FUNC_INFO<<query.lastError();
        qDebug()<<Q_FUNC_INFO<<cmd;
    }
    else
    {
        QMap<QString, QString> maps;
        maps.clear();
        while(query.next())
        {
            QSqlRecord record = query.record();
            QString type;
            QString value;
            for(int i = 0; i<record.count(); i++)
            {
                QSqlField field = record.field(i);
                if(field.name() == "street")
                {
                    value = field.value().toString();
                }
                else if (field.name() == "type")
                {
                    type = field.value().toString();
                }
            }
            if(!type.isEmpty() && !value.isEmpty())
            {
                maps[type] = value;
            }
            contact->setAddresses(maps);
        }
    }
}

bool CContactDB::importFromVCard(const QString &path)
{
    QFile file(path);
    if(!file.open(QIODevice::ReadOnly))
    {
        qDebug()<<Q_FUNC_INFO<<" can not open the file: "<<path;
        return false;
    }
    QList<CContact> contacts;
    QTextStream out(&file);
    while(!out.atEnd())
    {

    }
    return true;
}

bool CContactDB::exportToVCard(const QString &path)
{

}

