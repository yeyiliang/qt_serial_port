#-------------------------------------------------
#
# Project created by QtCreator 2019-05-16T14:38:25
#
#-------------------------------------------------

QT       += core gui
QT       += serialport
QT += sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = myserial
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    fb_encode.cpp \
    sqlite.cpp

HEADERS  += widget.h \
    fb_encode.h \
    sqlite.h

FORMS    += widget.ui
