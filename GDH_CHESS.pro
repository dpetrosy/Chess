QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    sources/main.cpp \
    sources/mainwindow.cpp \
    sources/namespaces.cpp \
    sources/utils.cpp \
    sources/menus_sources/mainmenu.cpp \
    sources/menus_sources/pvpmenu.cpp \
    sources/menus_sources/quitdialog.cpp

HEADERS += \
    headers/helpers.hpp \
    headers/mainwindow.hpp \
    headers/menus_helpers.hpp \
    headers/utils.hpp \
    headers/menus_headers/mainmenu.hpp \
    headers/menus_headers/pvpmenu.hpp \
    headers/menus_headers/quitdialog.hpp

INCLUDEPATH += \
    headers/ \
    headers/menus_headers/

FORMS += \
    mainwindow.ui \
    quitdialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc \
