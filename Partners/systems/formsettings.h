#ifndef FORMSETTINGS_H
#define FORMSETTINGS_H

#include <QWidget>
#include <QSettings>

namespace Ui {
class FormSettings;
}

class FormSettings : public QWidget {
    Q_OBJECT

public:
    explicit FormSettings(QWidget *parent = nullptr);
    ~FormSettings();

private slots:
    void on_checkBoxYandex_stateChanged(int arg1);

    void on_checkBoxCityMobile_stateChanged(int arg1);

private:
    Ui::FormSettings *ui;
    QSettings reestr_;
};

#endif // FORMSETTINGS_H
