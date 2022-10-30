#include "pawn.hpp"
#include "boardwidget.hpp"

Pawn::Pawn()
{
    // Setup
    setup();
    makeColored(PiecesColors::White);
    setPosition(0, 0);
    _pieceLabel->setPixmap(QPixmap(_piecesPath + _image));
}

Pawn::Pawn(const Pawn& other, PiecesColors pieceColor, int i, int j)
{
    Q_UNUSED(other)

    // Do setup, for prototype pattern
    setup();
    makeColored(pieceColor);
    setPosition(i, j);
    _pieceLabel->setPixmap(QPixmap(_piecesPath + _image));
}

Pawn::~Pawn() {}

// Prototype pattern realization
Pawn *Pawn::Clone(PiecesColors pieceColor, int i, int j) const
{
   return new Pawn(*this, pieceColor, i, j);
}

// Setup
void Pawn::setup()
{
    _pieceLabel = new QLabel();
    _pieceName = "pawn";
}
