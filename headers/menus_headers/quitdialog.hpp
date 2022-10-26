#ifndef QUITDIALOG_HPP
#define QUITDIALOG_HPP

#include <QDialog>
#include <QLabel>
#include <QDebug>
#include <QDialogButtonBox>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class QuitDialog; }
QT_END_NAMESPACE

class QuitDialog : public QDialog
{
    Q_OBJECT

public:
    explicit QuitDialog(QWidget *parent = nullptr);
    virtual ~QuitDialog();

    // Public util functions
    QDialogButtonBox *getQDialogButtonBox();

private:
    // Setup
    void setup();

    // Private util functions
    void makeQuitDialog();

private:
    Ui::QuitDialog *ui;

    // QuitDialog objects
    QLabel *quitImage;
    QLabel *quitText;
    QDialogButtonBox *quitButtonBox;
};

#endif // QUITDIALOG_HPP
