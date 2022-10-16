#ifndef GAMEWIDGET_HPP
#define GAMEWIDGET_HPP

#include <QWidget>

#include "boardwidget.hpp"

class GameWidget : public QWidget
{
    Q_OBJECT

public:
    explicit GameWidget(QWidget *parent = nullptr);
    virtual ~GameWidget();

    void show();

private:
    BoardWidget *boardWidget;
};

#endif // GAMEWIDGET_HPP
