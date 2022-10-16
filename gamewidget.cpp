#include "gamewidget.hpp"

GameWidget::GameWidget(QWidget *parent)
    : QWidget{parent}
{
    boardWidget = new BoardWidget(this);
}

GameWidget::~GameWidget() {}

void GameWidget::show()
{
    boardWidget->showBoard();
}
