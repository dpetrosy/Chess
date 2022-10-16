#include "boardwidget.hpp"

BoardWidget::BoardWidget(QWidget *parent)
    : QWidget{parent}
{
    this->setGeometry(BoardLeftUpCornerX, BoardLeftUpCornerY, BoardSizeHorizontal, BoardSizeVertical);

    board = new QGridLayout();
    piecesPath = ":/images/images/pieces/";

    // setups
    //setupRow0();
    //setupRow1();
}

BoardWidget::~BoardWidget() {}

//void BoardWidget::setupRow0()
//{
//    blackLeftRook_0_0 = new QLabel();
//    blackLeftKnight_0_1 = new QLabel();
//    blackLeftBishop_0_2 = new QLabel();
//    blackQueen_0_3 = new QLabel();
//    blackKing_0_4 = new QLabel();
//    blackRightBishop_0_5 = new QLabel();
//    blackRightKnight_0_6 = new QLabel();
//    blackRightRook_0_7 = new QLabel();

//    blackLeftRook_0_0->setPixmap(QPixmap( piecesPath + "black_rook.png"));
//    blackLeftKnight_0_1->setPixmap(QPixmap( piecesPath + "black_knight.png"));
//    blackLeftBishop_0_2->setPixmap(QPixmap( piecesPath + "black_bishop.png"));
//    blackQueen_0_3->setPixmap(QPixmap( piecesPath + "black_queen.png"));
//    blackKing_0_4->setPixmap(QPixmap( piecesPath + "black_king.png"));
//    blackRightBishop_0_5->setPixmap(QPixmap( piecesPath + "black_bishop.png"));
//    blackRightKnight_0_6->setPixmap(QPixmap( piecesPath + "black_knight.png"));
//    blackRightRook_0_7->setPixmap(QPixmap( piecesPath + "black_rook.png"));
//}

//void BoardWidget::setupRow1()
//{
//    blackPawn_1_0 = new QLabel();
//    blackPawn_1_1 = new QLabel();
//    blackPawn_1_2 = new QLabel();
//    blackPawn_1_3 = new QLabel();
//    blackPawn_1_4 = new QLabel();
//    blackPawn_1_5 = new QLabel();
//    blackPawn_1_6 = new QLabel();
//    blackPawn_1_7 = new QLabel();

//    blackPawn_1_0->setPixmap(QPixmap( piecesPath + "black_pawn.png"));
//    blackPawn_1_1->setPixmap(QPixmap( piecesPath + "black_pawn.png"));
//    blackPawn_1_2->setPixmap(QPixmap( piecesPath + "black_pawn.png"));
//    blackPawn_1_3->setPixmap(QPixmap( piecesPath + "black_pawn.png"));
//    blackPawn_1_4->setPixmap(QPixmap( piecesPath + "black_pawn.png"));
//    blackPawn_1_5->setPixmap(QPixmap( piecesPath + "black_pawn.png"));
//    blackPawn_1_6->setPixmap(QPixmap( piecesPath + "black_pawn.png"));
//    blackPawn_1_7->setPixmap(QPixmap( piecesPath + "black_pawn.png"));
//}

void BoardWidget::showBoard()
{
//    board->addWidget(blackLeftRook_0_0, 0, 0);
//    board->addWidget(blackLeftKnight_0_1, 0, 1);
//    board->addWidget(blackLeftBishop_0_2, 0, 2);
//    board->addWidget(blackQueen_0_3, 0, 3);
//    board->addWidget(blackKing_0_4, 0, 4);
//    board->addWidget(blackRightBishop_0_5, 0, 5);
//    board->addWidget(blackRightKnight_0_6, 0, 6);
//    board->addWidget(blackRightRook_0_7, 0, 7);

//    board->addWidget(blackPawn_1_0, 1, 0);
//    board->addWidget(blackPawn_1_1, 1, 1);
//    board->addWidget(blackPawn_1_2, 1, 2);
//    board->addWidget(blackPawn_1_3, 1, 3);
//    board->addWidget(blackPawn_1_4, 1, 4);
//    board->addWidget(blackPawn_1_5, 1, 5);
//    board->addWidget(blackPawn_1_6, 1, 6);
//    board->addWidget(blackPawn_1_7, 1, 7);


//    setLayout(board);


}
