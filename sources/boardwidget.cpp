#include "boardwidget.hpp"

BoardWidget::BoardWidget(QWidget *parent)
    : QWidget{parent}
{
    this->setGeometry(BoardLeftUpCornerX, BoardLeftUpCornerY, BoardSizeHorizontal, BoardSizeVertical);

    m_piecesPath = ":/images/images/pieces/";
    m_board = new QGridLayout();

}

BoardWidget *BoardWidget::GetInstance(QWidget *parent)
{
    if(m_boardWidget == nullptr)
        m_boardWidget = new BoardWidget(parent);

    return m_boardWidget;
}

BoardWidget* BoardWidget::m_boardWidget = nullptr;

BoardWidget::~BoardWidget() {}

void BoardWidget::showBoard()
{
    setLayout(m_board);
}
