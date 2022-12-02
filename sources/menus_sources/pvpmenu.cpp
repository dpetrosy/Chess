#include "pvpmenu.hpp"
#include "toggleswitch.hpp"
#include "clickablelabel.hpp"
#include "utils.hpp"

PVPMenu::PVPMenu(QWidget *parent) :
    QWidget(parent)
{
    // Init class members
    init();

    // Make PVPMenu
    makePVPMenu();
}

PVPMenu::~PVPMenu()
{
    delete _bkgLabel;
    delete _topTextLabel;

    // Game Variant
    delete _gameVariantTextLabel;
    delete _gameVariantComboBox;

    // Time Control
    delete _timeControlBkgLabel;
    delete _timeControlTextLabel;
    delete _timeControlToggleSwitch;
    delete _minutesTextLabel;
    delete _minutesNumberTextLabel;
    delete _incSecondsTextLabel;
    delete _incSecondsNumberTextLabel;
    delete _minutesSlider;
    delete _incSecondsSlider;

    // Quick Games
    delete _quickGamesTextLabel;
    delete _bullet1MPushButton;
    delete _blitz3MPushButton;
    delete _blitz3MInc2SecPushButton;
    delete _blitz5MPushButton;
    delete _blitz10MPushButton;
    delete _rapid15MPushButton;

    // Color buttons
    delete _blackColorPushButton;
    delete _randomColorPushButton;
    delete _whiteColorPushButton;

    // Return button
    delete _returnPushButton;
}

// Init
void PVPMenu::init()
{
    _bkgLabel = new QLabel(this);
    _topTextLabel = new QLabel(this);

    // Game Variant
    _gameVariantTextLabel = new QLabel(this);
    _gameVariantComboBox = new QComboBox(this);

    // Time Control
    _timeControlBkgLabel = new QLabel(this);
    _timeControlTextLabel = new QLabel(this);
    _timeControlToggleSwitch = new ToggleSwitch(this);
    _minutesTextLabel = new QLabel(this);
    _minutesNumberTextLabel = new QLabel(this);
    _incSecondsTextLabel = new QLabel(this);
    _incSecondsNumberTextLabel = new QLabel(this);
    _minutesSlider = new QSlider(Qt::Horizontal, this);
    _incSecondsSlider = new QSlider(Qt::Horizontal, this);

    // Quick Games
    _quickGamesTextLabel = new QLabel(this);
    _bullet1MPushButton = new QuickGameButton(this, QuickGames::Bullet1M);
    _blitz3MPushButton = new QuickGameButton(this, QuickGames::Blitz3M);
    _blitz3MInc2SecPushButton = new QuickGameButton(this, QuickGames::Blitz3MInc2Sec);
    _blitz5MPushButton = new QuickGameButton(this, QuickGames::Blitz5M);
    _blitz10MPushButton = new QuickGameButton(this, QuickGames::Blitz10M);
    _rapid15MPushButton = new QuickGameButton(this, QuickGames::Rapid15M);

    // Color buttons
    _blackColorPushButton = new QPushButton(this);
    _randomColorPushButton = new QPushButton(this);
    _whiteColorPushButton = new QPushButton(this);

    // Return button
    _returnPushButton = new QPushButton(this);
}

// Public util functions
//QPushButton *PVPMenu::getPushButton(PVPMenuPushButtons button)
//{
//    switch (button)
//    {

//    }
//}

