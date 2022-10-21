#ifndef QUITDIALOG_HPP
#define QUITDIALOG_HPP

#include <QDialog>
#include <QDialogButtonBox>

#include "menus_helpers.hpp"

QT_BEGIN_NAMESPACE
namespace Ui { class QuitDialog; }
QT_END_NAMESPACE

class QuitDialog : public QDialog
{
    Q_OBJECT

public:
    explicit QuitDialog(QWidget *parent = nullptr);
    virtual ~QuitDialog();

private:
    // Setups
    void setup();

    // Utils functions
    void makeQuitDialog();

private:
    Ui::QuitDialog *ui;

    // QuitDialog attrbutes
    //QDialogButtonBox *quitButtonBox;
};

#endif // QUITDIALOG_HPP
