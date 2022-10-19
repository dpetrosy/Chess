#include <QApplication>

#include "mainwindow.hpp"

int main(int argc, char *argv[])
{
    QString logoImagePath = ":/images/images/logos/logo.png";

    QApplication a(argc, argv);
    a.setWindowIcon(QIcon(logoImagePath));

    MainWindow w;
    w.setWindowIcon(QIcon(logoImagePath));
    w.show();

    return a.exec();
}
