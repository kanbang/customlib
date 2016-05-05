#ifndef OBJECT_H
#define OBJECT_H

#include <QObject>
#include <QtDBus>

class MyType{
public:
    int key;
    QString value;
};
Q_DECLARE_METATYPE(MyType)


QDBusArgument &operator<<(QDBusArgument &argument, const MyType &mytype);
const QDBusArgument &operator>>(const QDBusArgument &argument, MyType &mytype);

QDataStream &operator<<(QDataStream& ds, const MyType &type);
QDataStream &operator>>( QDataStream& ds, MyType& type);

inline void registerMyTypeDataTypes() {
    qDBusRegisterMetaType<MyType>();
}

class object : public QObject
{
    Q_OBJECT
    Q_CLASSINFO("D-Bus Interface", "com.test.dbus")
public:
    explicit object(QObject *parent = 0);

signals:

public slots:
    MyType testMyType(MyType type);
    QByteArray testByte();
};

#endif // OBJECT_H
