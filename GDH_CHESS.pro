QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    sources/boardwidget.cpp \
    sources/gamewidget.cpp \
    sources/main.cpp \
    sources/mainwindow.cpp \
    sources/pieces_sources/factory.cpp \
    sources/pieces_sources/pawn.cpp \
    sources/pieces_sources/piece.cpp \
    sources/quitdialog.cpp

HEADERS += \
    headers/boardwidget.hpp \
    headers/gamewidget.hpp \
    headers/helpers.hpp \
    headers/mainwindow.hpp \
    headers/pieces_headers/factory.hpp \
    headers/pieces_headers/pawn.hpp \
    headers/pieces_headers/piece.hpp \
    headers/quitdialog.hpp \

INCLUDEPATH += \
    headers/ \
    headers/pieces_headers \

FORMS += \
    mainwindow.ui \
    quitdialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc \
