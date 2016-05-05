#ifndef STRINGUTILITY_H
#define STRINGUTILITY_H

#include "utility_global.h"
#include <QString>
#include <QStringList>
#include <QMap>
#include <qchar.h>

class UTILITYSHARED_EXPORT  stringUtility
{
public:
    stringUtility();

    /**
        打开要读的文件时，要直到文件的编码。以文件是gb18030的编码为例：
        在linux下，默认是以utf8 来的编码来读文件的，由于文件是gb18030，
        因此，读出来的是乱码。要想读出来是正确的，那么就通过一下代码设置：

        QTextStream out(&file);
        out.setCodec(QTextCodec::codecForName("gb18030"));
        a.txt(utf8: 我)  stra
        b.txt(gb18030: 我) strb
        如果以正确的编码读出来后，stra== strb 为true，否则为 false。
        txt保存时，可以选择编码ANSI和Unicode。尽量选择unicode，^M 这是windows的编码
     */
    static QStringList setCodecForReadFile(const QString &fileName, const QString &codec = QString(""));

    /**
     * @brief 把vcard 的每一条记录按字段读出来。返回一个字段的列表
     * @param record
     * @return
     */
    static QStringList dealVCardRecord(const QString& record);

    static void splitStringByWord(const QString& value, const QStringList& words, bool order = true);

    static QString& encode_quote_qprintable(const QByteArray &input);
    static QByteArray& decode_quote_qprintable(const QString& input);

    static void initPinyinMap();
    static QString getPinyinString(QString in);
    static QString convert(QString str);
    static QList<QChar> getAllContactNameGroups();
    static QChar getPinyinChar(QString in);
    static QString getNumFromPinyin(QString str);
    static QMap<int, QString> map;
    static bool isZh_CN(const char& in);
};

#endif // STRINGUTILITY_H
