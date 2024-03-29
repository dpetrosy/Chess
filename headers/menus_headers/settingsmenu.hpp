#ifndef SETTINGS_MENU_HPP
#define SETTINGS_MENU_HPP

#include <QObject>
#include <QWidget>
#include <QDebug>
#include <QLabel>
#include <QFile>
#include <QComboBox>
#include <QPushButton>
#include <QMainWindow>

#include "menus_helpers.hpp"
#include "predefined_menu_classes.hpp"

class SettingsMenu : public QWidget
{
    Q_OBJECT

public:
    explicit SettingsMenu(QWidget *parent = nullptr);
    virtual ~SettingsMenu();

    // Public util functions
    bool            getTheme();
    QPushButton*    getPushButton(SettingsMenuPushButtons button);
    SettingsData&   getData();
    void            makeMenuBeforeSwitch();

public slots:
    void cancelButtonClicked();
    void saveButtonClicked();

private slots:
    void bkgImageComboBoxIndexChanged(int index);
    void pieceSetsComboBoxIndexChanged(int index);
    void boardComboBoxIndexChanged(int index);
    void languageComboBoxIndexChanged(int index);
    void swapMenuTheme();
    void swapSound();

private:
    // Init
    void init();

    // Private util functions
    void    makeSettingsMenu();
    QString getBkgStr(int index);
    QString getPieceSetStr(int index);
    QString getBoardStr(int index);
    QString getLanguageStr(int index);
    void    hideAndShowMenu();
    void    changeMenuTheme();

private:
    SettingsData  _settingsData;
    SettingsData  _tempData;
    QLabel*       _bkgLabel;
    QLabel*       _boardLabel;
    QLabel*       _piecesLabel;

    // Background image
    QLabel*       _bkgImageTextLabel;
    QComboBox*    _bkgImageComboBox;

    // Piece sets
    QLabel*       _pieceSetsTextLabel;
    QComboBox*    _pieceSetsComboBox;

    // Board
    QLabel*       _boardTextLabel;
    QComboBox*    _boardComboBox;

    // Language
    QLabel*       _languageTextLabel;
    QComboBox*    _languageComboBox;

    // Sound
    QLabel*       _soundTextLabel;
    ToggleSwitch* _soundToggleSwitch;

    // Theme
    QLabel*       _themeTextLabel;
    ToggleSwitch* _themeToggleSwitch;

    // Buttons background label
    QLabel*       _buttonsBkgLabel;

    // Confirm Buttons
    QPushButton*  _cancelPushButton;
    QPushButton*  _savePushButton;

    // Menu hide and show button
    bool          _isMenuVisible;
    QPushButton*  _hideAndShowButton;
};

#endif // SETTINGS_MENU_HPP
