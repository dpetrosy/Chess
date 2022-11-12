#include "rook.hpp"
#include "clickablelabel.hpp"

Rook::Rook()
{
    // Init
    init();
    makeColored(PiecesColors::White);
    setPosition(0, 0);
    _pieceLabel->setPixmap(QPixmap(_piecesPath + _image));
}

Rook::Rook(const Rook& other, PiecesColors pieceColor, int i, int j)
{
    Q_UNUSED(other)

    // Do Init, for prototype pattern
    init();
    makeColored(pieceColor);
    setPosition(i, j);
    _pieceLabel->setPixmap(QPixmap(_piecesPath + _image));
}

Rook::~Rook() {}

// Prototype pattern realization
Rook *Rook::Clone(PiecesColors pieceColor, int i, int j) const
{
   return new Rook(*this, pieceColor, i, j);
}

// Init
void Rook::init()
{
    _pieceLabel = new ClickableLabel();
    _pieceName = "rook";
    _pieceType = PiecesTypes::Rook;
}
