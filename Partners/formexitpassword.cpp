#include "formexitpassword.h"
#include "ui_formexitpassword.h"

FormExitPassword::FormExitPassword(QWidget *parent) :
QWidget(parent),
ui(new Ui::FormExitPassword) {
    ui->setupUi(this);
}

FormExitPassword::~FormExitPassword() {
    delete ui;
}

void FormExitPassword::keyPressEvent(QKeyEvent *event) {
    if ( (event->key()==Qt::Key_Enter) || (event->key()==Qt::Key_Return) ) {
        on_pushButton_clicked();
    }
}

void FormExitPassword::on_pushButton_clicked() {
    if (ui->LineEditPassword->text() == "rjrjcs743") {
        qInfo() << "CLOSED from button";
        qApp->quit();
    } else {
        ui->LineEditPassword->setText("");
        QMessageBox::warning(this, tr("Ошибка!"), tr("Неверный пароль!"));
    }
}
