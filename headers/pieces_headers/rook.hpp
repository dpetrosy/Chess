#ifndef ROOK_HPP
#define ROOK_HPP

#include <QDebug>
#include <QObject>
#include <QLabel>

#include "pieces_helpers.hpp"
#include "piece.hpp"

// Prototype pattern used
class Rook : public Piece
{
    Q_OBJECT

public:
    Rook();
    Rook(const Rook& other, PiecesColors pieceColor, int i, int j);
    virtual ~Rook();

public:
    // Prototype pattern realization
    Rook* Clone(PiecesColors pieceColor, int i, int j) const override;

    // Public game functions
    void findAvailableSteps(CharVector2D& stepsVector2D, CharVector2D& symbolsVector2D, PiecesColors turn, PiecesColors belowPlayerColor = PiecesColors::White) override;


private:
    // Init
    void init();
};

#endif // ROOK_HPP
