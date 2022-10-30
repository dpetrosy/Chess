#ifndef GAME_HELPERS_HPP
#define GAME_HELPERS_HPP

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
    bool isTimeAvailable = false;
    unsigned gameMinutes = 0;
    unsigned incrementSeconds = 0;
    bool isWhite = true;
    QuickGames quickGame = QuickGames::NoSelected;
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

//BoardX = 12,
//BoardY = 9,
//BoardW = 650,
//BoardH = 580

#endif // GAME_HELPERS_HPP
