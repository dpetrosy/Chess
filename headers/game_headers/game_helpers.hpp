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
    BoardX = 10,
    BoardY = 7,
    BoardW = 650,
    BoardH = 157
};

#endif // GAME_HELPERS_HPP
