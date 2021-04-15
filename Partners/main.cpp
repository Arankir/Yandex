#include "mainwindow.h"

#include <QApplication>
#include <QLockFile>
#include <QMessageBox>
#include <QDebug>
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

QScopedPointer<QFile> logFile_;
QScopedPointer<QFile> infoFile_;
QScopedPointer<QFile> errorFile_;
QSettings reestr_("RegionPostavka", "Partners");

bool createDir(const QString &aPath) {
    bool exist = true;
    QString path = aPath;
    path.replace("\\", "/");
    if (path.lastIndexOf("/") != path.length() - 1) {
        path += "/";
    }
    QStringList dirs = path.split("/");
    QString pathNow = "";
    for (auto &dir: dirs) {
        if (dir != dirs.last()) {
            pathNow += std::move(dir)+"/";
            exist = (QDir().mkdir(pathNow) && exist);
        }
    }
    return exist;
}

void log(QtMsgType aType, const QMessageLogContext &aContext, const QString &aMessage) {
    const char *function = aContext.function ? aContext.function : "";

    QString debug(function);
    if (debug.length() != 0 ) {
        debug += "  ";
    }
    debug += aMessage;
    OutputDebugString(reinterpret_cast<const wchar_t *>(debug.utf16()));

    if ((aMessage.indexOf("http") > 0) && (reestr_.value("ordersLog") == false)) {
        return;
    }
    if (aType == QtDebugMsg) {
        return;
    }

    QTextStream out(logFile_.data());

    out << QDateTime::currentDateTime().toString("hh:mm:ss "); //yyyy-MM-dd hh:mm:ss

    switch (aType) {
    case QtInfoMsg: {
        QTextStream outI(infoFile_.data());
        outI << QDateTime::currentDateTime().toString("hh:mm:ss "); //yyyy-MM-dd hh:mm:ss
        outI << aMessage << Qt::endl;
        outI.flush();

        break; //out << "INFO "; break;
    }
    case QtDebugMsg: {
        return;
    }
    case QtWarningMsg: {
        QTextStream outW(errorFile_.data());
        outW << QDateTime::currentDateTime().toString("hh:mm:ss "); //yyyy-MM-dd hh:mm:ss
        outW << aMessage << Qt::endl;
        outW.flush();

        out << "WRNG ";
        break;
    }
    case QtCriticalMsg: {
        out << "CRCL ";
        break;
    }
    case QtFatalMsg: {
        out << "FATL ";
        break;
    }
    default: ;
    }

    if (QString(aContext.category) == "Error") {
        out << "ERROR ";
    }

    out << aMessage << Qt::endl;
    out.flush();

}

void initLog() {
    createDir("logs/");

    //Удаление старых файлов
    QDir dirLogs("logs/");
    dirLogs.setFilter(QDir::Files | QDir::NoSymLinks);
    dirLogs.setSorting(QDir::Name);
    QFileInfoList list = dirLogs.entryInfoList();
    for(auto &file: list) {
        if ((file.fileName().indexOf("log_") == 0) ||
            (file.fileName().indexOf("info_") == 0) ||
            (file.fileName().indexOf("wrng_") == 0)) {
            QDateTime date;
            date = QDateTime::fromString(file.fileName().remove("log_").remove("info_").remove("wrng_").remove(".txt"), "yyyy.MM.dd");
            if (date < QDateTime::currentDateTime().addMonths(-2)) {
                QFile::remove(file.filePath());
            }
        }
    }

    logFile_.reset(new QFile("logs/" + QDateTime::currentDateTime().toString("log_yyyy.MM.dd") + ".txt"));
    logFile_.data()->open(QFile::Append | QFile::Text);

    infoFile_.reset(new QFile("logs/" + QDateTime::currentDateTime().toString("info_yyyy.MM.dd") + ".txt"));
    infoFile_.data()->open(QFile::Append | QFile::Text);

    errorFile_.reset(new QFile("logs/" + QDateTime::currentDateTime().toString("wrng_yyyy.MM.dd") + ".txt"));
    errorFile_.data()->open(QFile::Append | QFile::Text);
    qInstallMessageHandler(log);
}

int main(int argc, char *argv[]) {
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

    initLog();

    MainWindow w;
    //w.show();
    return a.exec();
}
