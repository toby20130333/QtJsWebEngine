#-------------------------------------------------
#
# Project created by QtCreator 2015-09-10T12:59:27
#
#-------------------------------------------------

QT       += core gui
QT       += network webenginewidgets webchannel

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QtJsWebEngine
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    htmlpage.cpp \
    webobjectinstance.cpp

HEADERS  += mainwindow.h \
    htmlpage.h \
    webobjectinstance.h

FORMS    += mainwindow.ui

RESOURCES += \
    resources.qrc

DISTFILES += \
    QtQuickWebEngine.qml
