#include "boardwidget.hpp"
#include "pieces_helpers.hpp"
#include "factory.hpp"
#include "piece.hpp"

BoardWidget::BoardWidget(QWidget *parent)
    : QWidget{parent}
{
    // Setup
    setup();

    // Make BoardWidget
    makeBoardWidget();
}

BoardWidget::~BoardWidget() {}

// Singlton pattern realization
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
    // Board attributes
    _boardLayout = new QGridLayout();
    _piecesFactory = new Factory();
    _boardSize = (int)BoardWidgetProps::BoardSquaresCount + 1;

    // Setup symbolsVector2D
    _symbolsVector2D.reserve(_boardSize);
    for (unsigned i = 0; i < _boardSize; ++i)
        _symbolsVector2D.push_back(QVector<char>(_boardSize, (char)PiecesSymbols::Placeholder));

    for (unsigned i = 1; i < _boardSize ; ++i)
    {
        for (unsigned j = 1; j < _boardSize; ++j)
        {
            if (i == 3 || i == 4 || i == 5 || i == 6)
                _symbolsVector2D[i][j] = (char)PiecesSymbols::Empty;
            else if (i == 7)
                _symbolsVector2D[i][j] = (char)PiecesSymbols::WhitePawn;
            else if (i == 2)
                _symbolsVector2D[i][j] = (char)PiecesSymbols::BlackPawn;
            else if ((i == 8 && j == 1) || (i == 8 && j == 8))
                _symbolsVector2D[i][j] = (char)PiecesSymbols::WhiteRook;
            else if ((i == 8 && j == 2) || (i == 8 && j == 7))
                _symbolsVector2D[i][j] = (char)PiecesSymbols::WhiteKnight;
            else if ((i == 8 && j == 3) || (i == 8 && j == 6))
                _symbolsVector2D[i][j] = (char)PiecesSymbols::WhiteBishop;
            else if (i == 8 && j == 4)
                _symbolsVector2D[i][j] = (char)PiecesSymbols::WhiteQueen;
            else if (i == 8 && j == 5)
                _symbolsVector2D[i][j] = (char)PiecesSymbols::WhiteKing;
            else if ((i == 1 && j == 1) || (i == 1 && j == 8))
                _symbolsVector2D[i][j] = (char)PiecesSymbols::BlackRook;
            else if ((i == 1 && j == 2) || (i == 1 && j == 7))
                _symbolsVector2D[i][j] = (char)PiecesSymbols::BlackKnight;
            else if ((i == 1 && j == 3) || (i == 1 && j == 6))
                _symbolsVector2D[i][j] = (char)PiecesSymbols::BlackBishop;
            else if (i == 1 && j == 4)
                _symbolsVector2D[i][j] = (char)PiecesSymbols::BlackQueen;
            else if (i == 1 && j == 5)
                _symbolsVector2D[i][j] = (char)PiecesSymbols::BlackKing;
        }
    }

    // Setup piecesVector2D                          /******* NOT COMPLETED *******/
    PiecesColors white = PiecesColors::White;
    PiecesColors black = PiecesColors::Black;

    _piecesVector2D.reserve(_boardSize);
    for (unsigned i = 0; i < _boardSize; ++i)
        _piecesVector2D.push_back(QVector<Piece *>(_boardSize, nullptr));

    for (unsigned i = 1; i < _boardSize ; ++i)
    {
        for (unsigned j = 1; j < _boardSize; ++j)
        {
            switch (_symbolsVector2D[i][j])
            {
            case (char)PiecesSymbols::Empty:
                //_piecesVector2D[i][j] = _piecesFactory->CreatePiece(Pieces::Empty);
                break;
            case (char)PiecesSymbols::WhitePawn:
                _piecesVector2D[i][j] = _piecesFactory->CreatePiece(Pieces::Pawn, white, i, j);
                break;
            case (char)PiecesSymbols::BlackPawn:
                _piecesVector2D[i][j] = _piecesFactory->CreatePiece(Pieces::Pawn, black, i, j);
                break;
            case (char)PiecesSymbols::WhiteRook:
                //_piecesVector2D[i][j] = _piecesFactory->CreatePiece(Pieces::Rook);
                break;
            case (char)PiecesSymbols::WhiteKnight:
                //_piecesVector2D[i][j] = _piecesFactory->CreatePiece(Pieces::Knight);
                break;
            case (char)PiecesSymbols::WhiteBishop:
                //_piecesVector2D[i][j] = _piecesFactory->CreatePiece(Pieces::Bishop);
                break;
            case (char)PiecesSymbols::WhiteQueen:
                //_piecesVector2D[i][j] = _piecesFactory->CreatePiece(Pieces::Queen);
                break;
            case (char)PiecesSymbols::WhiteKing:
                //_piecesVector2D[i][j] = _piecesFactory->CreatePiece(Pieces::King);
                break;
            case (char)PiecesSymbols::BlackRook:
                //_piecesVector2D[i][j] = _piecesFactory->CreatePiece(Pieces::Rook);
                break;
            case (char)PiecesSymbols::BlackKnight:
                //_piecesVector2D[i][j] = _piecesFactory->CreatePiece(Pieces::Knight);
                break;
            case (char)PiecesSymbols::BlackBishop:
                //_piecesVector2D[i][j] = _piecesFactory->CreatePiece(Pieces::Bishop);
                break;
            case (char)PiecesSymbols::BlackQueen:
                //_piecesVector2D[i][j] = _piecesFactory->CreatePiece(Pieces::Queen);
                break;
            case (char)PiecesSymbols::BlackKing:
                //_piecesVector2D[i][j] = _piecesFactory->CreatePiece(Pieces::King);
                break;
            default:
                break;
            }
        }
    }



    //************************************************ TESTING ************************************* //
//    QDebug deb = qDebug();
//    for (unsigned i = 0; i < _boardSize; ++i)
//    {
//        for (unsigned j = 0; j < _boardSize; ++j)
//        {
//            if (_piecesVector2D[i][j] != nullptr)
//                deb.nospace() << _piecesVector2D[i][j]->_image << " ";
//        }
//        deb.nospace() << "\n";
//    }
    //************************************************ TESTING ************************************* //
}

// Public util functions
void BoardWidget::showBoard()
{

}

// Private util functions
void BoardWidget::makeBoardWidget()
{
//    for (unsigned i = 0; i < _boardSize - 1; ++i)
//    {
//        for (unsigned j = 0; j < _boardSize - 1; ++j)
//        {
//            _piecesVector2D[i + 1][j + 1]->getPieceLabel()->setParent(this);
//            _boardLayout->addWidget(_piecesVector2D[i + 1][j + 1]->getPieceLabel(), i + 1, j + 1);
//        }
//    }

//    _boardLayout->setVerticalSpacing(0);
//    _boardLayout->setHorizontalSpacing(0);
//    setLayout(_boardLayout);
}
