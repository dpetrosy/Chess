#include "helpers.hpp"

bool globalIsDarkTheme = false;

// Images
namespace ImagesPaths
{
    QString imagesPath = ":/images/images/";
    QString piecesPath = imagesPath + "pieces/";
    QString logosPath = imagesPath + "logos/";
    QString backgroundsPath = imagesPath + "backgrounds/";
    QString boardsPath = imagesPath + "boards/";

    // Menus images
    QString menusPath = imagesPath + "menus/";

    // Settings menu
    QString settingsPath = menusPath + "settings/";
    QString settingsBoardsPath = settingsPath + "boards/";
    QString settingsPiecesSetsPath = settingsPath + "pieces_sets/";

    // PVP menu
    QString pvpPath = menusPath + "pvp/";

    QString LightQuickGamesPath = pvpPath + "light_quick_games/";
    QString LightBullet1MButton = LightQuickGamesPath + "bullet_1M.png";
    QString LightBlitz3MButton = LightQuickGamesPath + "blitz_3M.png";
    QString LightBlitz3MInc2SecButton = LightQuickGamesPath + "blitz_3M_inc2sec.png";
    QString LightBlitz5MButton = LightQuickGamesPath + "blitz_5M.png";
    QString LightBlitz10MButton = LightQuickGamesPath + "blitz_10M.png";
    QString LightRapid15MButton = LightQuickGamesPath + "rapid_15M.png";

    QString LightHoverQuickGamesPath = pvpPath + "light_hover_quick_games/";
    QString LightBullet1MHoverButton = LightHoverQuickGamesPath + "bullet_1M_hover.png";
    QString LightBlitz3MHoverButton = LightHoverQuickGamesPath + "blitz_3M_hover.png";
    QString LightBlitz3MInc2SecHoverButton = LightHoverQuickGamesPath + "blitz_3M_inc2sec_hover.png";
    QString LightBlitz5MHoverButton = LightHoverQuickGamesPath + "blitz_5M_hover.png";
    QString LightBlitz10MHoverButton = LightHoverQuickGamesPath + "blitz_10M_hover.png";
    QString LightRapid15MHoverButton = LightHoverQuickGamesPath + "rapid_15M_hover.png";

    QString DarkQuickGamesPath = pvpPath + "dark_quick_games/";
    QString DarkBullet1MButton = DarkQuickGamesPath + "bullet_1M.png";
    QString DarkBlitz3MButton = DarkQuickGamesPath + "blitz_3M.png";
    QString DarkBlitz3MInc2SecButton = DarkQuickGamesPath + "blitz_3M_inc2sec.png";
    QString DarkBlitz5MButton = DarkQuickGamesPath + "blitz_5M.png";
    QString DarkBlitz10MButton = DarkQuickGamesPath + "blitz_10M.png";
    QString DarkRapid15MButton = DarkQuickGamesPath + "rapid_15M.png";

    QString DarkHoverQuickGamesPath = pvpPath + "dark_hover_quick_games/";
    QString DarkBullet1MHoverButton = DarkHoverQuickGamesPath + "bullet_1M_hover.png";
    QString DarkBlitz3MHoverButton = DarkHoverQuickGamesPath + "blitz_3M_hover.png";
    QString DarkBlitz3MInc2SecHoverButton = DarkHoverQuickGamesPath + "blitz_3M_inc2sec_hover.png";
    QString DarkBlitz5MHoverButton = DarkHoverQuickGamesPath + "blitz_5M_hover.png";
    QString DarkBlitz10MHoverButton = DarkHoverQuickGamesPath + "blitz_10M_hover.png";
    QString DarkRapid15MHoverButton = DarkHoverQuickGamesPath + "rapid_15M_hover.png";
}

namespace StepsImages
{
    QString CanGo = ImagesPaths::piecesPath + "can_go.png";
    QString CanBeat = ImagesPaths::piecesPath + "can_beat.png";
    QString CurrentPiece = ImagesPaths::piecesPath + "current_piece.png";
    QString LastStepFrom = ImagesPaths::piecesPath + "last_step_from.png";
    QString LastStepTo = ImagesPaths::piecesPath + "last_step_to.png";
    QString LastStepFromAndCanGo = ImagesPaths::piecesPath + "last_step_from_can_go.png";
    QString Check = ImagesPaths::piecesPath + "check.png";
    QString CurrentPieceAndChecked = ImagesPaths::piecesPath + "current_piece_and_checked.png";
}


// Paths
namespace StylesPaths
{
    QString stylesPath = ":/styles/";

