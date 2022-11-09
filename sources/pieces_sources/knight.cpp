#include "knight.hpp"
#include "clickablelabel.hpp"

Knight::Knight()
{
    // Setup
    init();
    makeColored(PiecesColors::White);
    setPosition(0, 0);
    _pieceLabel->setPixmap(QPixmap(_piecesPath + _image));
}

Knight::Knight(const Knight& other, PiecesColors pieceColor, int i, int j)
{
    Q_UNUSED(other)

    // Do setup, for prototype pattern
    init();
    makeColored(pieceColor);
    setPosition(i, j);
    _pieceLabel->setPixmap(QPixmap(_piecesPath + _image));
}

Knight::~Knight() {}

// Prototype pattern realization
Knight *Knight::Clone(PiecesColors pieceColor, int i, int j) const
{
   return new Knight(*this, pieceColor, i, j);
}

// Setup
void Knight::init()
{
    _pieceLabel = new ClickableLabel();
    _pieceName = "knight";
    _pieceType = PiecesTypes::Knight;
}
