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
    // Game elements
    _gameData = new GameData();
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

// Getters
GameData *getGameData() const
{
    return _gameData;

}

GameVariants getGameVariant() const;
bool getIsTimeAvailable() const;
unsigned getGameMinutes() const;
unsigned getIncremetSeconds() const;
bool getIsWhite() const;
QuickGames getQuickGame() const;

// Setters
void setGameData(GameData *gameData);
void setGameVariant(GameVariants gameVariant);
void setIsTimeAvailable(bool isTimeAvailable);
void setGameMinutes(unsigned gameMinutes);
void setIncremetSeconds(unsigned incremetSeconds);
void setIsWhite(bool isWhite);
void setQuickGame(QuickGames quickGame);
