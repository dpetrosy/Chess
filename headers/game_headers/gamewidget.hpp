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

private:
    explicit GameWidget(QWidget *parent = nullptr);

    // Setup
    void setup();

    // Private util functions
    void makeGameWidget();

private:
    // Singltone realization
    static GameWidget *_gameWidget;

    // Game Widget elements
    BoardWidget *_boardWidget;
};

#endif // GAMEWIDGET_HPP
