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

    setBackgroundImage(BackgroundImages::StrongKnight);

    // Make stackedWidgets
    makeMenusStackedWidget();

    // Make connects
    makeConnects();

    // Set MainMenu when program start
    setCentralWidget(this->_MenusStackedWidget);
    //switchMenu(Menus::MainMenu);
}

MainWindow::~MainWindow()
{
    // Menus Widgets
    delete _MainMenuWidget;
    delete _PVPMenuWidget;
    delete _SettingsMenuWidget;

    // Chess game attributes
    delete _GameWidget;

    // StackedWidgets
    delete _MenusStackedWidget;
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
    if (toMenu == Menus::PVPMenu)
        _PVPMenuWidget->makeMenuBeforeSwitch();
    else if (toMenu == Menus::SettingsMenu)
        _SettingsMenuWidget->makeMenuBeforeSwitch();
    else if (toMenu == Menus::MainMenu)
        _MainMenuWidget->makeMenuBeforeSwitch(_SettingsMenuWidget, this);

    _MenusStackedWidget->setCurrentIndex((int)toMenu);
}

void MainWindow::showGame(double minutes, int incSeconds, PiecesColors color)
{
    switchMenu(Menus::GameWidget);

    _PVPMenuWidget->setDataBeforeStartGame(minutes, incSeconds, color);
    _GameWidget->startGame();






    // ************************** TEST *************************** //
//    qDebug() << "Variant: " << _GameWidget->getGameData().gameVariant;
//    qDebug() << "Time available: " << _GameWidget->getGameData().isTimeAvailable;
//    qDebug() << "Minutes: " << _GameWidget->getGameData().gameMinutes;
//    qDebug() << "Seconds: " << _GameWidget->getGameData().incrementSeconds;
//    if (_GameWidget->getGameData().belowPlayerColor == PiecesColors::Black)
//        qDebug() << "Color: Black";
//    else
//        qDebug() << "Color: White";
//    qDebug() << "Piece Set: " << _GameWidget->getPieceSet();

//    qDebug() << "\n";
}

void MainWindow::showQuitWindow()
{
    if (gLanguage == Languages::Armenian)
    {
        if (QMessageBox::question(this, "Լքման հաստատում", "Դուք վստահ եք, որ ցանկանում եք դուրս գալ?", QMessageBox::Yes|QMessageBox::Cancel, QMessageBox::Cancel) == QMessageBox::Yes)
            exitFromProgram(0);
    }
    else if (gLanguage == Languages::Russian)
    {
        if (QMessageBox::question(this, "Подтверждение выхода", "Вы уверены, что хотите выйти?", QMessageBox::Yes|QMessageBox::Cancel, QMessageBox::Cancel) == QMessageBox::Yes)
            exitFromProgram(0);
    }
    else // Endlish US
    {
        if (QMessageBox::question(this, "Quit confirmation", "Are you sure you want to quit?", QMessageBox::Yes|QMessageBox::Cancel, QMessageBox::Cancel) == QMessageBox::Yes)
            exitFromProgram(0);
    }
}

void MainWindow::exitFromProgram(int signal)
{
    QCoreApplication::exit(signal);
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
    makeStackedWidget(_MenusStackedWidget, _MainMenuWidget, _PVPMenuWidget, _SettingsMenuWidget, _GameWidget);
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

    // GameWidget connects
    connect(_GameWidget->getReturnButton(), &ClickableLabel::clickedLeftButton, this, std::bind(&MainWindow::switchMenu, this, Menus::MainMenu));
}
