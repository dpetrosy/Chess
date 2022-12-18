#ifndef BOARDWIDGET_HPP
#define BOARDWIDGET_HPP

#include <QWidget>
#include <QObject>
#include <QDebug>
#include <QLabel>
#include <QGridLayout>
#include <QVector>
#include <QVectorIterator>
#include <QMessageBox>

#include "predefined_game_classes.hpp"
#include "pieces_helpers.hpp"

extern Piece* gSelectedPiece;
extern bool doForQueen;

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

    // Public util functions
    void makeNewPieceBySymbol(char symbol, int i, int j);
    void clearBoardLayout();
    void clearUnderLayout();
    void resetBoardLayout();
    void drawUnderLayer();
    void getAllAvailStepsForColor(CharVector2D& allAvailStepsVector2D, CharVector2D& imitationVector2D, PiecesColors turn);

public:
    // Getters
    Piece*          getSelectedPiece() const;
    int             getBoardSize() const;
    QWidget*        getUnderLayerWidget() const;
    QGridLayout*    getUnderLayerLayout() const;
    PieceVector2D&  getUnderLayerVector2D();
    CharVector2D&   getPossibleStepsVector2D();
    QGridLayout*    getBoardLayout() const;
    CharVector2D&   getPiecesSymbolsVector2D();
    PieceVector2D&  getPiecesVector2D();
    PiecesColors    getTurn() const;
    bool            getIsChecked() const;
    Position        getCheckPosition() const;
    PiecesColors    getOppositeTurn(PiecesColors turn);

    // Setters
    void setCheckPosition(int i, int j);
    void setPromotedPawnPosition(int i, int j);
    void setValueInSymbolsVector2D(int i, int j, char value);
    void setTurn(PiecesColors turn);
    void setIsChecked(bool isChecked);
    void setIsCheckedKingSelected(bool isSelected);
    void setIsPawnPromoted(bool isPromoted);

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
    void drawSelectedPieceSquare();
    void drawCheck();
    void clearStepsVector2D();
    void clearStepsVector2DExceptCheck();
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
    void verifyCheckmateAndStalemate();
    void addToAllStepsVector2D(CharVector2D& allAvailStepsVector2D, CharVector2D& possibleStepsVector2D);
    void endGame(PiecesColors turn, bool isStalemate);

private:
    // Singleton pattern realization
    static BoardWidget* _boardWidget;

    // Prototype pattern factory
    Factory* _piecesFactory;

    // Board widget attributes
    int _boardSize;

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
    PawnPromDialog* _pawnPromDialog;
};

#endif // BOARDWIDGET_HPP
