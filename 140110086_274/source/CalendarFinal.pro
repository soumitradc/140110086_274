#-------------------------------------------------
#
# Project created by QtCreator 2015-04-12T12:31:02
#
#-------------------------------------------------

QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets multimedia

TARGET = CalendarFinal
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    global.cpp \
    reminddialog.cpp \
    remind.cpp \
    mydialog.cpp \
    editreminder.cpp \
    confirmdelete.cpp

HEADERS  += mainwindow.h \
    global.h \
    remind.h \
    mydialog.h \
    editreminder.h \
    confirmdelete.h \
    reminddialog.h

FORMS    += mainwindow.ui \
    reminddialog.ui \
    remind.ui \
    mydialog.ui \
    editreminder.ui \
    confirmdelete.ui

RESOURCES += \
    res.qrc
