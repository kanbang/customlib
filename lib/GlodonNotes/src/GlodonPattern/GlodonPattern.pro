#-------------------------------------------------
#
# Project created by QtCreator 2014-09-22T13:29:55
#
#-------------------------------------------------

QT       += widgets

TARGET = GlodonPattern
TEMPLATE = lib

DEFINES += GLODONPATTERN_LIBRARY

SOURCES += GlodonPattern.cpp \
    GlodonCommand.cpp

HEADERS += GlodonPattern.h\
        glodonpattern_global.h \
    GlodonCommand.h

include($(NOTEDIRS)\platform\platform-lib.mk)

unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}
