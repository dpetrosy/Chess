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
    virtual Piece *Clone() const = 0;

protected:
    Piece();

    // Setup
    void setup();


// ************************************ Poxel -> protected, just for test
public:
    QLabel* _pieceLabel;
    QString _piecesPath;
    QString _image;
    QString _name;
    unsigned _rowInGridLayout;
    unsigned _columnInGridLayout;
};

#endif // PIECE_HPP
