#include "pvpmenu.hpp"
#include "toggleswitch.hpp"
#include "clickablelabel.hpp"
#include "gamewidget.hpp"
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
    delete _bullet1MButton;
    delete _blitz3MButton;
    delete _blitz3MInc2SecButton;
    delete _blitz5MButton;
    delete _blitz10MButton;
    delete _rapid15MButton;

    // Color buttons
    delete _blackColorButton;
    delete _randomColorButton;
    delete _whiteColorButton;

    // Return button
    delete _returnButton;
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
    _isTimeAvailable = true;

    // Quick Games
    _quickGamesTextLabel = new QLabel(this);
    _bullet1MButton = new StartGameButton(this, StartGameButtonName::Bullet1M);
    _blitz3MButton = new StartGameButton(this, StartGameButtonName::Blitz3M);
    _blitz3MInc2SecButton = new StartGameButton(this, StartGameButtonName::Blitz3MInc2Sec);
    _blitz5MButton = new StartGameButton(this, StartGameButtonName::Blitz5M);
    _blitz10MButton = new StartGameButton(this, StartGameButtonName::Blitz10M);
    _rapid15MButton = new StartGameButton(this, StartGameButtonName::Rapid15M);

    // Color buttons
    _blackColorButton = new StartGameButton(this, StartGameButtonName::BlackColor);
    _randomColorButton = new StartGameButton(this, StartGameButtonName::RandomColor);
    _whiteColorButton = new StartGameButton(this, StartGameButtonName::WhiteColor);

    // Return button
    _returnButton = new ClickableLabel(this);
}

// Public slots
void PVPMenu::swapTimeControl()
{
    if (_isTimeAvailable)
    {
        _isTimeAvailable = false;
        GameWidget::GetInstance()->setIsTimeAvailable(false);

        _minutesSlider->setEnabled(false);
        _incSecondsSlider->setEnabled(false);

        _minutesSlider->setCursor(Qt::ForbiddenCursor);
        _incSecondsSlider->setCursor(Qt::ForbiddenCursor);
    }
    else
    {
        _isTimeAvailable = true;
        GameWidget::GetInstance()->setIsTimeAvailable(true);

        _minutesSlider->setEnabled(true);
        _incSecondsSlider->setEnabled(true);

        _minutesSlider->setCursor(Qt::PointingHandCursor);
        _incSecondsSlider->setCursor(Qt::PointingHandCursor);
    }
}

void PVPMenu::minutesSliderValueChanged(int x)
{
    double value = 0;

    if (x == 0)
        value = 0.25;
    else if (x >= 1 && x < 4)
        value = 0.25 * (x + 1);
    else if (x == 3)
        value = 1;
    else if (x == 4)
        value = 1.5;
    else if (x >= 5 && x <= 23)
        value = x - 3;
    else if (x >= 24 && x <= 27)
        value = ((x % 23) * 5) + 20;
    else
        value = ((x % 28) * 15) + 45;

    GameWidget::GetInstance()->setGameMinutes(value);
    _minutesNumberTextLabel->setText(QString::number(value));
}

void PVPMenu::incSecondsSliderValueChanged(int x)
{
    int value = 0;

    if (x == 0)
        value = 0;
    else if (x >= 1 && x <= 20)
        value = x;
    else if (x >= 21 && x <= 25)
        value = ((x % 20) * 5) + 20;
    else if (x == 26)
        value = 60;
    else
        value = ((x % 26) * 30) + 60;

    GameWidget::GetInstance()->setIncrementSeconds(value);
    _incSecondsNumberTextLabel->setText(QString::number(value));
}

