#include "piece.hpp"
#include "helpers.hpp"

Piece::Piece()
{   
    // Setup
    setup();
    makeColored(PiecesColors::White);
}

Piece::~Piece() {}

// Setup
void Piece::setup()
{
    _pieceLabel = nullptr;
    _piecesPath = ImagesPaths::piecesPath;
    _rowInGridLayout = 0;
    _columnInGridLayout = 0;
    _pieceName = "piece";
    _extension = ".png";
}

// Protected util functions
void Piece::makeColored(PiecesColors pieceColor)
{
    _pieceColor = pieceColor;
    if (_pieceColor == PiecesColors::White)
        _colorString = "white";
    else
        _colorString = "black";
    _coloredName = _colorString + "_" + _pieceName;
    _image = _coloredName + _extension;
}
