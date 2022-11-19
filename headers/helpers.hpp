#ifndef HELPERS_HPP
#define HELPERS_HPP

#include <QString>

enum class MainWindowProps
{
    windowSizeW = 1225,
    windowSizeH = 820,
};

enum class Backgrounds
{
    Background = 0,
    Board = 1
};

namespace ImagesPaths
{
    extern QString imagesPath;
    extern QString piecesPath;
    extern QString logosPath;
    extern QString backgroundsPath;
    extern QString boardsPath;
    extern QString optionsPath;
    extern QString optionsBoardsPath;
    extern QString optionsPiecesSetsPath;
}

namespace Paths
{
    extern QString stylesPath;
}

#endif // HELPERS_HPP
