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

#include "menus_helpers.hpp"
#include "game_helpers.hpp"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

// Singlton pattern used
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    // Singlton pattern realization
    MainWindow(MainWindow &other) = delete;
    MainWindow& operator=(const MainWindow&) = delete;
    static MainWindow *GetInstance(QWidget *parent = nullptr);
    virtual ~MainWindow();

public:
    // Public util functions
    void             setBackgroundImage(const QString& image);
    QStackedWidget*  getStackedWidget(MainMenuStackedWidgets stackedWidget);

public slots:
    void switchMenu(QStackedWidget *stackedWidget, Menus toMenu);
    void showGame(QStackedWidget *stackedWidget);
    void showQuitDialog();
    void exitFromProgram();

private:
    explicit MainWindow(QWidget *parent = nullptr);

    // Init
    void init();

    // Private util functions
    void makeStackedWidgets();
    void makeConnects();

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
        Q_UNUSED(stackedWidget)
        return;
    }

private:
    // Singleton pattern realization
    static MainWindow* _mainWindow;

    // Images
    QPixmap  _backgroundImage;
    QPalette _palette;

    // Menus Widgets
    MainMenu*    _mainMenuWidget;
    PVPMenu*     _PVPMenuWidget;
    QuitDialog*  _quitDialog;

    // StackedWidgets
    QStackedWidget* _PVPStackedWidget;

    // Chess game Widgets
    GameWidget* _gameWidget;
};

#endif // MAINWINDOW_HPP
