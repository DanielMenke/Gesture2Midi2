#-------------------------------------------------
#
# Project created by QtCreator 2014-11-14T11:50:15
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PlayMidiNote
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    ../ColorKeyer-regions/colorkeyerhsv.cpp \
    ../videoengine/videoengine.cpp \
    ../videoengine/videoformat.cpp \
    ../videoengine/videowidget.cpp \
    handanalyzer.cpp

HEADERS  += mainwindow.h \
    ../ColorKeyer-regions/colorkeyerhsv.h \
    ../videoengine/cvmattoqimage.h \
    ../videoengine/videoengine.h \
    ../videoengine/videoformat.h \
    ../videoengine/videoprocessor.h \
    ../videoengine/videowidget.h \
    handanalyzer.h



FORMS    += mainwindow.ui
include(../drumstick/drumstick.pro)
include (opencv.pri)


OTHER_FILES +=
