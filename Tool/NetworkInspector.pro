#-------------------------------------------------
#
# Project created by QtCreator 2014-08-12T02:12:15
#
#-------------------------------------------------

QT       += core gui network websockets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = NetworkInspector
TEMPLATE = app


SOURCES += main.cpp\
        networkinspector.cpp

HEADERS  += networkinspector.h

FORMS    += networkinspector.ui

RESOURCES += \
    ressources.qrc
