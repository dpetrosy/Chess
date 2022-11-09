#include <QApplication>
#include <QDebug>

#include "mainwindow.hpp"

int main(int argc, char *argv[])
{
    //QApplication::setAttribute(Qt::AA_EnableHighDpiScaling); // DPI support
    //QCoreApplication::setAttribute(Qt::AA_UseHighDpiPixmaps); //HiDPI pixmaps
    //QApplication::setAttribute(Qt::AA_DisableHighDpiScaling);
    //QCoreApplication::setAttribute(Qt::AA_DisableHighDpiScaling);
    //qputenv("QT_SCALE_FACTOR", "1");
    //qputenv("QT_AUTO_SCREEN_SCALE_FACTOR", "0");


    QString logoImagePath = ":/images/images/logos/logo.png";

    QApplication a(argc, argv);
    a.setWindowIcon(QIcon(logoImagePath));


    MainWindow *w = MainWindow::GetInstance();
    w->setWindowIcon(QIcon(logoImagePath));
    w->show();

    return a.exec();
}
