#ifndef PAWN_HPP
#define PAWN_HPP

#include <QDebug>
#include <QObject>
#include <QLabel>

#include "pieces_helpers.hpp"
#include "piece.hpp"

// Prototype pattern used
class Pawn : public Piece
{
    //Q_OBJECT

public:
    Pawn();
    Pawn(const Pawn& other, PiecesColors pieceColor);
    virtual ~Pawn();

    // Prototype pattern realization
    Pawn *Clone(PiecesColors pieceColor) const override;

private:
    // Setup
    void setup();
};

#endif // PAWN_HPP
