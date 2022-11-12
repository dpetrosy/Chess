#include "moveswidget.hpp"

MovesWidget::MovesWidget(QWidget *parent)
    : QWidget{parent}
{
    // Init
    init();

    // Make MovesWidget
    //makeMovesWidget();
}

MovesWidget::~MovesWidget() {}

// Singlton pattern realization
MovesWidget* MovesWidget::_movesWidget = nullptr;

MovesWidget* MovesWidget::GetInstance(QWidget *parent)
{
    if(_movesWidget == nullptr)
        _movesWidget = new MovesWidget(parent);

    return _movesWidget;
}

// Init
void MovesWidget::init()
{
    // Moves widget attributes
    _movesVector.push_back(qMakePair("placeholder", "placeholder"));
}

// Getters
const MovesVector& MovesWidget::getMovesVector() const
{
    return _movesVector;
}

const MovePair& MovesWidget::getLastMove() const
{
    return _movesVector.back();
}

const MovePair& MovesWidget::getMove(int index) const
{
    return _movesVector[index];
}

const QString& MovesWidget::getWhitePlayerLastMove() const
{
    return _movesVector.back().first;
}

const QString& MovesWidget::getBlackPlayerLastMove() const
{
    return _movesVector.back().first;
}

// Setters
void MovesWidget::setLastMove(MovePair movePair)
{
    _movesVector.push_back(movePair);
}

void MovesWidget::setLastMove(const QString& whiteMove, const QString& blackMove)
{
    _movesVector.push_back(qMakePair(whiteMove, blackMove));
}

void MovesWidget::setMove(int index, MovePair movePair)
{
    _movesVector.insert(index, movePair);
}

void MovesWidget::setWhitePlayerLastMove(const QString& move)
{
    _movesVector.back().first = move;
}

void MovesWidget::setBlackPlayerLastMove(const QString& move)
{
    _movesVector.back().second = move;
}
