#include "gamewidget.hpp"
#include "boardwidget.hpp"
#include "moveswidget.hpp"
#include "piece.hpp"
#include "mainwindow.hpp"
#include "clickablelabel.hpp"
#include "helpers.hpp"
#include "utils.hpp"

bool gIsTimeEnded = false;

GameWidget::GameWidget(QWidget *parent)
    : QWidget{parent}
{
    // Init
    init();

    // Make GameWidget
    makeGameWidget();
}

GameWidget::~GameWidget()
{
    delete _boardLabel;
    delete _boardWidget;
    delete _movesWidget;
    delete _returnButton;
    delete _movesScrollArea;
}

// Singlton pattern realization
GameWidget* GameWidget::_gameWidget = nullptr;

GameWidget* GameWidget::GetInstance(QWidget *parent)
{
    if(_gameWidget == nullptr)
        _gameWidget = new GameWidget(parent);

    return _gameWidget;
}

// Init
void GameWidget::init()
{
    // Game elements
    _boardLabel = new QLabel(this);
    _boardWidget = BoardWidget::GetInstance(this);
    _movesWidget = MovesWidget::GetInstance(this);

    // Return button
    _returnButton = new ClickableLabel(this);

    _movesScrollArea = new QScrollArea(this);
}

// Public util functions
void GameWidget::startGame()
{


    // Set background theme
    if (globalIsDarkTheme)
        MainWindow::GetInstance()->setBackgroundImage(ImagesPaths::DarkThemeGameBkg);
    else
        MainWindow::GetInstance()->setBackgroundImage(ImagesPaths::LightThemeGameBkg);

    if (globalIsDarkTheme)
        _movesScrollArea->setBackgroundRole(QPalette::Shadow);
    else
        _movesScrollArea->setBackgroundRole(QPalette::Midlight);

    gIsTimeEnded = false;
    MovesWidget::ResetInstance();
    _movesWidget = MovesWidget::GetInstance(this);
    _movesWidget->setGeometry((int)MovesWidgetProps::WidgetX, (int)MovesWidgetProps::WidgetY, (int)MovesWidgetProps::WidgetW, (int)MovesWidgetProps::WidgetH);

    _movesScrollArea->setWidget(_movesWidget);
    if (globalIsDarkTheme)
        _movesScrollArea->setBackgroundRole(QPalette::Shadow);
    else
        _movesScrollArea->setBackgroundRole(QPalette::Midlight);

    // Return button
    setQLabelPictureByTheme(_returnButton, globalIsDarkTheme, ImagesPaths::GameWidgetLightReturnButton, ImagesPaths::GameWidgetDarkReturnButton);

    gSelectedPiece = nullptr;
    resetBoard();

    if (gSound)
    {
        _boardWidget->getMediaPlayer()->setSource(QUrl::fromLocalFile(Sounds::StartGameSound));
        _boardWidget->getMediaPlayer()->play();
    }
}

// Private util functions
void GameWidget::makeGameWidget()
{
    // Set BoardWidget geometry
    _boardWidget->setGeometry((int)BoardWidgetProps::BoardWidgetX, (int)BoardWidgetProps::BoardWidgetY, (int)BoardWidgetProps::BoardWidgetW, (int)BoardWidgetProps::BoardWidgetH);

    // Board label
    if (_gameData.belowPlayerColor == PiecesColors::Black)
        _boardLabel->setPixmap(QPixmap(ImagesPaths::BlackBoardsPath + _gameData.board + "_ln" + Boards::Extencion));
    else
        _boardLabel->setPixmap(QPixmap(ImagesPaths::WhiteBoardsPath + _gameData.board + Boards::Extencion));

    //_boardLabel->setStyleSheet("QLabel { border-radius: 8px; }");
    _boardLabel->setGeometry((int)BoardWidgetProps::BoardLabelX, (int)BoardWidgetProps::BoardLabelY, (int)BoardWidgetProps::BoardLabelW, (int)BoardWidgetProps::BoardLabelH);

    // Return button
    _returnButton->move((int)GamwWidgetProps::ReturnButtonX, (int)GamwWidgetProps::ReturnButtonY);
    setQLabelPictureByTheme(_returnButton, globalIsDarkTheme, ImagesPaths::GameWidgetLightReturnButton, ImagesPaths::GameWidgetDarkReturnButton);
    _returnButton->setCursor(Qt::PointingHandCursor);

    // MovesWidget
    _movesWidget->setGeometry((int)MovesWidgetProps::WidgetX, (int)MovesWidgetProps::WidgetY, (int)MovesWidgetProps::WidgetW, (int)MovesWidgetProps::WidgetH);

    // Scroll area
    _movesScrollArea->setGeometry((int)MovesWidgetProps::ScrollX, (int)MovesWidgetProps::ScrollY, (int)MovesWidgetProps::ScrollW, (int)MovesWidgetProps::ScrollH);
    if (globalIsDarkTheme)
        _movesScrollArea->setBackgroundRole(QPalette::Shadow);
    else
        _movesScrollArea->setBackgroundRole(QPalette::Midlight);
    _movesScrollArea->setWidget(_movesWidget);
}

