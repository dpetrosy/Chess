#include "helpers.hpp"

namespace ImagesPaths
{
    QString imagesPath = ":/images/images/";
    QString piecesPath = imagesPath + "pieces/";
    QString logosPath = imagesPath + "logos/";
    QString backgroundsPath = imagesPath + "backgrounds/";
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
}
