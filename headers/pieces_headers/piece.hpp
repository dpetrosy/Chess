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
    virtual Piece *Clone(PiecesColors pieceColor) const = 0;

//    // Setters
//    void setPieceLabel(QLabel* pieceLabel);
//    void setRowInGridLayout(unsigned rowInGridLayout);
//    void setColumnInGridLayout(unsigned columnInGridLayout);
//    void setPieceColor(PiecesColors pieceColor);

//    // Getters

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
    unsigned _rowInGridLayout;
    unsigned _columnInGridLayout;
    QString _pieceName;
    QString _extension;

    // Piece color attributes
    PiecesColors _pieceColor;
    QString _colorString;
    QString _coloredName;
    QString _image;
};

#endif // PIECE_HPP
