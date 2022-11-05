#include "pawn.hpp"
#include "clickablelabel.hpp"

Pawn::Pawn()
{
    // Setup
    setup();
    makeColored(PiecesColors::White);
    setPosition(0, 0);
    _pieceLabel->setPixmap(QPixmap(_piecesPath + _image));
}

Pawn::Pawn(const Pawn& other, PiecesColors pieceColor, int i, int j)
{
    Q_UNUSED(other)

    // Do setup, for prototype pattern
    setup();
    makeColored(pieceColor);
    setPosition(i, j);
    _pieceLabel->setPixmap(QPixmap(_piecesPath + _image));
}

Pawn::~Pawn() {}

// Prototype pattern realization
Pawn *Pawn::Clone(PiecesColors pieceColor, int i, int j) const
{
   return new Pawn(*this, pieceColor, i, j);
}

// Setup
void Pawn::setup()
{
    _pieceLabel = new ClickableLabel();
    _pieceName = "pawn";
    _pieceType = PiecesTypes::Pawn;
}

// Public game functions
void Pawn::findAvailableSteps(charVector2D& stepsVector2D, charVector2D& symbolsVector2D)
{
    int i = _position.row;
    int j = _position.column;
    char empty = (char)PossibleSteps::Empty;
    char canGo = (char)PossibleSteps::CanGo;
    char canBeat = (char)PossibleSteps::CanBeat;
    char symbolEmpty = (char)PiecesSymbols::Empty;

    // For white pawn
    if (_pieceColor == PiecesColors::White)
    {
        if (symbolsVector2D[i - 1][j] == symbolEmpty)
        {
            stepsVector2D[i - 1][j] = canGo;
            if (i == 6)
                if (symbolsVector2D[i - 2][j] == symbolEmpty)
                stepsVector2D[i - 2][j] = canGo;
        }


        if (j != 7)
        {
            if (symbolsVector2D[i - 1][j + 1] != symbolEmpty)
                stepsVector2D[i - 1][j + 1] = canBeat;
        }
        if (j != 0)
        {
            if (symbolsVector2D[i - 1][j - 1] != symbolEmpty)
                stepsVector2D[i - 1][j - 1] = canBeat;
        }
    }

    // For black pawn
    if (_pieceColor == PiecesColors::Black)
    {
        if (symbolsVector2D[i + 1][j] == symbolEmpty)
            stepsVector2D[i + 1][j] = canGo;

        if (i == 1)
            if (symbolsVector2D[i + 2][j] == symbolEmpty)
            stepsVector2D[i + 2][j] = canGo;

        if (j != 7)
        {
            if (symbolsVector2D[i + 1][j + 1] != symbolEmpty)
                stepsVector2D[i + 1][j + 1] = canBeat;
        }
        if (j != 0)
        {
            if (symbolsVector2D[i + 1][j - 1] != symbolEmpty)
                stepsVector2D[i + 1][j - 1] = canBeat;
        }
    }
}
