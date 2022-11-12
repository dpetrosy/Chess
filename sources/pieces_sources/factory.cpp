#include "factory.hpp"
#include "boardwidget.hpp"
#include "clickablelabel.hpp"
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
    // Init
    init();
}

Factory::~Factory() {}

// Prototype pattern realization
Piece *Factory::CreatePiece(Pieces piece, PiecesColors pieceColor, int i, int j, BoardWidget* boardWidget)
{
   auto temp = _piecesMap[piece]->Clone(pieceColor, i, j);
   if (boardWidget != nullptr)
   {
       QAction::connect(temp->getPieceLabel(), &ClickableLabel::clickedLeftButton, boardWidget,
               std::bind(&BoardWidget::processLeftButtonClick, boardWidget, temp));
   }

   return temp;
}

// Init
void Factory::init()
{
    _piecesMap[Pieces::Empty] = new Empty();
    _piecesMap[Pieces::Pawn] = new Pawn();
    _piecesMap[Pieces::Knight] = new Knight();
    _piecesMap[Pieces::Bishop] = new Bishop();
    _piecesMap[Pieces::Rook] = new Rook();
    _piecesMap[Pieces::Queen] = new Queen();
    _piecesMap[Pieces::King] = new King();
}
