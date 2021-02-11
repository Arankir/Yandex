#ifndef FORMEXITPASSWORD_H
#define FORMEXITPASSWORD_H

#include <QWidget>
#include <QDebug>
#include <QMessageBox>
#include <QKeyEvent>

namespace Ui {
class FormExitPassword;
}

class FormExitPassword : public QWidget
{
    Q_OBJECT

public:
    explicit FormExitPassword(QWidget *parent = nullptr);
    ~FormExitPassword();
    void keyPressEvent(QKeyEvent *event);

private slots:
    void on_pushButton_clicked();

private:
    Ui::FormExitPassword *ui;
};

#endif // FORMEXITPASSWORD_H
