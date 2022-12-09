#ifndef PIECE_HPP
#define PIECE_HPP

#include <QDebug>
#include <QObject>
#include <QLabel>

#include "game_helpers.hpp"
#include "pieces_helpers.hpp"

// Prototype pattern used
class Piece : public QObject
{
    Q_OBJECT

public:
    virtual ~Piece();

    // Prototype pattern realization
    virtual Piece *Clone(PiecesColors pieceColor, int i, int j) const = 0;

    // Public game functions
    virtual void findAvailableSteps(CharVector2D& stepsVector2D, CharVector2D& symbolsVector2D, PiecesColors turn, PiecesColors belowPlayerColor = PiecesColors::White) = 0;
    bool isCanGo(CharVector2D& symbolsVector2D, int i, int j);
    bool isCanBeat(CharVector2D& symbolsVector2D, int i, int j, PiecesColors turn);
    bool isSameColoredPiece(CharVector2D& symbolsVector2D, int i, int j, PiecesColors turn);
    bool isKing(CharVector2D& symbolsVector2D, int i, int j);
    bool isGivingCheck(CharVector2D& stepsVector2D, CharVector2D& symbolsVector2D, PiecesColors turn);
    void markCanGoOrCanBeat(CharVector2D& stepsVector2D, CharVector2D& symbolsVector2D, int i, int j, PiecesColors turn);

public:
    // Getters
    ClickableLabel*  getPieceLabel() const;
    QString          getPiecePath() const;
    Position         getPosition() const;
    int              getPositionRow() const;
    int              getPositionColumn() const;
    QString          getPieceName() const;
    QString          getExtension() const;
    PiecesTypes      getPieceType() const;
    PiecesColors     getPieceColor() const;
    QString          getColorString() const;
    QString          getColoredName() const;
    QString          getImage() const;
    char             getPieceSymbol() const;

    // Setters
    void setPieceLabel(ClickableLabel* pieceLabel);
    void setPiecePath(QString piecePath);
    void setPosition(int row, int column);
    void setPositionRow(int row);
    void setPositionColumn(int column);
    void setPieceName(QString pieceName);
    void setExtension(QString extension);
    void setPieceType(PiecesTypes pieceType);
    void setPieceColor(PiecesColors piecesColor);
    void setColorString(QString colorString);
    void setColoredName(QString coloredName);
    void setImage(QString image);
    void changePixmap();

protected:
    Piece();

    // Init
    void init();

    // Protected util functions
    void makeColored(PiecesColors pieceColor);
    void findPieceSymbol();

protected:
    ClickableLabel*  _pieceLabel;
    Position         _position;
    QString          _pieceName;
    QString          _extension;
    PiecesTypes      _pieceType;
    QString          _pieceSet;
    char             _pieceSymbol;

    // Piece color attributes
    PiecesColors  _pieceColor;
    QString       _colorString;
    QString       _coloredName;
    QString       _image;
};

#endif // PIECE_HPP
