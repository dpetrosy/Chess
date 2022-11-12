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

private:
    // Init
    void init();
};

#endif // KING_HPP
