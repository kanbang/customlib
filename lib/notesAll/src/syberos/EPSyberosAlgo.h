#ifndef EPSYBEROSALGO_H
#define EPSYBEROSALGO_H
#include <QString>
#include <QLineEdit>

enum phoneType{
    opNone,
    opCellPhone,        // 手机
    opTelePhone,        // 固定电话
    opBankPhone,        // 服务电话 95588
    op400Phone,         // 400电话
    op10Phone,          // 10086
    op106Phone,         // 106 d的电话
    opPlusPhone,        // 6为的电话号码
    opSixPhone
};

class IPhoneAlgo
{
public:
    virtual void matchNumber(const QString& number, bool& match, const QRegExp& exp) = 0;
};

class CellphoneAlgo : public IPhoneAlgo
{
public:
    virtual void matchNumber(const QString& number, bool& match, const QRegExp& exp);
};

class TelephoneAlgo : public IPhoneAlgo
{
public:
    virtual void matchNumber(const QString& number, bool& match, const QRegExp& exp);
};

class BankPhoneAlgo : public IPhoneAlgo
{
public:
    virtual void matchNumber(const QString& number, bool& match, const QRegExp& exp);
};

class FourZeroZeroPhoneAlgo : public IPhoneAlgo
{
public:
    virtual void matchNumber(const QString& number, bool& match, const QRegExp& exp);
};

class OneZeroPhoneAlgo : public IPhoneAlgo
{
public:
    virtual void matchNumber(const QString& number, bool& match, const QRegExp& exp);
};

class OneZeroSixPhoneAlgo : public IPhoneAlgo
{
public:
    virtual void matchNumber(const QString &number, bool &match, const QRegExp& exp);
};

class PlusPhoneAlgo : public IPhoneAlgo
{
public:
    virtual void matchNumber(const QString &number, bool &match, const QRegExp& exp);
};

class SixPhoneAlgo : public IPhoneAlgo
{
public:
    virtual void matchNumber(const QString &number, bool &match, const QRegExp &exp);
};

class NumberEdit : public QLineEdit
{
    Q_OBJECT

public:
    NumberEdit(QWidget* parent = 0);

public slots:
    void matchNumber();

};

class EPSyberosAlgo
{
public:
    EPSyberosAlgo();

    /**
    电话号码匹配功能
      */
    static void matchPhoneNumber(const QString &number = QString());
    static void matchNumber(const QString& number = QString());
    static void testRegExp();
};

#endif // EPSYBEROSALGO_H
