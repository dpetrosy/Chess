#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include <QStackedWidget>
#include <QMessageBox>
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

// Singleton pattern used
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    // Singleton pattern realization
    MainWindow(MainWindow &other) = delete;
    MainWindow& operator=(const MainWindow&) = delete;
    static MainWindow *GetInstance(QWidget *parent = nullptr);
    virtual ~MainWindow();

public:
    // Public util functions
    void             setBackgroundImage(const QString& image);
    QStackedWidget*  getStackedWidget();

public slots:
    void switchMenu(Menus toMenu);
    void showGame();
    void showQuitWindow();
    void exitFromProgram(int signal);

private:
    explicit MainWindow(QWidget *parent = nullptr);

    // Init
    void init();

    // Private util functions
    void makeMenusStackedWidget();
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
    QPixmap         _backgroundImage;
    QPalette        _palette;

    // Menus Widgets
    MainMenu*       _MainMenuWidget;
    PVPMenu*        _PVPMenuWidget;
    SettingsMenu*   _SettingsMenuWidget;

    // Menus StackedWidget
    QStackedWidget* _MenusStackedWidget;

    // Chess game Widgets
    GameWidget*     _gameWidget;
};

#endif // MAINWINDOW_HPP
