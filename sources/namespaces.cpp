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
    QString returnButtonPath = pvpPath + "return_button/";

    QString LightStartButtonsPath = pvpPath + "light_start_buttons/";
    QString LightBullet1MButton = LightStartButtonsPath + "bullet_1M.png";
    QString LightBlitz3MButton = LightStartButtonsPath + "blitz_3M.png";
    QString LightBlitz3MInc2SecButton = LightStartButtonsPath + "blitz_3M_inc2sec.png";
    QString LightBlitz5MButton = LightStartButtonsPath + "blitz_5M.png";
    QString LightBlitz10MButton = LightStartButtonsPath + "blitz_10M.png";
    QString LightRapid15MButton = LightStartButtonsPath + "rapid_15M.png";
    QString LightBlackColorButton = LightStartButtonsPath + "black_color.png";
    QString LightRandomColorButton = LightStartButtonsPath + "random_color.png";
    QString LightWhiteColorButton = LightStartButtonsPath + "white_color.png";
    QString LightReturnButton = returnButtonPath + "light_return_button.png";

    QString LightHoverStartButtonsPath = pvpPath + "light_hover_start_buttons/";
    QString LightBullet1MHoverButton = LightHoverStartButtonsPath + "bullet_1M_hover.png";
    QString LightBlitz3MHoverButton = LightHoverStartButtonsPath + "blitz_3M_hover.png";
    QString LightBlitz3MInc2SecHoverButton = LightHoverStartButtonsPath + "blitz_3M_inc2sec_hover.png";
    QString LightBlitz5MHoverButton = LightHoverStartButtonsPath + "blitz_5M_hover.png";
    QString LightBlitz10MHoverButton = LightHoverStartButtonsPath + "blitz_10M_hover.png";
    QString LightRapid15MHoverButton = LightHoverStartButtonsPath + "rapid_15M_hover.png";
    QString LightBlackColorHoverButton = LightHoverStartButtonsPath + "black_color_hover.png";
    QString LightRandomColorHoverButton = LightHoverStartButtonsPath + "random_color_hover.png";
    QString LightWhiteColorHoverButton = LightHoverStartButtonsPath + "white_color_hover.png";

    QString DarkStartButtonsPath = pvpPath + "dark_start_buttons/";
    QString DarkBullet1MButton = DarkStartButtonsPath + "bullet_1M.png";
    QString DarkBlitz3MButton = DarkStartButtonsPath + "blitz_3M.png";
    QString DarkBlitz3MInc2SecButton = DarkStartButtonsPath + "blitz_3M_inc2sec.png";
    QString DarkBlitz5MButton = DarkStartButtonsPath + "blitz_5M.png";
    QString DarkBlitz10MButton = DarkStartButtonsPath + "blitz_10M.png";
    QString DarkRapid15MButton = DarkStartButtonsPath + "rapid_15M.png";
    QString DarkBlackColorButton = DarkStartButtonsPath + "black_color.png";
    QString DarkRandomColorButton = DarkStartButtonsPath + "random_color.png";
    QString DarkWhiteColorButton = DarkStartButtonsPath + "white_color.png";
    QString DarkReturnButton = returnButtonPath + "dark_return_button.png";

    QString DarkHoverStartButtonsPath = pvpPath + "dark_hover_start_buttons/";
    QString DarkBullet1MHoverButton = DarkHoverStartButtonsPath + "bullet_1M_hover.png";
    QString DarkBlitz3MHoverButton = DarkHoverStartButtonsPath + "blitz_3M_hover.png";
    QString DarkBlitz3MInc2SecHoverButton = DarkHoverStartButtonsPath + "blitz_3M_inc2sec_hover.png";
    QString DarkBlitz5MHoverButton = DarkHoverStartButtonsPath + "blitz_5M_hover.png";
    QString DarkBlitz10MHoverButton = DarkHoverStartButtonsPath + "blitz_10M_hover.png";
    QString DarkRapid15MHoverButton = DarkHoverStartButtonsPath + "rapid_15M_hover.png";
    QString DarkBlackColorHoverButton = DarkHoverStartButtonsPath + "black_color_hover.png";
    QString DarkRandomColorHoverButton = DarkHoverStartButtonsPath + "random_color_hover.png";
    QString DarkWhiteColorHoverButton = DarkHoverStartButtonsPath + "white_color_hover.png";
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
    QString darkColorButtonStyle = PVPMenuStylesPath + "dark_color_button.txt";
    QString lightVariantComboboxStyle = PVPMenuStylesPath + "light_variant_combobox.txt";
    QString darkVariantComboboxStyle = PVPMenuStylesPath + "dark_variant_combobox.txt";



    //QString pawnPromButtonsStyle = MenusStylesPath + "pawn_prom_buttons_style.txt";
}


// PVP Menu
namespace GameVariants
{
    QString Standard = "Standard";
    QString Chess960 = "Chess960";
    QString KingOfTheHill = "King_of_the_Hill";
    QString ThreeCheck = "Three-check";
    QString Horde = "Horde";
    QString FromPosition = "From_Position";
};

namespace StartGameButtonName
{
    QString NoSelected = "NoSelected";
    QString Bullet1M = "Bullet1M";
    QString Blitz3M = "Blitz3M";
    QString Blitz3MInc2Sec = "Blitz3MInc2Sec";
    QString Blitz5M = "Blitz5M";
    QString Blitz10M = "Blitz10M";
    QString Rapid15M = "Rapid15M";
    QString BlackColor = "BlackColor";
    QString RandomColor = "RandomColor";
    QString WhiteColor = "WhiteColor";
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
