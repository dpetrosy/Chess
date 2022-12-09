#ifndef GAMEWIDGET_HPP
#define GAMEWIDGET_HPP

#include <QWidget>
#include <QObject>
#include <QDebug>
#include <QLabel>
#include <QChar>
#include <QRandomGenerator>

#include "game_helpers.hpp"
#include "menus_helpers.hpp"

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
    void startGame();

    // Getters
    GameData      getGameData() const;
    QString       getGameVariant() const;
    bool          getIsTimeAvailable() const;
    double        getGameMinutes() const;
    int           getIncrementSeconds() const;
    PiecesColors  getBelowPlayerColor() const;
    QString       getQuickGame() const;
    QString       getPieceSet() const;

    // Setters
    void setGameVariant(QString gameVariant);
    void setIsTimeAvailable(bool isTimeAvailable);
    void setGameMinutes(double gameMinutes);
    void setIncrementSeconds(int incremetSeconds);
    void setQuickGame(QString quickGame);
    void setBelowPlayerColor(PiecesColors color);
    void setPieceSet(QString set);

private:
    explicit GameWidget(QWidget *parent = nullptr);

    // Init
    void init();

    // Private util functions
    void makeGameWidget();
    void resetBoard();
    void resetSymbolsVector2D();
    void makeSymbolsVector2DForHorde();
    void makeSymbolsVector2DForChess960();
    void reverseSymbolsVector2D();
    void resetPiecesVector2D();

private:
    // Singlton pattern realization
    static GameWidget*  _gameWidget;

    // Game elements
    QLabel*      _boardLabel;
    GameData     _gameData;
    BoardWidget* _boardWidget;
    MovesWidget* _movesWidget;
};

#endif // GAMEWIDGET_HPP
