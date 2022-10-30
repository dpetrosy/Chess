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

// Singlton pattern realization
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
    // Game elements
    _gameData = new GameData();
    _boardWidget = BoardWidget::GetInstance(this);
}

// Public util functions
void GameWidget::showGameElements()
{
    // Set board as background image
    MainWindow::GetInstance()->setBackgroundImage("board.jpg");

    _boardWidget->showBoard();
}

// Private util functions
void GameWidget::makeGameWidget()
{
    // Set BoardWidget geometry
    _boardWidget->setGeometry((int)BoardWidgetProps::BoardX, (int)BoardWidgetProps::BoardY, (int)BoardWidgetProps::BoardW, (int)BoardWidgetProps::BoardH);
    qDebug() << _boardWidget->size();
}

// Getters
GameData *GameWidget::getGameData() const
{
    return _gameData;
}

GameVariants GameWidget::getGameVariant() const
{
    return _gameData->gameVariant;
}

bool GameWidget::getIsTimeAvailable() const
{
    return _gameData->isTimeAvailable;
}

unsigned GameWidget::getGameMinutes() const
{
    return _gameData->gameMinutes;
}

unsigned GameWidget::getIncrementSeconds() const
{
    return _gameData->incrementSeconds;
}

bool GameWidget::getIsWhite() const
{
    return _gameData->isWhite;
}

QuickGames GameWidget::getQuickGame() const
{
    return _gameData->quickGame;
}

// Setters
void GameWidget::setGameData(GameData *gameData)
{
    _gameData = gameData;
}

void GameWidget::setGameVariant(GameVariants gameVariant)
{
    _gameData->gameVariant = gameVariant;
}

void GameWidget::setIsTimeAvailable(bool isTimeAvailable)
{
    _gameData->isTimeAvailable = isTimeAvailable;
}

void GameWidget::setGameMinutes(unsigned gameMinutes)
{
    _gameData->gameMinutes = gameMinutes;
}

void GameWidget::setIncrementSeconds(unsigned incrementSeconds)
{
    _gameData->incrementSeconds = incrementSeconds;
}

void GameWidget::setIsWhite(bool isWhite)
{
    _gameData->isWhite = isWhite;
}

void GameWidget::setQuickGame(QuickGames quickGame)
{
    _gameData->quickGame = quickGame;
}
