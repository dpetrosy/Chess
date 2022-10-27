#include "boardwidget.hpp"

BoardWidget::BoardWidget(QWidget *parent)
    : QWidget{parent}
{
    // Setup
    setup();

    // Make BoardWidget
    makeBoardWidget();
}

BoardWidget::~BoardWidget() {}

// Singltone realization
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
    _boardLayout = new QGridLayout(this);
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
            else if ((i == 8 && j == 3) || (8 == 8 && j == 6))
                _symbolsVector2D[i][j] = (char)PiecesSymbols::WhiteBishop;
            else if (i == 8 && j == 4)
                _symbolsVector2D[i][j] = (char)PiecesSymbols::WhiteQueen;
            else if (i == 8 && j == 5)
                _symbolsVector2D[i][j] = (char)PiecesSymbols::WhiteKing;
            else if ((i == 1 && j == 1) || (i == 1 && j == 8))
                _symbolsVector2D[i][j] = (char)PiecesSymbols::BlackRook;
            else if ((i == 1 && j == 2) || (i == 1 && j == 7))
                _symbolsVector2D[i][j] = (char)PiecesSymbols::BlackKnight;
            else if ((i == 1 && j == 3) || (8 == 1 && j == 6))
                _symbolsVector2D[i][j] = (char)PiecesSymbols::BlackBishop;
            else if (i == 1 && j == 4)
                _symbolsVector2D[i][j] = (char)PiecesSymbols::BlackQueen;
            else if (i == 1 && j == 5)
                _symbolsVector2D[i][j] = (char)PiecesSymbols::BlackKing;
        }
    }

    // Setup piecesVector2D              /******* NOT COMPLETED *******/
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
                break;
            case (char)PiecesSymbols::WhitePawn:
                break;
            case (char)PiecesSymbols::BlackPawn:
                break;
            case (char)PiecesSymbols::WhiteRook:
                break;
            case (char)PiecesSymbols::WhiteKnight:
                break;
            case (char)PiecesSymbols::WhiteBishop:
                break;
            case (char)PiecesSymbols::WhiteQueen:
                break;
            case (char)PiecesSymbols::WhiteKing:
                break;
            case (char)PiecesSymbols::BlackRook:
                break;
            case (char)PiecesSymbols::BlackKnight:
                break;
            case (char)PiecesSymbols::BlackBishop:
                break;
            case (char)PiecesSymbols::BlackQueen:
                break;
            case (char)PiecesSymbols::BlackKing:
                break;
            default:
                break;
            }
        }
    }


//    QDebug deb = qDebug();
//    for (unsigned i = 0; i < _boardSize; ++i)
//    {
//        for (unsigned j = 0; j < _boardSize; ++j)
//        {
//            deb.nospace() << _symbolsVector2D[i][j] << " ";
//        }
//        deb.nospace() << "\n";
//    }
}

// Public util functions
void BoardWidget::showBoard()
{
    //setLayout(_board);
}

// Private util functions
void BoardWidget::makeBoardWidget()
{

}
