
TARGET = epdatabase
TEMPLATE = lib
DESTDIR = $(HOME)/.build/lib

#core-private 包含qobject_p.h
# #include <private/qobject_p.h>

QT += sql  core-private

include(../../platform/platform-lib.mk)

DEFINES += DATABASE_LIBRARY

HEADERS += \
    EPDatabase_global.h \
    ccontactdb.h \
    ccontact.h \
    ccontact_p.h \
    utildb.h \
    managerdb.h \
    tabledata.h \
    DatabaseManagerProxy.h \
    dataobject.h


unix {
    target.path = /usr/lib
    INSTALLS += target
}

SOURCES += \
    ccontactdb.cpp \
    ccontact.cpp \
    utildb.cpp \
    managerdb.cpp \
    tabledata.cpp \
    DatabaseManagerProxy.cpp \
    dataobject.cpp
