#include "mainwindow.hpp"
#include "ui_mainwindow.h"
#include "ui_quitdialog.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    this->setFixedSize((int)MainWindowSizes::windowSizeHorizontal, (int)MainWindowSizes::windowSizeVerticale);
    ui->setupUi(this);

    // Background image
    backgroundImage.load(":/images/images/background.jpg");
    backgroundImage = backgroundImage.scaled(this->size(), Qt::IgnoreAspectRatio);
    palette.setBrush(QPalette::Window, backgroundImage);
    this->setPalette(palette);

    mainMenu = new QWidget;
    PVPMenu = new QWidget;
    PVPChess = new QWidget;
    stackedWidgetPVP.addWidget(mainMenu);
    stackedWidgetPVP.addWidget(PVPMenu);
    stackedWidgetPVP.addWidget(PVPChess);
    ui->stackedWidgetPVP->setCurrentIndex(0);

    QImage *pawnImage = new QImage;
    QLabel *pawnLabel = new QLabel;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_quit_button_clicked()
{
    quitDialog.setWindowIcon(QIcon(":/images/images/logo.png"));
    quitDialog.setModal(true);
    quitDialog.show();
}

void MainWindow::on_player_vs_player_button_clicked()
{
    ui->stackedWidgetPVP->setCurrentIndex(1);
}

void MainWindow::on_player_vs_computer_button_clicked()
{

}

void MainWindow::on_pushButton_2_clicked()
{
    ui->stackedWidgetPVP->setCurrentIndex(0);
}

void MainWindow::on_playButton_clicked()
{
    ui->stackedWidgetPVP->hide();

    // Background image
    backgroundImage.load(":/images/images/board.jpg");
    backgroundImage = backgroundImage.scaled(this->size(), Qt::IgnoreAspectRatio);
    palette.setBrush(QPalette::Window, backgroundImage);
    this->setPalette(palette);

    pawnImage->load(":/images/images/pieces/pawn.png");
    pawnLabel->setPixmap(QPixmap::fromImage(*boardImage));
    pawnLabel->setGeometry(10,10,30,80);
    pawnLabel->show();
}
