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

    // Menus Widgets
    mainMenuWidget = new QWidget();

    // StackedWidgets
    stackedWidgetPVP = new QStackedWidget();

    // Setup Menus Structs
    setupMainMenuStruct();





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

// Utils functions
void MainWindow::setBackgroundImage(const QString& image)
{
    backgroundImage.load(backgroundsPath + image);
    backgroundImage = backgroundImage.scaled(this->size(), Qt::IgnoreAspectRatio);
    palette.setBrush(QPalette::Window, backgroundImage);
    this->setPalette(palette);
}

// Make menus
void MainWindow::makeMenus()
{
    makeMainMenu();
}

void MainWindow::makeMainMenu()
{
    int buttonsWidth = 0;
    int buttonsHeight = 40;
    int buttonsFont = 15;

    // Set buttons sizes
    setPushButtonSize(mainMenuStruct->PVP, buttonsWidth, buttonsHeight);
    setPushButtonSize(mainMenuStruct->PVC, buttonsWidth, buttonsHeight);
    setPushButtonSize(mainMenuStruct->Instructions, buttonsWidth, buttonsHeight);

    // Set buttons fonts
    setPushButtonFont(mainMenuStruct->PVP, buttonsFont);
    setPushButtonFont(mainMenuStruct->PVC, buttonsFont);
    setPushButtonFont(mainMenuStruct->Instructions, buttonsFont);

    // Add buttons to layouts
    mainMenuStruct->verLayout->addWidget(mainMenuStruct->PVP);
    mainMenuStruct->verLayout->addWidget(mainMenuStruct->PVC);
    mainMenuStruct->verLayout->addWidget(mainMenuStruct->Instructions);

    // Set geometry for layouts
    QRect rect((int)MainMenuProps::verLayoutX, (int)MainMenuProps::verLayoutY, (int)MainMenuProps::verLayoutW, (int)MainMenuProps::verLayoutH);
    mainMenuStruct->widgetForVerLayout->setGeometry(rect);
}

// Make stackedWidgets
void MainWindow::makeStackedWidgets()
{
    // PVP StackedWidget
    makeStackedWidget(stackedWidgetPVP, mainMenuWidget);
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
