#include "EPSyberosAlgo.h"
#include <QRegExp>
#include <QLineEdit>
#include <QDebug>
#include <QRegExpValidator>
#include <QWidget>
#include <QHBoxLayout>
#include <EPSqlite.h>
#include <iostream>
#include <QDialog>
using namespace std;

EPSyberosAlgo::EPSyberosAlgo()
{
}

void EPSyberosAlgo::matchPhoneNumber(const QString &number)
{
    //
    /**
    在Qt 中的正则表达式， \\d 是整数的意思

    匹配一个数值
    QRegExp exp("^[1-9]\d*");

    匹配11位数字，必须是11位
    QRegExp exp("\\d{11}");

    要匹配+ ， 则QRegExp exp("\\+");
    */
    QWidget* widget = new QDialog();
    QLayout *layout = new QHBoxLayout(widget);
    QMap<phoneType, QRegExp> exps;
    exps[opCellPhone] = QRegExp();
    QLineEdit *lineEdit = new NumberEdit(widget);
    layout->addWidget(lineEdit);
/**    QRegExp exp("^((\(\\d{3}\))|(\\d{3}\-))?13[0-9]\\d{8}|15[89]\\d{8}");

    QRegExp exp("\(17951\)|\(\+86\)|\(86\)?\\d{11}");
    QRegExp exp("^((17951)|(\\+86)|(86))?1[358]\\d{9}$");

    QRegExp telephoneExp("^((17951)?(0[0-9]{2}))?[2-9]\\d{6,7}$");
    QRegExp fourZeroZeroExp("^400\\d{7}$");
    QRegExp oneZero("^10\\d{1,3}$");
    QRegExp bankExp("^9\\d{4}$");
    qDebug()<<__PRETTY_FUNCTION__<<exp.exactMatch("1795113120077642");
    qDebug()<<"telephone "<< telephoneExp.exactMatch("17951089862507634");
    qDebug()<<"400 "<< fourZeroZeroExp.exactMatch("4006789000");
    qDebug()<<"10 "<< oneZero.exactMatch("10086");
    qDebug()<<"95588 "<< bankExp.exactMatch("95588");
    QRegExpValidator *validator = new QRegExpValidator(exp);
    lineEdit->setValidator(validator);*/
    widget->setLayout(layout);
    widget->resize(400,250);

    EPSqlite::readFile();
    widget->show();
}

/**
    中国移动：
    2G号段：134、135、136、137、138、139、150、151、152、157、158、159； 3G号段：157、187、188；

    中国联通：
    2G号段：130、131、132、155、156； 3G号段：185、186；

    中国电信：
    2G号段：133、153； 3G号段：180、189
  */
