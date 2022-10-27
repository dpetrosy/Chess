#ifndef BOARDWIDGET_HPP
#define BOARDWIDGET_HPP

#include <QWidget>
#include <QDebug>
#include <QLabel>
#include <QLayout>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QVector>
#include <QVectorIterator>

#include "game_helpers.hpp"


///////////////////////////////// DELETE ///////////////////////////////////////////////////////
class Piece;
///////////////////////////////// DELETE ///////////////////////////////////////////////////////


// Singltone pattern used
class BoardWidget : public QWidget
{
    Q_OBJECT

public:
    // Singltone realization
    BoardWidget(BoardWidget &other) = delete;
    BoardWidget& operator=(const BoardWidget&) = delete;
    static BoardWidget *GetInstance(QWidget *parent = nullptr);
    virtual ~BoardWidget();

    // Public util functions
    void showBoard();

private:
    explicit BoardWidget(QWidget *parent = nullptr);

    // Setup
    void setup();

    // Private util functions
    void makeBoardWidget();

private:
    // Singltone realization
    static BoardWidget *_boardWidget;

    // Board attributes
    QGridLayout *_boardLayout;
    QVector<QVector<Piece *>> _piecesVector2D;
    QVector<QVector<char>> _symbolsVector2D;
    unsigned boardSize;
};

#endif // BOARDWIDGET_HPP
