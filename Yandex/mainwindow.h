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

private slots:
    void on_ButtonEnter_clicked();

    void on_ButtonGetPassword_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void mainFunction();

    void on_pushButton_4_clicked();

private:
    Ui::MainWindow *ui;
    QString _baseUrl="http://cabinet.tst.tanker.yandex.ru";
    YandexAPI *yandex;
    int _errorPassword=0;
};
#endif // MAINWINDOW_H
