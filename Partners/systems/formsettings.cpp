#include "formsettings.h"
#include "ui_formsettings.h"

FormSettings::FormSettings(QWidget *parent): QWidget(parent), ui(new Ui::FormSettings), reestr_("RegionPostavka", "Partners") {
    ui->setupUi(this);
    ui->checkBoxYandex->setChecked(reestr_.value("Yandex Enabled", QVariant(false)).toBool());
    ui->checkBoxCityMobile->setChecked(reestr_.value("CityMobile Enabled", QVariant(false)).toBool());
}

FormSettings::~FormSettings() {
    delete ui;
}

void FormSettings::on_checkBoxYandex_stateChanged(int arg1) {
    reestr_.setValue("Yandex Enabled", arg1 == 2);
    reestr_.sync();
    emit s_yandexChange(arg1 == 2);
}

void FormSettings::on_checkBoxCityMobile_stateChanged(int arg1) {
   reestr_.setValue("CityMobile Enabled", arg1 == 2);
   reestr_.sync();
   emit s_cityMobileChange(arg1 == 2);
}
