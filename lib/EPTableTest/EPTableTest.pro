#-------------------------------------------------
#
# Project created by QtCreator 2014-05-31T08:55:22
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = EPTableTest
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    EPlogAbstractModel.cpp \
    EPlogTable.cpp

HEADERS  += mainwindow.h \
    EPlogAbstractModel.h \
    EPlogTable.h

FORMS    += mainwindow.ui
