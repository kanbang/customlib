/*
* This file is part of Notification
*
* Copyright (C) 2014 Beijing Yuan Xin Technology Co.,Ltd. All rights reserved.
*
* Authors:
*       wangrui <wangrui@syberos.com>
*
* This software, including documentation, is protected by copyright controlled
* by Beijing Yuan Xin Technology Co.,Ltd. All rights are reserved.
*/

#ifndef CNOTIFICATIONTYPES_H
#define CNOTIFICATIONTYPES_H

#include <QtCore/QMap>
#include <QtCore/QList>
#include <QtCore/QString>
#include <QtCore/QMetaType>
#include <QtDBus/QtDBus>
#include <QtDBus/QDBusObjectPath>
#include <QtDBus>

class MyType
{
public:
    MyType();

    QString key;
    QString value;
};
Q_DECLARE_METATYPE(MyType)

QDBusArgument &operator<<(QDBusArgument &argument, const MyType &mytype);
const QDBusArgument &operator>>(const QDBusArgument &argument, MyType &mytype);

typedef QList<MyType> MyTypeList;
Q_DECLARE_METATYPE (MyTypeList);

inline void registerMyTypeDataTypes() {
    qDBusRegisterMetaType<MyType>();
    qDBusRegisterMetaType<MyTypeList>();
    qRegisterMetaType<MyTypeList>("MyTypeList");
}

#endif //CNOTIFICATIONTYPES_H
