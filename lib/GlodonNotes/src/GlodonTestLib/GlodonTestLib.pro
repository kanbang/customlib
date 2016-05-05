
QT  += widgets

TEMPLATE = lib
TARGET = testlib

DEFINES += WIDGET_LIBRARY

include($(NOTEDIRS)\platform\platform-lib.mk)

HEADERS += \
    GlodonTestGrammar.h \
    glodontestlib_global.h \
    GlodonTestWidget.h \
    GlodonThread.h \
    GlodonSmartPointer.h

SOURCES += \
    GlodonTestWidget.cpp \
    GlodonTestGrammar.cpp \
    GlodonThread.cpp \
    GlodonSmartPointer.cpp

LIBS += -LD:\program\lib
LIBS += -lGlodonModelView
