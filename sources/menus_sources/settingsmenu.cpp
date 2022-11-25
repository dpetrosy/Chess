#include "settingsmenu.hpp"
#include "mainwindow.hpp"
#include "toggleswitch.hpp"
#include "helpers.hpp"
#include "utils.hpp"

SettingsMenu::SettingsMenu(QWidget *parent) :
    QWidget(parent)
{
    // Init class members
    init();

    // Make SettingsMenu
    makeSettingsMenu();
}

SettingsMenu::~SettingsMenu()
{
    delete _bkgLabel;
    delete _boardLabel;
    delete _piecesLabel;

    // Background image
    delete _bkgImageTextLabel;
    delete _bkgImageComboBox;

    // Piece sets
    delete _pieceSetsTextLabel;
    delete _pieceSetsComboBox;

    // Board
    delete _boardTextLabel;
    delete _boardComboBox;

    // Language
    delete _languageTextLabel;
    delete _languageComboBox;

    // Sound
    delete _soundTextLabel;
    delete _soundToggleSwitch;

    // Theme
    delete _themeTextLabel;
    delete _themeToggleSwitch;

    // Buttons background label
    delete _buttonsBkgLabel;

    // Confirm Buttons
    delete _cancelPushButton;
    delete _savePushButton;

    // Menu hide and show button
    delete _hideAndShowButton;
}

// Init
void SettingsMenu::init()
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

    // Theme
    _themeTextLabel = new QLabel(this);
    _themeToggleSwitch = new ToggleSwitch(this);

    // Buttons background label
    _buttonsBkgLabel = new QLabel(this);

    // Confirm Buttons
    _cancelPushButton = new QPushButton(this);
    _savePushButton = new QPushButton(this);

    // Menu hide and show button
    _isMenuVisible = true;
    _hideAndShowButton = new QPushButton(this);
}

// Public slots
void SettingsMenu::cancelButtonClicked()
{
    _tempData = _settingsData;


    /* ******************************************  CRASH  **************************************** */
    auto mainWindow = MainWindow::GetInstance();
    mainWindow->switchMenu(mainWindow->getStackedWidget(MainMenuStackedWidgets::SettingsStackedWidget), (Menus)1);
}

void SettingsMenu::saveButtonClicked()
{
    _settingsData = _tempData;
    // Write new data in gameWidget data

    /* ******************************************  CRASH  **************************************** */
    auto mainWindow = MainWindow::GetInstance();
    mainWindow->switchMenu(mainWindow->getStackedWidget(MainMenuStackedWidgets::PVPStackedWidget), Menus::MainMenu);
}

// Public util functions
bool SettingsMenu::getTheme()
{
    return _settingsData.isDarkTheme;
}

QPushButton* SettingsMenu::getPushButton(SettingsMenuPushButtons button)
{
    switch (button)
    {
        case SettingsMenuPushButtons::CancelButton: return _cancelPushButton;
        case SettingsMenuPushButtons::SaveButton: return _savePushButton;
        default: return _cancelPushButton;
    }
}

