#include "boardwidget.hpp"
#include "helpers.hpp"
#include "pieces_helpers.hpp"
#include "factory.hpp"
#include "piece.hpp"
#include "clickablelabel.hpp"

BoardWidget::BoardWidget(QWidget *parent)
    : QWidget{parent}
{
    // Setup
    setup();

    // Make BoardWidget
    makeBoardWidget();
}

BoardWidget::~BoardWidget() {}

// Singleton pattern realization
BoardWidget* BoardWidget::_boardWidget = nullptr;

BoardWidget *BoardWidget::GetInstance(QWidget *parent)
{
    if(_boardWidget == nullptr)
        _boardWidget = new BoardWidget(parent);

    return _boardWidget;
}

// Setup
void BoardWidget::setup()
{
    // Prototype pattern factory
    _piecesFactory = new Factory();

    // Board widget attributes
    _boardSize = (int)BoardWidgetProps::BoardSquaresCount;
    _selectedPiece = nullptr;
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


    {
    //************************************************ TESTING ************************************* //
//    QDebug deb = qDebug();
//    for (unsigned i = 0; i < _boardSize; ++i)
//    {
//        for (unsigned j = 0; j < _boardSize; ++j)
//        {
//            if (_piecesVector2D[i][j] != nullptr)
//                deb.nospace() << (char)_piecesVector2D[i][j]->getPieceType() << " ";
//        }
//        deb.nospace() << "\n";
//    }
    //************************************************ TESTING ************************************* //


//        QDebug deb = qDebug();
//        for (unsigned i = 0; i < _boardSize; ++i)
//        {
//            for (unsigned j = 0; j < _boardSize; ++j)
//            {
//                deb.nospace() << _possibleStepsVector2D[i][j] << " ";
//            }
//            deb.nospace() << "\n";
//        }

    }
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
    static PiecesColors turn = PiecesColors::White;
    //static PiecesColors turn = PiecesColors::White;


    if (!isPieceSelected())
    {
        if (isCorrectColoredPieceClicked(clickedPiece, turn))
            makeUnderLayerForSelectedPiece(clickedPiece, turn);
    }
    else
    {
        if (isCorrectColoredPieceClicked(clickedPiece, turn))
            makeUnderLayerForSelectedPiece(clickedPiece, turn);
        else if (!isAvailableStepClicked(clickedPiece->getPositionRow(), clickedPiece->getPositionColumn()))
        {
            _selectedPiece = nullptr;
            resetUnderLayer();
        }
        //else if ()
    }

    drawUnderLayer();
}

// Private game functions
void BoardWidget::makeUnderLayerForSelectedPiece(Piece* clickedPiece, PiecesColors turn)
{
    clearStepsVector2D();
    _selectedPiece = clickedPiece;



    _selectedPiece->findAvailableSteps(_possibleStepsVector2D, _piecesSymbolsVector2D);
    markSelectedPieceSquare();
    //drawPreviousStep();

    //************************************************************************
    QDebug deb = qDebug();
    for (unsigned i = 0; i < _boardSize; ++i)
    {
        for (unsigned j = 0; j < _boardSize; ++j)
        {
            deb.nospace() << _possibleStepsVector2D[i][j] << " ";
        }
        deb.nospace() << "\n";
    }
    //**************************************************************************
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
            default: _underLayerVector2D[i][j]->getPieceLabel()->setPixmap(temp); break;
            }
        }
    }
}

void BoardWidget::clearStepsVector2D()
{
    for (unsigned i = 0; i < _boardSize; ++i)
        for (unsigned j = 0; j < _boardSize; ++j)
            _possibleStepsVector2D[i][j] = (char)PiecesTypes::Empty;
}

bool BoardWidget::isPieceSelected()
{
    return (_selectedPiece != nullptr);
}

bool BoardWidget::isEmptyClicked(Piece *clickedPiece)
{
    return (clickedPiece->getPieceType() == PiecesTypes::Empty);
}

bool BoardWidget::isOppositePieceClicked(Piece *clickedPiece, PiecesColors turn)
{
    return (clickedPiece->getPieceColor() != turn);
}

bool BoardWidget::isCorrectColoredPieceClicked(Piece *clickedPiece, PiecesColors turn)
{
    return (!isEmptyClicked(clickedPiece) && !isOppositePieceClicked(clickedPiece, turn));
}

bool BoardWidget::isAvailableStepClicked(int i, int j)
{
    char symbol = _possibleStepsVector2D[i][j];
    return (symbol == (char)PossibleSteps::CanGo || symbol == (char)PossibleSteps::CanBeat ||
            symbol == (char)PossibleSteps::LastStepFromAndCanGo || symbol == (char)PossibleSteps::LastStepToAndCanBeat);
}

void BoardWidget::markSelectedPieceSquare()
{
    _possibleStepsVector2D[_selectedPiece->getPositionRow()][_selectedPiece->getPositionColumn()] = (char)PossibleSteps::CurrentPiece;
}

//void BoardWidget::is

void BoardWidget::resetUnderLayer()
{
    clearStepsVector2D();
    //drawPreviousStep();
}
