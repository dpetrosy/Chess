#include "boardwidget.hpp"
#include "helpers.hpp"
#include "moveswidget.hpp"
#include "gamewidget.hpp"
#include "pieces_helpers.hpp"
#include "factory.hpp"
#include "piece.hpp"
#include "clickablelabel.hpp"

BoardWidget::BoardWidget(QWidget *parent)
    : QWidget{parent}
{
    // Setup
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

// Setup
void BoardWidget::init()
{
    // Prototype pattern factory
    _piecesFactory = new Factory();

    // Board widget attributes
    _boardSize = (int)BoardWidgetProps::BoardSquaresCount;
    _selectedPiece = nullptr;
    _turn = PiecesColors::White;
    _piecesPath = ImagesPaths::piecesPath;

    // Setup under layer attributes
    PiecesColors noColored = PiecesColors::NoColored;
    _underLayerWidget = new QWidget(this);
    _underLayerLayout = new QGridLayout(_underLayerWidget);

    // Setup possibleStepsVector2D
    _possibleStepsVector2D.reserve(_boardSize);
    for (unsigned i = 0; i < _boardSize; ++i)
        _possibleStepsVector2D.push_back(QVector<char>(_boardSize, (char)PossibleSteps::Empty));

    // Setup underLayerVector2D
    _underLayerVector2D.reserve(_boardSize);
    for (unsigned i = 0; i < _boardSize; ++i)
        _underLayerVector2D.push_back(QVector<Piece *>(_boardSize, nullptr));

    for (unsigned i = 0; i < _boardSize ; ++i)
        for (unsigned j = 0; j < _boardSize; ++j)
            _underLayerVector2D[i][j] = _piecesFactory->CreatePiece(Pieces::Empty, noColored, i, j);

    // Setup symbolsVector2D
    _piecesSymbolsVector2D.reserve(_boardSize);
    for (unsigned i = 0; i < _boardSize; ++i)
        _piecesSymbolsVector2D.push_back(QVector<char>(_boardSize, (char)PiecesSymbols::Placeholder));

    for (unsigned i = 0; i < _boardSize ; ++i)
    {
        for (unsigned j = 0; j < _boardSize; ++j)
        {
            if (i == 2 || i == 3 || i == 4 || i == 5)
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

    // Setup piecesVector2D
        _boardLayout = new QGridLayout();
    PiecesColors white = PiecesColors::White;
    PiecesColors black = PiecesColors::Black;

    _piecesVector2D.reserve(_boardSize);
    for (unsigned i = 0; i < _boardSize; ++i)
        _piecesVector2D.push_back(QVector<Piece *>(_boardSize, nullptr));

    for (unsigned i = 0; i < _boardSize ; ++i)
    {
        for (unsigned j = 0; j < _boardSize; ++j)
        {
            switch (_piecesSymbolsVector2D[i][j])
            {
            case (char)PiecesSymbols::Empty:
                _piecesVector2D[i][j] = _piecesFactory->CreatePiece(Pieces::Empty, noColored, i, j);
                break;
            case (char)PiecesSymbols::WhitePawn:
                _piecesVector2D[i][j] = _piecesFactory->CreatePiece(Pieces::Pawn, white, i, j);
                break;
            case (char)PiecesSymbols::WhiteKnight:
                _piecesVector2D[i][j] = _piecesFactory->CreatePiece(Pieces::Knight, white, i, j);
                break;
            case (char)PiecesSymbols::WhiteBishop:
                _piecesVector2D[i][j] = _piecesFactory->CreatePiece(Pieces::Bishop, white, i, j);
                break;
            case (char)PiecesSymbols::WhiteRook:
                _piecesVector2D[i][j] = _piecesFactory->CreatePiece(Pieces::Rook, white, i, j);
                break;
            case (char)PiecesSymbols::WhiteQueen:
                _piecesVector2D[i][j] = _piecesFactory->CreatePiece(Pieces::Queen, white, i, j);
                break;
            case (char)PiecesSymbols::WhiteKing:
                _piecesVector2D[i][j] = _piecesFactory->CreatePiece(Pieces::King, white, i, j);
                break;
            case (char)PiecesSymbols::BlackPawn:
                _piecesVector2D[i][j] = _piecesFactory->CreatePiece(Pieces::Pawn, black, i, j);
                break;
            case (char)PiecesSymbols::BlackKnight:
                _piecesVector2D[i][j] = _piecesFactory->CreatePiece(Pieces::Knight, black, i, j);
                break;
            case (char)PiecesSymbols::BlackBishop:
                _piecesVector2D[i][j] = _piecesFactory->CreatePiece(Pieces::Bishop, black, i, j);
                break;
            case (char)PiecesSymbols::BlackRook:
                _piecesVector2D[i][j] = _piecesFactory->CreatePiece(Pieces::Rook, black, i, j);
                break;
            case (char)PiecesSymbols::BlackQueen:
                _piecesVector2D[i][j] = _piecesFactory->CreatePiece(Pieces::Queen, black, i, j);
                break;
            case (char)PiecesSymbols::BlackKing:
                _piecesVector2D[i][j] = _piecesFactory->CreatePiece(Pieces::King, black, i, j);
                break;
            default:
                break;
            }
        }
    }
}

// Getters
Piece* BoardWidget::getSelectedPiece() const
{
    return _selectedPiece;
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

QString BoardWidget::getPiecesPath() const
{
    return _piecesPath;
}


// Private util functions
void BoardWidget::makeBoardWidget()
{
    // Set under layer geometry
    _underLayerWidget->setGeometry(0, 0, (int)BoardWidgetProps::BoardW, (int)BoardWidgetProps::BoardH);

    // Make layouts
    for (unsigned i = 0; i < _boardSize; ++i)
    {
        for (unsigned j = 0; j < _boardSize; ++j)
        {
            // Make board layout
            connect(_piecesVector2D[i][j]->getPieceLabel(), &ClickableLabel::clickedLeftButton, this,
                    std::bind(&BoardWidget::processLeftButtonClick, this, _piecesVector2D[i][j]));
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









































// Public slots
void BoardWidget::processLeftButtonClick(Piece* clickedPiece)
{
    // No piece selected
    if (!isPieceSelected())
    {
        // if clicked right color piece
        if (isCorrectColoredPieceClicked(clickedPiece))
            pieceSelected(clickedPiece);
    }
    else
    {
        // if click other piece with same color
        if (isCorrectColoredPieceClicked(clickedPiece) && !isSelectedPieceClicked(clickedPiece))
            pieceSelected(clickedPiece);
        // if clicked not available steps
        else if (!isAvailableStepClicked(clickedPiece->getPositionRow(), clickedPiece->getPositionColumn()))
        {
            _selectedPiece = nullptr;
            clearStepsVector2D();
        }
        else // Clicked available step
        {
            doStep(clickedPiece);
            _selectedPiece = nullptr;
            //clearStepsVector2D();
            switchTurn();
        }
    }

    //if (!isFirstStep)
        //drawPreviousStep();
    drawUnderLayer();
}

// Private game functions
void BoardWidget::pieceSelected(Piece* clickedPiece)
{
    clearStepsVector2D();
    _selectedPiece = clickedPiece;
    markSelectedPieceSquare();
    auto belowPlayerColor = GameWidget::GetInstance()->getBelowPlayerColor();
    _selectedPiece->findAvailableSteps(_possibleStepsVector2D, _piecesSymbolsVector2D, _turn, belowPlayerColor);
}

void BoardWidget::doStep(Piece* clickedPiece)
{
    //MovesWidget::GetInstance()->setLastMove("alo1", "alo2");

    int iSelected = _selectedPiece->getPositionRow();
    int jSelected = _selectedPiece->getPositionColumn();
    int iClicked = clickedPiece->getPositionRow();
    int jClicked = clickedPiece->getPositionColumn();

    clearBoardLayout();
    doStepInSymbolsVector(iSelected, jSelected, iClicked, jClicked);
    doStepInPiecesVector(iSelected, jSelected, iClicked, jClicked);
    resetBoardLayout();

    pieceSelected(_selectedPiece);
    if(_selectedPiece->isGivingCheck(_possibleStepsVector2D, _piecesSymbolsVector2D, _turn))
    {
        qDebug() << "asdasd";

            QDebug deb = qDebug();
            for (unsigned i = 0; i < _boardSize; ++i)
            {
                for (unsigned j = 0; j < _boardSize; ++j)
                {
                    deb.nospace() << _possibleStepsVector2D[i][j] << " ";
                }
                deb.nospace() << "\n";
            }

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

    // delete in future
    //connect(_piecesVector2D[iSelected][jSelected]->getPieceLabel(), &ClickableLabel::clickedLeftButton, this,
     //       std::bind(&BoardWidget::processLeftButtonClick, this, _piecesVector2D[iSelected][jSelected]));
}

void BoardWidget::switchTurn()
{
    if (_turn == PiecesColors::White)
        _turn = PiecesColors::Black;
    else
        _turn = PiecesColors::White;
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

void BoardWidget::clearStepsVector2D()
{
    for (unsigned i = 0; i < _boardSize; ++i)
        for (unsigned j = 0; j < _boardSize; ++j)
            _possibleStepsVector2D[i][j] = (char)PiecesTypes::Empty;
}

void BoardWidget::markSelectedPieceSquare()
{
    _possibleStepsVector2D[_selectedPiece->getPositionRow()][_selectedPiece->getPositionColumn()] = (char)PossibleSteps::CurrentPiece;
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
            default: _underLayerVector2D[i][j]->getPieceLabel()->setPixmap(temp); break;
            }
        }
    }
}

bool BoardWidget::isPieceSelected()
{
    return (_selectedPiece != nullptr);
}

bool BoardWidget::isSelectedPieceClicked(Piece *clickedPiece)
{
    int i = clickedPiece->getPositionRow();
    int j = clickedPiece->getPositionColumn();
    return (_possibleStepsVector2D[i][j] == (char)PossibleSteps::CurrentPiece);
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
