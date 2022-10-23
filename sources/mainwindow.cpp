#include "mainwindow.hpp"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    // Set MainWindow size
    this->setFixedSize((int)MainWindowProps::windowSizeW, (int)MainWindowProps::windowSizeH);
    ui->setupUi(this);

    // Setup class members
    setup();

    setBackgroundImage("background.jpg");

    // Make connects
    makeConnections();

    // Make stackedWidgets
    makeStackedWidgets();

    // Set MainMenu when program start
    switchMenu(stackedWidgetPVP, Menus::MainMenu);
}

MainWindow::~MainWindow() {}

// Slots
void MainWindow::switchMenu(QStackedWidget *stackedWidget, Menus toMenu)
{
    setCentralWidget(stackedWidget);
    stackedWidget->setCurrentIndex((int)toMenu);
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

// Setups
void MainWindow::setup()
{
    // Menus Widgets
    mainMenuWidget = new MainMenu();
    PVPMenuWidget = new PVPMenu();
    quitDialog = new QuitDialog();

    // StackedWidgets
    stackedWidgetPVP = new QStackedWidget();    




    // Chess game attributes
    //gameWidget = GameWidget::GetInstance(this);
}

// Utils functions
void MainWindow::setBackgroundImage(const QString& image)
{
    backgroundImage.load(ImagesPaths::backgroundsPath + image);
    backgroundImage = backgroundImage.scaled(this->size(), Qt::IgnoreAspectRatio);
    palette.setBrush(QPalette::Window, backgroundImage);
    this->setPalette(palette);
}

void MainWindow::makeConnections()
{
    // MainMenu connects
    connect(mainMenuWidget->getPushButton(MainMenuPushButtons::PVPButton), &QPushButton::clicked, this, std::bind(&MainWindow::switchMenu, this, stackedWidgetPVP, Menus::PVPMenu));
    connect(mainMenuWidget->getPushButton(MainMenuPushButtons::QuitButton), &QPushButton::clicked, this, std::bind(&MainWindow::showQuitDialog, this));

    // PVPMenu connects
    //connect(PVPMenuWidget->getPushButton(PVPMenuPushButtons::PlayButton), &QPushButton::clicked, this, std::bind(&MainWindow::showGame, this, stackedWidgetPVP));
    connect(PVPMenuWidget->getPushButton(PVPMenuPushButtons::ReturnButton), &QPushButton::clicked, this, std::bind(&MainWindow::switchMenu, this, stackedWidgetPVP, Menus::MainMenu));

    // QuitDialog connects
    connect(quitDialog->getQDialogButtonBox(), &QDialogButtonBox::accepted, this, std::bind(&MainWindow::exitFromProgram, this));
    connect(quitDialog->getQDialogButtonBox(), &QDialogButtonBox::rejected, this, std::bind(&QuitDialog::reject, quitDialog));
}

//void MainWindow::showGame(QStackedWidget *stackedWidget)
//{
//    stackedWidget->hide();
//    //setCentralWidget(gameWidget);
//}

void MainWindow::makeStackedWidgets()
{
    // PVP StackedWidget
    makeStackedWidget(stackedWidgetPVP, mainMenuWidget, PVPMenuWidget);
}
