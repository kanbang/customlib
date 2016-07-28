TEMPLATE = app

QT += qml declarative dbus

SOURCES += main.cpp \
    dbusclient.cpp \
    dbuswatcher.cpp \
    dbustypes.cpp

#RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model

# Default rules for deployment.
#include(deployment.pri)

HEADERS += \
    dbusclient.h \
    dbuswatcher.h \
    dbustypes.h

OTHER_FILES += \
    main.qml \
