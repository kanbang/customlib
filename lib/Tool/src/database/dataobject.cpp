#include "dataobject.h"
#include <QMap>
#include <QDateTime>
#include <QSharedData>
#include <QDebug>

class DataObjectData : public QSharedData {
public:
    uint id;
    QString displayLabel;
    QString firstName;
    QString lowerFirstName;
    QString lastName;
    QString lowerLastName;
    QString middleName;
    QString organization;
    QString gender;
    QString avatar;
    QString ringtone;
    QString syncTarget;
    QString note;
    QString pingyinName;
    QString lowerPingyinName;
    QString t9Index;

    QDateTime birthday;
    QDateTime created;
    QDateTime modified;

    uint mdmId;
    uint calendarId;

    bool isFavorite;

    QMap<QString, QString> phoneNumbers;
    QMap<QString, QString> emailAddresses;
    QMap<QString, QString> addresses;
    QMap<QString,QString> urls;
};

DataObject::DataObject() : data(new DataObjectData)
{
}

DataObject::DataObject(const DataObject &rhs) : data(rhs.data)
{
}

// data.operator=   调用下列函数
// QSharedDataPointer<T> &	operator=(const QSharedDataPointer<T> & other)
DataObject &DataObject::operator=(const DataObject &rhs)
{
    if (this != &rhs)
        data.operator=(rhs.data);
    return *this;
}

DataObject::~DataObject()
{
}

void DataObject::setid(uint id)
{

}
// data->id   调用下列函数
// T *	operator->()
uint DataObject::id() const
{
    return data->id;
}

void DataObject::setDisplayLabel(const QString &displayLabel)
{
    data->displayLabel = displayLabel;
}

QString DataObject::displayLabel() const
{
    return data->displayLabel;
}

void DataObject::setFirstName(const QString &firstName)
{
    data->firstName = firstName;
}

QString DataObject::firstName() const
{
    return data->firstName;
}

void DataObject::setLowerFirstName(const QString &lowerFirstName)
{
    data->lowerFirstName = lowerFirstName;
}

QString DataObject::lowerFirstName() const
{
    return data->lowerFirstName;
}

void DataObject::setLastName(const QString &lastName)
{
    data->lastName = lastName;
}

QString DataObject::lastName() const
{
    return data->lastName;
}

void DataObject::setLowerLastName(const QString &lowerLastName)
{
    data->lowerLastName = lowerLastName;
}

QString DataObject::lowerLastName() const
{
    return data->lowerLastName;
}

void DataObject::setMiddleName(const QString &middleName)
{
    data->middleName = middleName;
}

QString DataObject::middleName() const
{
    return data->middleName;
}

void DataObject::setOrganization(const QString &organization)
{
    data->organization = organization;
}

QString DataObject::organization() const
{
    return data->organization;
}

void DataObject::setGender(const QString &gender)
{
    data->gender = gender;
}

QString DataObject::gender() const
{
    return data->gender;
}

void DataObject::setAvatar(const QString &avatar)
{
    data->avatar = avatar;
}

QString DataObject::avatar() const
{
    return data->avatar;
}

void DataObject::setRingtone(const QString &ringtone)
{
    data->ringtone = ringtone;
}

QString DataObject::ringtone() const
{
    return data->ringtone;
}

void DataObject::setSyncTarget(const QString &syncTarget)
{
    data->syncTarget = syncTarget;
}

QString DataObject::syncTarget() const
{
    return data->syncTarget;
}

void DataObject::setNote(const QString &note)
{
    data->note = note;
}

QString DataObject::note() const
{
    return data->note;
}

QString DataObject::pingyinName() const
{
    return data->pingyinName;
}

QString DataObject::lowerPingyinName() const
{
    return data->lowerPingyinName;
}

QString DataObject::t9Index() const
{
    return data->t9Index;
}

void DataObject::setBirthday(const QDateTime &birthday)
{
    data->birthday = birthday;
}

QDateTime DataObject::birthday() const
{
    return data->birthday;
}

QDateTime DataObject::created() const
{
    return data->created;
}

QDateTime DataObject::modified() const
{
    return data->modified;
}

uint DataObject::mdmId() const
{
    return data->mdmId;
}

uint DataObject::calendarId() const
{
    return data->calendarId;
}

bool DataObject::setIsFavorite(bool isFavorite)
{
    data->isFavorite = isFavorite;
}

bool DataObject::isFavorite() const
{
    return data->isFavorite;
}

