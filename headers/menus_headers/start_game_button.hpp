#ifndef START_GAME_BUTTON_HPP
#define START_GAME_BUTTON_HPP

#include <QObject>
#include <QDebug>
#include <QLabel>
#include <QWidget>
#include <QMouseEvent>
#include <Qt>
#include <QCursor>

#include "clickablelabel.hpp"

class StartGameButton : public ClickableLabel
{
    Q_OBJECT

public:
    explicit StartGameButton(QWidget* parent = nullptr, QString buttonName = "NoSelected", Qt::WindowFlags f = Qt::WindowFlags());
    ~StartGameButton();

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
    QString _buttonName;
};

#endif // START_GAME_BUTTON_HPP
