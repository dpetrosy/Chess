#ifndef BISHOP_HPP
#define BISHOP_HPP

#include <QDebug>
#include <QObject>
#include <QLabel>

#include "pieces_helpers.hpp"
#include "piece.hpp"

// Prototype pattern used
class Bishop : public Piece
{
    Q_OBJECT

public:
    Bishop();
    Bishop(const Bishop& other, PiecesColors pieceColor, int i, int j);
    virtual ~Bishop();

public:
    // Prototype pattern realization
    Bishop* Clone(PiecesColors pieceColor, int i, int j) const override;

    // Public game functions
    void findAvailableSteps(CharVector2D& stepsVector2D, CharVector2D& symbolsVector2D, PiecesColors turn, PiecesColors belowPlayerColor = PiecesColors::White) override;

private:
    // Init
    void init();
};

#endif // BISHOP_HPP
