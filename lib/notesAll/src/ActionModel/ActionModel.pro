TEMPLATE = lib
TARGET   = actionmodel


include(../../platform/platform-lib.mk)
HEADERS += \
    EPTemplate.h \
    EPStrategy.h \
    EPState.h \
    EPObserver.h \
    EPMediator.h \
    EPMemento.h \
    EPReciever.h \
    EPVisitor.h \
    EPChainOfResponsibility.h \
    EPIterator.h \
    EPInterpreter.h

SOURCES += \
    EPTemplate.cpp \
    main.cpp \
    EPStrategy.cpp \
    EPState.cpp \
    EPObserver.cpp \
    EPMediator.cpp \
    EPMemento.cpp \
    EPReciever.cpp \
    EPVisitor.cpp \
    EPChainOfResponsibility.cpp \
    EPIterator.cpp \
    EPInterpreter.cpp
