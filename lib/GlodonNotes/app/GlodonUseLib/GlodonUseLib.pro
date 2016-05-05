QT       += core gui


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TEMPLATE = app
TARGET   = UseLib

include($(NOTEDIRS)/platform/platform-app.mk)


SOURCES += \
    glodonmain.cpp \
    testinterface.cpp

#INCLUDEPATH += $(NOTEDIRS)/src/GlodonTestLib

#LIBS += -LD:/lib
#LIBS += -ltestlib

HEADERS += \
    testinterface.h