void GameWidget::resetBoard()
{
    if (_gameData.belowPlayerColor == PiecesColors::Black)
        _boardLabel->setPixmap(QPixmap(ImagesPaths::BlackBoardsPath + _gameData.board + "_ln" + Boards::Extencion));
    else
        _boardLabel->setPixmap(QPixmap(ImagesPaths::WhiteBoardsPath + _gameData.board + "_ln" + Boards::Extencion));

    auto& symbolsVector2D = _boardWidget->getPiecesSymbolsVector2D();
    auto& stepsVector2D = _boardWidget->getPossibleStepsVector2D();

    _boardWidget->clearBoardLayout();
    _boardWidget->clearUnderLayout();

    resetCharVector2D(symbolsVector2D, 8, (char)PiecesSymbols::Empty);
    resetCharVector2D(stepsVector2D, 8, (char)PiecesSymbols::Empty);

    resetSymbolsVector2D();

    resetPiecesVector2D();

    _boardWidget->drawUnderLayer();
    _boardWidget->resetBoardLayout();


    _boardWidget->setTurn(PiecesColors::White);
    _boardWidget->setIsChecked(false);
    _boardWidget->setIsCheckedKingSelected(false);
    _boardWidget->setCheckPosition(0, 0);
    _boardWidget->setIsPawnPromoted(false);
    _boardWidget->setPromotedPawnPosition(0, 0);
    _boardWidget->setHordPiecesCount(36);
    _boardWidget->setWhiteKingCheckCount(0);
    _boardWidget->setBlackKingCheckCount(0);
}

void GameWidget::resetSymbolsVector2D()
{
    auto variant = _gameData.gameVariant;
    auto playerColor = _gameData.belowPlayerColor;

    if (variant == GameVariants::Horde)
        makeSymbolsVector2DForHorde();
    else if (variant == GameVariants::Chess960)
        makeSymbolsVector2DForChess960();
    else
        makeSymbolsVector2DStandard();

    if (playerColor == PiecesColors::Black)
        reverseSymbolsVector2D();
}

void GameWidget::reverseSymbolsVector2D()
{
    int i1 = 0;
    int j1 = 0;
    char temp;
    auto& vector2D = _boardWidget->getPiecesSymbolsVector2D();

    for (int i = 7; i >= 4; --i, ++i1)
    {
        j1 = 0;
        for (int j = 7; j >= 0; --j, ++j1)
        {
            temp = vector2D[i][j];
            vector2D[i][j] = vector2D[i1][j1];
            vector2D[i1][j1] = temp;
        }
    }
}

void GameWidget::makeSymbolsVector2DForHorde()
{
    QString hordeMatrix = GameVariants::HordeSymbolsVector2D;
    auto& vector2D = _boardWidget->getPiecesSymbolsVector2D();

    hordeMatrix.remove(' ');

    int k = 0;
    for (int i = 0; i < 8; ++i)
        for (int j = 0; j < 8; ++j, ++k)
            vector2D[i][j] = static_cast<char>(hordeMatrix.at(k).toLatin1());
}

void GameWidget::makeSymbolsVector2DForChess960()
{
    auto& vector2D = _boardWidget->getPiecesSymbolsVector2D();
    char shuffeledLine[8] = {'0', '0', '0', '0', '0', '0', '0', '0'};
    int min = 0;
    int max = 7;

    // King
    int kingPos = QRandomGenerator::global()->bounded(min + 1, max);
    shuffeledLine[kingPos] = (char)PiecesSymbols::BlackKing;

    // Rooks
    int rookPos = QRandomGenerator::global()->bounded(min, kingPos);
    shuffeledLine[rookPos] = (char)PiecesSymbols::BlackRook;
    rookPos = QRandomGenerator::global()->bounded(kingPos + 1, max + 1);
    shuffeledLine[rookPos] = (char)PiecesSymbols::BlackRook;

    // Bishops
    bool blackSquareBishop = false;
    bool whiteSquareBishop = false;
    int pos;
    while (true)
    {
        pos = QRandomGenerator::global()->bounded(min, max + 1);

        if ((pos % 2 != 0) && shuffeledLine[pos] == '0' && !blackSquareBishop)
        {
            shuffeledLine[pos] = (char)PiecesSymbols::BlackBishop;
            blackSquareBishop = true;
        }
        else if ((pos % 2 == 0) && shuffeledLine[pos] == '0' && !whiteSquareBishop)
        {
            shuffeledLine[pos] = (char)PiecesSymbols::BlackBishop;
            whiteSquareBishop = true;
        }

        if (blackSquareBishop && whiteSquareBishop)
            break;
    }

    // Queen
    while (true)
    {
        pos = QRandomGenerator::global()->bounded(min, max + 1);
        if (shuffeledLine[pos] == '0')
        {
            shuffeledLine[pos] = (char)PiecesSymbols::BlackQueen;
            break;
        }
    }

    // Knights
    for (int i = 0; i < 8; ++i)
        if (shuffeledLine[i] == '0')
            shuffeledLine[i] = (char)PiecesSymbols::BlackKnight;

    for (int i = 0; i < 8; ++i)
    {
        vector2D[0][i] = shuffeledLine[i];
        vector2D[7][i] = toupper(shuffeledLine[i]);
        vector2D[1][i] = (char)PiecesSymbols::BlackPawn;
        vector2D[6][i] = (char)PiecesSymbols::WhitePawn;
    }
}

