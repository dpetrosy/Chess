#include "pawn.hpp"

Pawn::Pawn()
{
    // Setup
    setup();
    makeColored(PiecesColors::White);
    _pieceLabel->setPixmap(QPixmap(_piecesPath + _image));
}

Pawn::Pawn(const Pawn& other, PiecesColors pieceColor)
{
    Q_UNUSED(other)

    // Do setup, for prototype pattern
    setup();
    makeColored(pieceColor);
    _pieceLabel->setPixmap(QPixmap(_piecesPath + _image));
}

Pawn::~Pawn() {}

// Prototype pattern realization
Pawn *Pawn::Clone(PiecesColors pieceColor) const
{
   return new Pawn(*this, pieceColor);
}

// Setup
void Pawn::setup()
{
    _pieceLabel = new QLabel();
    _pieceName = "pawn";
}
