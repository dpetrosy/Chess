#ifndef KING_HPP
#define KING_HPP

#include <QDebug>
#include <QObject>
#include <QLabel>

#include "pieces_helpers.hpp"
#include "piece.hpp"

// Prototype pattern used
class King : public Piece
{
    Q_OBJECT

public:
    King();
    King(const King& other, PiecesColors pieceColor, int i, int j);
    virtual ~King();

public:
    // Prototype pattern realization
    King* Clone(PiecesColors pieceColor, int i, int j) const override;

    // Public game functions
    void findAvailableSteps(CharVector2D& stepsVector2D, CharVector2D& symbolsVector2D, PiecesColors turn, PiecesColors belowPlayerColor = PiecesColors::White) override;
    void checkEveryStep(CharVector2D& stepsVector2D, CharVector2D& symbolsVector2D, PiecesColors turn, int kingI, int kingJ);

private:
    // Init
    void init();
};

#endif // KING_HPP
