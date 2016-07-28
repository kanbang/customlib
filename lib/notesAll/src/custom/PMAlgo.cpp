#include "PMAlgo.h"
#include <QString>
#include <QStringList>
#include <QRegExp>
#include <QDebug>

void CellphoneAlgo::matchNumber(const QString &number, bool& match, const QRegExp& exp, const QStringList& lists)
{
    match = false;
    QString simple = number.right(11);

    for(int i = 0; i< lists.count(); i++)
    {
        if(exp.exactMatch(lists.at(i)))
        {
            QString tmp = lists.at(i);
            if(simple == tmp.right(11))
            {
                match = true;
            }
        }
    }
}

void TelephoneAlgo::matchNumber(const QString &number, bool &match, const QRegExp& exp, const QStringList& lists)
{
    match = false;
    QString prefix = "^(17950)?(17951)?(\\+86)?(86)?";
    QRegExp tpExpThreeSix(prefix + "(0[12]\\d{1})?[1-9]\\d{6}$");
    QRegExp tpExpThreeSeven(prefix + "(0[12]\\d{1})?[1-9]\\d{7}$");
    QRegExp tpExpFourSix(prefix + "(0[3-9]\\d{2})?[1-9]\\d{6}$");
    QRegExp tpExpFourSeven(prefix + "(0[3-9]\\d{2})?[1-9]\\d{7}$");

    for(int i = 0; i< lists.count(); i++)
    {
        if(tpExpThreeSix.exactMatch(number) && tpExpThreeSix.exactMatch(lists.at(i)))
        {
            if(number.length() < 10)
            {
                if(number == lists.at(i).right(number.length()));
                {
                    match = true;
                }
            } else
            {
                if(number.right(10) == lists.at(i).right(10))
                {
                    match = true;
                }
            }
        }

        if(tpExpThreeSeven.exactMatch(number) && tpExpThreeSeven.exactMatch(lists.at(i)))
        {
            if(number.length() < 11)
            {
                if(number == lists.at(i).right(number.length()))
                {
                    match = true;
                }
            } else
            {
                if(number.right(11) == lists.at(i).right(11))
                {
                    match = true;
                }
            }
        }

        if(tpExpFourSix.exactMatch(number) && tpExpFourSix.exactMatch(lists.at(i)))
        {
            if(number.length() < 11)
            {
                if(number == lists.at(i).right(number.length()))
                {
                    match = true;
                }
            } else
            {
                if(number.right(11) == lists.at(i).right(11))
                {
                    match = true;
                }
            }
        }

        if(tpExpFourSeven.exactMatch(number) && tpExpFourSeven.exactMatch(lists.at(i)))
        {
            if(number.length() < 12)
            {
                if(number == lists.at(i).right(number.length()))
                {
                    match = true;
                }
            } else
            {
                if(number.right(12) == lists.at(i).right(12))
                {
                    match = true;
                }
            }
        }
    }
}

void FourZeroZeroPhoneAlgo::matchNumber(const QString &number, bool &match, const QRegExp& exp, const QStringList& lists)
{
    match = false;

    for(int i = 0; i<lists.count(); i++)
    {
        if(exp.exactMatch(lists.at(i)))
        {
            if(number.right(10) == lists.at(i).right(10))
            {
                match = true;
            }
        }
    }
}

void OneZeroPhoneAlgo::matchNumber(const QString &number, bool &match, const QRegExp& exp, const QStringList& lists)
{
    match = false;

    QRegExp ozExpZero("^(0[0-9]{2,3})?100\\d{2,5}$");
    QRegExp ozExpTwo("^(0[0-9]{2,3})?1[2]\\d{3}$");

    for(int i = 0; i< lists.count(); i++)
    {
        if(ozExpZero.exactMatch(number))
        {
            if(number.right(5) == lists.at(i).right(5))
            {
                match = true;
            }
        }

        if(ozExpTwo.exactMatch(number))
        {
            if(number.right(5) == lists.at(i).right(5))
            {
                match = true;
            }
        }
    }
}

void BankPhoneAlgo::matchNumber(const QString &number, bool &match, const QRegExp& exp, const QStringList& lists)
{
    match = false;

    // judge right(5)
    for(int i = 0; i <lists.count(); i++)
    {
        if(exp.exactMatch(lists.at(i)))
        {
            if(number.length() == 5)
            {
                if(lists.at(i).contains("+86"))
                {
                    QString tmp = lists.at(i);
                    tmp.replace("+86","");
                    if(number == tmp)
                    {
                        match = true;
                    }
                } else if(lists.at(i).left(2) == "86")
                {
                    QString tmp = lists.at(i);
                    tmp.replace("86","");
                    if(number == tmp)
                    {
                        match = true;
                    }
                } else
                {
                    if(number == lists.at(i))
                    {
                        match = true;
                    }
                }
            }
            else
            {
                if(lists.at(i).contains("+86"))
                {
                    QString num = number;
                    if(num.contains("+86"))
                    {
                        num.replace("+86","");
                    }
                    if(num.left(2) == "86")
                    {
                        num.replace("86","");
                    }
                    QString tmp = lists.at(i);
                    tmp.replace("+86","");
                    if(num == tmp)
                    {
                        match = true;
                    }
                }
                if(lists.at(i).left(2) == "86")
                {
                    QString num = number;
                    if(num.contains("+86"))
                    {
                        num.replace("+86","");
                    }
                    if(num.left(2) == "86")
                    {
                        num.replace("86","");
                    }
                    QString tmp = lists.at(i);
                    tmp.replace("86","");
                    if(num == tmp)
                    {
                        match = true;
                    }
                }
            }
        }
    }
}

void OneZeroSixPhoneAlgo::matchNumber(const QString &number, bool &match, const QRegExp& exp, const QStringList& lists)
{
    match = false;

    for(int i = 0; i<lists.count(); i++)
    {
        if(exp.exactMatch(lists.at(i)))
        {
            int dstLength = lists.at(i).length();
            int srcLength = number.length();
            if(srcLength == dstLength)
            {
                if(number == lists.at(i))
                {
                    match = true;
                }
            }
        }
    }
}

void PlusPhoneAlgo::matchNumber(const QString &number, bool &match, const QRegExp& exp, const QStringList& lists)
{
    match = false;

    for(int i = 0; i< lists.count(); i++)
    {
        if(exp.exactMatch(lists.at(i)))
        {
            if(number.contains("+"))
            {
                if(number.right(number.length()-1) == lists.at(i).right(number.length()-1) &&
                        abs(number.length()-lists.at(i).length()) <=1)
                {
                    match = true;
                }
            } else
            {
                if(number.right(number.length()-2) == lists.at(i).right(number.length()-2)&&
                        abs(number.length()-lists.at(i).length()) <=1)
                {
                    match = true;
                }
            }
        }
    }
}

void MatchAlgo::matchNumber(const QString &number, bool &match, const QRegExp& exp, const QStringList& lists)
{
    match = false;

    if(number.isEmpty())
    {
        match = false;
        return;
    }

    for(int i = 0; i< lists.count(); i++)
    {
        if(number == lists.at(i))
        {
            match = true;
        }
    }
}
