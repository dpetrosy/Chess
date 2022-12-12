#include "king.hpp"
#include "clickablelabel.hpp"
#include "boardwidget.hpp"
#include "utils.hpp"

King::King()
{
    // Init
    init();
    makeColored(PiecesColors::White);
    setPosition(0, 0);
    _pieceLabel->setPixmap(QPixmap(globalPieceSetPath + _image));
}

King::King(const King& other, PiecesColors pieceColor, int i, int j)
{
    Q_UNUSED(other)

    // Do Init, for prototype pattern
    init();
    makeColored(pieceColor);
    setPosition(i, j);
    _pieceLabel->setPixmap(QPixmap(globalPieceSetPath + _image));
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

    // Check canGo and canBeat is valid or not
    if (gSelectedPiece == this)
        checkEveryStep(stepsVector2D, symbolsVector2D, turn, i, j);
}

void King::checkEveryStep(CharVector2D& stepsVector2D, CharVector2D& symbolsVector2D, PiecesColors turn, int kingI, int kingJ)
{
    char clearedSymbol = '0';
    char kingSymbol = symbolsVector2D[kingI][kingJ];

    CharVector2D imitationVector2D;
    imitationVector2D.reserve(8);
    for (int i = 0; i < 8; ++i)
        imitationVector2D.push_back(QVector<char>(8, (char)PossibleSteps::Empty));
    copyVector2D(imitationVector2D, symbolsVector2D, 8);

    CharVector2D allAvailStepsVector2D;
    allAvailStepsVector2D.reserve(8);
    for (int i = 0; i < 8; ++i)
        allAvailStepsVector2D.push_back(QVector<char>(8, (char)PossibleSteps::Empty));

    for (int i = 0; i < 8; ++i)
    {
        for (int j = 0; j < 8; ++j)
        {
            if (stepsVector2D[i][j] == (char)PossibleSteps::CanGo || stepsVector2D[i][j] == (char)PossibleSteps::CanBeat)
            {
                clearedSymbol = symbolsVector2D[i][j];
                imitationVector2D[kingI][kingJ] = (char)PossibleSteps::Empty;
                imitationVector2D[i][j] = kingSymbol;
                BoardWidget::GetInstance()->getAllAvailStepsForColor(allAvailStepsVector2D, imitationVector2D, turn);

                if (allAvailStepsVector2D[i][j] == (char)PossibleSteps::CanBeat)
                    stepsVector2D[i][j] = (char)PossibleSteps::Empty;

                imitationVector2D[kingI][kingJ] = kingSymbol;
                imitationVector2D[i][j] = clearedSymbol;
                resetCharVector2D(allAvailStepsVector2D, 8, (char)PossibleSteps::Empty);
            }
        }
    }
}





