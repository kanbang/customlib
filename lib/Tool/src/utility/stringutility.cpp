#include "stringutility.h"
#include <QFile>
#include <QString>
#include <QDebug>
#include <QTextStream>
#include <QTextCodec>
#include <QChar>

QMap<int, QString> stringUtility::map;
stringUtility::stringUtility()
{
}

QStringList stringUtility::setCodecForReadFile(const QString& fileName, const QString& codec)
{
    QStringList texts;
    QFile file(fileName);
    if(!file.open(QIODevice::ReadOnly))
    {
            qDebug()<<"Can not open the "<<fileName<<" file !";
            return texts;
    }
    texts.clear();
    QTextStream out(&file);
    if(codec.isEmpty())
    {
        QTextCodec::codecForLocale()->name();
        out.setCodec(QTextCodec::codecForLocale());
    }
    else
    {
        QTextCodec *textCodec = QTextCodec::codecForName(codec.toStdString().c_str());
        out.setCodec(textCodec);
    }

    while(!out.atEnd())
    {
        QString str = out.readLine();
        /**
            QString str = "  lots\t of\nwhitespace\r\n ";
            str = str.simplified();
            // str == "lots of whitespace";
          */
        //去掉转移字符
        str = str.simplified();
        if(!str.isEmpty())
            texts.append(str);
    }
    return texts;
}

QStringList stringUtility::dealVCardRecord(const QString &record)
{
    QStringList fields;
    QString tmp;
    for(int i = 0; i<record.count(); i++)
    {
        QString s = record.mid(i,1);
        if(s == ";" || s == ":")
        {
            fields.append(tmp);
            fields.append(s);
            tmp.clear();
        }
        else
        {
            tmp.append(record[i]);
        }
    }

    fields.append(tmp);
    return fields;
}

void stringUtility::splitStringByWord(const QString &value, const QStringList& words, bool order)
{
    QStringList keys;
    QStringList values;

    QString s;
    int index = -2;
    for(int i = 0; i<value.count(); i++)
    {
        QString word = value.mid(i,1);
        if(words.contains(word))
        {
            if(order)
            {
                keys.prepend(word);
                if(i - index == 1)
                {
                    values.prepend("");
                }
                index = i;
                if(s.length() > 0)
                {
                    values.prepend(s);
                }
                s.clear();
            }
            else
            {
                keys.append(word);
                if(i - index == 1)
                {
                    values.append("");
                }
                index = i;
                if(s.length() > 0)
                {
                    values.append(s);
                }
                s.clear();
            }
        }
        else
        {
            s +=word;
        }
    }
    if(keys.length() - values.count() == 1)
    {
        if(order)
        {
            values.prepend(s);
        }
        else
        {
            values.append(s);
        }
    }

    qDebug()<<"keys==="<<keys;
    qDebug()<<"values ==="<<values;
}

