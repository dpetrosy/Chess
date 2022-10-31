#include "piece.hpp"
#include "helpers.hpp"

Piece::Piece()
{   
    // Setup
    setup();
    setPosition(0, 0);
    makeColored(PiecesColors::White);
}

Piece::~Piece() {}

// Setup
void Piece::setup()
{
    _pieceLabel = nullptr;
    _piecesPath = ImagesPaths::piecesPath;
    _pieceName = "piece";
    _extension = ".png";
}

// Protected util functions
void Piece::makeColored(PiecesColors pieceColor)
{
    _pieceColor = pieceColor;
    if (_pieceColor == PiecesColors::White)
        _colorString = "white";
    else if (_pieceColor == PiecesColors::Black)
        _colorString = "black";
    else
        _colorString = "";

    if (_colorString != "")
    {
        _coloredName = _colorString + "_" + _pieceName;
        _image = _coloredName + _extension;
    }
    else
    {
        _coloredName = _pieceName;
        _image = _coloredName;
    }
}

// Getters
QLabel* Piece::getPieceLabel() const
{
    return _pieceLabel;
}

// Setters
void Piece::setPosition(int i, int j)
{
    _position.row = i;
    _position.column = j;
}
