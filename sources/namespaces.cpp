#include "helpers.hpp"

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

namespace Paths
{
    QString stylesPath = ":/styles/";
    QString pawnPromButtonsStyle = stylesPath + "pawn_prom_buttons_style.txt";
    QString darkThemeBkgLabelStyle = stylesPath + "dark_theme_bkg_label.txt";
    QString lightThemeBkgLabelStyle = stylesPath + "light_theme_bkg_label.txt";

    QString lightThemeButtonsLabelStyle = stylesPath + "light_theme_buttons_label.txt";

    QString settingsMenuCancelButtonStyle = stylesPath + "settings_menu_cancel_button.txt";
    QString settingsMenuSaveButtonStyle = stylesPath + "settings_menu_save_button.txt";
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
    QString Lichess = "Lichess";
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
