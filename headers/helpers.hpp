#ifndef HELPERS_HPP
#define HELPERS_HPP

#include <QString>

enum class MainWindowProps
{
    windowSizeW = 1005,
    windowSizeH = 587,
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
}

#endif // HELPERS_HPP
