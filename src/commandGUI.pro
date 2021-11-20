QT += core widgets
TARGET = CommandGUI
QMAKE_CXXFLAGS += -O2 -O -I. -lboost_thread -lpthread -lboost_system
QMAKE_LFLAGS += -lboost_thread -lpthread -lboost_system
QMAKE_LIBS += -lboost_thread -lpthread -lboost_system
TEMPLATE = app 
SOURCES += main.cpp mainwindow.cpp command.cpp
HEADERS += mainwindow.h command.h
LIBS += -lboost_thread -lpthread 
QMAKE_CC += -g
QMAKE_CXX += -g
QMAKE_LINK += -g
