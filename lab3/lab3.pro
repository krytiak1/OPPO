QT += core
QT -= gui

CONFIG += c++11

TARGET = lab2
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    student.cpp \
    filehandler.cpp \
    printer.cpp \
    studentprinter.cpp

HEADERS += \
    student.h \
    filehandler.h \
    printer.h \
    studentprinter.h
