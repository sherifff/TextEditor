#-------------------------------------------------
#
# Project created by QtCreator 2015-06-25T15:49:14
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TextEditor
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    mytextedit.cpp

HEADERS  += mainwindow.h \
    mytextedit.h

FORMS    += mainwindow.ui

CONFIG += mobility
MOBILITY = 

DISTFILES +=

RESOURCES += \
    myres.qrc

