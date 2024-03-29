#ifndef GAME_HELPERS_HPP
#define GAME_HELPERS_HPP

#include "pieces_helpers.hpp"
#include "menus_helpers.hpp"

// Game Widget
enum class GamwWidgetProps
{
    ReturnButtonW = 35,
    ReturnButtonH = 28,
    ReturnButtonX = (int)MainWindowProps::windowSizeW - ReturnButtonW - 13,
    ReturnButtonY =  (int)MainWindowProps::windowSizeH - ReturnButtonH - 12
};

struct GameData
{
    QString gameVariant = GameVariants::Standard;
    bool isTimeAvailable = true;
    double gameMinutes = 10;
    int incrementSeconds = 0;
    QString quickGame = StartGameButtonName::NoSelected;
    PiecesColors belowPlayerColor = PiecesColors::White;

    QString pieceSet = PieceSets::Cburnett;
    QString board = Boards::Brown;
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
    PieceLabelH = PieceLabelW,
};


// Moves Widget
enum class MovesWidgetProps
{
    ScrollW = 332,
    ScrollH = 300,
    ScrollX = 690 + 14,
    ScrollY = 200,
    WidgetW = ScrollW - 20,
    WidgetH = 0,
    WidgetX = 0,
    WidgetY = 0,
    NumberLabelX = 0,
    NumberLabelY = 0,
    NumberLabelW = 60,
    NumberLabelH = 30
};

namespace PieceSymbolsForMove
{
    extern QString WhitePawn;
    extern QString WhiteKnight;
    extern QString WhiteBishop;
    extern QString WhiteRook;
    extern QString WhiteQueen;
    extern QString WhiteKing;
    extern QString BlackPawn;
    extern QString BlackKinght;
    extern QString BlackBishop;
    extern QString BlackRook;
    extern QString BlackQueen;
    extern QString BlackKing;
}


// PawnProm Dialog
enum class PawnPromDialogProps
{
    windowSizeW = 415,
    windowSizeH = 115,
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
