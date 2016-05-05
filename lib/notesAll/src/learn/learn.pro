
TEMPLATE = lib
TARGET  = learn

include(../../platform/platform-lib.mk)
HEADERS += \
    LPqtClassFunction.h \
    LPobjectClass.h \
    LPLinux.h \
    LPgeoanalyst.h \
    EPCodeTest.h \
    command.h \
    linux.h \
    qt.h \
    LPQt.h \
    thought.h \
    LPRedhat.h \
    LPUbuntu.h \
    EPSyberos.h \
    python.h \
    computer.h \
    java.h

SOURCES += \
    LPqtClassFunction.cpp \
    LPQt.cpp \
    LPobjectClass.cpp \
    LPLinux.cpp \
    EPCodeTest.cpp \
    command.cpp \
    linux.cpp \
    qt.cpp \
    thought.cpp \
    LPRedhat.cpp \
    LPUbuntu.cpp \
    EPSyberos.cpp \
    python.cpp \
    computer.cpp \
    java.cpp

OTHER_FILES += \
    macros
