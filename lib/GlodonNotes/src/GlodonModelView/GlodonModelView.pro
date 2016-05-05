#-------------------------------------------------
#
# Project created by QtCreator 2014-06-14T16:06:30
#
#-------------------------------------------------

QT       += widgets

TARGET = GlodonModelView
TEMPLATE = lib

DEFINES += GLODONMODELVIEW_LIBRARY

include($(NOTEDIRS)\platform\platform-lib.mk)

SOURCES += GlodonModelView.cpp \
    GlodonModel.cpp \
    GlodonTreeView.cpp

HEADERS += GlodonModelView.h\
        glodonmodelview_global.h \
    GlodonModel.h \
    GlodonTreeView.h

unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}
