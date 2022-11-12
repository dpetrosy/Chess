#ifndef KNIGHT_HPP
#define KNIGHT_HPP

#include <QDebug>
#include <QObject>
#include <QLabel>

#include "pieces_helpers.hpp"
#include "piece.hpp"

// Prototype pattern used
class Knight : public Piece
{
    Q_OBJECT

public:
    Knight();
    Knight(const Knight& other, PiecesColors pieceColor, int i, int j);
    virtual ~Knight();

public:
    // Prototype pattern realization
    Knight* Clone(PiecesColors pieceColor, int i, int j) const override;

    // Public game functions
    void findAvailableSteps(CharVector2D& stepsVector2D, CharVector2D& symbolsVector2D, PiecesColors turn, PiecesColors belowPlayerColor = PiecesColors::White) override;

private:
    // Init
    void init();
};

#endif // KNIGHT_HPP
