#ifndef MOVESWIDGET_HPP
#define MOVESWIDGET_HPP

#include <QWidget>
#include <QObject>
#include <QDebug>
#include <QVector>
#include <QString>
#include <QPair>

#include "pieces_helpers.hpp"

using std::make_tuple;
using std::make_pair;

// Singlton pattern used
class MovesWidget : public QWidget
{
    Q_OBJECT

public:
    // Singleton pattern realization
    MovesWidget(MovesWidget &other) = delete;
    MovesWidget& operator=(const MovesWidget&) = delete;
    static MovesWidget *GetInstance(QWidget *parent = nullptr);
    virtual ~MovesWidget();

    // Public util functions
        void addMoveForColor(char pieceSymbol, Position posFrom, Position posTo, bool isCheck, bool isHit, PiecesColors turn);
    QString getPieceMoveSymbol(char pieceSymbol);

private:
    explicit MovesWidget(QWidget *parent = nullptr);

    // Init
    void        init();

    // Private util functions
    //void makeMovesWidget();
    QString getMovePosStr(Position posTo);
    QString getColumnLetter(int column);

private:
    // Singlton pattern realization
    static MovesWidget* _movesWidget;

    // Moves widget attributes
    MovesVector         _movesVector;
};

#endif // MOVESWIDGET_HPP
