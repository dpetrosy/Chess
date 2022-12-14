#ifndef MENUS_HELPERS_HPP
#define MENUS_HELPERS_HPP

#include "helpers.hpp"
#include "predefined_game_classes.hpp"
#include "predefined_menu_classes.hpp"

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
    horLayoutY = verLayoutY + verLayoutH + 0,

    // PushButtons Properties
    verLayoutButtonsW = 0,
    verLayoutButtonsH = 44,
    verLayoutButtonsFont = 18,
    horLayoutButtonsW = verLayoutButtonsW,
    horLayoutButtonsH = verLayoutButtonsH,
    horLayoutButtonsFont = verLayoutButtonsFont,

    VersionTextLabelX = (int)MainWindowProps::windowSizeW - 120,
    VersionTextLabelY = (int)MainWindowProps::windowSizeH - 30,
    VersionTextLabelW = 140,
    VersionTextLabelH = 20,
};

enum class MainMenuPushButtons
{
    PVPButton = 1,
    PVCButton = 2,
    InstrButton = 3,
    SettingsButton = 4,
    QuitButton = 5
};

// PVPMenu
enum class PVPMenuProps
{
    BkgLabelW = 440,
    BkgLabelH = 589,
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
    MinutesNumberTextLabelY = MinutesTextLabelY + 3,
    MinutesNumberTextLabelW = 30,
    MinutesNumberTextLabelH = 15,
    MinutesSliderW = 360,
    MinutesSliderH = 25,
    MinutesSliderX = BkgLabelX + (BkgLabelW - MinutesSliderW) / 2,
    MinutesSliderY = MinutesTextLabelY + 30,
    IncSecondsTextLabelX = MinutesTextLabelX - 10,
    IncSecondsTextLabelY = MinutesSliderY + 44,
    IncSecondsNumberTextLabelX = IncSecondsTextLabelX + 147,
    IncSecondsNumberTextLabelY = IncSecondsTextLabelY + 3,
    IncSecondsNumberTextLabelW = MinutesNumberTextLabelW,
    IncSecondsNumberTextLabelH = MinutesNumberTextLabelH,
    IncSecondsSliderW = MinutesSliderW,
    IncSecondsSliderH = MinutesSliderH,
    IncSecondsSliderX = MinutesSliderX,
    IncSecondsSliderY = IncSecondsTextLabelY + 31,
    QuickGamesTextLabelX = IncSecondsTextLabelX + 36,
    QuickGamesTextLabelY = IncSecondsSliderY + 38,
    Bullet1MButtonW = 58,
    Bullet1MButtonH = 74,
    Bullet1MButtonX = BkgLabelX + 15,
    Bullet1MButtonY = QuickGamesTextLabelY + 37,
    Blitz3MButtonX = Bullet1MButtonX + Bullet1MButtonW + 12,
    Blitz3MButtonY = Bullet1MButtonY,
    Blitz3MInc2SecButtonX = Blitz3MButtonX + Bullet1MButtonW + 13,
    Blitz3MInc2SecButtonY = Bullet1MButtonY,
    Blitz5MButtonX = Blitz3MInc2SecButtonX + Bullet1MButtonW + 13,
    Blitz5MButtonY = Bullet1MButtonY,
    Blitz10MButtonX = Blitz5MButtonX + Bullet1MButtonW + 12,
    Blitz10MButtonY = Bullet1MButtonY,
    Rapid15MButtonX = Blitz10MButtonX + Bullet1MButtonW + 12,
    Rapid15MButtonY = Bullet1MButtonY,
    RandomColorButtonW = 90,
    RandomColorButtonH = RandomColorButtonW,
    RandomColorButtonX = BkgLabelX + ((BkgLabelW - RandomColorButtonW) / 2),
    RandomColorButtonY = Bullet1MButtonY + Bullet1MButtonH + 29,
    BlackColorButtonW = 70,
    BlackColorButtonH = BlackColorButtonW,
    BlackColorButtonX = RandomColorButtonX - BlackColorButtonW - 15,
    BlackColorButtonY = RandomColorButtonY + (RandomColorButtonH - BlackColorButtonH),
    WhiteColorButtonX = RandomColorButtonX + RandomColorButtonW + 15,
    WhiteColorButtonY = BlackColorButtonY,
    ReturnButtonW = 25,
    ReturnButtonH = 20,
    ReturnButtonX = BkgLabelX + BkgLabelW - ReturnButtonW - 8,
    ReturnButtonY = BkgLabelY + BkgLabelH - ReturnButtonH - 7,
};

