#工程文件的类型， 是执行程序 app， 还是库lib， 或者是迭代编译 subdirs
TEMPLATE = lib

# 生成目标文件的名字 例如： 这里生成的是networklib.so.1
TARGET  = gxtglobalshortcut

include(../../platform/platform-lib.mk)

INCLUDEPATH += $$PWD
DEPENDPATH += $$PWD

HEADERS += $$PWD/qxtglobal.h \
           $$PWD/qxtglobalshortcut.h \
           $$PWD/qxtglobalshortcut_p.h
SOURCES += $$PWD/qxtglobalshortcut.cpp
win32{
    SOURCES += $$PWD/qxtglobalshortcut_win.cpp
    LIBS += -luser32
}
unix:SOURCES += $$PWD/qxtglobalshortcut_x11.cpp
mac:SOURCES += $$PWD/qxtglobalshortcut_mac.cpp

