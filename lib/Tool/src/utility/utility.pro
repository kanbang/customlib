#-------------------------------------------------
#
# Project created by QtCreator 2015-12-29T16:41:37
#
#-------------------------------------------------

include(../../platform/platform-lib.mk)

TARGET = eputility
TEMPLATE = lib

DEFINES += UTILITY_LIBRARY

SOURCES += utility.cpp \
    stringutility.cpp \
    vcardparser.cpp

HEADERS += utility.h\
        utility_global.h \
    stringutility.h \
    vcardparser.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
