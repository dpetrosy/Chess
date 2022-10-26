#include "gamewidget.hpp"
#include "boardwidget.hpp"
#include "mainwindow.hpp"
#include "helpers.hpp"

GameWidget::GameWidget(QWidget *parent)
    : QWidget{parent}
{
    // Setup
    setup();

    // Make GameWidget
    makeGameWidget();
}

GameWidget::~GameWidget() {}

// Singltone realization
GameWidget *GameWidget::_gameWidget = nullptr;

GameWidget *GameWidget::GetInstance(QWidget *parent)
{
    if(_gameWidget == nullptr)
        _gameWidget = new GameWidget(parent);

    return _gameWidget;
}

// Setup
void GameWidget::setup()
{
    _boardWidget = BoardWidget::GetInstance(this);
}

// Public util functions
void GameWidget::showGameElements()
{
    // Set board as background image
    MainWindow::GetInstance()->setBackgroundImage("board.png");

    _boardWidget->showBoard();
}

// Private util functions
void GameWidget::makeGameWidget()
{
    // Set BoardWidget geometry
    _boardWidget->setGeometry((int)BoardWidgetProps::BoardX, (int)BoardWidgetProps::BoardY, (int)BoardWidgetProps::BoardW, (int)BoardWidgetProps::BoardH);
}
