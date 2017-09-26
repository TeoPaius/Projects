#-------------------------------------------------
#
# Project created by QtCreator 2015-07-08T15:47:52
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Battleships_1
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    board.cpp \
    ship.cpp

HEADERS  += widget.h \
    board.h \
    ship.h

FORMS    += widget.ui
