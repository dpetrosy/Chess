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

    // Prototype pattern realization
    Knight *Clone(PiecesColors pieceColor, int i, int j) const override;

private:
    // Setup
    void setup();
};

#endif // KNIGHT_HPP
