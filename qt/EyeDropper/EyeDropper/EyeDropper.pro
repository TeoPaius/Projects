#-------------------------------------------------
#
# Project created by QtCreator 2015-02-16T19:31:17
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = EyeDropper
TEMPLATE = app


SOURCES += main.cpp\
        eyedropper.cpp \
    mylabel.cpp

HEADERS  += eyedropper.h \
    mylabel.h

FORMS    += eyedropper.ui

RESOURCES += \
    images.qrc
