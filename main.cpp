#include <QApplication>

#include "mainwindow.hpp"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setWindowIcon(QIcon(":/images/images/logo.png"));

    MainWindow w;
    w.setWindowIcon(QIcon(":/images/images/logo.png"));
    w.show();

    return a.exec();
}
