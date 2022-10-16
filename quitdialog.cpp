#include "quitdialog.hpp"
#include "ui_quitdialog.h"

QuitDialog::QuitDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QuitDialog)
{
    this->setFixedSize((int)QuitDialogSizes::windowSizeHorizontal, (int)QuitDialogSizes::windowSizeVerticale);
    ui->setupUi(this);
}

QuitDialog::~QuitDialog() {}

void QuitDialog::on_quit_dialog_option_accepted()
{
    exit(0);
}

