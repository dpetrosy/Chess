#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include <QStackedWidget>
#include <QPalette>
#include <QWidget>
#include <QPixmap>
#include <QLabel>
#include <QImage>

#include "helpers.hpp"
#include "quitdialog.hpp"
#include "boardwidget.hpp"
#include "gamewidget.hpp"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    virtual ~MainWindow();

private slots:
    // Member functions
    void setup();
    void setBackgroundImage(const QString& image);

    // Main menu buttons
    void on_PVPbutton_clicked();
    void on_quitButton_clicked();

    // PVP menu buttons
    void on_PVPMenuPlayButton_clicked();
    void on_PVPMenuReturnButton_clicked();

    // StackedWidget maker
    template <typename T, typename... Types>
    void makeStackedWidget(QStackedWidget *stackedWidget, T widget, Types... arg2)
    {
        stackedWidget->addWidget(widget);

        return makeStackedWidget(stackedWidget, arg2...);
    }

    void makeStackedWidget(QStackedWidget *stackedWidget)
    {
        (void) stackedWidget;
        return;
    }

private:
    Ui::MainWindow *ui;

    // images
    QString imagesPath;
    QString piecesPath;
    QString logosPath;
    QString backgroundsPath;
    QPixmap backgroundImage;
    QPalette palette;

    // Main menu attributes
    QWidget *mainMenu;
    QuitDialog *quitDialog;

    // PVP StackedWidget attributes
    QStackedWidget *stackedWidgetPVP;
    QWidget *PVPMenu;

    // Chess game attributes
    GameWidget *gameWidget;





    QWidget *wid;
    QStackedWidget *widget;
};

#endif // MAINWINDOW_HPP
