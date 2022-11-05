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

// Singleton pattern used
// Prototype pattern used
class BoardWidget : public QWidget
{
    Q_OBJECT

public:
    // Singlton pattern realization
    BoardWidget(BoardWidget &other) = delete;
    BoardWidget& operator=(const BoardWidget&) = delete;
    static BoardWidget *GetInstance(QWidget *parent = nullptr);
    virtual ~BoardWidget();

public slots:
    void processLeftButtonClick(Piece *clickedPiece);

private:
    explicit BoardWidget(QWidget *parent = nullptr);

    // Setup
    void setup();

    // Private util functions
    void makeBoardWidget();

    // Private game functions
    void makeUnderLayerForSelectedPiece(Piece* clickedPiece, PiecesColors turn);
    void drawUnderLayer();
    void clearStepsVector2D();
    bool isPieceSelected();
    bool isEmptyClicked(Piece *clickedPiece);
    bool isOppositePieceClicked(Piece *clickedPiece, PiecesColors turn);
    bool isCorrectColoredPieceClicked(Piece *clickedPiece, PiecesColors turn);
    bool isAvailableStepClicked(int i, int j);
    void markSelectedPieceSquare();
    void resetUnderLayer();

private:
    // Singleton pattern realization
    static BoardWidget* _boardWidget;

    // Prototype pattern factory
    Factory* _piecesFactory;

    // Board widget attributes
    Piece* _selectedPiece;
    unsigned _boardSize;

    // Under layer attributes
    QWidget* _underLayerWidget;
    QGridLayout* _underLayerLayout;
    pieceVector2D _underLayerVector2D;
    charVector2D _possibleStepsVector2D;

    // Board attributes
    QGridLayout* _boardLayout;
    charVector2D _piecesSymbolsVector2D;
    pieceVector2D _piecesVector2D;
    QString _piecesPath;
};

#endif // BOARDWIDGET_HPP
