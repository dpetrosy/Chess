#include "boardwidget.hpp"
#include "moveswidget.hpp"
#include "gamewidget.hpp"
#include "pawnpromdialog.hpp"
#include "pieces_helpers.hpp"
#include "factory.hpp"
#include "piece.hpp"
#include "clickablelabel.hpp"
#include "utils.hpp"

Piece* gSelectedPiece = nullptr;
bool doForQueen = false;

BoardWidget::BoardWidget(QWidget *parent)
    : QWidget{parent}
{
    // Init
    init();

    // Make BoardWidget
    makeBoardWidget();
}

BoardWidget::~BoardWidget()
{
    delete _underLayerLayout;
    delete _piecesFactory;
    delete _pawnPromDialog;
    delete _underLayerWidget;
    delete _boardLayout;
    delete _mediaPlayer;
    delete _audioOutput;
    delete _whitePlayerTimer;
    delete _blackPlayerTimer;

    for (int i = 0; i < _boardSize; ++i)
        for (int j = 0; j < _boardSize; ++j)
            delete _piecesVector2D[i][j];
}

// Singleton pattern realization
BoardWidget* BoardWidget::_boardWidget = nullptr;

BoardWidget* BoardWidget::GetInstance(QWidget *parent)
{
    if(_boardWidget == nullptr)
        _boardWidget = new BoardWidget(parent);

    return _boardWidget;
}

// Init
void BoardWidget::init()
{
    // Prototype pattern factory
    _piecesFactory = new Factory();

    // Board widget attributes
    _boardSize = (int)BoardWidgetProps::BoardSquaresCount;
    _turn = PiecesColors::White;
    _isChecked = false;
    _isCheckedKingSelected = false;
    _isPawnPromoted = false;
    _pawnPromDialog = new PawnPromDialog();
    _hordePiecesCount = 36;
    _whiteKingCheckCount = 0;
    _blackKingCheckCount = 0;
    _mediaPlayer = new QMediaPlayer();
    _audioOutput = new QAudioOutput();
    _whitePlayerTimer = new QTimer(this);
    _whitePlayerTimer->setInterval(10 * 60 * 1000);
    _blackPlayerTimer = new QTimer(this);
    _blackPlayerTimer->setInterval(10 * 60 * 1000);

    // Init under layer attributes
    PiecesColors noColored = PiecesColors::NoColored;
    _underLayerWidget = new QWidget(this);
    _underLayerLayout = new QGridLayout(_underLayerWidget);

    // Init possibleStepsVector2D
    _possibleStepsVector2D.reserve(_boardSize);
    for (int i = 0; i < _boardSize; ++i)
        _possibleStepsVector2D.push_back(QVector<char>(_boardSize, (char)PossibleSteps::Empty));

    // Init underLayerVector2D
    _underLayerVector2D.reserve(_boardSize);
    for (int i = 0; i < _boardSize; ++i)
        _underLayerVector2D.push_back(QVector<Piece *>(_boardSize, nullptr));

    for (int i = 0; i < _boardSize ; ++i)
        for (int j = 0; j < _boardSize; ++j)
            _underLayerVector2D[i][j] = _piecesFactory->CreatePiece(Pieces::Empty, noColored, i, j);

    // Init symbolsVector2D
    _piecesSymbolsVector2D.reserve(_boardSize);
    for (int i = 0; i < _boardSize; ++i)
        _piecesSymbolsVector2D.push_back(QVector<char>(_boardSize, (char)PiecesSymbols::Placeholder));

    for (int i = 0; i < _boardSize ; ++i)
    {
        for (int j = 0; j < _boardSize; ++j)
        {
            //if (i == 1 || i == 2 || i == 3 || i == 4 || i == 5 || i == 6)
            //    _piecesSymbolsVector2D[i][j] = (char)PiecesSymbols::Empty;

            if (i == 2 || i == 3 || i == 4 || i == 5)
                _piecesSymbolsVector2D[i][j] = (char)PiecesSymbols::Empty;
            else if (i == 6)
                _piecesSymbolsVector2D[i][j] = (char)PiecesSymbols::WhitePawn;
            else if (i == 1)
                _piecesSymbolsVector2D[i][j] = (char)PiecesSymbols::BlackPawn;
            else if ((i == 7 && j == 0) || (i == 7 && j == 7))
                _piecesSymbolsVector2D[i][j] = (char)PiecesSymbols::WhiteRook;
            else if ((i == 7 && j == 1) || (i == 7 && j == 6))
                _piecesSymbolsVector2D[i][j] = (char)PiecesSymbols::WhiteKnight;
            else if ((i == 7 && j == 2) || (i == 7 && j == 5))
                _piecesSymbolsVector2D[i][j] = (char)PiecesSymbols::WhiteBishop;
            else if (i == 7 && j == 3)
                _piecesSymbolsVector2D[i][j] = (char)PiecesSymbols::WhiteQueen;
            else if (i == 7 && j == 4)
                _piecesSymbolsVector2D[i][j] = (char)PiecesSymbols::WhiteKing;
            else if ((i == 0 && j == 0) || (i == 0 && j == 7))
                _piecesSymbolsVector2D[i][j] = (char)PiecesSymbols::BlackRook;
            else if ((i == 0 && j == 1) || (i == 0 && j == 6))
                _piecesSymbolsVector2D[i][j] = (char)PiecesSymbols::BlackKnight;
            else if ((i == 0 && j == 2) || (i == 0 && j == 5))
                _piecesSymbolsVector2D[i][j] = (char)PiecesSymbols::BlackBishop;
            else if (i == 0 && j == 3)
                _piecesSymbolsVector2D[i][j] = (char)PiecesSymbols::BlackQueen;
            else if (i == 0 && j == 4)
                _piecesSymbolsVector2D[i][j] = (char)PiecesSymbols::BlackKing;
        }
    }

    // Init piecesVector2D
    _boardLayout = new QGridLayout();

    _piecesVector2D.reserve(_boardSize);
    for (int i = 0; i < _boardSize; ++i)
        _piecesVector2D.push_back(QVector<Piece *>(_boardSize, nullptr));

    for (int i = 0; i < _boardSize ; ++i)
        for (int j = 0; j < _boardSize; ++j)
            makeNewPieceBySymbol(_piecesSymbolsVector2D[i][j], i, j);
}

