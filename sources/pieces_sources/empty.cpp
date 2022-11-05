#include "empty.hpp"
#include "clickablelabel.hpp"

Empty::Empty()
{
    // Setup
    setup();
    makeColored(PiecesColors::NoColored);
    setPosition(0, 0);
}

Empty::Empty(const Empty& other, PiecesColors pieceColor, int i, int j)
{
    Q_UNUSED(other)

    // Do setup, for prototype pattern
    setup();
    makeColored(pieceColor);
    setPosition(i, j);
}

Empty::~Empty() {}

// Prototype pattern realization
Empty *Empty::Clone(PiecesColors pieceColor, int i, int j) const
{
   return new Empty(*this, pieceColor, i, j);
}

// Setup
void Empty::setup()
{
    _pieceLabel = new ClickableLabel();
    _pieceName = "empty";
    _pieceType = PiecesTypes::Empty;
}
