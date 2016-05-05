TEMPLATE = app
TARGET = testfunction

include(../../platform/platform-app.mk)

HEADERS += \
    AaImagePixelColor.h \
    TestWindowApp.h \
    ETestHeader.h \
    AbImageMoveTransparent.h \
    testFactory.h \
    AcMouseAutoClickWindow.h \
    AdScrollAreaView.h

SOURCES += \
    AaImagePixelColor.cpp \
    TestWindowApp.cpp \
    epmain.cpp \
    AbImageMoveTransparent.cpp \
    testFactory.cpp \
    AcMouseAutoClickWindow.cpp \
    AdScrollAreaView.cpp

FORMS += \
    TestWindowApp.ui \
    AcMouseAutoClickWindow.ui

RESOURCES += \
    ../../icons/EPCommon.qrc

