#ifndef QUEEN_HPP
#define QUEEN_HPP

#include <QDebug>
#include <QObject>
#include <QLabel>

#include "pieces_helpers.hpp"
#include "piece.hpp"

// Prototype pattern used
class Queen : public Piece
{
    Q_OBJECT

public:
    Queen();
    Queen(const Queen& other, PiecesColors pieceColor, int i, int j);
    virtual ~Queen();

public:
    // Prototype pattern realization
    Queen*  Clone(PiecesColors pieceColor, int i, int j) const override;

private:
    // Init
    void init();
};

#endif // QUEEN_HPP
