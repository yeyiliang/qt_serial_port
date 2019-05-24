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
    sqlite.cpp \
    fb_cmd.cpp \
    fb_decode.cpp \
    db_cmd.cpp

HEADERS  += widget.h \
    fb_encode.h \
    sqlite.h \
    fb_cmd.h \
    fb_decode.h \
    db_cmd.h

FORMS    += widget.ui
