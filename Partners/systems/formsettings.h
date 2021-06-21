#ifndef FORMSETTINGS_H
#define FORMSETTINGS_H

#include <QWidget>
#include <QSettings>
#include <QDebug>

namespace Ui {
class FormSettings;
}

class FormSettings : public QWidget {
    Q_OBJECT

public:
    explicit FormSettings(QWidget *parent = nullptr);
    ~FormSettings();

signals:
    void s_yandexChange(bool);
    void s_cityMobileChange(bool);
    void s_agzsChanged(const QString &agzs);

private slots:
    void on_checkBoxYandex_stateChanged(int arg1);

    void on_checkBoxCityMobile_stateChanged(int arg1);

    void on_CheckBoxAutorun_stateChanged(int arg1);

    void on_ButtonAGZS_clicked();

    void on_ButtonUnlock_clicked();

    void on_NotificationNewOrder_stateChanged(int arg1);

    void on_NotificationCancelOrder_stateChanged(int arg1);

    void on_NotificationApplyOrder_stateChanged(int arg1);

    void on_NotificationSound_stateChanged(int arg1);

    void on_NotificationUnknownStateOrder_stateChanged(int arg1);

private:
    Ui::FormSettings *ui;
    QSettings reestr_;
};

#endif // FORMSETTINGS_H
