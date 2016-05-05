#ifndef DATAOBJECT_H
#define DATAOBJECT_H

// 写时分开
#include <QSharedDataPointer>
//  共享数据
#include <QExplicitlySharedDataPointer>

#include <QDateTime>
#include <QMap>

class DataObjectData;

class DataObject
{
public:
    DataObject();
    DataObject(const DataObject &);
    DataObject &operator=(const DataObject &);
    ~DataObject();

    void setid(uint id);
    uint id() const;

    void setDisplayLabel(const QString& displayLabel);
    QString displayLabel() const;

    void setFirstName(const QString& firstName);
    QString firstName() const;

    void setLowerFirstName(const QString& lowerFirstName);
    QString lowerFirstName() const;

    void setLastName(const QString& lastName);
    QString lastName() const;

    void setLowerLastName(const QString& lowerLastName);
    QString lowerLastName() const;

    void setMiddleName(const QString& middleName);
    QString middleName() const;

    void setOrganization(const QString& organization);
    QString organization() const;

    void setGender(const QString& gender);
    QString gender() const;

    void setAvatar(const QString& avatar);
    QString avatar() const;

    void setRingtone(const QString& ringtone);
    QString ringtone() const;

    void setSyncTarget(const QString& syncTarget);
    QString syncTarget() const;

    void setNote(const QString& note);
    QString note() const;

//    void setPingyinName(const QString& pingyinName);
    QString pingyinName() const;

//    void setLowerPingyinName(const QString& pingyinName);
    QString lowerPingyinName() const;

//    void setT9Index(const QString& t9Index);
    QString t9Index() const;

    void setBirthday(const QDateTime& birthday);
    QDateTime birthday() const;

    QDateTime created() const;

    QDateTime modified() const;

    uint mdmId() const;

    uint calendarId() const;

    bool setIsFavorite(bool isFavorite);
    bool isFavorite() const;

    bool hasPhoneNumber() const;
    bool hasEmailAddresses() const;
    bool hasUrls() const;
    bool hasAddresses() const;

    void setPhoneNumbers(const QMap<QString, QString>& phoneNumbers);
    QMap<QString, QString> phoneNumbers() const;

    void setEmailAddresses(const QMap<QString, QString>& emailAddresses);
    QMap<QString, QString> emailAddresses() const;

    void setAddresses(const QMap<QString, QString>& addresses);
    QMap<QString, QString> addresses() const;

    void setUrls(const QMap<QString, QString>& urls);
    QMap<QString, QString> urls() const;

private:
    void setPingyinName(const QString& pingyinName);
    void setLowerPingyinName(const QString& pingyinName);
    void setT9Index(const QString& t9Index);
    void setCreated(const QDateTime& dateTime);
    void setModified(const QDateTime& dateTime);
    void setMdmId(uint mdmId);
    void setCalendarId(uint calenderId);
    friend QDebug& operator<<(QDebug dbg, const DataObject& contact);
    friend class CContactDB;
private:
    QSharedDataPointer<DataObjectData> data;
};

QDebug& operator<<(QDebug dbg, const DataObject& contact);
#endif // DATAOBJECT_H
