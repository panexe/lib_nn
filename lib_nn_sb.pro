TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        activation.cpp \
        layer.cpp \
        main.cpp \
        matrix.cpp \
        neuralnetwork.cpp

HEADERS += \
    activation.h \
    layer.h \
    matrix.h \
    neuralnetwork.h