void EPSyberosAlgo::matchNumber(const QString &number)
{
    EPSqlite::readFile();
    QMap<phoneType, QRegExp> regExpMaps;
    QMap<phoneType, IPhoneAlgo*> algos;
    regExpMaps.clear();
    algos.clear();

    QString prefix = "^(17900)?(17901)?(17908)?(17909)?(17910)?(17911)?(17950)?(17951)?(\\+86)?(86)?";
    QString cell = prefix + "(0086)?" + "1[4358]\\d{9}$";
    QRegExp cellphoneExp(cell);

    QString tele = prefix + "(0[1-9]\\d{1,2})?[1-9]\\d{6,7}$";
    QRegExp telephoneExp(tele);

    QRegExp bankExp(prefix + "(0[1-9]\\d{1,2})?9[56]\\d{3}$");
    // 考虑一种情况，400电话会不会加区号
    QRegExp fourZeroZeroExp(prefix + "(0|(0[1-9]\\d{1,2}))?400\\d{7}$");
    QRegExp oneZeroExp(prefix + "(0[1-9]\\d{1,2})?1[02]\\d{3}$");
    QRegExp oneZeroSixExp("^106\\d{5,12}$");
    QRegExp plusExp("^((\\+00)|(\\+)|(00))[^8][^6][1-9]\\d{2,3})?\\d{4,10}$");
    QRegExp sixExp("^0?\\d{6}$");

    regExpMaps[opCellPhone] = cellphoneExp;
    algos[opCellPhone] = new CellphoneAlgo();

    regExpMaps[opTelePhone] = telephoneExp;
    algos[opTelePhone] = new TelephoneAlgo();

    regExpMaps[opBankPhone] = bankExp;
    algos[opBankPhone] = new BankPhoneAlgo();

    regExpMaps[op400Phone] = fourZeroZeroExp;
    algos[op400Phone] = new FourZeroZeroPhoneAlgo();

    regExpMaps[op10Phone] = oneZeroExp;
    algos[op10Phone] = new OneZeroPhoneAlgo();

    regExpMaps[op106Phone] = oneZeroSixExp;
    algos[op106Phone] = new OneZeroSixPhoneAlgo();

    regExpMaps[opPlusPhone] = plusExp;
    algos[opPlusPhone] = new PlusPhoneAlgo();

    regExpMaps[opSixPhone] = sixExp;
    algos[opSixPhone] = new SixPhoneAlgo();

    phoneType type = opNone;
    bool bMatch = false;
    for(int i = 0; i < regExpMaps.count(); i++)
    {
        if(regExpMaps.value((phoneType)(i)).exactMatch(number))
        {
            type = (phoneType)(i);
            if(number.length() >= 10)
            {
                if(number.right(10).left(3) == "400")
                {
                    if(type == opTelePhone)
                    {

                    }
                }
            }
            qDebug()<<"happen "<< type;
            bMatch = true;
        }
    }

    int count = 0;
    QStringList strs;
    QStringList rests;
    for(int i =0; i< EPSqlite::_numDBs.count(); i++)
    {
        int refs = 0;
        bool isMatch = false;
        for(int j = 0; j < regExpMaps.count(); j++)
        {
            if(regExpMaps.value((phoneType)(j)).exactMatch(EPSqlite::_numDBs.at(i)))
            {
                refs++;
                count++;
                isMatch = true;
            }
        }

        if(refs > 1)
        {
            strs.append(EPSqlite::_numDBs.at(i));
        }
        if(!isMatch)
        {
            rests.append(EPSqlite::_numDBs.at(i));
        }
    }
    qDebug()<<__PRETTY_FUNCTION__<<EPSqlite::_numDBs.count()<< "   "<< count;

//    qDebug()<<strs << strs.count();
//    qDebug()<<"ddd   "<<rests << rests.count();
    if(!bMatch)
    {
        qDebug()<<__PRETTY_FUNCTION__<<" number Vaild";
    } else
    {
        bool match = false;
        algos.value(type)->matchNumber(number, match, regExpMaps.value(type));

        qDebug()<<__PRETTY_FUNCTION__<<"bMatch = "<<bMatch <<" match = "<<match << "  " <<type;
    }
}

void EPSyberosAlgo::testRegExp()
{
    QRegExp exp("^(0[1-9]\\d{1,2})?[^4][^0]{2}\\d{4,5}");
    qDebug()<<__PRETTY_FUNCTION__<<exp.exactMatch("0104004831");
}

void CellphoneAlgo::matchNumber(const QString &number, bool& match, const QRegExp& exp)
{
    match = false;
    QString simple = number.right(11);
    qDebug()<<__PRETTY_FUNCTION__<< simple;
    const QStringList &lists = EPSqlite::_numDBs;
    for(int i = 0; i< lists.count(); i++)
    {
//        if(lists.at(i).right(11) == "15120077642")
//            qDebug()<<"dksa;dfjda"<< lists.at(i);
        if(exp.exactMatch(lists.at(i)))
        {
            QString tmp = lists.at(i);

//            qDebug()<<"xindlf"<< tmp;

            if(simple == tmp)
            {
                match = true;
                qDebug()<<__PRETTY_FUNCTION__<<number.right(11);
            }
        }
    }
}

