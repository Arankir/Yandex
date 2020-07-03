#include "formsettings.h"
#include "ui_formsettings.h"

FormSettings::FormSettings(QWidget *parent): QWidget(parent), ui(new Ui::FormSettings), _reestr("RegionPostavka", "Partners") {
    ui->setupUi(this);
    ui->checkBoxYandex->setChecked(_reestr.value("Yandex Enabled", QVariant(false)).toBool());
    ui->checkBoxCityMobile->setChecked(_reestr.value("CityMobile Enabled", QVariant(false)).toBool());
}

FormSettings::~FormSettings() {
    delete ui;
}

void FormSettings::on_checkBoxYandex_stateChanged(int arg1) {
    _reestr.setValue("Yandex Enabled", arg1 == 2);
    _reestr.sync();
}

void FormSettings::on_checkBoxCityMobile_stateChanged(int arg1) {
   _reestr.setValue("CityMobile Enabled", arg1 == 2);
   _reestr.sync();
}
