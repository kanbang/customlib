#工程文件的类型， 是执行程序 app， 还是库lib， 或者是迭代编译 subdirs
TEMPLATE = lib

# 生成目标文件的名字 例如： 这里生成的是networklib.so.1
TARGET  = network

include(../../platform/platform-lib.mk)
SOURCES += \
    ClientSocketObj.cpp

HEADERS += \
    ClientSocketObj.h

QT += network
