#ifndef EPDATATEXTSTREAM_H
#define EPDATATEXTSTREAM_H

#include <QDataStream>
#include <QTextStream>

class QString;

enum style {

};

class AbstractStream
{
public:
    virtual ~AbstractStream();

    virtual void InputDataText(QDataStream &ds) = 0;
    virtual void InputDataText(QTextStream &ts) = 0;
    virtual void OutputDataText(QDataStream &ds) = 0;
    virtual void OutputDataText(QTextStream &ts) = 0;

    void Input(QDataStream &ds);
    void Input(QTextStream &ds);
    void Output(QDataStream &ds);
    void Output(QTextStream &ds);
protected:
    AbstractStream();
};

class InStream : public AbstractStream
{
public:
    InStream();
    ~InStream()
    {}

    virtual void InputDataText(QDataStream &ds);
    virtual void InputDataText(QTextStream &ts);
    virtual void OutputDataText(QDataStream &ds);
    virtual void OutputDataText(QTextStream &ds);
};

class EPStream
{
public:
    EPStream();

    void setDsFileName(QString dsFileName);
    void setTsFileName(QString tsFileName);
    void setConcreteStream(AbstractStream *as);

//    void setStream(QDataStream &ds); 流的赋值是私有的。不能复制
//    void setStream(QTextStream &ts);

    void operationDs();
    void operationTs();
private:
    QString m_dsFileName,m_tsFileName;
    AbstractStream *m_as;
};

#endif // EPDATATEXTSTREAM_H
