#include "pawn.hpp"

Pawn::Pawn()
{
    image = "pawn.png";
    name = "pawn";
}

Pawn *Pawn::Clone() const
{
   return new Pawn(*this);
}

Pawn::~Pawn() {}


