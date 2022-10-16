#ifndef QUITDIALOG_HPP
#define QUITDIALOG_HPP

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class QuitDialog; }
QT_END_NAMESPACE

enum class QuitDialogSizes
{
    windowSizeHorizontal = 444,
    windowSizeVerticale = 130
};

class QuitDialog : public QDialog
{
    Q_OBJECT

public:
    explicit QuitDialog(QWidget *parent = nullptr);
    virtual ~QuitDialog();

private slots:
    void on_quit_dialog_option_accepted();

private:
    Ui::QuitDialog *ui;
};

#endif // QUITDIALOG_HPP
