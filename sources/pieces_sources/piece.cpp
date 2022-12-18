#include "piece.hpp"
#include "boardwidget.hpp"
#include "clickablelabel.hpp"
#include "helpers.hpp"
#include "utils.hpp"

Piece::Piece()
{   
    // Init
    init();
    setPosition(0, 0);
    makeColored(PiecesColors::White);
}

Piece::~Piece() {}

// Init
void Piece::init()
{
    _pieceLabel = nullptr;
    _pieceName = "piece";
    _extension = ".png";
    _pieceType = PiecesTypes::Empty;
}

// Protected util functions
void Piece::makeColored(PiecesColors pieceColor)
{
    _pieceColor = pieceColor;
    if (_pieceColor == PiecesColors::White)
        _colorString = "white";
    else if (_pieceColor == PiecesColors::Black)
        _colorString = "black";
    else
        _colorString = "";

    if (_colorString != "")
    {
        _coloredName = _colorString + "_" + _pieceName;
        _image = _coloredName + _extension;
    }
    else
    {
        _coloredName = _pieceName;
        _image = _coloredName;
    }

    findPieceSymbol();
}

void Piece::findPieceSymbol()
{
    if (_pieceName == "pawn")
        _pieceSymbol = (char)PiecesTypes::Pawn;
    else if (_pieceName == "knight")
        _pieceSymbol = (char)PiecesTypes::Knight;
    else if (_pieceName == "bishop")
        _pieceSymbol = (char)PiecesTypes::Bishop;
    else if (_pieceName == "rook")
        _pieceSymbol = (char)PiecesTypes::Rook;
    else if (_pieceName == "queen")
        _pieceSymbol = (char)PiecesTypes::Queen;
    else if (_pieceName == "king")
        _pieceSymbol = (char)PiecesTypes::King;
    else // empty
        _pieceSymbol = (char)PiecesTypes::Empty;

    if (_colorString == "white")
        _pieceSymbol = toupper(_pieceSymbol);
}

// Getters
ClickableLabel* Piece::getPieceLabel() const
{
    return _pieceLabel;
}

Position Piece::getPosition() const
{
    return _position;
}

int Piece::getPositionRow() const
{
    return _position.row;
}

int Piece::getPositionColumn() const
{
    return _position.column;
}

QString Piece::getPieceName() const
{
    return _pieceName;
}

QString Piece::getExtension() const
{
    return _extension;
}

PiecesTypes Piece::getPieceType() const
{
    return _pieceType;
}

PiecesColors Piece::getPieceColor() const
{
    return _pieceColor;
}

QString Piece::getColorString() const
{
    return _colorString;
}

QString Piece::getColoredName() const
{
    return _coloredName;
}

QString Piece::getImage() const
{
    return _image;
}

char Piece::getPieceSymbol() const
{
    return _pieceSymbol;
}

// Setters
void Piece::setPieceLabel(ClickableLabel* pieceLabel)
{
    _pieceLabel = pieceLabel;
}

void Piece::setPosition(int row, int column)
{
    _position.row = row;
    _position.column = column;
}

void Piece::setPositionRow(int row)
{
    _position.row = row;
}

void Piece::setPositionColumn(int column)
{
    _position.column = column;
}

void Piece::setPieceName(QString pieceName)
{
    _pieceName = pieceName;
}

void Piece::setExtension(QString extension)
{
    _extension = extension;
}

void Piece::setPieceType(PiecesTypes pieceType)
{
    _pieceType = pieceType;
}

void Piece::setPieceColor(PiecesColors piecesColor)
{
    _pieceColor = piecesColor;
}

void Piece::setColorString(QString colorString)
{
    _colorString = colorString;
}

void Piece::setColoredName(QString coloredName)
{
    _coloredName = coloredName;
}

void Piece::setImage(QString image)
{
    _image = image;
}

void Piece::changePixmap()
{
    _pieceLabel->setPixmap(QPixmap(globalPieceSetPath + _image));
}









