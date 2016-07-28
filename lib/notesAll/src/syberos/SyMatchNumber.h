#ifndef SYMATCHNUMBER_H
#define SYMATCHNUMBER_H

#include <QList>
#include <QString>
#include <QRegExp>

// 前缀的
enum SyType
{
    syNone,
    syIp,       // 17951 类似的
    syNation,   // 国外的前缀 + 、00
    syChina,     // +86，区号
    syCell,
    syTele
};

class SyMatchNumber
{
public:
    SyMatchNumber();
};

class AbstractRegExp
{

public:
    virtual SyType type() { return syNone; }
    virtual QString pattern();

    virtual bool exactMatch(const QString& number) = 0;

protected:
    AbstractRegExp* m_pExp;

    AbstractRegExp(AbstractRegExp* exp, const QString& pattern = QString());
    ~AbstractRegExp();

    void setExpress(const QString& express);

    QString m_sPattern;
    QRegExp m_rReg;
};

class SyCellphoneRegExp : public AbstractRegExp
{
public:
    SyCellphoneRegExp();
    ~SyCellphoneRegExp();

    SyType type() { return syCell; }

    bool exactMatch(const QString &number);
};

class SyTelephoneRegExp : public AbstractRegExp
{
public:
    SyTelephoneRegExp();
    ~SyTelephoneRegExp();

    SyType tyep() { return syTele; }

    bool exactMatch(const QString &number);
};

// IP 拨号前缀
class SyPrefixIPRegExp : public AbstractRegExp
{
public:
    SyPrefixIPRegExp(AbstractRegExp *exp, const QString &pattern);
    ~SyPrefixIPRegExp();

    SyType type();

    virtual bool exactMatch(const QString &number);

private:
    QString m_sMatch;
};

class SyPrefixNationRegExp : public AbstractRegExp
{
public:
    SyPrefixNationRegExp(const QString& express);
    ~SyPrefixNationRegExp();

    SyType type() { return syNation; }

    bool exactMatch(const QString &number);
};

#endif // SYMATCHNUMBER_H
