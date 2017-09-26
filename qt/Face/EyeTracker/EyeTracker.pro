#-------------------------------------------------
#
# Project created by QtCreator 2015-06-18T17:30:28
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = EyeTracker
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    background.cpp

HEADERS  += widget.h \
    background.h

FORMS    += widget.ui

RESOURCES += \
    images.qrc

DISTFILES +=