// Private util functions
void SettingsMenu::makeSettingsMenu()
{
    // Background label
    ::setStyleSheetByTheme(StylesPaths::lightThemeBkgLabelStyle, StylesPaths::darkThemeBkgLabelStyle, _bkgLabel, _settingsData.isDarkTheme);
    _bkgLabel->setGeometry((int)SettingsMenuProps::BkgLabelX, (int)SettingsMenuProps::BkgLabelY, (int)SettingsMenuProps::BkgLabelW, (int)SettingsMenuProps::BkgLabelH);

    // Board label
    _boardLabel->setPixmap(QPixmap(ImagesPaths::settingsBoardsPath + "board" + _settingsData.boardStr + ".png"));
    _boardLabel->move((int)SettingsMenuProps::BoardLabelX, (int)SettingsMenuProps::BoardLabelY);

    // Pieces label
    _piecesLabel->setPixmap(QPixmap(ImagesPaths::settingsPiecesSetsPath + "set" + _settingsData.piecesSetStr + ".png"));
    _piecesLabel->move((int)SettingsMenuProps::BoardLabelX, (int)SettingsMenuProps::BoardLabelY);

    // Text for background image
    _bkgImageTextLabel->setGeometry((int)SettingsMenuProps::BkgImageTextLabelX, (int)SettingsMenuProps::BkgImageTextLabelY, (int)SettingsMenuProps::BkgImageTextLabelW, (int)SettingsMenuProps::BkgImageTextLabelH);
    _bkgImageTextLabel->setText("Background Image");
    ::setStyleSheetByTheme(StylesPaths::lightThemeTextStyle, StylesPaths::darkThemeTextStyle, _bkgImageTextLabel, _settingsData.isDarkTheme);

    // Background image combobox
    _bkgImageComboBox->setGeometry((int)SettingsMenuProps::BkgImageComboBoxX, (int)SettingsMenuProps::BkgImageComboBoxY, (int)SettingsMenuProps::BkgImageComboBoxW, (int)SettingsMenuProps::BkgImageComboBoxH);
    ::setStyleSheetByTheme(StylesPaths::lightComboBoxStyle, StylesPaths::darkComboBoxStyle, _bkgImageComboBox, _settingsData.isDarkTheme);
    _bkgImageComboBox->addItem(removeUnderscoreInString(BackgroundImages::AngelView));
    _bkgImageComboBox->addItem(removeUnderscoreInString(BackgroundImages::Blacked));
    _bkgImageComboBox->addItem(removeUnderscoreInString(BackgroundImages::BravePawn));
    _bkgImageComboBox->addItem(removeUnderscoreInString(BackgroundImages::Checkmate));
    _bkgImageComboBox->addItem(removeUnderscoreInString(BackgroundImages::Dark_Chess));
    _bkgImageComboBox->addItem(removeUnderscoreInString(BackgroundImages::Emperors));
    _bkgImageComboBox->addItem(removeUnderscoreInString(BackgroundImages::FaceToFace));
    _bkgImageComboBox->addItem(removeUnderscoreInString(BackgroundImages::IAmTheKing));
    _bkgImageComboBox->addItem(removeUnderscoreInString(BackgroundImages::Lichess));
    _bkgImageComboBox->addItem(removeUnderscoreInString(BackgroundImages::Shadow));
    _bkgImageComboBox->addItem(removeUnderscoreInString(BackgroundImages::StrongKnight));
    _bkgImageComboBox->addItem(removeUnderscoreInString(BackgroundImages::TheBishop));
    _bkgImageComboBox->addItem(removeUnderscoreInString(BackgroundImages::TheKing));
    _bkgImageComboBox->addItem(removeUnderscoreInString(BackgroundImages::TheKnight));
    _bkgImageComboBox->addItem(removeUnderscoreInString(BackgroundImages::TheQueen));
    _bkgImageComboBox->addItem(removeUnderscoreInString(BackgroundImages::TheRook));
    _bkgImageComboBox->addItem(removeUnderscoreInString(BackgroundImages::TopView));
    _bkgImageComboBox->setCurrentIndex(15);
    connect(_bkgImageComboBox, &QComboBox::currentIndexChanged, this, &SettingsMenu::bkgImageComboBoxIndexChanged);


    // Text for piece sets
    _pieceSetsTextLabel->setGeometry((int)SettingsMenuProps::PieceSetTextLabelX, (int)SettingsMenuProps::PieceSetTextLabelY, (int)SettingsMenuProps::PieceSetTextLabelW, (int)SettingsMenuProps::PieceSetTextLabelH);
    _pieceSetsTextLabel->setText("Piece Set");
    ::setStyleSheetByTheme(StylesPaths::lightThemeTextStyle, StylesPaths::darkThemeTextStyle, _pieceSetsTextLabel, _settingsData.isDarkTheme);

    // Piece sets combobox
    _pieceSetsComboBox->setGeometry((int)SettingsMenuProps::PieceSetComboBoxX, (int)SettingsMenuProps::PieceSetComboBoxY, (int)SettingsMenuProps::PieceSetComboBoxW, (int)SettingsMenuProps::PieceSetComboBoxH);
    ::setStyleSheetByTheme(StylesPaths::lightComboBoxStyle, StylesPaths::darkComboBoxStyle, _pieceSetsComboBox, _settingsData.isDarkTheme);

    // Text for board
    _boardTextLabel->setGeometry((int)SettingsMenuProps::BoardTextLabelX, (int)SettingsMenuProps::BoardTextLabelY, (int)SettingsMenuProps::BoardTextLabelW, (int)SettingsMenuProps::BoardTextLabelH);
    _boardTextLabel->setText("Board");
    ::setStyleSheetByTheme(StylesPaths::lightThemeTextStyle, StylesPaths::darkThemeTextStyle, _boardTextLabel, _settingsData.isDarkTheme);

    // Board combobox
    _boardComboBox->setGeometry((int)SettingsMenuProps::BoardComboBoxX, (int)SettingsMenuProps::BoardComboBoxY, (int)SettingsMenuProps::BoardComboBoxW, (int)SettingsMenuProps::BoardComboBoxH);
    ::setStyleSheetByTheme(StylesPaths::lightComboBoxStyle, StylesPaths::darkComboBoxStyle, _boardComboBox, _settingsData.isDarkTheme);

    // Text for language
    _languageTextLabel->setGeometry((int)SettingsMenuProps::LanguageTextLabelX, (int)SettingsMenuProps::LanguageTextLabelY, (int)SettingsMenuProps::LanguageTextLabelW, (int)SettingsMenuProps::LanguageTextLabelH);
    _languageTextLabel->setText("Language");
    ::setStyleSheetByTheme(StylesPaths::lightThemeTextStyle, StylesPaths::darkThemeTextStyle, _languageTextLabel, _settingsData.isDarkTheme);

    // Language combobox
    _languageComboBox->setGeometry((int)SettingsMenuProps::LanguageComboBoxX, (int)SettingsMenuProps::LanguageComboBoxY, (int)SettingsMenuProps::LanguageComboBoxW, (int)SettingsMenuProps::LanguageComboBoxH);
    ::setStyleSheetByTheme(StylesPaths::lightComboBoxStyle, StylesPaths::darkComboBoxStyle, _languageComboBox, _settingsData.isDarkTheme);
    _languageComboBox->addItem(Languages::Armenian);
    _languageComboBox->addItem(Languages::Russian);
    _languageComboBox->addItem(Languages::English);
    _languageComboBox->setCurrentIndex(2);
    connect(_languageComboBox, &QComboBox::currentIndexChanged, this, &SettingsMenu::languageComboBoxIndexChanged);

    // Text for sound
    _soundTextLabel->setGeometry((int)SettingsMenuProps::SoundTextLabelX, (int)SettingsMenuProps::SoundTextLabelY, (int)SettingsMenuProps::SoundTextLabelW, (int)SettingsMenuProps::SoundTextLabelH);
    _soundTextLabel->setText("Play Sounds");
    ::setStyleSheetByTheme(StylesPaths::lightThemeTextStyle, StylesPaths::darkThemeTextStyle, _soundTextLabel, _settingsData.isDarkTheme);

    // Sound toggle switch
    _soundToggleSwitch->move((int)SettingsMenuProps::SoundToggleSwitchX, (int)SettingsMenuProps::SoundToggleSwitchY);
    _soundToggleSwitch->setChecked(false);

    // Text for theme
    _themeTextLabel->setGeometry((int)SettingsMenuProps::ThemeTextLabelX, (int)SettingsMenuProps::ThemeTextLabelY, (int)SettingsMenuProps::ThemeTextLabelW, (int)SettingsMenuProps::ThemeTextLabelH);
    _themeTextLabel->setText("Black theme");
    ::setStyleSheetByTheme(StylesPaths::lightThemeTextStyle, StylesPaths::darkThemeTextStyle, _themeTextLabel, _settingsData.isDarkTheme);

    // Theme toggle switch
    _themeToggleSwitch->move((int)SettingsMenuProps::ThemeToggleSwitchX, (int)SettingsMenuProps::ThemeToggleSwitchY);
    _themeToggleSwitch->setChecked(_settingsData.isDarkTheme);

    // Buttons background label
    ::setStyleSheetByTheme(StylesPaths::lightThemeButtonsLabelStyle, StylesPaths::darkThemeButtonsLabelStyle, _buttonsBkgLabel, _settingsData.isDarkTheme);
    _buttonsBkgLabel->setGeometry((int)SettingsMenuProps::ButtonsBkgLabelX, (int)SettingsMenuProps::ButtonsBkgLabelY, (int)SettingsMenuProps::ButtonsBkgLabelW, (int)SettingsMenuProps::ButtonsBkgLabelH);

    // Cancel push button
    ::setStyleSheetByTheme(StylesPaths::settingsMenuLightCancelButtonStyle, StylesPaths::settingsMenuDarkCancelButtonStyle, _cancelPushButton, _settingsData.isDarkTheme);
    _cancelPushButton->setText("Cancel");
    _cancelPushButton->setGeometry((int)SettingsMenuProps::CancelButtonX, (int)SettingsMenuProps::CancelButtonY, (int)SettingsMenuProps::CancelButtonW, (int)SettingsMenuProps::CancelButtonH);

    // Save push button
    ::setStyleSheet(StylesPaths::settingsMenuSaveButtonStyle, _savePushButton);
    _savePushButton->setText("Save");
    _savePushButton->setGeometry((int)SettingsMenuProps::SaveButtonX, (int)SettingsMenuProps::SaveButtonY, (int)SettingsMenuProps::SaveButtonW, (int)SettingsMenuProps::SaveButtonH);

    // Menu hide and show button
    ::setStyleSheet(StylesPaths::hideAndShowButtonStyle, _hideAndShowButton);
    _hideAndShowButton->setText("Hide");
    _hideAndShowButton->setGeometry((int)SettingsMenuProps::HideAndShowButtonX, (int)SettingsMenuProps::HideAndShowButtonY, (int)SettingsMenuProps::HideAndShowButtonW, (int)SettingsMenuProps::HideAndShowButtonH);
    connect(_hideAndShowButton, &QPushButton::clicked, this, &SettingsMenu::hideAndShowMenu);
}

