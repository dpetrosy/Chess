#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include <QStackedWidget>
#include <QPalette>
#include <QWidget>
#include <QPixmap>
#include <QLabel>
#include <QImage>

#include "cordsandsizes.hpp"
#include "quitdialog.hpp"
#include "boardwidget.hpp"
#include "gamewidget.hpp"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    virtual ~MainWindow();

private slots:
    void setup();
    void setBackgroundImage(const QString& image);
    void makeStackedWidgetPVP();

    // Main menu buttons
    void on_PVPbutton_clicked();
    void on_quitButton_clicked();

    // PVP menu buttons
    void on_PVPMenuPlayButton_clicked();
    void on_PVPMenuReturnButton_clicked();

private:
    Ui::MainWindow *ui;

    // images
    QString imagesPath;
    QString piecesPath;
    QString logosPath;
    QString backgroundsPath;
    QPixmap backgroundImage;
    QPalette palette;

    // Main menu attributes
    QWidget *mainMenu;
    QuitDialog *quitDialog;

    // PVP StackedWidget attributes
    QStackedWidget *stackedWidgetPVP;
    QWidget *PVPMenu;

    // Chess game attributes
    GameWidget *gameWidget;
};

#endif // MAINWINDOW_HPP
