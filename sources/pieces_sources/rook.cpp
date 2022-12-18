#include "rook.hpp"
#include "boardwidget.hpp"
#include "clickablelabel.hpp"
#include "helpers.hpp"

Rook::Rook()
{
    // Init
    init();
    makeColored(PiecesColors::White);
    setPosition(0, 0);
    _pieceLabel->setPixmap(QPixmap(globalPieceSetPath + _image));
}

Rook::Rook(const Rook& other, PiecesColors pieceColor, int i, int j)
{
    Q_UNUSED(other)

    // Do Init, for prototype pattern
    init();
    makeColored(pieceColor);
    setPosition(i, j);
    _pieceLabel->setPixmap(QPixmap(globalPieceSetPath + _image));
}

Rook::~Rook()
{
    delete _pieceLabel;
}

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

// Public game functions
void Rook::findAvailableSteps(CharVector2D& stepsVector2D, CharVector2D& symbolsVector2D, PiecesColors turn, PiecesColors belowPlayerColor)
{
    int ipos = _position.row;
    int jpos = _position.column;
    char canGo = (char)PossibleSteps::CanGo;
    char canBeat = (char)PossibleSteps::CanBeat;
    Q_UNUSED(belowPlayerColor)

    // top
    int i = ipos;
    int j = jpos;
    if (i != 0)
    {
        while (--i >= 0)
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

    // down
    i = ipos;
    j = jpos;
    if (i != 7)
    {
        while (++i <= 7)
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

    // left
    i = ipos;
    j = jpos;
    if (j != 0)
    {
        while (--j >= 0)
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

    // right
    i = ipos;
    j = jpos;
    if (j != 7)
    {
        while (++j <= 7)
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

    // Verify if step open check
    if (gSelectedPiece == this || doForQueen)
    {
        doForQueen = false;
        verifyCheckOpening(stepsVector2D, symbolsVector2D, turn, ipos, jpos);
    }
}
