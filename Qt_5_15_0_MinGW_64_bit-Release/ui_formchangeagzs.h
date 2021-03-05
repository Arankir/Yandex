/********************************************************************************
** Form generated from reading UI file 'formchangeagzs.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMCHANGEAGZS_H
#define UI_FORMCHANGEAGZS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormChangeAgzs
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *LineEditAgzs;
    QPushButton *PushButtonApply;

    void setupUi(QWidget *FormChangeAgzs)
    {
        if (FormChangeAgzs->objectName().isEmpty())
            FormChangeAgzs->setObjectName(QString::fromUtf8("FormChangeAgzs"));
        FormChangeAgzs->resize(248, 40);
        horizontalLayout = new QHBoxLayout(FormChangeAgzs);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(FormChangeAgzs);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        LineEditAgzs = new QLineEdit(FormChangeAgzs);
        LineEditAgzs->setObjectName(QString::fromUtf8("LineEditAgzs"));

        horizontalLayout->addWidget(LineEditAgzs);

        PushButtonApply = new QPushButton(FormChangeAgzs);
        PushButtonApply->setObjectName(QString::fromUtf8("PushButtonApply"));

        horizontalLayout->addWidget(PushButtonApply);


        retranslateUi(FormChangeAgzs);

        QMetaObject::connectSlotsByName(FormChangeAgzs);
    } // setupUi

    void retranslateUi(QWidget *FormChangeAgzs)
    {
        FormChangeAgzs->setWindowTitle(QCoreApplication::translate("FormChangeAgzs", "Form", nullptr));
        label->setText(QCoreApplication::translate("FormChangeAgzs", "\320\220\320\223\320\227\320\241:", nullptr));
        LineEditAgzs->setPlaceholderText(QCoreApplication::translate("FormChangeAgzs", "agzs2", nullptr));
        PushButtonApply->setText(QCoreApplication::translate("FormChangeAgzs", "\320\237\321\200\320\270\320\274\320\265\320\275\320\270\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FormChangeAgzs: public Ui_FormChangeAgzs {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMCHANGEAGZS_H