// Public util functions
void BoardWidget::makeNewPieceBySymbol(char symbol, int i, int j)
{
    PiecesColors noColored = PiecesColors::NoColored;
    PiecesColors white = PiecesColors::White;
    PiecesColors black = PiecesColors::Black;

    switch (symbol)
    {
    case (char)PiecesSymbols::Empty:
        _piecesVector2D[i][j] = _piecesFactory->CreatePiece(Pieces::Empty, noColored, i, j, this);
        break;
    case (char)PiecesSymbols::WhitePawn:
        _piecesVector2D[i][j] = _piecesFactory->CreatePiece(Pieces::Pawn, white, i, j, this);
        break;
    case (char)PiecesSymbols::WhiteKnight:
        _piecesVector2D[i][j] = _piecesFactory->CreatePiece(Pieces::Knight, white, i, j, this);
        break;
    case (char)PiecesSymbols::WhiteBishop:
        _piecesVector2D[i][j] = _piecesFactory->CreatePiece(Pieces::Bishop, white, i, j, this);
        break;
    case (char)PiecesSymbols::WhiteRook:
        _piecesVector2D[i][j] = _piecesFactory->CreatePiece(Pieces::Rook, white, i, j, this);
        break;
    case (char)PiecesSymbols::WhiteQueen:
        _piecesVector2D[i][j] = _piecesFactory->CreatePiece(Pieces::Queen, white, i, j, this);
        break;
    case (char)PiecesSymbols::WhiteKing:
        _piecesVector2D[i][j] = _piecesFactory->CreatePiece(Pieces::King, white, i, j, this);
        break;
    case (char)PiecesSymbols::BlackPawn:
        _piecesVector2D[i][j] = _piecesFactory->CreatePiece(Pieces::Pawn, black, i, j, this);
        break;
    case (char)PiecesSymbols::BlackKnight:
        _piecesVector2D[i][j] = _piecesFactory->CreatePiece(Pieces::Knight, black, i, j, this);
        break;
    case (char)PiecesSymbols::BlackBishop:
        _piecesVector2D[i][j] = _piecesFactory->CreatePiece(Pieces::Bishop, black, i, j, this);
        break;
    case (char)PiecesSymbols::BlackRook:
        _piecesVector2D[i][j] = _piecesFactory->CreatePiece(Pieces::Rook, black, i, j, this);
        break;
    case (char)PiecesSymbols::BlackQueen:
        _piecesVector2D[i][j] = _piecesFactory->CreatePiece(Pieces::Queen, black, i, j, this);
        break;
    case (char)PiecesSymbols::BlackKing:
        _piecesVector2D[i][j] = _piecesFactory->CreatePiece(Pieces::King, black, i, j, this);
        break;
    default:
        _piecesVector2D[i][j] = _piecesFactory->CreatePiece(Pieces::Empty, noColored, i, j, this);
        break;
    }
}

