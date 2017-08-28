#-------------------------------------------------
#
# Project created by QtCreator 2017-04-27T18:47:38
#
#-------------------------------------------------
QT += core
QT += sql
QT += network
QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Stronghold
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    wincreate.cpp \
    wingenerate.cpp \
    xsabout.cpp \
    uitablelist.cpp \
    mainwindow.cpp \
    uilogin.cpp \
    xsbuttons.cpp

HEADERS +=\
    wincreate.h \
    wingenerate.h \
    xsabout.h \
    uitablelist.h \
    mainwindow.h \
    uilogin.h \
    xsbuttons.h

FORMS    += \
    wincreate.ui \
    wingenerate.ui \
    xsabout.ui \
    uilogin.ui \
    mainwindow.ui \


linux {
    INCLUDEPATH += /usr/include/xslib
    INCLUDEPATH += /usr/include/libStronghold
    target.path = /usr/bin
    INSTALLS += target
}

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../bin/release/ -lstronghold -lxs
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../bin/debug/ -lstronghold -lxs
else:unix: LIBS += -L$$PWD/../../bin/ -lstronghold -lxs

INCLUDEPATH += $$PWD/../xslib
INCLUDEPATH += $$PWD/../lib
DEPENDPATH += $$PWD/../lib

RESOURCES += \
    ../xsResource/res.qrc
