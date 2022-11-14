#include "king.hpp"
#include "clickablelabel.hpp"

King::King()
{
    // Init
    init();
    makeColored(PiecesColors::White);
    setPosition(0, 0);
    _pieceLabel->setPixmap(QPixmap(_piecesPath + _image));
}

King::King(const King& other, PiecesColors pieceColor, int i, int j)
{
    Q_UNUSED(other)

    // Do Init, for prototype pattern
    init();
    makeColored(pieceColor);
    setPosition(i, j);
    _pieceLabel->setPixmap(QPixmap(_piecesPath + _image));
}

King::~King()
{
    delete _pieceLabel;
}

// Prototype pattern realization
King *King::Clone(PiecesColors pieceColor, int i, int j) const
{
   return new King(*this, pieceColor, i, j);
}

// Init
void King::init()
{
    _pieceLabel = new ClickableLabel();
    _pieceName = "king";
    _pieceType = PiecesTypes::King;
}

// Public game functions
void King::findAvailableSteps(CharVector2D& stepsVector2D, CharVector2D& symbolsVector2D, PiecesColors turn, PiecesColors belowPlayerColor)
{
    int i = _position.row;
    int j = _position.column;
    Q_UNUSED(belowPlayerColor)

    // up left
    if (i >= 1 && j >= 1)
        markCanGoOrCanBeat(stepsVector2D, symbolsVector2D, i - 1, j - 1, turn);

    // up
    if (i >= 1)
        markCanGoOrCanBeat(stepsVector2D, symbolsVector2D, i - 1, j, turn);

    // up right
    if (i >= 1 && j <= 6)
        markCanGoOrCanBeat(stepsVector2D, symbolsVector2D, i - 1, j + 1, turn);

    // right
    if (j <= 6)
        markCanGoOrCanBeat(stepsVector2D, symbolsVector2D, i, j + 1, turn);

    // down right
    if (i <= 6 && j <= 6)
        markCanGoOrCanBeat(stepsVector2D, symbolsVector2D, i + 1, j + 1, turn);

    // down
    if (i <= 6)
        markCanGoOrCanBeat(stepsVector2D, symbolsVector2D, i + 1, j, turn);

    // down left
    if (i <= 6 && j >= 1)
        markCanGoOrCanBeat(stepsVector2D, symbolsVector2D, i + 1, j - 1, turn);

    // left
    if (j >= 1)
        markCanGoOrCanBeat(stepsVector2D, symbolsVector2D, i, j - 1, turn);
}
