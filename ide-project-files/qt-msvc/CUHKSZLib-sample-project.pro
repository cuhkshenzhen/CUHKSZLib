TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

INCLUDEPATH +=$$PWD/include
CONFIG(debug, debug|release) {
    LIBS += $$PWD/lib/Debug/cuhkszlib.lib
} else {
    LIBS += $$PWD/lib/Release/cuhkszlib.lib
}


SOURCES +=  src/main.cpp
