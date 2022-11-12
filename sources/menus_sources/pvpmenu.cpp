#include "pvpmenu.hpp"
#include "utils.hpp"

PVPMenu::PVPMenu(QWidget *parent) :
    QWidget(parent)
{
    // Init class members
    init();

    // Make PVPMenu
    makePVPMenu();
}

PVPMenu::~PVPMenu() {}

// Init
void PVPMenu::init()
{
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
