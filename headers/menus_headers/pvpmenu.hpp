#ifndef PVPMENU_HPP
#define PVPMENU_HPP

#include <QObject>
#include <QWidget>
#include <QDebug>
#include <QPushButton>

#include "menus_helpers.hpp"

class PVPMenu : public QWidget
{
    Q_OBJECT

public:
    explicit PVPMenu(QWidget *parent = nullptr);
    virtual ~PVPMenu();

    // Public util functions
    QPushButton *getPushButton(PVPMenuPushButtons button);

private:
    // Setup
    void setup();

    // Private til functions
    void makePVPMenu();

private:
    // PushButtons
    QPushButton *PlayButton;
    QPushButton *ReturnButton;
};

#endif // PVPMENU_HPP
