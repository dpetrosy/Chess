#include "pvpmenu.hpp"
#include "toggleswitch.hpp"
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
    _isDarkTheme = false;
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
    _bullet1MPushButton = new QPushButton(this);
    _blitz3MPushButton = new QPushButton(this);
    _blitz3MInc2SecPushButton = new QPushButton(this);
    _blitz5MPushButton = new QPushButton(this);
    _blitz10MPushButton = new QPushButton(this);
    _rapid15MPushButton = new QPushButton(this);

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
    ::setStyleSheetByTheme(StylesPaths::lightThemeBkgLabelStyle, StylesPaths::darkThemeBkgLabelStyle, _bkgLabel, _isDarkTheme);
    _bkgLabel->setGeometry((int)PVPMenuProps::BkgLabelX, (int)PVPMenuProps::BkgLabelY, (int)PVPMenuProps::BkgLabelW, (int)PVPMenuProps::BkgLabelH);

    // Top text label
    _topTextLabel->setGeometry((int)PVPMenuProps::TopTextLabelX, (int)PVPMenuProps::TopTextLabelY, (int)PVPMenuProps::TopTextLabelW, (int)PVPMenuProps::TopTextLabelH);
    ::setStyleSheetByTheme(StylesPaths::lightTopTextStyle, StylesPaths::darkTopTextStyle, _topTextLabel, _isDarkTheme);
    _topTextLabel->setText("Play with a friend");
    _topTextLabel->setAlignment(Qt::AlignCenter);

    // Text for game variant
    _gameVariantTextLabel->move((int)PVPMenuProps::GameVariantTextLabelX, (int)PVPMenuProps::GameVariantTextLabelY);
    ::setStyleSheetByTheme(StylesPaths::lightDimTextStyle, StylesPaths::darkDimTextStyle, _gameVariantTextLabel, _isDarkTheme);
    _gameVariantTextLabel->setText("Variant");

    // Game variant combobox
    _gameVariantComboBox->setGeometry((int)PVPMenuProps::GameVariantComboBoxX, (int)PVPMenuProps::GameVariantComboBoxY, (int)PVPMenuProps::GameVariantComboBoxW, (int)PVPMenuProps::GameVariantComboBoxH);
    ::setStyleSheetByTheme(StylesPaths::lightComboBoxStyle, StylesPaths::darkComboBoxStyle, _gameVariantComboBox, _isDarkTheme);
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
    ::setStyleSheetByTheme(StylesPaths::lightTimeControlBkgLabelStyle, StylesPaths::darkTimeControlBkgLabelStyle, _timeControlBkgLabel, _isDarkTheme);
    _timeControlBkgLabel->setGeometry((int)PVPMenuProps::TimeControlBkgLabelX, (int)PVPMenuProps::TimeControlBkgLabelY, (int)PVPMenuProps::TimeControlBkgLabelW, (int)PVPMenuProps::TimeControlBkgLabelH);

    // Text for time control
    _timeControlTextLabel->move((int)PVPMenuProps::TimeControlTextLabelX, (int)PVPMenuProps::TimeControlTextLabelY);
    ::setStyleSheetByTheme(StylesPaths::lightDimTextStyle, StylesPaths::darkDimTextStyle, _timeControlTextLabel, _isDarkTheme);
    _timeControlTextLabel->setText("Time control");

    // Time control toggle switch
    _timeControlToggleSwitch->move((int)PVPMenuProps::TimeControlToggleSwitchX, (int)PVPMenuProps::TimeControlToggleSwitchY);
    _timeControlToggleSwitch->setChecked(false);

    // Text for minutes slider
    _minutesTextLabel->move((int)PVPMenuProps::MinutesTextLabelX, (int)PVPMenuProps::MinutesTextLabelY);
    ::setStyleSheetByTheme(StylesPaths::lightDimTextStyle, StylesPaths::darkDimTextStyle, _minutesTextLabel, _isDarkTheme);
    _minutesTextLabel->setText("Minutes per side: ");

    // Text for minutes slider number
    _minutesNumberTextLabel->move((int)PVPMenuProps::MinutesNumberTextLabelX, (int)PVPMenuProps::MinutesNumberTextLabelY);
    ::setStyleSheetByTheme(StylesPaths::lightDimTextStyle, StylesPaths::darkDimTextStyle, _minutesNumberTextLabel, _isDarkTheme);
    _minutesNumberTextLabel->setText("0");

    // Minutes slider
    _minutesSlider->setGeometry((int)PVPMenuProps::MinutesSliderX, (int)PVPMenuProps::MinutesSliderY, (int)PVPMenuProps::MinutesSliderW, (int)PVPMenuProps::MinutesSliderH);
    ::setStyleSheetByTheme(StylesPaths::lightSliderStyle, StylesPaths::darkSliderStyle, _minutesSlider, _isDarkTheme);





    // Text for increment seconds
    _incSecondsTextLabel->move((int)PVPMenuProps::IncSecondsTextLabelX, (int)PVPMenuProps::IncSecondsTextLabelY);
    ::setStyleSheetByTheme(StylesPaths::lightDimTextStyle, StylesPaths::darkDimTextStyle, _incSecondsTextLabel, _isDarkTheme);
    _incSecondsTextLabel->setText("Increment in seconds: ");

    // Text for increment seconds number
    _incSecondsNumberTextLabel->move((int)PVPMenuProps::IncSecondsNumberTextLabelX, (int)PVPMenuProps::IncSecondsNumberTextLabelY);
    ::setStyleSheetByTheme(StylesPaths::lightDimTextStyle, StylesPaths::darkDimTextStyle, _incSecondsNumberTextLabel, _isDarkTheme);
    _incSecondsNumberTextLabel->setText("0");

    // Increment seconds slider
    _incSecondsSlider->setGeometry((int)PVPMenuProps::IncSecondsSliderX, (int)PVPMenuProps::IncSecondsSliderY, (int)PVPMenuProps::IncSecondsSliderW, (int)PVPMenuProps::IncSecondsSliderH);
    ::setStyleSheetByTheme(StylesPaths::lightSliderStyle, StylesPaths::darkSliderStyle, _incSecondsSlider, _isDarkTheme);









}
