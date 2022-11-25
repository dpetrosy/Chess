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

    // General for menus
    extern QString MenusStylesPath;
    extern QString darkThemeBkgLabelStyle;
    extern QString lightThemeBkgLabelStyle;
    extern QString darkThemeTextStyle;
    extern QString lightThemeTextStyle;
    extern QString darkComboBoxStyle;
    extern QString lightComboBoxStyle;

    // Settings menu
    extern QString SettingsMenuStylesPath;
    extern QString darkThemeButtonsLabelStyle;
    extern QString hideAndShowButtonStyle;
    extern QString lightThemeButtonsLabelStyle;
    extern QString settingsMenuDarkCancelButtonStyle;
    extern QString settingsMenuLightCancelButtonStyle;
    extern QString settingsMenuSaveButtonStyle;
}

#endif // HELPERS_HPP
