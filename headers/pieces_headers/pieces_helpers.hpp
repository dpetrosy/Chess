#ifndef PIECES_HELPERS_HPP
#define PIECES_HELPERS_HPP

#include "predefined_pieces_classes.hpp"

enum class Pieces
{
    Empty = 0,
    Pawn = 1,
    Knight = 2,
    Bishop = 3,
    Rook = 5,
    Queen = 10,
    King = 100
};

enum class PiecesSymbols
{
    Empty = '0',
    WhitePawn = 'P',
    WhiteKnight = 'N',
    WhiteBishop = 'B',
    WhiteRook = 'R',
    WhiteQueen = 'Q',
    WhiteKing = 'K',
    BlackPawn = 'p',
    BlackKnight = 'n',
    BlackBishop = 'b',
    BlackRook = 'r',
    BlackQueen = 'q',
    BlackKing = 'k',

    // column 0 and row 0 symbol
    Placeholder = '*'
};

enum class PiecesColors
{
    Black = 0,
    White = 1
};

#endif // PIECES_HELPERS_HPP
