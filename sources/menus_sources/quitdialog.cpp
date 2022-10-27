#include "quitdialog.hpp"
#include "ui_quitdialog.h"
#include "menus_helpers.hpp"

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

// Setup
void QuitDialog::setup()
{
    // QuitDialog attrbutes
    _quitImage = new QLabel(this);
    _quitText = new QLabel("Are you sure you want to exit?", this);
    _quitButtonBox = new QDialogButtonBox(QDialogButtonBox::Yes | QDialogButtonBox::Cancel, this);
}

// Public util functions
QDialogButtonBox *QuitDialog::getQDialogButtonBox()
{
    return _quitButtonBox;
}

// Private util functions
void QuitDialog::makeQuitDialog()
{
    // Set quitImage props
    QPixmap image(QPixmap(ImagesPaths::imagesPath + "quit.png"));
    _quitImage->setPixmap(image);
    _quitImage->setGeometry((int)QuitDialogProps::quitImageX, (int)QuitDialogProps::quitImageY, image.rect().width(), image.rect().height());

    // Set quitText props
    _quitText->setGeometry((int)QuitDialogProps::quitTextX, (int)QuitDialogProps::quitTextY, (int)QuitDialogProps::quitTextW, (int)QuitDialogProps::quitTextH);
    _quitText->setStyleSheet("font: 16pt 'Sylfaen';");

    // Set quitButtonBox props
    _quitButtonBox->setGeometry((int)QuitDialogProps::quitButtonBoxX, (int)QuitDialogProps::quitButtonBoxY, (int)QuitDialogProps::quitButtonBoxW, (int)QuitDialogProps::quitButtonBoxH);
}
