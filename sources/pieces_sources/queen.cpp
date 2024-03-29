#include "queen.hpp"
#include "bishop.hpp"
#include "boardwidget.hpp"
#include "rook.hpp"
#include "clickablelabel.hpp"
#include "helpers.hpp"

Queen::Queen()
{
    // Init
    init();
    makeColored(PiecesColors::White);
    setPosition(0, 0);
    _pieceLabel->setPixmap(QPixmap(globalPieceSetPath + _image));
}

Queen::Queen(const Queen& other, PiecesColors pieceColor, int i, int j)
{
    Q_UNUSED(other)

    // Do Init, for prototype pattern
    init();
    makeColored(pieceColor);
    setPosition(i, j);
    _pieceLabel->setPixmap(QPixmap(globalPieceSetPath + _image));
}

Queen::~Queen()
{
    delete _pieceLabel;
    delete _bishop;
    delete _rook;
}

// Prototype pattern realization
Queen *Queen::Clone(PiecesColors pieceColor, int i, int j) const
{
   return new Queen(*this, pieceColor, i, j);
}

// Init
void Queen::init()
{
    _pieceLabel = new ClickableLabel();
    _pieceName = "queen";
    _pieceType = PiecesTypes::Queen;

    _bishop = new Bishop();
    _rook = new Rook();
}

// Public game functions
void Queen::findAvailableSteps(CharVector2D& stepsVector2D, CharVector2D& symbolsVector2D, PiecesColors turn, PiecesColors belowPlayerColor)
{
    int i = _position.row;
    int j = _position.column;

    doForQueen = true;
    _bishop->setPosition(i, j);
    _bishop->findAvailableSteps(stepsVector2D, symbolsVector2D, turn, belowPlayerColor);
    doForQueen = true;
    _rook->setPosition(i, j);
    _rook->findAvailableSteps(stepsVector2D, symbolsVector2D, turn, belowPlayerColor);
}
