#include "optionsmenu.hpp"

OptionsMenu::OptionsMenu(QWidget *parent) :
    QWidget(parent)
{
    // Init class members
    init();

    // Make OptionsMenu
    makeOptionsMenu();
}

OptionsMenu::~OptionsMenu() {}

// Init
void OptionsMenu::init()
{
    // Widgets

    // Layouts

    // Push Buttons
}

// Private util functions

void OptionsMenu::makeOptionsMenu()
{
//    // Set buttons sizes
//    setPushButtonSize(_PVPButton, (int)OptionsMenuProps::verLayoutButtonsW, (int)OptionsMenuProps::verLayoutButtonsH);
//    setPushButtonSize(_PVCButton, (int)OptionsMenuProps::verLayoutButtonsW, (int)OptionsMenuProps::verLayoutButtonsH);
//    setPushButtonSize(_InstrButton, (int)OptionsMenuProps::verLayoutButtonsW, (int)OptionsMenuProps::verLayoutButtonsH);
//    setPushButtonSize(_OptionsButton, (int)OptionsMenuProps::horLayoutButtonsW, (int)OptionsMenuProps::horLayoutButtonsH);
//    setPushButtonSize(_QuitButton, (int)OptionsMenuProps::horLayoutButtonsW, (int)OptionsMenuProps::horLayoutButtonsH);

//    // Set buttons fonts
//    setPushButtonFont(_PVPButton, (int)OptionsMenuProps::verLayoutButtonsFont);
//    setPushButtonFont(_PVCButton, (int)OptionsMenuProps::verLayoutButtonsFont);
//    setPushButtonFont(_InstrButton, (int)OptionsMenuProps::verLayoutButtonsFont);
//    setPushButtonFont(_OptionsButton, (int)OptionsMenuProps::horLayoutButtonsFont);
//    setPushButtonFont(_QuitButton, (int)OptionsMenuProps::horLayoutButtonsFont);

//    // Add buttons to layouts
//    _verLayout->addWidget(_PVPButton);
//    _verLayout->addWidget(_PVCButton);
//    _verLayout->addWidget(_InstrButton);
//    _horLayout->addWidget(_OptionsButton);
//    _horLayout->addWidget(_QuitButton);

//    // Set geometry for layouts
//    QRect rect((int)OptionsMenuProps::verLayoutX, (int)OptionsMenuProps::verLayoutY, (int)OptionsMenuProps::verLayoutW, (int)OptionsMenuProps::verLayoutH);
//    _widgetForVerLayout->setGeometry(rect);
//    rect.setRect((int)OptionsMenuProps::horLayoutX, (int)OptionsMenuProps::horLayoutY, (int)OptionsMenuProps::horLayoutW, (int)OptionsMenuProps::horLayoutH);
//    _widgetForHorLayout->setGeometry(rect);
}
