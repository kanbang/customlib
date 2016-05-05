#include "utility.h"
#include <QtGui>

Utility::Utility()
{
}

QString Utility::stringByImage(const QImage &image, const char *format)
{
    QByteArray ba = base64ByImage(image, format);
    QString text = QString(ba.constData());
    qDebug()<<text;

    return text;
}

QImage Utility::imageByString(const QString &text, const char *format)
{
    QByteArray ba(text.toStdString().c_str());
    //从base64转为二进制
    return imageByString(ba.fromBase64(ba), format);
}

QByteArray Utility::base64ByImage(const QImage &image, const char *format)
{
    QByteArray ba;
    QBuffer buffer(&ba);
    buffer.open(QIODevice::WriteOnly);
    image.save(&buffer, format); // writes image into ba in PNG format
    return ba.toBase64(); // 二进制转为字符串的形式
}

//ba.fromBase64(ba)


QImage Utility::imageByString(const QByteArray &ba, const char *format)
{
    QImage image;
    image.loadFromData(ba, format);
    return image;
}

void Utility::testImage(QString format)
{
    QImage image("one.png");
    if(image.isNull())
    {
        qDebug()<<"one.png is not exist in "<<QDir::currentPath();
        return;
    }
    if(format.isEmpty())
        format = "PNG";
    QByteArray ba = base64ByImage(image, format.toStdString().c_str());
    QFile file("one.txt");
    file.open(QIODevice::WriteOnly);
    QTextStream out(&file);
    out<<ba;
    file.close();

    QFile readFile("one.txt");
    readFile.open(QIODevice::ReadOnly);
    QTextStream in(&readFile);
    QString text;
    in>>text;
    QByteArray loadByte(text.toStdString().c_str());
    QImage readFromFile = imageByString(loadByte, format.toStdString().c_str());
    readFromFile.save("readFromFile.png",format.toStdString().c_str());
}
