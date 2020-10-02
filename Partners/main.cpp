#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QCoreApplication::setOrganizationName("RegionPostavka");
    QCoreApplication::setOrganizationDomain("region postavka");
    QCoreApplication::setApplicationName("Agents api");
    QApplication a(argc, argv);
    MainWindow w;
    //w.show();
    return a.exec();
}