void BoardWidget::clearBoardLayout()
{
    for (int i = 0; i < _boardSize; ++i)
        for (int j = 0; j < _boardSize; ++j)
            _boardLayout->removeWidget(_piecesVector2D[i][j]->getPieceLabel());
}

void BoardWidget::clearUnderLayout()
{
    for (int i = 0; i < _boardSize; ++i)
        for (int j = 0; j < _boardSize; ++j)
            _underLayerLayout->removeWidget(_underLayerVector2D[i][j]->getPieceLabel());
}

void BoardWidget::resetBoardLayout()
{
    for (int i = 0; i < _boardSize; ++i)
        for (int j = 0; j < _boardSize; ++j)
            _boardLayout->addWidget(_piecesVector2D[i][j]->getPieceLabel(), i, j);
}

//void BoardWidget::resetUnderLayerVector2D()
//{
//    for (int i = 0; i < _boardSize; ++i)
//        for (int j = 0; j < _boardSize; ++j)
//            _underLayerVector2D[i][j] = '0';
//}

void BoardWidget::getAllAvailStepsForColor(CharVector2D& allAvailStepsVector2D, CharVector2D& imitationVector2D, PiecesColors turn)
{
    if (turn == PiecesColors::Black)
        turn = PiecesColors::White;
    else
        turn = PiecesColors::Black;

    for (int i = 0; i < 8; ++i)
    {
        for (int j = 0; j < 8; ++j)
        {
            if (imitationVector2D[i][j] != (char)PiecesSymbols::Empty && imitationVector2D[i][j] != 'p' && imitationVector2D[i][j] != 'P')
            {
                auto belowPlayerColor = GameWidget::GetInstance()->getBelowPlayerColor();

                if (turn == PiecesColors::Black && !isupper(imitationVector2D[i][j]))
                    _piecesVector2D[i][j]->findAvailableSteps(allAvailStepsVector2D, imitationVector2D, turn, belowPlayerColor);
                else if (turn == PiecesColors::White && isupper(imitationVector2D[i][j]))
                    _piecesVector2D[i][j]->findAvailableSteps(allAvailStepsVector2D, imitationVector2D, turn, belowPlayerColor);
            }
        }
    }
}

// Getters
Piece* BoardWidget::getSelectedPiece() const
{
    return gSelectedPiece;
}

int BoardWidget::getBoardSize() const
{
    return _boardSize;
}

QWidget* BoardWidget::getUnderLayerWidget() const
{
    return _underLayerWidget;
}

QGridLayout* BoardWidget::getUnderLayerLayout() const
{
    return _underLayerLayout;
}

PieceVector2D& BoardWidget::getUnderLayerVector2D()
{
    return _underLayerVector2D;
}

CharVector2D& BoardWidget::getPossibleStepsVector2D()
{
    return _possibleStepsVector2D;
}

QGridLayout* BoardWidget::getBoardLayout() const
{
    return _boardLayout;
}

CharVector2D& BoardWidget::getPiecesSymbolsVector2D()
{
    return _piecesSymbolsVector2D;
}

PieceVector2D& BoardWidget::getPiecesVector2D()
{
    return _piecesVector2D;
}

PiecesColors BoardWidget::getTurn() const
{
    return _turn;
}

QMediaPlayer* BoardWidget::getMediaPlayer()
{
    return _mediaPlayer;
}

// Setters
void BoardWidget::setCheckPosition(int i, int j)
{
    _checkPosition.row = i;
    _checkPosition.column = j;
}

void BoardWidget::setPromotedPawnPosition(int i, int j)
{
    _promotedPawnPos.row = i;
    _promotedPawnPos.column = j;
}

void BoardWidget::setValueInSymbolsVector2D(int i, int j, char value)
{
    _piecesSymbolsVector2D[i][j] = value;
}

