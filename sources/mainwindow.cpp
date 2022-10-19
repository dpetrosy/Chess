#include "mainwindow.hpp"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    // set MainWindow size
    this->setFixedSize((int)MainWindowSizes::windowSizeHorizontal, (int)MainWindowSizes::windowSizeVerticale);
    ui->setupUi(this);

    setup();
    setBackgroundImage("background.jpg");

    makeStackedWidgetPVP();
    ui->stackedWidgetPVP->setCurrentIndex(0);



    //ui->stackedWidgetPVP->hide();
    wid = new QWidget;
    QPushButton *button = new QPushButton(wid);
    button->setGeometry(15, 15, 15, 15);
    widget = new QStackedWidget();
    widget->addWidget(wid);
    //setCentralWidget(widget);
}

MainWindow::~MainWindow() {}

void MainWindow::setup()
{
    // images
    imagesPath = ":/images/images/";
    piecesPath = imagesPath + "pieces/";
    logosPath = imagesPath + "logos/";
    backgroundsPath = imagesPath + "backgrounds/";

    // Main menu attributes
    mainMenu = new QWidget();
    quitDialog = new QuitDialog();

    // PVP menu attributes
    stackedWidgetPVP = new QStackedWidget();
    PVPMenu = new QWidget();

    // Chess game attributes
    gameWidget = GameWidget::GetInstance(this);
}

void MainWindow::setBackgroundImage(const QString& image)
{
    backgroundImage.load(backgroundsPath + image);
    backgroundImage = backgroundImage.scaled(this->size(), Qt::IgnoreAspectRatio);
    palette.setBrush(QPalette::Window, backgroundImage);
    this->setPalette(palette);
}

void MainWindow::makeStackedWidgetPVP()
{
    ui->stackedWidgetPVP->addWidget(mainMenu);
    ui->stackedWidgetPVP->addWidget(PVPMenu);
}

// Main menu buttons
void MainWindow::on_PVPbutton_clicked()
{
    setCentralWidget(widget);


    //ui->stackedWidgetPVP->setCurrentIndex(1);
}

void MainWindow::on_quitButton_clicked()
{
    quitDialog->setWindowIcon(QIcon(imagesPath + "logo.png"));
    quitDialog->setModal(true);
    quitDialog->show();
}

// PVP menu buttons
void MainWindow::on_PVPMenuPlayButton_clicked()
{
    ui->stackedWidgetPVP->hide();
    setBackgroundImage("board.png");

    setCentralWidget(gameWidget);
    gameWidget->show();
}

void MainWindow::on_PVPMenuReturnButton_clicked()
{
    ui->stackedWidgetPVP->setCurrentIndex(0);
}
