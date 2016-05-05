TEMPLATE = app
TARGET = epthread

include(../../platform/platform-app.mk)

HEADERS += \
    ETAllHeader.h \
    AadlgThreadApp.h \
    AbShareMemoryWidgetApp.h \
    AcThreadWindowApp.h \
    AdImageWindowApp.h \
    threadFactory.h \
    threadWindowApp.h

SOURCES += \
    epmain.cpp \
    AadlgThreadApp.cpp \
    AbShareMemoryWidgetApp.cpp \
    AcThreadWindowApp.cpp \
    AdImageWindowAppwindowapp.cpp \
    threadFactory.cpp \
    threadWindowApp.cpp

FORMS += \
    AddlgImageResize.ui \
    threadWindowApp.ui
