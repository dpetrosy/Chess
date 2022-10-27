#include "pawn.hpp"

Pawn::Pawn()
{
    // Setup
    setup();
}

Pawn::~Pawn() {}

// Prototype pattern realization
Pawn *Pawn::Clone() const
{
   return new Pawn(*this);
}

// Setup
void Pawn::setup()
{
    _pieceLabel = new QLabel();
    _image = "black_pawn.png";
    _name = "black_pawn";
    _rowInGridLayout = 0;
    _columnInGridLayout = 0;
}
