#ifndef MENUS_HPP
#define MENUS_HPP

#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>

struct MainMenu
{
    // Widgets
    QWidget *widgetForVerLayout;
    QWidget *widgetForHorLayout;

    // Layouts
    QVBoxLayout *verLayout;
    QHBoxLayout *horLayout;

    // PushButtons
    QPushButton *PVP;
    QPushButton *PVC;
    QPushButton *Instructions;
    QPushButton *Options;
    QPushButton *Quit;
};

#endif // MENUS_HPP
