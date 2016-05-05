#ifndef PMALGO_H
#define PMALGO_H

#include <QRegExp>
#include <QStringList>


class IPhoneAlgo
{
public:
    virtual void matchNumber(const QString& number, bool& match, const QRegExp& exp, const QStringList& lists) = 0;
};

class CellphoneAlgo : public IPhoneAlgo
{
public:
    virtual void matchNumber(const QString& number, bool& match, const QRegExp& exp, const QStringList& lists);
};

class TelephoneAlgo : public IPhoneAlgo
{
public:
    virtual void matchNumber(const QString& number, bool& match, const QRegExp& exp, const QStringList& lists);
};

class BankPhoneAlgo : public IPhoneAlgo
{
public:
    virtual void matchNumber(const QString& number, bool& match, const QRegExp& exp, const QStringList& lists);
};

class FourZeroZeroPhoneAlgo : public IPhoneAlgo
{
public:
    virtual void matchNumber(const QString& number, bool& match, const QRegExp& exp, const QStringList& lists);
};

class OneZeroPhoneAlgo : public IPhoneAlgo
{
public:
    virtual void matchNumber(const QString& number, bool& match, const QRegExp& exp, const QStringList& lists);
};

class OneZeroSixPhoneAlgo : public IPhoneAlgo
{
public:
    virtual void matchNumber(const QString &number, bool &match, const QRegExp& exp, const QStringList& lists);
};

class PlusPhoneAlgo : public IPhoneAlgo
{
public:
    virtual void matchNumber(const QString &number, bool &match, const QRegExp& exp, const QStringList& lists);
};

class MatchAlgo : public IPhoneAlgo
{
public:
    virtual void matchNumber(const QString &number, bool &match, const QRegExp& exp, const QStringList& lists);
};

#endif // PMALGO_H
