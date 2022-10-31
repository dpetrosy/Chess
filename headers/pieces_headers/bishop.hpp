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
    //Q_OBJECT

public:
    Bishop();
    Bishop(const Bishop& other, PiecesColors pieceColor, int i, int j);
    virtual ~Bishop();

    // Prototype pattern realization
    Bishop *Clone(PiecesColors pieceColor, int i, int j) const override;

private:
    // Setup
    void setup();
};

#endif // BISHOP_HPP
