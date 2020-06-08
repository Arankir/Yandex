#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <yandexapi.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

    ~MainWindow();

public slots:

private slots:
    void on_ButtonEnter_clicked();

    void on_ButtonGetPassword_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void mainFunction();
    QString GetFullFuelName(int aFuelId);
    QString GetFuelAPIName(int aFuelVCode);

    void on_pushButton_4_clicked();

    void updatePrice();
    void updateConfiguration();


private:
    Ui::MainWindow *ui;
    QString _baseUrl="http://cabinet.tst.tanker.yandex.ru";
    YandexAPI *_yandex;
    int _errorPassword = 0;
    QSqlDatabase _db;
    QTimer _timer;
};
#endif // MAINWINDOW_H
