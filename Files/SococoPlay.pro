TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

LIBS +=  -lX11 -lGL -lm

SOURCES += \
        interfaceGraphique.c \
        main.c

HEADERS += \
    interfaceGraphique.h