// Private util functions
void BoardWidget::makeBoardWidget()
{
    _mediaPlayer->setAudioOutput(_audioOutput);
    _mediaPlayer->setSource(QUrl::fromLocalFile(Sounds::StartGameSound));
    _audioOutput->setVolume(50);

    // Set under layer geometry
    _underLayerWidget->setGeometry(0, 0, (int)BoardWidgetProps::BoardWidgetW, (int)BoardWidgetProps::BoardWidgetH);

    // Make layouts
    for (int i = 0; i < _boardSize; ++i)
    {
        for (int j = 0; j < _boardSize; ++j)
        {
            // Make board layout
            _boardLayout->addWidget(_piecesVector2D[i][j]->getPieceLabel(), i, j);

            // Make under layer layout
            _underLayerLayout->addWidget(_underLayerVector2D[i][j]->getPieceLabel(), i, j);
        }
    }

    _underLayerLayout->setVerticalSpacing(0);
    _underLayerLayout->setHorizontalSpacing(0);

    _boardLayout->setVerticalSpacing(0);
    _boardLayout->setHorizontalSpacing(0);
    setLayout(_boardLayout);
}

void BoardWidget::setTurn(PiecesColors turn)
{
    _turn = turn;
}

void BoardWidget::setIsChecked(bool isChecked)
{
    _isChecked = isChecked;
}

void BoardWidget::setIsCheckedKingSelected(bool isSelected)
{
    _isCheckedKingSelected = isSelected;
}

void BoardWidget::setIsPawnPromoted(bool isPromoted)
{
    _isPawnPromoted = isPromoted;
}

void BoardWidget::setHordPiecesCount(int count)
{
    _hordePiecesCount = count;
}

void BoardWidget::setWhiteKingCheckCount(int count)
{
    _whiteKingCheckCount = count;
}

void BoardWidget::setBlackKingCheckCount(int count)
{
    _blackKingCheckCount = count;
}





































// Game functions
void BoardWidget::processLeftButtonClick(Piece* clickedPiece)
{
    bool isDoStep = false;

    // No piece selected
    _isCheckedKingSelected = false;

    if (!isPieceSelected())
    {
        // if clicked right color piece
        if (isCorrectColoredPieceClicked(clickedPiece))
        {
            clearStepsVector2D();
            selectPiece(clickedPiece);
        }
    }
    else
    {
        // if click other piece with same color
        if (isCorrectColoredPieceClicked(clickedPiece) && !isSelectedPieceClicked(clickedPiece))
        {
            clearStepsVector2D();
            selectPiece(clickedPiece);
        }
        // if clicked not available steps
        else if (!isAvailableStepClicked(clickedPiece->getPositionRow(), clickedPiece->getPositionColumn()))
        {
            gSelectedPiece = nullptr;
            clearStepsVector2D();
        }
        else // Clicked available step
        {
            doStep(clickedPiece);
            clearStepsVector2D();
            isDoStep = true;
            switchTurn();
        }
    }

    // If pawn promotion exist, pop-up dialog
    if (_isPawnPromoted)
        showPawnPromDialog();

    if (isDoStep)
    {
            auto pieceSymbol = gSelectedPiece->getPieceSymbol();
            auto posFrom =  gSelectedPiece->getPosition();
            auto posTo = clickedPiece->getPosition();
            auto isCheck = isChecked();
            bool isHit = false;

            if (clickedPiece->getPieceSymbol() != (char)PiecesSymbols::Empty && clickedPiece->getPieceSymbol() != 0)
                isHit = true;

            if (isHit && GameWidget::GetInstance()->getGameData().gameVariant == GameVariants::Horde
                    && clickedPiece->getPieceSymbol() == (char)PiecesSymbols::WhitePawn)
                _hordePiecesCount -= 1;

            MovesWidget::GetInstance()->addMoveForColor(pieceSymbol, posFrom, posTo, isCheck,
                     isHit, _isPawnPromoted, _piecesSymbolsVector2D[_promotedPawnPos.row][_promotedPawnPos.column], _turn);
            gSelectedPiece = nullptr;
    }

    // If king checked, mark it in stepsVector2D
    if (isChecked())
        drawCheck();

    //if (!isFirstStep)
        //drawPreviousStep();
    drawUnderLayer();

    // Sound
    if (isDoStep && gSound)
    {
        if (isPiece(clickedPiece->getPieceSymbol()))
            _boardWidget->getMediaPlayer()->setSource(QUrl::fromLocalFile(Sounds::Beat));
        else
            _boardWidget->getMediaPlayer()->setSource(QUrl::fromLocalFile(Sounds::Go));
        _boardWidget->getMediaPlayer()->play();
    }

    // Verify checkmate and stalemate
    if (isDoStep)
    {
        verifyCheckmateAndStalemate();
        if (GameWidget::GetInstance()->getGameData().gameVariant == GameVariants::KingOfTheHill)
            checkKingOfTheHill();
    }

    if (_hordePiecesCount <= 0)
        endGame(_turn, false);

    if (_blackKingCheckCount >= 3 || _whiteKingCheckCount >= 3)
        endGame(_turn, false);
}

