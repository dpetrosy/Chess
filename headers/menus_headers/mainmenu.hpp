#ifndef MAINMENU_HPP
#define MAINMENU_HPP

#include <QObject>
#include <QWidget>
#include <QDebug>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>

#include "menus_helpers.hpp"

class MainMenu : public QWidget
{
    Q_OBJECT

public:
    explicit MainMenu(QWidget *parent = nullptr);
    virtual ~MainMenu();

    // Public util functions
    QPushButton* getPushButton(MainMenuPushButtons button);

private:
    // Init
    void init();

    // Private util functions
    void makeMainMenu();

private:
    // Widgets
    QWidget* _widgetForVerLayout;
    QWidget* _widgetForHorLayout;

    // Layouts
    QVBoxLayout* _verLayout;
    QHBoxLayout* _horLayout;

    // PushButtons
    QPushButton* _PVPButton;
    QPushButton* _PVCButton;
    QPushButton* _InstrButton;
    QPushButton* _OptionsButton;
    QPushButton* _QuitButton;
};

#endif // MAINMENU_HPP
