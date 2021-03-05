#ifndef FORMCHANGEAGZS_H
#define FORMCHANGEAGZS_H

#include <QWidget>

namespace Ui {
class FormChangeAgzs;
}

class FormChangeAgzs : public QWidget
{
    Q_OBJECT

public:
    explicit FormChangeAgzs(QWidget *parent = nullptr);
    ~FormChangeAgzs();

signals:
    void s_AgzsChanged(QString agzs);

private slots:
    void on_PushButtonApply_clicked();

private:
    Ui::FormChangeAgzs *ui;
};

#endif // FORMCHANGEAGZS_H
