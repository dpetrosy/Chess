#ifndef BOARDWIDGET_HPP
#define BOARDWIDGET_HPP

#include <QWidget>
#include <QLabel>
#include <QGridLayout>
#include <QLayout>
#include <QHBoxLayout>

#include "helpers.hpp"

// Singltone pattern used
class BoardWidget : public QWidget
{
    Q_OBJECT

public:
    // Singltone realization
    BoardWidget(BoardWidget &other) = delete;
    BoardWidget& operator=(const BoardWidget&) = delete;
    static BoardWidget *GetInstance(QWidget *parent = nullptr);
    virtual ~BoardWidget();

    // Member functions
    void showBoard();

private:
    explicit BoardWidget(QWidget *parent = nullptr);

private:
    // Singltone realization
    static BoardWidget *m_boardWidget;

    // Board attributes
    QGridLayout *m_board;
    QString m_piecesPath;

};

#endif // BOARDWIDGET_HPP