void TelephoneAlgo::matchNumber(const QString &number, bool &match, const QRegExp& exp)
{
    match = false;
    QString prefix = "^(17950)?(17951)?(\\+86)?(86)?";
    // 匹配固定电话 ，区号为01x， 02x的
//    QRegExp tpExpThree("^((17951)?(0[0-9]{2}))?[1-9]\\d{6,7}$");
    // 电话号码是7位的
    QRegExp tpExpThreeSix(prefix + "(0[12]\\d{1})?[1-9]\\d{6}$");
    // 电话号码是8位的
    QRegExp tpExpThreeSeven(prefix + "(0[12]\\d{1})?[1-9]\\d{7}$");

    // 匹配固定电话 ，区号为03xx， 09xx的
//    QRegExp tpExpFour("^((17951)?(0[0-9]{3}))?[1-9]\\d{6,7}$");
    // 电话号码是7位的
    QRegExp tpExpFourSix(prefix + "(0[3-9]\\d{2})?[1-9]\\d{6}$");
    // 电话号码是8位的
    QRegExp tpExpFourSeven(prefix + "(0[3-9]\\d{2})?[1-9]\\d{7}$");

    const QStringList &lists = EPSqlite::_numDBs;

    qDebug()<<tpExpThreeSix.exactMatch(number);
    qDebug()<<tpExpThreeSeven.exactMatch(number);
    qDebug()<<tpExpFourSix.exactMatch(number);
    qDebug()<<tpExpFourSeven.exactMatch(number);
    for(int i = 0; i< lists.count(); i++)
    {
        if(tpExpThreeSix.exactMatch(number) && tpExpThreeSix.exactMatch(lists.at(i)))
        {
            if(number.length() < 10)
            {
                if(number == lists.at(i))
                {
                    match = true;
                    qDebug()<< number.length() <<__PRETTY_FUNCTION__<<number;
                }
            } else
            {
                if(number.right(10) == lists.at(i).right(10))
                {
                    match = true;
                    qDebug()<< 10 <<__PRETTY_FUNCTION__<<number;
                }
            }
        }

        if(tpExpThreeSeven.exactMatch(number) && tpExpThreeSeven.exactMatch(lists.at(i)))
        {
            if(number.length() < 11)
            {
                if(number == lists.at(i))
                {
                    match = true;
                    qDebug()<< number.length() <<__PRETTY_FUNCTION__<<number;
                }
            } else
            {
                if(number.right(11) == lists.at(i).right(11))
                {
                    match = true;
                    qDebug()<< 11 <<__PRETTY_FUNCTION__<<number;
                }
            }
        }

        if(tpExpFourSix.exactMatch(number) && tpExpFourSix.exactMatch(lists.at(i)))
        {
            if(number.length() < 11)
            {
                if(number == lists.at(i))
                {
                    match = true;
                    qDebug()<< number.length() <<__PRETTY_FUNCTION__<<number;
                }
            } else
            {
                if(number.right(11) == lists.at(i).right(11))
                {
                    match = true;
                    qDebug()<< "tpExpFourSix" <<__PRETTY_FUNCTION__<<number;
                }
            }
        }

        if(tpExpFourSeven.exactMatch(number) && tpExpFourSeven.exactMatch(lists.at(i)))
        {
            if(number.length() < 12)
            {
                if(number == lists.at(i))
                {
                    match = true;
                    qDebug()<< number.length() <<__PRETTY_FUNCTION__<<number;
                }
            } else
            {
                if(number.right(12) == lists.at(i).right(12))
                {
                    match = true;
                    qDebug()<< "tpExpFourSeven" <<__PRETTY_FUNCTION__<<number;
                }
            }
        }
    }
}

