#include "formsettings.h"
#include "ui_formsettings.h"
#include <QInputDialog>
#include <QDir>
#include <QMessageBox>

FormSettings::FormSettings(QWidget *parent): QWidget(parent), ui(new Ui::FormSettings), reestr_("RegionPostavka", "Partners") {
    ui->setupUi(this);
    ui->checkBoxYandex->setChecked(reestr_.value("Yandex Enabled", QVariant(false)).toBool());
    ui->checkBoxCityMobile->setChecked(reestr_.value("CityMobile Enabled", QVariant(false)).toBool());

    ui->NotificationNewOrder->setChecked(reestr_.value("Notifications/NewOrder", QVariant(false)).toBool());
    ui->NotificationCancelOrder->setChecked(reestr_.value("Notifications/CancelOrder", QVariant(false)).toBool());
    ui->NotificationApplyOrder->setChecked(reestr_.value("Notifications/ApplyOrder", QVariant(false)).toBool());
    ui->NotificationUnknownStateOrder->setChecked(reestr_.value("Notifications/UnknownStateOrder", QVariant(false)).toBool());
    ui->NotificationSound->setChecked(reestr_.value("Notifications/Sound", QVariant(false)).toBool());

    ui->CheckBoxAutorun->setEnabled(false);
    ui->GroupBoxNotifications->setEnabled(false);
    ui->ButtonAGZS->setEnabled(false);
    ui->GroupBoxPartners->setEnabled(false);


    QSettings bootUpSettings("HKEY_CURRENT_USER\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run", QSettings::NativeFormat);
    QString value = bootUpSettings.value("RPYandex", QVariant("")).toString();
    if (value == "") {
        ui->CheckBoxAutorun->setChecked(false);
    } else if(value == QDir::toNativeSeparators(QCoreApplication::applicationFilePath())) {
        ui->CheckBoxAutorun->setChecked(true);
    } else {
        ui->CheckBoxAutorun->setCheckState(Qt::CheckState::PartiallyChecked);
    }

    this->setAttribute(Qt::WA_DeleteOnClose);
}

FormSettings::~FormSettings() {
    qDebug() << "Settings deleted";
    disconnect(this);
    delete ui;
}

void FormSettings::on_ButtonUnlock_clicked() {
    QString pass = QInputDialog::getText(this, tr("Проверка"), tr("Введите пароль:"), QLineEdit::Password, "");
    if (pass == "rjrjcs743") {
        ui->CheckBoxAutorun->setEnabled(true);
        ui->GroupBoxNotifications->setEnabled(true);
        ui->ButtonAGZS->setEnabled(true);
        ui->GroupBoxPartners->setEnabled(true);

    }
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

void FormSettings::on_CheckBoxAutorun_stateChanged(int arg1) {
    QSettings bootUpSettings("HKEY_CURRENT_USER\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run", QSettings::NativeFormat);
    QString app_path = QCoreApplication::applicationFilePath();
    if (arg1 == 2) {
        qInfo() << "app autorun is enabled" << app_path;
        bootUpSettings.setValue("RPYandex", QDir::toNativeSeparators(app_path));
    } else {
        qInfo() << "app autorun is disabled";
        bootUpSettings.remove("RPYandex");
    }
}

void FormSettings::on_ButtonAGZS_clicked() {
    QString agzs = QInputDialog::getText(this, tr("Поменять АГЗС"), tr("Введите АГЗС:"), QLineEdit::Normal, "agzs");
    if (agzs != "") {
        emit s_agzsChanged(agzs);
    }
}

void FormSettings::on_NotificationNewOrder_stateChanged(int arg1) {
    reestr_.setValue("Notifications/NewOrder", arg1 == 2);
    reestr_.sync();
}

void FormSettings::on_NotificationCancelOrder_stateChanged(int arg1) {
    reestr_.setValue("Notifications/CancelOrder", arg1 == 2);
    reestr_.sync();
}

void FormSettings::on_NotificationApplyOrder_stateChanged(int arg1) {
    reestr_.setValue("Notifications/ApplyOrder", arg1 == 2);
    reestr_.sync();
}

void FormSettings::on_NotificationSound_stateChanged(int arg1) {
    reestr_.setValue("Notifications/Sound", arg1 == 2);
    reestr_.sync();
}

void FormSettings::on_NotificationUnknownStateOrder_stateChanged(int arg1) {
    reestr_.setValue("Notifications/UnknownStateOrder", arg1 == 2);
    reestr_.sync();
}
