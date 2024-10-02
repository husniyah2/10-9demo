TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.c \
        my_utils.c \
        util_matrices.cpp \
        util_sequences.c

HEADERS += \
    my_utils.h \
    util_matrices.h \
    util_sequences.h
