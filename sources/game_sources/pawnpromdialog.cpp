#include "pawnpromdialog.hpp"
#include "game_helpers.hpp"
#include "boardwidget.hpp"
#include "helpers.hpp"

PawnPromDialog::PawnPromDialog(QWidget *parent) :
    QDialog(parent)
{
    // Set PawnPromDialog size
    this->setFixedSize((int)PawnPromDialogProps::windowSizeW, (int)PawnPromDialogProps::windowSizeH);

    // Init class members
    init();

    // Set title
    setWindowTitle("Choose Piece");

    // Set Icon
    setWindowIcon(QIcon(ImagesPaths::logosPath + "logo.png"));
}

PawnPromDialog::~PawnPromDialog()
{
    delete _queenPushButton;
    delete _rookPushButton;
    delete _bishopPushButton;
    delete _knightPushButton;
}

// Init
void PawnPromDialog::init()
{
    // PawnPromDialog attrbutes
    _queenPushButton = new QPushButton(this);
    _rookPushButton = new QPushButton(this);
    _bishopPushButton = new QPushButton(this);
    _knightPushButton = new QPushButton(this);
}

// Public util functions
void PawnPromDialog::keyPressEvent(QKeyEvent *event)
{
   if (event->key() == Qt::Key_Escape)
      return;

   QDialog::keyPressEvent(event);
}

void PawnPromDialog::makePawnPromDialog(PiecesColors turn)
{
    // Hide window close button
    setWindowFlags(windowFlags() & ~Qt::WindowCloseButtonHint);

    // Make Pieces Push Buttons
    QString colorString = "white";
    if (turn == PiecesColors::Black)
        colorString = "black";

    QFile file(Paths::pawnPromButtonsStyle);
    file.open(QFile::ReadOnly);
    QString styleSheet = QLatin1String(file.readAll());
    file.close();

    // Queen
    QPixmap pixmap(ImagesPaths::piecesPath + colorString + "_queen.png");
    QIcon buttonIcon(pixmap);
    _queenPushButton->setIcon(buttonIcon);
    _queenPushButton->setIconSize(pixmap.rect().size());
    _queenPushButton->setStyleSheet(styleSheet);
    _queenPushButton->move((int)PawnPromDialogProps::QueenPosX, (int)PawnPromDialogProps::QueenPosY);

    // Rook
    pixmap.load(ImagesPaths::piecesPath + colorString + "_rook.png");
    buttonIcon.addPixmap(pixmap);
    _rookPushButton->setIcon(buttonIcon);
    _rookPushButton->setIconSize(pixmap.rect().size());
    _rookPushButton->setStyleSheet(styleSheet);
    _rookPushButton->move((int)PawnPromDialogProps::RookPosX, (int)PawnPromDialogProps::RookPosY);

    // Bishop
    pixmap.load(ImagesPaths::piecesPath + colorString + "_bishop.png");
    buttonIcon.addPixmap(pixmap);
    _bishopPushButton->setIcon(buttonIcon);
    _bishopPushButton->setIconSize(pixmap.rect().size());
    _bishopPushButton->setStyleSheet(styleSheet);
    _bishopPushButton->move((int)PawnPromDialogProps::BishopPosX, (int)PawnPromDialogProps::BishopPosY);

    // Knight
    pixmap.load(ImagesPaths::piecesPath + colorString + "_knight.png");
    buttonIcon.addPixmap(pixmap);
    _knightPushButton->setIcon(buttonIcon);
    _knightPushButton->setIconSize(pixmap.rect().size());
    _knightPushButton->setStyleSheet(styleSheet);
    _knightPushButton->move((int)PawnPromDialogProps::KnightPosX, (int)PawnPromDialogProps::KnightPosY);

    // Connects
    connect(_queenPushButton, &QPushButton::clicked, this, std::bind(&BoardWidget::doPawnProm, BoardWidget::GetInstance(), PiecesTypes::Queen));
    connect(_rookPushButton, &QPushButton::clicked, this, std::bind(&BoardWidget::doPawnProm, BoardWidget::GetInstance(), PiecesTypes::Rook));
    connect(_bishopPushButton, &QPushButton::clicked, this, std::bind(&BoardWidget::doPawnProm, BoardWidget::GetInstance(), PiecesTypes::Bishop));
    connect(_knightPushButton, &QPushButton::clicked, this, std::bind(&BoardWidget::doPawnProm, BoardWidget::GetInstance(), PiecesTypes::Knight));
}
