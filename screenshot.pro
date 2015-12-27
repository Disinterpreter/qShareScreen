#-------------------------------------------------
#
# Project created by QtCreator 2015-12-25T11:58:23
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = screenshot
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    frame.cpp \
    qexlabel.cpp

HEADERS  += mainwindow.h \
    frame.h \
    qexlabel.h

FORMS    += mainwindow.ui \
    frame.ui
