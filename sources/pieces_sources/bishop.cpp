#include "bishop.hpp"

Bishop::Bishop()
{
    // Setup
    setup();
    makeColored(PiecesColors::White);
    setPosition(0, 0);
    _pieceLabel->setPixmap(QPixmap(_piecesPath + _image));
}

Bishop::Bishop(const Bishop& other, PiecesColors pieceColor, int i, int j)
{
    Q_UNUSED(other)

    // Do setup, for prototype pattern
    setup();
    makeColored(pieceColor);
    setPosition(i, j);
    _pieceLabel->setPixmap(QPixmap(_piecesPath + _image));
}

Bishop::~Bishop() {}

// Prototype pattern realization
Bishop *Bishop::Clone(PiecesColors pieceColor, int i, int j) const
{
   return new Bishop(*this, pieceColor, i, j);
}

// Setup
void Bishop::setup()
{
    _pieceLabel = new QLabel();
    _pieceName = "bishop";
}
