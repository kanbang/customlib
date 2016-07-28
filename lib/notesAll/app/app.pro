
TEMPLATE = subdirs
CONFIG  += ordered

LIST = network thread TestFunction qtalk \
         TestDBus EPArchitectureMouseEditItem \
         SYDbusClient SYDbusService

# for(item , LIST) : exists($$item) : SUBDIRS += $$item

SUBDIRS += \
    EPArchitectureMouseEditItem \
    TestDBus \
    SYDbusClient \
    SYDbusService \
    qtalk\
    thread \
    dbus\
    network

