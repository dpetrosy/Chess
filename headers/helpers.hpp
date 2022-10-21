#ifndef HELPERS_HPP
#define HELPERS_HPP

#include <QString>

enum class MainWindowProps
{
    windowSizeW = 1000,
    windowSizeH = 600,
};

namespace ImagesPaths
{
    extern QString imagesPath;
    extern QString piecesPath;
    extern QString logosPath;
    extern QString backgroundsPath;
}

//enum class GameWidgetProps
//{
//    BoardLeftUpCornerX = 10,
//    BoardLeftUpCornerY = 7,
//    BoardSizeHorizontal = 650,
//    BoardSizeVertical = 157
//};

#endif // HELPERS_HPP
