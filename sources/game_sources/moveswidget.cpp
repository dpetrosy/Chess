#include "moveswidget.hpp"
#include "gamewidget.hpp"
#include "boardwidget.hpp"
#include "piece.hpp"

using std::get;

MovesWidget::MovesWidget(QWidget *parent)
    : QWidget{parent}
{
    // Init
    init();

    // Make MovesWidget
    //makeMovesWidget();
}

MovesWidget::~MovesWidget()
{
    delete _movesLayout;
}

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
    _movesLayout = new QGridLayout(this);
    _movesLayout->setVerticalSpacing(0);
    _movesLayout->setHorizontalSpacing(0);
}

// Public util functions
//void MovesWidget::makeMovesWidget()
//{
//    Position pos;
//    _movesVector2D.push_back(QVector<QLabel *>(3, nullptr));
//    _movesVector.push_back(make_pair(make_tuple('0', pos, pos, ""), make_tuple('0', pos, pos, "")));
//}

LabelVector2D& MovesWidget::getMovesVector2d()
{
    return _movesVector2D;
}

void MovesWidget::addMoveForColor(char pieceSymbol, Position posFrom, Position posTo, bool isCheck, bool isHit, bool isPawnPromoted, char promotedPawnSymbol, PiecesColors turn)
{
    Position pos;
    QString moveStr = "";
    auto boardWidget = BoardWidget::GetInstance();
    auto& pieceVector2D = boardWidget->getPiecesVector2D();
    auto& lastMove = _movesVector.back();
    static auto height = 45;

    moveStr = getPieceMoveSymbol(pieceSymbol);
    //moveStr += pieceSymbol;

    if (isHit)
        moveStr += "x";

    moveStr += getMovePosStr(posTo);

    // pawn prom
    //if ((posTo.row == 0 || posTo.row == 7) && (pieceSymbol == 'p' || pieceSymbol == 'P'))
    if (isPawnPromoted)
    {
        moveStr += "=";
        moveStr += promotedPawnSymbol;  //pieceVector2D[posTo.row][posTo.column]->getPieceSymbol();
    }

    if (isCheck)
        moveStr += "+";

    // Turn rich this function reversed
    if (turn == PiecesColors::White && !isPawnPromoted)
    {
        get<0>(lastMove.second) = pieceSymbol;
        get<1>(lastMove.second).row = posFrom.row;
        get<1>(lastMove.second).column = posFrom.column;
        get<2>(lastMove.second).row = posTo.row;
        get<2>(lastMove.second).column = posTo.column;
        get<3>(lastMove.second) = moveStr;

        int line = _movesVector.size() - 1;
        _movesVector2D[line][2]->setText(moveStr);
    }
    else
    {
        this->setGeometry((int)MovesWidgetProps::WidgetX, (int)MovesWidgetProps::WidgetY, (int)MovesWidgetProps::WidgetW, height);
        height += 28;
        _movesVector.push_back(make_pair(make_tuple(pieceSymbol, posFrom, posTo, moveStr), make_tuple('0', pos, pos, "")));
        _movesVector2D.push_back(QVector<QLabel *>(3, nullptr));

        int line = _movesVector.size() - 1;
        QString lineStr = QString::number(line + 1);

        QLabel* lineNumberTextLabel = new QLabel(this);
        //lineNumberTextLabel->setSizeIncrement(QSize((int)MovesWidgetProps::NumberLabelW, (int)MovesWidgetProps::NumberLabelH));
        lineNumberTextLabel->setAlignment(Qt::AlignCenter);
        lineNumberTextLabel->setText(lineStr);
        QLabel* whiteMoveTextLabel = new QLabel(this);
        whiteMoveTextLabel->setText(moveStr);
        QLabel* blackMoveTextLabel = new QLabel(this);
        blackMoveTextLabel->setText("");

        lineNumberTextLabel->setStyleSheet("QLabel {font-size: 13pt;}");
        whiteMoveTextLabel->setStyleSheet("QLabel {font-size: 13pt;}");
        blackMoveTextLabel->setStyleSheet("QLabel {font-size: 13pt;}");

        _movesVector2D[line][0] = lineNumberTextLabel;
        _movesVector2D[line][1] = whiteMoveTextLabel;
        _movesVector2D[line][2] = blackMoveTextLabel;

        _movesLayout->addWidget(_movesVector2D[line][0], line, 0);
        _movesLayout->addWidget(_movesVector2D[line][1], line, 1);
        _movesLayout->addWidget(_movesVector2D[line][2], line, 2);
    }


    // *************************************************************
//    lastMove = _movesVector.back();
//    QDebug deb = qDebug();
//    deb.nospace() << "Move N" << _movesVector.size() - 1 << "\n";

//    deb.nospace() << "White: \n";
//    deb.nospace() << "Symbol : " << get<0>(lastMove.first) << "\n";
//    deb.nospace() << "PosFromI: " << get<1>(lastMove.first).row << "\n";
//    deb.nospace() << "PosFromJ: " << get<1>(lastMove.first).column << "\n";
//    deb.nospace() << "PosToI: " << get<2>(lastMove.first).row << "\n";
//    deb.nospace() << "PosToJ: " << get<2>(lastMove.first).column << "\n";
//    deb.nospace() << "MoveStr: " << get<3>(lastMove.first) << "\n\n";

//    deb.nospace() << "Black: \n";
//    deb.nospace() << "Symbol : " << get<0>(lastMove.second) << "\n";
//    deb.nospace() << "PosFromI: " << get<1>(lastMove.second).row << "\n";
//    deb.nospace() << "PosFromJ: " << get<1>(lastMove.second).column << "\n";
//    deb.nospace() << "PosToI: " << get<2>(lastMove.second).row << "\n";
//    deb.nospace() << "PosToJ: " << get<2>(lastMove.second).column << "\n";
//    deb.nospace() << "MoveStr: " << get<3>(lastMove.second) << "\n\n";
    // **************************************************************
}

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

QString MovesWidget::getMovePosStr(Position posTo)
{
    auto belowPlayerColor = GameWidget::GetInstance()->getBelowPlayerColor();
    QString text = "";

    if (belowPlayerColor == PiecesColors::White)
    {
        text += getColumnLetter(posTo.column + 1);
        text += QString::number(9 - (posTo.row + 1));
    }
    else
    {
        text += getColumnLetter(9 - (posTo.column + 1));
        text += QString::number(posTo.row + 1);
    }

    return text;
}

QString MovesWidget::getColumnLetter(int column)
{
    switch (column)
    {
    case 1:
        return "a";
        break;
    case 2:
        return "b";
        break;
    case 3:
        return "c";
        break;
    case 4:
        return "d";
        break;
    case 5:
        return "e";
        break;
    case 6:
        return "f";
        break;
    case 7:
        return "g";
        break;
    case 8:
        return "h";
        break;
    default:
        return "";
        break;
    }
}
