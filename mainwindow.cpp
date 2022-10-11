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
    QPixmap bkgnd(":/images/images/background.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, bkgnd);
    this->setPalette(palette);

    mainMenu = new QWidget;
    mainMenu->move(400, 400);
    PVPMenu = new QWidget;
    stackedWidgetPVP.addWidget(mainMenu);
    stackedWidgetPVP.addWidget(PVPMenu);
    ui->stackedWidgetPVP->setCurrentIndex(0);
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

