TEMPLATE = subdirs
CONFIG += ordered
#
LIST = networklib FactoryModel StructModel map\
            ActionModel threadlib HeadFirstModel modelviewlib \
            datastream cfunction item  \
            widget learn syberos dbus \
            database custom

 for(item, LIST) : exists($$item) : SUBDIRS += $$item

#SUBDIRS += \
#    learn \
#    syberos \
#    database \
#    modelviewlib \
#    dbus \
#    threadlib \
#    custom \ QxtGlobalShortcut
#    widget

#   要态
#   CONFIG += staticlib
#   LIBS += /home/xkd/xxx.a
