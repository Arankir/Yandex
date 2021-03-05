/********************************************************************************
** Form generated from reading UI file 'formsettings.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMSETTINGS_H
#define UI_FORMSETTINGS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormSettings
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QCheckBox *checkBoxYandex;
    QCheckBox *checkBoxCityMobile;

    void setupUi(QWidget *FormSettings)
    {
        if (FormSettings->objectName().isEmpty())
            FormSettings->setObjectName(QString::fromUtf8("FormSettings"));
        FormSettings->resize(231, 83);
        verticalLayout_2 = new QVBoxLayout(FormSettings);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(FormSettings);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        checkBoxYandex = new QCheckBox(FormSettings);
        checkBoxYandex->setObjectName(QString::fromUtf8("checkBoxYandex"));

        verticalLayout->addWidget(checkBoxYandex);

        checkBoxCityMobile = new QCheckBox(FormSettings);
        checkBoxCityMobile->setObjectName(QString::fromUtf8("checkBoxCityMobile"));

        verticalLayout->addWidget(checkBoxCityMobile);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(FormSettings);

        QMetaObject::connectSlotsByName(FormSettings);
    } // setupUi

    void retranslateUi(QWidget *FormSettings)
    {
        FormSettings->setWindowTitle(QCoreApplication::translate("FormSettings", "\320\235\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\270", nullptr));
        label->setText(QCoreApplication::translate("FormSettings", "\320\237\320\260\321\200\321\202\320\275\321\221\321\200\321\213", nullptr));
        checkBoxYandex->setText(QCoreApplication::translate("FormSettings", "\320\257\320\275\320\264\320\265\320\272\321\201 \320\267\320\260\320\277\321\200\320\260\320\262\320\272\320\270", nullptr));
        checkBoxCityMobile->setText(QCoreApplication::translate("FormSettings", "\320\241\320\270\321\202\320\270\320\274\320\276\320\261\320\270\320\273", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FormSettings: public Ui_FormSettings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMSETTINGS_H
