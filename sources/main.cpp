#include <QApplication>
#include <QDebug>

#include "mainwindow.hpp"

int main(int argc, char *argv[])
{
    //QApplication::setAttribute(Qt::AA_EnableHighDpiScaling); // DPI support
    //QCoreApplication::setAttribute(Qt::AA_UseHighDpiPixmaps); //HiDPI pixmaps

    QString logoImagePath = ":/images/images/logos/logo1.png";

    QApplication a(argc, argv);
    a.setWindowIcon(QIcon(logoImagePath));


    MainWindow *w = MainWindow::GetInstance();
    w->setWindowIcon(QIcon(logoImagePath));
    w->show();

    return a.exec();
}
