#include "ccontact.h"
#include "ccontact_p.h"
#include <QDebug>

CContact::CContact(QObject *parent) :
    QObject(*new CContactPrivate(), parent)
{
    Q_D(CContact);
    /*
    d->id = 0;
    d->displayLabel = "xingkd";
    d->firstName = "xing";
    d->lowerFirstName = "xing";
    d->lastName = "dao";
    d->lowerLastName = "dao";
    d->middleName = "kong";
    d->organization = "yuanxin";
    d->gender = "male";
    d->avatar = "file:://home/xkd/1.jpg";
    d->ringtone = "file::///home/xkd/hello.mp3";
    d->syncTarget = "ok";
    d->note = "Hello World";
    d->pingyinName = "xingkongdao";
    d->lowerPingyinName = "xingkongdao";
    d->t9Index = "94645664326,953";

    d->birthday = QDateTime(QDate(1998,7,20));
    d->created = QDateTime();
    d->modified = QDateTime();

    d->mdmId = 0;
    d->calendarId = 0;
    d->isFavorite = false;

    d->phoneNumbers["HOME"] = "15120077642";
    d->phoneNumbers["WORK"] = "13681524845";
    d->emailAddresses["GERNAL"] = "444071704@qq.com";
    d->emailAddresses["WORK"] = "chen12nan@sina.com";
    d->addresses["HOME"] = "rong-ze-jia-yuan";
    d->addresses["WORK"] = "hang-xin-yuan";
    d->urls["WEBSITE"]= "www.baidu.com";
    */
}

// 如果不加入QObject(* new CContactPrivate()),
// 那么拷贝构造的时候，没有d指针，导致不能拷贝
CContact::CContact(const CContact &contact)
    :QObject(*new CContactPrivate())
{
    Q_D(CContact);

    d->id = contact.id();
    d->displayLabel = contact.displayLabel();
    d->firstName = contact.firstName();
    d->lowerFirstName = contact.lowerFirstName();
    d->lastName = contact.lastName();
    d->lowerLastName = contact.lowerLastName();
    d->middleName = contact.middleName();
    d->organization = contact.organization();
    d->gender = contact.gender();
    d->avatar = contact.avatar();
    d->ringtone = contact.ringtone();
    d->syncTarget = contact.syncTarget();
    d->note = contact.note();
    d->pingyinName = contact.pingyinName();
    d->lowerPingyinName = contact.lowerPingyinName();
    d->t9Index = contact.t9Index();
    d->birthday = contact.birthday();
    d->created = contact.created();
    d->modified = contact.modified();
    d->mdmId = contact.mdmId();
    d->calendarId = contact.calendarId();
    d->isFavorite = contact.isFavorite();

    d->phoneNumbers = contact.phoneNumbers();
    d->emailAddresses = contact.emailAddresses();
    d->addresses = contact.addresses();
    d->urls = contact.urls();
}

CContact &CContact::operator=(const CContact &contact)
{
    Q_D(CContact);

    d->id = contact.id();
    d->displayLabel = contact.displayLabel();
    d->firstName = contact.firstName();
    d->lowerFirstName = contact.lowerFirstName();
    d->lastName = contact.lastName();
    d->lowerLastName = contact.lowerLastName();
    d->middleName = contact.middleName();
    d->organization = contact.organization();
    d->gender = contact.gender();
    d->avatar = contact.avatar();
    d->ringtone = contact.ringtone();
    d->syncTarget = contact.syncTarget();
    d->note = contact.note();
    d->pingyinName = contact.pingyinName();
    d->lowerPingyinName = contact.lowerPingyinName();
    d->t9Index = contact.t9Index();
    d->birthday = contact.birthday();
    d->created = contact.created();
    d->modified = contact.modified();
    d->mdmId = contact.mdmId();
    d->calendarId = contact.calendarId();
    d->isFavorite = contact.isFavorite();

    d->phoneNumbers = contact.phoneNumbers();
    d->emailAddresses = contact.emailAddresses();
    d->addresses = contact.addresses();
    d->urls = contact.urls();

    return *this;
}

void CContact::setid(uint id)
{
    Q_D(CContact);

    d->id = id;
}

// const 函数 必须要用 Q_D(const CContact)
// 如果不用，说明这个值是可以修改
// 注意 const CContactPrivate* d  和 CContactPrivate *const d 的区别
uint CContact::id() const
{    
    Q_D(const CContact);

    return d->id;
}

void CContact::setDisplayLabel(const QString &displayLabel)
{
    Q_D(CContact);

    d->displayLabel = displayLabel;
}

QString CContact::displayLabel() const
{
    Q_D(const CContact);

    return d->displayLabel;
}

void CContact::setFirstName(const QString &firstName)
{
    Q_D(CContact);

    d->firstName = firstName;
}

QString CContact::firstName() const
{
    Q_D(const CContact);

    return d->firstName;
}

void CContact::setLowerFirstName(const QString &lowerFirstName)
{
    Q_D(CContact);

    d->lowerFirstName = lowerFirstName;
}

QString CContact::lowerFirstName() const
{
    Q_D(const CContact);

    return d->lowerFirstName;
}

void CContact::setLastName(const QString &lastName)
{
    Q_D(CContact);

    d->lastName = lastName;
}

QString CContact::lastName() const
{
    Q_D(const CContact);

    return d->lastName;
}

void CContact::setLowerLastName(const QString &lowerLastName)
{
    Q_D(CContact);

    d->lowerLastName = lowerLastName;
}

