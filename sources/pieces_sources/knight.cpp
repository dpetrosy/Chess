#include "knight.hpp"
#include "clickablelabel.hpp"

Knight::Knight()
{
    // Init
    init();
    makeColored(PiecesColors::White);
    setPosition(0, 0);
    _pieceLabel->setPixmap(QPixmap(_piecesPath + _image));
}

Knight::Knight(const Knight& other, PiecesColors pieceColor, int i, int j)
{
    Q_UNUSED(other)

    // Do Init, for prototype pattern
    init();
    makeColored(pieceColor);
    setPosition(i, j);
    _pieceLabel->setPixmap(QPixmap(_piecesPath + _image));
}

Knight::~Knight()
{
    delete _pieceLabel;
}

// Prototype pattern realization
Knight *Knight::Clone(PiecesColors pieceColor, int i, int j) const
{
   return new Knight(*this, pieceColor, i, j);
}

// Init
void Knight::init()
{
    _pieceLabel = new ClickableLabel();
    _pieceName = "knight";
    _pieceType = PiecesTypes::Knight;
}

// Public game functions
void Knight::findAvailableSteps(CharVector2D& stepsVector2D, CharVector2D& symbolsVector2D, PiecesColors turn, PiecesColors belowPlayerColor)
{
    int i = _position.row;
    int j = _position.column;
    Q_UNUSED(belowPlayerColor)

    // top
    if (i >= 2)
    {
        if (j != 0)
            markCanGoOrCanBeat(stepsVector2D, symbolsVector2D, i - 2, j - 1, turn);
        if (j != 7)
             markCanGoOrCanBeat(stepsVector2D, symbolsVector2D, i - 2, j + 1, turn);
    }

    // down
    if (i <= 5)
    {
        if (j != 0)
            markCanGoOrCanBeat(stepsVector2D, symbolsVector2D, i + 2, j - 1, turn);

        if (j != 7)
            markCanGoOrCanBeat(stepsVector2D, symbolsVector2D, i + 2, j + 1, turn);
    }

    // left
    if (j >= 2)
    {
        if (i != 0)
            markCanGoOrCanBeat(stepsVector2D, symbolsVector2D, i - 1, j - 2, turn);

        if (i != 7)
             markCanGoOrCanBeat(stepsVector2D, symbolsVector2D, i + 1, j - 2, turn);
    }

    // right
    if (j <= 5)
    {
        if (i != 0)
            markCanGoOrCanBeat(stepsVector2D, symbolsVector2D, i - 1, j + 2, turn);
        if (i != 7)
            markCanGoOrCanBeat(stepsVector2D, symbolsVector2D, i + 1, j + 2, turn);
    }
}
