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

    // Make menus for stackedWidgets
    makeMenus();

    // Make stackedWidgets
    makeStackedWidgets();

    /////////////////////////////////////////// change numbers to enums //
    stackedWidgetPVP->setCurrentIndex(0);
    setCentralWidget(stackedWidgetPVP);










//    wid = new QWidget;
//    QPushButton *button = new QPushButton(wid);
//    button->setGeometry(15, 15, 15, 15);
//    widget = new QStackedWidget();
//    widget->addWidget(wid);
//    //setCentralWidget(widget);
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

// Setups
void MainWindow::setup()
{
    // Images
    imagesPath = ":/images/images/";
    piecesPath = imagesPath + "pieces/";
    logosPath = imagesPath + "logos/";
    backgroundsPath = imagesPath + "backgrounds/";

    // Menus Structs
    mainMenuStruct = new MainMenu();
    PVPMenuStruct = new PVPMenu();

    // Menus Widgets
    mainMenuWidget = new QWidget();
    PVPMenuWidget = new QWidget();

    // StackedWidgets
    stackedWidgetPVP = new QStackedWidget();

    // Setup Menus Structs
    setupMainMenuStruct();
    setupPVPMenuStruct();

    // do setup inside QuilDialog class
    quitDialog = new QuitDialog();





    // Quit attributes
    //quitDialog = new QuitDialog();

    // Chess game attributes
    //gameWidget = GameWidget::GetInstance(this);
}

void MainWindow::setupMainMenuStruct()
{
    // Widgets
    mainMenuStruct->widgetForVerLayout = new QWidget(mainMenuWidget);
    mainMenuStruct->widgetForHorLayout = new QWidget(mainMenuWidget);

    // Layouts
    mainMenuStruct->verLayout = new QVBoxLayout(mainMenuStruct->widgetForVerLayout);
    mainMenuStruct->horLayout = new QHBoxLayout(mainMenuStruct->widgetForHorLayout);

    // Push Buttons
    mainMenuStruct->PVP = new QPushButton("Player vs Player");
    mainMenuStruct->PVC = new QPushButton("Player vs Computer");
    mainMenuStruct->Instructions = new QPushButton("Instructions");
    mainMenuStruct->Options = new QPushButton("Options");
    mainMenuStruct->Quit = new QPushButton("Quit");
}

void MainWindow::setupPVPMenuStruct()
{
    // Push Buttons
    PVPMenuStruct->Play = new QPushButton("Play");
    PVPMenuStruct->Return = new QPushButton("Return");
}

// Utils functions
void MainWindow::setBackgroundImage(const QString& image)
{
    backgroundImage.load(backgroundsPath + image);
    backgroundImage = backgroundImage.scaled(this->size(), Qt::IgnoreAspectRatio);
    palette.setBrush(QPalette::Window, backgroundImage);
    this->setPalette(palette);
}

void MainWindow::showGame(QStackedWidget *stackedWidget)
{
    stackedWidget->hide();
    //setCentralWidget(gameWidget);
}

// Make menus
void MainWindow::makeMenus()
{
    makeMainMenu();
    makePVPMenu();
}