// Private game functions
void BoardWidget::selectPiece(Piece* clickedPiece)
{
    gSelectedPiece = clickedPiece;
    drawSelectedPieceSquare();
    auto belowPlayerColor = GameWidget::GetInstance()->getBelowPlayerColor();
    gSelectedPiece->findAvailableSteps(_possibleStepsVector2D, _piecesSymbolsVector2D, _turn, belowPlayerColor);

    if (gSelectedPiece->isKing(_piecesSymbolsVector2D, gSelectedPiece->getPositionRow(), gSelectedPiece->getPositionColumn()) && isChecked())
        _isCheckedKingSelected = true;
}

void BoardWidget::doStep(Piece* clickedPiece)
{
    int iSelected = gSelectedPiece->getPositionRow();
    int jSelected = gSelectedPiece->getPositionColumn();
    int iClicked = clickedPiece->getPositionRow();
    int jClicked = clickedPiece->getPositionColumn();

    // Do step in board layout
    clearBoardLayout();
    doStepInSymbolsVector(iSelected, jSelected, iClicked, jClicked);
    doStepInPiecesVector(iSelected, jSelected, iClicked, jClicked);
    resetBoardLayout();

    _isChecked = false;
    if (!isPiece(gSelectedPiece, PiecesTypes::King))
    {
        // Verify check
        verifyCheck();

        // Verify pawn promotion
        checkPawnPromotion(iClicked, jClicked);
    }
}

void BoardWidget::checkKingOfTheHill()
{
    auto symbol1 = _piecesSymbolsVector2D[3][3];
    auto symbol2 = _piecesSymbolsVector2D[3][4];
    auto symbol3 = _piecesSymbolsVector2D[4][3];
    auto symbol4 = _piecesSymbolsVector2D[4][4];

    if (symbol1 == (char)PiecesSymbols::WhiteKing || symbol2 == (char)PiecesSymbols::WhiteKing
            || symbol3 == (char)PiecesSymbols::WhiteKing || symbol4 == (char)PiecesSymbols::WhiteKing)
        endGame(_turn, false);

    if (symbol1 == (char)PiecesSymbols::BlackKing || symbol2 == (char)PiecesSymbols::BlackKing
            || symbol3 == (char)PiecesSymbols::BlackKing || symbol4 == (char)PiecesSymbols::BlackKing)
        endGame(_turn, false);
}

void BoardWidget::verifyCheckmateAndStalemate()
{
    CharVector2D allAvailStepsVector2D;
    allAvailStepsVector2D.reserve(8);
    for (int i = 0; i < 8; ++i)
        allAvailStepsVector2D.push_back(QVector<char>(8, (char)PossibleSteps::Empty));

    Piece* selectedPiece = gSelectedPiece;
    switchTurn();

    CharVector2D stepsVector2D;
    stepsVector2D.reserve(8);
    for (int i = 0; i < 8; ++i)
        stepsVector2D.push_back(QVector<char>(8, (char)PossibleSteps::Empty));
    copyVector2D(stepsVector2D, _piecesSymbolsVector2D, 8);

    auto turn = getOppositeTurn(_turn);
    auto belowPlayerColor = GameWidget::GetInstance()->getBelowPlayerColor();
    for (int i = 0; i < (int)_boardSize; ++i)
    {
        for (int j = 0; j < (int)_boardSize; ++j)
        {
            if (turn == PiecesColors::Black && !isupper(_piecesSymbolsVector2D[i][j]))
            {
                gSelectedPiece = _piecesVector2D[i][j];
                _piecesVector2D[i][j]->findAvailableSteps(_possibleStepsVector2D, _piecesSymbolsVector2D, turn, belowPlayerColor);
            }
            else if (turn == PiecesColors::White && isupper(_piecesSymbolsVector2D[i][j]))
            {
                gSelectedPiece = _piecesVector2D[i][j];
                _piecesVector2D[i][j]->findAvailableSteps(_possibleStepsVector2D, _piecesSymbolsVector2D, turn, belowPlayerColor);
            }

            addToAllStepsVector2D(allAvailStepsVector2D, _possibleStepsVector2D);
            resetCharVector2D(_possibleStepsVector2D, 8, (char)PossibleSteps::Empty);
            gSelectedPiece = selectedPiece;
        }
    }

    bool isStepsAvail = false;
    for (int i = 0; i < (int)_boardSize; ++i)
    {
        for (int j = 0; j < (int)_boardSize; ++j)
        {
            if (allAvailStepsVector2D[i][j] == (char)PossibleSteps::CanGo || allAvailStepsVector2D[i][j] == (char)PossibleSteps::CanBeat)
                isStepsAvail = true;
        }
    }

    if (isStepsAvail == false)
    {
        if (isChecked())
        {
            endGame(turn, false);
            return;
        }

        endGame(turn, false);
    }

    switchTurn();
}

