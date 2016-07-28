
TEMPLATE = lib

TARGET = epdbus

QT += dbus

include(../../platform/platform-lib.mk)

HEADERS += \
    EPHotel.h \
    EPDbusService.h \
    EPDbusClient.h

SOURCES += \
    EPHotel.cpp \
    EPDbusService.cpp \
    EPDbusClient.cpp


