#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include <QStackedWidget>
#include <QPushButton>
#include <QPalette>
#include <QWidget>
#include <QPixmap>
#include <QObject>
#include <QDebug>
#include <QLabel>
#include <QImage>
#include <QRect>

#include "helpers.hpp"
#include "menus_helpers.hpp"
#include "mainmenu.hpp"
#include "pvpmenu.hpp"
#include "quitdialog.hpp"


//#include "utils.hpp"

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

    // Utils functions
    void setBackgroundImage(const QString& image);
    void showGame(QStackedWidget *stackedWidget);
    void makeConnections();
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
    QPixmap backgroundImage;
    QPalette palette;

    // Menus Widgets
    MainMenu *mainMenuWidget;
    PVPMenu *PVPMenuWidget;
    QuitDialog *quitDialog;

    // StackedWidgets
    QStackedWidget *stackedWidgetPVP;    
};

#endif // MAINWINDOW_HPP
