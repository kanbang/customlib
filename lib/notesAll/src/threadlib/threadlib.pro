TEMPLATE = lib
TARGET = thread
#
include(../../platform/platform-lib.mk)

HEADERS += \
    MuteThread.h \
    SemaphoreThread.h \
    WaitConditionThread.h \
    TransactionThread.h \
    threadSignalSlot.h \
    readme.h \
    SYThreadConnect.h

SOURCES += \
    MuteThread.cpp \
    SemaphoreThread.cpp \
    WaitConditionThread.cpp \
    TransactionThread.cpp \
    threadSignalSlot.cpp \
    SYThreadConnect.cpp
