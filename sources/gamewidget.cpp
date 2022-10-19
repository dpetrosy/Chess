#include "gamewidget.hpp"

GameWidget::GameWidget(QWidget *parent)
    : QWidget{parent}
{
    m_boardWidget = BoardWidget::GetInstance(this);
}

GameWidget *GameWidget::GetInstance(QWidget *parent)
{
    if(m_gameWidget == nullptr)
        m_gameWidget = new GameWidget(parent);

    return m_gameWidget;
}

GameWidget *GameWidget::m_gameWidget = nullptr;

GameWidget::~GameWidget() {}

void GameWidget::show()
{
    m_boardWidget->showBoard();
}
