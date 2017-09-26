#-------------------------------------------------
#
# Project created by QtCreator 2015-06-09T10:02:29
#
#-------------------------------------------------

QT       += core gui widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GraphicsView
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    myshape.cpp
    myshape.cpp

HEADERS  += widget.h \
    myshape.h

FORMS    += widget.ui
