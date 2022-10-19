#ifndef PAWN_HPP
#define PAWN_HPP

#include "piece.hpp"

class Pawn : public Piece
{
public:
    Pawn();
    virtual ~Pawn();
    Pawn *Clone() const override;

private:

};

#endif // PAWN_HPP
