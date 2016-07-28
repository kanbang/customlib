
TEMPLATE = app
TARGET = epnetwork

#######################################################################
#  如果要设置DESTDIR的存放路径，DESTDIR取的当前路径是notesAll-desktop，
#  也就是/home/xkd/notesAll-build-desktop-Qt_4_6_4_in_PATH__Qt-4_6_4__Debug

#  而如果要设置LIBS 的链接库路径，LIBS 取的当前路径和DESTDIR一样。

#  LIBS += -L/usr/lib64 -L$$(EPONOTELIB)/lib  -L 和后面的路径之间不能有空格。否则就不对了

#  INCLUDEPATH - 应用程序所需的额外的包含路径的列表。
#  DEPENDPATH - 应用程序所依赖的搜索路径。
#######################################################################

include(../../platform/platform-app.mk)


HEADERS += \
    ENAllHeader.h \
    AServerWidgetApp.h \
    AClientWidgetApp.h \
    AadlgClientApp.h \
    AadlgServerApp.h \
    AcTcpServerWindowApp.h \
    AbUdpWidgetApp.h \
    AbdlgUdpApp.h \
    networkWindowApp.h \
    networkFactory.h

QT += network widgets


SOURCES += \
    AServerWidgetApp.cpp \
    AClientWidgetApp.cpp \
    epmain.cpp \
    AadlgClientApp.cpp \
    AadlgServerApp.cpp \
    AcTcpServerWindowApp.cpp \
    AbUdpWidgetApp.cpp \
    AbdlgUdpApp.cpp \
    networkWindowApp.cpp \
    networkFactory.cpp

FORMS += \
    AadlgClientApp.ui \
    AadlgServerApp.ui \
    AcTcpServerWindowApp.ui \
    networkWindowApp.ui
