#include "start_game_button.hpp"
#include "menus_helpers.hpp"
#include "utils.hpp"

StartGameButton::StartGameButton(QWidget* parent, QString buttonName, Qt::WindowFlags f)
    : ClickableLabel(parent)
{
    Q_UNUSED(f)
    _buttonName = buttonName;
}

StartGameButton::~StartGameButton() {}

// Mouse press events
void StartGameButton::mousePressEvent(QMouseEvent* event)
{
    if(event->buttons() & Qt::LeftButton)
        emit clickedLeftButton();
}

// Private util functions
void StartGameButton::changeImg(QString pixmapPath, QString stylePath)
{
    this->setPixmap(QPixmap(pixmapPath));
    ::setStyleSheet(stylePath, this);
}

// Enter and leave events
void StartGameButton::enterEvent(QEnterEvent *event)
{
    this->setCursor(Qt::PointingHandCursor);

    if (globalIsDarkTheme)
    {
        if (_buttonName == StartGameButtonName::Bullet1M)
            changeImg(ImagesPaths::DarkBullet1MHoverButton, StylesPaths::darkQuickGamesHoverButtonStyle);
        else if (_buttonName == StartGameButtonName::Blitz3M)
            changeImg(ImagesPaths::DarkBlitz3MHoverButton, StylesPaths::darkQuickGamesHoverButtonStyle);
        else if (_buttonName == StartGameButtonName::Blitz3MInc2Sec)
            changeImg(ImagesPaths::DarkBlitz3MInc2SecHoverButton, StylesPaths::darkQuickGamesHoverButtonStyle);
        else if (_buttonName == StartGameButtonName::Blitz5M)
            changeImg(ImagesPaths::DarkBlitz5MHoverButton, StylesPaths::darkQuickGamesHoverButtonStyle);
        else if (_buttonName == StartGameButtonName::Blitz10M)
            changeImg(ImagesPaths::DarkBlitz10MHoverButton, StylesPaths::darkQuickGamesHoverButtonStyle);
        else if (_buttonName == StartGameButtonName::Rapid15M)
            changeImg(ImagesPaths::DarkRapid15MHoverButton, StylesPaths::darkQuickGamesHoverButtonStyle);
        else if (_buttonName == StartGameButtonName::BlackColor)
            changeImg(ImagesPaths::DarkBlackColorHoverButton, StylesPaths::darkQuickGamesHoverButtonStyle);
        else if (_buttonName == StartGameButtonName::WhiteColor)
            changeImg(ImagesPaths::DarkWhiteColorHoverButton, StylesPaths::darkQuickGamesHoverButtonStyle);
        else // RandomColor
            changeImg(ImagesPaths::DarkRandomColorHoverButton, StylesPaths::darkQuickGamesHoverButtonStyle);
    }
    else
    {
        if (_buttonName == StartGameButtonName::Bullet1M)
            changeImg(ImagesPaths::LightBullet1MHoverButton, StylesPaths::lightQuickGamesHoverButtonStyle);
        else if (_buttonName == StartGameButtonName::Blitz3M)
            changeImg(ImagesPaths::LightBlitz3MHoverButton, StylesPaths::lightQuickGamesHoverButtonStyle);
        else if (_buttonName == StartGameButtonName::Blitz3MInc2Sec)
            changeImg(ImagesPaths::LightBlitz3MInc2SecHoverButton, StylesPaths::lightQuickGamesHoverButtonStyle);
        else if (_buttonName == StartGameButtonName::Blitz5M)
            changeImg(ImagesPaths::LightBlitz5MHoverButton, StylesPaths::lightQuickGamesHoverButtonStyle);
        else if (_buttonName == StartGameButtonName::Blitz10M)
            changeImg(ImagesPaths::LightBlitz10MHoverButton, StylesPaths::lightQuickGamesHoverButtonStyle);
        else if (_buttonName == StartGameButtonName::Rapid15M)
            changeImg(ImagesPaths::LightRapid15MHoverButton, StylesPaths::lightQuickGamesHoverButtonStyle);
        else if (_buttonName == StartGameButtonName::BlackColor)
            changeImg(ImagesPaths::LightBlackColorHoverButton, StylesPaths::lightQuickGamesHoverButtonStyle);
        else if (_buttonName == StartGameButtonName::WhiteColor)
            changeImg(ImagesPaths::LightWhiteColorHoverButton, StylesPaths::lightQuickGamesHoverButtonStyle);
        else // RandomColor
            changeImg(ImagesPaths::LightRandomColorHoverButton, StylesPaths::lightQuickGamesHoverButtonStyle);
    }

    QLabel::enterEvent(event);
}

