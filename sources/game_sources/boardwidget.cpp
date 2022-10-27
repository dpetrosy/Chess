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
    _boardSize = (int)BoardWidgetProps::BoardSquaresCount;

    // Setup piecesVector2D              /******* NOT COMPLETED *******/
    std::fill(_piecesVector2D.begin(), _piecesVector2D.end(), QVector<Piece *>(_boardSize + 1));

    /*
    // Setup symbolsVector2D
    std::fill(_symbolsVector2D.begin(), _symbolsVector2D.end(), QVector<char>(boardSize + 1));

    for (unsigned i = 0; i < boardSize + 1; ++i)
    {
        for (auto j = 0; j < (int)BoardWidgetProps::BoardSquaresCount + 1; ++i)
        {
            // Set 0 column and 0 row with *
            if (i == 0 || j == 0)
                _symbolsVector2D[i][j] = (char)PiecesSymbols::Placeholder;
            else if (i == 3 || i == 4 || i == 5 || i == 6)
                _symbolsVector2D[i][j] = (char)PiecesSymbols::Emptiness;
            else if (i == 2)
                _symbolsVector2D[i][j] = (char)PiecesSymbols::WhitePawn;
            else if (i == 7)
                _symbolsVector2D[i][j] = (char)PiecesSymbols::BlackPawn;
            else if ((i == 1 && j == 1) || (i == 8 && j == 8))
                _symbolsVector2D[i][j] = (char)PiecesSymbols::BlackRook;
            else if ((i == 1 && j == 2) || (i == 1 && j == 7))
                _symbolsVector2D[i][j] = (char)PiecesSymbols::BlackKnight;
            else if ((i == 1 && j == 3) || (i == 1 && j == 6))
                _symbolsVector2D[i][j] = (char)PiecesSymbols::BlackBishop;

        }
    }
    */




    /*
    for (auto i = 0; i < (int)BoardWidgetProps::BoardSquaresCount + 1; ++i)
    {
        for (auto j = 0; j < (int)BoardWidgetProps::BoardSquaresCount + 1; ++i)
        {
            // Set 0 column and 0 row with nullptr
            if (i == 0 || j == 0)
                _piecesVector2D[i][j] = nullptr;
        }
    }*/



    //QVectorIterator<>

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
