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
    BoardWidget(BoardWidget& other) = delete;
    BoardWidget& operator=(const BoardWidget&) = delete;
    static BoardWidget *GetInstance(QWidget *parent = nullptr);
    virtual ~BoardWidget();

public:
    // Getters
    Piece*          getSelectedPiece() const;
    unsigned        getBoardSize() const;
    QWidget*        getUnderLayerWidget() const;
    QGridLayout*    getUnderLayerLayout() const;
    PieceVector2D&  getUnderLayerVector2D();
    CharVector2D&   getPossibleStepsVector2D();
    QGridLayout*    getBoardLayout() const;
    CharVector2D&   getPiecesSymbolsVector2D();
    PieceVector2D&  getPiecesVector2D();
    PiecesColors    getTurn() const;
    QString         getPiecesPath() const;
    bool            getIsChecked() const;
    Position        getCheckPosition() const;

    // Setters
    void setCheckPosition(int i, int j);
    void setPromotedPawnPosition(int i, int j);

public slots:
    void processLeftButtonClick(Piece *clickedPiece);
    void doPawnProm(PiecesTypes pieceType);

private:
    explicit BoardWidget(QWidget *parent = nullptr);

    // Init
    void init();

    // Private util functions
    void makeBoardWidget();

    // Private game functions
    void selectPiece(Piece* clickedPiece);
    void doStep(Piece* clickedPiece);
    void doStepInSymbolsVector(int iSelected, int jSelected, int iClicked, int jClicked);
    void doStepInPiecesVector(int iSelected, int jSelected, int iClicked, int jClicked);
    void drawUnderLayer();
    void clearBoardLayout();
    void drawSelectedPieceSquare();
    void drawCheck();
    void clearStepsVector2D();
    void clearStepsVector2DExceptCheck();
    void resetBoardLayout();
    void switchTurn();
    bool isPieceSelected();
    bool isEmptyClicked(Piece *clickedPiece);
    bool isSelectedPieceClicked(Piece *clickedPiece);
    bool isOppositePieceClicked(Piece *clickedPiece);
    bool isCorrectColoredPieceClicked(Piece *clickedPiece);
    bool isAvailableStepClicked(int i, int j);
    bool isChecked();
    bool isPiece(Piece* piece, PiecesTypes pieceType);
    void markCurrentPieceAndCheck(Piece* clickedPiece);
    void checkPawnPromotion(int i, int j);
    void showPawnPromDialog();
    void verifyCheck();

private:
    // Singleton pattern realization
    static BoardWidget* _boardWidget;

    // Prototype pattern factory
    Factory* _piecesFactory;

    // Board widget attributes
    QString         _piecesPath;
    unsigned        _boardSize;

    // Under layer attributes
    QWidget*        _underLayerWidget;
    QGridLayout*    _underLayerLayout;
    PieceVector2D   _underLayerVector2D;
    CharVector2D    _possibleStepsVector2D;

    // Game attributes
    QGridLayout*    _boardLayout;
    CharVector2D    _piecesSymbolsVector2D;
    PieceVector2D   _piecesVector2D;
    PiecesColors    _turn;
    bool            _isChecked;
    bool            _isCheckedKingSelected;
    Position        _checkPosition;
    bool            _isPawnPromoted;
    Position        _promotedPawnPos;
    Piece*          _selectedPiece;
    PawnPromDialog* _pawnPromDialog;

};

#endif // BOARDWIDGET_HPP
