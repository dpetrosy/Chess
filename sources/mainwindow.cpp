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
    switchMenu(PVPStackedWidget, Menus::MainMenu);
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
    mainMenuWidget = new MainMenu();
    PVPMenuWidget = new PVPMenu();
    quitDialog = new QuitDialog();

    // StackedWidgets
    PVPStackedWidget = new QStackedWidget();

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
    _gameWidget->showGameElements();
}

void MainWindow::showQuitDialog()
{
    quitDialog->setModal(true);
    quitDialog->show();
}

void MainWindow::exitFromProgram()
{
    /*******************//*    MUST CHANGE    *//*************************/
    exit(EXIT_SUCCESS);
}

// Public util functions
void MainWindow::setBackgroundImage(const QString& image)
{
    backgroundImage.load(ImagesPaths::backgroundsPath + image);
    backgroundImage = backgroundImage.scaled(this->size(), Qt::IgnoreAspectRatio);
    palette.setBrush(QPalette::Window, backgroundImage);
    this->setPalette(palette);
}

QStackedWidget *MainWindow::getStackedWidget(MainMenuStackedWidgets stackedWidget)
{
    switch (stackedWidget)
    {
        case MainMenuStackedWidgets::PVPStackedWidget: return PVPStackedWidget;
        default: return PVPStackedWidget;
    }
}

// Private util functions
void MainWindow::makeStackedWidgets()
{
    // PVP StackedWidget
    makeStackedWidget(PVPStackedWidget, mainMenuWidget, PVPMenuWidget);
}

void MainWindow::makeConnects()
{
    // MainMenu connects
    connect(mainMenuWidget->getPushButton(MainMenuPushButtons::PVPButton), &QPushButton::clicked, this, std::bind(&MainWindow::switchMenu, this, PVPStackedWidget, Menus::PVPMenu));
    connect(mainMenuWidget->getPushButton(MainMenuPushButtons::QuitButton), &QPushButton::clicked, this, std::bind(&MainWindow::showQuitDialog, this));

    // PVPMenu connects
    connect(PVPMenuWidget->getPushButton(PVPMenuPushButtons::PlayButton), &QPushButton::clicked, this, std::bind(&MainWindow::showGame, this, PVPStackedWidget));
    connect(PVPMenuWidget->getPushButton(PVPMenuPushButtons::ReturnButton), &QPushButton::clicked, this, std::bind(&MainWindow::switchMenu, this, PVPStackedWidget, Menus::MainMenu));

    // QuitDialog connects
    connect(quitDialog->getQDialogButtonBox(), &QDialogButtonBox::accepted, this, std::bind(&MainWindow::exitFromProgram, this));
    connect(quitDialog->getQDialogButtonBox(), &QDialogButtonBox::rejected, this, std::bind(&QuitDialog::reject, quitDialog));
}
