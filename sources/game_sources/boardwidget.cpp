#include "boardwidget.hpp"
#include "helpers.hpp"
#include "moveswidget.hpp"
#include "gamewidget.hpp"
#include "pawnpromdialog.hpp"
#include "pieces_helpers.hpp"
#include "factory.hpp"
#include "piece.hpp"
#include "clickablelabel.hpp"

Piece* gSelectedPiece = nullptr;
bool doForQueen = false;

BoardWidget::BoardWidget(QWidget *parent)
    : QWidget{parent}
{
    // Init
    init();

    // Make BoardWidget
    makeBoardWidget();
}

BoardWidget::~BoardWidget() {}

// Singleton pattern realization
BoardWidget* BoardWidget::_boardWidget = nullptr;

BoardWidget* BoardWidget::GetInstance(QWidget *parent)
{
    if(_boardWidget == nullptr)
        _boardWidget = new BoardWidget(parent);

    return _boardWidget;
}

// Init
void BoardWidget::init()
{
    // Prototype pattern factory
    _piecesFactory = new Factory();

    // Board widget attributes
    _boardSize = (int)BoardWidgetProps::BoardSquaresCount;
    _turn = PiecesColors::White;
    _isChecked = false;
    _isCheckedKingSelected = false;
    _isPawnPromoted = false;
    _pawnPromDialog = new PawnPromDialog();

    // Init under layer attributes
    PiecesColors noColored = PiecesColors::NoColored;
    _underLayerWidget = new QWidget(this);
    _underLayerLayout = new QGridLayout(_underLayerWidget);

    // Init possibleStepsVector2D
    _possibleStepsVector2D.reserve(_boardSize);
    for (unsigned i = 0; i < _boardSize; ++i)
        _possibleStepsVector2D.push_back(QVector<char>(_boardSize, (char)PossibleSteps::Empty));

    // Init underLayerVector2D
    _underLayerVector2D.reserve(_boardSize);
    for (unsigned i = 0; i < _boardSize; ++i)
        _underLayerVector2D.push_back(QVector<Piece *>(_boardSize, nullptr));

    for (unsigned i = 0; i < _boardSize ; ++i)
        for (unsigned j = 0; j < _boardSize; ++j)
            _underLayerVector2D[i][j] = _piecesFactory->CreatePiece(Pieces::Empty, noColored, i, j);

    // Init symbolsVector2D
    _piecesSymbolsVector2D.reserve(_boardSize);
    for (unsigned i = 0; i < _boardSize; ++i)
        _piecesSymbolsVector2D.push_back(QVector<char>(_boardSize, (char)PiecesSymbols::Placeholder));

    for (unsigned i = 0; i < _boardSize ; ++i)
    {
        for (unsigned j = 0; j < _boardSize; ++j)
        {
            // test
            if (i == 2 && j == 2)
               _piecesSymbolsVector2D[i][j] = (char)PiecesSymbols::WhitePawn;




            else if (i == 2 || i == 3 || i == 4 || i == 5)
                _piecesSymbolsVector2D[i][j] = (char)PiecesSymbols::Empty;
            else if (i == 6)
                _piecesSymbolsVector2D[i][j] = (char)PiecesSymbols::WhitePawn;
            else if (i == 1)
                _piecesSymbolsVector2D[i][j] = (char)PiecesSymbols::BlackPawn;
            else if ((i == 7 && j == 0) || (i == 7 && j == 7))
                _piecesSymbolsVector2D[i][j] = (char)PiecesSymbols::WhiteRook;
            else if ((i == 7 && j == 1) || (i == 7 && j == 6))
                _piecesSymbolsVector2D[i][j] = (char)PiecesSymbols::WhiteKnight;
            else if ((i == 7 && j == 2) || (i == 7 && j == 5))
                _piecesSymbolsVector2D[i][j] = (char)PiecesSymbols::WhiteBishop;
            else if (i == 7 && j == 3)
                _piecesSymbolsVector2D[i][j] = (char)PiecesSymbols::WhiteQueen;
            else if (i == 7 && j == 4)
                _piecesSymbolsVector2D[i][j] = (char)PiecesSymbols::WhiteKing;
            else if ((i == 0 && j == 0) || (i == 0 && j == 7))
                _piecesSymbolsVector2D[i][j] = (char)PiecesSymbols::BlackRook;
            else if ((i == 0 && j == 1) || (i == 0 && j == 6))
                _piecesSymbolsVector2D[i][j] = (char)PiecesSymbols::BlackKnight;
            else if ((i == 0 && j == 2) || (i == 0 && j == 5))
                _piecesSymbolsVector2D[i][j] = (char)PiecesSymbols::BlackBishop;
            else if (i == 0 && j == 3)
                _piecesSymbolsVector2D[i][j] = (char)PiecesSymbols::BlackQueen;
            else if (i == 0 && j == 4)
                _piecesSymbolsVector2D[i][j] = (char)PiecesSymbols::BlackKing;
        }
    }

    // Init piecesVector2D
    _boardLayout = new QGridLayout();

    _piecesVector2D.reserve(_boardSize);
    for (unsigned i = 0; i < _boardSize; ++i)
        _piecesVector2D.push_back(QVector<Piece *>(_boardSize, nullptr));

    for (unsigned i = 0; i < _boardSize ; ++i)
        for (unsigned j = 0; j < _boardSize; ++j)
            makeNewPieceBySymbol(_piecesSymbolsVector2D[i][j], i, j);
}

