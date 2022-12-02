#ifndef PVPMENU_HPP
#define PVPMENU_HPP

#include <QObject>
#include <QWidget>
#include <QDebug>
#include <QPushButton>
#include <QComboBox>
#include <QLabel>
#include <QSlider>

#include "menus_helpers.hpp"
#include "quick_game_button.hpp"

class PVPMenu : public QWidget
{
    Q_OBJECT

public:
    explicit PVPMenu(QWidget *parent = nullptr);
    virtual ~PVPMenu();

    // Public util functions
    QPushButton* getPushButton(PVPMenuPushButtons button);

private:
    // Init
    void init();

    // Private til functions
    void makePVPMenu();

private:
    QLabel*       _bkgLabel;
    QLabel*       _topTextLabel;

    // Game Variant
    QLabel*       _gameVariantTextLabel;
    QComboBox*    _gameVariantComboBox;

    // Time Control
    QLabel*       _timeControlBkgLabel;
    QLabel*       _timeControlTextLabel;
    ToggleSwitch* _timeControlToggleSwitch;
    QLabel*       _minutesTextLabel;
    QLabel*       _minutesNumberTextLabel;
    QLabel*       _incSecondsTextLabel;
    QLabel*       _incSecondsNumberTextLabel;
    QSlider*      _minutesSlider;
    QSlider*      _incSecondsSlider;

    // Quick Games
    QLabel*           _quickGamesTextLabel;
    QuickGameButton*  _bullet1MPushButton;
    QuickGameButton*  _blitz3MPushButton;
    QuickGameButton*  _blitz3MInc2SecPushButton;
    QuickGameButton*  _blitz5MPushButton;
    QuickGameButton*  _blitz10MPushButton;
    QuickGameButton*  _rapid15MPushButton;

    // Color buttons
    QPushButton*  _blackColorPushButton;
    QPushButton*  _randomColorPushButton;
    QPushButton*  _whiteColorPushButton;

    // Return button
    QPushButton*  _returnPushButton;
};

#endif // PVPMENU_HPP
