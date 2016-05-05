#-------------------------------------------------
#
# Project created by QtCreator 2014-07-15T18:52:33
#
#-------------------------------------------------

QT       += widgets

TARGET = SharedLib
TEMPLATE = lib

DEFINES += SHAREDLIB_LIBRARY

include($(NOTEDIRS)\platform\platform-lib.mk)

SOURCES += SharedLib.cpp \
    GlodonURL.cpp \
    GlodonServiceDesign.cpp

HEADERS += SharedLib.h\
        sharedlib_global.h \
    GlodonURL.h \
    GlodonServiceDesign.h

unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}
