
TEMPLATE = app

include(../../platform/platform-app.mk)

HEADERS += \
    AaClientWindowApp.h \
    AaServerWindowApp.h \
    DefineType.h

SOURCES += \
    epmain.cpp \
    AaClientWindowApp.cpp \
    AaServerWindowApp.cpp

FORMS += \
    AaClientWindowApp.ui \
    AaServerWindowApp.ui

QT += network

RESOURCES += \
    ../../icons/baseIcon.qrc

CONFIG += console
