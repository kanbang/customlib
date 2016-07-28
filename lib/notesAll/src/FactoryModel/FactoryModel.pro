TEMPLATE = lib
TARGET   = factorymodel

include(../../platform/platform-lib.mk)
HEADERS += \
    EPEffective.h \
    EPFactory.h \
    AbstractFactory.h \
    EPSingleton.h \
    EPBuilder.h \
    EPPrototype.h

SOURCES += \
    EPEffective.cpp \
    main.cpp \
    EPFactory.cpp \
    AbstractFactory.cpp \
    EPSingleton.cpp \
    EPBuilder.cpp \
    EPPrototype.cpp

QT += network