// Public util functions
void PVPMenu::makeMenuBeforeSwitch()
{
    // Background label
    ::setStyleSheetByTheme(StylesPaths::lightThemeBkgLabelStyle, StylesPaths::darkThemeBkgLabelStyle, _bkgLabel, globalIsDarkTheme);

    // Top text label
    ::setStyleSheetByTheme(StylesPaths::lightTopTextStyle, StylesPaths::darkTopTextStyle, _topTextLabel, globalIsDarkTheme);

    // Text for game variant
    ::setStyleSheetByTheme(StylesPaths::lightDimTextStyle, StylesPaths::darkDimTextStyle, _gameVariantTextLabel, globalIsDarkTheme);

    // Game variant combobox
    ::setStyleSheetByTheme(StylesPaths::lightVariantComboboxStyle, StylesPaths::darkVariantComboboxStyle, _gameVariantComboBox, globalIsDarkTheme);

    // Time Control background label
    ::setStyleSheetByTheme(StylesPaths::lightTimeControlBkgLabelStyle, StylesPaths::darkTimeControlBkgLabelStyle, _timeControlBkgLabel, globalIsDarkTheme);

    // Text for time control
    ::setStyleSheetByTheme(StylesPaths::lightDimTextStyle, StylesPaths::darkDimTextStyle, _timeControlTextLabel, globalIsDarkTheme);

    // Time control toggle switch
    _timeControlToggleSwitch->setChecked(true);

    // Text for minutes slider
    ::setStyleSheetByTheme(StylesPaths::lightDimTextStyle, StylesPaths::darkDimTextStyle, _minutesTextLabel, globalIsDarkTheme);

    // Text for minutes slider number
    ::setStyleSheetByTheme(StylesPaths::lightBoldDimTextStyle, StylesPaths::darkBoldDimTextStyle, _minutesNumberTextLabel, globalIsDarkTheme);

    // Minutes slider
    ::setStyleSheetByTheme(StylesPaths::lightSliderStyle, StylesPaths::darkSliderStyle, _minutesSlider, globalIsDarkTheme);

    // Text for increment seconds
    ::setStyleSheetByTheme(StylesPaths::lightDimTextStyle, StylesPaths::darkDimTextStyle, _incSecondsTextLabel, globalIsDarkTheme);

    // Text for increment seconds number
    ::setStyleSheetByTheme(StylesPaths::lightBoldDimTextStyle, StylesPaths::darkBoldDimTextStyle, _incSecondsNumberTextLabel, globalIsDarkTheme);

    // Increment seconds slider
    ::setStyleSheetByTheme(StylesPaths::lightSliderStyle, StylesPaths::darkSliderStyle, _incSecondsSlider, globalIsDarkTheme);

    // Text for quick games
    ::setStyleSheetByTheme(StylesPaths::lightQuickGamesTextStyle, StylesPaths::darkQuickGamesTextStyle, _quickGamesTextLabel, globalIsDarkTheme);

    // Bullet 1M button
    ::setStyleSheetByTheme(StylesPaths::lightQuickGamesButtonStyle, StylesPaths::darkQuickGamesButtonStyle, _bullet1MButton, globalIsDarkTheme);
    setQLabelPictureByTheme(_bullet1MButton, globalIsDarkTheme, ImagesPaths::LightBullet1MButton, ImagesPaths::DarkBullet1MButton);

    // Blitz 3M button
    ::setStyleSheetByTheme(StylesPaths::lightQuickGamesButtonStyle, StylesPaths::darkQuickGamesButtonStyle, _blitz3MButton, globalIsDarkTheme);
    setQLabelPictureByTheme(_blitz3MButton, globalIsDarkTheme, ImagesPaths::LightBlitz3MButton, ImagesPaths::DarkBlitz3MButton);

    // Blitz 3M increment 2sec button
    ::setStyleSheetByTheme(StylesPaths::lightQuickGamesButtonStyle, StylesPaths::darkQuickGamesButtonStyle, _blitz3MInc2SecButton, globalIsDarkTheme);
    setQLabelPictureByTheme(_blitz3MInc2SecButton, globalIsDarkTheme, ImagesPaths::LightBlitz3MInc2SecButton, ImagesPaths::DarkBlitz3MInc2SecButton);

    // Blitz 5M button
    ::setStyleSheetByTheme(StylesPaths::lightQuickGamesButtonStyle, StylesPaths::darkQuickGamesButtonStyle, _blitz5MButton, globalIsDarkTheme);
    setQLabelPictureByTheme(_blitz5MButton, globalIsDarkTheme, ImagesPaths::LightBlitz5MButton, ImagesPaths::DarkBlitz5MButton);

    // Blitz 10M button
    ::setStyleSheetByTheme(StylesPaths::lightQuickGamesButtonStyle, StylesPaths::darkQuickGamesButtonStyle, _blitz10MButton, globalIsDarkTheme);
    setQLabelPictureByTheme(_blitz10MButton, globalIsDarkTheme, ImagesPaths::LightBlitz10MButton, ImagesPaths::DarkBlitz10MButton);

    // Rapid 15M button
    ::setStyleSheetByTheme(StylesPaths::lightQuickGamesButtonStyle, StylesPaths::darkQuickGamesButtonStyle, _rapid15MButton, globalIsDarkTheme);
    setQLabelPictureByTheme(_rapid15MButton, globalIsDarkTheme, ImagesPaths::LightRapid15MButton, ImagesPaths::DarkRapid15MButton);

    // Black color button
    ::setStyleSheetByTheme(StylesPaths::lightQuickGamesButtonStyle, StylesPaths::darkColorButtonStyle, _blackColorButton, globalIsDarkTheme);
    setQLabelPictureByTheme(_blackColorButton, globalIsDarkTheme, ImagesPaths::LightBlackColorButton, ImagesPaths::DarkBlackColorButton);

    // Random color button
    ::setStyleSheetByTheme(StylesPaths::lightQuickGamesButtonStyle, StylesPaths::darkColorButtonStyle, _randomColorButton, globalIsDarkTheme);
    setQLabelPictureByTheme(_randomColorButton, globalIsDarkTheme, ImagesPaths::LightRandomColorButton, ImagesPaths::DarkRandomColorButton);

    // Black color button
    ::setStyleSheetByTheme(StylesPaths::lightQuickGamesButtonStyle, StylesPaths::darkColorButtonStyle, _whiteColorButton, globalIsDarkTheme);
    setQLabelPictureByTheme(_whiteColorButton, globalIsDarkTheme, ImagesPaths::LightWhiteColorButton, ImagesPaths::DarkWhiteColorButton);
}

