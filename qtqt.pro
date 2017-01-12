QT      += core gui widgets

TARGET   = graphics
TEMPLATE = app

CONFIG  += c++11

SOURCES += \
   main.cpp \
   renderwindow.cpp \
   renderarea.cpp \
   client.cpp \
   renderer.cpp

HEADERS += \
   eventhandler.h \
   renderwindow.h \
   renderarea.h \
   client.h \
   renderer.h
