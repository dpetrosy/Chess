#ifndef PIECE_HPP
#define PIECE_HPP

#include <QString>

enum class Pieces
{
    Empty = 0,
    Pawn = 1,
    Knight = 2,
    Bishop = 3,
    Rook = 5,
    Queen = 8,
    King = 10
};

class Piece 
{
public:
    virtual ~Piece();
    virtual Piece *Clone() const = 0;

protected:
    Piece();

protected:
    QString piecePath;
    QString image;
    QString name;
    unsigned rowInGridLayout;
    unsigned columnInGridLayout;
};

#endif // PIECE_HPP
