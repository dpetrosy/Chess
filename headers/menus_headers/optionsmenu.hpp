#ifndef OPTIONSMENU_HPP
#define OPTIONSMENU_HPP

#include <QObject>
#include <QWidget>
#include <QDebug>

#include "menus_helpers.hpp"

class OptionsMenu : public QWidget
{
    Q_OBJECT

public:
    explicit OptionsMenu(QWidget *parent = nullptr);
    virtual ~OptionsMenu();

    // Public util functions

private:
    // Init
    void init();

    // Private util functions
    void makeOptionsMenu();

private:
    // Widgets

    // Layouts

    // PushButtons

};

#endif // OPTIONSMENU_HPP
