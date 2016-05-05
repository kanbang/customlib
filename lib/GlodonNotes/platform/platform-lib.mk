#设置工程运行的时候搜索头文件路径

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

EPOINCLUDE = $(NOTEDIRS)/src

#  如果 HEADERS += 不是当前路径的文件，而是其他路径的文件，那么就要
#  用INCLUDEPATH += 文件的路径。 为什么当前路径下的不添加INCLUDEPATH，
#  那是因为 INCLUDEPATH 默认添加当前路径

INCLUDEPATH += $$EPOINCLUDE/GlodonModelView
INCLUDEPATH += $$EPOINCLUDE/GlodonTestLib
INCLUDEPATH += $$EPOINCLUDE/GlodonLearn
INCLUDEPATH += $$EPOINCLUDE/GlodonForm
INCLUDEPATH += $$EPOINCLUDE/SharedLib
INCLUDEPATH += $$EPOINCLUDE/GlodonPattern

message($$EPOINCLUDE)
# 如果没有$$EPOINCLUDE/,那么就不能包含头文件。 #include<cfunction/EPCFunction.h>
# 因为头文件搜索路径不是从$$EPOINCLUDE 开始。


DESTDIR = D:/program/lib
UI_DIR = .uidir
MOC_DIR = .moc
OBJECTS_DIR = .obj
RCC_DIR = .rcc


