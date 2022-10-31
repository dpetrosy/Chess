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
    sources/pieces_sources/bishop.cpp \
    sources/pieces_sources/empty.cpp \
    sources/pieces_sources/king.cpp \
    sources/pieces_sources/knight.cpp \
    sources/pieces_sources/queen.cpp \
    sources/pieces_sources/rook.cpp \
    sources/utils.cpp \
    sources/menus_sources/mainmenu.cpp \
    sources/menus_sources/pvpmenu.cpp \
    sources/menus_sources/quitdialog.cpp \
    sources/game_sources/gamewidget.cpp \
    sources/game_sources/boardwidget.cpp \
    sources/pieces_sources/piece.cpp \
    sources/pieces_sources/factory.cpp \
    sources/pieces_sources/pawn.cpp \


HEADERS += \
    headers/helpers.hpp \
    headers/mainwindow.hpp \
    headers/pieces_headers/bishop.hpp \
    headers/pieces_headers/empty.hpp \
    headers/pieces_headers/king.hpp \
    headers/pieces_headers/knight.hpp \
    headers/pieces_headers/predefined_pieces_classes.hpp \
    headers/pieces_headers/queen.hpp \
    headers/pieces_headers/rook.hpp \
    headers/utils.hpp \
    headers/menus_headers/menus_helpers.hpp \
    headers/menus_headers/mainmenu.hpp \
    headers/menus_headers/pvpmenu.hpp \
    headers/menus_headers/quitdialog.hpp \
    headers/menus_headers/predefined_menu_classes.hpp \
    headers/game_headers/gamewidget.hpp \
    headers/game_headers/boardwidget.hpp \
    headers/game_headers/game_helpers.hpp \
    headers/game_headers/predefined_game_classes.hpp \
    headers/pieces_headers/pieces_helpers.hpp \
    headers/pieces_headers/piece.hpp \
    headers/pieces_headers/factory.hpp \
    headers/pieces_headers/pawn.hpp \


INCLUDEPATH += \
    headers/ \
    headers/menus_headers/ \
    headers/game_headers/ \
    headers/pieces_headers/ \


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc \
