#ifndef PIECE_HPP
#define PIECE_HPP

#include <QDebug>
#include <QObject>
#include <QLabel>

#include "pieces_helpers.hpp"

// Prototype pattern used
class Piece 
{
    //Q_OBJECT

public:
    virtual ~Piece();

    // Prototype pattern realization
    virtual Piece *Clone(PiecesColors pieceColor, int i, int j) const = 0;

    // Getters
    QLabel* getPieceLabel() const;

    // Setters
    void setPieceLabel(QLabel* pieceLabel);
    void setPosition(int i, int j);
    void setPieceColor(PiecesColors pieceColor);

protected:
    Piece();

    // Setup
    void setup();

    // Protected util functions
    void makeColored(PiecesColors pieceColor);

// **************************************** MUST BE PROTECTED, JUST FOR TEST ************************************** //
public:
    QLabel* _pieceLabel;
    QString _piecesPath;
    Position _position;
    QString _pieceName;
    QString _extension;

    // Piece color attributes
    PiecesColors _pieceColor;
    QString _colorString;
    QString _coloredName;
    QString _image;
};

#endif // PIECE_HPP
