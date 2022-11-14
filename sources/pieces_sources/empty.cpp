#include "empty.hpp"
#include "clickablelabel.hpp"

Empty::Empty()
{
    // Init
    init();
    makeColored(PiecesColors::NoColored);
    setPosition(0, 0);
}

Empty::Empty(const Empty& other, PiecesColors pieceColor, int i, int j)
{
    Q_UNUSED(other)

    // Do Init, for prototype pattern
    init();
    makeColored(pieceColor);
    setPosition(i, j);
}

Empty::~Empty()
{
    delete _pieceLabel;
}

// Prototype pattern realization
Empty *Empty::Clone(PiecesColors pieceColor, int i, int j) const
{
   return new Empty(*this, pieceColor, i, j);
}

// Init
void Empty::init()
{
    _pieceLabel = new ClickableLabel();
    _pieceName = "empty";
    _pieceType = PiecesTypes::Empty;
}

// Public game functions
void Empty::findAvailableSteps(CharVector2D& stepsVector2D, CharVector2D& symbolsVector2D, PiecesColors turn, PiecesColors belowPlayerColor)
{
    Q_UNUSED(stepsVector2D)
    Q_UNUSED(symbolsVector2D)
    Q_UNUSED(turn)
    Q_UNUSED(belowPlayerColor)
}
