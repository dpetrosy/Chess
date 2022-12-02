#include "quick_game_button.hpp"
#include "menus_helpers.hpp"
#include "utils.hpp"

#include <QCursor>

QuickGameButton::QuickGameButton(QWidget* parent, QString quickGame, Qt::WindowFlags f)
    : ClickableLabel(parent)
{
    Q_UNUSED(f)
    _quickGame = quickGame;
}

QuickGameButton::~QuickGameButton() {}

// Mouse press events
void QuickGameButton::mousePressEvent(QMouseEvent* event)
{
    if(event->buttons() & Qt::LeftButton)
        emit clickedLeftButton();
}

// Private util functions
void QuickGameButton::changeImg(QString pixmapPath, QString stylePath)
{
    this->setPixmap(QPixmap(pixmapPath));
    ::setStyleSheet(stylePath, this);
}

// Enter and leave events
void QuickGameButton::enterEvent(QEnterEvent *event)
{
    this->setCursor(Qt::PointingHandCursor);

    if (globalIsDarkTheme)
    {
        if (_quickGame == QuickGames::Bullet1M)
            changeImg(ImagesPaths::DarkBullet1MHoverButton, StylesPaths::darkQuickGamesHoverButtonStyle);
        else if (_quickGame == QuickGames::Blitz3M)
            changeImg(ImagesPaths::DarkBlitz3MHoverButton, StylesPaths::darkQuickGamesHoverButtonStyle);
        else if (_quickGame == QuickGames::Blitz3MInc2Sec)
            changeImg(ImagesPaths::DarkBlitz3MInc2SecHoverButton, StylesPaths::darkQuickGamesHoverButtonStyle);
        else if (_quickGame == QuickGames::Blitz5M)
            changeImg(ImagesPaths::DarkBlitz5MHoverButton, StylesPaths::darkQuickGamesHoverButtonStyle);
        else if (_quickGame == QuickGames::Blitz10M)
            changeImg(ImagesPaths::DarkBlitz10MHoverButton, StylesPaths::darkQuickGamesHoverButtonStyle);
        else // Rapid15M
            changeImg(ImagesPaths::DarkRapid15MHoverButton, StylesPaths::darkQuickGamesHoverButtonStyle);
    }
    else
    {
        if (_quickGame == QuickGames::Bullet1M)
            changeImg(ImagesPaths::LightBullet1MHoverButton, StylesPaths::lightQuickGamesHoverButtonStyle);
        else if (_quickGame == QuickGames::Blitz3M)
            changeImg(ImagesPaths::LightBlitz3MHoverButton, StylesPaths::lightQuickGamesHoverButtonStyle);
        else if (_quickGame == QuickGames::Blitz3MInc2Sec)
            changeImg(ImagesPaths::LightBlitz3MInc2SecHoverButton, StylesPaths::lightQuickGamesHoverButtonStyle);
        else if (_quickGame == QuickGames::Blitz5M)
            changeImg(ImagesPaths::LightBlitz5MHoverButton, StylesPaths::lightQuickGamesHoverButtonStyle);
        else if (_quickGame == QuickGames::Blitz10M)
            changeImg(ImagesPaths::LightBlitz10MHoverButton, StylesPaths::lightQuickGamesHoverButtonStyle);
        else // Rapid15M
            changeImg(ImagesPaths::LightRapid15MHoverButton, StylesPaths::lightQuickGamesHoverButtonStyle);
    }

    QLabel::enterEvent(event);
}

void QuickGameButton::leaveEvent(QEvent *event)
{
    if (globalIsDarkTheme)
    {
        if (_quickGame == QuickGames::Bullet1M)
            changeImg(ImagesPaths::DarkBullet1MButton, StylesPaths::darkQuickGamesButtonStyle);
        else if (_quickGame == QuickGames::Blitz3M)
            changeImg(ImagesPaths::DarkBlitz3MButton, StylesPaths::darkQuickGamesButtonStyle);
        else if (_quickGame == QuickGames::Blitz3MInc2Sec)
            changeImg(ImagesPaths::DarkBlitz3MInc2SecButton, StylesPaths::darkQuickGamesButtonStyle);
        else if (_quickGame == QuickGames::Blitz5M)
            changeImg(ImagesPaths::DarkBlitz5MButton, StylesPaths::darkQuickGamesButtonStyle);
        else if (_quickGame == QuickGames::Blitz10M)
            changeImg(ImagesPaths::DarkBlitz10MButton, StylesPaths::darkQuickGamesButtonStyle);
        else // Rapid15M
            changeImg(ImagesPaths::DarkRapid15MButton, StylesPaths::darkQuickGamesButtonStyle);
    }
    else
    {
        if (_quickGame == QuickGames::Bullet1M)
            changeImg(ImagesPaths::LightBullet1MButton, StylesPaths::lightQuickGamesButtonStyle);
        else if (_quickGame == QuickGames::Blitz3M)
            changeImg(ImagesPaths::LightBlitz3MButton, StylesPaths::lightQuickGamesButtonStyle);
        else if (_quickGame == QuickGames::Blitz3MInc2Sec)
            changeImg(ImagesPaths::LightBlitz3MInc2SecButton, StylesPaths::lightQuickGamesButtonStyle);
        else if (_quickGame == QuickGames::Blitz5M)
            changeImg(ImagesPaths::LightBlitz5MButton, StylesPaths::lightQuickGamesButtonStyle);
        else if (_quickGame == QuickGames::Blitz10M)
            changeImg(ImagesPaths::LightBlitz10MButton, StylesPaths::lightQuickGamesButtonStyle);
        else // Rapid15M
            changeImg(ImagesPaths::LightRapid15MButton, StylesPaths::lightQuickGamesButtonStyle);
    }


    QLabel::leaveEvent(event);
}