QString CContact::lowerLastName() const
{
    Q_D(const CContact);

    return d->lowerLastName;
}

void CContact::setMiddleName(const QString &middleName)
{
    Q_D(CContact);

    d->middleName = middleName;
}

QString CContact::middleName() const
{
    Q_D(const CContact);

    return d->middleName;
}

void CContact::setOrganization(const QString &organization)
{
    Q_D(CContact);

    d->organization = organization;
}

QString CContact::organization() const
{
    Q_D(const CContact);

    return d->organization;
}

void CContact::setGender(const QString &gender)
{
    Q_D(CContact);

    d->gender = gender;
}

QString CContact::gender() const
{
    Q_D(const CContact);

    return d->gender;
}

void CContact::setAvatar(const QString &avatar)
{
    Q_D(CContact);

    d->avatar = avatar;
}

QString CContact::avatar() const
{
    Q_D(const CContact);

    return d->avatar;
}

void CContact::setRingtone(const QString &ringtone)
{
    Q_D(CContact);

    d->ringtone = ringtone;
}

QString CContact::ringtone() const
{
    Q_D(const CContact);

    return d->ringtone;
}

void CContact::setSyncTarget(const QString &syncTarget)
{
    Q_D(CContact);

    d->syncTarget = syncTarget;
}

QString CContact::syncTarget() const
{
    Q_D(const CContact);

    return d->syncTarget;
}

void CContact::setNote(const QString &note)
{
    Q_D(CContact);

    d->note = note;
}

QString CContact::note() const
{
    Q_D(const CContact);

    return d->note;
}

QString CContact::pingyinName() const
{
    Q_D(const CContact);

    return d->pingyinName;
}

QString CContact::lowerPingyinName() const
{
    Q_D(const CContact);

    return d->lowerPingyinName;
}

QString CContact::t9Index() const
{
    Q_D(const CContact);

    return d->t9Index;
}

void CContact::setBirthday(const QDateTime &birthday)
{
    Q_D(CContact);

    d->birthday = birthday;
}

QDateTime CContact::birthday() const
{
    Q_D(const CContact);

    return d->birthday;
}

QDateTime CContact::created() const
{
    Q_D(const CContact);

    return d->created;
}

QDateTime CContact::modified() const
{
    Q_D(const CContact);

    return d->modified;
}

uint CContact::mdmId() const
{
    Q_D(const CContact);

    return d->mdmId;
}

uint CContact::calendarId() const
{
    Q_D(const CContact);

    return d->calendarId;
}

bool CContact::setIsFavorite(bool isFavorite)
{
    Q_D(CContact);

    d->isFavorite = isFavorite;
}

bool CContact::isFavorite() const
{
    Q_D(const CContact);

    return d->isFavorite;
}

bool CContact::hasPhoneNumber() const
{
    Q_D(const CContact);

    return d->phoneNumbers.count() > 0;
}

bool CContact::hasEmailAddresses() const
{
    Q_D(const CContact);

    return d->emailAddresses.count() > 0;
}

bool CContact::hasUrls() const
{
    Q_D(const CContact);

    return d->urls.count() > 0;
}

bool CContact::hasAddresses() const
{
    Q_D(const CContact);

    return d->addresses.count() > 0;
}

void CContact::setPhoneNumbers(const QMap<QString, QString> &phoneNumbers)
{
    Q_D(CContact);

    d->phoneNumbers = phoneNumbers;
}

QMap<QString, QString> CContact::phoneNumbers() const
{
    Q_D(const CContact);

    return d->phoneNumbers;
}

void CContact::setEmailAddresses(const QMap<QString, QString> &emailAddresses)
{
    Q_D(CContact);

    d->emailAddresses = emailAddresses;
}

QMap<QString, QString> CContact::emailAddresses() const
{
    Q_D(const CContact);

    return d->emailAddresses;
}

void CContact::setAddresses(const QMap<QString, QString> &addresses)
{
    Q_D(CContact);

    d->addresses = addresses;
}

QMap<QString, QString> CContact::addresses() const
{
    Q_D(const CContact);

    return d->addresses;
}

void CContact::setUrls(const QMap<QString, QString> &urls)
{
    Q_D(CContact);

    d->urls = urls;
}

QMap<QString, QString> CContact::urls() const
{
    Q_D(const CContact);

    return d->urls;
}

void CContact::setPingyinName(const QString &pingyinName)
{
    Q_D(CContact);

    d->pingyinName = pingyinName;
}

void CContact::setLowerPingyinName(const QString &pingyinName)
{
    Q_D(CContact);

    d->lowerPingyinName = pingyinName;
}

void CContact::setT9Index(const QString &t9Index)
{
    Q_D(CContact);

    d->t9Index = t9Index;
}

void CContact::setCreated(const QDateTime &dateTime)
{
    Q_D(CContact);

    d->created = dateTime;
}

void CContact::setModified(const QDateTime &dateTime)
{
    Q_D(CContact);

    d->modified = dateTime;
}

void CContact::setMdmId(uint mdmId)
{
    Q_D(CContact);

    d->mdmId = mdmId;
}

void CContact::setCalendarId(uint calenderId)
{
    Q_D(CContact);

    d->calendarId = calenderId;
}

QDebug &operator<<(QDebug dbg, const CContact &contact)
{
    dbg.nospace()<<"CContact( id: "<<contact.id()<<" , ";
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


CContactPrivate::CContactPrivate()
{

}

CContactPrivate::~CContactPrivate()
{

}
