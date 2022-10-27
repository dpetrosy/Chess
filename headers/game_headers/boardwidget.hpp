#ifndef BOARDWIDGET_HPP
#define BOARDWIDGET_HPP

#include <QWidget>
#include <QObject>
#include <QDebug>
#include <QGridLayout>
#include <QVector>
#include <QVectorIterator>

#include "game_helpers.hpp"
#include "pieces_helpers.hpp"

// Singltone pattern used
class BoardWidget : public QWidget
{
    Q_OBJECT

public:
    // Singlton pattern realization
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

    ////////////////////////////////// NOT COMPLETED ////////////////////////////////
    // Private util functions
    void makeBoardWidget();
    ////////////////////////////////// NOT COMPLETED ////////////////////////////////

private:
    // Singleton pattern realization
    static BoardWidget* _boardWidget;

    // Board attributes
    QGridLayout* _boardLayout;
    QVector<QVector<Piece *>> _piecesVector2D;
    QVector<QVector<char>> _symbolsVector2D;
    unsigned _boardSize;
};

#endif // BOARDWIDGET_HPP
