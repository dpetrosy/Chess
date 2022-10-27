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

    // Setup piecesVector2D
    std::fill(_piecesVector2D.begin(), _piecesVector2D.end(), QVector<Piece *>(9));



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
