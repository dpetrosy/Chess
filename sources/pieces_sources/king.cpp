#include "king.hpp"
#include "clickablelabel.hpp"

King::King()
{
    // Setup
    init();
    makeColored(PiecesColors::White);
    setPosition(0, 0);
    _pieceLabel->setPixmap(QPixmap(_piecesPath + _image));
}

King::King(const King& other, PiecesColors pieceColor, int i, int j)
{
    Q_UNUSED(other)

    // Do setup, for prototype pattern
    init();
    makeColored(pieceColor);
    setPosition(i, j);
    _pieceLabel->setPixmap(QPixmap(_piecesPath + _image));
}

King::~King() {}

// Prototype pattern realization
King *King::Clone(PiecesColors pieceColor, int i, int j) const
{
   return new King(*this, pieceColor, i, j);
}

// Setup
void King::init()
{
    _pieceLabel = new ClickableLabel();
    _pieceName = "king";
    _pieceType = PiecesTypes::King;
}
