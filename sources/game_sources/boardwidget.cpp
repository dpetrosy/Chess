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
    _boardLayout = new QGridLayout(this);

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
