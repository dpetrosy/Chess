#ifndef MENUS_HELPERS_HPP
#define MENUS_HELPERS_HPP

#include "helpers.hpp"
#include "predefined_menu_classes.hpp"

enum class Menus : int
{
    MainMenu = 0,
    PVPMenu = 1,
    OptionsMenu = 0
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
    OptionsButton = 4,
    QuitButton = 5
};

enum class MainMenuStackedWidgets
{
    PVPStackedWidget = 1,
    PVCStackedWidget = 2,
    InstrStackedWidget = 3,
    OptionsStackedWidget = 4
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


// OptionsMenu
enum class OptionsMenuProps
{
    BkgLabelW = 500,
    BkgLabelH = 600,
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






};


struct OptionsData
{
    bool isDarkMode = false;
    QString boardStr = "1";
    QString piecesSetsStr = "1";
};

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
