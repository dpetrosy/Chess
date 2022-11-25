#include "helpers.hpp"

// Images
namespace ImagesPaths
{
    QString imagesPath = ":/images/images/";
    QString piecesPath = imagesPath + "pieces/";
    QString logosPath = imagesPath + "logos/";
    QString backgroundsPath = imagesPath + "backgrounds/";
    QString boardsPath = imagesPath + "boards/";
    QString settingsPath = imagesPath + "settings/";
    QString settingsBoardsPath = ImagesPaths::settingsPath + "boards/";
    QString settingsPiecesSetsPath = ImagesPaths::settingsPath + "pieces_sets/";
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
    QString darkThemeBkgLabelStyle = MenusStylesPath + "dark_theme_bkg_label.txt";
    QString lightThemeBkgLabelStyle = MenusStylesPath + "light_theme_bkg_label.txt";
    QString darkThemeTextStyle = MenusStylesPath + "dark_theme_text.txt";
    QString lightThemeTextStyle = MenusStylesPath + "light_theme_text.txt";
    QString darkComboBoxStyle = MenusStylesPath + "dark_combobox.txt";
    QString lightComboBoxStyle = MenusStylesPath + "light_combobox.txt";

    // Settings menu
    QString SettingsMenuStylesPath = MenusStylesPath + "settings_menu_styles/";
    QString darkThemeButtonsLabelStyle = SettingsMenuStylesPath + "dark_theme_buttons_label.txt";
    QString hideAndShowButtonStyle = SettingsMenuStylesPath + "hide_and_show_button.txt";
    QString lightThemeButtonsLabelStyle = SettingsMenuStylesPath + "light_theme_buttons_label.txt";
    QString settingsMenuDarkCancelButtonStyle = SettingsMenuStylesPath + "settings_menu_dark_cancel_button.txt";
    QString settingsMenuLightCancelButtonStyle = SettingsMenuStylesPath + "settings_menu_light_cancel_button.txt";
    QString settingsMenuSaveButtonStyle = SettingsMenuStylesPath + "settings_menu_save_button.txt";




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
