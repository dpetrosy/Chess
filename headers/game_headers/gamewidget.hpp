#ifndef GAMEWIDGET_HPP
#define GAMEWIDGET_HPP

#include <QWidget>
#include <QObject>
#include <QDebug>

#include "game_helpers.hpp"

// Singltone pattern used
class GameWidget : public QWidget
{
    Q_OBJECT

public:
    // Singltone realization
    GameWidget(GameWidget &other) = delete;
    GameWidget& operator=(const GameWidget&) = delete;
    static GameWidget *GetInstance(QWidget *parent = nullptr);
    virtual ~GameWidget();

    // Public util functions
    void showGameElements();

    // Getters
    GameData *getGameData() const;
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

private:
    explicit GameWidget(QWidget *parent = nullptr);

    // Setup
    void setup();

    // Private util functions
    void makeGameWidget();

private:
    // Singltone realization
    static GameWidget *_gameWidget;

    // Game elements
    GameData *_gameData;
    BoardWidget *_boardWidget;
};

#endif // GAMEWIDGET_HPP
