#ifndef MENUS_HELPERS_HPP
#define MENUS_HELPERS_HPP

#include "helpers.hpp"
#include "predefined_menu_classes.hpp"
#include "predefined_game_classes.hpp"

enum class Menus : int
{
    MainMenu = 0,
    PVPMenu = 1,
    SettingsMenu = 2
};


// MainMenu
enum class MainMenuProps
{
    // Layouts Properties
    verLayoutW = ((int)MainWindowProps::windowSizeW / 10) * 4,
    verLayoutH = (int)MainWindowProps::windowSizeH / 4,
    verLayoutX = ((int)MainWindowProps::windowSizeW - verLayoutW) / 2,
    horLayoutX = verLayoutX,
    horLayoutW = verLayoutW,
    horLayoutH = verLayoutH / 3 + 2,
    verLayoutY = ((int)MainWindowProps::windowSizeH - (verLayoutH + horLayoutH + 20)) / 2,
    horLayoutY = verLayoutY + verLayoutH + 6,

    // PushButtons Properties
    verLayoutButtonsW = 0,
    verLayoutButtonsH = 44,
    verLayoutButtonsFont = 18,
    horLayoutButtonsW = verLayoutButtonsW,
    horLayoutButtonsH = verLayoutButtonsH,
    horLayoutButtonsFont = verLayoutButtonsFont,
};

enum class MainMenuPushButtons
{
    PVPButton = 1,
    PVCButton = 2,
    InstrButton = 3,
    SettingsButton = 4,
    QuitButton = 5
};

enum class MainMenuStackedWidgets
{
    PVPStackedWidget = 1,
    PVCStackedWidget = 2,
    InstrStackedWidget = 3,
    SettingsStackedWidget = 4
};


// PVPMenu
enum class PVPMenuProps
{
    BkgLabelW = 440,
    BkgLabelH = 600,
    BkgLabelX = ((int)MainWindowProps::windowSizeW - BkgLabelW) / 2,
    BkgLabelY = ((int)MainWindowProps::windowSizeH - BkgLabelH) / 2,
    TopTextLabelX = BkgLabelX,
    TopTextLabelY = BkgLabelY + 22,
    TopTextLabelW = BkgLabelW,
    TopTextLabelH = 40,
    GameVariantTextLabelX = BkgLabelX + 112,
    GameVariantTextLabelY = TopTextLabelY + 72,
    GameVariantComboBoxX = GameVariantTextLabelX + 57,
    GameVariantComboBoxY = GameVariantTextLabelY - 8,
    GameVariantComboBoxW = 157,
    GameVariantComboBoxH = 41,
    TimeControlBkgLabelX = BkgLabelX,
    TimeControlBkgLabelY = GameVariantTextLabelY + 49,
    TimeControlBkgLabelW = BkgLabelW,
    TimeControlBkgLabelH = 323,
    TimeControlTextLabelX = TimeControlBkgLabelX + 140,
    TimeControlTextLabelY = TimeControlBkgLabelY + 16,
    TimeControlToggleSwitchX = TimeControlTextLabelX + 94,
    TimeControlToggleSwitchY = TimeControlTextLabelY - 10,
    MinutesTextLabelX = TimeControlTextLabelX + 5,
    MinutesTextLabelY = TimeControlTextLabelY + 41,
    MinutesNumberTextLabelX = MinutesTextLabelX + 117,
    MinutesNumberTextLabelY = MinutesTextLabelY + 1,
    MinutesSliderW = 360,
    MinutesSliderH = 25,
    MinutesSliderX = BkgLabelX + (BkgLabelW - MinutesSliderW) / 2,
    MinutesSliderY = MinutesTextLabelY + 30,
    IncSecondsTextLabelX = MinutesTextLabelX - 10,
    IncSecondsTextLabelY = MinutesSliderY + 44,
    IncSecondsNumberTextLabelX = IncSecondsTextLabelX + 147,
    IncSecondsNumberTextLabelY = IncSecondsTextLabelY + 1,
    IncSecondsSliderW = MinutesSliderW,
    IncSecondsSliderH = MinutesSliderH,
    IncSecondsSliderX = MinutesSliderX,
    IncSecondsSliderY = IncSecondsTextLabelY + 31,
    QuickGamesTextLabelX = IncSecondsTextLabelX + 36,
    QuickGamesTextLabelY = IncSecondsSliderY + 38,
    Bullet1MPushButtonW = 58,
    Bullet1MPushButtonH = 74,
    Bullet1MPushButtonX = BkgLabelX + 15,
    Bullet1MPushButtonY = QuickGamesTextLabelY + 37,
    Blitz3MPushButtonX = Bullet1MPushButtonX + Bullet1MPushButtonW + 12,
    Blitz3MPushButtonY = Bullet1MPushButtonY,
    Blitz3MInc2SecPushButtonX = Blitz3MPushButtonX + Bullet1MPushButtonW + 13,
    Blitz3MInc2SecPushButtonY = Bullet1MPushButtonY,
    Blitz5MPushButtonX = Blitz3MInc2SecPushButtonX + Bullet1MPushButtonW + 13,
    Blitz5MPushButtonY = Bullet1MPushButtonY,
    Blitz10MPushButtonX = Blitz5MPushButtonX + Bullet1MPushButtonW + 12,
    Blitz10MPushButtonY = Bullet1MPushButtonY,
    Rapid15MPushButtonX = Blitz10MPushButtonX + Bullet1MPushButtonW + 12,
    Rapid15MPushButtonY = Bullet1MPushButtonY,
};

