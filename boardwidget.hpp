#ifndef BOARDWIDGET_HPP
#define BOARDWIDGET_HPP

#include <QWidget>
#include <QLabel>
#include <QGridLayout>
#include <QLayout>
#include <QHBoxLayout>

#include "cordsandsizes.hpp"

class BoardWidget : public QWidget
{
    Q_OBJECT

public:
    explicit BoardWidget(QWidget *parent = nullptr);
    virtual ~BoardWidget();

    // setup rows
//    void setupRow0();
//    void setupRow1();

    void showBoard();

private:
    QGridLayout *board;
    QString piecesPath;

//    // black player pieces, row 0
//    QLabel *blackLeftRook_0_0;
//    QLabel *blackLeftKnight_0_1;
//    QLabel *blackLeftBishop_0_2;
//    QLabel *blackQueen_0_3;
//    QLabel *blackKing_0_4;
//    QLabel *blackRightBishop_0_5;
//    QLabel *blackRightKnight_0_6;
//    QLabel *blackRightRook_0_7;

//    // black pawns, row 1
//    QLabel *blackPawn_1_0;
//    QLabel *blackPawn_1_1;
//    QLabel *blackPawn_1_2;
//    QLabel *blackPawn_1_3;
//    QLabel *blackPawn_1_4;
//    QLabel *blackPawn_1_5;
//    QLabel *blackPawn_1_6;
//    QLabel *blackPawn_1_7;
};

#endif // BOARDWIDGET_HPP
