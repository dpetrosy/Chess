#ifndef QUICK_GAME_BUTTON_HPP
#define QUICK_GAME_BUTTON_HPP

#include <QObject>
#include <QDebug>
#include <QLabel>
#include <QWidget>
#include <QMouseEvent>
#include <Qt>

#include "clickablelabel.hpp"
#include "helpers.hpp"

class QuickGameButton : public ClickableLabel
{
    Q_OBJECT

public:
    explicit QuickGameButton(QWidget* parent = nullptr, QString quickGame = "NoSelected", Qt::WindowFlags f = Qt::WindowFlags());
    ~QuickGameButton();

    // Enter and leave events
    using QLabel::enterEvent;
    void enterEvent(QEnterEvent *event) override;
    void leaveEvent(QEvent *event) override;

signals:
    void clickedLeftButton() override;

private:
    // Mouse press events
    void mousePressEvent(QMouseEvent* event) override;

    // Private util functions
    void changeImg(QString pixmapPath, QString stylePath);

private:
    QString _quickGame = "";
};

#endif // QUICK_GAME_BUTTON_HPP
