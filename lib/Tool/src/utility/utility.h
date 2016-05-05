#ifndef UTILITY_H
#define UTILITY_H

#include "utility_global.h"
#include <QImage>

class UTILITYSHARED_EXPORT Utility
{

public:
    Utility();

    /**
      把QImage以format的格式放到QByteArray中，此时QByteArray里的内容都是二进制，
      再把QByteArray转成base64的QByteArray。
     */
    static QString stringByImage(const QImage& image, const char* format = 0);
    static QImage imageByString(const QString& text, const char* format = 0);

    static QByteArray base64ByImage(const QImage& image, const char* format = 0);
    static QImage imageByString(const QByteArray& ba, const char* format = 0);
    static void testImage(QString format = QString());

};

#endif // UTILITY_H
