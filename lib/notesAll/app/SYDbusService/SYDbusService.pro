TEMPLATE = app

QT += qml declarative dbus

HEADERS += \
    dbustypes.h \
    dbusservice.h

SOURCES += \
    main.cpp \
    dbustypes.cpp \
    dbusservice.cpp

#RESOURCES += qml.qrc

OTHER_FILES += \
    main.qml
