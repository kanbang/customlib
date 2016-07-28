#ļͣ ִг app ǿlib ǵ subdirs
TEMPLATE = lib

# Ŀļ 磄17ɵnetworklib.so.1
TARGET  = datastream

include(../../platform/platform-lib.mk)

HEADERS += \
    EPDataTextStream.h \
    EPOutBlockDatastream.h

SOURCES += \
    EPDataTextStream.cpp \
    EPOutBlockDatastream.cpp