QString SettingsMenu::getBoardStr(int index)
{
    switch (index)
    {
    case 0:
        return BackgroundImages::AngelView;
    case 1:
        return BackgroundImages::Blacked;
    case 2:
        return BackgroundImages::BravePawn;
    case 3:
        return BackgroundImages::Checkmate;
    case 4:
        return BackgroundImages::Dark_Chess;
    case 5:
        return BackgroundImages::Emperors;
    case 6:
        return BackgroundImages::FaceToFace;
    case 7:
        return BackgroundImages::IAmTheKing;
    case 8:
        return BackgroundImages::Lichess;
    case 9:
        return BackgroundImages::Shadow;
    case 10:
        return BackgroundImages::StrongKnight;
    case 11:
        return BackgroundImages::TheBishop;
    case 12:
        return BackgroundImages::TheKing;
    case 13:
        return BackgroundImages::TheKnight;
    case 14:
        return BackgroundImages::TheQueen;
    case 15:
        return BackgroundImages::TheRook;
    case 16:
        return BackgroundImages::TopView;
    default:
        return BackgroundImages::TheRook;
    }
}

QString SettingsMenu::getLanguageStr(int index)
{
    switch (index)
    {
    case 0:
        return Languages::Armenian;
    case 1:
        return Languages::Russian;
    case 2:
        return Languages::English;
    default:
        return Languages::English;
    }
}