// Public util functions
void BoardWidget::makeNewPieceBySymbol(char symbol, int i, int j)
{
    PiecesColors noColored = PiecesColors::NoColored;
    PiecesColors white = PiecesColors::White;
    PiecesColors black = PiecesColors::Black;

    switch (symbol)
    {
    case (char)PiecesSymbols::Empty:
        _piecesVector2D[i][j] = _piecesFactory->CreatePiece(Pieces::Empty, noColored, i, j, this);
        break;
    case (char)PiecesSymbols::WhitePawn:
        _piecesVector2D[i][j] = _piecesFactory->CreatePiece(Pieces::Pawn, white, i, j, this);
        break;
    case (char)PiecesSymbols::WhiteKnight:
        _piecesVector2D[i][j] = _piecesFactory->CreatePiece(Pieces::Knight, white, i, j, this);
        break;
    case (char)PiecesSymbols::WhiteBishop:
        _piecesVector2D[i][j] = _piecesFactory->CreatePiece(Pieces::Bishop, white, i, j, this);
        break;
    case (char)PiecesSymbols::WhiteRook:
        _piecesVector2D[i][j] = _piecesFactory->CreatePiece(Pieces::Rook, white, i, j, this);
        break;
    case (char)PiecesSymbols::WhiteQueen:
        _piecesVector2D[i][j] = _piecesFactory->CreatePiece(Pieces::Queen, white, i, j, this);
        break;
    case (char)PiecesSymbols::WhiteKing:
        _piecesVector2D[i][j] = _piecesFactory->CreatePiece(Pieces::King, white, i, j, this);
        break;
    case (char)PiecesSymbols::BlackPawn:
        _piecesVector2D[i][j] = _piecesFactory->CreatePiece(Pieces::Pawn, black, i, j, this);
        break;
    case (char)PiecesSymbols::BlackKnight:
        _piecesVector2D[i][j] = _piecesFactory->CreatePiece(Pieces::Knight, black, i, j, this);
        break;
    case (char)PiecesSymbols::BlackBishop:
        _piecesVector2D[i][j] = _piecesFactory->CreatePiece(Pieces::Bishop, black, i, j, this);
        break;
    case (char)PiecesSymbols::BlackRook:
        _piecesVector2D[i][j] = _piecesFactory->CreatePiece(Pieces::Rook, black, i, j, this);
        break;
    case (char)PiecesSymbols::BlackQueen:
        _piecesVector2D[i][j] = _piecesFactory->CreatePiece(Pieces::Queen, black, i, j, this);
        break;
    case (char)PiecesSymbols::BlackKing:
        _piecesVector2D[i][j] = _piecesFactory->CreatePiece(Pieces::King, black, i, j, this);
        break;
    default:
        break;
    }
}