void GameWidget::makeSymbolsVector2DStandard()
{
    QString standartMatrix = GameVariants::StandardSymbolsVector2D;
    auto& vector2D = _boardWidget->getPiecesSymbolsVector2D();

    standartMatrix.remove(' ');

    int k = 0;
    for (int i = 0; i < 8; ++i)
        for (int j = 0; j < 8; ++j, ++k)
            vector2D[i][j] = static_cast<char>(standartMatrix.at(k).toLatin1());
}

void GameWidget::resetPiecesVector2D()
{
    auto& piecesVector2D = _boardWidget->getPiecesVector2D();
    auto& piecesSymbolsVector2D = _boardWidget->getPiecesSymbolsVector2D() ;

    //_boardWidget->clearBoardLayout();

    for (int i = 0; i < (int)BoardWidgetProps::BoardSquaresCount; ++i)
    {
        for (int j = 0; j < (int)BoardWidgetProps::BoardSquaresCount; ++j)
        {
            //delete piecesVector2D[i][j];
            //piecesVector2D[i][j]->getPieceLabel()->disconnect();

            if (piecesVector2D[i][j]->getPieceSymbol() != piecesSymbolsVector2D[i][j])
            {
                delete piecesVector2D[i][j];
                _boardWidget->makeNewPieceBySymbol(piecesSymbolsVector2D[i][j], i, j);
                //connect(piecesVector2D[i][j]->getPieceLabel(), &ClickableLabel::clickedLeftButton, _boardWidget,
                  //      std::bind(&BoardWidget::processLeftButtonClick, _boardWidget, piecesVector2D[i][j]));
             }

            piecesVector2D[i][j]->changePixmap();
        }
    }
}

// Getters
GameData GameWidget::getGameData() const
{
    return _gameData;
}

QString GameWidget::getGameVariant() const
{
    return _gameData.gameVariant;
}

bool GameWidget::getIsTimeAvailable() const
{
    return _gameData.isTimeAvailable;
}

double GameWidget::getGameMinutes() const
{
    return _gameData.gameMinutes;
}

int GameWidget::getIncrementSeconds() const
{
    return _gameData.incrementSeconds;
}

PiecesColors GameWidget::getBelowPlayerColor() const
{
    return _gameData.belowPlayerColor;
}

QString GameWidget::getQuickGame() const
{
    return _gameData.quickGame;
}

QString GameWidget::getPieceSet() const
{
    return _gameData.pieceSet;
}

QString GameWidget::getBoard() const
{
    return _gameData.board;
}

ClickableLabel* GameWidget::getReturnButton()
{
    return _returnButton;
}

// Setters
void GameWidget::setGameVariant(QString gameVariant)
{
    _gameData.gameVariant = gameVariant;
}

void GameWidget::setIsTimeAvailable(bool isTimeAvailable)
{
    _gameData.isTimeAvailable = isTimeAvailable;
}

void GameWidget::setGameMinutes(double gameMinutes)
{
    _gameData.gameMinutes = gameMinutes;
}

void GameWidget::setIncrementSeconds(int incrementSeconds)
{
    _gameData.incrementSeconds = incrementSeconds;
}

void GameWidget::setBelowPlayerColor(PiecesColors color)
{
    _gameData.belowPlayerColor = color;
}

void GameWidget::setQuickGame(QString quickGame)
{
    _gameData.quickGame = quickGame;
}

void GameWidget::setPieceSet(QString set)
{
    _gameData.pieceSet = set;
}

void GameWidget::setBoard(QString board)
{
    _gameData.board = board;
}
