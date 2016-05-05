TEMPLATE = lib
TARGET = database

include(../../platform/platform-lib.mk)

QT += sql core

HEADERS += \
    EPDatabase.h \
    EPSqlite.h \
    Sqlite.h \
    EPLocalCity.h

SOURCES += \
    EPDatabase.cpp \
    EPSqlite.cpp \
    Sqlite.cpp \
    EPLocalCity.cpp

