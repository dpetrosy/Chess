#ifndef GAMEWIDGET_HPP
#define GAMEWIDGET_HPP

#include <QWidget>
#include <QObject>
#include <QDebug>

#include "game_helpers.hpp"

// Singlton pattern used
class GameWidget : public QWidget
{
    Q_OBJECT

public:
    // Singleton pattern realization
    GameWidget(GameWidget &other) = delete;
    GameWidget& operator=(const GameWidget&) = delete;
    static GameWidget *GetInstance(QWidget *parent = nullptr);
    virtual ~GameWidget();

public:
    // Public util functions
    void            showGameElements();

    // Getters
    GameData*       getGameData() const;
    GameVariants    getGameVariant() const;
    bool            getIsTimeAvailable() const;
    unsigned        getGameMinutes() const;
    unsigned        getIncrementSeconds() const;
    PiecesColors    getBelowPlayerColor() const;
    QuickGames      getQuickGame() const;

    // Setters
    void            setGameData(GameData* gameData);
    void            setGameVariant(GameVariants gameVariant);
    void            setIsTimeAvailable(bool isTimeAvailable);
    void            setGameMinutes(unsigned gameMinutes);
    void            setIncrementSeconds(unsigned incremetSeconds);
    void            setBelowPlayerColor(PiecesColors color);
    void            setQuickGame(QuickGames quickGame);

private:
    explicit        GameWidget(QWidget *parent = nullptr);

    // Init
    void            init();

    // Private util functions
    void            makeGameWidget();

private:
    // Singlton pattern realization
    static GameWidget*  _gameWidget;

    // Game elements
    GameData*           _gameData;
    BoardWidget*        _boardWidget;
    MovesWidget*        _movesWidget;
};

#endif // GAMEWIDGET_HPP
