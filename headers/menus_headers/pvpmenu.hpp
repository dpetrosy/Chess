#ifndef PVPMENU_HPP
#define PVPMENU_HPP

#include <QObject>
#include <QWidget>
#include <QDebug>
#include <QPushButton>

#include "menus_helpers.hpp"
#include "utils.hpp"

class PVPMenu : public QWidget
{
    Q_OBJECT

public:
    explicit PVPMenu(QWidget *parent = nullptr);
    virtual ~PVPMenu();

    // Utils functions
    QPushButton *getPushButton(PVPMenuPushButtons button);

private:
    // Setups
    void setup();

    // Utils functions
    void makePVPMenu();

private:
    // PushButtons
    QPushButton *PlayButton;
    QPushButton *ReturnButton;
};

#endif // PVPMENU_HPP