void BoardWidget::clearBoardLayout()
{
    for (unsigned i = 0; i < _boardSize; ++i)
        for (unsigned j = 0; j < _boardSize; ++j)
            _boardLayout->removeWidget(_piecesVector2D[i][j]->getPieceLabel());
}

void BoardWidget::resetBoardLayout()
{
    for (unsigned i = 0; i < _boardSize; ++i)
        for (unsigned j = 0; j < _boardSize; ++j)
            _boardLayout->addWidget(_piecesVector2D[i][j]->getPieceLabel(), i, j);
}

void BoardWidget::getAllAvailStepsForColor(CharVector2D& allAvailStepsVector2D, CharVector2D& imitationVector2D, PiecesColors turn)
{
    if (turn == PiecesColors::Black)
        turn = PiecesColors::White;
    else
        turn = PiecesColors::Black;

    for (int i = 0; i < 8; ++i)
    {
        for (int j = 0; j < 8; ++j)
        {
            if (imitationVector2D[i][j] != (char)PossibleSteps::Empty)
            {
                auto belowPlayerColor = GameWidget::GetInstance()->getBelowPlayerColor();

                if (turn == PiecesColors::Black && !isupper(imitationVector2D[i][j]))
                    _piecesVector2D[i][j]->findAvailableSteps(allAvailStepsVector2D, imitationVector2D, turn, belowPlayerColor);
                else if (turn == PiecesColors::White && isupper(imitationVector2D[i][j]))
                    _piecesVector2D[i][j]->findAvailableSteps(allAvailStepsVector2D, imitationVector2D, turn, belowPlayerColor);
            }
        }
    }
}

// Getters
Piece* BoardWidget::getSelectedPiece() const
{
    return gSelectedPiece;
}

unsigned BoardWidget::getBoardSize() const
{
    return _boardSize;
}

QWidget* BoardWidget::getUnderLayerWidget() const
{
    return _underLayerWidget;
}

QGridLayout* BoardWidget::getUnderLayerLayout() const
{
    return _underLayerLayout;
}

PieceVector2D& BoardWidget::getUnderLayerVector2D()
{
    return _underLayerVector2D;
}

CharVector2D& BoardWidget::getPossibleStepsVector2D()
{
    return _possibleStepsVector2D;
}

QGridLayout* BoardWidget::getBoardLayout() const
{
    return _boardLayout;
}

CharVector2D& BoardWidget::getPiecesSymbolsVector2D()
{
    return _piecesSymbolsVector2D;
}

PieceVector2D& BoardWidget::getPiecesVector2D()
{
    return _piecesVector2D;
}

PiecesColors BoardWidget::getTurn() const
{
    return _turn;
}

// Setters
void BoardWidget::setCheckPosition(int i, int j)
{
    _checkPosition.row = i;
    _checkPosition.column = j;
}

void BoardWidget::setPromotedPawnPosition(int i, int j)
{
    _promotedPawnPos.row = i;
    _promotedPawnPos.column = j;
}

void BoardWidget::setValueInSymbolsVector2D(int i, int j, char value)
{
    _piecesSymbolsVector2D[i][j] = value;
}

// Private util functions
void BoardWidget::makeBoardWidget()
{
    // Set under layer geometry
    _underLayerWidget->setGeometry(0, 0, (int)BoardWidgetProps::BoardWidgetW, (int)BoardWidgetProps::BoardWidgetH);

    // Make layouts
    for (unsigned i = 0; i < _boardSize; ++i)
    {
        for (unsigned j = 0; j < _boardSize; ++j)
        {
            // Make board layout
            _boardLayout->addWidget(_piecesVector2D[i][j]->getPieceLabel(), i, j);

            // Make under layer layout
            _underLayerLayout->addWidget(_underLayerVector2D[i][j]->getPieceLabel(), i, j);
        }
    }

    _underLayerLayout->setVerticalSpacing(0);
    _underLayerLayout->setHorizontalSpacing(0);

    _boardLayout->setVerticalSpacing(0);
    _boardLayout->setHorizontalSpacing(0);
    setLayout(_boardLayout);
}









































