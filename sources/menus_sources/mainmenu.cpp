#include "mainmenu.hpp"
#include "mainwindow.hpp"
#include "utils.hpp"

MainMenu::MainMenu(QWidget *parent) :
    QWidget(parent)
{
    // Init class members
    init();

    // Make MainMenu
    makeMainMenu();
}

MainMenu::~MainMenu() {}

// Init
void MainMenu::init()
{
    // Widgets
    _widgetForVerLayout = new QWidget(this);
    _widgetForHorLayout = new QWidget(this);

    // Layouts
    _verLayout = new QVBoxLayout(_widgetForVerLayout);
    _horLayout = new QHBoxLayout(_widgetForHorLayout);

    // Push Buttons
    _PVPButton = new QPushButton("Player vs Player");
    _PVCButton = new QPushButton("Player vs Computer");
    _InstrButton = new QPushButton("Instructions");
    _SettingsButton = new QPushButton("Settings");
    _QuitButton = new QPushButton("Quit");
}

// Public util functions
QPushButton *MainMenu::getPushButton(MainMenuPushButtons button)
{
    switch (button)
    {
        case MainMenuPushButtons::PVPButton: return _PVPButton;
        case MainMenuPushButtons::PVCButton: return _PVCButton;
        case MainMenuPushButtons::InstrButton: return _InstrButton;
        case MainMenuPushButtons::SettingsButton: return _SettingsButton;
        case MainMenuPushButtons::QuitButton: return _QuitButton;
        default: return _PVPButton;
    }
}

// Private util functions
void MainMenu::makeMainMenu()
{
    // Set buttons sizes
    setPushButtonSize(_PVPButton, (int)MainMenuProps::verLayoutButtonsW, (int)MainMenuProps::verLayoutButtonsH);
    setPushButtonSize(_PVCButton, (int)MainMenuProps::verLayoutButtonsW, (int)MainMenuProps::verLayoutButtonsH);
    setPushButtonSize(_InstrButton, (int)MainMenuProps::verLayoutButtonsW, (int)MainMenuProps::verLayoutButtonsH);
    setPushButtonSize(_SettingsButton, (int)MainMenuProps::horLayoutButtonsW, (int)MainMenuProps::horLayoutButtonsH);
    setPushButtonSize(_QuitButton, (int)MainMenuProps::horLayoutButtonsW, (int)MainMenuProps::horLayoutButtonsH);

    // Set buttons fonts
    setPushButtonFont(_PVPButton, (int)MainMenuProps::verLayoutButtonsFont);
    setPushButtonFont(_PVCButton, (int)MainMenuProps::verLayoutButtonsFont);
    setPushButtonFont(_InstrButton, (int)MainMenuProps::verLayoutButtonsFont);
    setPushButtonFont(_SettingsButton, (int)MainMenuProps::horLayoutButtonsFont);
    setPushButtonFont(_QuitButton, (int)MainMenuProps::horLayoutButtonsFont);

    // Add buttons to layouts
    _verLayout->addWidget(_PVPButton);
    _verLayout->addWidget(_PVCButton);
    _verLayout->addWidget(_InstrButton);
    _horLayout->addWidget(_SettingsButton);
    _horLayout->addWidget(_QuitButton);

    // Set geometry for layouts
    QRect rect((int)MainMenuProps::verLayoutX, (int)MainMenuProps::verLayoutY, (int)MainMenuProps::verLayoutW, (int)MainMenuProps::verLayoutH);
    _widgetForVerLayout->setGeometry(rect);
    rect.setRect((int)MainMenuProps::horLayoutX, (int)MainMenuProps::horLayoutY, (int)MainMenuProps::horLayoutW, (int)MainMenuProps::horLayoutH);
    _widgetForHorLayout->setGeometry(rect);
}
