#ifndef PIECE_HPP
#define PIECE_HPP

#include <QString>

class Piece
{
public:
    virtual ~Piece() = 0;

protected:
    Piece();

protected:
    QString piecePath = ":/images/images/";
    QString image = "nothing";
    QString name = "abstract";
    unsigned rowInGridLayout = 0;
    unsigned columnInGridLayout = 0;
};

#endif // PIECE_HPP
