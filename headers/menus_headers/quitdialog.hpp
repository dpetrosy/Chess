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
    QDialogButtonBox*   getQDialogButtonBox();

private:
    // Init
    void    init();

    // Private util functions
    void    makeQuitDialog();

private:
    // QuitDialog objects
    QLabel*             _quitImage;
    QLabel*             _quitText;
    QDialogButtonBox*   _quitButtonBox;
};

#endif // QUITDIALOG_HPP