void FourZeroZeroPhoneAlgo::matchNumber(const QString &number, bool &match, const QRegExp& exp)
{
    match = false;

    const QStringList &lists = EPSqlite::_numDBs;

    for(int i = 0; i<lists.count(); i++)
    {
        if(exp.exactMatch(lists.at(i)))
        {
            if(number.length() == 10)
            {

            }
            if(number.right(10) == lists.at(i).right(10))
            {
                match = true;
                qDebug()<<__PRETTY_FUNCTION__<<number.right(10);
            }
        }
    }
}

void OneZeroPhoneAlgo::matchNumber(const QString &number, bool &match, const QRegExp &exp)
{
    match = false;

    QRegExp ozExpZero("^(0[0-9]{2,3})?100\\d{2,5}$");
    QRegExp ozExpTwo("^(0[0-9]{2,3})?1[2]\\d{3}$");

    const QStringList &lists = EPSqlite::_numDBs;

    for(int i = 0; i< lists.count(); i++)
    {
        if(ozExpZero.exactMatch(number))
        {
            if(number.right(5) == lists.at(i).right(5))
            {
                match = true;
                qDebug()<<__PRETTY_FUNCTION__<<number.right(5);
            }
        }

        if(ozExpTwo.exactMatch(number))
        {
            if(number.right(5) == lists.at(i).right(5))
            {
                match = true;
                qDebug()<<__PRETTY_FUNCTION__<<number.right(5);
            }
        }
    }
}

void BankPhoneAlgo::matchNumber(const QString &number, bool &match, const QRegExp &exp)
{
    match = false;

    const QStringList &lists = EPSqlite::_numDBs;

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
                        qDebug()<<__PRETTY_FUNCTION__<<number<< lists.at(i);
                    }
                } else if(lists.at(i).left(2) == "86")
                {
                    QString tmp = lists.at(i);
                    tmp.replace("86","");
                    if(number == tmp)
                    {
                        match = true;
                        qDebug()<<__PRETTY_FUNCTION__<<number<< lists.at(i);
                    }
                } else
                {
                    if(number == lists.at(i))
                    {
                        match = true;
                        qDebug()<<__PRETTY_FUNCTION__<<number<< lists.at(i);
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
                        qDebug()<<__PRETTY_FUNCTION__<<number<< lists.at(i);
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
                        qDebug()<<__PRETTY_FUNCTION__<<number<< lists.at(i);
                    }
                }
            }
        }
    }
}

void OneZeroSixPhoneAlgo::matchNumber(const QString &number, bool &match, const QRegExp &exp)
{
    match = false;

    const QStringList &lists = EPSqlite::_numDBs;

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
                    qDebug()<<__PRETTY_FUNCTION__<<number;
                }
            }
        }
    }
}

void PlusPhoneAlgo::matchNumber(const QString &number, bool &match, const QRegExp &exp)
{
    match = false;

    const QStringList &lists = EPSqlite::_numDBs;

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
                    qDebug()<<__PRETTY_FUNCTION__<<number;
                }
            } else
            {
                if(number.right(number.length()-2) == lists.at(i).right(number.length()-2)&&
                        abs(number.length()-lists.at(i).length()) <=1)
                {
                    match = true;
                    qDebug()<<__PRETTY_FUNCTION__<<number;
                }
            }
        }
    }
}

NumberEdit::NumberEdit(QWidget *parent) :
    QLineEdit(parent)
{

    connect(this,SIGNAL(returnPressed()), this, SLOT(matchNumber()));
}

void NumberEdit::matchNumber()
{
    EPSyberosAlgo::matchNumber(this->text());
}

void SixPhoneAlgo::matchNumber(const QString &number, bool &match, const QRegExp &exp)
{
    match = false;

    const QStringList &lists = EPSqlite::_numDBs;
    for(int i = 0; i < lists.count(); i++)
    {
        if(exp.exactMatch(lists.at(i)))
        {
            if(number == lists.at(i).right(number.length()))
            {
                match = true;
                qDebug()<<__PRETTY_FUNCTION__<<number;
            }
        }
    }
}

