# 这是笔记程序，为了更好的管理所有的工程
# 规定一定的命名方式

# 1、工程按模块来命名。 例如，如果该工程是为了测试网络的程序。那么工程的名字就为 EPNetwork 。如果显示主窗口，那么则命名为 ...App,
#   如果是这个主窗口里面要管理的对象，则命名为  ...App
#
# 2、在src里面，以lib结尾的都是程序库，learn主要以注释为主，代码测试放在cfunction里
#
#
#
#
#
#
#
#
# 生成调试程序
# CONFIG += qt debug
TEMPLATE = subdirs
CONFIG  += ordered

LIST = src app

for(item, LIST) : exists($$item) : SUBDIRS += $$item


