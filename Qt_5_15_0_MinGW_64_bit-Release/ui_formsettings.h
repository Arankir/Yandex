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
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormSettings
{
public:
    QVBoxLayout *verticalLayout_2;
    QPushButton *ButtonUnlock;
    QCheckBox *CheckBoxAutorun;
    QGroupBox *GroupBoxNotifications;
    QVBoxLayout *verticalLayout_3;
    QCheckBox *NotificationNewOrder;
    QCheckBox *NotificationCancelOrder;
    QCheckBox *NotificationApplyOrder;
    QCheckBox *NotificationUnknownStateOrder;
    QCheckBox *NotificationSound;
    QPushButton *ButtonAGZS;
    QGroupBox *GroupBoxPartners;
    QVBoxLayout *verticalLayout_4;
    QCheckBox *checkBoxYandex;
    QCheckBox *checkBoxCityMobile;

    void setupUi(QWidget *FormSettings)
    {
        if (FormSettings->objectName().isEmpty())
            FormSettings->setObjectName(QString::fromUtf8("FormSettings"));
        FormSettings->resize(187, 346);
        verticalLayout_2 = new QVBoxLayout(FormSettings);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        ButtonUnlock = new QPushButton(FormSettings);
        ButtonUnlock->setObjectName(QString::fromUtf8("ButtonUnlock"));

        verticalLayout_2->addWidget(ButtonUnlock);

        CheckBoxAutorun = new QCheckBox(FormSettings);
        CheckBoxAutorun->setObjectName(QString::fromUtf8("CheckBoxAutorun"));

        verticalLayout_2->addWidget(CheckBoxAutorun);

        GroupBoxNotifications = new QGroupBox(FormSettings);
        GroupBoxNotifications->setObjectName(QString::fromUtf8("GroupBoxNotifications"));
        verticalLayout_3 = new QVBoxLayout(GroupBoxNotifications);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        NotificationNewOrder = new QCheckBox(GroupBoxNotifications);
        NotificationNewOrder->setObjectName(QString::fromUtf8("NotificationNewOrder"));

        verticalLayout_3->addWidget(NotificationNewOrder);

        NotificationCancelOrder = new QCheckBox(GroupBoxNotifications);
        NotificationCancelOrder->setObjectName(QString::fromUtf8("NotificationCancelOrder"));

        verticalLayout_3->addWidget(NotificationCancelOrder);

        NotificationApplyOrder = new QCheckBox(GroupBoxNotifications);
        NotificationApplyOrder->setObjectName(QString::fromUtf8("NotificationApplyOrder"));

        verticalLayout_3->addWidget(NotificationApplyOrder);

        NotificationUnknownStateOrder = new QCheckBox(GroupBoxNotifications);
        NotificationUnknownStateOrder->setObjectName(QString::fromUtf8("NotificationUnknownStateOrder"));

        verticalLayout_3->addWidget(NotificationUnknownStateOrder);

        NotificationSound = new QCheckBox(GroupBoxNotifications);
        NotificationSound->setObjectName(QString::fromUtf8("NotificationSound"));

        verticalLayout_3->addWidget(NotificationSound);


        verticalLayout_2->addWidget(GroupBoxNotifications);

        ButtonAGZS = new QPushButton(FormSettings);
        ButtonAGZS->setObjectName(QString::fromUtf8("ButtonAGZS"));

        verticalLayout_2->addWidget(ButtonAGZS);

        GroupBoxPartners = new QGroupBox(FormSettings);
        GroupBoxPartners->setObjectName(QString::fromUtf8("GroupBoxPartners"));
        verticalLayout_4 = new QVBoxLayout(GroupBoxPartners);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        checkBoxYandex = new QCheckBox(GroupBoxPartners);
        checkBoxYandex->setObjectName(QString::fromUtf8("checkBoxYandex"));

        verticalLayout_4->addWidget(checkBoxYandex);

        checkBoxCityMobile = new QCheckBox(GroupBoxPartners);
        checkBoxCityMobile->setObjectName(QString::fromUtf8("checkBoxCityMobile"));

        verticalLayout_4->addWidget(checkBoxCityMobile);


        verticalLayout_2->addWidget(GroupBoxPartners);


        retranslateUi(FormSettings);

        QMetaObject::connectSlotsByName(FormSettings);
    } // setupUi

    void retranslateUi(QWidget *FormSettings)
    {
        FormSettings->setWindowTitle(QCoreApplication::translate("FormSettings", "\320\235\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\270", nullptr));
        ButtonUnlock->setText(QCoreApplication::translate("FormSettings", "\320\240\320\260\320\267\320\261\320\273\320\276\320\272\320\270\321\200\320\276\320\262\320\260\321\202\321\214", nullptr));
        CheckBoxAutorun->setText(QCoreApplication::translate("FormSettings", "\320\220\320\262\321\202\320\276\320\267\320\260\320\277\321\203\321\201\320\272", nullptr));
        GroupBoxNotifications->setTitle(QCoreApplication::translate("FormSettings", "\320\243\320\262\320\265\320\264\320\276\320\274\320\273\320\265\320\275\320\270\321\217", nullptr));
        NotificationNewOrder->setText(QCoreApplication::translate("FormSettings", "\320\235\320\276\320\262\320\260\321\217 \320\267\320\260\321\217\320\262\320\272\320\260", nullptr));
        NotificationCancelOrder->setText(QCoreApplication::translate("FormSettings", "\320\236\321\202\320\274\320\265\320\275\320\260 \320\267\320\260\321\217\320\262\320\272\320\270", nullptr));
        NotificationApplyOrder->setText(QCoreApplication::translate("FormSettings", "\320\243\321\201\320\277\320\265\321\210\320\275\320\260\321\217 \320\267\320\260\320\277\321\200\320\260\320\262\320\272\320\260", nullptr));
        NotificationUnknownStateOrder->setText(QCoreApplication::translate("FormSettings", "\320\235\320\265\320\270\320\267\320\262\320\265\321\201\321\202\320\275\320\276\320\265 \321\201\320\276\321\201\321\202\320\276\321\217\320\275\320\270\320\265", nullptr));
        NotificationSound->setText(QCoreApplication::translate("FormSettings", "\320\227\320\262\321\203\320\272\320\276\320\262\320\276\320\265 \320\276\320\277\320\276\320\262\320\265\321\211\320\260\320\275\320\270\320\265", nullptr));
        ButtonAGZS->setText(QCoreApplication::translate("FormSettings", "\320\220\320\223\320\227\320\241", nullptr));
        GroupBoxPartners->setTitle(QCoreApplication::translate("FormSettings", "\320\237\320\260\321\200\321\202\320\275\320\265\321\200\321\213", nullptr));
        checkBoxYandex->setText(QCoreApplication::translate("FormSettings", "\320\257\320\275\320\264\320\265\320\272\321\201 \320\267\320\260\320\277\321\200\320\260\320\262\320\272\320\270", nullptr));
        checkBoxCityMobile->setText(QCoreApplication::translate("FormSettings", "\320\241\320\270\321\202\320\270\320\274\320\276\320\261\320\270\320\273", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FormSettings: public Ui_FormSettings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMSETTINGS_H
