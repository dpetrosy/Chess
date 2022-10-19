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


//#include "quitdialog.hpp"
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

private:
    // Setups
    void setup();
    void setupMainMenuStruct();

    // Utils functions
    void setBackgroundImage(const QString& image);

    // Make menus
    void makeMenus();
    void makeMainMenu();

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

    // Menus Widgets
    QWidget *mainMenuWidget;

    // StackedWidgets
    QStackedWidget *stackedWidgetPVP;
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

