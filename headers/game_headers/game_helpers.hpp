#ifndef GAME_HELPERS_HPP
#define GAME_HELPERS_HPP

#include "pieces_helpers.hpp"
#include "menus_helpers.hpp"
#include "predefined_game_classes.hpp"

// Game Widget
struct GameData
{
    QString gameVariant = GameVariants::Standard;
    bool isTimeAvailable = true;
    double gameMinutes = 10;
    int incrementSeconds = 0;
    QString quickGame = StartGameButtonName::NoSelected;
    PiecesColors belowPlayerColor = PiecesColors::White;

    QString pieceSet = PieceSets::Cburnett;
};

// Board Widget
enum class BoardWidgetProps
{
    BoardSquaresCount = 8,
    BoardLabelX = 10,
    BoardLabelY = BoardLabelX,
    BoardLabelW = 680,
    BoardLabelH = BoardLabelW,
    BoardWidgetX = 1,
    BoardWidgetY = BoardWidgetX,
    BoardWidgetW = 698,
    BoardWidgetH = BoardWidgetW,
    PieceLabelW = BoardWidgetW / 8,
    PieceLabelH = PieceLabelW
};


// PawnProm Dialog
enum class PawnPromDialogProps
{
    windowSizeW = 355,
    windowSizeH = 100,
    QueenPosX = 12,
    QueenPosY = 15,
    RookPosX = QueenPosX + (int)BoardWidgetProps::PieceLabelW + 15,
    RookPosY = QueenPosY,
    BishopPosX = RookPosX + (int)BoardWidgetProps::PieceLabelW + 15,
    BishopPosY = RookPosY,
    KnightPosX = BishopPosX + (int)BoardWidgetProps::PieceLabelW + 15,
    KnightPosY = BishopPosY
};

#endif // GAME_HELPERS_HPP