PiecesColors BoardWidget::getOppositeTurn(PiecesColors turn)
{
    if (turn == PiecesColors::White)
        return PiecesColors::Black;
    else
        return PiecesColors::White;
}

void BoardWidget::addToAllStepsVector2D(CharVector2D& allAvailStepsVector2D, CharVector2D& possibleStepsVector2D)
{
    for (int i = 0; i < 8; ++i)
        for (int j = 0; j < 8; ++j)
            if (possibleStepsVector2D[i][j] != (char)PossibleSteps::Empty && allAvailStepsVector2D[i][j] == (char)PossibleSteps::Empty)
                allAvailStepsVector2D[i][j] = possibleStepsVector2D[i][j];
}

void BoardWidget::endGame(PiecesColors turn, bool isStalemate)
{
    QString text;

    if (isStalemate)
        text = "Stalemate!";
    else
    {
        if (turn == PiecesColors::Black)
            text = "White player win!";
        else
            text = "Black player win!";
    }

    switchTurn();

//    for (int i = 0; i < (int)_boardSize; ++i)
//        for (int j = 0; j < (int)_boardSize; ++j)
//            _piecesVector2D[i][j]->getPieceLabel()->disconnect();

    //int i = _promotedPawnPos.row;
    //int j = _promotedPawnPos.column;
    if (!gIsTimeEnded)
    {
        auto& vector2D = MovesWidget::GetInstance()->getMovesVector2d();
        if (_turn == PiecesColors::Black)
        {
            auto text = vector2D[vector2D.size() - 1][1]->text();
            text.chop(1);
            //text += _piecesVector2D[i][j]->getPieceSymbol();
            text += '#';
            vector2D[vector2D.size() - 1][1]->setText(text);
        }
        else
        {
            auto text = vector2D[vector2D.size() - 1][2]->text();
            text.chop(1);
            //text += _piecesVector2D[i][j]->getPieceSymbol();
            text += '#';
            vector2D[vector2D.size() - 1][1]->setText(text);
        }
    }

    QMessageBox::information(this, "End game", text);
}

void BoardWidget::showPawnPromDialog()
{
    _pawnPromDialog->setModal(true);
    switchTurn();
    _pawnPromDialog->makePawnPromDialog(_turn);
    _pawnPromDialog->show();
    //_pawnPromDialog->exec();
}

void BoardWidget::doPawnProm(PiecesTypes pieceType)
{
    _pawnPromDialog->hide();
    _isPawnPromoted = false;

    int i = _promotedPawnPos.row;
    int j = _promotedPawnPos.column;

    PiecesColors color = _piecesVector2D[i][j]->getPieceColor();

    if (color == PiecesColors::White)
        _piecesSymbolsVector2D[i][j] = toupper((char)pieceType);
    else
        _piecesSymbolsVector2D[i][j] = (char)pieceType;

    clearBoardLayout();
    delete _piecesVector2D[i][j];
    switch (pieceType)
    {
    case PiecesTypes::Queen:
        _piecesVector2D[i][j] = _piecesFactory->CreatePiece(Pieces::Queen, color, i, j, this);
        break;
    case PiecesTypes::Rook:
        _piecesVector2D[i][j] = _piecesFactory->CreatePiece(Pieces::Rook, color, i, j, this);
        break;
    case PiecesTypes::Bishop:
        _piecesVector2D[i][j] = _piecesFactory->CreatePiece(Pieces::Bishop, color, i, j, this);
        break;
    case PiecesTypes::Knight:
        _piecesVector2D[i][j] = _piecesFactory->CreatePiece(Pieces::Knight, color, i, j, this);
        break;
    default:
        _piecesVector2D[i][j] = _piecesFactory->CreatePiece(Pieces::Queen, color, i, j, this);
        break;
    }
    resetBoardLayout();

    // Verify check
    gSelectedPiece = _piecesVector2D[i][j];
    verifyCheck();

    // If king checked, mark it in stepsVector2D
    if (isChecked())
        drawCheck();

    //if (!isFirstStep)
        //drawPreviousStep();
    drawUnderLayer();

    auto& vector2D = MovesWidget::GetInstance()->getMovesVector2d();
    if (_turn == PiecesColors::White)
    {
        auto text = vector2D[vector2D.size() - 1][1]->text();
        text.chop(1);
        text += _piecesVector2D[i][j]->getPieceSymbol();
        if (_isChecked)
            text += "+";
        vector2D[vector2D.size() - 1][1]->setText(text);
    }
    else
    {
        auto text = vector2D[vector2D.size() - 1][2]->text();
        text.chop(1);
        text += _piecesVector2D[i][j]->getPieceSymbol();
        if (_isChecked)
            text += "+";
        vector2D[vector2D.size() - 1][1]->setText(text);
    }

    switchTurn();
}

