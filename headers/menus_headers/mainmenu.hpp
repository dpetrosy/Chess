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
    QPushButton *getPushButton(MainMenuPushButtons button);

private:
    // Setup
    void setup();

    // Private util functions
    void makeMainMenu();

private:
    // Widgets
    QWidget *widgetForVerLayout;
    QWidget *widgetForHorLayout;

    // Layouts
    QVBoxLayout *verLayout;
    QHBoxLayout *horLayout;

    // PushButtons
    QPushButton *PVPButton;
    QPushButton *PVCButton;
    QPushButton *InstrButton;
    QPushButton *OptionsButton;
    QPushButton *QuitButton;
};

#endif // MAINMENU_HPP
