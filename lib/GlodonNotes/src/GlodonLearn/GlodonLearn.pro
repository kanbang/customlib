#-------------------------------------------------
#
# Project created by QtCreator 2014-06-07T10:07:48
#
#-------------------------------------------------

QT       += core gui

TARGET = GlodonLearn
TEMPLATE = lib

DEFINES += GLODONLEARN_LIBRARY

SOURCES += GlodonLearn.cpp \
    GlodonWin.cpp \
    GlodonDelphi.cpp \
    GlodonCommand.cpp \
    GlodonClassDescription.cpp \
    GlodonWorkUseClass.cpp \
    GlodonBusiness.cpp

HEADERS += GlodonLearn.h\
        glodonlearn_global.h \
    GlodonWin.h \
    GlodonDelphi.h \
    GlodonCommand.h \
    GlodonClassDescription.h \
    GlodonWorkUseClass.h \
    GlodonBusiness.h

include($(NOTEDIRS)\platform\platform-lib.mk)

unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}
