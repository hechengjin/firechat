#-------------------------------------------------
#
# Project created by QtCreator 2020-03-27T10:41:05
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = firechat
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
    widgets/title_widget.cpp \
    widgets/push_button.cpp \
    widgets/tool_button.cpp \
    boxes/main_widget.cpp \
    util/util.cpp \
    boxes/content_widget.cpp \
    widgets/main_menu.cpp \
    widgets/system_tray.cpp \
    boxes/about_us.cpp \
    boxes/skin_widget.cpp \
    widgets/change_skin_widget.cpp \
    boxes/setting_dialog.cpp

HEADERS += \
    widgets/title_widget.h \
    widgets/push_button.h \
    widgets/tool_button.h \
    boxes/main_widget.h \
    util/util.h \
    boxes/content_widget.h \
    widgets/main_menu.h \
    widgets/system_tray.h \
    boxes/about_us.h \
    boxes/skin_widget.h \
    widgets/change_skin_widget.h \
    boxes/setting_dialog.h \
    util/common.h

TRANSLATIONS += English.ts\
                Chinese.ts
# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    qrc.qrc
