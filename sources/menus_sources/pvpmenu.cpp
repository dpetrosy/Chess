#include "pvpmenu.hpp"

PVPMenu::PVPMenu(QWidget *parent) :
    QWidget(parent)
{
    // Setup class members
    setup();

    // Make PVPMenu
    makePVPMenu();
}

PVPMenu::~PVPMenu() {}

// Setups
void PVPMenu::setup()
{
    // Push Buttons
    PlayButton = new QPushButton("Play");
    ReturnButton = new QPushButton("Return");
}

// Utils functions
QPushButton *PVPMenu::getPushButton(PVPMenuPushButtons button)
{
    switch (button)
    {
        case PVPMenuPushButtons::PlayButton: return PlayButton;
        case PVPMenuPushButtons::ReturnButton: return ReturnButton;
        default: return ReturnButton;
    }
}

void PVPMenu::makePVPMenu()
{
    // Set buttons sizes
    setPushButtonSize(PlayButton, (int)PVPMenuProps::PlayButtonW, (int)PVPMenuProps::PlayButtonH);
    setPushButtonSize(ReturnButton, (int)PVPMenuProps::ReturnButtonW, (int)PVPMenuProps::ReturnButtonH);

    // Set buttons positions
    PlayButton->move((int)PVPMenuProps::PlayButtonX, (int)PVPMenuProps::PlayButtonY);
    ReturnButton->move((int)PVPMenuProps::ReturnButtonX, (int)PVPMenuProps::ReturnButtonY);

    // Set buttons fonts
    setPushButtonFont(PlayButton, (int)PVPMenuProps::PlayButtonFont);
    setPushButtonFont(ReturnButton, (int)PVPMenuProps::ReturnButtonFont);

    // Set parents
    PlayButton->setParent(this);
    ReturnButton->setParent(this);
}
