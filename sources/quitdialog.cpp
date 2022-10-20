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
}

QuitDialog::~QuitDialog() {}

// Setups
void QuitDialog::setup()
{
    // QuitDialog attrbutes
    quitButtonBox = new QDialogButtonBox(this);
    quitButtonBox->setGeometry(10, 10, 50, 50);
}




//void QuitDialog::on_quit_dialog_option_accepted()
//{
//    exit(0);
//}

