#include "queen.hpp"
#include "clickablelabel.hpp"

Queen::Queen()
{
    // Init
    init();
    makeColored(PiecesColors::White);
    setPosition(0, 0);
    _pieceLabel->setPixmap(QPixmap(_piecesPath + _image));
}

Queen::Queen(const Queen& other, PiecesColors pieceColor, int i, int j)
{
    Q_UNUSED(other)

    // Do Init, for prototype pattern
    init();
    makeColored(pieceColor);
    setPosition(i, j);
    _pieceLabel->setPixmap(QPixmap(_piecesPath + _image));
}

Queen::~Queen() {}

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
}
