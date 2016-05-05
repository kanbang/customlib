
include(platform-lib.mk)


EPONOTE = $(HOME)/.build
DESTDIR = $$EPONOTE/bin

#message($(HOME))

EPONOTELIB = $$EPONOTE/lib

LIBS += -L/usr/lib64 -L$$EPONOTELIB
LIBS += -lepdatabase -lepmodel -leputility
