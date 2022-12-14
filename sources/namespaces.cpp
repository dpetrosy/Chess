#include "helpers.hpp"

bool    globalIsDarkTheme = false;

QString globalPieceSetPath = ":/images/images/pieces/Cburnett/";

// Images
namespace ImagesPaths
{
    QString imagesPath = ":/images/images/";
    QString boardsPath = imagesPath + "boards/";

    // Logos images
    QString logosPath = imagesPath + "logos/";

    // Backgrounds images
    QString backgroundsPath = imagesPath + "backgrounds/";
    QString LightThemeGameBkg = "light_theme_game_bkg";
    QString DarkThemeGameBkg = "dark_theme_game_bkg";

    // Steps images
    QString stepsPath = imagesPath + "steps/";

    // Boards images

    // Pieces images
    QString piecesPath = imagesPath + "pieces/";

    QString AlphaPath = imagesPath + "Alpha";
    QString CaliforniaPath = imagesPath + "California";
    QString CardinalPath = imagesPath + "Cardinal";
    QString CasesPath = imagesPath + "Cases";
    QString CburnettPath = imagesPath + "Cburnett";
    QString Chess7Path = imagesPath + "Chess7";
    QString CondalPath = imagesPath + "Condal";
    QString FrescaPath = imagesPath + "Fresca";
    QString GameRoomPath = imagesPath + "Game_Room";
    QString GlassPath = imagesPath + "Glass";
    QString ICPiecesPath = imagesPath + "IC_Pieces";
    QString LolzPath = imagesPath + "Lolz";
    QString MaestroPath = imagesPath + "Maestro";
    QString MeridaPath = imagesPath + "Marida";
    QString NeoPath = imagesPath + "Neo";
    QString OceanPath = imagesPath + "Ocean";

    // Boards images
    QString BoardsPath = imagesPath + "boards/";
    QString WhiteBoardsPath = BoardsPath + "white/";
    QString BlackBoardsPath = BoardsPath + "black/";

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
    QString CanGo = ImagesPaths::stepsPath + "can_go.png";
    QString CanBeat = ImagesPaths::stepsPath + "can_beat.png";
    QString CurrentPiece = ImagesPaths::stepsPath + "current_piece.png";
    QString LastStepFrom = ImagesPaths::stepsPath + "last_step_from.png";
    QString LastStepTo = ImagesPaths::stepsPath + "last_step_to.png";
    QString LastStepFromAndCanGo = ImagesPaths::stepsPath + "last_step_from_can_go.png";
    QString Check = ImagesPaths::stepsPath + "check.png";
    QString CurrentPieceAndChecked = ImagesPaths::stepsPath + "current_piece_and_checked.png";
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

    // Main menu
    QString MainMenuStylesPath = MenusStylesPath + "main_menu_styles/";
    QString VersionTextStyle = MainMenuStylesPath + "version_text.txt";
    QString MainMenuButtonStyle = MainMenuStylesPath + "main_menu_button.txt";

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

    // Pieces styles
    QString PiecesStylesPath = stylesPath + "pieces_styles/";
    QString PawnPromButtonsStyle = PiecesStylesPath + "pawn_prom_buttons_style.txt";
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

    QString HordeSymbolsVector2D = \
    "rnbqkbnr\
     pppppppp\
     00000000\
     0PP00PP0\
     PPPPPPPP\
     PPPPPPPP\
     PPPPPPPP\
     PPPPPPPP";
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
    QString Legends = "Legends";
    QString Shadow = "Shadow";
    QString StrongKnight = "Strong_Knight";
    QString TheBishop = "The_Bishop";
    QString TheKing = "The_King";
    QString TheKnight = "The_Knight";
    QString TheQueen = "The_Queen";
    QString TheRook = "The_Rook";
    QString TopView = "Top_View";
}

namespace Boards
{
    QString Extencion = ".png";
    QString Bit8 = "8_Bit";
    QString Bases = "Bases";
    QString Blue = "Blue";
    QString Brown = "Brown";
    QString Bubblegum = "Bubblegum";
    QString BurledWood = "Burled_Wood";
    QString DarkWood = "Dark_Wood";
    QString Dash = "Dash";
    QString Glass = "Glass";
    QString Graffiti = "Graffiti";
    QString Green = "Green";
    QString IceSea = "Ice_Sea";
    QString Light = "Light";
    QString Lolz = "Lolz";
    QString Marble = "Marble";
    QString Metal = "Metal";
    QString Neon = "Neon";
    QString Newspaper = "Newspaper";
    QString Orange = "Orange";
    QString Parchment = "Parchment";
    QString Purple = "Purple";
    QString Red = "Red";
    QString Sand = "Sand";
    QString Sky = "Sky";
    QString Stone = "Stone";
    QString Tan = "Tan";
    QString Tournament = "Tournament";
    QString Translucent = "Translucent";
    QString Walnut = "Walnut";
}

namespace PieceSets
{
    QString Extencion = ".png";
    QString Alpha = "Alpha";
    QString California = "California";
    QString Cardinal = "Cardinal";
    QString Cases = "Cases";
    QString Cburnett = "Cburnett";
    QString Chess7 = "Chess7";
    QString Condal = "Condal";
    QString Fresca = "Fresca";
    QString GameRoom = "Game_Room";
    QString Glass = "Glass";
    QString ICPieces = "IC_Pieces";
    QString Lolz = "Lolz";
    QString Maestro = "Maestro";
    QString Merida = "Merida";
    QString Neo = "Neo";
    QString Ocean = "Ocean";
}

namespace Languages
{
    QString Armenian = "Հայերեն";
    QString Russian = "Русский";
    QString English = "English (US)";
}


// Moves Widget
namespace PieceSymbolsForMove
{
    QString WhitePawn = "♙";
    QString WhiteKnight = "♘";
    QString WhiteBishop = "♗";
    QString WhiteRook = "♖";
    QString WhiteQueen = "♕";
    QString WhiteKing = "♔";
    QString BlackPawn = "♟︎";
    QString BlackKinght = "♞";
    QString BlackBishop = "♝";
    QString BlackRook = "♜";
    QString BlackQueen = "♛";
    QString BlackKing = "♚";
}
