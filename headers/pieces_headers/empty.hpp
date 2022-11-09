#ifndef EMPTY_HPP
#define EMPTY_HPP

#include <QDebug>
#include <QObject>
#include <QLabel>

#include "pieces_helpers.hpp"
#include "piece.hpp"

// Prototype pattern used
class Empty : public Piece
{
    //Q_OBJECT

public:
    Empty();
    Empty(const Empty& other, PiecesColors pieceColor, int i, int j);
    virtual ~Empty();

public:
    // Prototype pattern realization
    Empty*  Clone(PiecesColors pieceColor, int i, int j) const override;

private:
    // Init
    void    init();
};

#endif // EMPTY_HPP
