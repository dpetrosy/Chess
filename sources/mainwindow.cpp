#include "mainwindow.hpp"
#include "mainmenu.hpp"
#include "pvpmenu.hpp"
#include "optionsmenu.hpp"
#include "gamewidget.hpp"
#include "helpers.hpp"


#include "qapplication.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    // Set MainWindow size
    this->setFixedSize((int)MainWindowProps::windowSizeW, (int)MainWindowProps::windowSizeH);

    // Init class members
    init();

    setBackgroundImage("background1.jpg", Backgrounds::Background);

    // Make stackedWidgets
    makeStackedWidgets();

    // Make connects
    makeConnects();

    // Set MainMenu when program start
    switchMenu(_PVPStackedWidget, Menus::MainMenu);
}

MainWindow::~MainWindow() {}

// Singlton pattern realization
MainWindow *MainWindow::_mainWindow = nullptr;

MainWindow *MainWindow::GetInstance(QWidget *parent)
{
    if(_mainWindow == nullptr)
        _mainWindow = new MainWindow(parent);

    return _mainWindow;
}

// Init
void MainWindow::init()
{
    // Menus Widgets
    _MainMenuWidget = new MainMenu();
    _PVPMenuWidget = new PVPMenu();
    _OptionsMenuWidget = new OptionsMenu();

    // StackedWidgets
    _PVPStackedWidget = new QStackedWidget();
    _OptionsStackedWidget = new QStackedWidget();

    // Chess game attributes
    _gameWidget = GameWidget::GetInstance(this);
}

// Public slots
void MainWindow::switchMenu(QStackedWidget *stackedWidget, Menus toMenu)
{
    setCentralWidget(stackedWidget);
    stackedWidget->setCurrentIndex((int)toMenu);
}

void MainWindow::showGame(QStackedWidget *stackedWidget)
{
    stackedWidget->hide();
    setCentralWidget(_gameWidget);

    /***************** Test until make PVP menu *****************/
    _gameWidget->setGameVariant(GameVariants::Standart);
    _gameWidget->setIsTimeAvailable(false);
    _gameWidget->setGameMinutes(0);
    _gameWidget->setIncrementSeconds(0);
    _gameWidget->setBelowPlayerColor(PiecesColors::White);
    _gameWidget->setQuickGame(QuickGames::NoSelected);
    /************************************************************/


    _gameWidget->showGameElements();
}

void MainWindow::showQuitWindow()
{
    if (QMessageBox::question(this, "Quit confirmation", "Are you sure you want to quit?", QMessageBox::Yes|QMessageBox::Cancel, QMessageBox::Cancel) == QMessageBox::Yes)
        exitFromProgram(0);
}

void MainWindow::exitFromProgram(int signal)
{
    /*******************//*    MUST CHANGE    *//*************************/
    if (signal == 0)
        exit(EXIT_SUCCESS);
}

// Public util functions
void MainWindow::setBackgroundImage(const QString& image, Backgrounds bkg)
{
    if (bkg == Backgrounds::Background)
        _backgroundImage.load(ImagesPaths::backgroundsPath + image);
    else
        _backgroundImage.load(ImagesPaths::boardsPath + image);
    _backgroundImage = _backgroundImage.scaled(this->size(), Qt::IgnoreAspectRatio);
    _palette.setBrush(QPalette::Window, _backgroundImage);
    this->setPalette(_palette);
}

QStackedWidget *MainWindow::getStackedWidget(MainMenuStackedWidgets stackedWidget)
{
    switch (stackedWidget)
    {
        case MainMenuStackedWidgets::PVPStackedWidget: return _PVPStackedWidget;
        default: return _PVPStackedWidget;
    }
}

// Private util functions
void MainWindow::makeStackedWidgets()
{
    // PVP StackedWidget
    makeStackedWidget(_PVPStackedWidget, _MainMenuWidget, _PVPMenuWidget);

    // Options StackedWidget
    makeStackedWidget(_OptionsStackedWidget, _OptionsMenuWidget);
}

void MainWindow::makeConnects()
{
    // MainMenu connects
    connect(_MainMenuWidget->getPushButton(MainMenuPushButtons::PVPButton), &QPushButton::clicked, this, std::bind(&MainWindow::switchMenu, this, _PVPStackedWidget, Menus::PVPMenu));
    connect(_MainMenuWidget->getPushButton(MainMenuPushButtons::QuitButton), &QPushButton::clicked, this, std::bind(&MainWindow::showQuitWindow, this));
    connect(_MainMenuWidget->getPushButton(MainMenuPushButtons::OptionsButton), &QPushButton::clicked, this, std::bind(&MainWindow::switchMenu, this, _OptionsStackedWidget, Menus::OptionsMenu));

    // PVPMenu connects
    connect(_PVPMenuWidget->getPushButton(PVPMenuPushButtons::PlayButton), &QPushButton::clicked, this, std::bind(&MainWindow::showGame, this, _PVPStackedWidget));
    connect(_PVPMenuWidget->getPushButton(PVPMenuPushButtons::ReturnButton), &QPushButton::clicked, this, std::bind(&MainWindow::switchMenu, this, _PVPStackedWidget, Menus::MainMenu));
}