enum class PVPMenuPushButtons
{
    PlayButton = 1,
    ReturnButton = 2
};

namespace GameVariants
{
    extern QString Standart;
};

namespace QuickGames
{
    extern QString NoSelected;
    extern QString Bullet1M;
    extern QString Blitz3M;
    extern QString Blitz3MInc2Sec;
    extern QString Blitz5M;
    extern QString Blitz10M;
    extern QString Rapid15M;
}


// SettingsMenu
enum class SettingsMenuProps
{
    BkgLabelW = 460,
    BkgLabelH = 507,
    BkgLabelX = ((int)MainWindowProps::windowSizeW - BkgLabelW) / 2,
    BkgLabelY = ((int)MainWindowProps::windowSizeH - BkgLabelH) / 2,
    BoardLabelX = BkgLabelX + 10,
    BoardLabelY = BkgLabelY + 10,
    BoardLabelW = BkgLabelW - 20,
    BoardLabelH = 137,
    BkgImageTextLabelX = BoardLabelX,
    BkgImageTextLabelY = BoardLabelY + BoardLabelH + 13,
    BkgImageTextLabelW = BoardLabelW / 2,
    BkgImageTextLabelH = 30,
    BkgImageComboBoxX = BoardLabelX + (BoardLabelW / 2),
    BkgImageComboBoxY = BkgImageTextLabelY,
    BkgImageComboBoxW = BkgImageTextLabelW,
    BkgImageComboBoxH = BkgImageTextLabelH,
    PieceSetTextLabelX = BkgImageTextLabelX,
    PieceSetTextLabelY = BkgImageTextLabelY + BkgImageTextLabelH + 15,
    PieceSetTextLabelW = BkgImageTextLabelW,
    PieceSetTextLabelH = BkgImageTextLabelH,
    PieceSetComboBoxX = BkgImageComboBoxX,
    PieceSetComboBoxY = PieceSetTextLabelY,
    PieceSetComboBoxW = BkgImageComboBoxW,
    PieceSetComboBoxH = BkgImageComboBoxH,
    BoardTextLabelX = BkgImageTextLabelX,
    BoardTextLabelY = PieceSetTextLabelY + PieceSetTextLabelH + 15,
    BoardTextLabelW = BkgImageTextLabelW,
    BoardTextLabelH = BkgImageTextLabelH,
    BoardComboBoxX = BkgImageComboBoxX,
    BoardComboBoxY = BoardTextLabelY,
    BoardComboBoxW = BkgImageComboBoxW,
    BoardComboBoxH = BkgImageComboBoxH,
    LanguageTextLabelX = BkgImageTextLabelX,
    LanguageTextLabelY = BoardTextLabelY + BoardTextLabelH + 15,
    LanguageTextLabelW = BkgImageTextLabelW,
    LanguageTextLabelH = BkgImageTextLabelH,
    LanguageComboBoxX = BkgImageComboBoxX,
    LanguageComboBoxY = LanguageTextLabelY,
    LanguageComboBoxW = BkgImageComboBoxW,
    LanguageComboBoxH = BkgImageComboBoxH,
    SoundTextLabelX = BkgImageTextLabelX,
    SoundTextLabelY = LanguageTextLabelY + LanguageTextLabelH + 15,
    SoundTextLabelW = BkgImageTextLabelW,
    SoundTextLabelH = BkgImageTextLabelH,
    SoundToggleSwitchX = BkgImageComboBoxX + 162,
    SoundToggleSwitchY = SoundTextLabelY - 4,
    ThemeTextLabelX = BkgImageTextLabelX,
    ThemeTextLabelY = SoundTextLabelY + SoundTextLabelH + 15,
    ThemeTextLabelW = BkgImageTextLabelW,
    ThemeTextLabelH = BkgImageTextLabelH,
    ThemeToggleSwitchX = SoundToggleSwitchX,
    ThemeToggleSwitchY = ThemeTextLabelY - 4,
    ButtonsBkgLabelX = BkgLabelX,
    ButtonsBkgLabelY = ThemeTextLabelY + ThemeTextLabelH + 15,
    ButtonsBkgLabelW = BkgLabelW,
    ButtonsBkgLabelH = 80,
    CancelButtonX = ButtonsBkgLabelX + 16,
    CancelButtonY = ButtonsBkgLabelY + 15,
    CancelButtonW = (BkgLabelW - 50) / 2,
    CancelButtonH = ButtonsBkgLabelH - 30,
    SaveButtonX = CancelButtonX + CancelButtonW + 18,
    SaveButtonY = CancelButtonY,
    SaveButtonW = CancelButtonW,
    SaveButtonH = CancelButtonH,
    HideAndShowButtonW = 40,
    HideAndShowButtonH = 40,
    HideAndShowButtonX = (int)MainWindowProps::windowSizeW - HideAndShowButtonW - 15,
    HideAndShowButtonY = (int)MainWindowProps::windowSizeH - HideAndShowButtonH - 15
};

struct SettingsData
{
    QString bkgImageStr = "The_Rook";
    QString piecesSetStr = "1";
    QString boardStr = "1";
    QString languageStr = "eng";
    bool isSoundAvailable = false;
    bool isDarkTheme = globalIsDarkTheme;
};

enum class SettingsMenuPushButtons
{
    CancelButton = 1,
    SaveButton = 2,
};

namespace BackgroundImages
{
    extern QString Extencion;
    extern QString AngelView;
    extern QString Blacked;
    extern QString BravePawn;
    extern QString Checkmate;
    extern QString Dark_Chess;
    extern QString Emperors;
    extern QString FaceToFace;
    extern QString IAmTheKing;
    extern QString Landscape;
    extern QString Shadow;
    extern QString StrongKnight;
    extern QString TheBishop;
    extern QString TheKing;
    extern QString TheKnight;
    extern QString TheQueen;
    extern QString TheRook;
    extern QString TopView;
}

namespace Languages
{
    extern QString Armenian;
    extern QString Russian;
    extern QString English;
}

#endif // MENUS_HELPERS_HPP
