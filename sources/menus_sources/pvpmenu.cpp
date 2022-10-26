#include "pvpmenu.hpp"
#include "utils.hpp"

PVPMenu::PVPMenu(QWidget *parent) :
    QWidget(parent)
{
    // Setup class members
    setup();

    // Make PVPMenu
    makePVPMenu();
}

PVPMenu::~PVPMenu() {}

// Setup
void PVPMenu::setup()
{
    // Push Buttons
    PlayButton = new QPushButton("Play", this);
    ReturnButton = new QPushButton("Return", this);
}

// Public util functions
QPushButton *PVPMenu::getPushButton(PVPMenuPushButtons button)
{
    switch (button)
    {
        case PVPMenuPushButtons::PlayButton: return PlayButton;
        case PVPMenuPushButtons::ReturnButton: return ReturnButton;
        default: return ReturnButton;
    }
}

// Private util functions
void PVPMenu::makePVPMenu()
{
    // Set buttons geometry
    PlayButton->setGeometry((int)PVPMenuProps::PlayButtonX, (int)PVPMenuProps::PlayButtonY, (int)PVPMenuProps::ReturnButtonW, (int)PVPMenuProps::ReturnButtonH);
    ReturnButton->setGeometry((int)PVPMenuProps::ReturnButtonX, (int)PVPMenuProps::ReturnButtonY, (int)PVPMenuProps::ReturnButtonW, (int)PVPMenuProps::ReturnButtonH);

    // Set buttons fonts
    setPushButtonFont(PlayButton, (int)PVPMenuProps::PlayButtonFont);
    setPushButtonFont(ReturnButton, (int)PVPMenuProps::ReturnButtonFont);
}