void BoardWidget::verifyCheck()
{
    selectPiece(gSelectedPiece);
    if(gSelectedPiece->isGivingCheck(_possibleStepsVector2D, _piecesSymbolsVector2D, _turn))
    {
        _isChecked = true;

        if (GameWidget::GetInstance()->getGameVariant() == GameVariants::ThreeCheck)
        {
            if (_piecesSymbolsVector2D[_checkPosition.row][_checkPosition.column] == (char)PiecesSymbols::BlackKing)
                _blackKingCheckCount += 1;
            else
                _whiteKingCheckCount += 1;
        }
    }

    clearStepsVector2D();
}

void BoardWidget::checkPawnPromotion(int i, int j)
{
    if (isPiece(_piecesVector2D[i][j], PiecesTypes::Pawn) && (i ==  0 || i == 7))
    {
        _isPawnPromoted = true;
        setPromotedPawnPosition(i, j);
    }
}

void BoardWidget::doStepInSymbolsVector(int iSelected, int jSelected, int iClicked, int jClicked)
{
    auto temp = _piecesSymbolsVector2D[iSelected][jSelected];
    _piecesSymbolsVector2D[iSelected][jSelected] = (char)PiecesSymbols::Empty;
    _piecesSymbolsVector2D[iClicked][jClicked] = temp;
}

void BoardWidget::doStepInPiecesVector(int iSelected, int jSelected, int iClicked, int jClicked)
{
    delete _piecesVector2D[iClicked][jClicked];
    _piecesVector2D[iClicked][jClicked] = _piecesVector2D[iSelected][jSelected];
    _piecesVector2D[iClicked][jClicked]->setPosition(iClicked, jClicked);

    _piecesVector2D[iSelected][jSelected] = _piecesFactory->CreatePiece(Pieces::Empty, PiecesColors::NoColored, iSelected, jSelected, this);
}

void BoardWidget::switchTurn()
{
    if (_turn == PiecesColors::White)
        _turn = PiecesColors::Black;
    else
        _turn = PiecesColors::White;
}

void BoardWidget::clearStepsVector2D()
{
    for (int i = 0; i < _boardSize; ++i)
        for (int j = 0; j < _boardSize; ++j)
            _possibleStepsVector2D[i][j] = (char)PiecesTypes::Empty;
}

void BoardWidget::clearStepsVector2DExceptCheck()
{
    for (int i = 0; i < _boardSize; ++i)
        for (int j = 0; j < _boardSize; ++j)
        {
            if (_possibleStepsVector2D[i][j] == (char)PossibleSteps::Check)
                continue;
            else
                _possibleStepsVector2D[i][j] = (char)PossibleSteps::Empty;
        }
}

void BoardWidget::drawSelectedPieceSquare()
{
    _possibleStepsVector2D[gSelectedPiece->getPositionRow()][gSelectedPiece->getPositionColumn()] = (char)PossibleSteps::CurrentPiece;
}

void BoardWidget::drawCheck()
{
    _possibleStepsVector2D[_checkPosition.row][_checkPosition.column] = (char)PossibleSteps::Check;

    if (_isCheckedKingSelected)
        _possibleStepsVector2D[_checkPosition.row][_checkPosition.column] = (char)PossibleSteps::CurrentPieceAndCheck;
}

