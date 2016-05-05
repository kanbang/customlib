#include "dbustypes.h"

MyType::MyType()
{
    key.clear();
    value.clear();
}

QDBusArgument &operator<<(QDBusArgument &argument, const MyType &mytype)
{
    argument.beginStructure();
    argument << mytype.key << mytype.value ;
    argument.endStructure();
    return argument;
}

// Retrieve the Notification data from the D-Bus argument
const QDBusArgument &operator>>(const QDBusArgument &argument, MyType &mytype)
{
    argument.beginStructure();
    argument >> mytype.key >> mytype.value ;
    argument.endStructure();
    return argument;
}
