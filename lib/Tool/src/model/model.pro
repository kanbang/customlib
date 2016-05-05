
TARGET = epmodel
TEMPLATE = lib
DESTDIR = $(HOME)/.build/lib

QT += sql

include(../../platform/platform-lib.mk)

DEFINES += MODEL_LIBRARY

HEADERS += \
    tablemodel.h \
    EPModel_global.h

SOURCES += \
    tablemodel.cpp

LIBS += -L/usr/lib64 -L/home/xkd/.build/lib
LIBS += -lepdatabase
