#ifndef MOVESWIDGET_HPP
#define MOVESWIDGET_HPP

#include <QWidget>
#include <QObject>
#include <QDebug>
#include <QVector>
#include <QString>
#include <QPair>

#include "game_helpers.hpp"
#include "pieces_helpers.hpp"

// Singlton pattern used
class MovesWidget : public QWidget
{
    Q_OBJECT

public:
    // Singlton pattern realization
    MovesWidget(MovesWidget &other) = delete;
    MovesWidget& operator=(const MovesWidget&) = delete;
    static MovesWidget *GetInstance(QWidget *parent = nullptr);
    virtual ~MovesWidget();

    // Getters
    const MovesVector& getMovesVector() const;
    const MovePair& getLastMove() const;
    const MovePair& getMove(int index) const;
    const QString& getWhitePlayerLastMove() const;
    const QString& getBlackPlayerLastMove() const;

    // Setters
    void setLastMove(MovePair movePair);
    void setLastMove(const QString& whiteMove, const QString& blackMove);
    void setMove(int index, MovePair movePair);
    void setWhitePlayerLastMove(const QString& move);
    void setBlackPlayerLastMove(const QString& move);

private:
    explicit MovesWidget(QWidget *parent = nullptr);

    // Setup
    void setup();

    // Private util functions
    //void makeMovesWidget();

private:
    // Singlton pattern realization
    static MovesWidget* _movesWidget;

    // Moves widget attributes
    MovesVector _movesVector;
};

#endif // MOVESWIDGET_HPP
