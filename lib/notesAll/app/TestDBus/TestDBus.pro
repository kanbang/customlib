
TEMPLATE = app
TARGET = testDBus

include(../../platform/platform-app.mk)

QT += dbus

SOURCES += \
    epmain.cpp
