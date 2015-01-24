#-------------------------------------------------
#
# Project created by QtCreator 2015-01-24T13:44:46
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Gesture2Midi2
TEMPLATE = app

SOURCES += main.cpp\
        mainwindow.cpp \
    colorkeyerhsv.cpp \
    handanalyzer.cpp \
    videoengine.cpp \
    videoformat.cpp \
    videowidget.cpp \
    winmidiinput.cpp \
    winmidioutput.cpp \
    midiparametercontroller.cpp

HEADERS  += mainwindow.h \
    colorkeyerhsv.h \
    cvmattoqimage.h \
    handanalyzer.h \
    midiinput.h \
    midioutput.h \
    videoengine.h \
    videoformat.h \
    videoprocessor.h \
    videowidget.h \
    midiparametercontroller.h

FORMS    += mainwindow.ui
include(drumstick.pro)
include (opencv.pri)


SUBDIRS += \
    colorkeyer.pro \
    drumstick.pro \
    drumstick.pro \
    drumstick.pro \
    drumstick.pro

OTHER_FILES += \
