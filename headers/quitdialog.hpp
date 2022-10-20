#ifndef QUITDIALOG_HPP
#define QUITDIALOG_HPP

#include <QDialog>
#include <QDialogButtonBox>

#include "helpers.hpp"

QT_BEGIN_NAMESPACE
namespace Ui { class QuitDialog; }
QT_END_NAMESPACE

class QuitDialog : public QDialog
{
    Q_OBJECT

public:
    explicit QuitDialog(QWidget *parent = nullptr);
    ~QuitDialog();

private slots:

private:
    // Setups
    void setup();

private:
    Ui::QuitDialog *ui;

    // QuitDialog attrbutes
    QDialogButtonBox *quitButtonBox;
};

#endif // QUITDIALOG_HPP
