#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include <QStackedWidget>
#include <QPushButton>
#include <QPalette>
#include <QWidget>
#include <QPixmap>
#include <QLabel>
#include <QImage>
#include <QRect>

#include "menus.hpp"
#include "helpers.hpp"
#include "utils.hpp"
#include "quitdialog.hpp"


//#include "boardwidget.hpp"
//#include "gamewidget.hpp"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void switchMenu(QStackedWidget *stackedWidget, Menus toMenu);
    void showQuitDialog();

private:
    // Setups
    void setup();
    void setupMainMenuStruct();
    void setupPVPMenuStruct();

    // Utils functions
    void setBackgroundImage(const QString& image);
    void showGame(QStackedWidget *stackedWidget);

    // Make menus
    void makeMenus();
    void makeMainMenu();
    void makePVPMenu();

    // Make stackedWidgets
    void makeStackedWidgets();

    // StackedWidget maker
    template <typename T, typename... Types>
    void makeStackedWidget(QStackedWidget *stackedWidget, T widget, Types... arg2)
    {
        stackedWidget->addWidget(widget);
        return makeStackedWidget(stackedWidget, arg2...);
    }

    // Template Specialization
    void makeStackedWidget(QStackedWidget *stackedWidget)
    {
        (void) stackedWidget;
        return;
    }

private:
    Ui::MainWindow *ui;

    // images
    QString imagesPath;
    QString piecesPath;
    QString logosPath;
    QString backgroundsPath;
    QPixmap backgroundImage;
    QPalette palette;

    // Menus Structs
    MainMenu *mainMenuStruct;
    PVPMenu *PVPMenuStruct;

    // Menus Widgets
    QWidget *mainMenuWidget;
    QWidget *PVPMenuWidget;

    // StackedWidgets
    QStackedWidget *stackedWidgetPVP;

    // Quit attributes
    QuitDialog *quitDialog;
};

#endif // MAINWINDOW_HPP






//    // Main menu buttons
//    void on_PVPbutton_clicked();
//    void on_quitButton_clicked();

//    // PVP menu buttons
//    void on_PVPMenuPlayButton_clicked();
//    void on_PVPMenuReturnButton_clicked();



// Quit attributes
//QuitDialog *quitDialog;

//    // Chess game attributes
//    GameWidget *gameWidget;

