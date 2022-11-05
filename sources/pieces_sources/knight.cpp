#include "knight.hpp"
#include "clickablelabel.hpp"

Knight::Knight()
{
    // Setup
    setup();
    makeColored(PiecesColors::White);
    setPosition(0, 0);
    _pieceLabel->setPixmap(QPixmap(_piecesPath + _image));
}

Knight::Knight(const Knight& other, PiecesColors pieceColor, int i, int j)
{
    Q_UNUSED(other)

    // Do setup, for prototype pattern
    setup();
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
void Knight::setup()
{
    _pieceLabel = new ClickableLabel();
    _pieceName = "knight";
    _pieceType = PiecesTypes::Knight;
}
