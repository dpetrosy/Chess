#include "settingsmenu.hpp"
#include "mainwindow.hpp"
#include "toggleswitch.hpp"
#include "gamewidget.hpp"
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
    globalIsDarkTheme = _settingsData.isDarkTheme;
    globalPieceSetPath = ImagesPaths::piecesPath + _settingsData.piecesSetStr + "/";

    auto mainWindow = MainWindow::GetInstance();
    mainWindow->setBackgroundImage(_settingsData.bkgImageStr);
    mainWindow->switchMenu(Menus::MainMenu);
}

void SettingsMenu::saveButtonClicked()
{
    _settingsData = _tempData;
    globalIsDarkTheme = _settingsData.isDarkTheme;
    globalPieceSetPath = ImagesPaths::piecesPath + _settingsData.piecesSetStr + "/";

    auto mainWindow = MainWindow::GetInstance();
    auto gameWidget = GameWidget::GetInstance();

    mainWindow->setBackgroundImage(_settingsData.bkgImageStr);
    gameWidget->setPieceSet(_settingsData.piecesSetStr);
    gameWidget->setBoard(_settingsData.boardStr);

    mainWindow->switchMenu(Menus::MainMenu);
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

void SettingsMenu::makeMenuBeforeSwitch()
{
    // Background image
    _bkgImageComboBox->setCurrentIndex(_settingsData.bkgImageNumber);

    // Piece set
    _piecesLabel->setPixmap(QPixmap(ImagesPaths::settingsPiecesSetsPath + _settingsData.piecesSetStr + PieceSets::Extencion));
    _pieceSetsComboBox->setCurrentIndex(_settingsData.pieceSetNumber);

    // Board
    _boardLabel->setPixmap(QPixmap(ImagesPaths::settingsBoardsPath + _settingsData.boardStr + Boards::Extencion));
    _boardComboBox->setCurrentIndex(_settingsData.boardNumber);

    // Language
    _languageComboBox->setCurrentIndex(_settingsData.languageNumber);

    // Sound
    _soundToggleSwitch->setChecked(_settingsData.isSoundAvailable);

    // Theme
    _themeToggleSwitch->setChecked(globalIsDarkTheme);
    changeMenuTheme();
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
    _piecesLabel->setPixmap(QPixmap(ImagesPaths::settingsPiecesSetsPath + PieceSets::Cburnett + ".png"));
    _piecesLabel->move((int)SettingsMenuProps::BoardLabelX, (int)SettingsMenuProps::BoardLabelY);

    // Text for background image
    _bkgImageTextLabel->setGeometry((int)SettingsMenuProps::BkgImageTextLabelX, (int)SettingsMenuProps::BkgImageTextLabelY, (int)SettingsMenuProps::BkgImageTextLabelW, (int)SettingsMenuProps::BkgImageTextLabelH);
    _bkgImageTextLabel->setText("Background Image");
    ::setStyleSheetByTheme(StylesPaths::lightTextStyle, StylesPaths::darkBoldTextStyle, _bkgImageTextLabel, _settingsData.isDarkTheme);

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
    _bkgImageComboBox->addItem(removeUnderscoreInString(BackgroundImages::Landscape));
    _bkgImageComboBox->addItem(removeUnderscoreInString(BackgroundImages::Legends));
    _bkgImageComboBox->addItem(removeUnderscoreInString(BackgroundImages::Shadow));
    _bkgImageComboBox->addItem(removeUnderscoreInString(BackgroundImages::StrongKnight));
    _bkgImageComboBox->addItem(removeUnderscoreInString(BackgroundImages::TheBishop));
    _bkgImageComboBox->addItem(removeUnderscoreInString(BackgroundImages::TheKing));
    _bkgImageComboBox->addItem(removeUnderscoreInString(BackgroundImages::TheKnight));
    _bkgImageComboBox->addItem(removeUnderscoreInString(BackgroundImages::TheQueen));
    _bkgImageComboBox->addItem(removeUnderscoreInString(BackgroundImages::TheRook));
    _bkgImageComboBox->addItem(removeUnderscoreInString(BackgroundImages::TopView));
    _bkgImageComboBox->setCurrentIndex((int)BackgroundImagesNumbers::TheRook);
    connect(_bkgImageComboBox, &QComboBox::currentIndexChanged, this, &SettingsMenu::bkgImageComboBoxIndexChanged);

    // Text for piece sets
    _pieceSetsTextLabel->setGeometry((int)SettingsMenuProps::PieceSetTextLabelX, (int)SettingsMenuProps::PieceSetTextLabelY, (int)SettingsMenuProps::PieceSetTextLabelW, (int)SettingsMenuProps::PieceSetTextLabelH);
    _pieceSetsTextLabel->setText("Piece Set");
    ::setStyleSheetByTheme(StylesPaths::lightTextStyle, StylesPaths::darkBoldTextStyle, _pieceSetsTextLabel, _settingsData.isDarkTheme);

    // Piece sets combobox
    _pieceSetsComboBox->setGeometry((int)SettingsMenuProps::PieceSetComboBoxX, (int)SettingsMenuProps::PieceSetComboBoxY, (int)SettingsMenuProps::PieceSetComboBoxW, (int)SettingsMenuProps::PieceSetComboBoxH);
    ::setStyleSheetByTheme(StylesPaths::lightComboBoxStyle, StylesPaths::darkComboBoxStyle, _pieceSetsComboBox, _settingsData.isDarkTheme);
    _pieceSetsComboBox->addItem(removeUnderscoreInString(PieceSets::Alpha));
    _pieceSetsComboBox->addItem(removeUnderscoreInString(PieceSets::California));
    _pieceSetsComboBox->addItem(removeUnderscoreInString(PieceSets::Cardinal));
    _pieceSetsComboBox->addItem(removeUnderscoreInString(PieceSets::Cases));
    _pieceSetsComboBox->addItem(removeUnderscoreInString(PieceSets::Cburnett));
    _pieceSetsComboBox->addItem(removeUnderscoreInString(PieceSets::Chess7));
    _pieceSetsComboBox->addItem(removeUnderscoreInString(PieceSets::Condal));
    _pieceSetsComboBox->addItem(removeUnderscoreInString(PieceSets::Fresca));
    _pieceSetsComboBox->addItem(removeUnderscoreInString(PieceSets::GameRoom));
    _pieceSetsComboBox->addItem(removeUnderscoreInString(PieceSets::Glass));
    _pieceSetsComboBox->addItem(removeUnderscoreInString(PieceSets::ICPieces));
    _pieceSetsComboBox->addItem(removeUnderscoreInString(PieceSets::Lolz));
    _pieceSetsComboBox->addItem(removeUnderscoreInString(PieceSets::Maestro));
    _pieceSetsComboBox->addItem(removeUnderscoreInString(PieceSets::Merida));
    _pieceSetsComboBox->addItem(removeUnderscoreInString(PieceSets::Neo));
    _pieceSetsComboBox->addItem(removeUnderscoreInString(PieceSets::Ocean));
    _pieceSetsComboBox->setCurrentIndex((int)PieceSetsNumber::Cburnett);
    connect(_pieceSetsComboBox, &QComboBox::currentIndexChanged, this, &SettingsMenu::pieceSetsComboBoxIndexChanged);

    // Text for board
    _boardTextLabel->setGeometry((int)SettingsMenuProps::BoardTextLabelX, (int)SettingsMenuProps::BoardTextLabelY, (int)SettingsMenuProps::BoardTextLabelW, (int)SettingsMenuProps::BoardTextLabelH);
    _boardTextLabel->setText("Board");
    ::setStyleSheetByTheme(StylesPaths::lightTextStyle, StylesPaths::darkBoldTextStyle, _boardTextLabel, _settingsData.isDarkTheme);

    // Board combobox
    _boardComboBox->setGeometry((int)SettingsMenuProps::BoardComboBoxX, (int)SettingsMenuProps::BoardComboBoxY, (int)SettingsMenuProps::BoardComboBoxW, (int)SettingsMenuProps::BoardComboBoxH);
    ::setStyleSheetByTheme(StylesPaths::lightComboBoxStyle, StylesPaths::darkComboBoxStyle, _boardComboBox, _settingsData.isDarkTheme);
    _boardComboBox->addItem(removeUnderscoreInString(Boards::Bit8));
    _boardComboBox->addItem(removeUnderscoreInString(Boards::Bases));
    _boardComboBox->addItem(removeUnderscoreInString(Boards::Blue));
    _boardComboBox->addItem(removeUnderscoreInString(Boards::Brown));
    _boardComboBox->addItem(removeUnderscoreInString(Boards::Bubblegum));
    _boardComboBox->addItem(removeUnderscoreInString(Boards::BurledWood));
    _boardComboBox->addItem(removeUnderscoreInString(Boards::DarkWood));
    _boardComboBox->addItem(removeUnderscoreInString(Boards::Dash));
    _boardComboBox->addItem(removeUnderscoreInString(Boards::Glass));
    _boardComboBox->addItem(removeUnderscoreInString(Boards::Graffiti));
    _boardComboBox->addItem(removeUnderscoreInString(Boards::Green));
    _boardComboBox->addItem(removeUnderscoreInString(Boards::IceSea));
    _boardComboBox->addItem(removeUnderscoreInString(Boards::Light));
    _boardComboBox->addItem(removeUnderscoreInString(Boards::Lolz));
    _boardComboBox->addItem(removeUnderscoreInString(Boards::Marble));
    _boardComboBox->addItem(removeUnderscoreInString(Boards::Metal));
    _boardComboBox->addItem(removeUnderscoreInString(Boards::Neon));
    _boardComboBox->addItem(removeUnderscoreInString(Boards::Newspaper));
    _boardComboBox->addItem(removeUnderscoreInString(Boards::Orange));
    _boardComboBox->addItem(removeUnderscoreInString(Boards::Parchment));
    _boardComboBox->addItem(removeUnderscoreInString(Boards::Purple));
    _boardComboBox->addItem(removeUnderscoreInString(Boards::Red));
    _boardComboBox->addItem(removeUnderscoreInString(Boards::Sand));
    _boardComboBox->addItem(removeUnderscoreInString(Boards::Sky));
    _boardComboBox->addItem(removeUnderscoreInString(Boards::Stone));
    _boardComboBox->addItem(removeUnderscoreInString(Boards::Tan));
    _boardComboBox->addItem(removeUnderscoreInString(Boards::Tournament));
    _boardComboBox->addItem(removeUnderscoreInString(Boards::Translucent));
    _boardComboBox->addItem(removeUnderscoreInString(Boards::Walnut));
    _boardComboBox->setCurrentIndex((int)BoardsNumber::Brown);
    connect(_boardComboBox, &QComboBox::currentIndexChanged, this, &SettingsMenu::boardComboBoxIndexChanged);

    // Text for language
    _languageTextLabel->setGeometry((int)SettingsMenuProps::LanguageTextLabelX, (int)SettingsMenuProps::LanguageTextLabelY, (int)SettingsMenuProps::LanguageTextLabelW, (int)SettingsMenuProps::LanguageTextLabelH);
    _languageTextLabel->setText("Language");
    ::setStyleSheetByTheme(StylesPaths::lightTextStyle, StylesPaths::darkBoldTextStyle, _languageTextLabel, _settingsData.isDarkTheme);

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
    ::setStyleSheetByTheme(StylesPaths::lightTextStyle, StylesPaths::darkBoldTextStyle, _soundTextLabel, _settingsData.isDarkTheme);

    // Sound toggle switch
    _soundToggleSwitch->move((int)SettingsMenuProps::SoundToggleSwitchX, (int)SettingsMenuProps::SoundToggleSwitchY);
    _soundToggleSwitch->setChecked(false);
    connect(_soundToggleSwitch, &QCheckBox::clicked, this, &SettingsMenu::swapSound);

    // Text for theme
    _themeTextLabel->setGeometry((int)SettingsMenuProps::ThemeTextLabelX, (int)SettingsMenuProps::ThemeTextLabelY, (int)SettingsMenuProps::ThemeTextLabelW, (int)SettingsMenuProps::ThemeTextLabelH);
    _themeTextLabel->setText("Black theme");
    ::setStyleSheetByTheme(StylesPaths::lightTextStyle, StylesPaths::darkBoldTextStyle, _themeTextLabel, _settingsData.isDarkTheme);

    // Theme toggle switch
    _themeToggleSwitch->move((int)SettingsMenuProps::ThemeToggleSwitchX, (int)SettingsMenuProps::ThemeToggleSwitchY);
    _themeToggleSwitch->setChecked(_settingsData.isDarkTheme);
    connect(_themeToggleSwitch, &QCheckBox::clicked, this, &SettingsMenu::swapMenuTheme);

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

QString SettingsMenu::getBkgStr(int index)
{
    switch (index)
    {
    case (int)BackgroundImagesNumbers::AngelView:
        return BackgroundImages::AngelView;
    case (int)BackgroundImagesNumbers::Blacked:
        return BackgroundImages::Blacked;
    case (int)BackgroundImagesNumbers::BravePawn:
        return BackgroundImages::BravePawn;
    case (int)BackgroundImagesNumbers::Checkmate:
        return BackgroundImages::Checkmate;
    case (int)BackgroundImagesNumbers::Dark_Chess:
        return BackgroundImages::Dark_Chess;
    case (int)BackgroundImagesNumbers::Emperors:
        return BackgroundImages::Emperors;
    case (int)BackgroundImagesNumbers::FaceToFace:
        return BackgroundImages::FaceToFace;
    case (int)BackgroundImagesNumbers::IAmTheKing:
        return BackgroundImages::IAmTheKing;
    case (int)BackgroundImagesNumbers::Landscape:
        return BackgroundImages::Landscape;
    case (int)BackgroundImagesNumbers::Legends:
        return BackgroundImages::Legends;
    case (int)BackgroundImagesNumbers::Shadow:
        return BackgroundImages::Shadow;
    case (int)BackgroundImagesNumbers::StrongKnight:
        return BackgroundImages::StrongKnight;
    case (int)BackgroundImagesNumbers::TheBishop:
        return BackgroundImages::TheBishop;
    case (int)BackgroundImagesNumbers::TheKing:
        return BackgroundImages::TheKing;
    case (int)BackgroundImagesNumbers::TheKnight:
        return BackgroundImages::TheKnight;
    case (int)BackgroundImagesNumbers::TheQueen:
        return BackgroundImages::TheQueen;
    case (int)BackgroundImagesNumbers::TheRook:
        return BackgroundImages::TheRook;
    case (int)BackgroundImagesNumbers::TopView:
        return BackgroundImages::TopView;
    default:
        return BackgroundImages::TheRook;
    }
}

QString SettingsMenu::getPieceSetStr(int index)
{
    switch (index)
    {
    case (int)PieceSetsNumber::Alpha:
        return PieceSets::Alpha;
    case (int)PieceSetsNumber::California:
        return PieceSets::California;
    case (int)PieceSetsNumber::Cardinal:
        return PieceSets::Cardinal;
    case (int)PieceSetsNumber::Cases:
        return PieceSets::Cases;
    case (int)PieceSetsNumber::Cburnett:
        return PieceSets::Cburnett;
    case (int)PieceSetsNumber::Chess7:
        return PieceSets::Chess7;
    case (int)PieceSetsNumber::Condal:
        return PieceSets::Condal;
    case (int)PieceSetsNumber::Fresca:
        return PieceSets::Fresca;
    case (int)PieceSetsNumber::GameRoom:
        return PieceSets::GameRoom;
    case (int)PieceSetsNumber::Glass:
        return PieceSets::Glass;
    case (int)PieceSetsNumber::ICPieces:
        return PieceSets::ICPieces;
    case (int)PieceSetsNumber::Lolz:
        return PieceSets::Lolz;
    case (int)PieceSetsNumber::Maestro:
        return PieceSets::Maestro;
    case (int)PieceSetsNumber::Merida:
        return PieceSets::Merida;
    case (int)PieceSetsNumber::Neo:
        return PieceSets::Neo;
    case (int)PieceSetsNumber::Ocean:
        return PieceSets::Ocean;
    default:
        return PieceSets::Cburnett;
    }
}

QString SettingsMenu::getBoardStr(int index)
{
    switch (index)
    {
    case (int)BoardsNumber::Bit8:
        return Boards::Bit8;
    case (int)BoardsNumber::Bases:
        return Boards::Bases;
    case (int)BoardsNumber::Blue:
        return Boards::Blue;
    case (int)BoardsNumber::Brown:
        return Boards::Brown;
    case (int)BoardsNumber::Bubblegum:
        return Boards::Bubblegum;
    case (int)BoardsNumber::BurledWood:
        return Boards::BurledWood;
    case (int)BoardsNumber::DarkWood:
        return Boards::DarkWood;
    case (int)BoardsNumber::Dash:
        return Boards::Dash;
    case (int)BoardsNumber::Glass:
        return Boards::Glass;
    case (int)BoardsNumber::Graffiti:
        return Boards::Graffiti;
    case (int)BoardsNumber::Green:
        return Boards::Green;
    case (int)BoardsNumber::IceSea:
        return Boards::IceSea;
    case (int)BoardsNumber::Light:
        return Boards::Light;
    case (int)BoardsNumber::Lolz:
        return Boards::Lolz;
    case (int)BoardsNumber::Marble:
        return Boards::Marble;
    case (int)BoardsNumber::Metal:
        return Boards::Metal;
    case (int)BoardsNumber::Neon:
        return Boards::Neon;
    case (int)BoardsNumber::Newspaper:
        return Boards::Newspaper;
    case (int)BoardsNumber::Orange:
        return Boards::Orange;
    case (int)BoardsNumber::Parchment:
        return Boards::Parchment;
    case (int)BoardsNumber::Purple:
        return Boards::Purple;
    case (int)BoardsNumber::Red:
        return Boards::Red;
    case (int)BoardsNumber::Sand:
        return Boards::Sand;
    case (int)BoardsNumber::Sky:
        return Boards::Sky;
    case (int)BoardsNumber::Stone:
        return Boards::Stone;
    case (int)BoardsNumber::Tan:
        return Boards::Tan;
    case (int)BoardsNumber::Tournament:
        return Boards::Tournament;
    case (int)BoardsNumber::Translucent:
        return Boards::Translucent;
    case (int)BoardsNumber::Walnut:
        return Boards::Walnut;
    default:
        return Boards::Brown;
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

void SettingsMenu::changeMenuTheme()
{
    // Background label
    ::setStyleSheetByTheme(StylesPaths::lightThemeBkgLabelStyle, StylesPaths::darkThemeBkgLabelStyle, _bkgLabel, globalIsDarkTheme);

    // Text for background image
    ::setStyleSheetByTheme(StylesPaths::lightTextStyle, StylesPaths::darkBoldTextStyle, _bkgImageTextLabel, globalIsDarkTheme);

    // Background image combobox
    ::setStyleSheetByTheme(StylesPaths::lightComboBoxStyle, StylesPaths::darkComboBoxStyle, _bkgImageComboBox, globalIsDarkTheme);

    // Text for piece sets
    ::setStyleSheetByTheme(StylesPaths::lightTextStyle, StylesPaths::darkBoldTextStyle, _pieceSetsTextLabel, globalIsDarkTheme);

    // Piece sets combobox
    ::setStyleSheetByTheme(StylesPaths::lightComboBoxStyle, StylesPaths::darkComboBoxStyle, _pieceSetsComboBox, globalIsDarkTheme);

    // Text for board
    ::setStyleSheetByTheme(StylesPaths::lightTextStyle, StylesPaths::darkBoldTextStyle, _boardTextLabel, globalIsDarkTheme);

    // Board combobox
    ::setStyleSheetByTheme(StylesPaths::lightComboBoxStyle, StylesPaths::darkComboBoxStyle, _boardComboBox, globalIsDarkTheme);

    // Text for language
    ::setStyleSheetByTheme(StylesPaths::lightTextStyle, StylesPaths::darkBoldTextStyle, _languageTextLabel, globalIsDarkTheme);

    // Language combobox
    ::setStyleSheetByTheme(StylesPaths::lightComboBoxStyle, StylesPaths::darkComboBoxStyle, _languageComboBox, globalIsDarkTheme);

    // Text for sound
    ::setStyleSheetByTheme(StylesPaths::lightTextStyle, StylesPaths::darkBoldTextStyle, _soundTextLabel, globalIsDarkTheme);

    // Text for theme
    ::setStyleSheetByTheme(StylesPaths::lightTextStyle, StylesPaths::darkBoldTextStyle, _themeTextLabel, globalIsDarkTheme);

    // Buttons background label
    ::setStyleSheetByTheme(StylesPaths::lightThemeButtonsLabelStyle, StylesPaths::darkThemeButtonsLabelStyle, _buttonsBkgLabel, globalIsDarkTheme);

    // Cancel push button
    ::setStyleSheetByTheme(StylesPaths::settingsMenuLightCancelButtonStyle, StylesPaths::settingsMenuDarkCancelButtonStyle, _cancelPushButton, globalIsDarkTheme);
}

// Private slots
void SettingsMenu::bkgImageComboBoxIndexChanged(int index)
{
    _tempData.bkgImageNumber = index;
    _tempData.bkgImageStr = getBkgStr(index);

    MainWindow::GetInstance()->setBackgroundImage(_tempData.bkgImageStr);
}

void SettingsMenu::pieceSetsComboBoxIndexChanged(int index)
{
    QString pieceSet = getPieceSetStr(index);;

    _tempData.pieceSetNumber = index;
    _tempData.piecesSetStr = pieceSet;

    _piecesLabel->setPixmap(QPixmap(ImagesPaths::settingsPiecesSetsPath + pieceSet + PieceSets::Extencion));
}

void SettingsMenu::boardComboBoxIndexChanged(int index)
{
    QString board = getBoardStr(index);;

    _tempData.boardNumber = index;
    _tempData.boardStr = board;

    _boardLabel->setPixmap(QPixmap(ImagesPaths::settingsBoardsPath + board + PieceSets::Extencion));
}

void SettingsMenu::languageComboBoxIndexChanged(int index)
{
    _tempData.languageNumber = index;
    _tempData.languageStr = getLanguageStr(index);
    // call function to set language
}

void SettingsMenu::swapMenuTheme()
{
    if (_tempData.isDarkTheme)
    {
        _tempData.isDarkTheme = false;
        globalIsDarkTheme = false;
    }
    else
    {
        _tempData.isDarkTheme = true;
        globalIsDarkTheme = true;
    }

    changeMenuTheme();
}

void SettingsMenu::swapSound()
{
    if (_tempData.isSoundAvailable)
        _tempData.isSoundAvailable = false;
    else
        _tempData.isSoundAvailable = true;
}
