#ifndef GAMEWIDGET_HPP
#define GAMEWIDGET_HPP

#include <QWidget>

#include "boardwidget.hpp"

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

    // Member functions
    void show();

private:
    explicit GameWidget(QWidget *parent = nullptr);

private:
    // Singltone realization
    static GameWidget *m_gameWidget;

    // Member attributes
    BoardWidget *m_boardWidget;
};

#endif // GAMEWIDGET_HPP
