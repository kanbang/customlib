#ifndef CCONTACT_H
#define CCONTACT_H

#include <QObject>
#include "EPDatabase_global.h"

// http://www.cnblogs.com/SkylineSoft/articles/2046404.html

class CContactPrivate;
class DATABASE_EXPORT CContact : public QObject
{
    Q_OBJECT
    Q_DECLARE_PRIVATE(CContact)

public:
    explicit CContact(QObject *parent = 0);
    CContact(const CContact& contact);
    CContact& operator=(const CContact& contact);

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
    friend class CContactDB;
    friend QDebug& operator<<(QDebug dbg, const CContact& contact);
};

QDebug& operator<<(QDebug dbg, const CContact& contact);


#endif // CCONTACT_H
