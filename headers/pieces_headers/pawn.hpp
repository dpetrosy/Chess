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
    Q_OBJECT

public:
    Pawn();
    Pawn(const Pawn& other, PiecesColors pieceColor, int i, int j);
    virtual ~Pawn();

public:
    // Prototype pattern realization
    Pawn* Clone(PiecesColors pieceColor, int i, int j) const override;

public:
    // Public game functions
    void findAvailableSteps(CharVector2D& stepsVector2D, CharVector2D& symbolsVector2D, PiecesColors turn, PiecesColors belowPlayerColor = PiecesColors::White) override;

private:
    // Init
    void init();
};

#endif // PAWN_HPP
