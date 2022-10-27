#include "mainwindow.hpp"
#include "mainmenu.hpp"
#include "pvpmenu.hpp"
#include "quitdialog.hpp"
#include "gamewidget.hpp"
#include "helpers.hpp"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    // Set MainWindow size
    this->setFixedSize((int)MainWindowProps::windowSizeW, (int)MainWindowProps::windowSizeH);

    // Setup class members
    setup();

    setBackgroundImage("background.jpg");

    // Make stackedWidgets
    makeStackedWidgets();

    // Make connects
    makeConnects();

    // Set MainMenu when program start
    switchMenu(_PVPStackedWidget, Menus::MainMenu);
}

MainWindow::~MainWindow() {}

// Singltone realization
MainWindow *MainWindow::_mainWindow = nullptr;

MainWindow *MainWindow::GetInstance(QWidget *parent)
{
    if(_mainWindow == nullptr)
        _mainWindow = new MainWindow(parent);

    return _mainWindow;
}

// Setup
void MainWindow::setup()
{
    // Menus Widgets
    _mainMenuWidget = new MainMenu();
    _PVPMenuWidget = new PVPMenu();
    _quitDialog = new QuitDialog();

    // StackedWidgets
    _PVPStackedWidget = new QStackedWidget();

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
    _gameWidget->setIsWhite(true);
    _gameWidget->setQuickGame(QuickGames::NoSelected);
    /************************************************************/


    _gameWidget->showGameElements();
}

void MainWindow::showQuitDialog()
{
    _quitDialog->setModal(true);
    _quitDialog->show();
}

void MainWindow::exitFromProgram()
{
    /*******************//*    MUST CHANGE    *//*************************/
    exit(EXIT_SUCCESS);
}

// Public util functions
void MainWindow::setBackgroundImage(const QString& image)
{
    _backgroundImage.load(ImagesPaths::backgroundsPath + image);
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
    makeStackedWidget(_PVPStackedWidget, _mainMenuWidget, _PVPMenuWidget);
}

void MainWindow::makeConnects()
{
    // MainMenu connects
    connect(_mainMenuWidget->getPushButton(MainMenuPushButtons::PVPButton), &QPushButton::clicked, this, std::bind(&MainWindow::switchMenu, this,_PVPStackedWidget, Menus::PVPMenu));
    connect(_mainMenuWidget->getPushButton(MainMenuPushButtons::QuitButton), &QPushButton::clicked, this, std::bind(&MainWindow::showQuitDialog, this));

    // PVPMenu connects
    connect(_PVPMenuWidget->getPushButton(PVPMenuPushButtons::PlayButton), &QPushButton::clicked, this, std::bind(&MainWindow::showGame, this,_PVPStackedWidget));
    connect(_PVPMenuWidget->getPushButton(PVPMenuPushButtons::ReturnButton), &QPushButton::clicked, this, std::bind(&MainWindow::switchMenu, this,_PVPStackedWidget, Menus::MainMenu));

    // QuitDialog connects
    connect(_quitDialog->getQDialogButtonBox(), &QDialogButtonBox::accepted, this, std::bind(&MainWindow::exitFromProgram, this));
    connect(_quitDialog->getQDialogButtonBox(), &QDialogButtonBox::rejected, this, std::bind(&QuitDialog::reject, _quitDialog));
}
