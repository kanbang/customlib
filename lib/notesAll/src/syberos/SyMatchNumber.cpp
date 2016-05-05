#include "SyMatchNumber.h"
#include<QDebug>

SyMatchNumber::SyMatchNumber()
{
}

QString AbstractRegExp::pattern()
{
    if(m_pExp)
    {
        return m_sPattern + m_pExp->pattern();
    }
    else
    {
        return m_sPattern;
    }
}

AbstractRegExp::AbstractRegExp(AbstractRegExp *exp, const QString &pattern)
    :m_pExp(exp),
      m_sPattern("(" + pattern + ")")
{
}

AbstractRegExp::~AbstractRegExp()
{
}

void AbstractRegExp::setExpress(const QString &pattern)
{
    m_sPattern = pattern;
}

SyPrefixIPRegExp::SyPrefixIPRegExp(AbstractRegExp* exp, const QString& pattern) : AbstractRegExp(exp, pattern)
{
    m_sMatch = QString("^%1%2").arg(m_sPattern).arg(m_pExp->pattern());
    m_rReg.setPattern(m_sMatch);
}

SyType SyPrefixIPRegExp::type()
{
    if(m_pExp)
    {
        return m_pExp->type();
    }
    else
    {
        return syNone;
    }
}

bool SyPrefixIPRegExp::exactMatch(const QString &number)
{
    return m_rReg.exactMatch(number);
}

SyCellphoneRegExp::SyCellphoneRegExp()
    :AbstractRegExp(NULL, "")
{
    m_sPattern = QString("?(\\+86)?(86)?1[358]\\d{9}$");
}

SyCellphoneRegExp::~SyCellphoneRegExp()
{
}

bool SyCellphoneRegExp::exactMatch(const QString &number)
{
    return false;
}
