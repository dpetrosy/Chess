#include "queen.hpp"

Queen::Queen()
{
    // Setup
    setup();
    makeColored(PiecesColors::White);
    setPosition(0, 0);
    _pieceLabel->setPixmap(QPixmap(_piecesPath + _image));
}

Queen::Queen(const Queen& other, PiecesColors pieceColor, int i, int j)
{
    Q_UNUSED(other)

    // Do setup, for prototype pattern
    setup();
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

// Setup
void Queen::setup()
{
    _pieceLabel = new QLabel();
    _pieceName = "queen";
}
