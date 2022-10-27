#ifndef MENUS_HELPERS_HPP
#define MENUS_HELPERS_HPP

#include "helpers.hpp"
#include "predefined_menu_classes.hpp"

enum class Menus : int
{
    QuitMenu = -1,
    MainMenu = 0,
    PVPMenu = 1,
};


// MainMenu
enum class MainMenuProps
{
    // Layouts Properties
    verLayoutX = (int)MainWindowProps::windowSizeW / 2 - 165,
    verLayoutY = (int)MainWindowProps::windowSizeH / 2 - 150,
    verLayoutW = (int)MainWindowProps::windowSizeW / 3,
    verLayoutH = (int)MainWindowProps::windowSizeH / 4,
    horLayoutX = verLayoutX,
    horLayoutY = verLayoutY + verLayoutH - 10,
    horLayoutW = verLayoutW,
    horLayoutH = verLayoutH / 3,

    // PushButtons Properties
    verLayoutButtonsW = 0,
    verLayoutButtonsH = 40,
    verLayoutButtonsFont = 15,
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


// QuitDialog
enum class QuitDialogProps
{
    windowSizeW = 430,
    windowSizeH = 130,
    quitImageX = (int)windowSizeW - 410,
    quitImageY = (int)windowSizeH - 106,
    quitTextX = quitImageX + 122,
    quitTextY = quitImageY,
    quitTextW = windowSizeW - 150,
    quitTextH = 30,
    quitButtonBoxX = quitTextX + 52,
    quitButtonBoxY = quitTextY + 55,
    quitButtonBoxW = windowSizeW / 2,
    quitButtonBoxH = windowSizeH / 4
};

#endif // MENUS_HELPERS_HPP