// Game functions
void BoardWidget::processLeftButtonClick(Piece* clickedPiece)
{
    // No piece selected
    _isCheckedKingSelected = false;
    if (!isPieceSelected())
    {
        // if clicked right color piece
        if (isCorrectColoredPieceClicked(clickedPiece))
        {
            clearStepsVector2D();
            selectPiece(clickedPiece);
        }
    }
    else
    {
        // if click other piece with same color
        if (isCorrectColoredPieceClicked(clickedPiece) && !isSelectedPieceClicked(clickedPiece))
        {
            clearStepsVector2D();
            selectPiece(clickedPiece);
        }
        // if clicked not available steps
        else if (!isAvailableStepClicked(clickedPiece->getPositionRow(), clickedPiece->getPositionColumn()))
        {
            gSelectedPiece = nullptr;
            clearStepsVector2D();
        }
        else // Clicked available step
        {
            doStep(clickedPiece);
            gSelectedPiece = nullptr;
            clearStepsVector2D();
            switchTurn();
        }
    }

    // If pawn promotion exist, pop-up dialog
    if (_isPawnPromoted)
        showPawnPromDialog();

    // If king checked, mark it in stepsVector2D
    if (isChecked())
        drawCheck();

    //if (!isFirstStep)
        //drawPreviousStep();
    drawUnderLayer();
}

// Private game functions
void BoardWidget::selectPiece(Piece* clickedPiece)
{
    gSelectedPiece = clickedPiece;
    drawSelectedPieceSquare();
    auto belowPlayerColor = GameWidget::GetInstance()->getBelowPlayerColor();
    gSelectedPiece->findAvailableSteps(_possibleStepsVector2D, _piecesSymbolsVector2D, _turn, belowPlayerColor);

    if (gSelectedPiece->isKing(_piecesSymbolsVector2D, gSelectedPiece->getPositionRow(), gSelectedPiece->getPositionColumn()) && isChecked())
        _isCheckedKingSelected = true;
}

void BoardWidget::doStep(Piece* clickedPiece)
{
    //MovesWidget::GetInstance()->setLastMove("alo1", "alo2");

    int iSelected = gSelectedPiece->getPositionRow();
    int jSelected = gSelectedPiece->getPositionColumn();
    int iClicked = clickedPiece->getPositionRow();
    int jClicked = clickedPiece->getPositionColumn();

    // Do step in board layout
    clearBoardLayout();
    doStepInSymbolsVector(iSelected, jSelected, iClicked, jClicked);
    doStepInPiecesVector(iSelected, jSelected, iClicked, jClicked);
    resetBoardLayout();

    _isChecked = false;
    if (!isPiece(gSelectedPiece, PiecesTypes::King))
    {
        // Verify check
        verifyCheck();

        // Verify pawn promotion
        checkPawnPromotion(iClicked, jClicked);
    }
}














void BoardWidget::showPawnPromDialog()
{
    _pawnPromDialog->setModal(true);
    switchTurn();
    _pawnPromDialog->makePawnPromDialog(_turn);
    _pawnPromDialog->show();
}

