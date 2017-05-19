TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

INCLUDEPATH +=$$PWD/include

LIBS += $$PWD/lib/libcuhkszlib.a


SOURCES +=  src/main.cpp
