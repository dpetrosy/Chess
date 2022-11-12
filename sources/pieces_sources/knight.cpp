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

Knight::~Knight() {}

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
    char canGo = (char)PossibleSteps::CanGo;
    char canBeat = (char)PossibleSteps::CanBeat;

    // top
    if (i >= 2)
    {
        if (j != 0)
        {
            if (isCanGo(symbolsVector2D, i - 2, j - 1))
                stepsVector2D[i - 2][j - 1] = canGo;
            if (isCanBeat(symbolsVector2D, i - 2, j - 1, turn))
                stepsVector2D[i - 2][j - 1] = canBeat;
        }
        if (j != 7)
        {
            if (isCanGo(symbolsVector2D, i - 2, j + 1))
                stepsVector2D[i - 2][j + 1] = canGo;
            if (isCanBeat(symbolsVector2D, i - 2, j + 1, turn))
                stepsVector2D[i - 2][j + 1] = canBeat;
        }
    }

    // down
    if (i <= 5)
    {
        if (j != 0)
        {
            if (isCanGo(symbolsVector2D, i + 2, j - 1))
                stepsVector2D[i + 2][j - 1] = canGo;
            if (isCanBeat(symbolsVector2D, i + 2, j - 1, turn))
                stepsVector2D[i + 2][j - 1] = canBeat;
        }
        if (j != 7)
        {
            if (isCanGo(symbolsVector2D, i + 2, j + 1))
                stepsVector2D[i + 2][j + 1] = canGo;
            if (isCanBeat(symbolsVector2D, i + 2, j + 1, turn))
                stepsVector2D[i + 2][j + 1] = canBeat;
        }
    }

    // left
    if (j >= 2)
    {
        if (i != 0)
        {
            if (isCanGo(symbolsVector2D, i - 1, j - 2))
                stepsVector2D[i - 1][j - 2] = canGo;
            if (isCanBeat(symbolsVector2D, i - 1, j - 2, turn))
                stepsVector2D[i - 1][j - 2] = canBeat;
        }
        if (i != 7)
        {
            if (isCanGo(symbolsVector2D, i + 1, j - 2))
                stepsVector2D[i + 1][j - 2] = canGo;
            if (isCanBeat(symbolsVector2D, i + 1, j - 2, turn))
                stepsVector2D[i + 1][j - 2] = canBeat;
        }
    }

    // right
    if (j <= 5)
    {
        if (i != 0)
        {
            if (isCanGo(symbolsVector2D, i - 1, j + 2))
                stepsVector2D[i - 1][j + 2] = canGo;
            if (isCanBeat(symbolsVector2D, i - 1, j + 2, turn))
                stepsVector2D[i - 1][j + 2] = canBeat;
        }
        if (i != 7)
        {
            if (isCanGo(symbolsVector2D, i + 1, j + 2))
                stepsVector2D[i + 1][j + 2] = canGo;
            if (isCanBeat(symbolsVector2D, i + 1, j + 2, turn))
                stepsVector2D[i + 1][j + 2] = canBeat;
        }
    }
}
