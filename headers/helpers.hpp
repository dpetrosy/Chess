#ifndef HELPERS_HPP
#define HELPERS_HPP

enum class MainWindowProps
{
    windowSizeW = 1000,
    windowSizeH = 600,
};

enum class MainMenuProps
{
    verLayoutX = (int)MainWindowProps::windowSizeW / 2 - 165,
    verLayoutY = (int)MainWindowProps::windowSizeH / 2 - 150,
    verLayoutW = (int)MainWindowProps::windowSizeW / 3,
    verLayoutH = (int)MainWindowProps::windowSizeH / 4,
    horLayoutX = 450,
    horLayoutY = 450,
    horLayoutW = 100,
    horLayoutH = 100,
};

//enum class QuitDialogProps
//{
//    windowSizeW = 444,
//    windowSizeH = 130
//};

//enum class GameWidgetProps
//{
//    BoardLeftUpCornerX = 10,
//    BoardLeftUpCornerY = 7,
//    BoardSizeHorizontal = 650,
//    BoardSizeVertical = 157
//};

#endif // HELPERS_HPP
