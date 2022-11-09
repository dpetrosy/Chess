#include "piece.hpp"
#include "boardwidget.hpp"
#include "clickablelabel.hpp"
#include "helpers.hpp"

Piece::Piece()
{   
    // Setup
    setup();
    setPosition(0, 0);
    makeColored(PiecesColors::White);
}

Piece::~Piece()
{
    delete _pieceLabel;
}

// Setup
void Piece::setup()
{
    _pieceLabel = nullptr;
    _piecesPath = ImagesPaths::piecesPath;
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
}

// Getters
ClickableLabel* Piece::getPieceLabel() const
{
    return _pieceLabel;
}

QString Piece::getPiecePath() const
{
    return _piecesPath;
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

// Setters
void Piece::setPieceLabel(ClickableLabel* pieceLabel)
{
    _pieceLabel = pieceLabel;
}

void Piece::setPiecePath(QString piecePath)
{
    _piecesPath = piecePath;
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
    for (unsigned i = 0; i < boardSize; ++i)
        for (unsigned j = 0; j < boardSize; ++j)
            if ((stepsVector2D[i][j] == (char)PossibleSteps::CanBeat) && isKing(symbolsVector2D, i, j) && !isSameColoredPiece(symbolsVector2D, i, j, turn))
            {
                stepsVector2D[i][j] = (char)PossibleSteps::Check;
                return true;
            }
    return false;
}




// Delete
void Piece::findAvailableSteps(CharVector2D& stepsVector2D, CharVector2D& symbolsVector2D, PiecesColors turn, PiecesColors belowPlayerColor)
{}
