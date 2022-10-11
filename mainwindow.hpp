#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include <QPalette>
#include <QStackedWidget>
#include <QWidget>

#include "quitdialog.hpp"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

enum class MainWindowSizes
{
    windowSizeHorizontal = 1000,
    windowSizeVerticale = 600
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_quit_button_clicked();
    void on_player_vs_player_button_clicked();
    void on_player_vs_computer_button_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    QuitDialog quitDialog;
    QStackedWidget stackedWidgetPVP;
    QWidget *mainMenu;
    QWidget *PVPMenu;
};

#endif // MAINWINDOW_HPP
