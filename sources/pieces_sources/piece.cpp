#include "piece.hpp"

Piece::Piece()
{
    piecePath = ":/images/images/pieces/";
    image = "empty";
    name = "empty";
    rowInGridLayout = 0;
    columnInGridLayout = 0;
}

Piece::~Piece() {}
