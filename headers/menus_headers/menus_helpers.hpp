#ifndef MENUS_HELPERS_HPP
#define MENUS_HELPERS_HPP

#include "helpers.hpp"
#include "predefined_menu_classes.hpp"

enum class Menus : int
{
    MainMenu = 0,
    PVPMenu = 1,
    SettingsMenu = 0
};


// MainMenu
enum class MainMenuProps
{
    // Layouts Properties
    verLayoutW = ((int)MainWindowProps::windowSizeW / 10) * 4,
    verLayoutH = (int)MainWindowProps::windowSizeH / 4,
    verLayoutX = ((int)MainWindowProps::windowSizeW - verLayoutW) / 2,
    horLayoutX = verLayoutX,
    horLayoutW = verLayoutW,
    horLayoutH = verLayoutH / 3 + 2,
    verLayoutY = ((int)MainWindowProps::windowSizeH - (verLayoutH + horLayoutH + 20)) / 2,
    horLayoutY = verLayoutY + verLayoutH + 6,

    // PushButtons Properties
    verLayoutButtonsW = 0,
    verLayoutButtonsH = 55,
    verLayoutButtonsFont = 24,
    horLayoutButtonsW = verLayoutButtonsW,
    horLayoutButtonsH = verLayoutButtonsH,
    horLayoutButtonsFont = verLayoutButtonsFont,
};

enum class MainMenuPushButtons
{
    PVPButton = 1,
    PVCButton = 2,
    InstrButton = 3,
    SettingsButton = 4,
    QuitButton = 5
};

enum class MainMenuStackedWidgets
{
    PVPStackedWidget = 1,
    PVCStackedWidget = 2,
    InstrStackedWidget = 3,
    SettingsStackedWidget = 4
};


// PVPMenu
enum class PVPMenuProps
{
    // PushButtons Properties
    PlayButtonX = (int)MainMenuProps::verLayoutX,
    PlayButtonY = (int)MainMenuProps::verLayoutY,
    PlayButtonW = (int)MainMenuProps::horLayoutW,
    PlayButtonH = (int)MainMenuProps::horLayoutH,
    PlayButtonFont = (int)MainMenuProps::horLayoutButtonsFont,
    ReturnButtonX = PlayButtonX,
    ReturnButtonY = PlayButtonY + PlayButtonH + 10,
    ReturnButtonW = PlayButtonW,
    ReturnButtonH = PlayButtonH,
    ReturnButtonFont = PlayButtonFont
};

enum class PVPMenuPushButtons
{
    PlayButton = 1,
    ReturnButton = 2
};