void StartGameButton::leaveEvent(QEvent *event)
{
    if (globalIsDarkTheme)
    {
        if (_buttonName == StartGameButtonName::Bullet1M)
            changeImg(ImagesPaths::DarkBullet1MButton, StylesPaths::darkQuickGamesButtonStyle);
        else if (_buttonName == StartGameButtonName::Blitz3M)
            changeImg(ImagesPaths::DarkBlitz3MButton, StylesPaths::darkQuickGamesButtonStyle);
        else if (_buttonName == StartGameButtonName::Blitz3MInc2Sec)
            changeImg(ImagesPaths::DarkBlitz3MInc2SecButton, StylesPaths::darkQuickGamesButtonStyle);
        else if (_buttonName == StartGameButtonName::Blitz5M)
            changeImg(ImagesPaths::DarkBlitz5MButton, StylesPaths::darkQuickGamesButtonStyle);
        else if (_buttonName == StartGameButtonName::Blitz10M)
            changeImg(ImagesPaths::DarkBlitz10MButton, StylesPaths::darkQuickGamesButtonStyle);
        else if (_buttonName == StartGameButtonName::Rapid15M)
            changeImg(ImagesPaths::DarkRapid15MButton, StylesPaths::darkQuickGamesButtonStyle);
        else if (_buttonName == StartGameButtonName::BlackColor)
            changeImg(ImagesPaths::DarkBlackColorButton, StylesPaths::darkColorButtonStyle);
        else if (_buttonName == StartGameButtonName::WhiteColor)
            changeImg(ImagesPaths::DarkWhiteColorButton, StylesPaths::darkColorButtonStyle);
        else // RandomColor
            changeImg(ImagesPaths::DarkRandomColorButton, StylesPaths::darkColorButtonStyle);
    }
    else
    {
        if (_buttonName == StartGameButtonName::Bullet1M)
            changeImg(ImagesPaths::LightBullet1MButton, StylesPaths::lightQuickGamesButtonStyle);
        else if (_buttonName == StartGameButtonName::Blitz3M)
            changeImg(ImagesPaths::LightBlitz3MButton, StylesPaths::lightQuickGamesButtonStyle);
        else if (_buttonName == StartGameButtonName::Blitz3MInc2Sec)
            changeImg(ImagesPaths::LightBlitz3MInc2SecButton, StylesPaths::lightQuickGamesButtonStyle);
        else if (_buttonName == StartGameButtonName::Blitz5M)
            changeImg(ImagesPaths::LightBlitz5MButton, StylesPaths::lightQuickGamesButtonStyle);
        else if (_buttonName == StartGameButtonName::Blitz10M)
            changeImg(ImagesPaths::LightBlitz10MButton, StylesPaths::lightQuickGamesButtonStyle);
        else if (_buttonName == StartGameButtonName::Rapid15M)
            changeImg(ImagesPaths::LightRapid15MButton, StylesPaths::lightQuickGamesButtonStyle);
        else if (_buttonName == StartGameButtonName::BlackColor)
            changeImg(ImagesPaths::LightBlackColorButton, StylesPaths::lightQuickGamesButtonStyle);
        else if (_buttonName == StartGameButtonName::WhiteColor)
            changeImg(ImagesPaths::LightWhiteColorButton, StylesPaths::lightQuickGamesButtonStyle);
        else // RandomColor
            changeImg(ImagesPaths::LightRandomColorButton, StylesPaths::lightQuickGamesButtonStyle);
    }

    QLabel::leaveEvent(event);
}
