#-------------------------------------------------
#
# Project created by QtCreator 2022-08-17T19:46:56
#
#-------------------------------------------------

QT       += core gui network sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = UI
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        widget.cpp \
    GUI/log.cpp \
    GUI/mainui.cpp \
    GUI/logon.cpp \
    GUI/testbox.cpp \
    GUI/mainui_leftbar.cpp \
    GUI/mainui_midbar.cpp \
    GUI/mainui_rightbar.cpp \
    signalopt.cpp \
    headlabel.cpp \ 
    listwidget.cpp \
    accountType/user.cpp \
    accountType/group.cpp \
    global.cpp \
    GUI/mytoolbutton.cpp \
    GUI/notice.cpp \
    jsonoperator.cpp \
    mypushbutton.cpp \
    noticeitem.cpp

HEADERS += \
        widget.h \
    GUI/log.h \
    GUI/mainui.h \
    GUI/logon.h \
    GUI/testbox.h \
    GUI/mainui_leftbar.h \
    GUI/mainui_midbar.h \
    GUI/mainui_rightbar.h \
    accountType/user.h \
    accountType/group.h \
    listwidget.h \
    signalopt.h \
    headlabel.h \
    global.h \
    GUI/mytoolbutton.h \
    GUI/notice.h \
    jsonoperator.h \
    mypushbutton.h \
    noticeitem.h


FORMS += \
        widget.ui \
    GUI/log.ui \
    GUI/mainui.ui \
    GUI/logon.ui \
    GUI/testbox.ui \
    GUI/notice.ui

# Default rules for deployment.


qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    photo.qrc \
    icon.qrc