// Private util functions
void PVPMenu::makePVPMenu()
{
    // Background label
    ::setStyleSheetByTheme(StylesPaths::lightThemeBkgLabelStyle, StylesPaths::darkThemeBkgLabelStyle, _bkgLabel, globalIsDarkTheme);
    _bkgLabel->setGeometry((int)PVPMenuProps::BkgLabelX, (int)PVPMenuProps::BkgLabelY, (int)PVPMenuProps::BkgLabelW, (int)PVPMenuProps::BkgLabelH);

    // Top text label
    _topTextLabel->setGeometry((int)PVPMenuProps::TopTextLabelX, (int)PVPMenuProps::TopTextLabelY, (int)PVPMenuProps::TopTextLabelW, (int)PVPMenuProps::TopTextLabelH);
    ::setStyleSheetByTheme(StylesPaths::lightTopTextStyle, StylesPaths::darkTopTextStyle, _topTextLabel, globalIsDarkTheme);
    _topTextLabel->setText("Play with a friend");
    _topTextLabel->setAlignment(Qt::AlignCenter);

    // Text for game variant
    _gameVariantTextLabel->move((int)PVPMenuProps::GameVariantTextLabelX, (int)PVPMenuProps::GameVariantTextLabelY);
    ::setStyleSheetByTheme(StylesPaths::lightDimTextStyle, StylesPaths::darkDimTextStyle, _gameVariantTextLabel, globalIsDarkTheme);
    _gameVariantTextLabel->setText("Variant");

    // Game variant combobox
    _gameVariantComboBox->setGeometry((int)PVPMenuProps::GameVariantComboBoxX, (int)PVPMenuProps::GameVariantComboBoxY, (int)PVPMenuProps::GameVariantComboBoxW, (int)PVPMenuProps::GameVariantComboBoxH);
    ::setStyleSheetByTheme(StylesPaths::lightComboBoxStyle, StylesPaths::darkComboBoxStyle, _gameVariantComboBox, globalIsDarkTheme);
//    _gameVariantComboBox->addItem(removeUnderscoreInString(BackgroundImages::AngelView));
//    _gameVariantComboBox->addItem(removeUnderscoreInString(BackgroundImages::Blacked));
//    _gameVariantComboBox->addItem(removeUnderscoreInString(BackgroundImages::BravePawn));
//    _gameVariantComboBox->addItem(removeUnderscoreInString(BackgroundImages::Checkmate));
//    _gameVariantComboBox->addItem(removeUnderscoreInString(BackgroundImages::Dark_Chess));
//    _gameVariantComboBox->addItem(removeUnderscoreInString(BackgroundImages::Emperors));
//    _gameVariantComboBox->addItem(removeUnderscoreInString(BackgroundImages::FaceToFace));
//    _gameVariantComboBox->addItem(removeUnderscoreInString(BackgroundImages::IAmTheKing));
//    _gameVariantComboBox->addItem(removeUnderscoreInString(BackgroundImages::Landscape));
//    _gameVariantComboBox->addItem(removeUnderscoreInString(BackgroundImages::Shadow));
//    _gameVariantComboBox->addItem(removeUnderscoreInString(BackgroundImages::StrongKnight));
//    _gameVariantComboBox->addItem(removeUnderscoreInString(BackgroundImages::TheBishop));
//    _gameVariantComboBox->addItem(removeUnderscoreInString(BackgroundImages::TheKing));
//    _gameVariantComboBox->addItem(removeUnderscoreInString(BackgroundImages::TheKnight));
//    _gameVariantComboBox->addItem(removeUnderscoreInString(BackgroundImages::TheQueen));
//    _gameVariantComboBox->addItem(removeUnderscoreInString(BackgroundImages::TheRook));
//    _gameVariantComboBox->addItem(removeUnderscoreInString(BackgroundImages::TopView));
//    _gameVariantComboBox->setCurrentIndex(15);
//    connect(_gameVariantComboBox, &QComboBox::currentIndexChanged, this, &SettingsMenu::bkgImageComboBoxIndexChanged);

    // Time Control background label
    ::setStyleSheetByTheme(StylesPaths::lightTimeControlBkgLabelStyle, StylesPaths::darkTimeControlBkgLabelStyle, _timeControlBkgLabel, globalIsDarkTheme);
    _timeControlBkgLabel->setGeometry((int)PVPMenuProps::TimeControlBkgLabelX, (int)PVPMenuProps::TimeControlBkgLabelY, (int)PVPMenuProps::TimeControlBkgLabelW, (int)PVPMenuProps::TimeControlBkgLabelH);

    // Text for time control
    _timeControlTextLabel->move((int)PVPMenuProps::TimeControlTextLabelX, (int)PVPMenuProps::TimeControlTextLabelY);
    ::setStyleSheetByTheme(StylesPaths::lightDimTextStyle, StylesPaths::darkDimTextStyle, _timeControlTextLabel, globalIsDarkTheme);
    _timeControlTextLabel->setText("Time control");

    // Time control toggle switch
    _timeControlToggleSwitch->move((int)PVPMenuProps::TimeControlToggleSwitchX, (int)PVPMenuProps::TimeControlToggleSwitchY);
    _timeControlToggleSwitch->setChecked(false);

    // Text for minutes slider
    _minutesTextLabel->move((int)PVPMenuProps::MinutesTextLabelX, (int)PVPMenuProps::MinutesTextLabelY);
    ::setStyleSheetByTheme(StylesPaths::lightDimTextStyle, StylesPaths::darkDimTextStyle, _minutesTextLabel, globalIsDarkTheme);
    _minutesTextLabel->setText("Minutes per side: ");

    // Text for minutes slider number
    _minutesNumberTextLabel->move((int)PVPMenuProps::MinutesNumberTextLabelX, (int)PVPMenuProps::MinutesNumberTextLabelY);
    ::setStyleSheetByTheme(StylesPaths::lightBoldDimTextStyle, StylesPaths::darkBoldDimTextStyle, _minutesNumberTextLabel, globalIsDarkTheme);
    _minutesNumberTextLabel->setText("0.25");

    // Minutes slider
    _minutesSlider->setGeometry((int)PVPMenuProps::MinutesSliderX, (int)PVPMenuProps::MinutesSliderY, (int)PVPMenuProps::MinutesSliderW, (int)PVPMenuProps::MinutesSliderH);
    ::setStyleSheetByTheme(StylesPaths::lightSliderStyle, StylesPaths::darkSliderStyle, _minutesSlider, globalIsDarkTheme);
    _incSecondsSlider->setCursor(Qt::PointingHandCursor);

    // Text for increment seconds
    _incSecondsTextLabel->move((int)PVPMenuProps::IncSecondsTextLabelX, (int)PVPMenuProps::IncSecondsTextLabelY);
    ::setStyleSheetByTheme(StylesPaths::lightDimTextStyle, StylesPaths::darkDimTextStyle, _incSecondsTextLabel, globalIsDarkTheme);
    _incSecondsTextLabel->setText("Increment in seconds: ");

    // Text for increment seconds number
    _incSecondsNumberTextLabel->move((int)PVPMenuProps::IncSecondsNumberTextLabelX, (int)PVPMenuProps::IncSecondsNumberTextLabelY);
    ::setStyleSheetByTheme(StylesPaths::lightBoldDimTextStyle, StylesPaths::darkBoldDimTextStyle, _incSecondsNumberTextLabel, globalIsDarkTheme);
    _incSecondsNumberTextLabel->setText("0");

    // Increment seconds slider
    _incSecondsSlider->setGeometry((int)PVPMenuProps::IncSecondsSliderX, (int)PVPMenuProps::IncSecondsSliderY, (int)PVPMenuProps::IncSecondsSliderW, (int)PVPMenuProps::IncSecondsSliderH);
    ::setStyleSheetByTheme(StylesPaths::lightSliderStyle, StylesPaths::darkSliderStyle, _incSecondsSlider, globalIsDarkTheme);
    _incSecondsSlider->setCursor(Qt::PointingHandCursor);

    // Text for quick games
    _quickGamesTextLabel->move((int)PVPMenuProps::QuickGamesTextLabelX, (int)PVPMenuProps::QuickGamesTextLabelY);
    ::setStyleSheetByTheme(StylesPaths::lightQuickGamesTextStyle, StylesPaths::darkQuickGamesTextStyle, _quickGamesTextLabel, globalIsDarkTheme);
    _quickGamesTextLabel->setText("Quick Games");

    // Bullet 1M button
    _bullet1MPushButton->move((int)PVPMenuProps::Bullet1MPushButtonX, (int)PVPMenuProps::Bullet1MPushButtonY);
    ::setStyleSheetByTheme(StylesPaths::lightQuickGamesButtonStyle, StylesPaths::darkQuickGamesButtonStyle, _bullet1MPushButton, globalIsDarkTheme);
    setQLabelPictureByTheme(_bullet1MPushButton, globalIsDarkTheme, ImagesPaths::LightBullet1MButton, ImagesPaths::DarkBullet1MButton);

    // Blitz 3M button
    _blitz3MPushButton->move((int)PVPMenuProps::Blitz3MPushButtonX, (int)PVPMenuProps::Blitz3MPushButtonY);
    ::setStyleSheetByTheme(StylesPaths::lightQuickGamesButtonStyle, StylesPaths::darkQuickGamesButtonStyle, _blitz3MPushButton, globalIsDarkTheme);
    setQLabelPictureByTheme(_blitz3MPushButton, globalIsDarkTheme, ImagesPaths::LightBlitz3MButton, ImagesPaths::DarkBlitz3MButton);

    // Blitz 3M increment 2sec button
    _blitz3MInc2SecPushButton->move((int)PVPMenuProps::Blitz3MInc2SecPushButtonX, (int)PVPMenuProps::Blitz3MInc2SecPushButtonY);
    ::setStyleSheetByTheme(StylesPaths::lightQuickGamesButtonStyle, StylesPaths::darkQuickGamesButtonStyle, _blitz3MInc2SecPushButton, globalIsDarkTheme);
    setQLabelPictureByTheme(_blitz3MInc2SecPushButton, globalIsDarkTheme, ImagesPaths::LightBlitz3MInc2SecButton, ImagesPaths::DarkBlitz3MInc2SecButton);

    // Blitz 5M button
    _blitz5MPushButton->move((int)PVPMenuProps::Blitz5MPushButtonX, (int)PVPMenuProps::Blitz5MPushButtonY);
    ::setStyleSheetByTheme(StylesPaths::lightQuickGamesButtonStyle, StylesPaths::darkQuickGamesButtonStyle, _blitz5MPushButton, globalIsDarkTheme);
    setQLabelPictureByTheme(_blitz5MPushButton, globalIsDarkTheme, ImagesPaths::LightBlitz5MButton, ImagesPaths::DarkBlitz5MButton);

    // Blitz 10M button
    _blitz10MPushButton->move((int)PVPMenuProps::Blitz10MPushButtonX, (int)PVPMenuProps::Blitz10MPushButtonY);
    ::setStyleSheetByTheme(StylesPaths::lightQuickGamesButtonStyle, StylesPaths::darkQuickGamesButtonStyle, _blitz10MPushButton, globalIsDarkTheme);
    setQLabelPictureByTheme(_blitz10MPushButton, globalIsDarkTheme, ImagesPaths::LightBlitz10MButton, ImagesPaths::DarkBlitz10MButton);

    // Rapid 15M button
    _rapid15MPushButton->move((int)PVPMenuProps::Rapid15MPushButtonX, (int)PVPMenuProps::Rapid15MPushButtonY);
    ::setStyleSheetByTheme(StylesPaths::lightQuickGamesButtonStyle, StylesPaths::darkQuickGamesButtonStyle, _rapid15MPushButton, globalIsDarkTheme);
    setQLabelPictureByTheme(_rapid15MPushButton, globalIsDarkTheme, ImagesPaths::LightRapid15MButton, ImagesPaths::DarkRapid15MButton);
}


