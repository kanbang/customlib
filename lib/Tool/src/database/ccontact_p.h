#ifndef CCONTACT_P_H
#define CCONTACT_P_H

#include <private/qobject_p.h>
#include <qglobal.h>
#include <QString>
#include <QMap>
#include <QDateTime>
#include "ccontact.h"

class CContactPrivate : public QObjectPrivate
{
    Q_DECLARE_PUBLIC(CContact)

public:
    CContactPrivate();
    virtual ~CContactPrivate();

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

    QMap<QString, QString> cfields;
};

#endif // CCONTACT_P_H