    // General for menus
    QString MenusStylesPath = stylesPath + "menus_styles/";
    QString lightThemeBkgLabelStyle = MenusStylesPath + "light_theme_bkg_label.txt";
    QString darkThemeBkgLabelStyle = MenusStylesPath + "dark_theme_bkg_label.txt";
    QString lightTextStyle = MenusStylesPath + "light_text.txt";
    QString darkTextStyle = MenusStylesPath + "dark_text.txt";
    QString lightBoldTextStyle = MenusStylesPath + "light_bold_text.txt";
    QString darkBoldTextStyle = MenusStylesPath + "dark_bold_text.txt";
    QString lightComboBoxStyle = MenusStylesPath + "light_combobox.txt";
    QString darkComboBoxStyle = MenusStylesPath + "dark_combobox.txt";
    QString lightSliderStyle = MenusStylesPath + "light_slider.txt";
    QString darkSliderStyle = MenusStylesPath + "dark_slider.txt";
    QString lightDimTextStyle = MenusStylesPath + "light_dim_text.txt";
    QString darkDimTextStyle = MenusStylesPath + "dark_dim_text.txt";
    QString lightBoldDimTextStyle = MenusStylesPath + "light_bold_dim_text.txt";
    QString darkBoldDimTextStyle = MenusStylesPath + "dark_bold_dim_text.txt";

    // Settings menu
    QString SettingsMenuStylesPath = MenusStylesPath + "settings_menu_styles/";
    QString hideAndShowButtonStyle = SettingsMenuStylesPath + "hide_and_show_button.txt";
    QString lightThemeButtonsLabelStyle = SettingsMenuStylesPath + "light_theme_buttons_label.txt";
    QString darkThemeButtonsLabelStyle = SettingsMenuStylesPath + "dark_theme_buttons_label.txt";
    QString settingsMenuLightCancelButtonStyle = SettingsMenuStylesPath + "settings_menu_light_cancel_button.txt";
    QString settingsMenuDarkCancelButtonStyle = SettingsMenuStylesPath + "settings_menu_dark_cancel_button.txt";
    QString settingsMenuSaveButtonStyle = SettingsMenuStylesPath + "settings_menu_save_button.txt";

    // PVP menu
    QString PVPMenuStylesPath = MenusStylesPath + "pvp_menu_styles/";
    QString lightTopTextStyle = PVPMenuStylesPath + "light_top_text.txt";
    QString darkTopTextStyle = PVPMenuStylesPath + "dark_top_text.txt";
    QString lightTimeControlBkgLabelStyle = PVPMenuStylesPath + "light_time_control_bkg_label.txt";
    QString darkTimeControlBkgLabelStyle = PVPMenuStylesPath + "dark_time_control_bkg_label.txt";
    QString lightQuickGamesTextStyle = PVPMenuStylesPath + "light_quick_games_text.txt";
    QString darkQuickGamesTextStyle = PVPMenuStylesPath + "dark_quick_games_text.txt";
    QString lightQuickGamesButtonStyle = PVPMenuStylesPath + "light_quickgames_button.txt";
    QString darkQuickGamesButtonStyle = PVPMenuStylesPath + "dark_quickgames_button.txt";
    QString lightQuickGamesHoverButtonStyle = PVPMenuStylesPath + "light_quickgames_hover_button.txt";
    QString darkQuickGamesHoverButtonStyle = PVPMenuStylesPath + "dark_quickgames_hover_button.txt";



    //QString pawnPromButtonsStyle = MenusStylesPath + "pawn_prom_buttons_style.txt";
}


// PVP Menu
namespace GameVariants
{
    QString Standart = "Standart";
};

namespace QuickGames
{
    QString NoSelected = "NoSelected";
    QString Bullet1M = "Bullet1M";
    QString Blitz3M = "Blitz3M";
    QString Blitz3MInc2Sec = "Blitz3MInc2Sec";
    QString Blitz5M = "Blitz5M";;
    QString Blitz10M = "Blitz10M";;
    QString Rapid15M = "Rapid15M";;
}


// Settings menu
namespace BackgroundImages
{
    QString Extencion = ".jpg";
    QString AngelView = "Angel_View";
    QString Blacked = "Blacked";
    QString BravePawn = "Brave_Pawn";
    QString Checkmate = "Checkmate";
    QString Dark_Chess = "Dark_Chess";
    QString Emperors = "Emperors";
    QString FaceToFace = "Face_to_Face";
    QString IAmTheKing = "I_am_the_King";
    QString Landscape = "Landscape";
    QString Shadow = "Shadow";
    QString StrongKnight = "Strong_Knight";
    QString TheBishop = "The_Bishop";
    QString TheKing = "The_King";
    QString TheKnight = "The_Knight";
    QString TheQueen = "The_Queen";
    QString TheRook = "The_Rook";
    QString TopView = "Top_View";
}

namespace Languages
{
    QString Armenian = "Հայերեն";
    QString Russian = "Русский";
    QString English = "English (US)";
}
