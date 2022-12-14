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
    Position pos;
    _movesVector.push_back(make_pair(make_tuple('0', pos, pos, ""), make_tuple('0', pos, pos, "")));
}

// Public util functions
//void MovesWidget::addMoveForColor(char pieceSymbol, Position posFrom, Position posTo, bool isCheck, bool isHit, PiecesColors turn)
//{
//    Position pos;
//    QString moveStr = "";

//    moveStr = getPieceMoveSymbol(pieceSymbol);

//    if (isHit)
//        moveStr += "x";







//    + getMovePosStr(Position posTo);

//    if (turn == PiecesColors::White)
//         _movesVector.push_back(make_pair(make_tuple(pieceSymbol, posFrom, posTo, moveStr), make_tuple('0', pos, pos, "")));
//    else
//        ;
//}

QString MovesWidget::getPieceMoveSymbol(char pieceSymbol)
{
    switch (pieceSymbol)
    {
    case (char)PiecesSymbols::WhitePawn:
        return PieceSymbolsForMove::WhitePawn;
    case (char)PiecesSymbols::WhiteKnight:
        return PieceSymbolsForMove::WhiteKnight;
    case (char)PiecesSymbols::WhiteBishop:
        return PieceSymbolsForMove::WhiteBishop;
    case (char)PiecesSymbols::WhiteRook:
        return PieceSymbolsForMove::WhiteRook;
    case (char)PiecesSymbols::WhiteQueen:
        return PieceSymbolsForMove::WhiteQueen;
    case (char)PiecesSymbols::WhiteKing:
        return PieceSymbolsForMove::WhiteKing;
    case (char)PiecesSymbols::BlackPawn:
        return PieceSymbolsForMove::BlackPawn;
    case (char)PiecesSymbols::BlackKnight:
        return PieceSymbolsForMove::BlackKinght;
    case (char)PiecesSymbols::BlackBishop:
        return PieceSymbolsForMove::BlackBishop;
    case (char)PiecesSymbols::BlackRook:
        return PieceSymbolsForMove::BlackRook;
    case (char)PiecesSymbols::BlackQueen:
        return PieceSymbolsForMove::BlackQueen;
    case (char)PiecesSymbols::BlackKing:
        return PieceSymbolsForMove::BlackKing;
    default:
        return "";
    }
}

