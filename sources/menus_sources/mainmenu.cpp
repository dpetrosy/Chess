#include "mainmenu.hpp"
#include "mainwindow.hpp"
#include "utils.hpp"

MainMenu::MainMenu(QWidget *parent) :
    QWidget(parent)
{
    // Setup class members
    setup();

    // Make MainMenu
    makeMainMenu();
}

MainMenu::~MainMenu() {}

// Setup
void MainMenu::setup()
{
    // Widgets
    widgetForVerLayout = new QWidget(this);
    widgetForHorLayout = new QWidget(this);

    // Layouts
    verLayout = new QVBoxLayout(widgetForVerLayout);
    horLayout = new QHBoxLayout(widgetForHorLayout);

    // Push Buttons
    PVPButton = new QPushButton("Player vs Player");
    PVCButton = new QPushButton("Player vs Computer");
    InstrButton = new QPushButton("Instructions");
    OptionsButton = new QPushButton("Options");
    QuitButton = new QPushButton("Quit");
}

// Private util functions
QPushButton *MainMenu::getPushButton(MainMenuPushButtons button)
{
    switch (button)
    {
        case MainMenuPushButtons::PVPButton: return PVPButton;
        case MainMenuPushButtons::PVCButton: return PVCButton;
        case MainMenuPushButtons::InstrButton: return InstrButton;
        case MainMenuPushButtons::OptionsButton: return OptionsButton;
        case MainMenuPushButtons::QuitButton: return QuitButton;
        default: return PVPButton;
    }
}

void MainMenu::makeMainMenu()
{

    // Set buttons sizes
    setPushButtonSize(PVPButton, (int)MainMenuProps::verLayoutButtonsW, (int)MainMenuProps::verLayoutButtonsH);
    setPushButtonSize(PVCButton, (int)MainMenuProps::verLayoutButtonsW, (int)MainMenuProps::verLayoutButtonsH);
    setPushButtonSize(InstrButton, (int)MainMenuProps::verLayoutButtonsW, (int)MainMenuProps::verLayoutButtonsH);
    setPushButtonSize(OptionsButton, (int)MainMenuProps::horLayoutButtonsW, (int)MainMenuProps::horLayoutButtonsH);
    setPushButtonSize(QuitButton, (int)MainMenuProps::horLayoutButtonsW, (int)MainMenuProps::horLayoutButtonsH);

    // Set buttons fonts
    setPushButtonFont(PVPButton, (int)MainMenuProps::verLayoutButtonsFont);
    setPushButtonFont(PVCButton, (int)MainMenuProps::verLayoutButtonsFont);
    setPushButtonFont(InstrButton, (int)MainMenuProps::verLayoutButtonsFont);
    setPushButtonFont(OptionsButton, (int)MainMenuProps::horLayoutButtonsFont);
    setPushButtonFont(QuitButton, (int)MainMenuProps::horLayoutButtonsFont);

    // Add buttons to layouts
    verLayout->addWidget(PVPButton);
    verLayout->addWidget(PVCButton);
    verLayout->addWidget(InstrButton);
    horLayout->addWidget(OptionsButton);
    horLayout->addWidget(QuitButton);

    // Set geometry for layouts
    QRect rect((int)MainMenuProps::verLayoutX, (int)MainMenuProps::verLayoutY, (int)MainMenuProps::verLayoutW, (int)MainMenuProps::verLayoutH);
    widgetForVerLayout->setGeometry(rect);
    rect.setRect((int)MainMenuProps::horLayoutX, (int)MainMenuProps::horLayoutY, (int)MainMenuProps::horLayoutW, (int)MainMenuProps::horLayoutH);
    widgetForHorLayout->setGeometry(rect);    
}