enum class PVPMenuPushButtons
{
    PlayButton = 1,
    ReturnButton = 2
};

namespace GameVariants
{
    extern QString Standard;
    extern QString Chess960;
    extern QString KingOfTheHill;
    extern QString ThreeCheck;
    extern QString Horde;
    extern QString FromPosition;
    extern QString HordeSymbolsVector2D;
}

enum class GameVariantsNumber
{
    Standard,
    Chess960,
    KingOfTheHill,
    ThreeCheck,
    Horde,
    FromPosition,
};

enum class StartGameButtons
{
    NoSelected = 0,
    Bullet1M = 1,
    Blitz3M = 2,
    Blitz3MInc2Sec = 3,
    Blitz5M = 4,
    Blitz10M = 5,
    Rapid15M = 6,
    BlackColor = 7,
    RandomColor = 8,
    WhiteColor = 9
};

namespace StartGameButtonName
{
    extern QString NoSelected;
    extern QString Bullet1M;
    extern QString Blitz3M;
    extern QString Blitz3MInc2Sec;
    extern QString Blitz5M;
    extern QString Blitz10M;
    extern QString Rapid15M;
    extern QString BlackColor;
    extern QString RandomColor;
    extern QString WhiteColor;
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
    int     bkgImageNumber = 16;
    QString bkgImageStr = "The_Rook";
    int     pieceSetNumber = 4;
    QString piecesSetStr = "Cburnett";
    int     boardNumber = 3;
    QString boardStr = "Brown";
    int     languageNumber = 2;
    QString languageStr = "eng";
    bool    isSoundAvailable = false;
    bool    isDarkTheme = globalIsDarkTheme;
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
    extern QString Legends;
    extern QString Shadow;
    extern QString StrongKnight;
    extern QString TheBishop;
    extern QString TheKing;
    extern QString TheKnight;
    extern QString TheQueen;
    extern QString TheRook;
    extern QString TopView;
}

enum class BackgroundImagesNumbers
{
    AngelView,
    Blacked,
    BravePawn,
    Checkmate,
    Dark_Chess,
    Emperors,
    FaceToFace,
    IAmTheKing,
    Landscape,
    Legends,
    Shadow,
    StrongKnight,
    TheBishop,
    TheKing,
    TheKnight,
    TheQueen,
    TheRook,
    TopView,
};

namespace Boards
{
    extern QString Extencion;
    extern QString Bit8;
    extern QString Bases;
    extern QString Blue;
    extern QString Brown;
    extern QString Bubblegum;
    extern QString BurledWood;
    extern QString DarkWood;
    extern QString Dash;
    extern QString Glass;
    extern QString Graffiti;
    extern QString Green;
    extern QString IceSea;
    extern QString Light;
    extern QString Lolz;
    extern QString Marble;
    extern QString Metal;
    extern QString Neon;
    extern QString Newspaper;
    extern QString Orange;
    extern QString Parchment;
    extern QString Purple;
    extern QString Red;
    extern QString Sand;
    extern QString Sky;
    extern QString Stone;
    extern QString Tan;
    extern QString Tournament;
    extern QString Translucent;
    extern QString Walnut;
}

enum class BoardsNumber
{
    Bit8,
    Bases,
    Blue,
    Brown,
    Bubblegum,
    BurledWood,
    DarkWood,
    Dash,
    Glass,
    Graffiti,
    Green,
    IceSea,
    Light,
    Lolz,
    Marble,
    Metal,
    Neon,
    Newspaper,
    Orange,
    Parchment,
    Purple,
    Red,
    Sand,
    Sky,
    Stone,
    Tan,
    Tournament,
    Translucent,
    Walnut
};

namespace PieceSets
{
    extern QString Extencion;
    extern QString Alpha;
    extern QString California;
    extern QString Cardinal;
    extern QString Cases;
    extern QString Cburnett;
    extern QString Chess7;
    extern QString Condal;
    extern QString Fresca;
    extern QString GameRoom;
    extern QString Glass;
    extern QString ICPieces;
    extern QString Lolz;
    extern QString Maestro;
    extern QString Merida;
    extern QString Neo;
    extern QString Ocean;
}

enum class PieceSetsNumber
{
    Alpha,
    California,
    Cardinal,
    Cases,
    Cburnett,
    Chess7,
    Condal,
    Fresca,
    GameRoom,
    Glass,
    ICPieces,
    Lolz,
    Maestro,
    Merida,
    Neo,
    Ocean,
};

namespace Languages
{
    extern QString Armenian;
    extern QString Russian;
    extern QString English;
}

#endif // MENUS_HELPERS_HPP
