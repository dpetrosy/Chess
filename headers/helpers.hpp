#ifndef HELPERS_HPP
#define HELPERS_HPP

enum class MainWindowProps
{
    windowSizeW = 1000,
    windowSizeH = 600,
};

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

enum class QuitDialogProps
{
    windowSizeW = 444,
    windowSizeH = 130
};




//enum class GameWidgetProps
//{
//    BoardLeftUpCornerX = 10,
//    BoardLeftUpCornerY = 7,
//    BoardSizeHorizontal = 650,
//    BoardSizeVertical = 157
//};

#endif // HELPERS_HPP
