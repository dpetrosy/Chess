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
    QPushButton* getPushButton(PVPMenuPushButtons button);

private:
    // Init
    void init();

    // Private til functions
    void makePVPMenu();

private:
//    GameData  _settingsData;
//    SettingsData  _tempData;
//    QLabel*       _bkgLabel;
//    QLabel*       _boardLabel;
//    QLabel*       _piecesLabel;









    // PushButtons
    QPushButton* _PlayButton;
    QPushButton* _ReturnButton;
};

#endif // PVPMENU_HPP
