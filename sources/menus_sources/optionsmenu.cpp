#include "optionsmenu.hpp"
#include "helpers.hpp"
#include "toggleswitch.hpp""
#include "utils.hpp"

OptionsMenu::OptionsMenu(QWidget *parent) :
    QWidget(parent)
{
    // Init class members
    init();

    // Make OptionsMenu
    makeOptionsMenu();
}

OptionsMenu::~OptionsMenu()
{
    delete _bkgLabel;
    delete _boardLabel;
    delete _piecesLabel;
}

// Init
void OptionsMenu::init()
{
    _bkgLabel = new QLabel(this);
    _boardLabel = new QLabel(this);
    _piecesLabel = new QLabel(this);

    // Background image
    _bkgImageTextLabel = new QLabel(this);
    _bkgImageComboBox = new QComboBox(this);

    // Piece sets
    _pieceSetsTextLabel = new QLabel(this);
    _pieceSetsComboBox = new QComboBox(this);

    // Board
    _boardTextLabel = new QLabel(this);
    _boardComboBox = new QComboBox(this);

    // Language
    _languageTextLabel = new QLabel(this);
    _languageComboBox = new QComboBox(this);

    // Sound
    _soundTextLabel = new QLabel(this);
    _soundToggleSwitch = new ToggleSwitch(this);
}

// Public util functions
bool OptionsMenu::isDarkMode()
{
    return _optionsData.isDarkMode;
}

// Private util functions
void OptionsMenu::makeOptionsMenu()
{
    QFile file;

    if (isDarkMode())
        file.setFileName(Paths::stylesPath + "dark_mode_bkg_label.txt");
    else
        file.setFileName(Paths::stylesPath + "light_mode_bkg_label.txt");

    // Background label
    file.open(QFile::ReadOnly);
    QString styleSheet = QLatin1String(file.readAll());
    _bkgLabel->setStyleSheet(styleSheet);
    _bkgLabel->setGeometry((int)OptionsMenuProps::BkgLabelX, (int)OptionsMenuProps::BkgLabelY, (int)OptionsMenuProps::BkgLabelW, (int)OptionsMenuProps::BkgLabelH);

    // Board label
    _boardLabel->setPixmap(QPixmap(ImagesPaths::optionsBoardsPath + "board" + _optionsData.boardStr + ".png"));
    _boardLabel->move((int)OptionsMenuProps::BoardLabelX, (int)OptionsMenuProps::BoardLabelY);

    // Pieces label
    _piecesLabel->setPixmap(QPixmap(ImagesPaths::optionsPiecesSetsPath + "set" + _optionsData.piecesSetsStr + ".png"));
    _piecesLabel->move((int)OptionsMenuProps::BoardLabelX, (int)OptionsMenuProps::BoardLabelY);

    // Text for background image
    _bkgImageTextLabel->setGeometry((int)OptionsMenuProps::BkgImageTextLabelX, (int)OptionsMenuProps::BkgImageTextLabelY, (int)OptionsMenuProps::BkgImageTextLabelW, (int)OptionsMenuProps::BkgImageTextLabelH);
    _bkgImageTextLabel->setText("Background Image");
    setLabelTextFont(_bkgImageTextLabel, 15);

    // Background image combobox
    _bkgImageComboBox->setGeometry((int)OptionsMenuProps::BkgImageComboBoxX, (int)OptionsMenuProps::BkgImageComboBoxY, (int)OptionsMenuProps::BkgImageComboBoxW, (int)OptionsMenuProps::BkgImageComboBoxH);

    // Text for piece sets
    _pieceSetsTextLabel->setGeometry((int)OptionsMenuProps::PieceSetTextLabelX, (int)OptionsMenuProps::PieceSetTextLabelY, (int)OptionsMenuProps::PieceSetTextLabelW, (int)OptionsMenuProps::PieceSetTextLabelH);
    _pieceSetsTextLabel->setText("Piece set");
    setLabelTextFont(_pieceSetsTextLabel, 15);

    // Piece sets combobox
    _pieceSetsComboBox->setGeometry((int)OptionsMenuProps::PieceSetComboBoxX, (int)OptionsMenuProps::PieceSetComboBoxY, (int)OptionsMenuProps::PieceSetComboBoxW, (int)OptionsMenuProps::PieceSetComboBoxH);

    // Text for board
    _boardTextLabel->setGeometry((int)OptionsMenuProps::BoardTextLabelX, (int)OptionsMenuProps::BoardTextLabelY, (int)OptionsMenuProps::BoardTextLabelW, (int)OptionsMenuProps::BoardTextLabelH);
    _boardTextLabel->setText("Board");
    setLabelTextFont(_boardTextLabel, 15);

    // Board combobox
    _boardComboBox->setGeometry((int)OptionsMenuProps::BoardComboBoxX, (int)OptionsMenuProps::BoardComboBoxY, (int)OptionsMenuProps::BoardComboBoxW, (int)OptionsMenuProps::BoardComboBoxH);

    // Text for language
    _languageTextLabel->setGeometry((int)OptionsMenuProps::LanguageTextLabelX, (int)OptionsMenuProps::LanguageTextLabelY, (int)OptionsMenuProps::LanguageTextLabelW, (int)OptionsMenuProps::LanguageTextLabelH);
    _languageTextLabel->setText("Language");
    setLabelTextFont(_languageTextLabel, 15);

    // Board combobox
    _languageComboBox->setGeometry((int)OptionsMenuProps::LanguageComboBoxX, (int)OptionsMenuProps::LanguageComboBoxY, (int)OptionsMenuProps::LanguageComboBoxW, (int)OptionsMenuProps::LanguageComboBoxH);

    // Text for sound
    _soundTextLabel->setGeometry((int)OptionsMenuProps::SoundTextLabelX, (int)OptionsMenuProps::SoundTextLabelY, (int)OptionsMenuProps::SoundTextLabelW, (int)OptionsMenuProps::SoundTextLabelH);
    _soundTextLabel->setText("Play Sounds");
    setLabelTextFont(_soundTextLabel, 15);





    // Sound toggle switch
    _soundToggleSwitch->setDisabled(false);
    _soundToggleSwitch->move((int)OptionsMenuProps::SoundToggleSwitchX, (int)OptionsMenuProps::SoundToggleSwitchY);
}
