TEMPLATE = subdirs
CONFIG  += ordered

LIST = src app

for(item, LIST) : exists($$item) : SUBDIRS += $$item
