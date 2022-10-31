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
    //Q_OBJECT

public:
    Rook();
    Rook(const Rook& other, PiecesColors pieceColor, int i, int j);
    virtual ~Rook();

    // Prototype pattern realization
    Rook *Clone(PiecesColors pieceColor, int i, int j) const override;

private:
    // Setup
    void setup();
};

#endif // ROOK_HPP
