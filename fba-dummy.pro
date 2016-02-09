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

SOURCES += main.cpp \
    control_module.cpp \
    fba_game_input_config_store.cpp

HEADERS  += \
    fba_game_input_config_store.h \
    control_module.h

FORMS    += \
    control_module.ui

RESOURCES += \
    images.qrc

DISTFILES +=
