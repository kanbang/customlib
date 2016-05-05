#######################################################################
#  如果要设置DESTDIR的存放路径，DESTDIR取的当前路径是notesAll-desktop，
#  也就是/home/xkd/notesAll-build-desktop-Qt_4_6_4_in_PATH__Qt-4_6_4__Debug

#  而如果要设置LIBS 的链接库路径，LIBS 取的当前路径和DESTDIR一样。

#  LIBS += -L/usr/lib64 -L$$(EPONOTELIB)/lib  -L 和后面的路径之间不能有空格。否则就不对了

#  INCLUDEPATH - 应用程序所需的额外的包含路径的列表。
#  DEPENDPATH - 应用程序所依赖的搜索路径。
#######################################################################

#此处用来设置连接库的
#这些文件只是用来生成Makefile，一旦生成Makefile，那就跟这些文件没有关心了。

include(platform-lib.mk)
EPONOTE = $(HOME)/.build
DESTDIR = $$EPONOTE/bin

#message($(HOME)) -lgxtglobalshortcut

EPONOTELIB = $$EPONOTE/lib

LIBS += -L/usr/lib64 -L$$EPONOTELIB
LIBS += -lfactorymodel -lthread -lcfunction  -litem -lX11 -lXext -lXtst
LIBS += -lmodelviewlib -ldatastream -lmap -lwidget -lsyberos -ldatabase -lsqlite3 -lepdbus

#运行程序如果要静态编译，则可以这么设置静态库
# LIBS += 路径/具体库  LIBS += /home/xkd/ligQtGui.a(注意是点a)
