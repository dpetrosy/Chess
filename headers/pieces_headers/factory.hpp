#ifndef FACTORY_HPP
#define FACTORY_HPP

#include <QDebug>
#include <QHash>

#include "pieces_helpers.hpp"
#include "game_helpers.hpp"

// Prototype pattern used
class Factory
{   
public:
    Factory();
    virtual ~Factory();

    // Prototype pattern realization
    Piece *CreatePiece(Pieces piece, PiecesColors pieceColor, int i, int j, BoardWidget* boardWidget = nullptr);

private:
    // Prototype pattern realization
    QHash<Pieces, Piece *> _piecesMap;

    // Setup
    void setup();
};

#endif // FACTORY_HPP
