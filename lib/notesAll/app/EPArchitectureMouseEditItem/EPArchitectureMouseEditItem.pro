TEMPLATE = app
TARGET = architecturemouseedititem

include(../../platform/platform-app.mk)

SOURCES += \
    epmain.cpp

QT += dbus sql
