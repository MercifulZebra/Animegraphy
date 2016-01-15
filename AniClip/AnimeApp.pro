#-------------------------------------------------
#
# Project created by QtCreator 2016-01-07T22:20:43
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = AnimeApp
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    parse.cpp \
    tablineedit.cpp \
    clip.cpp \
    tagcontainer.cpp \
    tagtreewidget.cpp \
    listtreewidget.cpp

HEADERS  += mainwindow.h \
    apptypes.h \
    tablineedit.h \
    clip.h \
    tagcontainer.h \
    tagtreewidget.h \
    listtreewidget.h

FORMS    += mainwindow.ui