void BoardWidget::doPawnProm(PiecesTypes pieceType)
{
    _pawnPromDialog->hide();
    _isPawnPromoted = false;

    int i = _promotedPawnPos.row;
    int j = _promotedPawnPos.column;

    PiecesColors color = _piecesVector2D[i][j]->getPieceColor();

    if (color == PiecesColors::White)
        _piecesSymbolsVector2D[i][j] = toupper((char)pieceType);
    else
        _piecesSymbolsVector2D[i][j] = (char)pieceType;

    clearBoardLayout();
    delete _piecesVector2D[i][j];
    switch (pieceType)
    {
    case PiecesTypes::Queen:
        _piecesVector2D[i][j] = _piecesFactory->CreatePiece(Pieces::Queen, color, i, j, this);
        break;
    case PiecesTypes::Rook:
        _piecesVector2D[i][j] = _piecesFactory->CreatePiece(Pieces::Rook, color, i, j, this);
        break;
    case PiecesTypes::Bishop:
        _piecesVector2D[i][j] = _piecesFactory->CreatePiece(Pieces::Bishop, color, i, j, this);
        break;
    case PiecesTypes::Knight:
        _piecesVector2D[i][j] = _piecesFactory->CreatePiece(Pieces::Knight, color, i, j, this);
        break;
    default:
        _piecesVector2D[i][j] = _piecesFactory->CreatePiece(Pieces::Queen, color, i, j, this);
        break;
    }
    resetBoardLayout();

    // Verify check
    gSelectedPiece = _piecesVector2D[i][j];
    verifyCheck();

    // If king checked, mark it in stepsVector2D
    if (isChecked())
        drawCheck();

    //if (!isFirstStep)
        //drawPreviousStep();
    drawUnderLayer();

    switchTurn();
}

void BoardWidget::verifyCheck()
{
    selectPiece(gSelectedPiece);
    if(gSelectedPiece->isGivingCheck(_possibleStepsVector2D, _piecesSymbolsVector2D, _turn))
        _isChecked = true;
    clearStepsVector2D();
}

void BoardWidget::checkPawnPromotion(int i, int j)
{
    if (isPiece(_piecesVector2D[i][j], PiecesTypes::Pawn) && (i ==  0 || i == 7))
    {
        _isPawnPromoted = true;
        setPromotedPawnPosition(i, j);
    }
}

void BoardWidget::doStepInSymbolsVector(int iSelected, int jSelected, int iClicked, int jClicked)
{
    auto temp = _piecesSymbolsVector2D[iSelected][jSelected];
    _piecesSymbolsVector2D[iSelected][jSelected] = (char)PiecesSymbols::Empty;
    _piecesSymbolsVector2D[iClicked][jClicked] = temp;
}

void BoardWidget::doStepInPiecesVector(int iSelected, int jSelected, int iClicked, int jClicked)
{
    delete _piecesVector2D[iClicked][jClicked];
    _piecesVector2D[iClicked][jClicked] = _piecesVector2D[iSelected][jSelected];
    _piecesVector2D[iClicked][jClicked]->setPosition(iClicked, jClicked);

    _piecesVector2D[iSelected][jSelected] = _piecesFactory->CreatePiece(Pieces::Empty, PiecesColors::NoColored, iSelected, jSelected, this);
}

void BoardWidget::switchTurn()
{
    if (_turn == PiecesColors::White)
        _turn = PiecesColors::Black;
    else
        _turn = PiecesColors::White;
}

void BoardWidget::clearStepsVector2D()
{
    for (unsigned i = 0; i < _boardSize; ++i)
        for (unsigned j = 0; j < _boardSize; ++j)
            _possibleStepsVector2D[i][j] = (char)PiecesTypes::Empty;
}

void BoardWidget::clearStepsVector2DExceptCheck()
{
    for (unsigned i = 0; i < _boardSize; ++i)
        for (unsigned j = 0; j < _boardSize; ++j)
        {
            if (_possibleStepsVector2D[i][j] == (char)PossibleSteps::Check)
                continue;
            else
                _possibleStepsVector2D[i][j] = (char)PossibleSteps::Empty;
        }
}

void BoardWidget::drawSelectedPieceSquare()
{
    _possibleStepsVector2D[gSelectedPiece->getPositionRow()][gSelectedPiece->getPositionColumn()] = (char)PossibleSteps::CurrentPiece;
}

