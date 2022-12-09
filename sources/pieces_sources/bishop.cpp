#include "bishop.hpp"
#include "clickablelabel.hpp"

Bishop::Bishop()
{
    // Init
    init();
    makeColored(PiecesColors::White);
    setPosition(0, 0);
    _pieceLabel->setPixmap(QPixmap(globalPieceSetPath + _image));
}

Bishop::Bishop(const Bishop& other, PiecesColors pieceColor, int i, int j)
{
    Q_UNUSED(other)

    // Do Init, for prototype pattern
    init();
    makeColored(pieceColor);
    setPosition(i, j);
    _pieceLabel->setPixmap(QPixmap(globalPieceSetPath + _image));
}

Bishop::~Bishop()
{
    delete _pieceLabel;
}

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

// Public game functions
void Bishop::findAvailableSteps(CharVector2D& stepsVector2D, CharVector2D& symbolsVector2D, PiecesColors turn, PiecesColors belowPlayerColor)
{
    int ipos = _position.row;
    int jpos = _position.column;
    char canGo = (char)PossibleSteps::CanGo;
    char canBeat = (char)PossibleSteps::CanBeat;
    Q_UNUSED(belowPlayerColor)

    // top left
    int i = ipos;
    int j = jpos;
    if (i != 0 && j != 0)
    {
        while ((--i >= 0) && (--j >= 0))
        {
            if (isCanGo(symbolsVector2D, i, j))
                stepsVector2D[i][j] = canGo;
            else if (isCanBeat(symbolsVector2D, i, j, turn))
            {
                stepsVector2D[i][j] = canBeat;
                break;
            }
            else
                break;
        }
    }

    // top right
    i = ipos;
    j = jpos;
    if (i != 0 && j != 7)
    {
        while ((--i >= 0) && (++j <= 7))
        {
            if (isCanGo(symbolsVector2D, i, j))
                stepsVector2D[i][j] = canGo;
            else if (isCanBeat(symbolsVector2D, i, j, turn))
            {
                stepsVector2D[i][j] = canBeat;
                break;
            }
            else
                break;
        }
    }

    // down right
    i = ipos;
    j = jpos;
    if (i != 7 && j != 7)
    {
        while ((++i <= 7) && (++j <= 7))
        {
            if (isCanGo(symbolsVector2D, i, j))
                stepsVector2D[i][j] = canGo;
            else if (isCanBeat(symbolsVector2D, i, j, turn))
            {
                stepsVector2D[i][j] = canBeat;
                break;
            }
            else
                break;
        }
    }

    // down left
    i = ipos;
    j = jpos;
    if (i != 7 && j != 0)
    {
        while ((++i <= 7) && (--j >= 0))
        {
            if (isCanGo(symbolsVector2D, i, j))
                stepsVector2D[i][j] = canGo;
            else if (isCanBeat(symbolsVector2D, i, j, turn))
            {
                stepsVector2D[i][j] = canBeat;
                break;
            }
            else
                break;
        }
    }
}
