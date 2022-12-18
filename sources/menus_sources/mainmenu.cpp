#include "mainmenu.hpp"
#include "mainwindow.hpp"
#include "settingsmenu.hpp"
#include "utils.hpp"

MainMenu::MainMenu(QWidget *parent) :
    QWidget(parent)
{
    // Init class members
    init();

    // Make MainMenu
    makeMainMenu();
}

MainMenu::~MainMenu()
{
    delete _PVPButton;
    delete _PVCButton;
    delete _InstrButton;
    delete _SettingsButton;
    delete _QuitButton;
    delete _verLayout;
    delete _horLayout;
    delete _versionTextLabel;
    delete _widgetForVerLayout;
    delete _widgetForHorLayout;
}

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

    // Version text label
    _versionTextLabel = new QLabel(this);
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

void MainMenu::makeMenuBeforeSwitch(SettingsMenu* settingMenuWidget, MainWindow* mainWindow)
{
    // set bkg image
    mainWindow->setBackgroundImage(settingMenuWidget->getData().bkgImageStr);

    if (gLanguage == Languages::Armenian)
    {
        _PVPButton->setText("Խաղալ ընկերոջ հետ");
        _PVCButton->setText("Խաղալ համակարգչի հետ");
        _InstrButton->setText("Կանոններ");
        _SettingsButton->setText("Կարգավորումներ");
        _QuitButton->setText("Լքել");
        _versionTextLabel->setText("Տարբերակ: 1.2.4");
        _versionTextLabel->move((int)MainMenuProps::VersionTextLabelX - 20, (int)MainMenuProps::VersionTextLabelY);
    }
    else if (gLanguage == Languages::Russian)
    {
        _PVPButton->setText("Сыграть с Другом");
        _PVCButton->setText("Сыграть с Компьютером");
        _InstrButton->setText("Правила");
        _SettingsButton->setText("Настройки");
        _QuitButton->setText("Выйти");
        _versionTextLabel->setText("Версия: 1.2.4");
        _versionTextLabel->move((int)MainMenuProps::VersionTextLabelX, (int)MainMenuProps::VersionTextLabelY);
    }
    else // English US
    {
        _PVPButton->setText("Player vs Player");
        _PVCButton->setText("Player vs Computer");
        _InstrButton->setText("Instructions");
        _SettingsButton->setText("Settings");
        _QuitButton->setText("Quit");
        _versionTextLabel->setText("Version: 1.2.4");
        _versionTextLabel->move((int)MainMenuProps::VersionTextLabelX, (int)MainMenuProps::VersionTextLabelY);
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

    // Set buttons style
    ::setStyleSheet(StylesPaths::MainMenuButtonStyle, _PVPButton);
    ::setStyleSheet(StylesPaths::MainMenuButtonStyle, _PVCButton);
    ::setStyleSheet(StylesPaths::MainMenuButtonStyle, _InstrButton);
    ::setStyleSheet(StylesPaths::MainMenuButtonStyle, _SettingsButton);
    ::setStyleSheet(StylesPaths::MainMenuButtonStyle, _QuitButton);

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

    // Version text label
    _versionTextLabel->setGeometry((int)MainMenuProps::VersionTextLabelX, (int)MainMenuProps::VersionTextLabelY, (int)MainMenuProps::VersionTextLabelW, (int)MainMenuProps::VersionTextLabelH);
    ::setStyleSheet(StylesPaths::VersionTextStyle, _versionTextLabel);
    _versionTextLabel->setText("Version: 1.2.4");

    // Hide PVC button
    _PVCButton->hide();
}
