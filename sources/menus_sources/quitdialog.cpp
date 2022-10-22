#include "quitdialog.hpp"
#include "ui_quitdialog.h"

QuitDialog::QuitDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QuitDialog)
{
    // Set QuitDialog size
    this->setFixedSize((int)QuitDialogProps::windowSizeW, (int)QuitDialogProps::windowSizeH);
    ui->setupUi(this);

    // Setup class members
    setup();

    // Make QuitDialog
    makeQuitDialog();

    // Set title
    setWindowTitle("Quit");

    // Set Icon
    setWindowIcon(QIcon(ImagesPaths::logosPath + "logo.png"));
}

QuitDialog::~QuitDialog() {}

// Setups
void QuitDialog::setup()
{
    // QuitDialog attrbutes
    quitText = new QLabel("Are you sure you want to exit?", this);
    //quitText->setAlignment(Qt::AlignCenter);
    //quitImage = new QLabel(this);
    //quitImage->setStyleSheet(ImagesPaths::imagesPath + "quit.png");
    //quitButtonBox = new QDialogButtonBox(QDialogButtonBox::Yes | QDialogButtonBox::Cancel, this);
}

// Utils functions
void QuitDialog::makeQuitDialog()
{
    // Set quitImage props
    quitImage->setGeometry((int)QuitDialogProps::quitImageX, (int)QuitDialogProps::quitImageY, (int)QuitDialogProps::quitImageW, (int)QuitDialogProps::quitImageH);

    // Set quitText props
    //quitText->setGeometry((int)QuitDialogProps::quitTextX, (int)QuitDialogProps::quitTextY, (int)QuitDialogProps::quitTextW, (int)QuitDialogProps::quitTextH);



//    setPushButtonSize(PlayButton, (int)PVPMenuProps::PlayButtonW, (int)PVPMenuProps::PlayButtonH);
//    setPushButtonSize(ReturnButton, (int)PVPMenuProps::ReturnButtonW, (int)PVPMenuProps::ReturnButtonH);

//    // Set buttons positions
//    PlayButton->move((int)PVPMenuProps::PlayButtonX, (int)PVPMenuProps::PlayButtonY);
//    ReturnButton->move((int)PVPMenuProps::ReturnButtonX, (int)PVPMenuProps::ReturnButtonY);

//    // Set buttons fonts
//    setPushButtonFont(PlayButton, (int)PVPMenuProps::PlayButtonFont);
//    setPushButtonFont(ReturnButton, (int)PVPMenuProps::ReturnButtonFont);
}
