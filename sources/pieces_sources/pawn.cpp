#include "pawn.hpp"
#include "boardwidget.hpp"
#include "gamewidget.hpp"
#include "clickablelabel.hpp"

Pawn::Pawn()
{
    // Init
    init();
    makeColored(PiecesColors::White);
    setPosition(0, 0);
    _pieceLabel->setPixmap(QPixmap(_piecesPath + _image));
}

Pawn::Pawn(const Pawn& other, PiecesColors pieceColor, int i, int j)
{
    Q_UNUSED(other)

    // Do Init, for prototype pattern
    init();
    makeColored(pieceColor);
    setPosition(i, j);
    _pieceLabel->setPixmap(QPixmap(_piecesPath + _image));
}

Pawn::~Pawn()
{
    delete _pieceLabel;
}

// Prototype pattern realization
Pawn *Pawn::Clone(PiecesColors pieceColor, int i, int j) const
{
   return new Pawn(*this, pieceColor, i, j);
}

// Init
void Pawn::init()
{
    _pieceLabel = new ClickableLabel();
    _pieceName = "pawn";
    _pieceType = PiecesTypes::Pawn;
}

// Public game functions
void Pawn::findAvailableSteps(CharVector2D& stepsVector2D, CharVector2D& symbolsVector2D, PiecesColors turn, PiecesColors belowPlayerColor)
{
    int i = _position.row;
    int j = _position.column;
    char canGo = (char)PossibleSteps::CanGo;
    char canBeat = (char)PossibleSteps::CanBeat;

    if (turn == belowPlayerColor)
    {
        if (i != 0 && isCanGo(symbolsVector2D, i - 1, j))
        {
            stepsVector2D[i - 1][j] = canGo;
            if (i == 6 && isCanGo(symbolsVector2D, i - 2, j))
                stepsVector2D[i - 2][j] = canGo;
        }

        if (j != 7 && i != 0)
            if(isCanBeat(symbolsVector2D, i - 1, j + 1, turn))
                stepsVector2D[i - 1][j + 1] = canBeat;

        if (j != 0 && i != 0)
            if(isCanBeat(symbolsVector2D, i - 1, j - 1, turn))
                stepsVector2D[i - 1][j - 1] = canBeat;
    }
    else
    {
        if (i != 7 && isCanGo(symbolsVector2D, i + 1, j))
        {
            stepsVector2D[i + 1][j] = canGo;
            if (i == 1 && isCanGo(symbolsVector2D, i + 2, j))
                stepsVector2D[i + 2][j] = canGo;
        }

        if (j != 7 && i != 7)
            if(isCanBeat(symbolsVector2D, i + 1, j + 1, turn))
                stepsVector2D[i + 1][j + 1] = canBeat;

        if (j != 0 && i != 7)
            if(isCanBeat(symbolsVector2D, i + 1, j - 1, turn))
                stepsVector2D[i + 1][j - 1] = canBeat;
    }


}
