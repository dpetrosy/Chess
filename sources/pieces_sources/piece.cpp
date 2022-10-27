#include "piece.hpp"
#include "helpers.hpp"

Piece::Piece()
{   
    // Setup
    setup();
}

Piece::~Piece() {}

// Prototype pattern realization

// Setup
void Piece::setup()
{
    _pieceLabel = nullptr;
    _piecesPath = ImagesPaths::piecesPath;
    _image = "empty";
    _name = "piece";
    _rowInGridLayout = 0;
    _columnInGridLayout = 0;
}
