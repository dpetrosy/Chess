#ifndef FACTORY_HPP
#define FACTORY_HPP

#include "piece.hpp"
#include "pawn.hpp"

class Factory
{
public:
    Factory();
    virtual ~Factory();
    Piece *CreatePiece(Pieces piece);

private:
    std::unordered_map<Pieces, Piece *> m_pieces;
};

#endif // FACTORY_HPP
