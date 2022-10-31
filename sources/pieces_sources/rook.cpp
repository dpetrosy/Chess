#include "rook.hpp"

Rook::Rook()
{
    // Setup
    setup();
    makeColored(PiecesColors::White);
    setPosition(0, 0);
    _pieceLabel->setPixmap(QPixmap(_piecesPath + _image));
}

Rook::Rook(const Rook& other, PiecesColors pieceColor, int i, int j)
{
    Q_UNUSED(other)

    // Do setup, for prototype pattern
    setup();
    makeColored(pieceColor);
    setPosition(i, j);
    _pieceLabel->setPixmap(QPixmap(_piecesPath + _image));
}

Rook::~Rook() {}

// Prototype pattern realization
Rook *Rook::Clone(PiecesColors pieceColor, int i, int j) const
{
   return new Rook(*this, pieceColor, i, j);
}

// Setup
void Rook::setup()
{
    _pieceLabel = new QLabel();
    _pieceName = "rook";
}
