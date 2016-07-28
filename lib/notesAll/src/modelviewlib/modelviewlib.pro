#ļͣ ִг app ǿlib ǵ subdirs
TEMPLATE = lib

# Ŀļ 磺 ɵnetworklib.so.1
TARGET  = modelviewlib

include(../../platform/platform-lib.mk)

HEADERS += \
    EPModel.h \
    TreeWidget.h

SOURCES += \
    EPModel.cpp \
    TreeWidget.cpp
