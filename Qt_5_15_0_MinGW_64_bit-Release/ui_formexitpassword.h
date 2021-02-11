/********************************************************************************
** Form generated from reading UI file 'formexitpassword.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMEXITPASSWORD_H
#define UI_FORMEXITPASSWORD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormExitPassword
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QLineEdit *LineEditPassword;
    QPushButton *pushButton;

    void setupUi(QWidget *FormExitPassword)
    {
        if (FormExitPassword->objectName().isEmpty())
            FormExitPassword->setObjectName(QString::fromUtf8("FormExitPassword"));
        FormExitPassword->resize(365, 61);
        verticalLayout = new QVBoxLayout(FormExitPassword);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(FormExitPassword);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        LineEditPassword = new QLineEdit(FormExitPassword);
        LineEditPassword->setObjectName(QString::fromUtf8("LineEditPassword"));
        LineEditPassword->setEchoMode(QLineEdit::Password);

        horizontalLayout->addWidget(LineEditPassword);

        pushButton = new QPushButton(FormExitPassword);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout->addWidget(pushButton);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(FormExitPassword);

        QMetaObject::connectSlotsByName(FormExitPassword);
    } // setupUi

    void retranslateUi(QWidget *FormExitPassword)
    {
        FormExitPassword->setWindowTitle(QCoreApplication::translate("FormExitPassword", "Form", nullptr));
        label->setText(QCoreApplication::translate("FormExitPassword", "\320\224\320\273\321\217 \320\262\321\213\321\205\320\276\320\264\320\260 \320\275\320\265\320\276\320\261\321\205\320\276\320\264\320\270\320\274\320\276 \320\262\320\262\320\265\321\201\321\202\320\270 \320\277\320\260\321\200\320\276\320\273\321\214", nullptr));
        pushButton->setText(QCoreApplication::translate("FormExitPassword", "\320\222\321\213\320\271\321\202\320\270", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FormExitPassword: public Ui_FormExitPassword {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMEXITPASSWORD_H
