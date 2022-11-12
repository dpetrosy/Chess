#include "bishop.hpp"
#include "clickablelabel.hpp"

Bishop::Bishop()
{
    // Init
    init();
    makeColored(PiecesColors::White);
    setPosition(0, 0);
    _pieceLabel->setPixmap(QPixmap(_piecesPath + _image));
}

Bishop::Bishop(const Bishop& other, PiecesColors pieceColor, int i, int j)
{
    Q_UNUSED(other)

    // Do Init, for prototype pattern
    init();
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

// Init
void Bishop::init()
{
    _pieceLabel = new ClickableLabel();
    _pieceName = "bishop";
    _pieceType = PiecesTypes::Bishop;
}
