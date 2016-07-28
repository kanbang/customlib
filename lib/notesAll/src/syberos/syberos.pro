TEMPLATE = lib
TARGET = syberos

include(../../platform/platform-lib.mk)

QT += dbus declarative

HEADERS += \
    EPDBus.h \
    EPQml.h \
    EPObject.h \
    EPSyberosAlgo.h \
    SyMatchNumber.h \
    EPMateObject.h

SOURCES += \
    EPDBus.cpp \
    EPQml.cpp \
    EPObject.cpp \
    EPSyberosAlgo.cpp \
    SyMatchNumber.cpp \
    EPMateObject.cpp

OTHER_FILES += \
    main.qml \
    EPQmlInteractionC.qml