QString &stringUtility::encode_quote_qprintable(const QByteArray &input)
{
    QString *output = new QString();

    char byte;
    const char hex[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

    for (int i = 0; i < input.length() ; ++i)
    {
        byte = input[i];

        if ((byte == 0x20) || (byte >= 33) && (byte <= 126) && (byte != 61))
        {
            output->append(byte);
        }
        else
        {
            output->append('=');
            output->append(hex[((byte >> 4) & 0x0F)]);
            output->append(hex[(byte & 0x0F)]);
        }
    }

    return *output;
}

QByteArray &stringUtility::decode_quote_qprintable(const QString &input)
{
    // 0 1 2 3 4 5 6 7 8 9 : ; < = > ? @ A B C D E F
    const int hexVal[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 0, 0, 0, 0, 0, 0, 10, 11, 12, 13, 14, 15};

    QByteArray *output = new QByteArray();

    for (int i = 0; i < input.length(); ++i)
    {
        if (input.at(i).toLatin1() == '=')
        {
            output->append((hexVal[input.at(++i).toLatin1() - '0'] << 4) + hexVal[input.at(++i).toLatin1() - '0']);
        }
        else
        {
            output->append(input.at(i).toLatin1());
        }
    }

    return *output;
}

void stringUtility::initPinyinMap()
{
    QFile file("/home/xkd/unicode_to_hanyu_pinyin.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;
    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        bool ok;
        map.insert(line.split(" ").at(0).toInt(&ok,16),line.split(" ").at(1));
    }
}

QString stringUtility::getPinyinString(QString in)
{
    QString str = in;
    QChar *data = str.data();
    ushort findkey =data->unicode();
    //qDebug()<<findkey<<data->unicode();
    QMap<int,QString>::const_iterator i = map.find(findkey);
    while (i != map.end() && i.key() == findkey) {

        if(i.key()==findkey){
            QString ret = i.value();
            ret = ret.replace(QRegExp("[0-9|\(\\)]"),"");
            if(ret.contains(",")) {
                ret=ret.split(",").at(0);
            }
            return ret;
        }
        ++i;
    }
    return "";
}

QString stringUtility::convert(QString str)
{
    QString result ="";
    result = getPinyinString(str);
    if(result==""){
        result = QString(str).toUpper();
    }
    if(result.toUpper().at(0).isLetter()||result.toUpper().at(0).isSymbol()){
        return result.toUpper();
    }
    else {
        return "#";
    }
}

QList<QChar> stringUtility::getAllContactNameGroups()
{
    QList<QChar> groups;
    groups << QLatin1Char('A')
           << QLatin1Char('B')
           << QLatin1Char('C')
           << QLatin1Char('D')
           << QLatin1Char('E')
           << QLatin1Char('F')
           << QLatin1Char('G')
           << QLatin1Char('H')
           << QLatin1Char('I')
           << QLatin1Char('J')
           << QLatin1Char('K')
           << QLatin1Char('L')
           << QLatin1Char('M')
           << QLatin1Char('N')
           << QLatin1Char('O')
           << QLatin1Char('P')
           << QLatin1Char('Q')
           << QLatin1Char('R')
           << QLatin1Char('S')
           << QLatin1Char('T')
           << QLatin1Char('U')
           << QLatin1Char('V')
           << QLatin1Char('W')
           << QLatin1Char('X')
           << QLatin1Char('Y')
           << QLatin1Char('Z')
           << QChar(0x00c5)     // Å
           << QChar(0x00c4)     // Ä
           << QChar(0x00d6)     // Ö
           << QLatin1Char('#');
    return groups;
}

QChar stringUtility::getPinyinChar(QString in)
{
    if(in.isNull()||in=="")
        return QChar('#');
    QString out = getPinyinString(in);
    if(out == ""){
        if(in.at(0).isLetter())
            return in.at(0).toUpper();
        else
            return QChar('#');
    }
    return out.at(0).toUpper();
}

QString stringUtility::getNumFromPinyin(QString str)
{
    // TODO Auto-generated method stub
    QString returnNumber = "";
    for(int i=0; i<str.length();i++){
        int num = str.toLocal8Bit().at(i);
        switch (num) {
        case 'A':
        case 'B':
        case 'C':
            returnNumber.append('2');
            break;
        case 'D':
        case 'E':
        case 'F':
            returnNumber.append('3');
            break;
        case 'G':
        case 'H':
        case 'I':
            returnNumber.append('4');
            break;
        case 'J':
        case 'K':
        case 'L':
            returnNumber.append('5');
            break;
        case 'M':
        case 'N':
        case 'O':
            returnNumber.append('6');
            break;
        case 'P':
        case 'Q':
        case 'R':
        case 'S':
            returnNumber.append('7');
            break;
        case 'T':
        case 'U':
        case 'V':
            returnNumber.append('8');
            break;
        case 'W':
        case 'X':
        case 'Y':
        case 'Z':
            returnNumber.append('9');
            break;
        default:
            returnNumber.append("");
            break;
        }
    }
    return returnNumber;
}


