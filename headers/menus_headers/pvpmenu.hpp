#ifndef PVPMENU_HPP
#define PVPMENU_HPP

#include <QObject>
#include <QWidget>
#include <QDebug>
#include <QPushButton>
#include <QComboBox>
#include <QLabel>
#include <QSlider>
#include <QRandomGenerator>

#include "menus_helpers.hpp"
#include "game_helpers.hpp"
#include "start_game_button.hpp"
#include "predefined_menu_classes.hpp"

// Command pattern used
class PVPMenu : public QWidget
{
    Q_OBJECT

public:
    explicit PVPMenu(QWidget *parent = nullptr);
    virtual ~PVPMenu();

    // Public util functions
    void              makeMenuBeforeSwitch();
    ClickableLabel*   getReturnButton();
    StartGameButton*  getStartGameButton(StartGameButtons button);
    void              setDataBeforeStartGame(double minutes, int incSeconds, PiecesColors color);
    QString           getGameVariantStr(int index);

public slots:
    void variantComboBoxIndexChanged(int index);
    void swapTimeControl();
    void minutesSliderValueChanged(int x);
    void incSecondsSliderValueChanged(int x);

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
    bool          _isTimeAvailable;

    // Quick Games
    QLabel*           _quickGamesTextLabel;
    StartGameButton*  _bullet1MButton;
    StartGameButton*  _blitz3MButton;
    StartGameButton*  _blitz3MInc2SecButton;
    StartGameButton*  _blitz5MButton;
    StartGameButton*  _blitz10MButton;
    StartGameButton*  _rapid15MButton;

    // Color buttons
    StartGameButton*  _blackColorButton;
    StartGameButton*  _randomColorButton;
    StartGameButton*  _whiteColorButton;

    // Return button
    ClickableLabel*   _returnButton;
};

#endif // PVPMENU_HPP