void BoardWidget::drawUnderLayer()
{
    QPixmap temp;
    for (int i = 0; i < _boardSize; ++i)
    {
        for (int j = 0; j < _boardSize; ++j)
        {
            switch (_possibleStepsVector2D[i][j])
            {
            case (char)PossibleSteps::Empty: _underLayerVector2D[i][j]->getPieceLabel()->setPixmap(temp); break;
            case (char)PossibleSteps::CanGo: _underLayerVector2D[i][j]->getPieceLabel()->setPixmap(QPixmap(StepsImages::CanGo)); break;
            case (char)PossibleSteps::CanBeat: _underLayerVector2D[i][j]->getPieceLabel()->setPixmap(QPixmap(StepsImages::CanBeat)); break;
            case (char)PossibleSteps::CurrentPiece: _underLayerVector2D[i][j]->getPieceLabel()->setPixmap(QPixmap(StepsImages::CurrentPiece)); break;
            case (char)PossibleSteps::LastStepFrom: _underLayerVector2D[i][j]->getPieceLabel()->setPixmap(QPixmap(StepsImages::LastStepFrom)); break;
            case (char)PossibleSteps::LastStepTo: _underLayerVector2D[i][j]->getPieceLabel()->setPixmap(QPixmap(StepsImages::LastStepTo)); break;
            case (char)PossibleSteps::LastStepFromAndCanGo: _underLayerVector2D[i][j]->getPieceLabel()->setPixmap(QPixmap(StepsImages::LastStepFromAndCanGo)); break;
            case (char)PossibleSteps::Check: _underLayerVector2D[i][j]->getPieceLabel()->setPixmap(QPixmap(StepsImages::Check)); break;
            case (char)PossibleSteps::CurrentPieceAndCheck: _underLayerVector2D[i][j]->getPieceLabel()->setPixmap(QPixmap(StepsImages::CurrentPieceAndChecked)); break;
            default: _underLayerVector2D[i][j]->getPieceLabel()->setPixmap(temp); break;
            }
        }
    }
}

bool BoardWidget::isPieceSelected()
{
    return (gSelectedPiece != nullptr);
}

bool BoardWidget::isSelectedPieceClicked(Piece *clickedPiece)
{
    int i = clickedPiece->getPositionRow();
    int j = clickedPiece->getPositionColumn();
    return (_possibleStepsVector2D[i][j] == (char)PossibleSteps::CurrentPiece || _possibleStepsVector2D[i][j] == (char)PossibleSteps::CurrentPieceAndCheck);
}

bool BoardWidget::isEmptyClicked(Piece *clickedPiece)
{
    return (clickedPiece->getPieceType() == PiecesTypes::Empty);
}

bool BoardWidget::isOppositePieceClicked(Piece *clickedPiece)
{
    return (clickedPiece->getPieceColor() != _turn);
}

bool BoardWidget::isCorrectColoredPieceClicked(Piece *clickedPiece)
{
    return (!isEmptyClicked(clickedPiece) && !isOppositePieceClicked(clickedPiece));
}

bool BoardWidget::isAvailableStepClicked(int i, int j)
{
    char symbol = _possibleStepsVector2D[i][j];
    return (symbol == (char)PossibleSteps::CanGo || symbol == (char)PossibleSteps::CanBeat
            || symbol == (char)PossibleSteps::LastStepFromAndCanGo);
}

bool BoardWidget::isChecked()
{
    return _isChecked;
}

bool BoardWidget::isPiece(Piece* piece, PiecesTypes pieceType)
{
    return (piece->getPieceType() == pieceType);
}

bool BoardWidget::isPiece(char symbol)
{
    if (symbol == (char)PiecesSymbols::WhitePawn || symbol == (char)PiecesSymbols::WhiteKnight || symbol == (char)PiecesSymbols::WhiteBishop ||
        symbol == (char)PiecesSymbols::WhiteRook || symbol == (char)PiecesSymbols::WhiteQueen || symbol == (char)PiecesSymbols::WhiteKing ||
        symbol == (char)PiecesSymbols::BlackPawn || symbol == (char)PiecesSymbols::BlackKnight || symbol == (char)PiecesSymbols::BlackBishop ||
        symbol == (char)PiecesSymbols::BlackRook || symbol == (char)PiecesSymbols::BlackQueen || symbol == (char)PiecesSymbols::BlackKing)
                return true;
    return false;
}