// SettingsMenu
enum class SettingsMenuProps
{
    BkgLabelW = 500,
    BkgLabelH = 520,
    BkgLabelX = ((int)MainWindowProps::windowSizeW - BkgLabelW) / 2,
    BkgLabelY = ((int)MainWindowProps::windowSizeH - BkgLabelH) / 2,
    BoardLabelX = BkgLabelX + 10,
    BoardLabelY = BkgLabelY + 10,
    BoardLabelW = BkgLabelW - 20,
    BoardLabelH = 150,
    BkgImageTextLabelX = BoardLabelX,
    BkgImageTextLabelY = BoardLabelY + BoardLabelH + 15,
    BkgImageTextLabelW = BoardLabelW / 2,
    BkgImageTextLabelH = 30,
    BkgImageComboBoxX = BoardLabelX + (BoardLabelW / 2),
    BkgImageComboBoxY = BkgImageTextLabelY,
    BkgImageComboBoxW = BkgImageTextLabelW,
    BkgImageComboBoxH = BkgImageTextLabelH,
    PieceSetTextLabelX = BkgImageTextLabelX,
    PieceSetTextLabelY = BkgImageTextLabelY + BkgImageTextLabelH + 15,
    PieceSetTextLabelW = BkgImageTextLabelW,
    PieceSetTextLabelH = BkgImageTextLabelH,
    PieceSetComboBoxX = BkgImageComboBoxX,
    PieceSetComboBoxY = PieceSetTextLabelY,
    PieceSetComboBoxW = BkgImageComboBoxW,
    PieceSetComboBoxH = BkgImageComboBoxH,
    BoardTextLabelX = BkgImageTextLabelX,
    BoardTextLabelY = PieceSetTextLabelY + PieceSetTextLabelH + 15,
    BoardTextLabelW = BkgImageTextLabelW,
    BoardTextLabelH = BkgImageTextLabelH,
    BoardComboBoxX = BkgImageComboBoxX,
    BoardComboBoxY = BoardTextLabelY,
    BoardComboBoxW = BkgImageComboBoxW,
    BoardComboBoxH = BkgImageComboBoxH,
    LanguageTextLabelX = BkgImageTextLabelX,
    LanguageTextLabelY = BoardTextLabelY + BoardTextLabelH + 15,
    LanguageTextLabelW = BkgImageTextLabelW,
    LanguageTextLabelH = BkgImageTextLabelH,
    LanguageComboBoxX = BkgImageComboBoxX,
    LanguageComboBoxY = LanguageTextLabelY,
    LanguageComboBoxW = BkgImageComboBoxW,
    LanguageComboBoxH = BkgImageComboBoxH,
    SoundTextLabelX = BkgImageTextLabelX,
    SoundTextLabelY = LanguageTextLabelY + LanguageTextLabelH + 15,
    SoundTextLabelW = BkgImageTextLabelW,
    SoundTextLabelH = BkgImageTextLabelH,
    SoundToggleSwitchX = BkgImageComboBoxX + 185,
    SoundToggleSwitchY = SoundTextLabelY,
    ThemeTextLabelX = BkgImageTextLabelX,
    ThemeTextLabelY = SoundTextLabelY + SoundTextLabelH + 15,
    ThemeTextLabelW = BkgImageTextLabelW,
    ThemeTextLabelH = BkgImageTextLabelH,
    ThemeToggleSwitchX = BkgImageComboBoxX + 185,
    ThemeToggleSwitchY = ThemeTextLabelY,
    ButtonsBkgLabelX = BkgLabelX,
    ButtonsBkgLabelY = ThemeTextLabelY + ThemeTextLabelH + 15,
    ButtonsBkgLabelW = BkgLabelW,
    ButtonsBkgLabelH = 90,
    CancelButtonX = ButtonsBkgLabelX + 16,
    CancelButtonY = ButtonsBkgLabelY + 15,
    CancelButtonW = 225,
    CancelButtonH = 60,
    SaveButtonX = CancelButtonX + CancelButtonW + 18,
    SaveButtonY = CancelButtonY,
    SaveButtonW = CancelButtonW,
    SaveButtonH = CancelButtonH
};

struct SettingsData
{
    QString bkgImageStr = "1";
    QString piecesSetStr = "1";
    QString boardStr = "1";
    QString languageStr = "eng";
    bool isSoundAvailable = false;
    bool isDarkTheme = true;
};

enum class SettingsMenuPushButtons
{
    CancelButton = 1,
    SaveButton = 2,
};

namespace BackgroundImages
{
    extern QString Extencion;
    extern QString AngelView;
    extern QString Blacked;
    extern QString BravePawn;
    extern QString Checkmate;
    extern QString Dark_Chess;
    extern QString Emperors;
    extern QString FaceToFace;
    extern QString IAmTheKing;
    extern QString Lichess;
    extern QString Shadow;
    extern QString StrongKnight;
    extern QString TheBishop;
    extern QString TheKing;
    extern QString TheKnight;
    extern QString TheQueen;
    extern QString TheRook;
    extern QString TopView;
}

namespace Languages
{
    extern QString Armenian;
    extern QString Russian;
    extern QString English;
}

// #Delete#
// QuitDialog
//enum class QuitDialogProps
//{
//    windowSizeW = 430,
//    windowSizeH = 130,
//    quitImageX = (int)windowSizeW - 410,
//    quitImageY = (int)windowSizeH - 106,
//    quitTextX = quitImageX + 122,
//    quitTextY = quitImageY,
//    quitTextW = windowSizeW - 150,
//    quitTextH = 30,
//    quitButtonBoxX = quitTextX + 52,
//    quitButtonBoxY = quitTextY + 55,
//    quitButtonBoxW = windowSizeW / 2,
//    quitButtonBoxH = windowSizeH / 4
//};

#endif // MENUS_HELPERS_HPP