void BoardWidget::drawCheck()
{
    _possibleStepsVector2D[_checkPosition.row][_checkPosition.column] = (char)PossibleSteps::Check;

    if (_isCheckedKingSelected)
        _possibleStepsVector2D[_checkPosition.row][_checkPosition.column] = (char)PossibleSteps::CurrentPieceAndCheck;
}

void BoardWidget::drawUnderLayer()
{
    QPixmap temp;
    for (unsigned i = 0; i < _boardSize; ++i)
    {
        for (unsigned j = 0; j < _boardSize; ++j)
        {
            switch (_possibleStepsVector2D[i][j])
            {
            case (char)PossibleSteps::Empty: _underLayerVector2D[i][j]->getPieceLabel()->setPixmap(temp); break;
            case (char)PossibleSteps::CanGo: _underLayerVector2D[i][j]->getPieceLabel()->setPixmap(QPixmap(StepsImages::CanGo)); break;
            case (char)PossibleSteps::CanBeat: _underLayerVector2D[i][j]->getPieceLabel()->setPixmap(QPixmap(StepsImages::CanBeat)); break;
            case (char)PossibleSteps::CurrentPiece: _underLayerVector2D[i][j]->getPieceLabel()->setPixmap(QPixmap(StepsImages::CurrentPiece)); break;
            case (char)PossibleSteps::LastStepFrom: _underLayerVector2D[i][j]->getPieceLabel()->setPixmap(QPixmap(StepsImages::LastStepFrom)); break;
            case (char)PossibleSteps::LastStepTo: _underLayerVector2D[i][j]->getPieceLabel()->setPixmap(QPixmap(StepsImages::LastStepTo)); break;
            case (char)PossibleSteps::LastStepFromAndCanGo: _underLayerVector2D[i][j]->getPieceLabel()->setPixmap(QPixmap(StepsImages::LastStepFromAndCanGo)); break;
            case (char)PossibleSteps::Check: _underLayerVector2D[i][j]->getPieceLabel()->setPixmap(QPixmap(StepsImages::Check)); break;
            case (char)PossibleSteps::CurrentPieceAndCheck: _underLayerVector2D[i][j]->getPieceLabel()->setPixmap(QPixmap(StepsImages::CurrentPieceAndChecked)); break;
            default: _underLayerVector2D[i][j]->getPieceLabel()->setPixmap(temp); break;
            }
        }
    }
}

bool BoardWidget::isPieceSelected()
{
    return (gSelectedPiece != nullptr);
}

bool BoardWidget::isSelectedPieceClicked(Piece *clickedPiece)
{
    int i = clickedPiece->getPositionRow();
    int j = clickedPiece->getPositionColumn();
    return (_possibleStepsVector2D[i][j] == (char)PossibleSteps::CurrentPiece || _possibleStepsVector2D[i][j] == (char)PossibleSteps::CurrentPieceAndCheck);
}

bool BoardWidget::isEmptyClicked(Piece *clickedPiece)
{
    return (clickedPiece->getPieceType() == PiecesTypes::Empty);
}

bool BoardWidget::isOppositePieceClicked(Piece *clickedPiece)
{
    return (clickedPiece->getPieceColor() != _turn);
}

bool BoardWidget::isCorrectColoredPieceClicked(Piece *clickedPiece)
{
    return (!isEmptyClicked(clickedPiece) && !isOppositePieceClicked(clickedPiece));
}

bool BoardWidget::isAvailableStepClicked(int i, int j)
{
    char symbol = _possibleStepsVector2D[i][j];
    return (symbol == (char)PossibleSteps::CanGo || symbol == (char)PossibleSteps::CanBeat
            || symbol == (char)PossibleSteps::LastStepFromAndCanGo);
}

bool BoardWidget::isChecked()
{
    return _isChecked;
}

bool BoardWidget::isPiece(Piece* piece, PiecesTypes pieceType)
{
    return (piece->getPieceType() == pieceType);
}