void MainWindow::makeMainMenu()
{
    // Set buttons sizes
    setPushButtonSize(mainMenuStruct->PVP, (int)MainMenuProps::verLayoutButtonsW, (int)MainMenuProps::verLayoutButtonsH);
    setPushButtonSize(mainMenuStruct->PVC, (int)MainMenuProps::verLayoutButtonsW, (int)MainMenuProps::verLayoutButtonsH);
    setPushButtonSize(mainMenuStruct->Instructions, (int)MainMenuProps::verLayoutButtonsW, (int)MainMenuProps::verLayoutButtonsH);
    setPushButtonSize(mainMenuStruct->Options, (int)MainMenuProps::horLayoutButtonsW, (int)MainMenuProps::horLayoutButtonsH);
    setPushButtonSize(mainMenuStruct->Quit, (int)MainMenuProps::horLayoutButtonsW, (int)MainMenuProps::horLayoutButtonsH);

    // Set buttons fonts
    setPushButtonFont(mainMenuStruct->PVP, (int)MainMenuProps::verLayoutButtonsFont);
    setPushButtonFont(mainMenuStruct->PVC, (int)MainMenuProps::verLayoutButtonsFont);
    setPushButtonFont(mainMenuStruct->Instructions, (int)MainMenuProps::verLayoutButtonsFont);
    setPushButtonFont(mainMenuStruct->Options, (int)MainMenuProps::horLayoutButtonsFont);
    setPushButtonFont(mainMenuStruct->Quit, (int)MainMenuProps::horLayoutButtonsFont);

    // Connections
    connect(mainMenuStruct->PVP, &QPushButton::clicked, this, std::bind(&MainWindow::switchMenu, this, stackedWidgetPVP, Menus::PVPMenu));
    connect(mainMenuStruct->Quit, &QPushButton::clicked, this, std::bind(&MainWindow::showQuitDialog, this));

    // Add buttons to layouts
    mainMenuStruct->verLayout->addWidget(mainMenuStruct->PVP);
    mainMenuStruct->verLayout->addWidget(mainMenuStruct->PVC);
    mainMenuStruct->verLayout->addWidget(mainMenuStruct->Instructions);
    mainMenuStruct->horLayout->addWidget(mainMenuStruct->Options);
    mainMenuStruct->horLayout->addWidget(mainMenuStruct->Quit);

    // Set geometry for layouts
    QRect rect((int)MainMenuProps::verLayoutX, (int)MainMenuProps::verLayoutY, (int)MainMenuProps::verLayoutW, (int)MainMenuProps::verLayoutH);
    mainMenuStruct->widgetForVerLayout->setGeometry(rect);
    rect.setRect((int)MainMenuProps::horLayoutX, (int)MainMenuProps::horLayoutY, (int)MainMenuProps::horLayoutW, (int)MainMenuProps::horLayoutH);
    mainMenuStruct->widgetForHorLayout->setGeometry(rect);
}

void MainWindow::makePVPMenu()
{
    // Set buttons sizes
    setPushButtonSize(PVPMenuStruct->Play, (int)PVPMenuProps::PlayButtonW, (int)PVPMenuProps::PlayButtonH);
    setPushButtonSize(PVPMenuStruct->Return, (int)PVPMenuProps::ReturnButtonW, (int)PVPMenuProps::ReturnButtonH);

    // Set buttons positions
    PVPMenuStruct->Play->move((int)PVPMenuProps::PlayButtonX, (int)PVPMenuProps::PlayButtonY);
    PVPMenuStruct->Return->move((int)PVPMenuProps::ReturnButtonX, (int)PVPMenuProps::ReturnButtonY);

    // Set buttons fonts
    setPushButtonFont(PVPMenuStruct->Play, (int)PVPMenuProps::PlayButtonFont);
    setPushButtonFont(PVPMenuStruct->Return, (int)PVPMenuProps::ReturnButtonFont);

    // Connections
    connect(PVPMenuStruct->Play, &QPushButton::clicked, this, std::bind(&MainWindow::showGame, this, stackedWidgetPVP));
    connect(PVPMenuStruct->Return, &QPushButton::clicked, this, std::bind(&MainWindow::switchMenu, this, stackedWidgetPVP, Menus::MainMenu));

    // Set parents
    PVPMenuStruct->Play->setParent(PVPMenuWidget);
    PVPMenuStruct->Return->setParent(PVPMenuWidget);
}

// Make stackedWidgets
void MainWindow::makeStackedWidgets()
{
    // PVP StackedWidget
    makeStackedWidget(stackedWidgetPVP, mainMenuWidget, PVPMenuWidget);
}


























//void MainWindow::makeStackedWidgetPVP()
//{
//    ui->stackedWidgetPVP->addWidget(mainMenu);
//    ui->stackedWidgetPVP->addWidget(PVPMenu);
//}

//// Main menu buttons
//void MainWindow::on_PVPbutton_clicked()
//{
//    setCentralWidget(widget);


//    //ui->stackedWidgetPVP->setCurrentIndex(1);
//}

//void MainWindow::on_quitButton_clicked()
//{
//    quitDialog->setWindowIcon(QIcon(imagesPath + "logo.png"));
//    quitDialog->setModal(true);
//    quitDialog->show();
//}

//// PVP menu buttons
//void MainWindow::on_PVPMenuPlayButton_clicked()
//{
//    ui->stackedWidgetPVP->hide();
//    setBackgroundImage("board.png");

//    setCentralWidget(gameWidget);
//    gameWidget->show();
//}

//void MainWindow::on_PVPMenuReturnButton_clicked()
//{
//    ui->stackedWidgetPVP->setCurrentIndex(0);
//}
