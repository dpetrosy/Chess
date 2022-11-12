#ifndef PAWNPROMDIALOG_HPP
#define PAWNPROMDIALOG_HPP

#include <QDialog>
#include <QLabel>
#include <QDebug>
#include <QPushButton>
#include <QEvent>
#include <QKeyEvent>
#include <QFile>

#include "pieces_helpers.hpp"

class PawnPromDialog : public QDialog
{
    Q_OBJECT

public:
    explicit PawnPromDialog(QWidget *parent = nullptr);
    virtual ~PawnPromDialog();

    // Public util functions
    void keyPressEvent(QKeyEvent *event);
    void makePawnPromDialog(PiecesColors turn);

private:
    // Init
    void init();

private:
    // PawnPromDialog objects
    QPushButton* _queenPushButton;
    QPushButton* _rookPushButton;
    QPushButton* _bishopPushButton;
    QPushButton* _knightPushButton;
};

#endif // PAWNPROMDIALOG_HPP
