#-------------------------------------------------
#
# Project created by QtCreator 2016-04-30T19:42:17
#
#-------------------------------------------------

QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Application
TEMPLATE = app

SOURCES += main.cpp\
        mainwindow.cpp \
    gamehandler.cpp

HEADERS += mainwindow.h \
    gamehandler.h

FORMS += mainwindow.ui

CONFIG += c++11
