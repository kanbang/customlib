TEMPLATE = lib
TARGET  = cfunction

include(../../platform/platform-lib.mk)

HEADERS += \
    EPCFunction.h \
    EPAlgorithm.h \
    effective.h \
    EPDataStructs.h \
    EPBinTreeNode.h \
    EPHashTable.h \
    EPTrie.h \
    EPBPlusTree.h \
    EPMinusTree.h \
    EPAVLTree.h \
    EPRedBlackTree.h

SOURCES += \
    EPCFunction.cpp \
    EPAlgorithm.cpp \
    effective.cpp \
    EPDataStructs.cpp \
    EPBinTreeNode.cpp \
    EPHashTable.cpp \
    EPTrie.cpp \
    EPBPlusTree.cpp \
    EPMinusTree.cpp \
    EPAVLTree.cpp \
    EPRedBlackTree.cpp


