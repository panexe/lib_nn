TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        activation.cpp \
        denselayer.cpp \
        inputlayer.cpp \
        layer.cpp \
        main.cpp \
        matrix.cpp \
        neuralnetwork.cpp \
        outputlayer.cpp

HEADERS += \
    activation.h \
    denselayer.h \
    inputlayer.h \
    layer.h \
    matrix.h \
    neuralnetwork.h \
    outputlayer.h
