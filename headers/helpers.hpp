#ifndef HELPERS_HPP
#define HELPERS_HPP

#include <QString>

extern bool globalIsDarkTheme;
extern QString globalPieceSetPath;

enum class MainWindowProps
{
    windowSizeW = 1115,
    windowSizeH = 700,
};

namespace ImagesPaths
{
    extern QString imagesPath;
    extern QString boardsPath;

    // Logos images
    extern QString logosPath;

    // Backgrounds images
    extern QString backgroundsPath;
    extern QString LightThemeGameBkg;
    extern QString DarkThemeGameBkg;

    // Steps images
    extern QString stepsPath;


    // Pieces images
    extern QString piecesPath;

    extern QString AlphaPath;
    extern QString CaliforniaPath;
    extern QString CardinalPath;
    extern QString CasesPath;
    extern QString CburnettPath;
    extern QString Chess7Path;
    extern QString CondalPath;
    extern QString FrescaPath;
    extern QString GameRoomPath;
    extern QString GlassPath;
    extern QString ICPiecesPath;
    extern QString LolzPath;
    extern QString MaestroPath;
    extern QString MeridaPath;
    extern QString NeoPath;
    extern QString OceanPath;


    // Menus images
    extern QString menusPath;

    // Settings images
    extern QString settingsPath;
    extern QString settingsBoardsPath;
    extern QString settingsPiecesSetsPath;

    // PVP menu
    extern QString pvpPath;

    extern QString LightStartButtonsPath;
    extern QString LightBullet1MButton;
    extern QString LightBlitz3MButton;
    extern QString LightBlitz3MInc2SecButton;
    extern QString LightBlitz5MButton;
    extern QString LightBlitz10MButton;
    extern QString LightRapid15MButton;
    extern QString LightBlackColorButton;
    extern QString LightRandomColorButton;
    extern QString LightWhiteColorButton;
    extern QString LightReturnButton;

    extern QString LightHoverStartButtonsPath;
    extern QString LightBullet1MHoverButton;
    extern QString LightBlitz3MHoverButton;
    extern QString LightBlitz3MInc2SecHoverButton;
    extern QString LightBlitz5MHoverButton;
    extern QString LightBlitz10MHoverButton;
    extern QString LightRapid15MHoverButton;
    extern QString LightBlackColorHoverButton;
    extern QString LightRandomColorHoverButton;
    extern QString LightWhiteColorHoverButton;

    extern QString DarkStartButtonsPath;
    extern QString DarkBullet1MButton;
    extern QString DarkBlitz3MButton;
    extern QString DarkBlitz3MInc2SecButton;
    extern QString DarkBlitz5MButton;
    extern QString DarkBlitz10MButton;
    extern QString DarkRapid15MButton;
    extern QString DarkBlackColorButton;
    extern QString DarkRandomColorButton;
    extern QString DarkWhiteColorButton;
    extern QString DarkReturnButton;

    extern QString DarkHoverStartButtonsPath;
    extern QString DarkBullet1MHoverButton;
    extern QString DarkBlitz3MHoverButton;
    extern QString DarkBlitz3MInc2SecHoverButton;
    extern QString DarkBlitz5MHoverButton;
    extern QString DarkBlitz10MHoverButton;
    extern QString DarkRapid15MHoverButton;
    extern QString DarkBlackColorHoverButton;
    extern QString DarkRandomColorHoverButton;
    extern QString DarkWhiteColorHoverButton;
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
    extern QString lightBoldDimTextStyle;
    extern QString darkBoldDimTextStyle;

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
    extern QString lightQuickGamesTextStyle;
    extern QString darkQuickGamesTextStyle;
    extern QString lightQuickGamesButtonStyle;
    extern QString darkQuickGamesButtonStyle;
    extern QString lightQuickGamesHoverButtonStyle;
    extern QString darkQuickGamesHoverButtonStyle;
    extern QString darkColorButtonStyle;
    extern QString lightVariantComboboxStyle;
    extern QString darkVariantComboboxStyle;
}

#endif // HELPERS_HPP
