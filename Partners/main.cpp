#include "mainwindow.h"

#include <QApplication>
#include <QLockFile>
#include <QMessageBox>

int main(int argc, char *argv[])
{
    QCoreApplication::setOrganizationName("RegionPostavka");
    QCoreApplication::setOrganizationDomain("region postavka");
    QCoreApplication::setApplicationName("Agents api");
    QApplication a(argc, argv);

    QLockFile lockFile(QDir::temp().absoluteFilePath("lurity.lock"));
    if(!lockFile.tryLock(100)) {
        QMessageBox msgBox;
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setText("Приложение уже запущено.\n"
                       "Разрешено запускать только один экземпляр приложения.");
        msgBox.exec();
        return 1;
    }

    MainWindow w;
    //w.show();
    return a.exec();
}
