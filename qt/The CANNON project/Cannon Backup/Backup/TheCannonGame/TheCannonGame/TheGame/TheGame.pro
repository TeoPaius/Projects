#-------------------------------------------------
#
# Project created by QtCreator 2015-03-19T13:17:17
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TheGame
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    cannonfield.cpp \
    extraspace.cpp

HEADERS  += widget.h \
    cannonfield.h \
    extraspace.h

FORMS    += widget.ui
