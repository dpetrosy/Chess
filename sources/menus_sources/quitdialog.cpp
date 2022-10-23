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
    quitImage = new QLabel(this);
    quitText = new QLabel("Are you sure you want to exit?", this);
    quitButtonBox = new QDialogButtonBox(QDialogButtonBox::Yes | QDialogButtonBox::Cancel, this);
}

// Utils functions
void QuitDialog::makeQuitDialog()
{
    // Set quitImage props
    QPixmap image(QPixmap(ImagesPaths::imagesPath + "quit.png"));
    quitImage->setPixmap(image);
    quitImage->setGeometry((int)QuitDialogProps::quitImageX, (int)QuitDialogProps::quitImageY, image.rect().width(), image.rect().height());


    // Set quitText props
    quitText->setGeometry((int)QuitDialogProps::quitTextX, (int)QuitDialogProps::quitTextY, (int)QuitDialogProps::quitTextW, (int)QuitDialogProps::quitTextH);
    quitText->setStyleSheet("font: 16pt 'Sylfaen';");

    // Set quitButtonBox props
    quitButtonBox->setGeometry((int)QuitDialogProps::quitButtonBoxX, (int)QuitDialogProps::quitButtonBoxY, (int)QuitDialogProps::quitButtonBoxW, (int)QuitDialogProps::quitButtonBoxH);
}

QDialogButtonBox *QuitDialog::getQDialogButtonBox()
{
    return quitButtonBox;
}
