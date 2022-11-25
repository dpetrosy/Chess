#include "gamewidget.hpp"
#include "boardwidget.hpp"
#include "moveswidget.hpp"

#include "mainwindow.hpp"
#include "helpers.hpp"

GameWidget::GameWidget(QWidget *parent)
    : QWidget{parent}
{
    // Init
    init();

    // Make GameWidget
    makeGameWidget();
}

GameWidget::~GameWidget() {}

// Singlton pattern realization
GameWidget* GameWidget::_gameWidget = nullptr;

GameWidget* GameWidget::GetInstance(QWidget *parent)
{
    if(_gameWidget == nullptr)
        _gameWidget = new GameWidget(parent);

    return _gameWidget;
}

// Init
void GameWidget::init()
{
    // Game elements
    _boardWidget = BoardWidget::GetInstance(this);
    _movesWidget = MovesWidget::GetInstance(this);
}

// Public util functions
void GameWidget::showGameElements()
{
    // Set board as background image
    //MainWindow::GetInstance()->setBackgroundImage("dark/board1.jpg");
}

// Private util functions
void GameWidget::makeGameWidget()
{
    // Set BoardWidget geometry
    _boardWidget->setGeometry((int)BoardWidgetProps::BoardX, (int)BoardWidgetProps::BoardY, (int)BoardWidgetProps::BoardW, (int)BoardWidgetProps::BoardH);
}

// Getters
GameData GameWidget::getGameData() const
{
    return _gameData;
}

QString GameWidget::getGameVariant() const
{
    return _gameData.gameVariant;
}

bool GameWidget::getIsTimeAvailable() const
{
    return _gameData.isTimeAvailable;
}

unsigned GameWidget::getGameMinutes() const
{
    return _gameData.gameMinutes;
}

unsigned GameWidget::getIncrementSeconds() const
{
    return _gameData.incrementSeconds;
}

PiecesColors GameWidget::getBelowPlayerColor() const
{
    return _gameData.belowPlayerColor;
}

QString GameWidget::getQuickGame() const
{
    return _gameData.quickGame;
}

// Setters
void GameWidget::setGameVariant(QString gameVariant)
{
    _gameData.gameVariant = gameVariant;
}

void GameWidget::setIsTimeAvailable(bool isTimeAvailable)
{
    _gameData.isTimeAvailable = isTimeAvailable;
}

void GameWidget::setGameMinutes(unsigned gameMinutes)
{
    _gameData.gameMinutes = gameMinutes;
}

void GameWidget::setIncrementSeconds(unsigned incrementSeconds)
{
    _gameData.incrementSeconds = incrementSeconds;
}

void GameWidget::setBelowPlayerColor(PiecesColors color)
{
    _gameData.belowPlayerColor = color;
}

void GameWidget::setQuickGame(QString quickGame)
{
    _gameData.quickGame = quickGame;
}
