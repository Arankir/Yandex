#include "formchangeagzs.h"
#include "ui_formchangeagzs.h"

FormChangeAgzs::FormChangeAgzs(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormChangeAgzs) {
    ui->setupUi(this);
}

FormChangeAgzs::~FormChangeAgzs() {
    delete ui;
}

void FormChangeAgzs::on_PushButtonApply_clicked() {
    emit s_AgzsChanged(ui->LineEditAgzs->text());
}
