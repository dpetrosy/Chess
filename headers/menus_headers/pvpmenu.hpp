#ifndef PVPMENU_HPP
#define PVPMENU_HPP

#include <QObject>
#include <QWidget>
#include <QDebug>
#include <QPushButton>
#include <QComboBox>
#include <QLabel>

#include "menus_helpers.hpp"

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
    QComboBox*    _timeControlComboBox;
    //minutes controler
    //increment seconds controler

    // Quick Games
    QPushButton*  _bullet1MPushButton;
    QPushButton*  _blitz3MPushButton;
    QPushButton*  _blitz3MInc2SecPushButton;
    QPushButton*  _blitz5MPushButton;
    QPushButton*  _blitz10MPushButton;
    QPushButton*  _rapid15MPushButton;

    // Color buttons
    QPushButton* _blackColorPushButton;
    QPushButton* _randomColorPushButton;
    QPushButton* _whiteColorPushButton;

    // Return button
    QPushButton* _returnPushButton;



    QPushButton*  _PlayButton;
    QPushButton* _ReturnButton;
};

#endif // PVPMENU_HPP
