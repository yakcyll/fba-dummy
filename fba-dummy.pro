#-------------------------------------------------
#
# Project created by QtCreator 2016-02-09T01:37:51
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = fba-dummy
TEMPLATE = app

QMAKE_CXXFLAGS += -std=c++14

SOURCES += main.cpp\
        controlmodule.cpp

HEADERS  += controlmodule.h

FORMS    += controlmodule.ui
