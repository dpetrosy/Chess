#ifndef PIECES_HELPERS_HPP
#define PIECES_HELPERS_HPP

#include <QVector>
#include <QString>
#include <QPair>
#include <QLabel>
using std::vector;
using std::pair;
using std::tuple;
struct Position;

#include "predefined_pieces_classes.hpp"

// Typedefs
typedef QVector<QVector<char>> CharVector2D;
typedef QVector<QVector<Piece *>> PieceVector2D;
typedef QVector<QVector<QLabel *>> LabelVector2D;
typedef vector<pair<tuple<char, Position, Position, QString>, tuple<char, Position, Position, QString>>> MovesVector;

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

enum class PiecesSymbols : char
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

enum class PiecesTypes : char
{
    Empty = '0',
    Pawn = 'p',
    Knight = 'n',
    Bishop = 'b',
    Rook = 'r',
    Queen = 'q',
    King = 'k',
};

enum class PiecesColors
{
    NoColored = 0,
    Black = 1,
    White = 2,
    Random = 3
};

struct Position
{
    int row = -1;
    int column = -1;
};

enum class PossibleSteps : char
{
    Empty = '0',
    CanGo = '*',
    CanBeat = 'x',
    CurrentPiece = '#',
    LastStepFrom = '1',
    LastStepTo = '2',
    LastStepFromAndCanGo = '$',
    CurrentPieceAndCheck = '&',
    Check = '%'
};

namespace StepsImages
{
    extern QString CanGo;
    extern QString CanBeat;
    extern QString CurrentPiece;
    extern QString LastStepFrom;
    extern QString LastStepTo;
    extern QString LastStepFromAndCanGo;
    extern QString Check;
    extern QString CurrentPieceAndChecked;
}

#endif // PIECES_HELPERS_HPP
