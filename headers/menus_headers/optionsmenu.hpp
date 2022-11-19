#ifndef OPTIONSMENU_HPP
#define OPTIONSMENU_HPP

#include <QObject>
#include <QWidget>
#include <QDebug>
#include <QLabel>
#include <QFile>
#include <QComboBox>

#include "menus_helpers.hpp"

class OptionsMenu : public QWidget
{
    Q_OBJECT

public:
    explicit OptionsMenu(QWidget *parent = nullptr);
    virtual ~OptionsMenu();

    // Public util functions
    bool isDarkMode();

private:
    // Init
    void init();

    // Private util functions
    void makeOptionsMenu();

private:
    OptionsData   _optionsData;
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
};

#endif // OPTIONSMENU_HPP