bool DataObject::hasPhoneNumber() const
{
    return data->phoneNumbers.count() > 0;
}

bool DataObject::hasEmailAddresses() const
{
    return data->emailAddresses.count() > 0;
}

bool DataObject::hasUrls() const
{
    return data->urls.count() > 0;
}

bool DataObject::hasAddresses() const
{
    return data->addresses.count() > 0;
}

void DataObject::setPhoneNumbers(const QMap<QString, QString> &phoneNumbers)
{
    data->phoneNumbers = phoneNumbers;
}

QMap<QString, QString> DataObject::phoneNumbers() const
{
    return data->phoneNumbers;
}

void DataObject::setEmailAddresses(const QMap<QString, QString> &emailAddresses)
{
    data->emailAddresses = emailAddresses;
}

QMap<QString, QString> DataObject::emailAddresses() const
{
    return data->emailAddresses;
}

void DataObject::setAddresses(const QMap<QString, QString> &addresses)
{
    data->addresses = addresses;
}

QMap<QString, QString> DataObject::addresses() const
{
    return data->addresses;
}

void DataObject::setUrls(const QMap<QString, QString> &urls)
{
    data->urls = urls;
}

QMap<QString, QString> DataObject::urls() const
{
    return data->urls;
}

void DataObject::setPingyinName(const QString &pingyinName)
{
    data->pingyinName = pingyinName;
}

void DataObject::setLowerPingyinName(const QString &pingyinName)
{
    data->lowerPingyinName = pingyinName;
}

void DataObject::setT9Index(const QString &t9Index)
{
    data->t9Index = t9Index;
}

void DataObject::setCreated(const QDateTime &dateTime)
{
    data->created = dateTime;
}

void DataObject::setModified(const QDateTime &dateTime)
{
    data->modified = dateTime;
}

void DataObject::setMdmId(uint mdmId)
{
    data->mdmId = mdmId;
}

void DataObject::setCalendarId(uint calenderId)
{
    data->calendarId = calenderId;
}

QDebug &operator<<(QDebug dbg, const DataObject &contact)
{
    dbg.nospace()<<"DataObject( id: "<<contact.id()<<" , ";
    dbg.nospace()<<"displayLabel: "<<contact.displayLabel()<<" , ";
    dbg.nospace()<<"firstName: "<<contact.firstName()<<" , ";
    dbg.nospace()<<"lowerFirstName: "<<contact.lowerFirstName()<<" , ";
    dbg.nospace()<<"lastName: "<<contact.lastName()<<" , ";
    dbg.nospace()<<"lowerLastName: "<<contact.lowerLastName()<<" , ";
    dbg.nospace()<<"middle: "<<contact.middleName()<<" , ";
    dbg.nospace()<<"organization: "<<contact.organization()<<" , ";
    dbg.nospace()<<"gender: "<<contact.gender()<<" , ";
    dbg.nospace()<<"avatar: "<<contact.avatar()<<" , ";
    dbg.nospace()<<"ringtone: "<<contact.ringtone()<<" , ";
    dbg.nospace()<<"syncTarget: "<<contact.syncTarget()<<" , ";
    dbg.nospace()<<"note: "<<contact.note()<<" , ";
    dbg.nospace()<<"pingyinName: "<<contact.pingyinName()<<" , ";
    dbg.nospace()<<"lowerPingyinName: "<<contact.lowerPingyinName()<<" , ";
    dbg.nospace()<<"t9Index: "<<contact.t9Index()<<" , ";
    dbg.nospace()<<"birthday: "<<contact.birthday()<<" , ";
    dbg.nospace()<<"created: "<<contact.created()<<" , ";
    dbg.nospace()<<"modified: "<<contact.modified()<<" , ";
    dbg.nospace()<<"mdmId: "<<contact.mdmId()<<" , ";
    dbg.nospace()<<"calendarId: "<<contact.calendarId()<<" , ";
    dbg.nospace()<<"isFavorite: "<<contact.isFavorite()<<" , ";
    dbg.nospace()<<"phoneNumbers: "<<contact.phoneNumbers()<<" , ";
    dbg.nospace()<<"emailAddresses: "<<contact.emailAddresses()<<" , ";
    dbg.nospace()<<"addresses: "<<contact.addresses()<<" , ";
    dbg.nospace()<<"urls: "<<contact.urls()<<" )";
    return dbg.maybeSpace();
}