ClickableLabel* PVPMenu::getReturnButton()
{
    return _returnButton;
}

StartGameButton* PVPMenu::getStartGameButton(StartGameButtons button)
{
    switch (button)
    {
        case StartGameButtons::Bullet1M: return _bullet1MButton;
        case StartGameButtons::Blitz3M: return _blitz3MButton;
        case StartGameButtons::Blitz3MInc2Sec: return _blitz3MInc2SecButton;
        case StartGameButtons::Blitz5M: return _blitz5MButton;
        case StartGameButtons::Blitz10M: return _blitz10MButton;
        case StartGameButtons::Rapid15M: return _rapid15MButton;
        case StartGameButtons::BlackColor: return _blackColorButton;
        case StartGameButtons::RandomColor: return _randomColorButton;
        case StartGameButtons::WhiteColor: return _whiteColorButton;
        default: return _randomColorButton;
    }
}

void PVPMenu::setDataBeforeStartGame(double minutes, int incSeconds, PiecesColors color)
{
    auto gameWidget = GameWidget::GetInstance();

    if (minutes != 0 || incSeconds != 0)
    {
        gameWidget->setIsTimeAvailable(true);
        gameWidget->setGameMinutes(minutes);
        gameWidget->setIncrementSeconds(incSeconds);
    }

    if (color == PiecesColors::Random)
    {
        if (QRandomGenerator::global()->bounded(0, 2) == 0)
            color = PiecesColors::Black;
        else
            color = PiecesColors::White;
    }

    gameWidget->setBelowPlayerColor(color);
}

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
    ::setStyleSheetByTheme(StylesPaths::lightVariantComboboxStyle, StylesPaths::darkVariantComboboxStyle, _gameVariantComboBox, globalIsDarkTheme);
    _gameVariantComboBox->addItem(removeUnderscoreInString(GameVariants::Standard));
    _gameVariantComboBox->addItem(removeUnderscoreInString(GameVariants::Chess960));
    _gameVariantComboBox->addItem(removeUnderscoreInString(GameVariants::KingOfTheHill));
    _gameVariantComboBox->addItem(removeUnderscoreInString(GameVariants::ThreeCheck));
    _gameVariantComboBox->addItem(removeUnderscoreInString(GameVariants::Horde));
    _gameVariantComboBox->addItem(removeUnderscoreInString(GameVariants::FromPosition));
    _gameVariantComboBox->setCurrentIndex(0);
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
    _timeControlToggleSwitch->setChecked(true);
     connect(_timeControlToggleSwitch, &QCheckBox::clicked, this, &PVPMenu::swapTimeControl);

    // Text for minutes slider
    _minutesTextLabel->move((int)PVPMenuProps::MinutesTextLabelX, (int)PVPMenuProps::MinutesTextLabelY);
    ::setStyleSheetByTheme(StylesPaths::lightDimTextStyle, StylesPaths::darkDimTextStyle, _minutesTextLabel, globalIsDarkTheme);
    _minutesTextLabel->setText("Minutes per side: ");

    // Text for minutes slider number
    _minutesNumberTextLabel->setGeometry((int)PVPMenuProps::MinutesNumberTextLabelX, (int)PVPMenuProps::MinutesNumberTextLabelY, (int)PVPMenuProps::MinutesNumberTextLabelW, (int)PVPMenuProps::MinutesNumberTextLabelH);
    ::setStyleSheetByTheme(StylesPaths::lightBoldDimTextStyle, StylesPaths::darkBoldDimTextStyle, _minutesNumberTextLabel, globalIsDarkTheme);
    _minutesNumberTextLabel->setText("10");

    // Minutes slider
    _minutesSlider->setGeometry((int)PVPMenuProps::MinutesSliderX, (int)PVPMenuProps::MinutesSliderY, (int)PVPMenuProps::MinutesSliderW, (int)PVPMenuProps::MinutesSliderH);
    ::setStyleSheetByTheme(StylesPaths::lightSliderStyle, StylesPaths::darkSliderStyle, _minutesSlider, globalIsDarkTheme);
    _minutesSlider->setCursor(Qt::PointingHandCursor);
    connect(_minutesSlider, &QSlider::valueChanged, this, &PVPMenu::minutesSliderValueChanged);
    _minutesSlider->setRange(0, 37);
    _minutesSlider->setValue(13);

    // Text for increment seconds
    _incSecondsTextLabel->move((int)PVPMenuProps::IncSecondsTextLabelX, (int)PVPMenuProps::IncSecondsTextLabelY);
    ::setStyleSheetByTheme(StylesPaths::lightDimTextStyle, StylesPaths::darkDimTextStyle, _incSecondsTextLabel, globalIsDarkTheme);
    _incSecondsTextLabel->setText("Increment in seconds: ");

    // Text for increment seconds number
    _incSecondsNumberTextLabel->setGeometry((int)PVPMenuProps::IncSecondsNumberTextLabelX, (int)PVPMenuProps::IncSecondsNumberTextLabelY, (int)PVPMenuProps::IncSecondsNumberTextLabelW, (int)PVPMenuProps::IncSecondsNumberTextLabelH);
    ::setStyleSheetByTheme(StylesPaths::lightBoldDimTextStyle, StylesPaths::darkBoldDimTextStyle, _incSecondsNumberTextLabel, globalIsDarkTheme);
    _incSecondsNumberTextLabel->setText("0");

    // Increment seconds slider
    _incSecondsSlider->setGeometry((int)PVPMenuProps::IncSecondsSliderX, (int)PVPMenuProps::IncSecondsSliderY, (int)PVPMenuProps::IncSecondsSliderW, (int)PVPMenuProps::IncSecondsSliderH);
    ::setStyleSheetByTheme(StylesPaths::lightSliderStyle, StylesPaths::darkSliderStyle, _incSecondsSlider, globalIsDarkTheme);
    _incSecondsSlider->setCursor(Qt::PointingHandCursor);
    connect(_incSecondsSlider, &QSlider::valueChanged, this, &PVPMenu::incSecondsSliderValueChanged);
    _incSecondsSlider->setRange(0, 30);
    _incSecondsSlider->setValue(0);

    // Text for quick games
    _quickGamesTextLabel->move((int)PVPMenuProps::QuickGamesTextLabelX, (int)PVPMenuProps::QuickGamesTextLabelY);
    ::setStyleSheetByTheme(StylesPaths::lightQuickGamesTextStyle, StylesPaths::darkQuickGamesTextStyle, _quickGamesTextLabel, globalIsDarkTheme);
    _quickGamesTextLabel->setText("Quick Games");

    // Bullet 1M button
    _bullet1MButton->move((int)PVPMenuProps::Bullet1MButtonX, (int)PVPMenuProps::Bullet1MButtonY);
    ::setStyleSheetByTheme(StylesPaths::lightQuickGamesButtonStyle, StylesPaths::darkQuickGamesButtonStyle, _bullet1MButton, globalIsDarkTheme);
    setQLabelPictureByTheme(_bullet1MButton, globalIsDarkTheme, ImagesPaths::LightBullet1MButton, ImagesPaths::DarkBullet1MButton);

    // Blitz 3M button
    _blitz3MButton->move((int)PVPMenuProps::Blitz3MButtonX, (int)PVPMenuProps::Blitz3MButtonY);
    ::setStyleSheetByTheme(StylesPaths::lightQuickGamesButtonStyle, StylesPaths::darkQuickGamesButtonStyle, _blitz3MButton, globalIsDarkTheme);
    setQLabelPictureByTheme(_blitz3MButton, globalIsDarkTheme, ImagesPaths::LightBlitz3MButton, ImagesPaths::DarkBlitz3MButton);

    // Blitz 3M increment 2sec button
    _blitz3MInc2SecButton->move((int)PVPMenuProps::Blitz3MInc2SecButtonX, (int)PVPMenuProps::Blitz3MInc2SecButtonY);
    ::setStyleSheetByTheme(StylesPaths::lightQuickGamesButtonStyle, StylesPaths::darkQuickGamesButtonStyle, _blitz3MInc2SecButton, globalIsDarkTheme);
    setQLabelPictureByTheme(_blitz3MInc2SecButton, globalIsDarkTheme, ImagesPaths::LightBlitz3MInc2SecButton, ImagesPaths::DarkBlitz3MInc2SecButton);

    // Blitz 5M button
    _blitz5MButton->move((int)PVPMenuProps::Blitz5MButtonX, (int)PVPMenuProps::Blitz5MButtonY);
    ::setStyleSheetByTheme(StylesPaths::lightQuickGamesButtonStyle, StylesPaths::darkQuickGamesButtonStyle, _blitz5MButton, globalIsDarkTheme);
    setQLabelPictureByTheme(_blitz5MButton, globalIsDarkTheme, ImagesPaths::LightBlitz5MButton, ImagesPaths::DarkBlitz5MButton);

    // Blitz 10M button
    _blitz10MButton->move((int)PVPMenuProps::Blitz10MButtonX, (int)PVPMenuProps::Blitz10MButtonY);
    ::setStyleSheetByTheme(StylesPaths::lightQuickGamesButtonStyle, StylesPaths::darkQuickGamesButtonStyle, _blitz10MButton, globalIsDarkTheme);
    setQLabelPictureByTheme(_blitz10MButton, globalIsDarkTheme, ImagesPaths::LightBlitz10MButton, ImagesPaths::DarkBlitz10MButton);

    // Rapid 15M button
    _rapid15MButton->move((int)PVPMenuProps::Rapid15MButtonX, (int)PVPMenuProps::Rapid15MButtonY);
    ::setStyleSheetByTheme(StylesPaths::lightQuickGamesButtonStyle, StylesPaths::darkQuickGamesButtonStyle, _rapid15MButton, globalIsDarkTheme);
    setQLabelPictureByTheme(_rapid15MButton, globalIsDarkTheme, ImagesPaths::LightRapid15MButton, ImagesPaths::DarkRapid15MButton);

    // Black color button
    _blackColorButton->move((int)PVPMenuProps::BlackColorButtonX, (int)PVPMenuProps::BlackColorButtonY);
    ::setStyleSheetByTheme(StylesPaths::lightQuickGamesButtonStyle, StylesPaths::darkColorButtonStyle, _blackColorButton, globalIsDarkTheme);
    setQLabelPictureByTheme(_blackColorButton, globalIsDarkTheme, ImagesPaths::LightBlackColorButton, ImagesPaths::DarkBlackColorButton);
    _blackColorButton->setCursor(Qt::PointingHandCursor);

    // Random color button
    _randomColorButton->move((int)PVPMenuProps::RandomColorButtonX, (int)PVPMenuProps::RandomColorButtonY);
    ::setStyleSheetByTheme(StylesPaths::lightQuickGamesButtonStyle, StylesPaths::darkColorButtonStyle, _randomColorButton, globalIsDarkTheme);
    setQLabelPictureByTheme(_randomColorButton, globalIsDarkTheme, ImagesPaths::LightRandomColorButton, ImagesPaths::DarkRandomColorButton);
    _randomColorButton->setCursor(Qt::PointingHandCursor);

    // Black color button
    _whiteColorButton->move((int)PVPMenuProps::WhiteColorButtonX, (int)PVPMenuProps::WhiteColorButtonY);
    ::setStyleSheetByTheme(StylesPaths::lightQuickGamesButtonStyle, StylesPaths::darkColorButtonStyle, _whiteColorButton, globalIsDarkTheme);
    setQLabelPictureByTheme(_whiteColorButton, globalIsDarkTheme, ImagesPaths::LightWhiteColorButton, ImagesPaths::DarkWhiteColorButton);
    _whiteColorButton->setCursor(Qt::PointingHandCursor);

    // Return button
    _returnButton->move((int)PVPMenuProps::ReturnButtonX, (int)PVPMenuProps::ReturnButtonY);
    //::setStyleSheetByTheme(StylesPaths::lightReturnButtonStyle, StylesPaths::darkColorButtonStyle, _whiteColorButton, globalIsDarkTheme);
    setQLabelPictureByTheme(_returnButton, globalIsDarkTheme, ImagesPaths::LightReturnButton, ImagesPaths::DarkReturnButton);
    _returnButton->setCursor(Qt::PointingHandCursor);
}
