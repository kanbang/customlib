#-------------------------------------------------
#
# Project created by QtCreator 2014-06-13T14:17:49
#
#-------------------------------------------------

QT       += widgets

TARGET = GlodonForm
TEMPLATE = lib

DEFINES += GLODONFORM_LIBRARY

SOURCES += \
    GlodonForm.cpp \
    GlodonGuideTipFrame.cpp

HEADERS +=\
        glodonform_global.h \
    GlodonForm.h \
    GlodonGuideTipFrame.h

include($(NOTEDIRS)\platform\platform-lib.mk)

unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}

FORMS += \
    GlodonForm.ui

RESOURCES += \
    ../../icons/EPCommon.qrc
