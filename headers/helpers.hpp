#ifndef HELPERS_HPP
#define HELPERS_HPP

#include <QString>

enum class MainWindowProps
{
    windowSizeW = 1115,
    windowSizeH = 700,
};

namespace ImagesPaths
{
    extern QString imagesPath;
    extern QString piecesPath;
    extern QString logosPath;
    extern QString backgroundsPath;
    extern QString boardsPath;
    extern QString settingsPath;
    extern QString settingsBoardsPath;
    extern QString settingsPiecesSetsPath;
}

namespace StylesPaths
{
    extern QString stylesPath;
    extern QString pawnPromButtonsStyle;
    extern QString darkThemeBkgLabelStyle;
    extern QString lightThemeBkgLabelStyle;
    extern QString lightThemeButtonsLabelStyle;
    extern QString settingsMenuCancelButtonStyle;
    extern QString settingsMenuSaveButtonStyle;
    extern QString hideAndShowButtonStyle;
}

#endif // HELPERS_HPP