void SettingsMenu::hideAndShowMenu()
{
    if (_isMenuVisible)
    {
        _bkgLabel->hide();
        _boardLabel->hide();
        _piecesLabel->hide();

        // Background image
        _bkgImageTextLabel->hide();
        _bkgImageComboBox->hide();

        // Piece sets
        _pieceSetsTextLabel->hide();
        _pieceSetsComboBox->hide();

        // Board
        _boardTextLabel->hide();
        _boardComboBox->hide();

        // Language
        _languageTextLabel->hide();
        _languageComboBox->hide();

        // Sound
        _soundTextLabel->hide();
        _soundToggleSwitch->hide();

        // Theme
        _themeTextLabel->hide();
        _themeToggleSwitch->hide();

        // Buttons background label
        _buttonsBkgLabel->hide();

        // Confirm Buttons
        _cancelPushButton->hide();
        _savePushButton->hide();

        // Menu hide and show button
        _hideAndShowButton->setText("Show");
        _isMenuVisible = false;
    }
    else
    {
        _bkgLabel->show();
        _boardLabel->show();
        _piecesLabel->show();

        // Background image
        _bkgImageTextLabel->show();
        _bkgImageComboBox->show();

        // Piece sets
        _pieceSetsTextLabel->show();
        _pieceSetsComboBox->show();

        // Board
        _boardTextLabel->show();
        _boardComboBox->show();

        // Language
        _languageTextLabel->show();
        _languageComboBox->show();

        // Sound
        _soundTextLabel->show();
        _soundToggleSwitch->show();

        // Theme
        _themeTextLabel->show();
        _themeToggleSwitch->show();

        // Buttons background label
        _buttonsBkgLabel->show();

        // Confirm Buttons
        _cancelPushButton->show();
        _savePushButton->show();

        // Menu hide and show button
        _hideAndShowButton->setText("Hide");
        _isMenuVisible = true;
    }
}

// Private slots
void SettingsMenu::bkgImageComboBoxIndexChanged(int index)
{
    _tempData.boardStr = getBoardStr(index);
    MainWindow::GetInstance()->setBackgroundImage(_tempData.boardStr);
}

void SettingsMenu::languageComboBoxIndexChanged(int index)
{
    _tempData.languageStr = getLanguageStr(index);
    // call function to set language
}
