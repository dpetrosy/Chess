#ifndef MENUS_HPP
#define MENUS_HPP

#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>

enum class Menus : int
{
    QuitMenu = -1,
    MainMenu = 0,
    PVPMenu = 1,
};

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

struct PVPMenu
{
    // PushButtons
    QPushButton *Play;
    QPushButton *Return;
};

#endif // MENUS_HPP
