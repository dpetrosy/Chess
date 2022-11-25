#include "pvpmenu.hpp"
#include "toggleswitch.hpp"
#include "utils.hpp"

PVPMenu::PVPMenu(QWidget *parent) :
    QWidget(parent)
{
    // Init class members
    init();

    // Make PVPMenu
    makePVPMenu();
}

PVPMenu::~PVPMenu()
{
    delete _bkgLabel;
    delete _topTextLabel;

    // Game Variant
    delete _gameVariantTextLabel;
    delete _gameVariantComboBox;

    // Time Control
    delete _timeControlBkgLabel;
    delete _timeControlTextLabel;
    delete _timeControlComboBox;
    //minutes controler
    //increment seconds controler

    // Quick Games
    delete _bullet1MPushButton;
    delete _blitz3MPushButton;
    delete _blitz3MInc2SecPushButton;
    delete _blitz5MPushButton;
    delete _blitz10MPushButton;
    delete _rapid15MPushButton;

    // Color buttons
    delete _blackColorPushButton;
    delete _randomColorPushButton;
    delete _whiteColorPushButton;

    // Return button
    delete _returnPushButton;



    // Push Buttons
    delete _PlayButton;
    delete _ReturnButton;
}

// Init
void PVPMenu::init()
{
    _bkgLabel = new QLabel();
    _topTextLabel = new QLabel();

    // Game Variant
    _gameVariantTextLabel = new QLabel();
    _gameVariantComboBox = new QComboBox();

    // Time Control
    _timeControlBkgLabel = new QLabel();
    _timeControlTextLabel = new QLabel();
    _timeControlComboBox = new QComboBox();
    //minutes controler
    //increment seconds controler

    // Quick Games
    _bullet1MPushButton = new QPushButton();
    _blitz3MPushButton = new QPushButton();
    _blitz3MInc2SecPushButton = new QPushButton();
    _blitz5MPushButton = new QPushButton();
    _blitz10MPushButton = new QPushButton();
    _rapid15MPushButton = new QPushButton();

    // Color buttons
    _blackColorPushButton = new QPushButton();
    _randomColorPushButton = new QPushButton();
    _whiteColorPushButton = new QPushButton();

    // Return button
    _returnPushButton = new QPushButton();



    // Push Buttons
    _PlayButton = new QPushButton("Play", this);
    _ReturnButton = new QPushButton("Return", this);
}

// Public util functions
QPushButton *PVPMenu::getPushButton(PVPMenuPushButtons button)
{
    switch (button)
    {
        case PVPMenuPushButtons::PlayButton: return _PlayButton;
        case PVPMenuPushButtons::ReturnButton: return _ReturnButton;
        default: return _ReturnButton;
    }
}

// Private util functions
void PVPMenu::makePVPMenu()
{
    // Set buttons geometry
    _PlayButton->setGeometry((int)PVPMenuProps::PlayButtonX, (int)PVPMenuProps::PlayButtonY, (int)PVPMenuProps::ReturnButtonW, (int)PVPMenuProps::ReturnButtonH);
    _ReturnButton->setGeometry((int)PVPMenuProps::ReturnButtonX, (int)PVPMenuProps::ReturnButtonY, (int)PVPMenuProps::ReturnButtonW, (int)PVPMenuProps::ReturnButtonH);

    // Set buttons fonts
    setPushButtonFont(_PlayButton, (int)PVPMenuProps::PlayButtonFont);
    setPushButtonFont(_ReturnButton, (int)PVPMenuProps::ReturnButtonFont);
}
