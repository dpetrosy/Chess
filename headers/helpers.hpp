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
    extern QString lightThemeBkgLabelStyle;
    extern QString darkThemeBkgLabelStyle;
    extern QString lightTextStyle;
    extern QString darkTextStyle;
    extern QString lightBoldTextStyle;
    extern QString darkBoldTextStyle;
    extern QString lightComboBoxStyle;
    extern QString darkComboBoxStyle;
    extern QString lightSliderStyle;
    extern QString darkSliderStyle;
    extern QString lightDimTextStyle;
    extern QString darkDimTextStyle;

    // Settings menu
    extern QString SettingsMenuStylesPath;
    extern QString hideAndShowButtonStyle;
    extern QString lightThemeButtonsLabelStyle;
    extern QString darkThemeButtonsLabelStyle;
    extern QString settingsMenuLightCancelButtonStyle;
    extern QString settingsMenuDarkCancelButtonStyle;
    extern QString settingsMenuSaveButtonStyle;

    // PVP menu
    extern QString PVPMenuStylesPath;
    extern QString lightTopTextStyle;
    extern QString darkTopTextStyle;
    extern QString lightTimeControlBkgLabelStyle;
    extern QString darkTimeControlBkgLabelStyle;
}

#endif // HELPERS_HPP