// Public game functions
bool Piece::isCanGo(CharVector2D& symbolsVector2D, int i, int j)
{
    return (symbolsVector2D[i][j] == (char)PiecesSymbols::Empty);
}

bool Piece::isCanBeat(CharVector2D& symbolsVector2D, int i, int j, PiecesColors turn)
{
    return (!isCanGo(symbolsVector2D, i, j) && !isSameColoredPiece(symbolsVector2D, i, j, turn));
}

bool Piece::isSameColoredPiece(CharVector2D& symbolsVector2D, int i, int j, PiecesColors turn)
{
    bool isPieceWhite = isupper(symbolsVector2D[i][j]);

    if (turn == PiecesColors::White && isPieceWhite)
        return true;
    if (turn == PiecesColors::Black && !isPieceWhite)
        return true;
    return false;
}

bool Piece::isKing(CharVector2D& symbolsVector2D, int i, int j)
{
    return (symbolsVector2D[i][j] == (char)PiecesSymbols::WhiteKing || symbolsVector2D[i][j] == (char)PiecesSymbols::BlackKing);
}

bool Piece::isGivingCheck(CharVector2D& stepsVector2D, CharVector2D& symbolsVector2D, PiecesColors turn)
{
    auto boardSize = BoardWidget::GetInstance()->getBoardSize();
    for (int i = 0; i < boardSize; ++i)
        for (int j = 0; j < boardSize; ++j)
            if ((stepsVector2D[i][j] == (char)PossibleSteps::CanBeat) && isKing(symbolsVector2D, i, j) && !isSameColoredPiece(symbolsVector2D, i, j, turn))
            {
                BoardWidget::GetInstance()->setCheckPosition(i, j);
                return true;
            }
    return false;
}

void Piece::markCanGoOrCanBeat(CharVector2D& stepsVector2D, CharVector2D& symbolsVector2D, int i, int j, PiecesColors turn)
{
    char canGo = (char)PossibleSteps::CanGo;
    char canBeat = (char)PossibleSteps::CanBeat;

    if (isCanGo(symbolsVector2D, i, j))
        stepsVector2D[i][j] = canGo;
    if (isCanBeat(symbolsVector2D, i, j, turn))
        stepsVector2D[i][j] = canBeat;
}

void Piece::verifyCheckOpening(CharVector2D& stepsVector2D, CharVector2D& symbolsVector2D, PiecesColors turn, int pieceI, int pieceJ)
{
    char clearedSymbol = '0';
    char pieceSymbol = symbolsVector2D[pieceI][pieceJ];
    char kingSymbol;
    int kingI = 0;
    int kingJ = 0;

    if (turn == PiecesColors::Black)
        kingSymbol = 'k';
    else
        kingSymbol = 'K';
    findKingPos(symbolsVector2D, kingI, kingJ, kingSymbol);

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
                imitationVector2D[pieceI][pieceJ] = (char)PossibleSteps::Empty;
                imitationVector2D[i][j] = pieceSymbol;
                BoardWidget::GetInstance()->getAllAvailStepsForColor(allAvailStepsVector2D, imitationVector2D, turn);

                if (allAvailStepsVector2D[kingI][kingJ] == (char)PossibleSteps::CanBeat)
                    stepsVector2D[i][j] = (char)PossibleSteps::Empty;

                imitationVector2D[pieceI][pieceJ] = pieceSymbol;
                imitationVector2D[i][j] = clearedSymbol;
                resetCharVector2D(allAvailStepsVector2D, 8, (char)PossibleSteps::Empty);
            }
        }
    }
}

void Piece::findKingPos(CharVector2D& symbolsVector2D, int& kingI, int& kingJ, char kingSymbol)
{
    for (int i = 0; i < 8; ++i)
        for (int j = 0; j < 8; ++j)
            if (symbolsVector2D[i][j] == kingSymbol)
            {
                kingI = i;
                kingJ = j;
            }
}

