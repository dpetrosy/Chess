#ifndef GAME_HELPERS_HPP
#define GAME_HELPERS_HPP

#include "pieces_helpers.hpp"
#include "predefined_game_classes.hpp"

// Game data
enum class GameVariants
{
    Standart = 1
};

enum class QuickGames
{
    NoSelected = 0
};

struct GameData
{
    GameVariants gameVariant = GameVariants::Standart;
    QuickGames quickGame = QuickGames::NoSelected;
    bool isTimeAvailable = false;
    unsigned gameMinutes = 0;
    unsigned incrementSeconds = 0;
    PiecesColors belowPlayerColor = PiecesColors::White;
};


// Board Widget
enum class BoardWidgetProps
{
    BoardSquaresCount = 8,
    BoardX = 7,
    BoardY = BoardX,
    BoardW = 574,
    BoardH = BoardW,
    PieceW = BoardW / 8,
    PieceH = PieceW
};


// PawnProm Dialog
enum class PawnPromDialogProps
{
    windowSizeW = 355,
    windowSizeH = 100,
    QueenPosX = 12,
    QueenPosY = 15,
    RookPosX = QueenPosX + (int)BoardWidgetProps::PieceW + 15,
    RookPosY = QueenPosY,
    BishopPosX = RookPosX + (int)BoardWidgetProps::PieceW + 15,
    BishopPosY = RookPosY,
    KnightPosX = BishopPosX + (int)BoardWidgetProps::PieceW + 15,
    KnightPosY = BishopPosY
};

#endif // GAME_HELPERS_HPP
