#include "factory.hpp"

Factory::Factory()
{
    //m_pieces[Pieces::Empty] = new Empty();
    m_pieces[Pieces::Pawn] = new Pawn();
    //m_pieces[Pieces::Knight] = new Knight();
    //m_pieces[Pieces::Bishop] = new Bishop();
    //m_pieces[Pieces::Rook] = new Rook();
    //m_pieces[Pieces::Queen] = new Queen();
    //m_pieces[Pieces::King] = new King();
}

Factory::~Factory() {}

Piece *Factory::CreatePiece(Pieces piece)
{
   return m_pieces[piece]->Clone();
}
