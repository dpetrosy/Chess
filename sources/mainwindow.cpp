#include "mainwindow.hpp"
#include "mainmenu.hpp"
#include "pvpmenu.hpp"
#include "settingsmenu.hpp"
#include "gamewidget.hpp"
#include "helpers.hpp"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    // Set MainWindow size
    this->setFixedSize((int)MainWindowProps::windowSizeW, (int)MainWindowProps::windowSizeH);

    // Init class members
    init();

    setBackgroundImage(BackgroundImages::TheRook);

    // Make stackedWidgets
    makeMenusStackedWidget();

    // Make connects
    makeConnects();

    // Set MainMenu when program start
    switchMenu(Menus::MainMenu);
}

MainWindow::~MainWindow()
{
    // Menus Widgets
    delete _MainMenuWidget;
    delete _PVPMenuWidget;
    delete _SettingsMenuWidget;

    // StackedWidgets
    delete _MenusStackedWidget;

    // Chess game attributes
    delete _GameWidget;
}

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
    _SettingsMenuWidget = new SettingsMenu();

    // Menus StackedWidget
    _MenusStackedWidget = new QStackedWidget();

    // Chess game attributes
    _GameWidget = GameWidget::GetInstance(this);
}

// Public slots
void MainWindow::switchMenu(Menus toMenu)
{
    setCentralWidget(_MenusStackedWidget);

    if (toMenu == Menus::PVPMenu)
        _PVPMenuWidget->makeMenuBeforeSwitch();
    else if (toMenu == Menus::SettingsMenu)
        _SettingsMenuWidget->makeMenuBeforeSwitch();

    _MenusStackedWidget->setCurrentIndex((int)toMenu);
}

void MainWindow::showGame(double minutes, int incSeconds, PiecesColors color)
{
    _MenusStackedWidget->hide();
    setCentralWidget(_GameWidget);

    _PVPMenuWidget->setDataBeforeStartGame(minutes, incSeconds, color);
    _GameWidget->showGameElements();






    // ************************** TEST *************************** //
    qDebug() << "Time available: " << _GameWidget->getGameData().isTimeAvailable;
    qDebug() << "Minutes: " << _GameWidget->getGameData().gameMinutes;
    qDebug() << "Seconds: " << _GameWidget->getGameData().incrementSeconds;
    if (_GameWidget->getGameData().belowPlayerColor == PiecesColors::Black)
        qDebug() << "Color: Black";
    else
        qDebug() << "Color: White";

    qDebug() << "\n";
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
void MainWindow::setBackgroundImage(const QString& image)
{
    _backgroundImage.load(ImagesPaths::backgroundsPath + image + BackgroundImages::Extencion);
    _backgroundImage = _backgroundImage.scaled(this->size(), Qt::IgnoreAspectRatio);
    _palette.setBrush(QPalette::Window, _backgroundImage);
    this->setPalette(_palette);
}

QStackedWidget* MainWindow::getStackedWidget()
{
    return _MenusStackedWidget;
}

// Private util functions
void MainWindow::makeMenusStackedWidget()
{
    makeStackedWidget(_MenusStackedWidget, _MainMenuWidget, _PVPMenuWidget, _SettingsMenuWidget);
}

void MainWindow::makeConnects()
{
    // MainMenu connects
    connect(_MainMenuWidget->getPushButton(MainMenuPushButtons::PVPButton), &QPushButton::clicked, this, std::bind(&MainWindow::switchMenu, this, Menus::PVPMenu));
    connect(_MainMenuWidget->getPushButton(MainMenuPushButtons::QuitButton), &QPushButton::clicked, this, std::bind(&MainWindow::showQuitWindow, this));
    connect(_MainMenuWidget->getPushButton(MainMenuPushButtons::SettingsButton), &QPushButton::clicked, this, std::bind(&MainWindow::switchMenu, this, Menus::SettingsMenu));

    // PVPMenu connects
    connect(_PVPMenuWidget->getStartGameButton(StartGameButtons::Bullet1M), &StartGameButton::clickedLeftButton, this, std::bind(&MainWindow::showGame, this, 1, 0, PiecesColors::Random));
    connect(_PVPMenuWidget->getStartGameButton(StartGameButtons::Blitz3M), &StartGameButton::clickedLeftButton, this, std::bind(&MainWindow::showGame, this, 3, 0, PiecesColors::Random));
    connect(_PVPMenuWidget->getStartGameButton(StartGameButtons::Blitz3MInc2Sec), &StartGameButton::clickedLeftButton, this, std::bind(&MainWindow::showGame, this, 3, 2, PiecesColors::Random));
    connect(_PVPMenuWidget->getStartGameButton(StartGameButtons::Blitz5M), &StartGameButton::clickedLeftButton, this, std::bind(&MainWindow::showGame, this, 5, 0, PiecesColors::Random));
    connect(_PVPMenuWidget->getStartGameButton(StartGameButtons::Blitz10M), &StartGameButton::clickedLeftButton, this, std::bind(&MainWindow::showGame, this, 10, 0, PiecesColors::Random));
    connect(_PVPMenuWidget->getStartGameButton(StartGameButtons::Rapid15M), &StartGameButton::clickedLeftButton, this, std::bind(&MainWindow::showGame, this, 15, 0, PiecesColors::Random));
    connect(_PVPMenuWidget->getStartGameButton(StartGameButtons::BlackColor), &StartGameButton::clickedLeftButton, this, std::bind(&MainWindow::showGame, this, 0, 0, PiecesColors::Black));
    connect(_PVPMenuWidget->getStartGameButton(StartGameButtons::RandomColor), &StartGameButton::clickedLeftButton, this, std::bind(&MainWindow::showGame, this, 0, 0, PiecesColors::Random));
    connect(_PVPMenuWidget->getStartGameButton(StartGameButtons::WhiteColor), &StartGameButton::clickedLeftButton, this, std::bind(&MainWindow::showGame, this, 0, 0, PiecesColors::White));







    connect(_PVPMenuWidget->getReturnButton(), &ClickableLabel::clickedLeftButton, this, std::bind(&MainWindow::switchMenu, this, Menus::MainMenu));

    // Settings menu connects
    connect(_SettingsMenuWidget->getPushButton(SettingsMenuPushButtons::CancelButton), &QPushButton::clicked, _SettingsMenuWidget, std::bind(&SettingsMenu::cancelButtonClicked, _SettingsMenuWidget));
    connect(_SettingsMenuWidget->getPushButton(SettingsMenuPushButtons::SaveButton), &QPushButton::clicked, _SettingsMenuWidget, std::bind(&SettingsMenu::saveButtonClicked, _SettingsMenuWidget));
}
