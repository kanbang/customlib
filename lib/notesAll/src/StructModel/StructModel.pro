TEMPLATE = lib
TARGET   = struckmodel

include(../../platform/platform-lib.mk)
SOURCES += \
    main.cpp \
    EPBridge.cpp \
    EPAdapter.cpp \
    EPDecorator.cpp \
    EPComposite.cpp \
    EPFlyWeight.cpp \
    EPFacade.cpp \
    EPProxy.cpp

HEADERS += \
    EPBridge.h \
    EPAdapter.h \
    EPDecorator.h \
    EPComposite.h \
    EPFlyWeight.h \
    EPFacade.h \
    EPProxy.h
