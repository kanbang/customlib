TEMPLATE = app
TARGET = Test

QT += core gui widgets sql

include(../../platform/platform-app.mk)

SOURCES += \
    main.cpp \
    DisplayTableForm.cpp

HEADERS += \
    DisplayTableForm.h

FORMS += \
    DisplayTableForm.ui
