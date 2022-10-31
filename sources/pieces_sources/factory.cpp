#include "factory.hpp"
#include "piece.hpp"
#include "empty.hpp"
#include "pawn.hpp"
#include "knight.hpp"
#include "bishop.hpp"
#include "rook.hpp"
#include "queen.hpp"
#include "king.hpp"

Factory::Factory()
{
    // Setup
    setup();
}

Factory::~Factory() {}

// Prototype pattern realization
Piece *Factory::CreatePiece(Pieces piece, PiecesColors pieceColor, int i, int j)
{
   return _piecesMap[piece]->Clone(pieceColor, i, j);
}

// Setup
void Factory::setup()
{
    _piecesMap[Pieces::Empty] = new Empty();
    _piecesMap[Pieces::Pawn] = new Pawn();
    _piecesMap[Pieces::Knight] = new Knight();
    _piecesMap[Pieces::Bishop] = new Bishop();
    _piecesMap[Pieces::Rook] = new Rook();
    _piecesMap[Pieces::Queen] = new Queen();
    _piecesMap[Pieces::King] = new King();
}
