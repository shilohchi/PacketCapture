######################################################################
# Automatically generated by qmake (2.01a) Thu Jun 13 21:28:12 2013
######################################################################

QT += network
QMAKE_CXXFLAGS += -g -std=c++11 -I/usr/include/qjson -include glog/logging.h
LIBS += -lqjson -lglog
TEMPLATE = app
TARGET = 
DEPENDPATH += .
INCLUDEPATH += .

# Input
HEADERS += DummyHandler.h GetConfigHandler.h RequestHandler.h Server.h
SOURCES += DummyHandler.cpp \
           GetConfigHandler.cpp \
           main.cpp \
           RequestHandler.cpp \
           Server.cpp