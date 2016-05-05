TEMPLATE = subdirs
CONFIG += ordered

LIST = database model

 for(item, LIST) : exists($$item) : SUBDIRS += $$item

SUBDIRS += \
    utility
